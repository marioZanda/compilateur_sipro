/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ex1.y"

  #include <ctype.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <limits.h>
  #include <stdarg.h>
  #include "stable.h"

  int yylex(void);
  void yyerror(char const *);
  #define STACK_CAPACITY 50
  #define MAXBUF 500
  #define OK 1
  #define ERR 0
  #define T_BOOL 2
  #define T_INT 3

  #define PROGRAM_START			"debut:program"

  #define NEG_VRAI				"neg:vrai"
  #define NEG_FAUX				"neg:faux"
  #define NEG_FIN				"neg:fin"

  #define OR_VRAI				"or:vrai"
  #define OR_FAUX				"or:faux"
  #define OR_FIN				"or:fin"

  #define EQ_FIN 				"eq:fin"
  #define EQ_VRAI 				"eq:vrai"
  #define EQ_FAUX 				"eq:faux"

  #define INF_FIN 				"inf:fin"
  #define INF_VRAI 				"inf:vrai"
  #define INF_FAUX 				"inf:faux"

  #define SUP_FIN 				"sup:fin"
  #define SUP_VRAI 				"sup:vrai"
  #define SUP_FAUX 				"sup:faux"

  #define INF_EQ_FIN 			"inf:eq:fin"
  #define INF_EQ_VRAI 			"inf:eq:vrai"
  #define INF_EQ_FAUX 			"inf:eq:faux"

  #define SUP_EQ_FIN 			"sup:eq:fin"
  #define SUP_EQ_VRAI 			"sup:eq:vrai"
  #define SUP_EQ_FAUX 			"sup:eq:faux"

  #define FUNCTION_DEFINITION 				"function:definition"
  #define FUNCTION_DEFINITION_FIN			"function:definition:end"
  #define FUNCTION_CALL_FIN			"function:call:end"

  #define VAR_GLOBAL			"var:global"
  #define VAR_GLOBAL_VAL 		"var:global:val"

  #define VAR_LOCAL				"var:local"
  #define VAR_LOCAL_VAL 		"var:local:val"

  #define VAR_PARAM 			"var:fun:param"
  #define VAR_PARAM_VAL 		"var:fun:param:val"

  #define VAR_PARAM_INIT		"var:fun:param:init"
  #define VAR_PARAM_INIT_FIN	"var:fun:param:init:fin"

  #define ERR_DIV_ZERO			"err:div0"
  #define ERR_DIV_ZERO_MSG		"err:div0:msg"

  #define BOOL_STR_FALSE		"bool:str:faux"
  #define BOOL_STR_TRUE			"bool:str:vrai"

  #define PRINT_TRUE			"bool:affichage:vrai"
  #define PRINT_FALSE			"bool:affichage:faux"
  #define PRINT_FIN				"bool:affichage:fin"

  char buffer1[MAXBUF];
  char buffer2[MAXBUF];

  static unsigned int new_label_number();
  static void create_label(char *buf, size_t buf_size, const char *format, ...);
  void fail_with(const char *format, ...);

  symbol_table_entry* function_def = NULL;


#line 155 "ex1.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "ex1.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_EQ = 5,                         /* EQ  */
  YYSYMBOL_OR = 6,                         /* OR  */
  YYSYMBOL_NEG = 7,                        /* NEG  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_BOOL_LEX = 10,                  /* BOOL_LEX  */
  YYSYMBOL_INT_LEX = 11,                   /* INT_LEX  */
  YYSYMBOL_VOID_LEX = 12,                  /* VOID_LEX  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_NON_ELSE = 18,                  /* NON_ELSE  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_SUP = 20,                       /* SUP  */
  YYSYMBOL_SUP_EQ = 21,                    /* SUP_EQ  */
  YYSYMBOL_INF = 22,                       /* INF  */
  YYSYMBOL_INF_EQ = 23,                    /* INF_EQ  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_n_ = 28,                     /* '\n'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_lignes = 37,                    /* lignes  */
  YYSYMBOL_ligne = 38,                     /* ligne  */
  YYSYMBOL_fixif = 39,                     /* fixif  */
  YYSYMBOL_type = 40,                      /* type  */
  YYSYMBOL_deffun = 41,                    /* deffun  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_largV = 44,                     /* largV  */
  YYSYMBOL_largs = 45,                     /* largs  */
  YYSYMBOL_blocinstr = 46,                 /* blocinstr  */
  YYSYMBOL_sdeclV = 47,                    /* sdeclV  */
  YYSYMBOL_sdecl = 48,                     /* sdecl  */
  YYSYMBOL_sinstrV = 49,                   /* sinstrV  */
  YYSYMBOL_sinstr = 50,                    /* sinstr  */
  YYSYMBOL_lexpr = 51,                     /* lexpr  */
  YYSYMBOL_lexprV = 52,                    /* lexprV  */
  YYSYMBOL_instr = 53,                     /* instr  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_55_4 = 55,                      /* @4  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_decl = 57,                      /* decl  */
  YYSYMBOL_expr = 58                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,    26,    24,    31,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   107,   108,   109,   110,   111,   112,   116,
     117,   118,   121,   135,   136,   137,   142,   160,   142,   206,
     207,   212,   253,   297,   306,   307,   311,   312,   316,   317,
     321,   322,   329,   330,   334,   335,   340,   342,   356,   373,
     378,   393,   393,   406,   412,   416,   412,   431,   477,   539,
     581,   615,   631,   646,   661,   678,   691,   740,   789,   835,
     888,   939,   955,  1006,  1052,  1061,  1070
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "AND", "EQ",
  "OR", "NEG", "TRUE", "FALSE", "BOOL_LEX", "INT_LEX", "VOID_LEX", "ID",
  "IF", "WHILE", "PRINT", "ELSE", "NON_ELSE", "RETURN", "SUP", "SUP_EQ",
  "INF", "INF_EQ", "'+'", "'-'", "'*'", "'/'", "'\\n'", "'('", "')'",
  "','", "'{'", "'}'", "';'", "'='", "$accept", "lignes", "ligne", "fixif",
  "type", "deffun", "$@1", "$@2", "largV", "largs", "blocinstr", "sdeclV",
  "sdecl", "sinstrV", "sinstr", "lexpr", "lexprV", "instr", "$@3", "@4",
  "$@5", "decl", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,    10,    40,
      41,    44,   123,   125,    59,    61
};
#endif

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,   -11,   -35,    57,   -35,   -35,   -35,   -35,   -35,   -19,
       1,    26,    57,     0,   -35,    13,    85,     3,     5,   -35,
     -35,   -35,   -35,   127,   -35,    28,   -35,    57,    57,    57,
     -35,   151,   -35,   175,    16,   251,    13,   -35,   -35,     4,
     -35,    30,    31,   -35,   -29,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,   -35,    57,    33,   267,
     199,   267,    57,   -35,   -35,   -29,    34,   251,   -35,   -35,
     -35,   -35,   -35,   -35,    57,    39,   275,    81,    15,    81,
      81,    81,    81,   -12,   -12,   -35,   -35,   267,   -35,   -35,
      41,   267,   -35,   -35,   223,    13,   251,    42,   -35,    61,
      45,    47,    59,   251,   -35,   -35,    13,   -35,   -35,    49,
      66,   251,   -35,   -35,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    55,     0,    64,    65,    13,    14,    15,    66,
       0,     0,     0,     0,     8,    24,     0,     0,     0,    11,
      36,     9,    10,     0,     4,    66,    63,    34,     0,     0,
      44,     0,    37,     0,     0,    28,    25,    26,     1,     0,
       6,     0,     0,     7,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    35,     0,    32,
       0,    12,     0,    47,    38,     0,     0,    29,    30,    27,
       2,     5,     3,    49,     0,     0,    61,    56,    62,    58,
      60,    57,    59,    51,    52,    53,    54,    33,    50,    40,
       0,    45,    23,    31,     0,    19,     0,     0,    48,     0,
       0,    20,    43,     0,    21,    17,     0,    41,    46,     0,
       0,     0,    18,    22,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,    67,   -35,   -15,   -35,   -35,   -35,   -35,   -35,
     -27,   -35,   -35,   -35,   -35,   -35,   -35,   -34,   -35,   -35,
     -35,     7,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    16,    17,    90,    18,    19,    75,   109,   100,   101,
      20,    35,    36,    66,    67,    57,    58,    21,   111,    62,
      97,    22,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    68,    26,     2,    42,    73,    74,     3,     4,     5,
      27,    31,    33,    25,    54,    55,    28,    24,    44,    45,
      46,    34,    37,     6,     7,     8,    59,    60,    61,    65,
      29,    43,    70,    93,    32,    48,    49,    50,    51,    52,
      53,    54,    55,    69,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    30,    87,    27,    71,    72,
       2,    91,   102,    88,     3,     4,     5,    92,    95,   108,
      25,    96,   103,    94,   104,   105,   107,   114,   106,   113,
      99,    15,   112,    41,     0,    38,    39,     0,     2,     0,
       0,   110,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,    52,    53,    54,    55,     0,
       0,     0,     1,    40,     2,     0,     0,    15,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    45,    46,    47,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    15,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    45,    46,    47,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    45,
      46,    47,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    45,    46,    47,     0,     0,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    45,    46,    47,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
      55,     0,     0,     0,     2,     0,     0,    98,     3,     4,
       5,     0,     0,     0,     9,    10,    11,    12,     0,     0,
      13,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      46,     0,     0,    15,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    48,    49,    50,    51,    52,
      53,    54,    55
};

static const yytype_int8 yycheck[] =
{
      15,    35,     3,     3,     1,    34,    35,     7,     8,     9,
      29,    12,    13,    13,    26,    27,    35,    28,    13,     4,
       5,    36,    15,    10,    11,    12,    27,    28,    29,    13,
      29,    28,    28,    67,    34,    20,    21,    22,    23,    24,
      25,    26,    27,    36,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    29,    57,    29,    28,    28,
       3,    62,    96,    30,     7,     8,     9,    33,    29,   103,
      13,    30,    30,    74,    13,    30,    17,   111,    31,    13,
      95,    32,   109,    16,    -1,     0,     1,    -1,     3,    -1,
      -1,   106,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    24,    25,    26,    27,    -1,
      -1,    -1,     1,    28,     3,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,     4,     5,     6,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,     4,
       5,     6,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,     4,     5,     6,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,     4,     5,     6,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,     3,    -1,    -1,    34,     7,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,
      19,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    32,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    20,    21,    22,    23,    24,
      25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    19,    28,    32,    37,    38,    40,    41,
      46,    53,    57,    58,    28,    13,    58,    29,    35,    29,
      29,    58,    34,    58,    40,    47,    48,    57,     0,     1,
      28,    38,     1,    28,    13,     4,     5,     6,    20,    21,
      22,    23,    24,    25,    26,    27,    34,    51,    52,    58,
      58,    58,    55,    34,    34,    13,    49,    50,    53,    57,
      28,    28,    28,    34,    35,    42,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    30,    34,
      39,    58,    33,    53,    58,    29,    30,    56,    34,    40,
      44,    45,    53,    30,    13,    30,    31,    17,    53,    43,
      40,    54,    46,    13,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    37,    38,
      38,    38,    39,    40,    40,    40,    42,    43,    41,    44,
      44,    45,    45,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    54,    53,    53,    55,    56,    53,    53,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     3,     2,     2,     1,     1,
       1,     1,     0,     1,     1,     1,     0,     0,     8,     0,
       1,     2,     4,     4,     0,     1,     1,     2,     0,     1,
       1,     2,     1,     2,     0,     1,     1,     2,     3,     2,
       4,     0,     9,     6,     0,     0,     7,     3,     5,     3,
       4,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* lignes: lignes error '\n'  */
#line 106 "ex1.y"
                        {yyerrok;}
#line 1319 "ex1.tab.c"
    break;

  case 3: /* lignes: ligne error '\n'  */
#line 107 "ex1.y"
                        {yyerrok; }
#line 1325 "ex1.tab.c"
    break;

  case 4: /* lignes: error '\n'  */
#line 108 "ex1.y"
                        {yyerrok; }
#line 1331 "ex1.tab.c"
    break;

  case 12: /* fixif: %empty  */
#line 122 "ex1.y"
{
	unsigned int number = new_label_number();
	(yyval.entier) = number;
	printf("; If No %d\n"
	"\tpop ax\n"
	"\tconst bx,0\n"
	"\tconst cx,if:test:neg:%d\n"
	"\tcmp ax,bx\n"
	"\tjmpc cx\n"
	, number, number);
}
#line 1347 "ex1.tab.c"
    break;

  case 13: /* type: BOOL_LEX  */
#line 135 "ex1.y"
                { (yyval.entier) = BOOL_T; }
#line 1353 "ex1.tab.c"
    break;

  case 14: /* type: INT_LEX  */
#line 136 "ex1.y"
                { (yyval.entier) = INT_T; }
#line 1359 "ex1.tab.c"
    break;

  case 15: /* type: VOID_LEX  */
#line 137 "ex1.y"
                { (yyval.entier) = VOID_T; }
#line 1365 "ex1.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 142 "ex1.y"
                {
	 
			// Vérification de l'unicité de l'identifiant de la fonction
				function_def = search_symbol_table((yyvsp[0].chaine));
				if (function_def != NULL) {
					fail_with("ID existe deja\n");
				}

			/* Ajout de l'identifiant de la fontion dans la
			table des symboles et préparation du traitement 
			de la définition de la fontion */
				function_def = new_symbol_table_entry((yyvsp[0].chaine));
				function_def->class = FUNCTION;
				function_def->nParams = 0;
				function_def->nLocalVariables = 0;
				function_def->desc[0] = (yyvsp[-1].entier);

				
			}
#line 1389 "ex1.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 160 "ex1.y"
                                        {
				printf(
					"; Saut à fin définition %s()\n"
					"\tconst dx,"FUNCTION_DEFINITION_FIN":%s\n"
					"\tjmp dx\n",
				function_def->name,
				function_def->name);

				printf(":"FUNCTION_DEFINITION":%s\n", (yyvsp[-4].chaine));

				for (int i = function_def->nParams; i > 0 ; i--) {
					printf(
						"; Code saut à l'initialisation du paramètre %d de %s()\n"
						"\tconst dx,"VAR_PARAM_INIT":%s:%d\n"
						"\tjmp dx\n"
						":"VAR_PARAM_INIT_FIN":%s:%d\n",
					i, function_def->name,
					function_def->name, i,
					function_def->name, i
					);
				}
				printf(
					"; Début de l'exécution du code de %s()\n",
				function_def->name);

			}
#line 1420 "ex1.tab.c"
    break;

  case 18: /* deffun: type ID $@1 '(' largV ')' $@2 blocinstr  */
#line 185 "ex1.y"
                                    {

			/* Fin de traitement de la définition de la fonction donc
			 libération  des ressources */
				for(int i = 0; i < function_def->nParams; i++){
					free_first_symbol_table_entry();
				}
				printf(
					"\tconst dx,"FUNCTION_CALL_FIN":%s\n"
					"\tjmp dx\n"
					"; Saut à la fin de l'exécution du code de %s()\n"
					":function:definition:end:%s\n",
				function_def->name,
				function_def->name,
				function_def->name);
				function_def = NULL;

			}
#line 1443 "ex1.tab.c"
    break;

  case 19: /* largV: %empty  */
#line 206 "ex1.y"
                        { (yyval.entier) = 0; }
#line 1449 "ex1.tab.c"
    break;

  case 20: /* largV: largs  */
#line 207 "ex1.y"
                        { (yyval.entier) = (yyvsp[0].entier); }
#line 1455 "ex1.tab.c"
    break;

  case 21: /* largs: type ID  */
#line 212 "ex1.y"
                                {
					// Vérification de l'unicité de l'identifiant de l'argument
						symbol_table_entry* function_arg = search_symbol_table((yyvsp[0].chaine));
						if (function_arg != NULL){
							fail_with("ID existe deja\n");
						}

					/* Ajout de l'identifiant de l'argument dans la
					table des symboles */
						function_arg =  new_symbol_table_entry((yyvsp[0].chaine));
						function_arg->class = LOCAL_VARIABLE;
						function_arg->desc[0] = (yyvsp[-1].entier);

					/* Mise à jour des informations de définition de
					la fontion dans la table des symboles */
						function_def->desc[function_def->nParams] = (yyvsp[-1].entier);
						function_def->nParams++;

						printf(
							"; Code de définition et d'initialisation du paramètre %s de %s()\n"
							":"VAR_PARAM_INIT":%s:%lu \n"
							"\tconst ax,"VAR_PARAM_VAL":%s:%s\n"
							"\tjmp ax\n"
							":"VAR_PARAM":%s:%s\n"
							"@int 0\n"
							":"VAR_PARAM_VAL":%s:%s\n"
							"\tpop ax\n"
							"\tconst bx,"VAR_PARAM":%s:%s\n"
							"\tstorew ax,bx\n"
							"\tconst dx,"VAR_PARAM_INIT_FIN":%s:%lu\n"
							"\tjmp dx\n",
						(yyvsp[0].chaine), function_def->name,
						function_def->name, function_def->nParams,
						function_def->name, (yyvsp[0].chaine),
						function_def->name, (yyvsp[0].chaine),
						function_def->name, (yyvsp[0].chaine),
						function_def->name, (yyvsp[0].chaine),
						function_def->name, function_def->nParams
						);
					}
#line 1500 "ex1.tab.c"
    break;

  case 22: /* largs: largs ',' type ID  */
#line 253 "ex1.y"
                        {
					// Vérification de l'unicité de l'identifiant de l'argument
						symbol_table_entry* function_arg = search_symbol_table((yyvsp[0].chaine));
						if (function_arg != NULL){
							fail_with("ID existe deja\n");
						}

					/* Ajout de l'identifiant de l'argument dans la
					table des symboles */
						function_arg =  new_symbol_table_entry((yyvsp[0].chaine));
						function_arg->class = LOCAL_VARIABLE;
						function_arg->desc[0] = (yyvsp[-1].entier);

					/* Mise à jour des informations de définition de
					la fontion dans la table des symboles */
						function_def->nParams++;
						function_def->desc[function_def->nParams] = (yyvsp[-1].entier);

						
						printf(
							"; Code de définition du paramètre %s de %s()\n"
							":"VAR_PARAM_INIT":%s:%lu\n"
							"\tconst ax,"VAR_PARAM_VAL":%s:%s\n"
							"\tjmp ax\n"
							":"VAR_PARAM":%s:%s\n"
							"@int 0\n\n"
							":"VAR_PARAM_VAL":%s:%s\n"
							"\tpop ax\n"
							"\tconst bx,"VAR_PARAM":%s:%s\n"
							"\tstorew ax,bx\n"
							"\tconst dx,"VAR_PARAM_INIT_FIN":%s:%lu\n"
							"\tjmp dx",
						(yyvsp[0].chaine), function_def->name,
						function_def->name, function_def->nParams,
						function_def->name, (yyvsp[0].chaine),
						function_def->name, (yyvsp[0].chaine),
						function_def->name, (yyvsp[0].chaine),
						function_def->name, (yyvsp[0].chaine),
						function_def->name, function_def->nParams
						);
					}
#line 1546 "ex1.tab.c"
    break;

  case 23: /* blocinstr: '{' sdeclV sinstrV '}'  */
#line 297 "ex1.y"
                        {
							for (int i = 0; i < (yyvsp[-2].entier); i++) {
								free_first_symbol_table_entry();
							}
							(yyval.entier) = (yyvsp[-2].entier) + (yyvsp[-1].entier);
						}
#line 1557 "ex1.tab.c"
    break;

  case 24: /* sdeclV: %empty  */
#line 306 "ex1.y"
                        { (yyval.entier) = 0; }
#line 1563 "ex1.tab.c"
    break;

  case 25: /* sdeclV: sdecl  */
#line 307 "ex1.y"
                        { (yyval.entier) = (yyvsp[0].entier); }
#line 1569 "ex1.tab.c"
    break;

  case 26: /* sdecl: decl  */
#line 311 "ex1.y"
                        { (yyval.entier) = 1; }
#line 1575 "ex1.tab.c"
    break;

  case 27: /* sdecl: sdecl decl  */
#line 312 "ex1.y"
                { (yyval.entier) = (yyvsp[-1].entier) + 1; }
#line 1581 "ex1.tab.c"
    break;

  case 28: /* sinstrV: %empty  */
#line 316 "ex1.y"
                        { (yyval.entier) = 0; }
#line 1587 "ex1.tab.c"
    break;

  case 29: /* sinstrV: sinstr  */
#line 317 "ex1.y"
                        { (yyval.entier) = (yyvsp[0].entier); }
#line 1593 "ex1.tab.c"
    break;

  case 30: /* sinstr: instr  */
#line 321 "ex1.y"
                        { (yyval.entier) = 1; }
#line 1599 "ex1.tab.c"
    break;

  case 31: /* sinstr: sinstr instr  */
#line 322 "ex1.y"
                { (yyval.entier) = (yyvsp[-1].entier) +1; }
#line 1605 "ex1.tab.c"
    break;

  case 32: /* lexpr: expr  */
#line 329 "ex1.y"
                        { (yyval.entier) = 1;  }
#line 1611 "ex1.tab.c"
    break;

  case 33: /* lexpr: lexpr expr  */
#line 330 "ex1.y"
                { (yyval.entier) = (yyvsp[-1].entier) + 1;}
#line 1617 "ex1.tab.c"
    break;

  case 34: /* lexprV: %empty  */
#line 334 "ex1.y"
                        { (yyval.entier) = 0; }
#line 1623 "ex1.tab.c"
    break;

  case 35: /* lexprV: lexpr  */
#line 335 "ex1.y"
                        { (yyval.entier) = (yyvsp[0].entier); }
#line 1629 "ex1.tab.c"
    break;

  case 36: /* instr: blocinstr  */
#line 340 "ex1.y"
                                { (yyval.entier) = (yyvsp[0].entier); }
#line 1635 "ex1.tab.c"
    break;

  case 37: /* instr: RETURN ';'  */
#line 342 "ex1.y"
                        {
						if (function_def == NULL) {
							fail_with("Espace global, retour de valeur impossible !");
								(yyval.entier) = ERR;
						} else {
							if (function_def->desc[0] != VOID_T) {
								fail_with("Types de retour incompatible !");
								(yyval.entier) = ERR;
							} else {
								(yyval.entier) = VOID_T;
							}
						}
					}
#line 1653 "ex1.tab.c"
    break;

  case 38: /* instr: RETURN expr ';'  */
#line 356 "ex1.y"
                        {
						if ((yyvsp[-1].entier) != ERR) {
							if (function_def == NULL) {
								fail_with("Espace global, retour de valeur impossible !");
								(yyval.entier) = ERR;
							} else {
								if ((function_def->desc[0] == INT_T && (yyvsp[-1].entier) != T_INT)
									|| (function_def->desc[0] == BOOL_T && (yyvsp[-1].entier) != T_BOOL)) {
										fail_with("Types de retour incompatible !");
										(yyval.entier) = ERR;
								} else {
									(yyval.entier) = (yyvsp[-1].entier);
								}
							}
						}
					}
#line 1674 "ex1.tab.c"
    break;

  case 39: /* instr: expr ';'  */
#line 373 "ex1.y"
                                {
 					if ((yyvsp[-1].entier) != ERR){
 						//printf("\tpop\n");
 					}
 				}
#line 1684 "ex1.tab.c"
    break;

  case 40: /* instr: ID '=' expr ';'  */
#line 378 "ex1.y"
                                {
					symbol_table_entry* ste = search_symbol_table((yyvsp[-3].chaine));
					if(ste == NULL){
						fail_with("ID n'existe pas");
					}
					if( (ste->desc[0] == INT_T && (yyvsp[-1].entier) != T_INT) || (ste->desc[0] == BOOL_T && (yyvsp[-1].entier) != T_BOOL)){
						fail_with("Type incompatible");
					}
					printf("; Code affectation variable %s\n"
					"\tpop ax\n"
					"\tconst bx,"VAR_GLOBAL":%s\n"
					"\tstorew ax,bx\n",
					 ste->name, ste->name);
				}
#line 1703 "ex1.tab.c"
    break;

  case 41: /* $@3: %empty  */
#line 393 "ex1.y"
                                   {
					printf(";si if No %d vrai et instr executé\n"
					"\tconst ax,if:fin:%d\n"
					"\tjmp ax\n"
					";si if No %d est faux\n"
					":if:test:neg:%d\n"
					, (yyvsp[-3].entier), (yyvsp[-3].entier), (yyvsp[-3].entier), (yyvsp[-3].entier));
				}
#line 1716 "ex1.tab.c"
    break;

  case 42: /* instr: IF '(' expr fixif ')' instr ELSE $@3 instr  */
#line 400 "ex1.y"
                                        {
						if ( (yyvsp[-6].entier) != T_BOOL ) { fail_with("condition du if non booleenne \n"); }
						printf(";fin du if No %d\n"
						":if:fin:%d\n"
						, (yyvsp[-5].entier), (yyvsp[-5].entier));
					}
#line 1727 "ex1.tab.c"
    break;

  case 43: /* instr: IF '(' expr fixif ')' instr  */
#line 406 "ex1.y"
                              {
				if ( (yyvsp[-3].entier) != T_BOOL ) { fail_with("condition du if non booleenne \n"); }
				printf(";si if No %d est faux\n"
				":if:test:neg:%d\n"
				, (yyvsp[-2].entier), (yyvsp[-2].entier));
			}
#line 1738 "ex1.tab.c"
    break;

  case 44: /* @4: %empty  */
#line 412 "ex1.y"
           {
	unsigned int number = new_label_number();
	(yyval.entier) = number;
	printf(":debut:while:%u\n",number);
	}
#line 1748 "ex1.tab.c"
    break;

  case 45: /* $@5: %empty  */
#line 416 "ex1.y"
             {
		printf("; while No %u\n"
		"\tpop ax\n"
		"\tconst bx,0\n"
		"\tconst cx,fin:while:%u\n"
		"\tcmp ax,bx\n"
		"\tjmpc cx\n"
		, (yyvsp[-1].entier), (yyvsp[-1].entier));
				}
#line 1762 "ex1.tab.c"
    break;

  case 46: /* instr: WHILE '(' @4 expr $@5 ')' instr  */
#line 424 "ex1.y"
                                          {
						if( (yyvsp[-3].entier) != T_BOOL ){ fail_with("condition non booléenne\n");}
						printf("; fin tour de boucle\n"
						"\tconst cx,debut:while:%u\n"
						"\tjmp cx\n"
						":fin:while:%u\n", (yyvsp[-4].entier), (yyvsp[-4].entier));
							}
#line 1774 "ex1.tab.c"
    break;

  case 47: /* instr: PRINT expr ';'  */
#line 431 "ex1.y"
                                {
					if ((yyvsp[-1].entier) == T_INT) {
 						printf("; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile\n"
						"\tcp ax,sp\n"
						"\tcallprintfd ax\n"
						"\tpop ax\n");
 					} else if ((yyvsp[-1].entier) == T_BOOL) {
						
						unsigned int labelNumber = new_label_number();
						create_label(buffer1, MAXBUF, "%s:%u", PRINT_TRUE, labelNumber);
						create_label(buffer2, MAXBUF, "%s:%u", PRINT_FIN, labelNumber);

 						printf(
							"; Affichage booleen (%d)\n"
							"\tpop ax\n"
							"\tconst bx,1\n"
							"\tconst cx,%s\n"
						// Test (expr1 == true)
							"; Comparaison de expr1 à true\n"
							"\tcmp ax,bx\n"
							"\tjmpc cx\n"
							"; Si expr1 == true saut à "PRINT_TRUE"\n"
						// PRINT_FALSE
							"; Code cible "PRINT_FALSE"\n"
							"\tconst cx,"BOOL_STR_FALSE"\n"
							"\tcallprintfs cx\n"
							"\tconst cx,%s\n"
							"\tjmp cx\n"
							"; Saut à "PRINT_FIN"\n\n"
						// PRINT_TRUE
							"; Code cible "PRINT_TRUE"\n"
							":%s\n"
							"\tconst cx,"BOOL_STR_TRUE"\n"
							"\tcallprintfs cx\n\n"
						// PRINT_FIN
							":%s\n",
						labelNumber,
						buffer1,
						buffer2,
						buffer1,
						buffer2);
 					}
				}
#line 1822 "ex1.tab.c"
    break;

  case 48: /* decl: type ID '=' expr ';'  */
#line 477 "ex1.y"
                        {
	 					// Vérifier la comatibilité des types
						// Ajouter l'ID dans la table des symboles en fontion
						//  de la portée de la varible
						// 		* Si analyes de definition de fonction variable locale
						//		* Sinon variable globale
							if (((yyvsp[-1].entier) == T_INT && (yyvsp[-4].entier) == INT_T) || ((yyvsp[-1].entier) == T_BOOL && (yyvsp[-4].entier) == BOOL_T) ) {
								
								symbol_table_entry* var = search_symbol_table((yyvsp[-3].chaine));
								if (var != NULL){
									fail_with("ID existe deja\n");
								}
								
								var = new_symbol_table_entry((yyvsp[-3].chaine));
								var->desc[0] = (yyvsp[-4].entier);

								if (function_def != NULL) {
							// Analyse d'une fonction la variable est locale
							// Mise à jour de la définition de la fonction
									var->class = LOCAL_VARIABLE;
									function_def->nLocalVariables++;
									printf(
										"; Code nouvelle variable locale (%s, %s)\n"
										"\tconst ax,"VAR_LOCAL_VAL":%s:%s\n"
										"\tjmp ax\n"
										"; Saut à "VAR_LOCAL_VAL"\n\n"
										":"VAR_LOCAL":%s:%s\n"
										"@int 0\n\n"
										":"VAR_LOCAL_VAL":%s:%s\n"
										"\tpop ax\n"
										"\tconst bx,"VAR_LOCAL":%s:%s\n"
										"\tstorew ax,bx\n",
									function_def->name, (yyvsp[-3].chaine),
									function_def->name, (yyvsp[-3].chaine),
									function_def->name, (yyvsp[-3].chaine),
									function_def->name, (yyvsp[-3].chaine),
									function_def->name, (yyvsp[-3].chaine));
								} else {
							// Aucune analyse de fonction en cours, la variable est globale
									var->class = GLOBAL_VARIABLE;

									printf(
										"; Code nouvelle variable globale %s\n"
										"\tconst ax,"VAR_GLOBAL_VAL":%s\n"
										"\tjmp ax\n"
										"; Saut à "VAR_GLOBAL_VAL"\n\n"
										":"VAR_GLOBAL":%s\n"
										"@int 0\n\n"
										":"VAR_GLOBAL_VAL":%s\n"
										"\tpop ax\n"
										"\tconst bx,"VAR_GLOBAL":%s\n"
										"\tstorew ax,bx\n",
									(yyvsp[-3].chaine), (yyvsp[-3].chaine), (yyvsp[-3].chaine), (yyvsp[-3].chaine), (yyvsp[-3].chaine));
								}

								(yyval.entier) = (yyvsp[-1].entier);

							} else {
								(yyval.entier) = ERR;
								fail_with("Type imcompatible !");
							}
						}
#line 1889 "ex1.tab.c"
    break;

  case 49: /* decl: type ID ';'  */
#line 539 "ex1.y"
                {
						// Ajouter l'ID dans la table des symboles en fontion
						//  de la portée de la varible
						// 		* Si analye de definition de fonction variable locale
						//		* Sinon variable globale
								symbol_table_entry* var = search_symbol_table((yyvsp[-1].chaine));
								if (var != NULL){
									fail_with("ID existe deja\n");
								}

								var = new_symbol_table_entry((yyvsp[-1].chaine));
								var->desc[0] = (yyvsp[-2].entier);
								
								if (function_def != NULL) {
							// Analyse d'une fonction la variable est locale
							// Mise à jour de la définition de la fonction
									var->class = LOCAL_VARIABLE;
									function_def->nLocalVariables++;
									printf(
										"; Code nouvelle variable locale (%s, %s)\n"
										":"VAR_LOCAL":%s:%s\n"
										"@int 0\n",
									function_def->name, (yyvsp[-1].chaine),
									function_def->name, (yyvsp[-1].chaine));

								} else {
							// Aucune analyse de fonction en cours, la variable est globale
									var->class = GLOBAL_VARIABLE;

									printf(
										"; Code nouvelle variable globale %s\n"
										":"VAR_GLOBAL":%s\n"
										"@int 0\n",
									(yyvsp[-1].chaine), (yyvsp[-1].chaine));
								}

								(yyval.entier) = ((yyvsp[-2].entier) == INT_T) ? T_INT : T_BOOL;
						}
#line 1932 "ex1.tab.c"
    break;

  case 50: /* expr: ID '(' lexprV ')'  */
#line 581 "ex1.y"
                                {
						// Vérifation de l'existance de la définition de la fonction
							symbol_table_entry* fun = search_symbol_table((yyvsp[-3].chaine));

							if (fun == NULL) {
								fail_with("ID n'existe pas déja\n");
								(yyval.entier) = ERR;
							}


						// Traitement de l'appel de la function 
						// Vérification de l'appel avec nombre de paramètres correct
							if ((yyvsp[-1].entier) != fun->nParams ) {
								fail_with(
									"Syntaxe incorrecte:\n"
									"\t%s() a %d arguments\n",
								(yyvsp[-3].chaine), (yyvsp[-1].entier));
							}


							//- Exécution de la fonction */
							printf(
								"; Saut à %s() pour exécution\n"
								"\tconst dx,"FUNCTION_DEFINITION":%s\n"
								"\tjmp dx\n"
								":"FUNCTION_CALL_FIN":%s\n",
							fun->name,
							fun->name,
							fun->name);

							(yyval.entier) = (fun->desc[0] == INT_T)
								? T_INT
								: T_BOOL;
						}
#line 1971 "ex1.tab.c"
    break;

  case 51: /* expr: expr '+' expr  */
#line 615 "ex1.y"
                        {
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer l'addition
						if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT ){
							printf(
								"; Debut addition\n"
								"\tpop ax\n"
								"\tpop bx\n"
								"\tadd bx,ax\n"
								"\tpush bx\n");

							(yyval.entier) = T_INT;
						} else {
							(yyval.entier) = ERR;
						}
					}
#line 1992 "ex1.tab.c"
    break;

  case 52: /* expr: expr '-' expr  */
#line 631 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer la soustraction
							if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT){
								printf(
									"; Debut soustraction\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tsub bx,ax\n"
									"\tpush bx\n");
								(yyval.entier) = T_INT;
							} else {
								(yyval.entier) = ERR;
							}
						}
#line 2012 "ex1.tab.c"
    break;

  case 53: /* expr: expr '*' expr  */
#line 646 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer la multiplication
							if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT){
								printf(
									"; Debut multiplication\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tmul bx,ax\n"
									"\tpush bx\n");
								(yyval.entier) = T_INT;
							} else {
								(yyval.entier) = ERR;
							}
						}
#line 2032 "ex1.tab.c"
    break;

  case 54: /* expr: expr '/' expr  */
#line 661 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer la division
							if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT){
								printf(
									"; Debut division"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tconst cx,"ERR_DIV_ZERO"\n"
									"\tdiv bx,ax\n"
									"\tjmpe cx\n"
									"\tpush bx\n");
								(yyval.entier) = T_INT;
							} else {
								(yyval.entier) = ERR;
							}
						}
#line 2054 "ex1.tab.c"
    break;

  case 55: /* expr: NUMBER  */
#line 678 "ex1.y"
                                        {
							printf(
								"; Ajout du nombre %d\n"
								"\tconst ax,%d\n"
								"\tpush ax\n",
							(yyvsp[0].entier),
							(yyvsp[0].entier));

							(yyval.entier) = T_INT;
						}
#line 2069 "ex1.tab.c"
    break;

  case 56: /* expr: expr EQ expr  */
#line 691 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le EQ
							if ((yyvsp[-2].entier) == (yyvsp[0].entier) && (yyvsp[-2].entier) != ERR) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", EQ_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", EQ_FIN, labelNumber);

								printf(
									"; Debut EQ (%d)\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tconst cx,%s\n"
								// Test (expr1 == expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Si expr1 == expr2 saut à "EQ_VRAI"\n"
									"; Si expr1 != expr2 code cible "EQ_FAUX"\n"
								//EQ_FAUX
									"; Code cible "EQ_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n"
									";Saut à "EQ_FIN"\n"
								//EQ_VRAI
									"; Code cible "EQ_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
								// EQ_FIN
									"; Code cible "EQ_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								(yyval.entier) = T_BOOL;
							} else {
								(yyval.entier) = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
								printf("; Fin EQ\n");
						}
#line 2123 "ex1.tab.c"
    break;

  case 57: /* expr: expr INF expr  */
#line 740 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le INF
							if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", INF_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", INF_FIN, labelNumber);

								printf(
									"; Debut INF (%d)\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
									// Test (expr1 < expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tsless ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 < expr2) saut à "INF_VRAI"\n"
									"; Si (expr1 !(<) expr2) code cible "INF_FAUX"\n"
									//INF_FAUX
									"; Code cible "INF_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
									";Saut à "INF_FIN"\n"
									//INF_VRAI
									"; Code cible "INF_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
									// INF_FIN
									"; Code cible "INF_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								(yyval.entier) = T_BOOL;
							} else {
								(yyval.entier) = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf("; Fin INF\n");
						}
#line 2177 "ex1.tab.c"
    break;

  case 58: /* expr: expr SUP expr  */
#line 789 "ex1.y"
                        {
							if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", SUP_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", SUP_FIN, labelNumber);

								printf(
									"; Debut SUP %d\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
									// Test (expr2 < expr1)
									"; Comparaison de expr1 et expr2\n"
									"\tsless bx,ax\n"
									"\tjmpc cx\n"
									"; Si expr2 < expr1 saut à "SUP_VRAI"\n"
									"; Si expr2 !(<) expr1 code cible "SUP_FAUX"\n"
									//EQ_FAUX
									"; Code cible "SUP_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
									";Saut à "SUP_FIN"\n"
									//EQ_VRAI
									"; Code cible "SUP_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
									// EQ_FIN
									"; Code cible "SUP_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								(yyval.entier) = T_BOOL;
							} else {
								(yyval.entier) = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf("; Fin SUP\n");
						}
#line 2228 "ex1.tab.c"
    break;

  case 59: /* expr: expr INF_EQ expr  */
#line 835 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le INF_EQ
							if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", INF_EQ_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", INF_EQ_FIN, labelNumber);
								
								printf(
									"; Debut INF_EQ %d\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
									// Test (expr1 == expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 == expr2) saut à "INF_EQ_VRAI"\n"
									// Test (expr1 < expr2)
									"\tsless ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 < expr2) saut à "INF_EQ_VRAI"\n"
									"; Si (expr1 !(<=) expr2) code cible "INF_EQ_FAUX"\n"
									//INF_EQ_FAUX
									"; Code cible "INF_EQ_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
									"; Saut à "INF_EQ_FIN"\n"
									//INF_EQ_VRAI
									"; Code cible "INF_EQ_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
									// INF_EQ_FIN
									"; Code cible "INF_EQ_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								(yyval.entier) = T_BOOL;
							} else {
								(yyval.entier) = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf("; Fin INF_EQ\n");
                      	}
#line 2286 "ex1.tab.c"
    break;

  case 60: /* expr: expr SUP_EQ expr  */
#line 888 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le SUP_EQ
							if ((yyvsp[-2].entier) == T_INT && (yyvsp[0].entier) == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", SUP_EQ_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", SUP_EQ_FIN, labelNumber);
								printf(
									"; Debut SUP_EQ (%d)\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
								// Test (expr1 == expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 == expr2) saut à "SUP_EQ_VRAI"\n"
								// Test (expr1 < expr2)
									"\tsless bx,ax\n"
									"\tjmpc cx\n"
									"; Si (expr2 < expr1) saut à "SUP_EQ_VRAI"\n"
									"; Si (expr2 !(<=) expr1) code cible "SUP_EQ_FAUX"\n"
								// SUP_EQ_FAUX
									"; Code cible "SUP_EQ_FAUX"\n"
									"\tconst dx,0\n"
									"; Saut à "SUP_EQ_FIN"\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
								// SUP_EQ_VRAI
									"; Code cible "SUP_EQ_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
								// SUP_EQ_FIN
									"; Code cible "SUP_EQ_FIN"\n"
									":%s\n"
									"\tpush dx\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								(yyval.entier) = T_BOOL;
							} else {
								(yyval.entier) = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf(";Fin INF_EQ\n");
                      	}
#line 2342 "ex1.tab.c"
    break;

  case 61: /* expr: expr AND expr  */
#line 939 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// puis évaluer le ET (epxr1 * expr2 car true = 1)
							if ((yyvsp[-2].entier) == T_BOOL && (yyvsp[0].entier) == T_BOOL){
								printf(
									"; Code cible AND\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tmul bx,ax\n"
									"\tpush bx\n");
								(yyval.entier) = T_BOOL;
							} else {
								(yyval.entier) = ERR;
							}
							printf("; Fin AND\n");
						}
#line 2363 "ex1.tab.c"
    break;

  case 62: /* expr: expr OR expr  */
#line 955 "ex1.y"
                                {
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le OU
							if ((yyvsp[-2].entier) == T_BOOL && (yyvsp[0].entier) == T_BOOL) {
									unsigned int labelNumber = new_label_number();
									create_label(buffer1, MAXBUF, "%s:%u", OR_VRAI, labelNumber);
									create_label(buffer2, MAXBUF, "%s:%u", OR_FIN, labelNumber);
									
									printf(
										"; Debut OU (%d)\n"
										"\tconst cx,%s\n"
										"\tpop bx\n"
										"\tpop ax\n"
									// Test (expr1 == true)
										"; Comparaison à true de expr1\n"
										"\tconst dx,1\n"
										"\tcmp ax,dx\n"
										"\tjmpc cx\n"
										"; Saut à "OR_VRAI" si expr1 == vrai\n"
									// Test (expr2 == true)
										"; Comparaison à true de expr2\n"
										"\tcmp bx,dx\n"
										"\tjmpc cx\n"
										"; Saut à "OR_VRAI" si expr2 est vrai\n"
										"; L'esxpressin est évaluée à false\n"
									// OR_FAUX
										"; Code cible "OR_FAUX"\n"
										"\tconst bx,0\n"
										"\tpush bx\n"
										"\tconst dx,%s\n"
										"\tjmp dx\n"
									// OR_VRAI
										"; Code cible "OR_VRAI"\n"
										":%s\n"
										"\tconst bx,1\n"
										"\tpush bx\n"
									// OR_FIN
										"; Code cible "OR_FIN"\n"
										":%s\n",
									labelNumber,
									buffer1,
									buffer2,
									buffer1,
									buffer2);
									(yyval.entier) = T_BOOL;
							} else {
								(yyval.entier) = ERR;
							}
							printf("; Fin OR\n");
						}
#line 2419 "ex1.tab.c"
    break;

  case 63: /* expr: NEG expr  */
#line 1006 "ex1.y"
                                        {
						// Vérifier que expr est de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer la négation
							if ((yyvsp[0].entier) == T_BOOL) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", NEG_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", NEG_FIN, labelNumber);
								printf(
									"; Debut NEG (%d)\n"
									"\tconst cx,%s\n"
									"\tpop ax\n"
								// Test (expr == false)
									"; Comparaison à false\n"
									"\tconst bx,0\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Saut  à "NEG_VRAI" en cas d'égalité\n"
								// NEG_FAUX
									"; La comparison est évaluée à true\n"
									"; Code cible "NEG_FAUX"\n"
									"\tpush bx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n"
									"; Saut  à "NEG_FIN"\n"
								// NEG VRAI
									"; Code cible "NEG_VRAI"\n"
									":%s\n"
									"\tconst bx,1\n"
									"\tpush bx\n"
								// NEG_FIN
									"; Code cible "NEG_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								(yyval.entier) = T_BOOL;

							}else{
								(yyval.entier) = ERR;
							}
							printf("; Fin NEG\n");
						}
#line 2470 "ex1.tab.c"
    break;

  case 64: /* expr: TRUE  */
#line 1052 "ex1.y"
                                        {
						// Ajouter true en pile
							printf(
								"; Ajout de TRUE\n"
								"\tconst ax,%u\n"
								"\tpush ax\n",
							1);
							(yyval.entier) = T_BOOL;
						}
#line 2484 "ex1.tab.c"
    break;

  case 65: /* expr: FALSE  */
#line 1061 "ex1.y"
                                        {
						// Ajouter false en pile
							printf(
								"; Ajout de FALSE\n"
								"\tconst ax,%u\n"
								"\tpush ax\n",
							0);
							(yyval.entier) = T_BOOL;
						}
#line 2498 "ex1.tab.c"
    break;

  case 66: /* expr: ID  */
#line 1070 "ex1.y"
                                        {
						// Vérifation de l'existance de la déclaration de la variable
							symbol_table_entry* var = search_symbol_table((yyvsp[0].chaine));

							if (var == NULL){
								//fail_with("%s n'a pas été déclaré\n", $1);
								(yyval.entier) = ERR;
							} else if (function_def == NULL && var->class == GLOBAL_VARIABLE) {
						// Accès à une varibale globale
								printf(
									"; Debut évaluation ID (variable globale)\n"
									"; Recuperation valeur de %s et mise en pile\n"
									"\tconst bx,"VAR_GLOBAL":%s\n"
									"\tloadw ax,bx\n"
									"\tpush ax\n",
								var->name,
								var->name);

								(yyval.entier) = (var->desc[0] == INT_T)
									? T_INT
									: T_BOOL;

							} else if (function_def != NULL && var->class == LOCAL_VARIABLE) {
						// Accès à une varibale locale ou un paramètre
								printf(
									"; Debut évaluation ID (variable locale)\n"
									"; Recuperation valeur de %s:%s et mise en pile\n"
									"\tconst bx,"VAR_LOCAL":%s:%s\n"
									"\tloadw ax,bx\n"
									"\tpush ax\n",
								function_def->name, (yyvsp[0].chaine),
								function_def->name, (yyvsp[0].chaine));
								(yyval.entier) = (var->desc[0] == INT_T)
									? T_INT
									: T_BOOL;
							} else {
						// ID n'est pas une varibale ou un paramètre
								(yyval.entier) = ERR;
							}
						}
#line 2543 "ex1.tab.c"
    break;


#line 2547 "ex1.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1111 "ex1.y"


void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}

static unsigned int new_label_number() {
	static unsigned int current_label_number = 0u;
	if ( current_label_number == UINT_MAX ) {
		fail_with("Error: maximum label number reached!\n");
	}
	return current_label_number++;
}
/*
* char buffer1[MAXBUF], char buffer2[MAXBUF];
* unsigned ln = new_label_number();
* create_label(buffer1, MAXBUF, "%s:%u:%s", "loop", ln, "begin"); // "loop:10:begin"
* create_label(buffer2, MAXBUF, "%s:%u:%s", "loop", ln, "end");  //  "loop:10:end"
*/

static void create_label(char *buf, size_t buf_size, const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	if ( vsnprintf(buf, buf_size, format, ap) >= buf_size ) {
		va_end(ap);
		fail_with("Error in label generation: size of label exceeds maximum size!\n");
	}
	va_end(ap);
}

void fail_with(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}

int main (int argc, char** argv){
	printf(
		"; Calculette\n"
		"\tconst ax,"PROGRAM_START"\n"
		"\tjmp ax\n"
		":"PROGRAM_START"\n"
		"; Préparation de la pile\n"
		"\tconst bp,pile\n"
		"\tconst sp,pile\n"
		"\tconst ax,2\n"
		"\tsub sp,ax\n");

	yyparse();

	printf(
		"\tend\n"
		"; La zone de pile\n"
		":pile\n"
		"@int 0\n\n"
		"; Définition Chaine de charactère boolean faux\n"
		":"BOOL_STR_FALSE"\n"
		"@string \"false\"\n\n"
		"; Définition Chaine de charactère boolean true\n"
		":"BOOL_STR_TRUE"\n"
		"@string \"true\"\n\n"
		"; Définition chaine de charactère erreur de division par zéro\n"
		":"ERR_DIV_ZERO_MSG"\n"
		"@string \"Erreur: division par 0\"\n\n"
		"; Code cible erreur de division par zéro\n"
		":"ERR_DIV_ZERO"\n"
		"\tconst ax,"ERR_DIV_ZERO_MSG"\n"
		"\tcallprintfs ax\n"
		"\tend\n"
	);
	return 0;
}
