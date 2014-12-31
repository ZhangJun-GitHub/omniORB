%{
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

#ifdef __WIN32__
#include <direct.h>
#endif

typedef struct 
{
	int	 valtype; 		/* 变量类型 */
	char idname[128]; 	/* 标识名称 */
	char tpname[128];  	/* 结构类型名称 */
} node_val;

#define YYSTYPE		node_val

extern int yylex(YYSTYPE *yylval);

#define yyerror(msg) fprintf(stderr, "error encountered: (%s)\n", msg);

enum {
	UL,
	L,
	UI,
	I,
	USH,
	SH,
	D,
	F,
	UC,
	C,
	USTR,
	STR,
	ST_JY,
	STRT,
	PUL,
	PL,
	PUI,
	PI,
	PUSH,
	PSH,
	PD,
	PF,
	PST_JY,
	PSTRT
};

struct varnode
{
	node_val var;
	struct varnode* next;
};

struct strtnode
{
	char tpname[64];
	struct varnode*	mbrlist;
	struct strtnode* next;
};

struct varnode*	g_mbrlist = NULL;

struct varnode*	g_prmlist = NULL;

struct strtnode* g_strtlist = NULL;

char* g_str_type[] = {
	"unsigned long",
	"long",
	"unsigned int",
	"int",
	"unsigned short",
	"short",
	"double",
	"float",
	"unsigned char",
	"char",
	"unsigned char*",
	"char*",
	"ST_JYXX",
	"struct",
	"unsigned long",
	"long",
	"unsigned int",
	"int",
	"unsigned short",
	"short",
	"double",
	"float",
	"ST_JYXX",
	"struct"
};

char g_src_head[]=
"#include <mypkg.h>\n"
"#include <testpub.h>\n"
"#include <%s.h>\n"
"\n"
"extern \"C\"\n"
"%s %s(CMyPkg* aInPkg, CMyPkg* aOutPkg)\n"
"{\n"
"	ST_JYXX lrt_jyxx;\n"
"	ST_JYXX *prt_jyxx = &lrt_jyxx;\n"
"	int	i;\n"
"\n"
"	memset(&lrt_jyxx, 0, sizeof(lrt_jyxx));\n"
"\n"
"    /* 从 aInPkg 取值填入 prt_jyxx */\n"
"	prt_jyxx->jzgy = aInPkg->getLong(\"jzgy\", \"prt_jyxx\")\n"
"	prt_jyxx->cngy = aInPkg->getLong(\"cngy\", \"prt_jyxx\")\n"
"	prt_jyxx->sqgy = aInPkg->getLong(\"sqgy\", \"prt_jyxx\")\n"
"	prt_jyxx->jym = aInPkg->getLong(\"jym\", \"prt_jyxx\")\n"
"	prt_jyxx->yyrq = aInPkg->getLong(\"yyrq\", \"prt_jyxx\")\n"
"	strcpy(prt_jyxx->jgm, aInPkg->getString(\"jgm\", \"prt_jyxx\")\n"
"\n"
"	for (i=0; i<aInPkg->getFldNum(); i++)\n"
"	{\n"
"		if (strcmp(aInPkg->getFldNs(i), \"pubbuf\") == 0)\n"
"		{\n"
"			mpfld2buf(lrt_jyxx.pubbuf, aInPkg, \"pubbuf\", \n"
"				aInPkg->getFldName(i), aInPkg->getFldName(i));\n"
"		}\n"
"		else if (strcmp(aInPkg->getFldNs(i), \"sysbuf\") == 0)\n"
"		{\n"
"			mpfld2buf(lrt_jyxx.sysbuf, aInPkg, \"sysbuf\", \n"
"						aInPkg->getFldName(i), aInPkg->getFldName(i));\n"
"                       if (!strcmp(aInPkg->getFldName(i), \"jgm\"))\n"
"                       {\n"
"                           get_string(\"jgm\", lrt_jyxx.sysbuf, lrt_jyxx.jgm);\n"
"                           put_string(\"JGM\", lrt_jyxx.sysbuf, lrt_jyxx.jgm);\n"
"                           put_string(\"_JGM\", lrt_jyxx.pubbuf, lrt_jyxx.jgm);\n"
"                       }\n"
"                       else if (!strcmp(aInPkg->getFldName(i), \"jym\"))\n"
"                       {\n"
"                           get_lng(\"jym\", lrt_jyxx.sysbuf, &lrt_jyxx.jym);\n"
"                       }\n"
"                       else if (!strcmp(aInPkg->getFldName(i), \"yyrq\"))\n"
"                       {\n"
"                           get_lng(\"yyrq\", lrt_jyxx.sysbuf, &lrt_jyxx.yyrq);\n"
"                       }\n"
"     	}\n"
"		else if (strcmp(aInPkg->getFldNs(i), \"inbuf\") == 0)\n"
"		{\n"
"			mpfld2buf(lrt_jyxx.inbuf, aInPkg, \"inbuf\", \n"
"			aInPkg->getFldName(i), aInPkg->getFldName(i));\n"
"		}\n"
"	}\n\n";
  
char g_src_tail[]=
"	if (lrt_jyxx.sendfile[0] != 0)\n"
"	{\n"
"		aOutPkg->addString(\"FILENAME\", lrt_jyxx.sendfile);\n"
"	}\n"
"	buf2mp(lrt_jyxx.downbuf, aOutPkg);\n"
"\n"
"	return 0;\n"
"}\n";

%}

%pure-parser

%token '*' ';'
%token ULONG LONG UINT INT USHORT SHORT DOUBLE FLOAT UCHAR CHAR ST_JYXX UDFID STRUCT
%token '(' ')'

%%

file: 
	  strtdef
	| funcdef
	| strtdef file
	| funcdef file
	;

funcdef:
	  vardef funcparams ';'
	  {
	  	struct varnode* pprm = NULL;
	  	struct varnode* pmbr = NULL;
		struct strtnode* pstrt = NULL;

		char   filename[128];
		char   str_type[128];
		FILE*  fpw = NULL;
	  		  	
		sprintf(filename, "stub_%s.cpp", $1.idname);
		fpw = fopen(filename, "w");
		if (fpw == NULL)
		{
			perror(filename);
			exit(0);
		}

		/* 生成程序首 */
		if ($1.valtype == STRT)
		{
			sprintf(str_type, "struct %s", $1.tpname);
		}
		else if ($1.valtype == PSTRT)
		{
			sprintf(str_type, "struct %s *", $1.tpname);
		}
		else
		{
			strcpy(str_type, g_str_type[$1.valtype]);
		}

	  	fprintf(fpw, g_src_head, $1.idname, str_type, $1.idname);

		/* 生成I/O参数定义 */

	  	fprintf(fpw, "	/* I/O参数定义 */\n");
	  	pprm = g_prmlist;
	  	while (pprm != NULL)
	  	{
			switch (pprm->var.valtype)
			{
			case UL:
			case L:
			case UI:
			case I:
			case USH:
			case SH:
			case D:
			case F:
			case UC:
			case C:
			case USTR:
			case STR:
			case STRT:
				fprintf(fpw, "	%s %s;\n", g_str_type[pprm->var.valtype], pprm->var.idname);
				break;
			case PUL:
			case PL:
			case PUI:
			case PI:
			case PUSH:
			case PSH:
			case PD:
			case PF:
				fprintf(fpw, "	%s* %s = (%s*)malloc(sizeof(%s));\n", 
								g_str_type[pprm->var.valtype], pprm->var.idname,
								g_str_type[pprm->var.valtype], g_str_type[pprm->var.valtype]); 
				break;
			case PSTRT:
				fprintf(fpw, "	struct %s* %s = (struct %s*)malloc(sizeof(struct %s));\n", 
								pprm->var.tpname, pprm->var.idname,
								pprm->var.tpname, pprm->var.tpname); 
				break;
			case ST_JY:
			case PST_JY:
				break;
			default:
				break;
			}

	  		pprm = pprm->next;
	  	}	  

		fprintf(fpw, "\n");

		/* 传入参数处理 */
	  	fprintf(fpw, "	/* 传入参数处理 */\n");

	  	pprm = g_prmlist;
	  	while (pprm != NULL)
	  	{
			switch (pprm->var.valtype)
			{
			case UL:
				fprintf(fpw, "	%s = aInPkg->getULong(\"%s\");\n", pprm->var.idname,pprm->var.idname);
				break;
			case PUL:
				fprintf(fpw, "	*%s = aInPkg->getULong(\"%s\");\n", 
							pprm->var.idname,pprm->var.idname);
				break;
			case L:
				fprintf(fpw, "	%s = aInPkg->getLong(\"%s\");\n", pprm->var.idname,pprm->var.idname);
				break;
			case PL:
				fprintf(fpw, "	*%s = aInPkg->getLong(\"%s\");\n", pprm->var.idname,pprm->var.idname);
				break;
			case UI:
				fprintf(fpw, "	%s = aInPkg->getUInt(\"%s\");\n", pprm->var.idname,pprm->var.idname);
				break;
			case PUI:
				fprintf(fpw, "	*%s = aInPkg->getUInt(\"%s\");\n", pprm->var.idname,pprm->var.idname);
				break;
			case I:
				fprintf(fpw, "	%s = aInPkg->getInt(\"%s\");\n", pprm->var.idname,pprm->var.idname);
				break;
			case PI:
				fprintf(fpw, "	*%s = aInPkg->getInt(\"%s\");\n", pprm->var.idname,pprm->var.idname);
				break;
			case USH:
				fprintf(fpw, "	%s = aInPkg->getUShort(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case PUSH:
				fprintf(fpw, "	*%s = aInPkg->getUShort(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case SH:
				fprintf(fpw, "	%s = aInPkg->getShort(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case PSH:
				fprintf(fpw, "	*%s = aInPkg->getShort(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case D:
				fprintf(fpw, "	%s = aInPkg->getDouble(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case PD:
				fprintf(fpw, "	*%s = aInPkg->getDouble(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case F:
				fprintf(fpw, "	%s = aInPkg->getFloat(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case PF:
				fprintf(fpw, "	*%s = aInPkg->getFloat(\"%s\");\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case UC:
			case C:
				fprintf(fpw, "	%s = aInPkg->getString(\"%s\")[0];\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case USTR:
			case STR:
				fprintf(fpw, "	strdup(%s, aInPkg->getString(\"%s\"));\n", 
								pprm->var.idname,pprm->var.idname);
				break;
			case ST_JY:
			case PST_JY:
				break;
			case STRT:
			case PSTRT:
				break;
			default:
				break;
			}

	  		pprm = pprm->next;
	  	}
	  	fprintf(fpw, "\n");

		/* 函数调用处理 */
	  	fprintf(fpw, "	/* 函数调用处理 */\n");

	  	fprintf(fpw, "	%s FuncRet;\n", str_type);
	  	fprintf(fpw, "	FuncRet = %s(\n", $1.idname);

	  	pprm = g_prmlist;
	  	while (pprm != NULL)
	  	{
	  		if (pprm != g_prmlist)
			{
				fprintf(fpw, ",\n");
			}

			switch (pprm->var.valtype)
			{
			case UL:
			case L:
			case UI:
			case I:
			case USH:
			case SH:
			case D:
			case F:
			case UC:
			case C:
			case USTR:
			case STR:
			case STRT:
			case PUL:
			case PL:
			case PUI:
			case PI:
			case PUSH:
			case PSH:
			case PD:
			case PF:
			case PSTRT:
				fprintf(fpw, "	            %s", pprm->var.idname);
				break;
			case ST_JY:
				fprintf(fpw, "	            lrt_jyxx", pprm->var.idname);
				break;
			case PST_JY:
				fprintf(fpw, "	            prt_jyxx", pprm->var.idname);
				break;
			default:
				break;
			}

	  		pprm = pprm->next;
	  	}
	  	fprintf(fpw, ");\n");
	  	fprintf(fpw, "\n");

		/* 传出参数处理 */
	  	fprintf(fpw, "	/* 传出参数处理 */\n");

	  	pprm = g_prmlist;
	  	while (pprm != NULL)
	  	{
			switch (pprm->var.valtype)
			{
			case PUL:
				fprintf(fpw, "	aOutPkg->addULong(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PL:
				fprintf(fpw, "	aOutPkg->addLong(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PUI:
				fprintf(fpw, "	aOutPkg->addUInt(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PI:
				fprintf(fpw, "	aOutPkg->addInt(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PUSH:
				fprintf(fpw, "	aOutPkg->addUShort(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PSH:
				fprintf(fpw, "	aOutPkg->addShort(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PD:
				fprintf(fpw, "	aOutPkg->addDouble(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PF:
				fprintf(fpw, "	aOutPkg->addFloat(\"%s\", *%s);\n", 
							pprm->var.idname, pprm->var.idname);
				break;
			case PSTRT:
				break;
			default:
				break;
			}

	  		pprm = pprm->next;
	  	}
	  	fprintf(fpw, "\n");

		/* 释放传出参数 */
	  	fprintf(fpw, "	/* 释放传出参数 */\n");

	  	pprm = g_prmlist;
	  	while (pprm != NULL)
	  	{
			switch (pprm->var.valtype)
			{
			case PUL:
			case PL:
			case PUI:
			case PI:
			case PUSH:
			case PSH:
			case PD:
			case PF:
			case PSTRT:
				fprintf(fpw, "	free(%s);\n", pprm->var.idname);
				break;
			default:
				break;
			}

	  		pprm = pprm->next;
	  	}
	  	fprintf(fpw, "\n");
	  	fprintf(fpw, g_src_tail);

		fclose(fpw);

	  }
	;

strtdef:
	  STRUCT UDFID '{' vardef '}' ';'
	  {
	  	struct varnode* pmbr = NULL;
	  	struct strtnode* pstrt = NULL;
	  	
	  	g_mbrlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_mbrlist->var = $4;
	  	g_mbrlist->next = NULL;
	  	
	  	if (g_strtlist == NULL)
	  	{
	  		g_strtlist = (struct strtnode*)malloc(sizeof(struct strtnode));
	  	}
	  	else
	  	{
	  		pstrt = g_strtlist;
	  		while (pstrt->next != NULL)
	  		{
	  			pstrt = pstrt->next;
	  		}
	  		
	  		pstrt->next = (struct strtnode*)malloc(sizeof(struct strtnode));
	  		pstrt = pstrt->next;
	  		strcpy(pstrt->tpname, $2.idname);
	  		pstrt->mbrlist = g_mbrlist;
	  		pstrt->next = NULL;
	  		g_mbrlist = NULL;
	  	}
	  	
	  	pmbr = g_mbrlist;
	  	while (pmbr != NULL)
	  	{
	  		pmbr = pmbr->next;
	  	}
	  }
	| STRUCT UDFID '{' members '}' ';'
	  {
	  	struct varnode* pmbr = NULL;
	  	struct strtnode* pstrt = NULL;
	  	
	  	if (g_strtlist == NULL)
	  	{
	  		g_strtlist = (struct strtnode*)malloc(sizeof(struct strtnode));
	  	}
	  	else
	  	{
	  		pstrt = g_strtlist;
	  		while (pstrt->next != NULL)
	  		{
	  			pstrt = pstrt->next;
	  		}
	  		
	  		pstrt->next = (struct strtnode*)malloc(sizeof(struct strtnode));
	  		pstrt = pstrt->next;
	  		strcpy(pstrt->tpname, $2.idname);
	  		pstrt->mbrlist = g_mbrlist;
	  		pstrt->next = NULL;
	  		g_mbrlist = NULL;
	  	}

	  	pmbr = g_mbrlist;
	  	while (pmbr != NULL)
	  	{
	  		pmbr = pmbr->next;
	  	}
	  }
	  
members: 
	  member
	| members member
	;
member:
	  vardef ';'
	  {
	  	struct varnode* p = g_mbrlist;

		if (g_mbrlist == NULL)
		{
			g_mbrlist = (struct varnode*)malloc(sizeof(struct varnode));
			g_mbrlist->var = $1;
			g_mbrlist->next = NULL;
		}
		else
		{
			while (p->next != NULL)
			{
				p = p->next;
			}
					
			p->next = (struct varnode*)malloc(sizeof(struct varnode));
			
			p = p->next;
			p->var = $1;
			p->next = NULL;	  
		}
	  }
	;
	
funcparams: 
	  '(' params ')'
	| '(' vardef ')'
	  {
	  	struct varnode* p = NULL;
	  	
	  	g_prmlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_prmlist->var = $1;
	  	g_prmlist->next = NULL;
	  }  		
	;

params:
	  vardef ',' vardef
	  {
	  	struct varnode* p = NULL;
	  	
	  	g_prmlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_prmlist->var = $1;

	  	g_prmlist->next = (struct varnode*)malloc(sizeof(struct varnode));
		p = g_prmlist->next;
	  	p->var = $3;
	  	p->next = NULL;	  
	  }  		
	| params ',' vardef
	  {
	  	struct varnode* p = g_prmlist;
	  	
		while (p->next != NULL)
		{
			p = p->next;
		}
			  	
	  	p->next = (struct varnode*)malloc(sizeof(struct varnode));
	  	p = p->next;
	  	p->var = $3;
	  	p->next = NULL;	  
	  }
	;
	
vardef:
	  ULONG UDFID 
	  { 
	  	$$.valtype = UL;
	  	strcpy($$.idname, $2.idname); 
	  }
	| LONG UDFID
	  { 
	  	$$.valtype = L;
	  	strcpy($$.idname, $2.idname); 
	  }
	| UINT UDFID
	  { 
	  	$$.valtype = UI;
	  	strcpy($$.idname, $2.idname); 
	  }
	| INT UDFID	
	  { 
	  	$$.valtype = I;
	  	strcpy($$.idname, $2.idname); 
	  }
	| USHORT UDFID
	  { 
	  	$$.valtype = USH;
	  	strcpy($$.idname, $2.idname); 
	  }
	| SHORT UDFID
	  { 
	  	$$.valtype = SH;
	  	strcpy($$.idname, $2.idname); 
	  }
	| DOUBLE UDFID
	  { 
	  	$$.valtype = D;
	  	strcpy($$.idname, $2.idname); 
	  }
	| FLOAT UDFID
	  { 
	  	$$.valtype = F;
	  	strcpy($$.idname, $2.idname); 
	  }
	| UCHAR UDFID
	  { 
	  	$$.valtype = UC;
	  	strcpy($$.idname, $2.idname); 
	  }
	| CHAR UDFID
	  { 
	  	$$.valtype = C;
	  	strcpy($$.idname, $2.idname); 
	  }
	| UCHAR '*' UDFID
	  { 
	  	$$.valtype = USTR;
	  	strcpy($$.idname, $3.idname); 
	  }
	| CHAR '*' UDFID
	  { 
	  	$$.valtype = STR;
	  	strcpy($$.idname, $3.idname); 
	  }
	| ST_JYXX UDFID
	  { 
	  	$$.valtype = ST_JY;
	  	strcpy($$.idname, $2.idname); 
	  }
	| STRUCT UDFID UDFID
	  { 
	  	$$.valtype = STRT;
	  	strcpy($$.tpname, $2.idname); 
	  	strcpy($$.idname, $3.idname); 
	  }
	| ULONG '*' UDFID
	  { 
	  	$$.valtype = PUL;
	  	strcpy($$.idname, $3.idname); 
	  }
	| LONG '*' UDFID
	  { 
	  	$$.valtype = PL;
	  	strcpy($$.idname, $3.idname); 
	  }
	| UINT '*' UDFID
	  { 
	  	$$.valtype = PUI;
	  	strcpy($$.idname, $3.idname); 
	  }
	| INT '*' UDFID	
	  { 
	  	$$.valtype = PI;
	  	strcpy($$.idname, $3.idname); 
	  }
	| USHORT '*' UDFID
	  { 
	  	$$.valtype = PUSH;
	  	strcpy($$.idname, $3.idname); 
	  }
	| SHORT '*' UDFID
	  { 
	  	$$.valtype = PSH;
	  	strcpy($$.idname, $3.idname); 
	  }
	| DOUBLE '*' UDFID
	  { 
	  	$$.valtype = PD;
	  	strcpy($$.idname, $3.idname); 
	  }
	| FLOAT '*' UDFID
	  { 
	  	$$.valtype = PF;
	  	strcpy($$.idname, $3.idname); 
	  }
	| ST_JYXX '*' UDFID
	  { 
	  	$$.valtype = PST_JY;
	  	strcpy($$.idname, $3.idname); 
	  }
	| STRUCT UDFID '*' UDFID
	  { 
	  	$$.valtype = PSTRT;
	  	strcpy($$.tpname, $2.idname); 
	  	strcpy($$.idname, $4.idname); 
	  }
	;

%%

extern FILE* yyin;

int main(int argc, char *argv[])
{
	
	if (argc<2)
	{
		printf("usage: %s file\n", argv[0]);
		return -1;
	}
		
	yyin = fopen(argv[1], "r");
	if (yyin == (FILE*) NULL)
	{
		perror(argv[1]);
		exit(-1);
	}
	
	yyparse();
	
	fclose(yyin);
	return 0;
}
