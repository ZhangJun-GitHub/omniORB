%{
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "StmtParser.h"

typedef struct 
{
	int idtype; /*
				1 - 变量定义
				2 - 结构定义
				3 - 函数定义
				*/
	char idname[128]; /* 标识名称 */
	int	 valtype; /* 普通变量类型 */
	char tpname[128];  /* 结构变量类型 */
} node_val;

#define YYSTYPE		node_val

#define YY_DECL int yylex( YYSTYPE *yylval )

%}

%option never-interactive
%option nostdinit
%option noyywrap
		
%%

"unsigned long" 	return ULONG; 
"u_long" 			return ULONG;	
"long" 				{ return LONG; }
	
"unsigned int" 		return UINT;	
"u_int" 			return UINT;	
"int" 				return INT;	

"unsigned short" 	return USHORT;	
"u_short" 			return USHORT;	
"short" 			return SHORT;	

"double" 			return DOUBLE;	
"float" 			return FLOAT;	

"unsigned char" 	return UCHAR;	
"u_char" 			return UCHAR;	
"char" 				return CHAR;	

"ST_JYXX" 			return ST_JYXX;	

"struct"			return STRUCT;

"extern"[ \t]*\"C\"

[_a-zA-Z][_a-zA-Z0-9]* { strcpy(yylval->idname, yytext); return UDFID; }

\*					return *yytext;

"("					return *yytext;

")"					return *yytext;

"{"					return *yytext;

"}"					return *yytext;

","					return *yytext;	

";"					return *yytext;

"/"\*.*\*"/"  

[\n\r]+
.

<<EOF>>		{yyterminate(); return 0;}

%%

