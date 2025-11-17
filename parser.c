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
  YYSYMBOL_CLASS = 18,                     /* CLASS  */
  YYSYMBOL_NEW = 19,                       /* NEW  */
  YYSYMBOL_THIS = 20,                      /* THIS  */
  YYSYMBOL_SUPER = 21,                     /* SUPER  */
  YYSYMBOL_STATIC = 22,                    /* STATIC  */
  YYSYMBOL_EXTENDS = 23,                   /* EXTENDS  */
  YYSYMBOL_CONSTRUCTOR = 24,               /* CONSTRUCTOR  */
  YYSYMBOL_NEWLINE = 25,                   /* NEWLINE  */
  YYSYMBOL_IDENTIFIER = 26,                /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 27,                    /* NUMBER  */
  YYSYMBOL_STRING = 28,                    /* STRING  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MINUS = 30,                     /* MINUS  */
  YYSYMBOL_STAR = 31,                      /* STAR  */
  YYSYMBOL_SLASH = 32,                     /* SLASH  */
  YYSYMBOL_PERCENT = 33,                   /* PERCENT  */
  YYSYMBOL_EQUALS = 34,                    /* EQUALS  */
  YYSYMBOL_EQ_EQ = 35,                     /* EQ_EQ  */
  YYSYMBOL_NOT_EQ = 36,                    /* NOT_EQ  */
  YYSYMBOL_STRICT_EQ = 37,                 /* STRICT_EQ  */
  YYSYMBOL_STRICT_NOT_EQ = 38,             /* STRICT_NOT_EQ  */
  YYSYMBOL_LT = 39,                        /* LT  */
  YYSYMBOL_LE = 40,                        /* LE  */
  YYSYMBOL_GT = 41,                        /* GT  */
  YYSYMBOL_GE = 42,                        /* GE  */
  YYSYMBOL_BANG = 43,                      /* BANG  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_PLUS_PLUS = 46,                 /* PLUS_PLUS  */
  YYSYMBOL_MINUS_MINUS = 47,               /* MINUS_MINUS  */
  YYSYMBOL_PLUS_EQ = 48,                   /* PLUS_EQ  */
  YYSYMBOL_MINUS_EQ = 49,                  /* MINUS_EQ  */
  YYSYMBOL_STAR_EQ = 50,                   /* STAR_EQ  */
  YYSYMBOL_SLASH_EQ = 51,                  /* SLASH_EQ  */
  YYSYMBOL_LPAREN = 52,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 53,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 54,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 55,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 56,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 57,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 58,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 59,                     /* COMMA  */
  YYSYMBOL_DOT = 60,                       /* DOT  */
  YYSYMBOL_COLON = 61,                     /* COLON  */
  YYSYMBOL_QUESTION = 62,                  /* QUESTION  */
  YYSYMBOL_ERROR = 63,                     /* ERROR  */
  YYSYMBOL_POSTFIX = 64,                   /* POSTFIX  */
  YYSYMBOL_ASSIGNMENT = 65,                /* ASSIGNMENT  */
  YYSYMBOL_BITWISE_OR = 66,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 67,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_AND = 68,               /* BITWISE_AND  */
  YYSYMBOL_EQUALITY = 69,                  /* EQUALITY  */
  YYSYMBOL_RELATIONAL = 70,                /* RELATIONAL  */
  YYSYMBOL_SHIFT = 71,                     /* SHIFT  */
  YYSYMBOL_ADDITIVE = 72,                  /* ADDITIVE  */
  YYSYMBOL_MULTIPLICATIVE = 73,            /* MULTIPLICATIVE  */
  YYSYMBOL_EXPONENTIAL = 74,               /* EXPONENTIAL  */
  YYSYMBOL_UNARY = 75,                     /* UNARY  */
  YYSYMBOL_CALL = 76,                      /* CALL  */
  YYSYMBOL_PRE_INC = 77,                   /* PRE_INC  */
  YYSYMBOL_PRE_DEC = 78,                   /* PRE_DEC  */
  YYSYMBOL_POST_INC = 79,                  /* POST_INC  */
  YYSYMBOL_POST_DEC = 80,                  /* POST_DEC  */
  YYSYMBOL_YYACCEPT = 81,                  /* $accept  */
  YYSYMBOL_program = 82,                   /* program  */
  YYSYMBOL_statements = 83,                /* statements  */
  YYSYMBOL_statement = 84,                 /* statement  */
  YYSYMBOL_class_declaration = 85,         /* class_declaration  */
  YYSYMBOL_class_extends_opt = 86,         /* class_extends_opt  */
  YYSYMBOL_class_body = 87,                /* class_body  */
  YYSYMBOL_class_element_list_opt = 88,    /* class_element_list_opt  */
  YYSYMBOL_class_element_list = 89,        /* class_element_list  */
  YYSYMBOL_class_element = 90,             /* class_element  */
  YYSYMBOL_static_opt = 91,                /* static_opt  */
  YYSYMBOL_method_definition = 92,         /* method_definition  */
  YYSYMBOL_property_definition = 93,       /* property_definition  */
  YYSYMBOL_variable_declaration = 94,      /* variable_declaration  */
  YYSYMBOL_optional_initializer = 95,      /* optional_initializer  */
  YYSYMBOL_expression_statement = 96,      /* expression_statement  */
  YYSYMBOL_asi_semicolon = 97,             /* asi_semicolon  */
  YYSYMBOL_empty_statement = 98,           /* empty_statement  */
  YYSYMBOL_block_statement = 99,           /* block_statement  */
  YYSYMBOL_if_statement = 100,             /* if_statement  */
  YYSYMBOL_while_statement = 101,          /* while_statement  */
  YYSYMBOL_for_statement = 102,            /* for_statement  */
  YYSYMBOL_for_init = 103,                 /* for_init  */
  YYSYMBOL_for_cond = 104,                 /* for_cond  */
  YYSYMBOL_for_iter = 105,                 /* for_iter  */
  YYSYMBOL_variable_declaration_no_semi = 106, /* variable_declaration_no_semi  */
  YYSYMBOL_function_declaration = 107,     /* function_declaration  */
  YYSYMBOL_parameter_list_opt = 108,       /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 109,           /* parameter_list  */
  YYSYMBOL_return_statement = 110,         /* return_statement  */
  YYSYMBOL_break_statement = 111,          /* break_statement  */
  YYSYMBOL_continue_statement = 112,       /* continue_statement  */
  YYSYMBOL_expression_opt = 113,           /* expression_opt  */
  YYSYMBOL_expression = 114,               /* expression  */
  YYSYMBOL_assignment_expression = 115,    /* assignment_expression  */
  YYSYMBOL_left_hand_side = 116,           /* left_hand_side  */
  YYSYMBOL_conditional_expression = 117,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 118,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 119,   /* logical_and_expression  */
  YYSYMBOL_equality_expression = 120,      /* equality_expression  */
  YYSYMBOL_relational_expression = 121,    /* relational_expression  */
  YYSYMBOL_additive_expression = 122,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 123, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 124,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 125,       /* postfix_expression  */
  YYSYMBOL_call_expression = 126,          /* call_expression  */
  YYSYMBOL_member_expression = 127,        /* member_expression  */
  YYSYMBOL_new_expression = 128,           /* new_expression  */
  YYSYMBOL_primary_expression = 129,       /* primary_expression  */
  YYSYMBOL_argument_list_opt = 130,        /* argument_list_opt  */
  YYSYMBOL_argument_list = 131,            /* argument_list  */
  YYSYMBOL_array_literal = 132,            /* array_literal  */
  YYSYMBOL_array_element_list_opt = 133,   /* array_element_list_opt  */
  YYSYMBOL_array_element_list = 134        /* array_element_list  */
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
#define YYFINAL  93
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   335


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   116,   120,   126,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   160,   168,
     169,   173,   182,   187,   194,   201,   219,   225,   234,   235,
     239,   247,   259,   266,   277,   282,   287,   295,   296,   301,
     309,   310,   311,   316,   324,   329,   338,   342,   350,   358,
     365,   366,   367,   371,   372,   376,   377,   381,   386,   391,
     400,   410,   415,   422,   429,   448,   456,   463,   470,   471,
     476,   480,   481,   485,   489,   493,   497,   505,   506,   510,
     511,   518,   519,   526,   527,   534,   535,   539,   543,   547,
     554,   555,   559,   563,   567,   574,   575,   579,   586,   587,
     591,   595,   602,   603,   607,   611,   615,   619,   626,   627,
     628,   629,   630,   634,   642,   647,   652,   661,   666,   671,
     675,   683,   688,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   710,   715,   722,   729,   748,   757,
     762,   769,   776
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
  "TRUE", "FALSE", "NULL_LITERAL", "UNDEFINED", "CLASS", "NEW", "THIS",
  "SUPER", "STATIC", "EXTENDS", "CONSTRUCTOR", "NEWLINE", "IDENTIFIER",
  "NUMBER", "STRING", "PLUS", "MINUS", "STAR", "SLASH", "PERCENT",
  "EQUALS", "EQ_EQ", "NOT_EQ", "STRICT_EQ", "STRICT_NOT_EQ", "LT", "LE",
  "GT", "GE", "BANG", "AND", "OR", "PLUS_PLUS", "MINUS_MINUS", "PLUS_EQ",
  "MINUS_EQ", "STAR_EQ", "SLASH_EQ", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "DOT", "COLON",
  "QUESTION", "ERROR", "POSTFIX", "ASSIGNMENT", "BITWISE_OR",
  "BITWISE_XOR", "BITWISE_AND", "EQUALITY", "RELATIONAL", "SHIFT",
  "ADDITIVE", "MULTIPLICATIVE", "EXPONENTIAL", "UNARY", "CALL", "PRE_INC",
  "PRE_DEC", "POST_INC", "POST_DEC", "$accept", "program", "statements",
  "statement", "class_declaration", "class_extends_opt", "class_body",
  "class_element_list_opt", "class_element_list", "class_element",
  "static_opt", "method_definition", "property_definition",
  "variable_declaration", "optional_initializer", "expression_statement",
  "asi_semicolon", "empty_statement", "block_statement", "if_statement",
  "while_statement", "for_statement", "for_init", "for_cond", "for_iter",
  "variable_declaration_no_semi", "function_declaration",
  "parameter_list_opt", "parameter_list", "return_statement",
  "break_statement", "continue_statement", "expression_opt", "expression",
  "assignment_expression", "left_hand_side", "conditional_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "postfix_expression",
  "call_expression", "member_expression", "new_expression",
  "primary_expression", "argument_list_opt", "argument_list",
  "array_literal", "array_element_list_opt", "array_element_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-216)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     347,   -48,   -19,    -4,    19,    25,    32,    34,   152,   -24,
     -24,  -216,  -216,  -216,  -216,    61,     9,  -216,  -216,    18,
    -216,  -216,   432,   432,   432,   432,   432,   152,   239,   152,
    -216,    22,   347,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,   -24,  -216,    41,  -216,
     -18,    49,     5,   161,    24,    50,  -216,    39,    46,    28,
    -216,    43,  -216,   152,   152,   398,    52,    71,    71,    71,
     -24,  -216,  -216,  -216,  -216,  -216,    84,  -216,    46,    54,
      43,  -216,    68,  -216,  -216,  -216,  -216,    55,  -216,   293,
    -216,    64,    63,  -216,  -216,  -216,   152,   152,   152,   152,
     152,   432,   152,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,  -216,  -216,   152,
     152,   152,    83,   152,   152,    97,    72,    73,   106,   107,
     109,    78,  -216,  -216,   111,   152,   -24,   -24,   -24,  -216,
     113,    91,   152,  -216,  -216,  -216,   152,  -216,  -216,  -216,
    -216,  -216,    49,    85,     5,   161,   161,   161,   161,    24,
      24,    24,    24,    50,    50,  -216,  -216,  -216,  -216,   112,
     116,   117,    93,  -216,   123,   120,  -216,   347,   347,    71,
      71,    71,   152,  -216,   130,   125,  -216,  -216,  -216,  -216,
    -216,   -17,   -24,   133,  -216,   432,  -216,   152,  -216,  -216,
    -216,  -216,   183,  -216,  -216,  -216,  -216,   138,  -216,   134,
     171,  -216,   150,    -6,  -216,    -9,  -216,  -216,  -216,  -216,
     347,   152,  -216,  -216,  -216,  -216,   154,   -20,  -216,   156,
    -216,   162,  -216,   111,   152,   111,  -216,   347,   163,  -216,
     164,  -216,   134,   134,  -216,  -216
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,    68,    42,
      42,   126,   127,   128,   129,     0,     0,   130,   131,   123,
     124,   125,     0,     0,     0,     0,     0,     0,     0,   139,
      43,     0,     2,     4,    12,     6,     7,    17,    16,     8,
       9,    10,    11,    13,    14,    15,    42,    70,     0,    71,
      79,    81,    83,    85,    90,    95,    98,   102,   109,   110,
     111,   108,   132,     0,     0,    50,     0,    37,    37,    37,
      42,    69,    41,    40,    66,    67,    19,   123,   122,     0,
       0,   103,   110,   104,   105,   106,   107,     0,    45,     0,
     141,     0,   140,     1,     5,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   134,
     134,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    61,     0,    42,    42,    42,    65,
       0,     0,   134,   133,    44,   138,     0,    72,    73,    74,
      75,    76,    82,     0,    84,    86,    87,    88,    89,    91,
      92,    93,    94,    96,    97,    99,   100,   101,   136,     0,
     135,     0,     0,   118,     0,     0,   117,     0,     0,    37,
      37,    37,    53,    63,     0,    62,    38,    34,    35,    36,
      20,    28,    42,     0,   142,     0,   115,     0,   116,   120,
     114,   119,    46,    48,    57,    58,    59,     0,    54,     0,
       0,    29,     0,    28,    24,     0,    18,   116,    80,   137,
       0,    55,    60,    64,    21,    25,     0,    32,    26,     0,
      47,     0,    56,    61,     0,    61,    27,     0,     0,    33,
       0,    49,     0,     0,    30,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,   190,   -30,  -216,  -216,  -216,  -216,  -216,     6,
    -216,  -216,  -216,  -216,   -62,  -216,    -7,  -216,  -196,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -215,  -216,  -216,
    -216,  -216,  -216,    -8,    44,  -216,    26,  -216,   119,   121,
      87,   101,   -16,   -14,  -216,   206,    48,  -216,   207,   -92,
    -216,  -216,  -216,  -216
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    31,    32,    33,    34,   141,   192,   212,   213,   214,
     215,   228,   229,    35,   136,    36,    74,    37,    38,    39,
      40,    41,   131,   207,   231,   132,    42,   184,   185,    43,
      44,    45,    70,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   169,
     170,    62,    91,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    72,    94,    75,    63,   211,   137,   138,    81,    83,
      84,    85,    86,   222,   234,   226,   211,   227,   238,    87,
     240,    90,    93,    11,    12,    13,    14,   101,   171,    17,
      18,   174,   235,    64,    73,    77,    20,    21,   -22,    95,
     104,   105,   106,   107,   102,    66,   244,   245,    65,   -23,
     193,    67,   -77,   112,   113,   126,   127,   133,    68,    94,
      69,    27,   -78,   139,    79,    29,   -77,   -77,   -77,   -77,
      82,    82,    82,    82,    82,    96,   -78,   -78,   -78,   -78,
     120,   114,   115,   116,   121,   117,   118,    76,   122,    97,
      98,    99,   100,   103,   153,   123,   163,   164,   119,   124,
     165,   166,   167,   125,   134,   135,   142,   140,   143,   173,
     121,   168,   168,   172,   122,   168,   175,   204,   205,   206,
     120,   145,   146,   176,   121,   177,   178,   186,   122,   187,
     188,   189,   179,   180,   168,   181,   182,   183,   194,   190,
     147,   148,   149,   150,   151,   191,   195,   202,   203,    82,
     199,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,   196,    11,    12,    13,    14,
     198,    16,    17,    18,   208,   197,   200,   201,    19,    20,
      21,    22,    23,   209,   210,   216,   217,   220,    28,   219,
     230,   155,   156,   157,   158,    24,   221,   223,    25,    26,
     108,   109,   110,   111,    27,   224,   233,   241,    29,   159,
     160,   161,   162,   232,   236,   237,   242,   243,    89,   225,
     152,   218,    78,    80,   154,     0,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    82,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,     0,    19,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,    25,    26,     0,     0,     0,
       0,    27,     0,    28,    88,    29,     1,    30,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,     0,    25,
      26,     0,     0,     0,     0,    27,     0,    28,   144,    29,
       1,    30,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,     0,    25,    26,     0,     0,     0,     0,    27,
       0,    28,     0,    29,     0,    30,   128,   129,   130,     0,
       0,     0,    11,    12,    13,    14,     0,    16,    17,    18,
       0,     0,     0,     0,    19,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,    25,    26,    11,    12,    13,    14,
      27,    16,    17,    18,    29,     0,     0,     0,    77,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    25,    26,
       0,     0,     0,     0,    27,     0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
       8,    25,    32,    10,    52,    22,    68,    69,    22,    23,
      24,    25,    26,   209,    34,    24,    22,    26,   233,    27,
     235,    29,     0,    14,    15,    16,    17,    45,   120,    20,
      21,   123,    52,    52,    58,    26,    27,    28,    55,    46,
      35,    36,    37,    38,    62,    26,   242,   243,    52,    55,
     142,    26,    34,    29,    30,    63,    64,    65,    26,    89,
      26,    52,    34,    70,    16,    56,    48,    49,    50,    51,
      22,    23,    24,    25,    26,    34,    48,    49,    50,    51,
      52,    31,    32,    33,    56,    46,    47,    26,    60,    48,
      49,    50,    51,    44,   102,    52,   112,   113,    52,    56,
     114,   115,   116,    60,    52,    34,    52,    23,    53,    26,
      56,   119,   120,   121,    60,   123,   124,   179,   180,   181,
      52,    57,    59,    26,    56,    53,    53,   135,    60,   136,
     137,   138,    26,    26,   142,    26,    58,    26,   146,    26,
      96,    97,    98,    99,   100,    54,    61,   177,   178,   101,
      57,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    53,    14,    15,    16,    17,
      53,    19,    20,    21,   182,    59,    53,    57,    26,    27,
      28,    29,    30,    53,    59,   192,    53,     4,    54,   197,
     220,   104,   105,   106,   107,    43,    58,    26,    46,    47,
      39,    40,    41,    42,    52,    55,    52,   237,    56,   108,
     109,   110,   111,   221,    58,    53,    53,    53,    28,   213,
     101,   195,    16,    16,   103,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,   195,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,     3,    58,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
       3,    58,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    54,    -1,    56,    -1,    58,     8,     9,    10,    -1,
      -1,    -1,    14,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    46,    47,    14,    15,    16,    17,
      52,    19,    20,    21,    56,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    26,
      27,    28,    29,    30,    43,    46,    47,    52,    54,    56,
      58,    82,    83,    84,    85,    94,    96,    98,    99,   100,
     101,   102,   107,   110,   111,   112,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   132,    52,    52,    52,    26,    26,    26,    26,
     113,   114,    25,    58,    97,    97,    26,    26,   126,   127,
     129,   124,   127,   124,   124,   124,   124,   114,    55,    83,
     114,   133,   134,     0,    84,    97,    34,    48,    49,    50,
      51,    45,    62,    44,    35,    36,    37,    38,    39,    40,
      41,    42,    29,    30,    31,    32,    33,    46,    47,    52,
      52,    56,    60,    52,    56,    60,   114,   114,     8,     9,
      10,   103,   106,   114,    52,    34,    95,    95,    95,    97,
      23,    86,    52,    53,    55,    57,    59,   115,   115,   115,
     115,   115,   119,   114,   120,   121,   121,   121,   121,   122,
     122,   122,   122,   123,   123,   124,   124,   124,   114,   130,
     131,   130,   114,    26,   130,   114,    26,    53,    53,    26,
      26,    26,    58,    26,   108,   109,   114,    97,    97,    97,
      26,    54,    87,   130,   114,    61,    53,    59,    53,    57,
      53,    57,    84,    84,    95,    95,    95,   104,   114,    53,
      59,    22,    88,    89,    90,    91,    97,    53,   117,   114,
       4,    58,    99,    26,    55,    90,    24,    26,    92,    93,
      84,   105,   114,    52,    34,    52,    58,    53,   108,   114,
     108,    84,    53,    53,    99,    99
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    86,
      86,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    95,    95,    96,
      97,    97,    97,    98,    99,    99,   100,   100,   101,   102,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     107,   108,   108,   109,   109,   110,   111,   112,   113,   113,
     114,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   122,   122,   122,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   127,   127,   127,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   133,
     133,   134,   134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     0,
       2,     3,     0,     1,     1,     2,     2,     3,     0,     1,
       5,     5,     1,     3,     4,     4,     4,     0,     2,     2,
       1,     1,     0,     1,     3,     2,     5,     7,     5,     9,
       0,     1,     1,     0,     1,     0,     1,     3,     3,     3,
       6,     0,     1,     1,     3,     3,     2,     2,     0,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     1,
       5,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     4,     4,     4,     3,     3,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     3,     3,     0,
       1,     1,     3
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
#line 107 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        ast_root = (yyval.node);
        printf("PARSER: Successfully parsed program and built AST\n");
    }
#line 1459 "parser.c"
    break;

  case 3: /* statements: %empty  */
#line 116 "parser.y"
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 0);
        (yyval.node) = create_program(stmts, 0);
    }
#line 1468 "parser.c"
    break;

  case 4: /* statements: statement  */
#line 121 "parser.y"
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 1);
        stmts[0] = (yyvsp[0].node);
        (yyval.node) = create_program(stmts, 1);
    }
#line 1478 "parser.c"
    break;

  case 5: /* statements: statements statement  */
#line 127 "parser.y"
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
#line 1497 "parser.c"
    break;

  case 6: /* statement: variable_declaration  */
#line 144 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1503 "parser.c"
    break;

  case 7: /* statement: expression_statement  */
#line 145 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1509 "parser.c"
    break;

  case 8: /* statement: if_statement  */
#line 146 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1515 "parser.c"
    break;

  case 9: /* statement: while_statement  */
#line 147 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1521 "parser.c"
    break;

  case 10: /* statement: for_statement  */
#line 148 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1527 "parser.c"
    break;

  case 11: /* statement: function_declaration  */
#line 149 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1533 "parser.c"
    break;

  case 12: /* statement: class_declaration  */
#line 150 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1539 "parser.c"
    break;

  case 13: /* statement: return_statement  */
#line 151 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1545 "parser.c"
    break;

  case 14: /* statement: break_statement  */
#line 152 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1551 "parser.c"
    break;

  case 15: /* statement: continue_statement  */
#line 153 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1557 "parser.c"
    break;

  case 16: /* statement: block_statement  */
#line 154 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1563 "parser.c"
    break;

  case 17: /* statement: empty_statement  */
#line 155 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1569 "parser.c"
    break;

  case 18: /* class_declaration: CLASS IDENTIFIER class_extends_opt class_body asi_semicolon  */
#line 161 "parser.y"
    {
        (yyval.node) = create_class_declaration((yyvsp[-3].str), (yyvsp[-2].node), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1578 "parser.c"
    break;

  case 19: /* class_extends_opt: %empty  */
#line 168 "parser.y"
                  { (yyval.node) = NULL; }
#line 1584 "parser.c"
    break;

  case 20: /* class_extends_opt: EXTENDS IDENTIFIER  */
#line 169 "parser.y"
                         { (yyval.node) = create_identifier((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1590 "parser.c"
    break;

  case 21: /* class_body: LBRACE class_element_list_opt RBRACE  */
#line 174 "parser.y"
    {
        (yyval.node) = create_class_body((yyvsp[-1].class_element_list)->elements, (yyvsp[-1].class_element_list)->element_count);
        free((yyvsp[-1].class_element_list)); // 释放临时结构体，但不释放其中的元素
    }
#line 1599 "parser.c"
    break;

  case 22: /* class_element_list_opt: %empty  */
#line 182 "parser.y"
    {
        (yyval.class_element_list) = malloc(sizeof(ClassElementList));
        (yyval.class_element_list)->elements = malloc(sizeof(ASTNode*) * 0);
        (yyval.class_element_list)->element_count = 0;
    }
#line 1609 "parser.c"
    break;

  case 23: /* class_element_list_opt: class_element_list  */
#line 188 "parser.y"
    {
        (yyval.class_element_list) = (yyvsp[0].class_element_list);
    }
#line 1617 "parser.c"
    break;

  case 24: /* class_element_list: class_element  */
#line 195 "parser.y"
    {
        (yyval.class_element_list) = malloc(sizeof(ClassElementList));
        (yyval.class_element_list)->elements = malloc(sizeof(ASTNode*) * 1);
        (yyval.class_element_list)->elements[0] = (yyvsp[0].node);
        (yyval.class_element_list)->element_count = 1;
    }
#line 1628 "parser.c"
    break;

  case 25: /* class_element_list: class_element_list class_element  */
#line 202 "parser.y"
    {
        int old_count = (yyvsp[-1].class_element_list)->element_count;
        ASTNode** new_elements = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_elements[i] = (yyvsp[-1].class_element_list)->elements[i];
        }
        new_elements[old_count] = (yyvsp[0].node);
        
        free((yyvsp[-1].class_element_list)->elements);
        (yyvsp[-1].class_element_list)->elements = new_elements;
        (yyvsp[-1].class_element_list)->element_count = old_count + 1;
        (yyval.class_element_list) = (yyvsp[-1].class_element_list);
    }
#line 1647 "parser.c"
    break;

  case 26: /* class_element: static_opt method_definition  */
#line 220 "parser.y"
    {
        (yyval.node) = create_class_method((yyvsp[0].method_def)->kind, (yyvsp[0].method_def)->key, (yyvsp[0].method_def)->value, (yyvsp[-1].int_val));
        free((yyvsp[0].method_def)->key);
        free((yyvsp[0].method_def));
    }
#line 1657 "parser.c"
    break;

  case 27: /* class_element: static_opt property_definition SEMICOLON  */
#line 226 "parser.y"
    {
        (yyval.node) = create_class_property((yyvsp[-1].prop_def)->key, (yyvsp[-1].prop_def)->value, (yyvsp[-2].int_val));
        free((yyvsp[-1].prop_def)->key);
        free((yyvsp[-1].prop_def));
    }
#line 1667 "parser.c"
    break;

  case 28: /* static_opt: %empty  */
#line 234 "parser.y"
                  { (yyval.int_val) = 0; }
#line 1673 "parser.c"
    break;

  case 29: /* static_opt: STATIC  */
#line 235 "parser.y"
             { (yyval.int_val) = 1; }
#line 1679 "parser.c"
    break;

  case 30: /* method_definition: CONSTRUCTOR LPAREN parameter_list_opt RPAREN block_statement  */
#line 240 "parser.y"
    {
        (yyval.method_def) = malloc(sizeof(MethodDefinition));
        (yyval.method_def)->kind = strdup("constructor");
        (yyval.method_def)->key = strdup("constructor");
        (yyval.method_def)->value = create_function_declaration("constructor", (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-2].param_list));
    }
#line 1691 "parser.c"
    break;

  case 31: /* method_definition: IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement  */
#line 248 "parser.y"
    {
        (yyval.method_def) = malloc(sizeof(MethodDefinition));
        (yyval.method_def)->kind = strdup("method");
        (yyval.method_def)->key = strdup((yyvsp[-4].str));
        (yyval.method_def)->value = create_function_declaration((yyvsp[-4].str), (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-4].str));
        free((yyvsp[-2].param_list));
    }
#line 1704 "parser.c"
    break;

  case 32: /* property_definition: IDENTIFIER  */
#line 260 "parser.y"
    {
        (yyval.prop_def) = malloc(sizeof(PropertyDefinition));
        (yyval.prop_def)->key = strdup((yyvsp[0].str));
        (yyval.prop_def)->value = NULL;
        free((yyvsp[0].str));
    }
#line 1715 "parser.c"
    break;

  case 33: /* property_definition: IDENTIFIER EQUALS expression  */
#line 267 "parser.y"
    {
        (yyval.prop_def) = malloc(sizeof(PropertyDefinition));
        (yyval.prop_def)->key = strdup((yyvsp[-2].str));
        (yyval.prop_def)->value = (yyvsp[0].node);
        free((yyvsp[-2].str));
    }
#line 1726 "parser.c"
    break;

  case 34: /* variable_declaration: VAR IDENTIFIER optional_initializer asi_semicolon  */
#line 278 "parser.y"
    {
        (yyval.node) = create_variable_declaration("var", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1735 "parser.c"
    break;

  case 35: /* variable_declaration: LET IDENTIFIER optional_initializer asi_semicolon  */
#line 283 "parser.y"
    {
        (yyval.node) = create_variable_declaration("let", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1744 "parser.c"
    break;

  case 36: /* variable_declaration: CONST IDENTIFIER optional_initializer asi_semicolon  */
#line 288 "parser.y"
    {
        (yyval.node) = create_variable_declaration("const", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1753 "parser.c"
    break;

  case 37: /* optional_initializer: %empty  */
#line 295 "parser.y"
                  { (yyval.node) = NULL; }
#line 1759 "parser.c"
    break;

  case 38: /* optional_initializer: EQUALS expression  */
#line 296 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1765 "parser.c"
    break;

  case 39: /* expression_statement: expression asi_semicolon  */
#line 302 "parser.y"
    {
        (yyval.node) = create_expression_statement((yyvsp[-1].node));
    }
#line 1773 "parser.c"
    break;

  case 40: /* asi_semicolon: SEMICOLON  */
#line 309 "parser.y"
                { (yyval.node) = NULL; }
#line 1779 "parser.c"
    break;

  case 41: /* asi_semicolon: NEWLINE  */
#line 310 "parser.y"
              { (yyval.node) = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); }
#line 1785 "parser.c"
    break;

  case 42: /* asi_semicolon: %empty  */
#line 311 "parser.y"
                  { (yyval.node) = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); }
#line 1791 "parser.c"
    break;

  case 43: /* empty_statement: SEMICOLON  */
#line 317 "parser.y"
    {
        (yyval.node) = create_empty_statement();
    }
#line 1799 "parser.c"
    break;

  case 44: /* block_statement: LBRACE statements RBRACE  */
#line 325 "parser.y"
    {
        (yyval.node) = create_block_statement((yyvsp[-1].node)->data.program.statements, (yyvsp[-1].node)->data.program.statement_count);
        free((yyvsp[-1].node)); // 释放临时的 program 节点，但保留其中的语句
    }
#line 1808 "parser.c"
    break;

  case 45: /* block_statement: LBRACE RBRACE  */
#line 330 "parser.y"
    {
        ASTNode** body = malloc(sizeof(ASTNode*) * 0);
        (yyval.node) = create_block_statement(body, 0);
    }
#line 1817 "parser.c"
    break;

  case 46: /* if_statement: IF LPAREN expression RPAREN statement  */
#line 339 "parser.y"
    {
        (yyval.node) = create_if_statement((yyvsp[-2].node), (yyvsp[0].node), NULL);
    }
#line 1825 "parser.c"
    break;

  case 47: /* if_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 343 "parser.y"
    {
        (yyval.node) = create_if_statement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1833 "parser.c"
    break;

  case 48: /* while_statement: WHILE LPAREN expression RPAREN statement  */
#line 351 "parser.y"
    {
        (yyval.node) = create_while_statement((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1841 "parser.c"
    break;

  case 49: /* for_statement: FOR LPAREN for_init SEMICOLON for_cond SEMICOLON for_iter RPAREN statement  */
#line 359 "parser.y"
    {
        (yyval.node) = create_for_statement((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1849 "parser.c"
    break;

  case 50: /* for_init: %empty  */
#line 365 "parser.y"
                  { (yyval.node) = NULL; }
#line 1855 "parser.c"
    break;

  case 51: /* for_init: variable_declaration_no_semi  */
#line 366 "parser.y"
                                   { (yyval.node) = (yyvsp[0].node); }
#line 1861 "parser.c"
    break;

  case 52: /* for_init: expression  */
#line 367 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1867 "parser.c"
    break;

  case 53: /* for_cond: %empty  */
#line 371 "parser.y"
                  { (yyval.node) = NULL; }
#line 1873 "parser.c"
    break;

  case 54: /* for_cond: expression  */
#line 372 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1879 "parser.c"
    break;

  case 55: /* for_iter: %empty  */
#line 376 "parser.y"
                  { (yyval.node) = NULL; }
#line 1885 "parser.c"
    break;

  case 56: /* for_iter: expression  */
#line 377 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1891 "parser.c"
    break;

  case 57: /* variable_declaration_no_semi: VAR IDENTIFIER optional_initializer  */
#line 382 "parser.y"
    {
        (yyval.node) = create_variable_declaration("var", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 1900 "parser.c"
    break;

  case 58: /* variable_declaration_no_semi: LET IDENTIFIER optional_initializer  */
#line 387 "parser.y"
    {
        (yyval.node) = create_variable_declaration("let", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 1909 "parser.c"
    break;

  case 59: /* variable_declaration_no_semi: CONST IDENTIFIER optional_initializer  */
#line 392 "parser.y"
    {
        (yyval.node) = create_variable_declaration("const", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 1918 "parser.c"
    break;

  case 60: /* function_declaration: FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement  */
#line 401 "parser.y"
    {
        (yyval.node) = create_function_declaration((yyvsp[-4].str), (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-4].str));
        free((yyvsp[-2].param_list)); // 释放参数列表结构体，但不释放字符串（它们被转移到了 AST 节点中）
    }
#line 1928 "parser.c"
    break;

  case 61: /* parameter_list_opt: %empty  */
#line 410 "parser.y"
    {
        (yyval.param_list) = malloc(sizeof(ParamList));
        (yyval.param_list)->parameters = malloc(sizeof(char*) * 0);
        (yyval.param_list)->parameter_count = 0;
    }
#line 1938 "parser.c"
    break;

  case 62: /* parameter_list_opt: parameter_list  */
#line 416 "parser.y"
    {
        (yyval.param_list) = (yyvsp[0].param_list);
    }
#line 1946 "parser.c"
    break;

  case 63: /* parameter_list: IDENTIFIER  */
#line 423 "parser.y"
    {
        (yyval.param_list) = malloc(sizeof(ParamList));
        (yyval.param_list)->parameters = malloc(sizeof(char*) * 1);
        (yyval.param_list)->parameters[0] = (yyvsp[0].str);
        (yyval.param_list)->parameter_count = 1;
    }
#line 1957 "parser.c"
    break;

  case 64: /* parameter_list: parameter_list COMMA IDENTIFIER  */
#line 430 "parser.y"
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
#line 1976 "parser.c"
    break;

  case 65: /* return_statement: RETURN expression_opt asi_semicolon  */
#line 449 "parser.y"
    {
        (yyval.node) = create_return_statement((yyvsp[-1].node));
    }
#line 1984 "parser.c"
    break;

  case 66: /* break_statement: BREAK asi_semicolon  */
#line 457 "parser.y"
    {
        (yyval.node) = create_break_statement();
    }
#line 1992 "parser.c"
    break;

  case 67: /* continue_statement: CONTINUE asi_semicolon  */
#line 464 "parser.y"
    {
        (yyval.node) = create_continue_statement();
    }
#line 2000 "parser.c"
    break;

  case 68: /* expression_opt: %empty  */
#line 470 "parser.y"
                  { (yyval.node) = NULL; }
#line 2006 "parser.c"
    break;

  case 69: /* expression_opt: expression  */
#line 471 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2012 "parser.c"
    break;

  case 70: /* expression: assignment_expression  */
#line 476 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2018 "parser.c"
    break;

  case 71: /* assignment_expression: conditional_expression  */
#line 480 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2024 "parser.c"
    break;

  case 72: /* assignment_expression: left_hand_side EQUALS assignment_expression  */
#line 482 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2032 "parser.c"
    break;

  case 73: /* assignment_expression: left_hand_side PLUS_EQ assignment_expression  */
#line 486 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_ADD_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2040 "parser.c"
    break;

  case 74: /* assignment_expression: left_hand_side MINUS_EQ assignment_expression  */
#line 490 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_SUB_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2048 "parser.c"
    break;

  case 75: /* assignment_expression: left_hand_side STAR_EQ assignment_expression  */
#line 494 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_MUL_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2056 "parser.c"
    break;

  case 76: /* assignment_expression: left_hand_side SLASH_EQ assignment_expression  */
#line 498 "parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_DIV_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2064 "parser.c"
    break;

  case 77: /* left_hand_side: IDENTIFIER  */
#line 505 "parser.y"
                 { (yyval.node) = create_identifier((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2070 "parser.c"
    break;

  case 78: /* left_hand_side: member_expression  */
#line 506 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2076 "parser.c"
    break;

  case 79: /* conditional_expression: logical_or_expression  */
#line 510 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2082 "parser.c"
    break;

  case 80: /* conditional_expression: logical_or_expression QUESTION expression COLON conditional_expression  */
#line 512 "parser.y"
    {
        (yyval.node) = create_conditional_expression((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2090 "parser.c"
    break;

  case 81: /* logical_or_expression: logical_and_expression  */
#line 518 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2096 "parser.c"
    break;

  case 82: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 520 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_OR, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2104 "parser.c"
    break;

  case 83: /* logical_and_expression: equality_expression  */
#line 526 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2110 "parser.c"
    break;

  case 84: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 528 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_AND, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2118 "parser.c"
    break;

  case 85: /* equality_expression: relational_expression  */
#line 534 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2124 "parser.c"
    break;

  case 86: /* equality_expression: equality_expression EQ_EQ relational_expression  */
#line 536 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2132 "parser.c"
    break;

  case 87: /* equality_expression: equality_expression NOT_EQ relational_expression  */
#line 540 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_NEQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2140 "parser.c"
    break;

  case 88: /* equality_expression: equality_expression STRICT_EQ relational_expression  */
#line 544 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_STRICT_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2148 "parser.c"
    break;

  case 89: /* equality_expression: equality_expression STRICT_NOT_EQ relational_expression  */
#line 548 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_STRICT_NEQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2156 "parser.c"
    break;

  case 90: /* relational_expression: additive_expression  */
#line 554 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2162 "parser.c"
    break;

  case 91: /* relational_expression: relational_expression LT additive_expression  */
#line 556 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_LT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2170 "parser.c"
    break;

  case 92: /* relational_expression: relational_expression LE additive_expression  */
#line 560 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_LE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2178 "parser.c"
    break;

  case 93: /* relational_expression: relational_expression GT additive_expression  */
#line 564 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_GT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2186 "parser.c"
    break;

  case 94: /* relational_expression: relational_expression GE additive_expression  */
#line 568 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_GE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2194 "parser.c"
    break;

  case 95: /* additive_expression: multiplicative_expression  */
#line 574 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2200 "parser.c"
    break;

  case 96: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 576 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_ADD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2208 "parser.c"
    break;

  case 97: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 580 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_SUB, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2216 "parser.c"
    break;

  case 98: /* multiplicative_expression: unary_expression  */
#line 586 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2222 "parser.c"
    break;

  case 99: /* multiplicative_expression: multiplicative_expression STAR unary_expression  */
#line 588 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_MUL, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2230 "parser.c"
    break;

  case 100: /* multiplicative_expression: multiplicative_expression SLASH unary_expression  */
#line 592 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_DIV, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2238 "parser.c"
    break;

  case 101: /* multiplicative_expression: multiplicative_expression PERCENT unary_expression  */
#line 596 "parser.y"
    {
        (yyval.node) = create_binary_expression(OP_MOD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2246 "parser.c"
    break;

  case 102: /* unary_expression: postfix_expression  */
#line 602 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2252 "parser.c"
    break;

  case 103: /* unary_expression: PLUS unary_expression  */
#line 604 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_ADD, (yyvsp[0].node));
    }
#line 2260 "parser.c"
    break;

  case 104: /* unary_expression: MINUS unary_expression  */
#line 608 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_SUB, (yyvsp[0].node));
    }
#line 2268 "parser.c"
    break;

  case 105: /* unary_expression: BANG unary_expression  */
#line 612 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_NOT, (yyvsp[0].node));
    }
#line 2276 "parser.c"
    break;

  case 106: /* unary_expression: PLUS_PLUS unary_expression  */
#line 616 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_PRE_INC, (yyvsp[0].node));
    }
#line 2284 "parser.c"
    break;

  case 107: /* unary_expression: MINUS_MINUS unary_expression  */
#line 620 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_PRE_DEC, (yyvsp[0].node));
    }
#line 2292 "parser.c"
    break;

  case 108: /* postfix_expression: primary_expression  */
#line 626 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2298 "parser.c"
    break;

  case 109: /* postfix_expression: call_expression  */
#line 627 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2304 "parser.c"
    break;

  case 110: /* postfix_expression: member_expression  */
#line 628 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2310 "parser.c"
    break;

  case 111: /* postfix_expression: new_expression  */
#line 629 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2316 "parser.c"
    break;

  case 112: /* postfix_expression: postfix_expression PLUS_PLUS  */
#line 631 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_POST_INC, (yyvsp[-1].node));
    }
#line 2324 "parser.c"
    break;

  case 113: /* postfix_expression: postfix_expression MINUS_MINUS  */
#line 635 "parser.y"
    {
        (yyval.node) = create_unary_expression(OP_POST_DEC, (yyvsp[-1].node));
    }
#line 2332 "parser.c"
    break;

  case 114: /* call_expression: primary_expression LPAREN argument_list_opt RPAREN  */
#line 643 "parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2341 "parser.c"
    break;

  case 115: /* call_expression: call_expression LPAREN argument_list_opt RPAREN  */
#line 648 "parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2350 "parser.c"
    break;

  case 116: /* call_expression: member_expression LPAREN argument_list_opt RPAREN  */
#line 653 "parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2359 "parser.c"
    break;

  case 117: /* member_expression: primary_expression DOT IDENTIFIER  */
#line 662 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-2].node), create_identifier((yyvsp[0].str)), 0);
        free((yyvsp[0].str));
    }
#line 2368 "parser.c"
    break;

  case 118: /* member_expression: member_expression DOT IDENTIFIER  */
#line 667 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-2].node), create_identifier((yyvsp[0].str)), 0);
        free((yyvsp[0].str));
    }
#line 2377 "parser.c"
    break;

  case 119: /* member_expression: primary_expression LBRACKET expression RBRACKET  */
#line 672 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-3].node), (yyvsp[-1].node), 1);
    }
#line 2385 "parser.c"
    break;

  case 120: /* member_expression: member_expression LBRACKET expression RBRACKET  */
#line 676 "parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-3].node), (yyvsp[-1].node), 1);
    }
#line 2393 "parser.c"
    break;

  case 121: /* new_expression: NEW member_expression LPAREN argument_list_opt RPAREN  */
#line 684 "parser.y"
    {
        (yyval.node) = create_new_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2402 "parser.c"
    break;

  case 122: /* new_expression: NEW call_expression  */
#line 689 "parser.y"
    {
        (yyval.node) = create_new_expression((yyvsp[0].node), NULL, 0);
    }
#line 2410 "parser.c"
    break;

  case 123: /* primary_expression: IDENTIFIER  */
#line 695 "parser.y"
                 { (yyval.node) = create_identifier((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2416 "parser.c"
    break;

  case 124: /* primary_expression: NUMBER  */
#line 696 "parser.y"
             { (yyval.node) = create_number((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2422 "parser.c"
    break;

  case 125: /* primary_expression: STRING  */
#line 697 "parser.y"
             { (yyval.node) = create_string((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2428 "parser.c"
    break;

  case 126: /* primary_expression: TRUE  */
#line 698 "parser.y"
           { (yyval.node) = create_boolean(1); }
#line 2434 "parser.c"
    break;

  case 127: /* primary_expression: FALSE  */
#line 699 "parser.y"
            { (yyval.node) = create_boolean(0); }
#line 2440 "parser.c"
    break;

  case 128: /* primary_expression: NULL_LITERAL  */
#line 700 "parser.y"
                   { (yyval.node) = create_null(); }
#line 2446 "parser.c"
    break;

  case 129: /* primary_expression: UNDEFINED  */
#line 701 "parser.y"
                { (yyval.node) = create_undefined(); }
#line 2452 "parser.c"
    break;

  case 130: /* primary_expression: THIS  */
#line 702 "parser.y"
           { (yyval.node) = create_this_expression(); }
#line 2458 "parser.c"
    break;

  case 131: /* primary_expression: SUPER  */
#line 703 "parser.y"
            { (yyval.node) = create_super_expression(); }
#line 2464 "parser.c"
    break;

  case 132: /* primary_expression: array_literal  */
#line 704 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2470 "parser.c"
    break;

  case 133: /* primary_expression: LPAREN expression RPAREN  */
#line 705 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 2476 "parser.c"
    break;

  case 134: /* argument_list_opt: %empty  */
#line 710 "parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 0);
        (yyval.arg_list)->argument_count = 0;
    }
#line 2486 "parser.c"
    break;

  case 135: /* argument_list_opt: argument_list  */
#line 716 "parser.y"
    {
        (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 2494 "parser.c"
    break;

  case 136: /* argument_list: expression  */
#line 723 "parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 1);
        (yyval.arg_list)->arguments[0] = (yyvsp[0].node);
        (yyval.arg_list)->argument_count = 1;
    }
#line 2505 "parser.c"
    break;

  case 137: /* argument_list: argument_list COMMA expression  */
#line 730 "parser.y"
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
#line 2524 "parser.c"
    break;

  case 138: /* array_literal: LBRACKET array_element_list_opt RBRACKET  */
#line 749 "parser.y"
    {
        (yyval.node) = create_array_literal((yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2533 "parser.c"
    break;

  case 139: /* array_element_list_opt: %empty  */
#line 757 "parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 0);
        (yyval.arg_list)->argument_count = 0;
    }
#line 2543 "parser.c"
    break;

  case 140: /* array_element_list_opt: array_element_list  */
#line 763 "parser.y"
    {
        (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 2551 "parser.c"
    break;

  case 141: /* array_element_list: expression  */
#line 770 "parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 1);
        (yyval.arg_list)->arguments[0] = (yyvsp[0].node);
        (yyval.arg_list)->argument_count = 1;
    }
#line 2562 "parser.c"
    break;

  case 142: /* array_element_list: array_element_list COMMA expression  */
#line 777 "parser.y"
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
#line 2581 "parser.c"
    break;


#line 2585 "parser.c"

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

#line 794 "parser.y"


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
