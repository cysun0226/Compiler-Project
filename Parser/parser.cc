/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <fstream>
    #include "node.h"


    using namespace std;
    FILE *pFile;

    extern "C"
    {
        int yyparse(void);
        int yylex(void);
        int yywrap()
        {
          return 1;
        }

        void yyerror(const char *str)
        {
            fprintf(pFile, "error! \n");
            fclose(pFile);
            fprintf(stderr,"error: %s\n",str);
        }

    }

    Node* ASTROOT;



#line 101 "parser.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hh".  */
#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ARRAY = 259,
    CASE = 260,
    CONST = 261,
    DIV = 262,
    DO = 263,
    DOWNTO = 264,
    ELSE = 265,
    END = 266,
    EXTERNAL = 267,
    FOR = 268,
    FORWARD = 269,
    FUNCTION = 270,
    GOTO = 271,
    IF = 272,
    IN = 273,
    INTEGER = 274,
    LABEL = 275,
    MOD = 276,
    NIL = 277,
    NOT = 278,
    OF = 279,
    OR = 280,
    OTHERWISE = 281,
    PACKED = 282,
    PBEGIN = 283,
    PFILE = 284,
    PROCEDURE = 285,
    PROGRAM = 286,
    RECORD = 287,
    REPEAT = 288,
    SET = 289,
    THEN = 290,
    TO = 291,
    TYPE = 292,
    UNTIL = 293,
    VAR = 294,
    WHILE = 295,
    WITH = 296,
    REAL = 297,
    id = 298,
    ASSIGNMENT = 299,
    CHARACTER_STRING = 300,
    COLON = 301,
    COMMA = 302,
    DIGSEQ = 303,
    DOT = 304,
    DOTDOT = 305,
    EQUAL = 306,
    GE = 307,
    GT = 308,
    LBRAC = 309,
    LE = 310,
    LPAREN = 311,
    LT = 312,
    MINUS = 313,
    PLUS = 314,
    RBRAC = 315,
    REALNUMBER = 316,
    RPAREN = 317,
    SEMICOLON = 318,
    SLASH = 319,
    STAR = 320,
    STARSTAR = 321,
    notEQUAL = 322,
    NUM = 323,
    REAL_NUM = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "parser.y" /* yacc.c:355  */

    struct Node* node;
    int number;
    char* string;

#line 217 "parser.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "parser.cc" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   164,   171,   182,   205,   215,   225,   243,
     252,   258,   271,   284,   297,   314,   319,   324,   341,   348,
     357,   368,   378,   390,   397,   406,   414,   422,   436,   441,
     450,   461,   470,   475,   486,   493,   498,   503,   511,   519,
     528,   535,   543,   553,   561,   570,   575,   587,   593,   605,
     610,   621,   626,   637,   642,   653,   660,   669,   675,   680,
     686,   694,   705,   711,   721,   727,   736,   742,   748,   754,
     760,   766
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ARRAY", "CASE", "CONST", "DIV",
  "DO", "DOWNTO", "ELSE", "END", "EXTERNAL", "FOR", "FORWARD", "FUNCTION",
  "GOTO", "IF", "IN", "INTEGER", "LABEL", "MOD", "NIL", "NOT", "OF", "OR",
  "OTHERWISE", "PACKED", "PBEGIN", "PFILE", "PROCEDURE", "PROGRAM",
  "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE",
  "WITH", "REAL", "id", "ASSIGNMENT", "CHARACTER_STRING", "COLON", "COMMA",
  "DIGSEQ", "DOT", "DOTDOT", "EQUAL", "GE", "GT", "LBRAC", "LE", "LPAREN",
  "LT", "MINUS", "PLUS", "RBRAC", "REALNUMBER", "RPAREN", "SEMICOLON",
  "SLASH", "STAR", "STARSTAR", "notEQUAL", "NUM", "REAL_NUM", "$accept",
  "prog", "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "arguments", "parameter_list", "optional_var", "compound_statement",
  "optional_statements", "statement_list", "statement", "if_stmt",
  "variable", "tail", "procedure_statement", "expression_list",
  "expression", "simple_expression", "term", "factor", "addop", "mulop",
  "relop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -13,   -21,    66,     2,   -65,   -16,   -65,   -27,    51,    41,
     -65,   -65,    22,   -16,   -16,   -16,    58,    46,    48,    38,
      62,    -7,    63,    45,   -65,    60,    19,    11,     7,    55,
     -11,   -11,    36,   -65,    96,    47,   -65,    68,   -65,    55,
     -65,    23,   -65,    50,    61,   -65,   -65,   -65,    57,   -65,
       8,    59,    82,    77,   -11,   -31,   -65,   -11,   -65,   -65,
     -65,    89,    24,     4,   -65,    64,   117,   -11,   -11,   -65,
     -65,    -7,   -11,    65,   -65,   -65,   -30,   -65,   -65,   -65,
     -65,    67,   -16,    -2,   -65,   -11,   -65,    69,    -7,   -65,
     -65,   -65,   -65,   -65,   -65,   -11,   -11,   -65,   -65,   -11,
     -65,    -7,    70,    16,   -65,   -65,   -65,   -65,    76,    83,
     -65,    54,    71,    27,   -65,   125,   -65,     4,    44,   -65,
     -65,    73,   -11,   -65,   -29,   -24,     7,   -65,   -65,    -7,
     -65,   -65,    78,    79,    80,    81,    90,    84,   -65,   112,
     118,   119,   120,    82,    11,    11,    11,    11,   -65,   -65,
     -65,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       4,     9,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,     0,     9,     0,     0,     0,     0,    24,
       0,     0,    45,    36,     0,    31,    32,     0,    35,    24,
      18,     0,     2,     0,     0,    15,    16,    17,     0,    10,
       0,     0,    29,     0,     0,    44,    58,     0,    63,    62,
      57,     0,    49,    51,    53,     0,     0,     0,     0,    42,
      30,    39,     0,     0,    20,     7,     0,     8,     6,     5,
      28,     0,     0,     0,    61,     0,    55,     0,    39,    68,
      70,    67,    69,    66,    71,     0,     0,    65,    64,     0,
      59,    39,     0,     0,    47,    33,    34,    22,     0,     0,
      23,     0,     0,     0,    60,    41,    37,    52,    50,    54,
      38,    44,     0,    46,     0,     0,     0,    21,    56,    39,
      43,    48,     0,     0,     0,     0,    26,    25,    40,     0,
       0,     0,     0,    29,     0,     0,     0,     0,    27,    14,
      12,    13,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -12,   121,   -28,    72,   -65,   -65,   -65,   107,
       5,   -65,    26,   -65,   -65,   -64,   -65,   -65,   -49,   -65,
      74,   -26,    53,    56,   -45,   -54,   -65,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    48,    49,    16,    23,    24,    53,
      81,    82,    33,    34,    35,    36,   116,    37,    69,    38,
     103,   104,    62,    63,    64,    65,    99,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    17,    18,    19,    61,    66,    86,   105,    95,    84,
      30,    44,    54,   108,   132,    44,    50,    45,     1,   134,
       8,    21,     3,    67,   115,    85,    45,     6,    13,    13,
      45,    87,    55,    31,    56,     9,    32,   120,   109,   133,
      46,   102,    25,    47,   135,    57,   106,    58,    59,    46,
       6,    21,    47,    46,   119,     8,    47,    60,     5,    14,
      14,    15,    15,   122,    95,   138,     4,    74,    97,    98,
     111,    78,   130,    20,   122,    89,    90,    91,   123,    92,
     -44,    93,    58,    59,    28,     8,    21,    43,    22,   128,
      67,    94,    68,     8,    10,     8,   131,    26,   137,    27,
     126,     8,    58,    59,    11,    29,    39,    70,    40,    42,
      71,    52,    72,    75,   136,    76,   149,   150,   151,   152,
      77,    80,    79,    83,    88,   101,   124,    67,   107,   110,
     121,   114,   100,   125,   127,   129,   144,     8,   139,   140,
     141,   142,   145,   146,   147,    41,    73,   143,   148,   118,
       0,   117,     0,     0,     0,   112,     0,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
      28,    13,    14,    15,    30,    31,    55,    71,    62,    54,
      17,     4,    23,    43,    43,     4,    28,    19,    31,    43,
      47,    28,    43,    54,    88,    56,    19,    43,     6,     6,
      19,    57,    43,    40,    45,    62,    43,   101,    68,    68,
      42,    67,    16,    45,    68,    56,    72,    58,    59,    42,
      43,    28,    45,    42,    99,    47,    45,    68,    56,    37,
      37,    39,    39,    47,   118,   129,     0,    41,    64,    65,
      82,    63,   121,    15,    47,    51,    52,    53,    62,    55,
      44,    57,    58,    59,    46,    47,    28,    68,    30,    62,
      54,    67,    56,    47,    43,    47,   122,    51,   126,    51,
      46,    47,    58,    59,    63,    43,    43,    11,    63,    49,
      63,    56,    44,    63,   126,    54,   144,   145,   146,   147,
      63,    39,    63,    46,    35,     8,    50,    54,    63,    62,
      60,    62,    68,    50,    63,    10,    24,    47,    60,    60,
      60,    60,    24,    24,    24,    24,    39,    63,   143,    96,
      -1,    95,    -1,    -1,    -1,    83,    -1,    -1,    -1,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    71,    43,     0,    56,    43,    72,    47,    62,
      43,    63,    73,     6,    37,    39,    76,    72,    72,    72,
      15,    28,    30,    77,    78,    82,    51,    51,    46,    43,
      17,    40,    43,    82,    83,    84,    85,    87,    89,    43,
      63,    73,    49,    68,     4,    19,    42,    45,    74,    75,
      72,    74,    56,    79,    23,    43,    45,    56,    58,    59,
      68,    91,    92,    93,    94,    95,    91,    54,    56,    88,
      11,    63,    44,    79,    82,    63,    54,    63,    63,    63,
      39,    80,    81,    46,    94,    56,    88,    91,    35,    51,
      52,    53,    55,    57,    67,    95,    97,    64,    65,    96,
      68,     8,    91,    90,    91,    85,    91,    63,    43,    68,
      62,    72,    75,    90,    62,    85,    86,    93,    92,    94,
      85,    60,    47,    62,    50,    50,    46,    63,    62,    10,
      88,    91,    43,    68,    43,    68,    72,    74,    85,    60,
      60,    60,    60,    63,    24,    24,    24,    24,    80,    74,
      74,    74,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    75,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    80,    81,    81,
      82,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     6,     6,     6,     0,
       1,     8,     8,     8,     8,     1,     1,     1,     3,     0,
       3,     6,     4,     3,     0,     4,     4,     6,     1,     0,
       3,     1,     1,     3,     3,     1,     1,     4,     4,     0,
       3,     1,     2,     4,     0,     1,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     4,     1,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 138 "parser.y" /* yacc.c:1646  */
    {
     printf("Reduction ( prog -> PROGRAM id (identifier_list); \n");
     printf("                    declarations \n");
     printf("                    subprogram_declarations \n");
     printf("                    compound_statement \n");
     printf("                    .                             )\n");

     fprintf(pFile, "Parse finish. \n");

     (yyval.node) = newNode(NODE_START);
     addChild((yyval.node), newNode(RE_PROG));
     addChild((yyval.node), newNode(NODE_ID));
     addChild((yyval.node), newNode(PUC_LPAREN));
     addChild((yyval.node), (yyvsp[-6].node));
     addChild((yyval.node), newNode(PUC_RPAREN));
     addChild((yyval.node), newNode(PUC_SEMI));
     addChild((yyval.node), (yyvsp[-3].node));
     addChild((yyval.node), (yyvsp[-2].node));
     addChild((yyval.node), (yyvsp[-1].node));
     addChild((yyval.node), newNode(PUC_DOT));
     ASTROOT = (yyval.node);
  }
#line 1447 "parser.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 164 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( identifier_list -> id )\n");
      (yyval.node) = newNode(NODE_ID_LT);
      Node* id_node = newNode(NODE_ID);
      id_node->string = (yyvsp[0].string);
      addChild((yyval.node), id_node);
    }
#line 1459 "parser.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 171 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( identifier_list -> identifier_list , id )\n");
      (yyval.node) = newNode(NODE_ID_LT);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(PUC_COMMA));
      addChild((yyval.node), newNode(NODE_ID));
    }
#line 1471 "parser.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 182 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( declarations -> declarations VAR identifier_list : type ; )\n");

      // 每個 reduction 都建一個新 node
      (yyval.node) = newNode(NODE_DECL); // $$ = declarations

      // addChilde($$, $1) -> $1 的 parent = $$
      // 它會推出幾個就 add 幾次
      // 像這條有 declarations VAR identifier_list COLON type SEMICOLON
      // 所以要 add 6 次

      // 如果是 non-terminal 就 addChild $i

      // terminal 就 add ($$, newNode(terminal))，terminal 是上面 %token <node> FOR 這些，
      // scanner 拆出來的每個 token 都是 terminal

      addChild((yyval.node), (yyvsp[-5].node)); // declarations 是 non-terminal，add $1 到 $$ ($1 是 $$ 的 child)
      addChild((yyval.node), newNode(NODE_VAR)); // VAR 是 terminal
      addChild((yyval.node), (yyvsp[-3].node)); // identifier_list 是 non-terminal，add $3
      addChild((yyval.node), newNode(PUC_COLON)); // 冒號是 terminal，add newNode(:)
      addChild((yyval.node), (yyvsp[-1].node)); // type 是 non-terminal，add $5
      addChild((yyval.node), newNode(PUC_SEMI)); // 冒號是 terminal，add newNode(;)
    }
#line 1499 "parser.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 205 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( declarations -> declarations VAR identifier_list : id ; )\n");
      (yyval.node) = newNode(NODE_DECL);
      addChild((yyval.node), (yyvsp[-5].node));
      addChild((yyval.node), newNode(NODE_VAR));
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), newNode(PUC_COLON));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_SEMI));
    }
#line 1514 "parser.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 215 "parser.y" /* yacc.c:1646  */
    {
    printf("Reduction ( declarations -> declarations CONST identifier_list = NUM ; )\n");
    (yyval.node) = newNode(NODE_DECL); // $$ = declarations
    addChild((yyval.node), (yyvsp[-5].node));
    addChild((yyval.node), newNode(RE_CONST));
    addChild((yyval.node), (yyvsp[-3].node));
    addChild((yyval.node), newNode(OP_EQUAL));
    addChild((yyval.node), newNode(NODE_NUM));
    addChild((yyval.node), newNode(PUC_SEMI));
    }
#line 1529 "parser.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 225 "parser.y" /* yacc.c:1646  */
    {
    printf("Reduction ( declarations -> declarations TYPE identifier_list = type ; )\n");
    (yyval.node) = newNode(NODE_DECL); // $$ = declarations
    addChild((yyval.node), (yyvsp[-5].node));
    addChild((yyval.node), newNode(RE_TYPE));
    addChild((yyval.node), (yyvsp[-3].node));
    addChild((yyval.node), newNode(OP_EQUAL));
    addChild((yyval.node), (yyvsp[-1].node));
    addChild((yyval.node), newNode(PUC_SEMI));
    }
#line 1544 "parser.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 243 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( declarations -> LAMDBA )\n");
      (yyval.node) = newNode(NODE_DECL);
      addChild((yyval.node), newNode(NODE_LAMDBA));
    }
#line 1554 "parser.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 252 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( type -> standard_type )\n");

      (yyval.node) = newNode(NODE_TYPE);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1565 "parser.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 258 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( type -> ARRAY [NUM .. NUM] OF type )\n");

      (yyval.node) = newNode(NODE_TYPE);
      addChild((yyval.node), newNode(RE_ARR));
      addChild((yyval.node), newNode(PUC_LBRAC));
      addChild((yyval.node), newNode(NODE_NUM));
      addChild((yyval.node), newNode(PUC_DOTDOT));
      addChild((yyval.node), newNode(NODE_NUM));
      addChild((yyval.node), newNode(PUC_RBRAC));
      addChild((yyval.node), newNode(RE_OF));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1583 "parser.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 271 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( type -> ARRAY [id .. NUM] OF type )\n");

      (yyval.node) = newNode(NODE_TYPE);
      addChild((yyval.node), newNode(RE_ARR));
      addChild((yyval.node), newNode(PUC_LBRAC));
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), newNode(PUC_DOTDOT));
      addChild((yyval.node), newNode(NODE_NUM));
      addChild((yyval.node), newNode(PUC_RBRAC));
      addChild((yyval.node), newNode(RE_OF));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1601 "parser.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 284 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( type -> ARRAY [NUM .. id] OF type )\n");

      (yyval.node) = newNode(NODE_TYPE);
      addChild((yyval.node), newNode(RE_ARR));
      addChild((yyval.node), newNode(PUC_LBRAC));
      addChild((yyval.node), newNode(NODE_NUM));
      addChild((yyval.node), newNode(PUC_DOTDOT));
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), newNode(PUC_RBRAC));
      addChild((yyval.node), newNode(RE_OF));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1619 "parser.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 297 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( type -> ARRAY [id .. id] OF type )\n");

      (yyval.node) = newNode(NODE_TYPE);
      addChild((yyval.node), newNode(RE_ARR));
      addChild((yyval.node), newNode(PUC_LBRAC));
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), newNode(PUC_DOTDOT));
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), newNode(PUC_RBRAC));
      addChild((yyval.node), newNode(RE_OF));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1637 "parser.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 314 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( standard_type -> INTEGER )\n");
      (yyval.node) = newNode(NODE_STDTYPE);
      addChild((yyval.node), newNode(TY_INT));
    }
#line 1647 "parser.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 319 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( standard_type -> REAL )\n");
      (yyval.node) = newNode(NODE_STDTYPE);
      addChild((yyval.node), newNode(TY_REAL));
    }
#line 1657 "parser.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 324 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( standard_type -> CHARACTER_STRING )\n");
      (yyval.node) = newNode(NODE_STDTYPE);
      addChild((yyval.node), newNode(TY_STR));
    }
#line 1667 "parser.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 341 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( subprogram_declarations -> subprogram_declarations subprogram_declaration ; )\n");
      (yyval.node) = newNode(NODE_SPROG_DECLS);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_SEMI));
   }
#line 1679 "parser.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 348 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( subprogram_declarations -> LAMDBA )\n");
      (yyval.node) = newNode(NODE_SPROG_DECLS);
      addChild((yyval.node), newNode(NODE_LAMDBA));
   }
#line 1689 "parser.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 357 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( subprogram_declaration -> subprogram_head declarations compound_statement )\n");
      (yyval.node) = newNode(NODE_SPROG_DECL);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1701 "parser.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 368 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( subprogram_head -> FUNCTION id arguments : standard_type ; )\n");
      (yyval.node) = newNode(NODE_SPROG_H);
      addChild((yyval.node), newNode(RE_FUNC));
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), newNode(PUC_COLON));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_SEMI));
    }
#line 1716 "parser.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 378 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( subprogram_head -> PROCEDURE id arguments ; )\n");
      (yyval.node) = newNode(NODE_SPROG_H);
      addChild((yyval.node), newNode(RE_PROC));
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_SEMI));
    }
#line 1729 "parser.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 390 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( arguments -> (parameter_list) )\n");
      (yyval.node) = newNode(NODE_ARG);
      addChild((yyval.node), newNode(PUC_LPAREN));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_RPAREN));
    }
#line 1741 "parser.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 397 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( arguments -> LAMDBA )\n");
      (yyval.node) = newNode(NODE_ARG);
      addChild((yyval.node), newNode(NODE_LAMDBA));
    }
#line 1751 "parser.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 406 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( parameter_list -> optional_var identifier_list : type )\n");
      (yyval.node) = newNode(NODE_PARAM_LI);
      addChild((yyval.node), (yyvsp[-3].node));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(PUC_COLON));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1764 "parser.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 414 "parser.y" /* yacc.c:1646  */
    {
    printf("Reduction ( parameter_list -> optional_var identifier_list : identifier_list )\n");
    (yyval.node) = newNode(NODE_PARAM_LI);
    addChild((yyval.node), (yyvsp[-3].node));
    addChild((yyval.node), (yyvsp[-2].node));
    addChild((yyval.node), newNode(PUC_COLON));
    addChild((yyval.node), (yyvsp[0].node));
    }
#line 1777 "parser.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 422 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
      (yyval.node) = newNode(NODE_PARAM_LI);
      addChild((yyval.node), (yyvsp[-5].node));
      addChild((yyval.node), (yyvsp[-4].node));
      addChild((yyval.node), newNode(PUC_COLON));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(PUC_SEMI));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1792 "parser.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 436 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( optional_var -> VAR )\n");
      (yyval.node) = newNode(NODE_OPTVAR);
      addChild((yyval.node), newNode(RE_VAR));
    }
#line 1802 "parser.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 441 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( optional_var -> LAMDBA )\n");
      (yyval.node) = newNode(NODE_OPTVAR);
      addChild((yyval.node), newNode(NODE_LAMDBA));
    }
#line 1812 "parser.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 450 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( compound_statement -> begin optional_statements end )\n");
      (yyval.node) = newNode(NODE_COMP_STMT);
      addChild((yyval.node), newNode(RE_BEGIN));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(RE_END));
    }
#line 1824 "parser.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 461 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( optional_statements -> statement_list )\n");
      (yyval.node) = newNode(NODE_OPT_STMT);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1834 "parser.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 470 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement_list -> statement )\n");
      (yyval.node) = newNode(NODE_STMT_LI);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1844 "parser.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 475 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement_list -> statement_list ; statement )\n");
      (yyval.node) = newNode(NODE_STMT_LI);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(PUC_SEMI));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1856 "parser.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 486 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement -> variable := expression )\n");
      (yyval.node) = newNode(NODE_STMT);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_ASGMNT));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1868 "parser.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 493 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement -> procedure_statement )\n");
      (yyval.node) = newNode(NODE_STMT);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1878 "parser.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 498 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement -> compound_statement )\n");
      (yyval.node) = newNode(NODE_STMT);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1888 "parser.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 503 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement -> IF expression THEN if_stmt )\n");
      (yyval.node) = newNode(NODE_STMT);
      addChild((yyval.node), newNode(RE_IF));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_THEN));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1901 "parser.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 511 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement -> WHILE expression DO statement )\n");
      (yyval.node) = newNode(NODE_STMT);
      addChild((yyval.node), newNode(RE_WHILE));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(RE_DO));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1914 "parser.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 519 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( statement -> lambda )\n");
      (yyval.node) = newNode(NODE_STMT);
      addChild((yyval.node), newNode(NODE_LAMDBA));
  }
#line 1924 "parser.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 528 "parser.y" /* yacc.c:1646  */
    {
        printf("Reduction ( if_stmt -> statement ELSE statement )\n");
        (yyval.node) = newNode(NODE_IF_STMT);
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), newNode(RE_ELSE));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1936 "parser.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 535 "parser.y" /* yacc.c:1646  */
    {
        printf("Reduction ( if_stmt -> statement )\n");
        (yyval.node) = newNode(NODE_IF_STMT);
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1946 "parser.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 543 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( variable -> id tail )\n");
      (yyval.node) = newNode(NODE_VAR);
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1957 "parser.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 553 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( tail -> [expression] tail )\n");
      (yyval.node) = newNode(NODE_TAIL);
      addChild((yyval.node), newNode(PUC_LBRAC));
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(PUC_RBRAC));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 1970 "parser.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 561 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( tail -> lambda )\n");
      (yyval.node) = newNode(NODE_TAIL);
      addChild((yyval.node), newNode(NODE_LAMDBA));
  }
#line 1980 "parser.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 570 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( procedure_statement -> id )\n");
      (yyval.node) = newNode(NODE_PROC_STMT);
      addChild((yyval.node), newNode(NODE_ID));
    }
#line 1990 "parser.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 575 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( procedure_statement -> id (expression_list) )\n");
      (yyval.node) = newNode(NODE_PROC_STMT);
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), newNode(PUC_LPAREN));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_RPAREN));
    }
#line 2003 "parser.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 587 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( expression_list -> expression )\n");

      (yyval.node) = newNode(NODE_EXPR_LI);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2014 "parser.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 593 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( expression_list -> expression_list, expression )\n");

      (yyval.node) = newNode(NODE_EXPR_LI);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), newNode(PUC_COMMA));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2027 "parser.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 605 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( expression -> simple_expression )\n");
      (yyval.node) = newNode(NODE_EXPR);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2037 "parser.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 610 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( expression -> simple_expression relop simple_expression )\n");
      (yyval.node) = newNode(NODE_EXPR);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2049 "parser.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 621 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( simple_expression -> term )\n");
      (yyval.node) = newNode(NODE_SI_EXPR);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2059 "parser.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 626 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( simple_expression -> simple_expression addop term )\n");
      (yyval.node) = newNode(NODE_SI_EXPR);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2071 "parser.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 637 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( term -> factor )\n");
      (yyval.node) = newNode(NODE_TERM);
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2081 "parser.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 642 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( term -> term mulop factor )\n");
      (yyval.node) = newNode(NODE_TERM);
      addChild((yyval.node), (yyvsp[-2].node));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2093 "parser.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 653 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( factor -> id tail )\n");

      (yyval.node) = newNode(NODE_FACTOR);
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2105 "parser.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 660 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( factor -> id ( expression_list ) )\n");

      (yyval.node) = newNode(NODE_FACTOR);
      addChild((yyval.node), newNode(NODE_ID));
      addChild((yyval.node), newNode(PUC_LPAREN));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_RPAREN));
    }
#line 2119 "parser.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 669 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( factor -> NUM )\n");

      (yyval.node) = newNode(NODE_FACTOR);
      addChild((yyval.node), newNode(NODE_NUM));
    }
#line 2130 "parser.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 675 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( factor -> CHARACTER_STRING )\n");
      (yyval.node) = newNode(NODE_FACTOR);
      addChild((yyval.node), newNode(NODE_STRING));
    }
#line 2140 "parser.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 680 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( factor -> addop NUM )\n");
      (yyval.node) = newNode(NODE_FACTOR);
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(NODE_NUM));
    }
#line 2151 "parser.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 686 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( factor -> ( expression ) )\n");

      (yyval.node) = newNode(NODE_FACTOR);
      addChild((yyval.node), newNode(PUC_LPAREN));
      addChild((yyval.node), (yyvsp[-1].node));
      addChild((yyval.node), newNode(PUC_RPAREN));
    }
#line 2164 "parser.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 694 "parser.y" /* yacc.c:1646  */
    {
      printf("Reduction ( factor -> NOT factor )\n");

      (yyval.node) = newNode(NODE_FACTOR);
      addChild((yyval.node), newNode(RE_NOT));
      addChild((yyval.node), (yyvsp[0].node));
    }
#line 2176 "parser.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 705 "parser.y" /* yacc.c:1646  */
    {
          printf("Reduction ( addop -> + )\n");

          (yyval.node) = newNode(NODE_ADDOP);
          addChild((yyval.node), newNode(OP_PLUS));
      }
#line 2187 "parser.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 711 "parser.y" /* yacc.c:1646  */
    {
           printf("Reduction ( addop -> - )\n");

           (yyval.node) = newNode(NODE_ADDOP);
           addChild((yyval.node), newNode(OP_MINUS));
      }
#line 2198 "parser.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 721 "parser.y" /* yacc.c:1646  */
    {
          printf("Reduction ( mulop -> * )\n");

          (yyval.node) = newNode(NODE_MULOP);
          addChild((yyval.node), newNode(OP_MUL));
      }
#line 2209 "parser.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 727 "parser.y" /* yacc.c:1646  */
    {
          printf("Reduction ( mulop -> / )\n");

          (yyval.node) = newNode(NODE_MULOP);
          addChild((yyval.node), newNode(OP_DIV));
      }
#line 2220 "parser.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 736 "parser.y" /* yacc.c:1646  */
    {
       printf("Reduction ( relop -> < )\n");

       (yyval.node) = newNode(NODE_RELOP);
       addChild((yyval.node), newNode(OP_LT));
    }
#line 2231 "parser.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 742 "parser.y" /* yacc.c:1646  */
    {
       printf("Reduction ( relop -> > )\n");

       (yyval.node) = newNode(NODE_RELOP);
       addChild((yyval.node), newNode(OP_GT));
    }
#line 2242 "parser.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 748 "parser.y" /* yacc.c:1646  */
    {
       printf("Reduction ( relop -> = )\n");

       (yyval.node) = newNode(NODE_RELOP);
       addChild((yyval.node), newNode(OP_EQUAL));
    }
#line 2253 "parser.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 754 "parser.y" /* yacc.c:1646  */
    {
       printf("Reduction ( relop -> <= )\n");

       (yyval.node) = newNode(NODE_RELOP);
       addChild((yyval.node), newNode(OP_LE));
    }
#line 2264 "parser.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 760 "parser.y" /* yacc.c:1646  */
    {
       printf("Reduction ( relop -> >= )\n");

       (yyval.node) = newNode(NODE_RELOP);
       addChild((yyval.node), newNode(OP_GE));
    }
#line 2275 "parser.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 766 "parser.y" /* yacc.c:1646  */
    {
       printf("Reduction ( relop -> != )\n");

       (yyval.node) = newNode(NODE_RELOP);
       addChild((yyval.node), newNode(OP_notEQUAL));
    }
#line 2286 "parser.cc" /* yacc.c:1646  */
    break;


#line 2290 "parser.cc" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 774 "parser.y" /* yacc.c:1906  */





int main()
{
    pFile = fopen( "result.txt", "a" );

    yyparse();
    printf("-----------------------------------------------\n");
    printTree(ASTROOT, 0);

    fclose(pFile);

    return 0;
}
