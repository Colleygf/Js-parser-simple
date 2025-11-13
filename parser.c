/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "ast.h"
#include "parser_types.h"

// 声明函数
int yylex(void);
void yyerror(ScannerState *scanner, const char *s);

// 声明全局变量
extern ScannerState *global_scanner;

// 全局 AST 根节点
ASTNode* ast_root = NULL;


#line 91 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_FUNCTION = 7,                   /* FUNCTION  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_LET = 9,                        /* LET  */
  YYSYMBOL_CONST = 10,                     /* CONST  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_TRUE = 14,                      /* TRUE  */
  YYSYMBOL_FALSE = 15,                     /* FALSE  */
  YYSYMBOL_NULL_LITERAL = 16,              /* NULL_LITERAL  */
  YYSYMBOL_UNDEFINED = 17,                 /* UNDEFINED  */
  YYSYMBOL_NEWLINE = 18,                   /* NEWLINE  */
  YYSYMBOL_IDENTIFIER = 19,                /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 20,                    /* NUMBER  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_STAR = 24,                      /* STAR  */
  YYSYMBOL_SLASH = 25,                     /* SLASH  */
  YYSYMBOL_PERCENT = 26,                   /* PERCENT  */
  YYSYMBOL_EQUALS = 27,                    /* EQUALS  */
  YYSYMBOL_EQ_EQ = 28,                     /* EQ_EQ  */
  YYSYMBOL_NOT_EQ = 29,                    /* NOT_EQ  */
  YYSYMBOL_STRICT_EQ = 30,                 /* STRICT_EQ  */
  YYSYMBOL_STRICT_NOT_EQ = 31,             /* STRICT_NOT_EQ  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_LE = 33,                        /* LE  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_BANG = 36,                      /* BANG  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_PLUS_PLUS = 39,                 /* PLUS_PLUS  */
  YYSYMBOL_MINUS_MINUS = 40,               /* MINUS_MINUS  */
  YYSYMBOL_PLUS_EQ = 41,                   /* PLUS_EQ  */
  YYSYMBOL_MINUS_EQ = 42,                  /* MINUS_EQ  */
  YYSYMBOL_STAR_EQ = 43,                   /* STAR_EQ  */
  YYSYMBOL_SLASH_EQ = 44,                  /* SLASH_EQ  */
  YYSYMBOL_LPAREN = 45,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 46,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 47,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 48,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 49,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 50,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 52,                     /* COMMA  */
  YYSYMBOL_DOT = 53,                       /* DOT  */
  YYSYMBOL_COLON = 54,                     /* COLON  */
  YYSYMBOL_QUESTION = 55,                  /* QUESTION  */
  YYSYMBOL_ERROR = 56,                     /* ERROR  */
  YYSYMBOL_POSTFIX = 57,                   /* POSTFIX  */
  YYSYMBOL_ASSIGNMENT = 58,                /* ASSIGNMENT  */
  YYSYMBOL_BITWISE_OR = 59,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 60,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_AND = 61,               /* BITWISE_AND  */
  YYSYMBOL_EQUALITY = 62,                  /* EQUALITY  */
  YYSYMBOL_RELATIONAL = 63,                /* RELATIONAL  */
  YYSYMBOL_SHIFT = 64,                     /* SHIFT  */
  YYSYMBOL_ADDITIVE = 65,                  /* ADDITIVE  */
  YYSYMBOL_MULTIPLICATIVE = 66,            /* MULTIPLICATIVE  */
  YYSYMBOL_EXPONENTIAL = 67,               /* EXPONENTIAL  */
  YYSYMBOL_UNARY = 68,                     /* UNARY  */
  YYSYMBOL_CALL = 69,                      /* CALL  */
  YYSYMBOL_PRE_INC = 70,                   /* PRE_INC  */
  YYSYMBOL_PRE_DEC = 71,                   /* PRE_DEC  */
  YYSYMBOL_POST_INC = 72,                  /* POST_INC  */
  YYSYMBOL_POST_DEC = 73,                  /* POST_DEC  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_program = 75,                   /* program  */
  YYSYMBOL_statements = 76,                /* statements  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_variable_declaration = 78,      /* variable_declaration  */
  YYSYMBOL_optional_initializer = 79,      /* optional_initializer  */
  YYSYMBOL_expression_statement = 80,      /* expression_statement  */
  YYSYMBOL_asi_semicolon = 81,             /* asi_semicolon  */
  YYSYMBOL_empty_statement = 82,           /* empty_statement  */
  YYSYMBOL_block_statement = 83,           /* block_statement  */
  YYSYMBOL_if_statement = 84,              /* if_statement  */
  YYSYMBOL_while_statement = 85,           /* while_statement  */
  YYSYMBOL_for_statement = 86,             /* for_statement  */
  YYSYMBOL_for_init = 87,                  /* for_init  */
  YYSYMBOL_for_cond = 88,                  /* for_cond  */
  YYSYMBOL_for_iter = 89,                  /* for_iter  */
  YYSYMBOL_variable_declaration_no_semi = 90, /* variable_declaration_no_semi  */
  YYSYMBOL_function_declaration = 91,      /* function_declaration  */
  YYSYMBOL_parameter_list_opt = 92,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 93,            /* parameter_list  */
  YYSYMBOL_return_statement = 94,          /* return_statement  */
  YYSYMBOL_break_statement = 95,           /* break_statement  */
  YYSYMBOL_continue_statement = 96,        /* continue_statement  */
  YYSYMBOL_expression_opt = 97,            /* expression_opt  */
  YYSYMBOL_expression = 98,                /* expression  */
  YYSYMBOL_assignment_expression = 99,     /* assignment_expression  */
  YYSYMBOL_conditional_expression = 100,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 101,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 102,   /* logical_and_expression  */
  YYSYMBOL_equality_expression = 103,      /* equality_expression  */
  YYSYMBOL_relational_expression = 104,    /* relational_expression  */
  YYSYMBOL_additive_expression = 105,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 106, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 107,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 108,       /* postfix_expression  */
  YYSYMBOL_call_expression = 109,          /* call_expression  */
  YYSYMBOL_member_expression = 110,        /* member_expression  */
  YYSYMBOL_primary_expression = 111,       /* primary_expression  */
  YYSYMBOL_argument_list_opt = 112,        /* argument_list_opt  */
  YYSYMBOL_argument_list = 113             /* argument_list  */
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
typedef yytype_uint8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    97,   101,   107,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   140,   145,   150,
     158,   159,   164,   172,   173,   174,   179,   187,   192,   201,
     205,   213,   221,   228,   229,   230,   234,   235,   239,   240,
     244,   249,   254,   263,   273,   278,   285,   292,   311,   319,
     326,   333,   334,   339,   343,   344,   349,   354,   359,   364,
     372,   373,   380,   381,   388,   389,   396,   397,   401,   405,
     409,   416,   417,   421,   425,   429,   436,   437,   441,   448,
     449,   453,   457,   464,   465,   469,   473,   481,   482,   483,
     488,   493,   498,   506,   507,   508,   509,   513,   520,   521,
     525,   529,   533,   537,   544,   549,   554,   558,   565,   566,
     567,   568,   569,   570,   571,   572,   577,   582,   589,   596
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "FOR", "FUNCTION", "VAR", "LET", "CONST", "RETURN", "BREAK", "CONTINUE",
  "TRUE", "FALSE", "NULL_LITERAL", "UNDEFINED", "NEWLINE", "IDENTIFIER",
  "NUMBER", "STRING", "PLUS", "MINUS", "STAR", "SLASH", "PERCENT",
  "EQUALS", "EQ_EQ", "NOT_EQ", "STRICT_EQ", "STRICT_NOT_EQ", "LT", "LE",
  "GT", "GE", "BANG", "AND", "OR", "PLUS_PLUS", "MINUS_MINUS", "PLUS_EQ",
  "MINUS_EQ", "STAR_EQ", "SLASH_EQ", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "DOT", "COLON",
  "QUESTION", "ERROR", "POSTFIX", "ASSIGNMENT", "BITWISE_OR",
  "BITWISE_XOR", "BITWISE_AND", "EQUALITY", "RELATIONAL", "SHIFT",
  "ADDITIVE", "MULTIPLICATIVE", "EXPONENTIAL", "UNARY", "CALL", "PRE_INC",
  "PRE_DEC", "POST_INC", "POST_DEC", "$accept", "program", "statements",
  "statement", "variable_declaration", "optional_initializer",
  "expression_statement", "asi_semicolon", "empty_statement",
  "block_statement", "if_statement", "while_statement", "for_statement",
  "for_init", "for_cond", "for_iter", "variable_declaration_no_semi",
  "function_declaration", "parameter_list_opt", "parameter_list",
  "return_statement", "break_statement", "continue_statement",
  "expression_opt", "expression", "assignment_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "call_expression", "member_expression",
  "primary_expression", "argument_list_opt", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     269,   -35,   -23,   -16,    22,    41,    51,    64,    42,    -1,
      -1,   -62,   -62,   -62,   -62,   -11,   -62,   -62,    52,    52,
      52,    52,    52,    42,   175,   -62,    76,   269,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
      -1,   -62,   -62,   -27,    56,    88,    89,    57,    27,   -62,
      50,    75,    58,    59,    42,    42,     4,    90,    82,    82,
      82,    -1,   -62,   -62,   -62,   -62,   -62,    42,    42,    42,
      42,    42,   -62,   -62,   -62,   -62,   -62,   -62,    91,   -62,
     222,   -62,   -62,   -62,    52,    42,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
     -62,   -62,    42,    42,    42,   117,    42,    42,   119,    93,
      94,   122,   123,   124,    95,   -62,   -62,   125,    42,    -1,
      -1,    -1,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
      56,    96,    88,    89,    89,    89,    89,    57,    57,    57,
      57,    27,    27,   -62,   -62,   -62,   -62,    99,    97,   101,
      98,   -62,   105,   103,   -62,   269,   269,    82,    82,    82,
      42,   -62,   108,   104,   -62,   -62,   -62,   -62,    52,   -62,
      42,   -62,   -62,   -62,   -62,   151,   -62,   -62,   -62,   -62,
     106,   -62,   111,   140,   -62,   -62,   269,    42,   -62,   -62,
     -62,   115,   -62,   269,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,    51,    25,
      25,   111,   112,   113,   114,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     2,     4,     6,
       7,    16,    15,     8,     9,    10,    11,    12,    13,    14,
      25,    53,    54,    60,    62,    64,    66,    71,    76,    79,
      83,    88,    89,    87,     0,     0,    33,     0,    20,    20,
      20,    25,    52,    24,    23,    49,    50,     0,     0,     0,
       0,     0,   108,    84,    85,    86,   102,   103,     0,    28,
       0,     1,     5,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,   116,   116,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,    44,     0,    25,
      25,    25,    48,    55,    56,    57,    58,    59,   115,    27,
      63,     0,    65,    67,    68,    69,    70,    72,    73,    74,
      75,    77,    78,    80,    81,    82,   118,     0,   117,     0,
       0,   105,     0,     0,   104,     0,     0,    20,    20,    20,
      36,    46,     0,    45,    21,    17,    18,    19,     0,    91,
       0,    92,   107,    90,   106,    29,    31,    40,    41,    42,
       0,    37,     0,     0,    61,   119,     0,    38,    43,    47,
      30,     0,    39,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   139,   -26,   -62,   -57,   -62,    -6,   -62,   -18,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,    -8,   -32,    -3,   -62,    84,    80,
      38,    40,    10,   -13,   -62,   -62,   -62,   -62,   -61,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,    28,    29,   119,    30,    65,    31,    32,
      33,    34,    35,   114,   180,   191,   115,    36,   162,   163,
      37,    38,    39,    61,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,   147,   148
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    82,   120,   121,    66,    73,    74,    75,    76,    77,
      54,    84,   111,   112,   113,    78,    67,    63,    11,    12,
      13,    14,    55,    15,    16,    17,    18,    19,    85,    56,
      68,    69,    70,    71,    83,   123,   124,   125,   126,   127,
      20,    57,   149,    21,    22,   152,   109,   110,   116,    23,
      64,    97,    98,    99,    82,   122,    11,    12,    13,    14,
      58,    15,    16,    17,    18,    19,    11,    12,    13,    14,
      59,    72,    16,    17,    18,    19,    81,   131,    20,    95,
      96,    21,    22,    60,   143,   144,   145,    23,    20,   100,
     101,    21,    22,    86,   146,   146,   150,    23,   146,   153,
     177,   178,   179,   103,   106,   141,   142,   104,   107,   118,
     164,   105,   108,   165,   166,   167,    87,    88,    89,    90,
     102,    91,    92,    93,    94,   133,   134,   135,   136,   175,
     176,   137,   138,   139,   140,   117,   151,   128,   154,   155,
     156,   157,   158,   159,   161,   169,   160,   171,   172,   170,
     168,   173,   181,   174,   182,   186,   183,   187,    24,   189,
     190,   193,   185,    80,   188,   184,   132,   194,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   192,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,    21,    22,     0,     0,     0,     0,
      23,     0,    24,    79,     0,     1,    25,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       0,    21,    22,     0,     0,     0,     0,    23,     0,    24,
     129,     0,     1,    25,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,    21,    22,
       0,     0,     0,     0,    23,     0,    24,     0,     0,     0,
      25
};

static const yytype_int16 yycheck[] =
{
       8,    27,    59,    60,    10,    18,    19,    20,    21,    22,
      45,    38,     8,     9,    10,    23,    27,    18,    14,    15,
      16,    17,    45,    19,    20,    21,    22,    23,    55,    45,
      41,    42,    43,    44,    40,    67,    68,    69,    70,    71,
      36,    19,   103,    39,    40,   106,    54,    55,    56,    45,
      51,    24,    25,    26,    80,    61,    14,    15,    16,    17,
      19,    19,    20,    21,    22,    23,    14,    15,    16,    17,
      19,    19,    20,    21,    22,    23,     0,    85,    36,    22,
      23,    39,    40,    19,    97,    98,    99,    45,    36,    39,
      40,    39,    40,    37,   102,   103,   104,    45,   106,   107,
     157,   158,   159,    45,    45,    95,    96,    49,    49,    27,
     118,    53,    53,   119,   120,   121,    28,    29,    30,    31,
      45,    32,    33,    34,    35,    87,    88,    89,    90,   155,
     156,    91,    92,    93,    94,    45,    19,    46,    19,    46,
      46,    19,    19,    19,    19,    46,    51,    46,    50,    52,
      54,    46,   160,    50,    46,     4,    52,    51,    47,    19,
     186,    46,   170,    24,   182,   168,    86,   193,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,   187,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    47,    48,    -1,     3,    51,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,    47,
      48,    -1,     3,    51,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    -1,    -1,
      51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    19,    20,    21,    22,    23,
      36,    39,    40,    45,    47,    51,    75,    76,    77,    78,
      80,    82,    83,    84,    85,    86,    91,    94,    95,    96,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    45,    45,    45,    19,    19,    19,
      19,    97,    98,    18,    51,    81,    81,    27,    41,    42,
      43,    44,    19,   107,   107,   107,   107,   107,    98,    48,
      76,     0,    77,    81,    38,    55,    37,    28,    29,    30,
      31,    32,    33,    34,    35,    22,    23,    24,    25,    26,
      39,    40,    45,    45,    49,    53,    45,    49,    53,    98,
      98,     8,     9,    10,    87,    90,    98,    45,    27,    79,
      79,    79,    81,    99,    99,    99,    99,    99,    46,    48,
     102,    98,   103,   104,   104,   104,   104,   105,   105,   105,
     105,   106,   106,   107,   107,   107,    98,   112,   113,   112,
      98,    19,   112,    98,    19,    46,    46,    19,    19,    19,
      51,    19,    92,    93,    98,    81,    81,    81,    54,    46,
      52,    46,    50,    46,    50,    77,    77,    79,    79,    79,
      88,    98,    46,    52,   100,    98,     4,    51,    83,    19,
      77,    89,    98,    46,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      79,    79,    80,    81,    81,    81,    82,    83,    83,    84,
      84,    85,    86,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    91,    92,    92,    93,    93,    94,    95,
      96,    97,    97,    98,    99,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   105,   105,   105,   106,
     106,   106,   106,   107,   107,   107,   107,   108,   108,   108,
     109,   109,   109,   108,   108,   108,   108,   108,   107,   107,
     107,   107,   107,   107,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     2,     2,     1,     1,     0,     1,     3,     2,     5,
       7,     5,     9,     0,     1,     1,     0,     1,     0,     1,
       3,     3,     3,     6,     0,     1,     1,     3,     3,     2,
       2,     0,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     5,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     1,     1,     1,
       4,     4,     4,     1,     1,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     3,     3,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (scanner, YY_("syntax error: cannot back up")); \
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ScannerState *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ScannerState *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
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
                 int yyrule, ScannerState *scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, ScannerState *scanner)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
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
yyparse (ScannerState *scanner)
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* program: statements  */
#line 88 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        ast_root = (yyval.node);
        printf("PARSER: Successfully parsed program and built AST\n");
    }
#line 1372 "parser.c"
    break;

  case 3: /* statements: %empty  */
#line 97 "parser.y"
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 0);
        (yyval.node) = create_program(stmts, 0);
    }
#line 1381 "parser.c"
    break;

  case 4: /* statements: statement  */
#line 102 "parser.y"
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 1);
        stmts[0] = (yyvsp[0].node);
        (yyval.node) = create_program(stmts, 1);
    }
#line 1391 "parser.c"
    break;

  case 5: /* statements: statements statement  */
#line 108 "parser.y"
    {
        int old_count = (yyvsp[-1].node)->data.program.statement_count;
        ASTNode** new_stmts = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_stmts[i] = (yyvsp[-1].node)->data.program.statements[i];
        }
        new_stmts[old_count] = (yyvsp[0].node);
        
        free((yyvsp[-1].node)->data.program.statements);
        (yyvsp[-1].node)->data.program.statements = new_stmts;
        (yyvsp[-1].node)->data.program.statement_count = old_count + 1;
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1410 "parser.c"
    break;

  case 6: /* statement: variable_declaration  */
#line 125 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1416 "parser.c"
    break;

  case 7: /* statement: expression_statement  */
#line 126 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1422 "parser.c"
    break;

  case 8: /* statement: if_statement  */
#line 127 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1428 "parser.c"
    break;

  case 9: /* statement: while_statement  */
#line 128 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1434 "parser.c"
    break;

  case 10: /* statement: for_statement  */
#line 129 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1440 "parser.c"
    break;

  case 11: /* statement: function_declaration  */
#line 130 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1446 "parser.c"
    break;

  case 12: /* statement: return_statement  */
#line 131 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1452 "parser.c"
    break;

  case 13: /* statement: break_statement  */
#line 132 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1458 "parser.c"
    break;

  case 14: /* statement: continue_statement  */
#line 133 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1464 "parser.c"
    break;

  case 15: /* statement: block_statement  */
#line 134 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1470 "parser.c"
    break;

  case 16: /* statement: empty_statement  */
#line 135 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1476 "parser.c"
    break;

  case 17: /* variable_declaration: VAR IDENTIFIER optional_initializer asi_semicolon  */
#line 141 "parser.y"
    {
        (yyval.node) = create_variable_declaration("var", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1485 "parser.c"
    break;

  case 18: /* variable_declaration: LET IDENTIFIER optional_initializer asi_semicolon  */
#line 146 "parser.y"
    {
        (yyval.node) = create_variable_declaration("let", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1494 "parser.c"
    break;

  case 19: /* variable_declaration: CONST IDENTIFIER optional_initializer asi_semicolon  */
#line 151 "parser.y"
    {
        (yyval.node) = create_variable_declaration("const", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1503 "parser.c"
    break;

  case 20: /* optional_initializer: %empty  */
#line 158 "parser.y"
                  { (yyval.node) = NULL; }
#line 1509 "parser.c"
    break;

  case 21: /* optional_initializer: EQUALS expression  */
#line 159 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1515 "parser.c"
    break;

  case 22: /* expression_statement: expression asi_semicolon  */
#line 165 "parser.y"
    {
        (yyval.node) = create_expression_statement((yyvsp[-1].node));
    }
#line 1523 "parser.c"
    break;

  case 23: /* asi_semicolon: SEMICOLON  */
#line 172 "parser.y"
                { (yyval.node) = NULL; }
#line 1529 "parser.c"
    break;

  case 24: /* asi_semicolon: NEWLINE  */
#line 173 "parser.y"
              { (yyval.node) = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); }
#line 1535 "parser.c"
    break;

  case 25: /* asi_semicolon: %empty  */
#line 174 "parser.y"
                  { (yyval.node) = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); }
#line 1541 "parser.c"
    break;

  case 26: /* empty_statement: SEMICOLON  */
#line 180 "parser.y"
    {
        (yyval.node) = create_empty_statement();
    }
#line 1549 "parser.c"
    break;

  case 27: /* block_statement: LBRACE statements RBRACE  */
#line 188 "parser.y"
    {
        (yyval.node) = create_block_statement((yyvsp[-1].node)->data.program.statements, (yyvsp[-1].node)->data.program.statement_count);
        free((yyvsp[-1].node)); // 释放临时的 program 节点，但保留其中的语句
    }
#line 1558 "parser.c"
    break;

  case 28: /* block_statement: LBRACE RBRACE  */
#line 193 "parser.y"
    {
        ASTNode** body = malloc(sizeof(ASTNode*) * 0);
        (yyval.node) = create_block_statement(body, 0);
    }
#line 1567 "parser.c"
    break;

  case 29: /* if_statement: IF LPAREN expression RPAREN statement  */
#line 202 "parser.y"
    {
        (yyval.node) = create_if_statement((yyvsp[-2].node), (yyvsp[0].node), NULL);
    }
#line 1575 "parser.c"
    break;

  case 30: /* if_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 206 "parser.y"
    {
        (yyval.node) = create_if_statement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1583 "parser.c"
    break;

  case 31: /* while_statement: WHILE LPAREN expression RPAREN statement  */
#line 214 "parser.y"
    {
        (yyval.node) = create_while_statement((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1591 "parser.c"
    break;

  case 32: /* for_statement: FOR LPAREN for_init SEMICOLON for_cond SEMICOLON for_iter RPAREN statement  */
#line 222 "parser.y"
    {
        (yyval.node) = create_for_statement((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1599 "parser.c"
    break;

  case 33: /* for_init: %empty  */
#line 228 "parser.y"
                  { (yyval.node) = NULL; }
#line 1605 "parser.c"
    break;

  case 34: /* for_init: variable_declaration_no_semi  */
#line 229 "parser.y"
                                   { (yyval.node) = (yyvsp[0].node); }
#line 1611 "parser.c"
    break;

  case 35: /* for_init: expression  */
#line 230 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1617 "parser.c"
    break;

  case 36: /* for_cond: %empty  */
#line 234 "parser.y"
                  { (yyval.node) = NULL; }
#line 1623 "parser.c"
    break;

  case 37: /* for_cond: expression  */
#line 235 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1629 "parser.c"
    break;

  case 38: /* for_iter: %empty  */
#line 239 "parser.y"
                  { (yyval.node) = NULL; }
#line 1635 "parser.c"
    break;

  case 39: /* for_iter: expression  */
#line 240 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1641 "parser.c"
    break;

  case 40: /* variable_declaration_no_semi: VAR IDENTIFIER optional_initializer  */
#line 245 "parser.y"
    {
        (yyval.node) = create_variable_declaration("var", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 1650 "parser.c"
    break;

  case 41: /* variable_declaration_no_semi: LET IDENTIFIER optional_initializer  */
#line 250 "parser.y"
    {
        (yyval.node) = create_variable_declaration("let", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 1659 "parser.c"
    break;

  case 42: /* variable_declaration_no_semi: CONST IDENTIFIER optional_initializer  */
#line 255 "parser.y"
    {
        (yyval.node) = create_variable_declaration("const", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 1668 "parser.c"
    break;

  case 43: /* function_declaration: FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement  */
#line 264 "parser.y"
    {
        (yyval.node) = create_function_declaration((yyvsp[-4].str), (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-4].str));
        free((yyvsp[-2].param_list)); // 释放参数列表结构体，但不释放字符串（它们被转移到了 AST 节点中）
    }
#line 1678 "parser.c"
    break;

  case 44: /* parameter_list_opt: %empty  */
#line 273 "parser.y"
    {
        (yyval.param_list) = malloc(sizeof(ParamList));
        (yyval.param_list)->parameters = malloc(sizeof(char*) * 0);
        (yyval.param_list)->parameter_count = 0;
    }
#line 1688 "parser.c"
    break;

  case 45: /* parameter_list_opt: parameter_list  */
#line 279 "parser.y"
    {
        (yyval.param_list) = (yyvsp[0].param_list);
    }
#line 1696 "parser.c"
    break;

  case 46: /* parameter_list: IDENTIFIER  */
#line 286 "parser.y"
    {
        (yyval.param_list) = malloc(sizeof(ParamList));
        (yyval.param_list)->parameters = malloc(sizeof(char*) * 1);
        (yyval.param_list)->parameters[0] = (yyvsp[0].str);
        (yyval.param_list)->parameter_count = 1;
    }
#line 1707 "parser.c"
    break;

  case 47: /* parameter_list: parameter_list COMMA IDENTIFIER  */
#line 293 "parser.y"
    {
        int old_count = (yyvsp[-2].param_list)->parameter_count;
        char** new_params = malloc(sizeof(char*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_params[i] = (yyvsp[-2].param_list)->parameters[i];
        }
        new_params[old_count] = (yyvsp[0].str);
        
        free((yyvsp[-2].param_list)->parameters);
        (yyvsp[-2].param_list)->parameters = new_params;
        (yyvsp[-2].param_list)->parameter_count = old_count + 1;
        (yyval.param_list) = (yyvsp[-2].param_list);
    }
#line 1726 "parser.c"
    break;

  case 48: /* return_statement: RETURN expression_opt asi_semicolon  */
#line 312 "parser.y"
    {
        (yyval.node) = create_return_statement((yyvsp[-1].node));
    }
#line 1734 "parser.c"
    break;

  case 49: /* break_statement: BREAK asi_semicolon  */
#line 320 "parser.y"
    {
        (yyval.node) = create_break_statement();
    }
#line 1742 "parser.c"
    break;

  case 50: /* continue_statement: CONTINUE asi_semicolon  */
#line 327 "parser.y"
    {
        (yyval.node) = create_continue_statement();
    }
#line 1750 "parser.c"
    break;

  case 51: /* expression_opt: %empty  */
#line 333 "parser.y"
                  { (yyval.node) = NULL; }
#line 1756 "parser.c"
    break;

  case 52: /* expression_opt: expression  */
#line 334 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1762 "parser.c"
    break;

  case 53: /* expression: assignment_expression  */
#line 339 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1768 "parser.c"
    break;

  case 54: /* assignment_expression: conditional_expression  */
#line 343 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1774 "parser.c"
    break;

  case 55: /* assignment_expression: IDENTIFIER EQUALS assignment_expression  */
#line 345 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_ASSIGN, create_identifier((yyvsp[-2].str)), (yyvsp[0].node));
        free((yyvsp[-2].str));
    }
#line 1783 "parser.c"
    break;

  case 56: /* assignment_expression: IDENTIFIER PLUS_EQ assignment_expression  */
#line 350 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_ADD_ASSIGN, create_identifier((yyvsp[-2].str)), (yyvsp[0].node));
        free((yyvsp[-2].str));
    }
#line 1792 "parser.c"
    break;

  case 57: /* assignment_expression: IDENTIFIER MINUS_EQ assignment_expression  */
#line 355 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_SUB_ASSIGN, create_identifier((yyvsp[-2].str)), (yyvsp[0].node));
        free((yyvsp[-2].str));
    }
#line 1801 "parser.c"
    break;

  case 58: /* assignment_expression: IDENTIFIER STAR_EQ assignment_expression  */
#line 360 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_MUL_ASSIGN, create_identifier((yyvsp[-2].str)), (yyvsp[0].node));
        free((yyvsp[-2].str));
    }
#line 1810 "parser.c"
    break;

  case 59: /* assignment_expression: IDENTIFIER SLASH_EQ assignment_expression  */
#line 365 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_DIV_ASSIGN, create_identifier((yyvsp[-2].str)), (yyvsp[0].node));
        free((yyvsp[-2].str));
    }
#line 1819 "parser.c"
    break;

  case 60: /* conditional_expression: logical_or_expression  */
#line 372 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1825 "parser.c"
    break;

  case 61: /* conditional_expression: logical_or_expression QUESTION expression COLON conditional_expression  */
#line 374 "parser.y"
    {
        (yyval.node) = create_conditional_expression((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1833 "parser.c"
    break;

  case 62: /* logical_or_expression: logical_and_expression  */
#line 380 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1839 "parser.c"
    break;

  case 63: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 382 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_OR, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1847 "parser.c"
    break;

  case 64: /* logical_and_expression: equality_expression  */
#line 388 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1853 "parser.c"
    break;

  case 65: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 390 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_AND, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1861 "parser.c"
    break;

  case 66: /* equality_expression: relational_expression  */
#line 396 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1867 "parser.c"
    break;

  case 67: /* equality_expression: equality_expression EQ_EQ relational_expression  */
#line 398 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1875 "parser.c"
    break;

  case 68: /* equality_expression: equality_expression NOT_EQ relational_expression  */
#line 402 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_NEQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1883 "parser.c"
    break;

  case 69: /* equality_expression: equality_expression STRICT_EQ relational_expression  */
#line 406 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_STRICT_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1891 "parser.c"
    break;

  case 70: /* equality_expression: equality_expression STRICT_NOT_EQ relational_expression  */
#line 410 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_STRICT_NEQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1899 "parser.c"
    break;

  case 71: /* relational_expression: additive_expression  */
#line 416 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1905 "parser.c"
    break;

  case 72: /* relational_expression: relational_expression LT additive_expression  */
#line 418 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_LT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1913 "parser.c"
    break;

  case 73: /* relational_expression: relational_expression LE additive_expression  */
#line 422 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_LE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1921 "parser.c"
    break;

  case 74: /* relational_expression: relational_expression GT additive_expression  */
#line 426 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_GT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1929 "parser.c"
    break;

  case 75: /* relational_expression: relational_expression GE additive_expression  */
#line 430 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_GE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1937 "parser.c"
    break;

  case 76: /* additive_expression: multiplicative_expression  */
#line 436 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1943 "parser.c"
    break;

  case 77: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 438 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_ADD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1951 "parser.c"
    break;

  case 78: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 442 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_SUB, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1959 "parser.c"
    break;

  case 79: /* multiplicative_expression: unary_expression  */
#line 448 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1965 "parser.c"
    break;

  case 80: /* multiplicative_expression: multiplicative_expression STAR unary_expression  */
#line 450 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_MUL, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1973 "parser.c"
    break;

  case 81: /* multiplicative_expression: multiplicative_expression SLASH unary_expression  */
#line 454 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_DIV, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1981 "parser.c"
    break;

  case 82: /* multiplicative_expression: multiplicative_expression PERCENT unary_expression  */
#line 458 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_MOD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1989 "parser.c"
    break;

  case 83: /* unary_expression: postfix_expression  */
#line 464 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1995 "parser.c"
    break;

  case 84: /* unary_expression: PLUS unary_expression  */
#line 466 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_ADD, (yyvsp[0].node));
    }
#line 2003 "parser.c"
    break;

  case 85: /* unary_expression: MINUS unary_expression  */
#line 470 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_SUB, (yyvsp[0].node));
    }
#line 2011 "parser.c"
    break;

  case 86: /* unary_expression: BANG unary_expression  */
#line 474 "parser.y"
    {
        // 注意：这里需要为逻辑非创建一个新的操作符类型
        (yyval.node) = create_unary_expression(OP_SUB, (yyvsp[0].node)); // 临时使用减法操作符
    }
#line 2020 "parser.c"
    break;

  case 87: /* postfix_expression: primary_expression  */
#line 481 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2026 "parser.c"
    break;

  case 88: /* postfix_expression: call_expression  */
#line 482 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2032 "parser.c"
    break;

  case 89: /* postfix_expression: member_expression  */
#line 483 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2038 "parser.c"
    break;

  case 90: /* call_expression: primary_expression LPAREN argument_list_opt RPAREN  */
#line 489 "parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2047 "parser.c"
    break;

  case 91: /* call_expression: call_expression LPAREN argument_list_opt RPAREN  */
#line 494 "parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2056 "parser.c"
    break;

  case 92: /* call_expression: member_expression LPAREN argument_list_opt RPAREN  */
#line 499 "parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2065 "parser.c"
    break;

  case 93: /* postfix_expression: primary_expression  */
#line 506 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2071 "parser.c"
    break;

  case 94: /* postfix_expression: call_expression  */
#line 507 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2077 "parser.c"
    break;

  case 95: /* postfix_expression: member_expression  */
#line 508 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2083 "parser.c"
    break;

  case 96: /* postfix_expression: postfix_expression PLUS_PLUS  */
#line 510 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_POST_INC, (yyvsp[-1].node));
    }
#line 2091 "parser.c"
    break;

  case 97: /* postfix_expression: postfix_expression MINUS_MINUS  */
#line 514 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_POST_DEC, (yyvsp[-1].node));
    }
#line 2099 "parser.c"
    break;

  case 98: /* unary_expression: postfix_expression  */
#line 520 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2105 "parser.c"
    break;

  case 99: /* unary_expression: PLUS unary_expression  */
#line 522 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_ADD, (yyvsp[0].node));
    }
#line 2113 "parser.c"
    break;

  case 100: /* unary_expression: MINUS unary_expression  */
#line 526 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_SUB, (yyvsp[0].node));
    }
#line 2121 "parser.c"
    break;

  case 101: /* unary_expression: BANG unary_expression  */
#line 530 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_NOT, (yyvsp[0].node));
    }
#line 2129 "parser.c"
    break;

  case 102: /* unary_expression: PLUS_PLUS unary_expression  */
#line 534 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_PRE_INC, (yyvsp[0].node));
    }
#line 2137 "parser.c"
    break;

  case 103: /* unary_expression: MINUS_MINUS unary_expression  */
#line 538 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_PRE_DEC, (yyvsp[0].node));
    }
#line 2145 "parser.c"
    break;

  case 104: /* member_expression: primary_expression DOT IDENTIFIER  */
#line 545 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-2].node), create_identifier((yyvsp[0].str)), 0);
        free((yyvsp[0].str));
    }
#line 2154 "parser.c"
    break;

  case 105: /* member_expression: member_expression DOT IDENTIFIER  */
#line 550 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-2].node), create_identifier((yyvsp[0].str)), 0);
        free((yyvsp[0].str));
    }
#line 2163 "parser.c"
    break;

  case 106: /* member_expression: primary_expression LBRACKET expression RBRACKET  */
#line 555 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-3].node), (yyvsp[-1].node), 1);
    }
#line 2171 "parser.c"
    break;

  case 107: /* member_expression: member_expression LBRACKET expression RBRACKET  */
#line 559 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-3].node), (yyvsp[-1].node), 1);
    }
#line 2179 "parser.c"
    break;

  case 108: /* primary_expression: IDENTIFIER  */
#line 565 "parser.y"
                 { (yyval.node) = create_identifier((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2185 "parser.c"
    break;

  case 109: /* primary_expression: NUMBER  */
#line 566 "parser.y"
             { (yyval.node) = create_number((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2191 "parser.c"
    break;

  case 110: /* primary_expression: STRING  */
#line 567 "parser.y"
             { (yyval.node) = create_string((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2197 "parser.c"
    break;

  case 111: /* primary_expression: TRUE  */
#line 568 "parser.y"
           { (yyval.node) = create_boolean(1); }
#line 2203 "parser.c"
    break;

  case 112: /* primary_expression: FALSE  */
#line 569 "parser.y"
            { (yyval.node) = create_boolean(0); }
#line 2209 "parser.c"
    break;

  case 113: /* primary_expression: NULL_LITERAL  */
#line 570 "parser.y"
                   { (yyval.node) = create_null(); }
#line 2215 "parser.c"
    break;

  case 114: /* primary_expression: UNDEFINED  */
#line 571 "parser.y"
                { (yyval.node) = create_undefined(); }
#line 2221 "parser.c"
    break;

  case 115: /* primary_expression: LPAREN expression RPAREN  */
#line 572 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 2227 "parser.c"
    break;

  case 116: /* argument_list_opt: %empty  */
#line 577 "parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 0);
        (yyval.arg_list)->argument_count = 0;
    }
#line 2237 "parser.c"
    break;

  case 117: /* argument_list_opt: argument_list  */
#line 583 "parser.y"
    {
        (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 2245 "parser.c"
    break;

  case 118: /* argument_list: expression  */
#line 590 "parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 1);
        (yyval.arg_list)->arguments[0] = (yyvsp[0].node);
        (yyval.arg_list)->argument_count = 1;
    }
#line 2256 "parser.c"
    break;

  case 119: /* argument_list: argument_list COMMA expression  */
#line 597 "parser.y"
    {
        int old_count = (yyvsp[-2].arg_list)->argument_count;
        ASTNode** new_args = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_args[i] = (yyvsp[-2].arg_list)->arguments[i];
        }
        new_args[old_count] = (yyvsp[0].node);
        
        free((yyvsp[-2].arg_list)->arguments);
        (yyvsp[-2].arg_list)->arguments = new_args;
        (yyvsp[-2].arg_list)->argument_count = old_count + 1;
        (yyval.arg_list) = (yyvsp[-2].arg_list);
    }
#line 2275 "parser.c"
    break;


#line 2279 "parser.c"

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
      yyerror (scanner, YY_("syntax error"));
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
                      yytoken, &yylval, scanner);
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
  ++yynerrs;

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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 613 "parser.y"


void yyerror(ScannerState *scanner, const char *s) {
    (void)scanner; // 标记为未使用，消除警告
    fprintf(stderr, "PARSER: Syntax error: %s\n", s);
    if (global_scanner) {
        fprintf(stderr, "PARSER: At position: %d\n", global_scanner->pos);
        int start = global_scanner->pos - 10;
        if (start < 0) start = 0;
        size_t length = 30;
        size_t input_len = strlen(global_scanner->input);
        if (start + length > input_len) {
            length = input_len - start;
        }
        fprintf(stderr, "PARSER: Context: '%.*s'\n", (int)length, global_scanner->input + start);
        fprintf(stderr, "PARSER:           %*s^\n", global_scanner->pos - start, "");
    }
}
