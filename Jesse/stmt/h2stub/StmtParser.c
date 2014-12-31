/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ULONG = 258,
     LONG = 259,
     UINT = 260,
     INT = 261,
     USHORT = 262,
     SHORT = 263,
     DOUBLE = 264,
     FLOAT = 265,
     UCHAR = 266,
     CHAR = 267,
     ST_JYXX = 268,
     UDFID = 269,
     STRUCT = 270
   };
#endif
#define ULONG 258
#define LONG 259
#define UINT 260
#define INT 261
#define USHORT 262
#define SHORT 263
#define DOUBLE 264
#define FLOAT 265
#define UCHAR 266
#define CHAR 267
#define ST_JYXX 268
#define UDFID 269
#define STRUCT 270




/* Copy the first part of user declarations.  */
#line 1 "StmtParser.y"

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
"	prt_jyxx->jzgy = aInPkg->getLong(\"jzgy\", \"prt_jyxx\");\n"
"	prt_jyxx->cngy = aInPkg->getLong(\"cngy\", \"prt_jyxx\");\n"
"	prt_jyxx->sqgy = aInPkg->getLong(\"sqgy\", \"prt_jyxx\");\n"
"	prt_jyxx->jym = aInPkg->getLong(\"jym\", \"prt_jyxx\");\n"
"	prt_jyxx->yyrq = aInPkg->getLong(\"yyrq\", \"prt_jyxx\");\n"
"	strcpy(prt_jyxx->jgm, aInPkg->getString(\"jgm\", \"prt_jyxx\"));\n"
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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 281 "StmtParser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  9
/* YYNRULES -- Number of rules. */
#define YYNRULES  39
/* YYNRULES -- Number of states. */
#define YYNSTATES  81

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      18,    19,     3,     2,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,    21,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    17,    24,    31,
      33,    36,    39,    43,    47,    51,    55,    58,    61,    64,
      67,    70,    73,    76,    79,    82,    85,    89,    93,    96,
     100,   104,   108,   112,   116,   120,   124,   128,   132,   136
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      24,     0,    -1,    26,    -1,    25,    -1,    26,    24,    -1,
      25,    24,    -1,    31,    29,     4,    -1,    17,    16,    20,
      31,    21,     4,    -1,    17,    16,    20,    27,    21,     4,
      -1,    28,    -1,    27,    28,    -1,    31,     4,    -1,    18,
      30,    19,    -1,    18,    31,    19,    -1,    31,    22,    31,
      -1,    30,    22,    31,    -1,     5,    16,    -1,     6,    16,
      -1,     7,    16,    -1,     8,    16,    -1,     9,    16,    -1,
      10,    16,    -1,    11,    16,    -1,    12,    16,    -1,    13,
      16,    -1,    14,    16,    -1,    13,     3,    16,    -1,    14,
       3,    16,    -1,    15,    16,    -1,    17,    16,    16,    -1,
       5,     3,    16,    -1,     6,     3,    16,    -1,     7,     3,
      16,    -1,     8,     3,    16,    -1,     9,     3,    16,    -1,
      10,     3,    16,    -1,    11,     3,    16,    -1,    12,     3,
      16,    -1,    15,     3,    16,    -1,    17,    16,     3,    16,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   175,   175,   176,   177,   178,   182,   496,   531,   564,
     565,   568,   595,   596,   607,   619,   636,   641,   646,   651,
     656,   661,   666,   671,   676,   681,   686,   691,   696,   701,
     707,   712,   717,   722,   727,   732,   737,   742,   747,   752
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'*'", "';'", "ULONG", "LONG", "UINT", 
  "INT", "USHORT", "SHORT", "DOUBLE", "FLOAT", "UCHAR", "CHAR", "ST_JYXX", 
  "UDFID", "STRUCT", "'('", "')'", "'{'", "'}'", "','", "$accept", "file", 
  "funcdef", "strtdef", "members", "member", "funcparams", "params", 
  "vardef", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,    42,    59,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,    40,    41,
     123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    23,    24,    24,    24,    24,    25,    26,    26,    27,
      27,    28,    29,    29,    30,    30,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     6,     6,     1,
       2,     2,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     2,     0,     0,    16,     0,
      17,     0,    18,     0,    19,     0,    20,     0,    21,     0,
      22,     0,    23,     0,    24,     0,    25,     0,    28,     0,
       1,     5,     4,     0,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    26,    27,    38,     0,    29,     0,     0,
       0,     0,     6,    39,     0,     9,     0,     0,    12,     0,
      13,     0,     0,    10,     0,    11,     0,    15,    14,     8,
       7
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,    13,    14,    15,    64,    65,    44,    60,    16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yysigned_char yypact[] =
{
      56,     1,     3,     6,     7,     8,     9,    37,    39,    40,
      41,    43,    11,    48,    56,    56,    31,    34,   -44,    35,
     -44,    36,   -44,    38,   -44,    42,   -44,    71,   -44,    72,
     -44,    73,   -44,    74,   -44,    75,   -44,    76,   -44,    -2,
     -44,   -44,   -44,    69,    68,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,    77,   -44,    69,    78,
     -17,    -6,   -44,   -44,    24,   -44,    -1,    44,   -44,    69,
     -44,    69,    81,   -44,    91,   -44,    92,   -44,   -44,   -44,
     -44
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -44,    -7,   -44,   -44,   -44,    33,   -44,   -44,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      61,    56,    68,    75,    17,    69,    19,    41,    42,    21,
      23,    25,    27,    70,    57,    66,    71,    18,    58,    20,
      76,    74,    22,    24,    26,    28,    77,    39,    78,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      29,    59,    31,    33,    35,    72,    37,    56,    40,    43,
      45,    46,    47,    30,    48,    32,    34,    36,    49,    38,
      57,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    62,    12,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    79,    59,    50,    51,    52,
      53,    54,    55,    63,    67,    75,    80,    73
};

static const unsigned char yycheck[] =
{
      43,     3,    19,     4,     3,    22,     3,    14,    15,     3,
       3,     3,     3,    19,    16,    58,    22,    16,    20,    16,
      21,    64,    16,    16,    16,    16,    69,    16,    71,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       3,    17,     3,     3,     3,    21,     3,     3,     0,    18,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     4,    17,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     4,    17,    16,    16,    16,
      16,    16,    16,    16,    16,     4,     4,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    17,    24,    25,    26,    31,     3,    16,     3,
      16,     3,    16,     3,    16,     3,    16,     3,    16,     3,
      16,     3,    16,     3,    16,     3,    16,     3,    16,    16,
       0,    24,    24,    18,    29,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,     3,    16,    20,    17,
      30,    31,     4,    16,    27,    28,    31,    16,    19,    22,
      19,    22,    21,    28,    31,     4,    21,    31,    31,     4,
       4
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 183 "StmtParser.y"
    {
	  	struct varnode* pprm = NULL;
	  	struct varnode* pmbr = NULL;
		struct strtnode* pstrt = NULL;

		char   filename[128];
		char   str_type[128];
		FILE*  fpw = NULL;
	  		  	
		sprintf(filename, "stub_%s.cpp", yyvsp[-2].idname);
		fpw = fopen(filename, "w");
		if (fpw == NULL)
		{
			perror(filename);
			exit(0);
		}

		/* 生成程序首 */
		if (yyvsp[-2].valtype == STRT)
		{
			sprintf(str_type, "struct %s", yyvsp[-2].tpname);
		}
		else if (yyvsp[-2].valtype == PSTRT)
		{
			sprintf(str_type, "struct %s *", yyvsp[-2].tpname);
		}
		else
		{
			strcpy(str_type, g_str_type[yyvsp[-2].valtype]);
		}

	  	fprintf(fpw, g_src_head, yyvsp[-2].idname, str_type, yyvsp[-2].idname);

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
	  	fprintf(fpw, "	FuncRet = %s(\n", yyvsp[-2].idname);

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

	  ;}
    break;

  case 7:
#line 497 "StmtParser.y"
    {
	  	struct varnode* pmbr = NULL;
	  	struct strtnode* pstrt = NULL;
	  	
	  	g_mbrlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_mbrlist->var = yyvsp[-2];
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
	  		strcpy(pstrt->tpname, yyvsp[-4].idname);
	  		pstrt->mbrlist = g_mbrlist;
	  		pstrt->next = NULL;
	  		g_mbrlist = NULL;
	  	}
	  	
	  	pmbr = g_mbrlist;
	  	while (pmbr != NULL)
	  	{
	  		pmbr = pmbr->next;
	  	}
	  ;}
    break;

  case 8:
#line 532 "StmtParser.y"
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
	  		strcpy(pstrt->tpname, yyvsp[-4].idname);
	  		pstrt->mbrlist = g_mbrlist;
	  		pstrt->next = NULL;
	  		g_mbrlist = NULL;
	  	}

	  	pmbr = g_mbrlist;
	  	while (pmbr != NULL)
	  	{
	  		pmbr = pmbr->next;
	  	}
	  ;}
    break;

  case 11:
#line 569 "StmtParser.y"
    {
	  	struct varnode* p = g_mbrlist;

		if (g_mbrlist == NULL)
		{
			g_mbrlist = (struct varnode*)malloc(sizeof(struct varnode));
			g_mbrlist->var = yyvsp[-1];
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
			p->var = yyvsp[-1];
			p->next = NULL;	  
		}
	  ;}
    break;

  case 13:
#line 597 "StmtParser.y"
    {
	  	struct varnode* p = NULL;
	  	
	  	g_prmlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_prmlist->var = yyvsp[-2];
	  	g_prmlist->next = NULL;
	  ;}
    break;

  case 14:
#line 608 "StmtParser.y"
    {
	  	struct varnode* p = NULL;
	  	
	  	g_prmlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_prmlist->var = yyvsp[-2];

	  	g_prmlist->next = (struct varnode*)malloc(sizeof(struct varnode));
		p = g_prmlist->next;
	  	p->var = yyvsp[0];
	  	p->next = NULL;	  
	  ;}
    break;

  case 15:
#line 620 "StmtParser.y"
    {
	  	struct varnode* p = g_prmlist;
	  	
		while (p->next != NULL)
		{
			p = p->next;
		}
			  	
	  	p->next = (struct varnode*)malloc(sizeof(struct varnode));
	  	p = p->next;
	  	p->var = yyvsp[0];
	  	p->next = NULL;	  
	  ;}
    break;

  case 16:
#line 637 "StmtParser.y"
    { 
	  	yyval.valtype = UL;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 17:
#line 642 "StmtParser.y"
    { 
	  	yyval.valtype = L;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 18:
#line 647 "StmtParser.y"
    { 
	  	yyval.valtype = UI;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 19:
#line 652 "StmtParser.y"
    { 
	  	yyval.valtype = I;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 20:
#line 657 "StmtParser.y"
    { 
	  	yyval.valtype = USH;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 21:
#line 662 "StmtParser.y"
    { 
	  	yyval.valtype = SH;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 22:
#line 667 "StmtParser.y"
    { 
	  	yyval.valtype = D;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 23:
#line 672 "StmtParser.y"
    { 
	  	yyval.valtype = F;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 24:
#line 677 "StmtParser.y"
    { 
	  	yyval.valtype = UC;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 25:
#line 682 "StmtParser.y"
    { 
	  	yyval.valtype = C;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 26:
#line 687 "StmtParser.y"
    { 
	  	yyval.valtype = USTR;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 27:
#line 692 "StmtParser.y"
    { 
	  	yyval.valtype = STR;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 28:
#line 697 "StmtParser.y"
    { 
	  	yyval.valtype = ST_JY;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 29:
#line 702 "StmtParser.y"
    { 
	  	yyval.valtype = STRT;
	  	strcpy(yyval.tpname, yyvsp[-1].idname); 
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 30:
#line 708 "StmtParser.y"
    { 
	  	yyval.valtype = PUL;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 31:
#line 713 "StmtParser.y"
    { 
	  	yyval.valtype = PL;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 32:
#line 718 "StmtParser.y"
    { 
	  	yyval.valtype = PUI;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 33:
#line 723 "StmtParser.y"
    { 
	  	yyval.valtype = PI;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 34:
#line 728 "StmtParser.y"
    { 
	  	yyval.valtype = PUSH;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 35:
#line 733 "StmtParser.y"
    { 
	  	yyval.valtype = PSH;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 36:
#line 738 "StmtParser.y"
    { 
	  	yyval.valtype = PD;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 37:
#line 743 "StmtParser.y"
    { 
	  	yyval.valtype = PF;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 38:
#line 748 "StmtParser.y"
    { 
	  	yyval.valtype = PST_JY;
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;

  case 39:
#line 753 "StmtParser.y"
    { 
	  	yyval.valtype = PSTRT;
	  	strcpy(yyval.tpname, yyvsp[-2].idname); 
	  	strcpy(yyval.idname, yyvsp[0].idname); 
	  ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 1866 "StmtParser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  Doesn't work in C++ */
#ifndef __cplusplus
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 760 "StmtParser.y"


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

