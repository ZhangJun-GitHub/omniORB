/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
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



/* Line 268 of yacc.c  */
#line 237 "StmtParser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 294 "StmtParser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNRULES -- Number of states.  */
#define YYNSTATES  81

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    17,    24,    31,
      33,    36,    39,    43,    47,    51,    55,    58,    61,    64,
      67,    70,    73,    76,    79,    82,    85,    89,    93,    96,
     100,   104,   108,   112,   116,   120,   124,   128,   132,   136
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
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
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   176,   177,   178,   182,   496,   531,   564,
     565,   568,   595,   596,   607,   619,   636,   641,   646,   651,
     656,   661,   666,   671,   676,   681,   686,   691,   696,   701,
     707,   712,   717,   722,   727,   732,   737,   742,   747,   752
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
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
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    42,    59,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,    40,    41,
     123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    23,    24,    24,    24,    24,    25,    26,    26,    27,
      27,    28,    29,    29,    30,    30,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     6,     6,     1,
       2,     2,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    64,    65,    44,    60,    16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yytype_int8 yypact[] =
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
static const yytype_int8 yypgoto[] =
{
     -44,    -7,   -44,   -44,   -44,    33,   -44,   -44,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
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

#define yypact_value_is_default(yystate) \
  ((yystate) == (-44))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
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
static const yytype_uint8 yystos[] =
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
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
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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

/* Line 1806 of yacc.c  */
#line 183 "StmtParser.y"
    {
	  	struct varnode* pprm = NULL;
	  	struct varnode* pmbr = NULL;
		struct strtnode* pstrt = NULL;

		char   filename[128];
		char   str_type[128];
		FILE*  fpw = NULL;
	  		  	
		sprintf(filename, "stub_%s.cpp", (yyvsp[(1) - (3)]).idname);
		fpw = fopen(filename, "w");
		if (fpw == NULL)
		{
			perror(filename);
			exit(0);
		}

		/* 生成程序首 */
		if ((yyvsp[(1) - (3)]).valtype == STRT)
		{
			sprintf(str_type, "struct %s", (yyvsp[(1) - (3)]).tpname);
		}
		else if ((yyvsp[(1) - (3)]).valtype == PSTRT)
		{
			sprintf(str_type, "struct %s *", (yyvsp[(1) - (3)]).tpname);
		}
		else
		{
			strcpy(str_type, g_str_type[(yyvsp[(1) - (3)]).valtype]);
		}

	  	fprintf(fpw, g_src_head, (yyvsp[(1) - (3)]).idname, str_type, (yyvsp[(1) - (3)]).idname);

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
	  	fprintf(fpw, "	FuncRet = %s(\n", (yyvsp[(1) - (3)]).idname);

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
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 497 "StmtParser.y"
    {
	  	struct varnode* pmbr = NULL;
	  	struct strtnode* pstrt = NULL;
	  	
	  	g_mbrlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_mbrlist->var = (yyvsp[(4) - (6)]);
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
	  		strcpy(pstrt->tpname, (yyvsp[(2) - (6)]).idname);
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
    break;

  case 8:

/* Line 1806 of yacc.c  */
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
	  		strcpy(pstrt->tpname, (yyvsp[(2) - (6)]).idname);
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
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 569 "StmtParser.y"
    {
	  	struct varnode* p = g_mbrlist;

		if (g_mbrlist == NULL)
		{
			g_mbrlist = (struct varnode*)malloc(sizeof(struct varnode));
			g_mbrlist->var = (yyvsp[(1) - (2)]);
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
			p->var = (yyvsp[(1) - (2)]);
			p->next = NULL;	  
		}
	  }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 597 "StmtParser.y"
    {
	  	struct varnode* p = NULL;
	  	
	  	g_prmlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_prmlist->var = (yyvsp[(1) - (3)]);
	  	g_prmlist->next = NULL;
	  }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 608 "StmtParser.y"
    {
	  	struct varnode* p = NULL;
	  	
	  	g_prmlist = (struct varnode*)malloc(sizeof(struct varnode));
	  	g_prmlist->var = (yyvsp[(1) - (3)]);

	  	g_prmlist->next = (struct varnode*)malloc(sizeof(struct varnode));
		p = g_prmlist->next;
	  	p->var = (yyvsp[(3) - (3)]);
	  	p->next = NULL;	  
	  }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 620 "StmtParser.y"
    {
	  	struct varnode* p = g_prmlist;
	  	
		while (p->next != NULL)
		{
			p = p->next;
		}
			  	
	  	p->next = (struct varnode*)malloc(sizeof(struct varnode));
	  	p = p->next;
	  	p->var = (yyvsp[(3) - (3)]);
	  	p->next = NULL;	  
	  }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 637 "StmtParser.y"
    { 
	  	(yyval).valtype = UL;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 642 "StmtParser.y"
    { 
	  	(yyval).valtype = L;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 647 "StmtParser.y"
    { 
	  	(yyval).valtype = UI;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 652 "StmtParser.y"
    { 
	  	(yyval).valtype = I;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 657 "StmtParser.y"
    { 
	  	(yyval).valtype = USH;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 662 "StmtParser.y"
    { 
	  	(yyval).valtype = SH;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 667 "StmtParser.y"
    { 
	  	(yyval).valtype = D;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 672 "StmtParser.y"
    { 
	  	(yyval).valtype = F;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 677 "StmtParser.y"
    { 
	  	(yyval).valtype = UC;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 682 "StmtParser.y"
    { 
	  	(yyval).valtype = C;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 687 "StmtParser.y"
    { 
	  	(yyval).valtype = USTR;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 692 "StmtParser.y"
    { 
	  	(yyval).valtype = STR;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 697 "StmtParser.y"
    { 
	  	(yyval).valtype = ST_JY;
	  	strcpy((yyval).idname, (yyvsp[(2) - (2)]).idname); 
	  }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 702 "StmtParser.y"
    { 
	  	(yyval).valtype = STRT;
	  	strcpy((yyval).tpname, (yyvsp[(2) - (3)]).idname); 
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 708 "StmtParser.y"
    { 
	  	(yyval).valtype = PUL;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 713 "StmtParser.y"
    { 
	  	(yyval).valtype = PL;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 718 "StmtParser.y"
    { 
	  	(yyval).valtype = PUI;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 723 "StmtParser.y"
    { 
	  	(yyval).valtype = PI;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 728 "StmtParser.y"
    { 
	  	(yyval).valtype = PUSH;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 733 "StmtParser.y"
    { 
	  	(yyval).valtype = PSH;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 738 "StmtParser.y"
    { 
	  	(yyval).valtype = PD;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 743 "StmtParser.y"
    { 
	  	(yyval).valtype = PF;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 748 "StmtParser.y"
    { 
	  	(yyval).valtype = PST_JY;
	  	strcpy((yyval).idname, (yyvsp[(3) - (3)]).idname); 
	  }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 753 "StmtParser.y"
    { 
	  	(yyval).valtype = PSTRT;
	  	strcpy((yyval).tpname, (yyvsp[(2) - (4)]).idname); 
	  	strcpy((yyval).idname, (yyvsp[(4) - (4)]).idname); 
	  }
    break;



/* Line 1806 of yacc.c  */
#line 2289 "StmtParser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
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

