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
#line 1 "src/parser.y"

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


#line 91 "src/parser.c"

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
  YYSYMBOL_DOT_DOT_DOT = 63,               /* DOT_DOT_DOT  */
  YYSYMBOL_ARROW = 64,                     /* ARROW  */
  YYSYMBOL_TEMPLATE_STRING = 65,           /* TEMPLATE_STRING  */
  YYSYMBOL_REGEXP_LITERAL = 66,            /* REGEXP_LITERAL  */
  YYSYMBOL_SWITCH = 67,                    /* SWITCH  */
  YYSYMBOL_CASE = 68,                      /* CASE  */
  YYSYMBOL_DEFAULT = 69,                   /* DEFAULT  */
  YYSYMBOL_TRY = 70,                       /* TRY  */
  YYSYMBOL_CATCH = 71,                     /* CATCH  */
  YYSYMBOL_FINALLY = 72,                   /* FINALLY  */
  YYSYMBOL_ERROR = 73,                     /* ERROR  */
  YYSYMBOL_POSTFIX = 74,                   /* POSTFIX  */
  YYSYMBOL_ASSIGNMENT = 75,                /* ASSIGNMENT  */
  YYSYMBOL_BITWISE_OR = 76,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 77,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_AND = 78,               /* BITWISE_AND  */
  YYSYMBOL_EQUALITY = 79,                  /* EQUALITY  */
  YYSYMBOL_RELATIONAL = 80,                /* RELATIONAL  */
  YYSYMBOL_SHIFT = 81,                     /* SHIFT  */
  YYSYMBOL_ADDITIVE = 82,                  /* ADDITIVE  */
  YYSYMBOL_MULTIPLICATIVE = 83,            /* MULTIPLICATIVE  */
  YYSYMBOL_EXPONENTIAL = 84,               /* EXPONENTIAL  */
  YYSYMBOL_UNARY = 85,                     /* UNARY  */
  YYSYMBOL_CALL = 86,                      /* CALL  */
  YYSYMBOL_PRE_INC = 87,                   /* PRE_INC  */
  YYSYMBOL_PRE_DEC = 88,                   /* PRE_DEC  */
  YYSYMBOL_POST_INC = 89,                  /* POST_INC  */
  YYSYMBOL_POST_DEC = 90,                  /* POST_DEC  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_program = 92,                   /* program  */
  YYSYMBOL_statements = 93,                /* statements  */
  YYSYMBOL_statement = 94,                 /* statement  */
  YYSYMBOL_class_declaration = 95,         /* class_declaration  */
  YYSYMBOL_class_extends_opt = 96,         /* class_extends_opt  */
  YYSYMBOL_class_body = 97,                /* class_body  */
  YYSYMBOL_class_element_list_opt = 98,    /* class_element_list_opt  */
  YYSYMBOL_class_element_list = 99,        /* class_element_list  */
  YYSYMBOL_class_element = 100,            /* class_element  */
  YYSYMBOL_static_opt = 101,               /* static_opt  */
  YYSYMBOL_method_definition = 102,        /* method_definition  */
  YYSYMBOL_property_definition = 103,      /* property_definition  */
  YYSYMBOL_variable_declaration = 104,     /* variable_declaration  */
  YYSYMBOL_optional_initializer = 105,     /* optional_initializer  */
  YYSYMBOL_expression_statement = 106,     /* expression_statement  */
  YYSYMBOL_asi_semicolon = 107,            /* asi_semicolon  */
  YYSYMBOL_empty_statement = 108,          /* empty_statement  */
  YYSYMBOL_block_statement = 109,          /* block_statement  */
  YYSYMBOL_if_statement = 110,             /* if_statement  */
  YYSYMBOL_while_statement = 111,          /* while_statement  */
  YYSYMBOL_for_statement = 112,            /* for_statement  */
  YYSYMBOL_for_init = 113,                 /* for_init  */
  YYSYMBOL_for_cond = 114,                 /* for_cond  */
  YYSYMBOL_for_iter = 115,                 /* for_iter  */
  YYSYMBOL_variable_declaration_no_semi = 116, /* variable_declaration_no_semi  */
  YYSYMBOL_switch_statement = 117,         /* switch_statement  */
  YYSYMBOL_try_statement = 118,            /* try_statement  */
  YYSYMBOL_function_declaration = 119,     /* function_declaration  */
  YYSYMBOL_parameter_list_opt = 120,       /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 121,           /* parameter_list  */
  YYSYMBOL_return_statement = 122,         /* return_statement  */
  YYSYMBOL_function_expression = 123,      /* function_expression  */
  YYSYMBOL_break_statement = 124,          /* break_statement  */
  YYSYMBOL_continue_statement = 125,       /* continue_statement  */
  YYSYMBOL_expression_opt = 126,           /* expression_opt  */
  YYSYMBOL_expression = 127,               /* expression  */
  YYSYMBOL_assignment_expression = 128,    /* assignment_expression  */
  YYSYMBOL_left_hand_side = 129,           /* left_hand_side  */
  YYSYMBOL_conditional_expression = 130,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 131,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 132,   /* logical_and_expression  */
  YYSYMBOL_equality_expression = 133,      /* equality_expression  */
  YYSYMBOL_relational_expression = 134,    /* relational_expression  */
  YYSYMBOL_additive_expression = 135,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 136, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 137,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 138,       /* postfix_expression  */
  YYSYMBOL_left_hand_side_expression = 139, /* left_hand_side_expression  */
  YYSYMBOL_call_expression = 140,          /* call_expression  */
  YYSYMBOL_member_expression = 141,        /* member_expression  */
  YYSYMBOL_new_expression = 142,           /* new_expression  */
  YYSYMBOL_primary_expression = 143,       /* primary_expression  */
  YYSYMBOL_argument_list_opt = 144,        /* argument_list_opt  */
  YYSYMBOL_argument_list = 145,            /* argument_list  */
  YYSYMBOL_array_literal = 146,            /* array_literal  */
  YYSYMBOL_array_element_list_opt = 147,   /* array_element_list_opt  */
  YYSYMBOL_array_element_list = 148,       /* array_element_list  */
  YYSYMBOL_object_literal = 149,           /* object_literal  */
  YYSYMBOL_property_list_opt = 150,        /* property_list_opt  */
  YYSYMBOL_property_list = 151,            /* property_list  */
  YYSYMBOL_property = 152,                 /* property  */
  YYSYMBOL_arrow_function = 153,           /* arrow_function  */
  YYSYMBOL_spread_element = 154            /* spread_element  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  123
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   963

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   345


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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   126,   130,   136,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     172,   180,   181,   185,   194,   199,   206,   213,   231,   237,
     246,   247,   251,   259,   271,   278,   289,   294,   299,   307,
     308,   313,   321,   322,   323,   328,   336,   341,   350,   354,
     362,   370,   377,   378,   379,   383,   384,   388,   389,   393,
     398,   403,   412,   420,   426,   431,   439,   449,   454,   461,
     468,   487,   494,   500,   509,   516,   523,   524,   529,   533,
     534,   538,   542,   546,   550,   558,   559,   560,   561,   562,
     566,   567,   574,   575,   582,   583,   590,   591,   595,   599,
     603,   610,   611,   615,   619,   623,   630,   631,   635,   642,
     643,   647,   651,   658,   659,   663,   667,   671,   675,   683,
     684,   688,   695,   696,   697,   702,   707,   716,   717,   722,
     726,   731,   739,   744,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     771,   776,   783,   791,   812,   821,   826,   834,   839,   846,
     853,   858,   873,   892,   901,   906,   913,   920,   938,   943,
     948,   953,   961,   967,   972,   985,  1001
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
  "QUESTION", "DOT_DOT_DOT", "ARROW", "TEMPLATE_STRING", "REGEXP_LITERAL",
  "SWITCH", "CASE", "DEFAULT", "TRY", "CATCH", "FINALLY", "ERROR",
  "POSTFIX", "ASSIGNMENT", "BITWISE_OR", "BITWISE_XOR", "BITWISE_AND",
  "EQUALITY", "RELATIONAL", "SHIFT", "ADDITIVE", "MULTIPLICATIVE",
  "EXPONENTIAL", "UNARY", "CALL", "PRE_INC", "PRE_DEC", "POST_INC",
  "POST_DEC", "$accept", "program", "statements", "statement",
  "class_declaration", "class_extends_opt", "class_body",
  "class_element_list_opt", "class_element_list", "class_element",
  "static_opt", "method_definition", "property_definition",
  "variable_declaration", "optional_initializer", "expression_statement",
  "asi_semicolon", "empty_statement", "block_statement", "if_statement",
  "while_statement", "for_statement", "for_init", "for_cond", "for_iter",
  "variable_declaration_no_semi", "switch_statement", "try_statement",
  "function_declaration", "parameter_list_opt", "parameter_list",
  "return_statement", "function_expression", "break_statement",
  "continue_statement", "expression_opt", "expression",
  "assignment_expression", "left_hand_side", "conditional_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "postfix_expression",
  "left_hand_side_expression", "call_expression", "member_expression",
  "new_expression", "primary_expression", "argument_list_opt",
  "argument_list", "array_literal", "array_element_list_opt",
  "array_element_list", "object_literal", "property_list_opt",
  "property_list", "property", "arrow_function", "spread_element", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-170)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     562,   -23,    25,    33,   -11,    60,    75,    83,   725,   -19,
     -19,  -136,  -136,  -136,  -136,    84,   897,  -136,  -136,     6,
    -136,  -136,   768,   768,   768,   768,   768,   811,   362,   619,
    -136,  -136,  -136,    68,   -34,   143,   562,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,   -19,  -136,    85,  -136,    14,   102,   117,
     140,   -16,    96,  -136,   -24,  -136,    65,   231,  -136,  -136,
      89,   122,  -136,   725,   725,    17,    95,   131,   114,   114,
     114,     9,     2,   -19,  -136,  -136,  -136,  -136,  -136,   136,
     103,    28,    66,  -136,  -136,   854,  -136,    28,   139,  -136,
    -136,  -136,  -136,    41,   107,   115,   124,    47,   129,  -136,
     619,   430,   113,   130,  -136,   725,  -136,   148,   137,  -136,
     725,   496,    32,  -136,  -136,  -136,   725,   725,   725,   725,
     725,   768,   725,   768,   768,   768,   768,   768,   768,   768,
     768,   768,   768,   768,   768,   768,   768,  -136,  -136,   725,
     725,   171,   725,   725,   181,   155,   158,   186,   189,   192,
     161,  -136,  -136,   131,  -136,   160,   725,   -19,   -19,   -19,
     168,   166,   129,   725,  -136,   202,   176,   725,  -136,  -136,
     172,   211,  -136,   725,   725,   191,  -136,  -136,     2,  -136,
    -136,   672,   196,   198,   -34,  -136,  -136,  -136,  -136,  -136,
     102,   199,   117,   140,   140,   140,   140,   -16,   -16,   -16,
     -16,    96,    96,  -136,  -136,  -136,  -136,   206,   193,   205,
    -136,   210,   207,  -136,   562,   562,   114,   114,   114,   725,
     213,   -34,  -136,  -136,  -136,  -136,   131,   191,  -136,    -6,
     -19,   214,   854,  -136,  -136,  -136,   208,  -136,  -136,  -136,
     -34,   242,  -136,   768,  -136,   725,  -136,  -136,  -136,   267,
    -136,  -136,  -136,  -136,   215,  -136,   -34,  -136,   221,  -136,
     229,    -4,  -136,    48,  -136,   154,  -136,  -136,   725,  -136,
     232,  -136,  -136,   562,   725,   896,   -34,  -136,  -136,   234,
      16,  -136,   230,  -136,   -34,  -136,   236,  -136,  -136,   131,
     725,   131,  -136,   218,   562,   241,  -136,   257,   -34,  -136,
     -34,   -34,  -136,  -136,  -136
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,    76,    44,
      44,   139,   140,   141,   142,     0,     0,   143,   144,   134,
     135,   136,     0,     0,     0,     0,     0,    67,     0,   155,
      45,   137,   138,     0,     0,     0,     2,     4,    12,     6,
       7,    17,    16,     8,     9,    10,    18,    19,    11,    13,
     148,    14,    15,    44,    78,     0,    79,    90,    92,    94,
      96,   101,   106,   109,   113,   119,   122,   123,   124,   127,
     145,   146,   147,     0,     0,    52,     0,    67,    39,    39,
      39,     0,   164,    44,    77,    43,    42,    74,    75,    21,
     134,     0,   133,   145,   146,     0,   114,   122,   123,   115,
     116,   117,   118,   134,     0,    68,     0,   134,   136,    47,
     155,     0,     0,   165,   166,     0,   158,     0,   156,   159,
       0,     0,     0,     1,     5,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,   150,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    67,    69,     0,     0,    44,    44,    44,
       0,   169,     0,     0,    71,     0,     0,   150,   175,   174,
       0,     0,   149,     0,     0,   158,    46,   163,     0,   176,
     154,   160,     0,     0,     0,    80,    81,    82,    83,    84,
      93,     0,    95,    97,    98,    99,   100,   102,   103,   104,
     105,   107,   108,   110,   111,   112,   152,     0,   151,     0,
     130,     0,     0,   128,     0,     0,    39,    39,    39,    55,
       0,     0,    40,    36,    37,    38,    67,     0,    22,    30,
      44,     0,     0,    70,   168,   170,     0,   167,   161,   162,
       0,     0,    65,     0,   126,     0,   131,   125,   129,    48,
      50,    59,    60,    61,     0,    56,     0,    73,     0,    31,
       0,    30,    26,     0,    20,   132,   173,   172,     0,    62,
       0,    91,   153,     0,    57,    66,     0,    23,    27,     0,
      34,    28,     0,   171,     0,    49,     0,    58,    72,    67,
       0,    67,    29,    63,     0,     0,    35,     0,     0,    51,
       0,     0,    64,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   329,   -32,  -136,  -136,  -136,  -136,  -136,    59,
    -136,  -136,  -136,  -136,   -77,  -136,    -5,  -136,   -33,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   -70,
    -136,  -136,  -136,  -136,  -136,  -136,    -8,   128,  -136,    79,
    -136,   217,   233,   109,   187,   -90,   -14,  -136,  -136,   162,
     178,  -136,  -136,  -135,  -136,   200,  -136,  -136,   216,  -136,
    -136,   175,  -136,   173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    35,   111,    37,    38,   176,   240,   270,   271,   272,
     273,   291,   292,    39,   167,    40,    87,    41,    42,    43,
      44,    45,   160,   264,   296,   161,    46,    47,    48,   104,
     105,    49,    50,    51,    52,    83,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,   217,   218,    70,   117,   118,    71,   112,
     113,   114,    72,   119
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,   122,   168,   169,   124,    88,    85,   165,    96,    99,
     100,   101,   102,   142,   143,    76,   269,   221,   269,   106,
     121,   116,   147,   148,    81,   157,   158,   159,   171,    73,
     172,    11,    12,    13,    14,   170,    16,    17,    18,    86,
     -85,    77,   241,    19,    20,    21,    22,    23,   125,   -24,
     300,   -25,   211,   212,   -85,   -85,   -85,   -85,   173,   131,
      24,    77,   178,    25,    26,   155,   156,   162,   301,    27,
      95,    82,   289,    29,   290,   -85,   132,    74,   174,   124,
     149,   -85,    31,    32,   150,    75,    78,   179,   151,   -85,
     -85,   -85,   -85,   230,   -69,   -85,   -85,   -85,   -85,   -87,
     -69,    79,   185,   193,   194,    95,  -169,   189,   183,    80,
      89,    95,   192,   -87,   -87,   -87,   -87,   149,   177,   126,
     120,   150,   153,   -88,   201,   151,   154,   144,   145,   146,
     213,   214,   215,   127,   128,   129,   130,   -88,   -88,   -88,
     -88,   216,   219,   123,   216,   222,   133,   163,   166,   261,
     262,   263,   134,   135,   136,   137,   -89,   164,   232,   175,
     180,   252,   233,   234,   235,   237,   268,    95,   187,   216,
     -89,   -89,   -89,   -89,   181,   244,   245,   182,    91,   138,
     139,   140,   141,   248,    97,    97,    97,    97,    97,   188,
     184,   152,   259,   260,    92,   153,   191,   220,   267,   154,
      98,    98,    98,    98,    98,   190,  -125,   223,   224,   276,
    -125,   225,   226,   231,  -125,   227,    93,   279,   228,   229,
     236,   265,    93,    93,    93,    93,    93,   183,   238,   305,
     239,   307,    94,   285,   277,   274,   242,   243,    94,    94,
      94,    94,    94,   203,   204,   205,   206,   282,   246,   250,
     251,   295,   255,   298,   195,   196,   197,   198,   199,   254,
     253,   303,   256,   257,   258,   -86,   266,   275,   280,   278,
     293,   283,   309,   284,   286,   312,   297,   313,   314,   -86,
     -86,   -86,   -86,   152,   287,   294,   299,   153,   302,   304,
     308,   154,   306,    97,   310,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
     311,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,   207,   208,   209,   210,    36,
     288,    93,   281,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,   200,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,   247,   249,     1,   202,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,   107,    20,
     108,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    97,    28,   109,   110,     0,
      30,     0,     0,     0,     0,     0,     0,    31,    32,    33,
       0,    98,    34,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,    93,     0,     0,    19,    20,    21,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,     0,    24,     0,     0,    25,    26,     0,     0,
       0,     0,    27,     0,    28,   186,    29,     0,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,     0,     1,
      34,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,    19,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,    25,    26,     0,     0,     0,     0,    27,     0,
      28,   109,    29,     0,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,     0,     1,    34,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,    19,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    25,    26,
       0,     0,     0,     0,    27,     0,    28,     0,    29,     0,
      30,     0,     0,     0,     0,     0,    81,    31,    32,    33,
       0,     0,    34,    11,    12,    13,    14,     0,    16,    17,
      18,     0,     0,     0,     0,    19,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,    25,    26,     0,     0,     0,
       0,    27,     0,    82,     0,    29,     0,     0,  -157,    81,
       0,     0,   115,     0,    31,    32,    11,    12,    13,    14,
       0,    16,    17,    18,     0,     0,     0,     0,    19,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    25,    26,
       0,     0,     0,     0,    27,     0,    82,     0,    29,     0,
       0,     0,    81,     0,     0,   115,     0,    31,    32,    11,
      12,    13,    14,     0,    16,    17,    18,     0,     0,     0,
       0,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    25,    26,     0,     0,    81,     0,    27,     0,    82,
       0,    29,    11,    12,    13,    14,     0,    16,    17,    18,
      31,    32,     0,     0,    90,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,    25,    26,     0,     0,    81,     0,
      27,     0,    82,     0,    29,    11,    12,    13,    14,     0,
      16,    17,    18,    31,    32,     0,     0,   103,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,    25,    26,     0,
       0,    81,     0,    27,     0,    82,     0,    29,    11,    12,
      13,    14,     0,    16,    17,    18,    31,    32,     0,     0,
      19,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,     0,
      25,    26,     0,     0,    81,     0,    27,     0,    28,     0,
      29,    11,    12,    13,    14,     0,     0,    17,    18,    31,
      32,   -72,     0,    90,    20,    21,     0,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,
     -72,   -72,     0,     0,   -72,   -72,   -72,   -72,     0,    27,
       0,    82,     0,    29,     0,     0,   -72,     0,   -72,     0,
       0,     0,    31,    32
};

static const yytype_int16 yycheck[] =
{
       8,    34,    79,    80,    36,    10,    25,    77,    22,    23,
      24,    25,    26,    29,    30,    26,    22,   152,    22,    27,
      54,    29,    46,    47,     7,     8,     9,    10,    26,    52,
      28,    14,    15,    16,    17,    26,    19,    20,    21,    58,
      34,    52,   177,    26,    27,    28,    29,    30,    53,    55,
      34,    55,   142,   143,    48,    49,    50,    51,    56,    45,
      43,    52,    95,    46,    47,    73,    74,    75,    52,    52,
      64,    54,    24,    56,    26,    34,    62,    52,    83,   111,
      52,    34,    65,    66,    56,    52,    26,    95,    60,    48,
      49,    50,    51,   163,    53,    48,    49,    50,    51,    34,
      59,    26,   110,    71,    72,    64,    59,   115,    61,    26,
      26,    64,   120,    48,    49,    50,    51,    52,    52,    34,
      52,    56,    56,    34,   132,    60,    60,    31,    32,    33,
     144,   145,   146,    48,    49,    50,    51,    48,    49,    50,
      51,   149,   150,     0,   152,   153,    44,    52,    34,   226,
     227,   228,    35,    36,    37,    38,    34,    26,   166,    23,
      53,   194,   167,   168,   169,   173,   236,    64,    55,   177,
      48,    49,    50,    51,    59,   183,   184,    53,    16,    39,
      40,    41,    42,   191,    22,    23,    24,    25,    26,    59,
      61,    52,   224,   225,    16,    56,    59,    26,   231,    60,
      22,    23,    24,    25,    26,    57,    52,    26,    53,   242,
      56,    53,    26,    53,    60,    26,    16,   250,    26,    58,
      52,   229,    22,    23,    24,    25,    26,    61,    26,   299,
      54,   301,    16,   266,   242,   240,    64,    26,    22,    23,
      24,    25,    26,   134,   135,   136,   137,   255,    57,    53,
      52,   283,    59,   286,   126,   127,   128,   129,   130,    53,
      61,   294,    57,    53,    57,    34,    53,    53,    26,    61,
     278,     4,   304,    58,    53,   308,   284,   310,   311,    48,
      49,    50,    51,    52,    55,    53,    52,    56,    58,    53,
      72,    60,   300,   131,    53,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   131,
      53,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   138,   139,   140,   141,     0,
     271,   131,   253,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   131,   131,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   188,   191,     3,   133,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,   253,    54,    55,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,   253,    70,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,   253,    -1,    -1,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,     3,
      70,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,     3,    70,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,     7,    65,    66,    67,
      -1,    -1,    70,    14,    15,    16,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    -1,    56,    -1,    -1,    59,     7,
      -1,    -1,    63,    -1,    65,    66,    14,    15,    16,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,
      -1,    -1,     7,    -1,    -1,    63,    -1,    65,    66,    14,
      15,    16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    46,    47,    -1,    -1,     7,    -1,    52,    -1,    54,
      -1,    56,    14,    15,    16,    17,    -1,    19,    20,    21,
      65,    66,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    46,    47,    -1,    -1,     7,    -1,
      52,    -1,    54,    -1,    56,    14,    15,    16,    17,    -1,
      19,    20,    21,    65,    66,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,    -1,
      -1,     7,    -1,    52,    -1,    54,    -1,    56,    14,    15,
      16,    17,    -1,    19,    20,    21,    65,    66,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      46,    47,    -1,    -1,     7,    -1,    52,    -1,    54,    -1,
      56,    14,    15,    16,    17,    -1,    -1,    20,    21,    65,
      66,    25,    -1,    26,    27,    28,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    -1,    48,    49,    50,    51,    -1,    52,
      -1,    54,    -1,    56,    -1,    -1,    60,    -1,    62,    -1,
      -1,    -1,    65,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    26,
      27,    28,    29,    30,    43,    46,    47,    52,    54,    56,
      58,    65,    66,    67,    70,    92,    93,    94,    95,   104,
     106,   108,   109,   110,   111,   112,   117,   118,   119,   122,
     123,   124,   125,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     146,   149,   153,    52,    52,    52,    26,    52,    26,    26,
      26,     7,    54,   126,   127,    25,    58,   107,   107,    26,
      26,   140,   141,   146,   149,    64,   137,   140,   141,   137,
     137,   137,   137,    26,   120,   121,   127,    26,    28,    55,
      56,    93,   150,   151,   152,    63,   127,   147,   148,   154,
      52,    54,   109,     0,    94,   107,    34,    48,    49,    50,
      51,    45,    62,    44,    35,    36,    37,    38,    39,    40,
      41,    42,    29,    30,    31,    32,    33,    46,    47,    52,
      56,    60,    52,    56,    60,   127,   127,     8,     9,    10,
     113,   116,   127,    52,    26,   120,    34,   105,   105,   105,
      26,    26,    28,    56,   107,    23,    96,    52,   109,   127,
      53,    59,    53,    61,    61,   127,    55,    55,    59,   127,
      57,    59,   127,    71,    72,   128,   128,   128,   128,   128,
     132,   127,   133,   134,   134,   134,   134,   135,   135,   135,
     135,   136,   136,   137,   137,   137,   127,   144,   145,   127,
      26,   144,   127,    26,    53,    53,    26,    26,    26,    58,
     120,    53,   127,   107,   107,   107,    52,   127,    26,    54,
      97,   144,    64,    26,   127,   127,    57,   152,   127,   154,
      53,    52,   109,    61,    53,    59,    57,    53,    57,    94,
      94,   105,   105,   105,   114,   127,    53,   109,   120,    22,
      98,    99,   100,   101,   107,    53,   109,   127,    61,   109,
      26,   130,   127,     4,    58,   109,    53,    55,   100,    24,
      26,   102,   103,   127,    53,    94,   115,   127,   109,    52,
      34,    52,    58,   109,    53,   120,   127,   120,    72,    94,
      53,    53,   109,   109,   109
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   105,
     105,   106,   107,   107,   107,   108,   109,   109,   110,   110,
     111,   112,   113,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   117,   118,   118,   118,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   125,   126,   126,   127,   128,
     128,   128,   128,   128,   128,   129,   129,   129,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   133,
     133,   134,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   138,
     138,   138,   139,   139,   139,   140,   140,   141,   141,   141,
     141,   141,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   145,   145,   146,   147,   147,   148,   148,   148,
     148,   148,   148,   149,   150,   150,   151,   151,   152,   152,
     152,   152,   153,   153,   153,   153,   154
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     0,     2,     3,     0,     1,     1,     2,     2,     3,
       0,     1,     5,     5,     1,     3,     4,     4,     4,     0,
       2,     2,     1,     1,     0,     1,     3,     2,     5,     7,
       5,     9,     0,     1,     1,     0,     1,     0,     1,     3,
       3,     3,     5,     7,     9,     4,     6,     0,     1,     1,
       3,     3,     6,     5,     2,     2,     0,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     4,     4,     1,     3,     4,
       3,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     3,     3,     0,     1,     0,     1,     1,
       2,     3,     3,     3,     0,     1,     1,     3,     3,     1,
       3,     5,     5,     5,     3,     3,     2
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
#line 117 "src/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        ast_root = (yyval.node);
        printf("PARSER: Successfully parsed program and built AST\n");
    }
#line 1613 "src/parser.c"
    break;

  case 3: /* statements: %empty  */
#line 126 "src/parser.y"
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 0);
        (yyval.node) = create_program(stmts, 0);
    }
#line 1622 "src/parser.c"
    break;

  case 4: /* statements: statement  */
#line 131 "src/parser.y"
    {
        ASTNode** stmts = malloc(sizeof(ASTNode*) * 1);
        stmts[0] = (yyvsp[0].node);
        (yyval.node) = create_program(stmts, 1);
    }
#line 1632 "src/parser.c"
    break;

  case 5: /* statements: statements statement  */
#line 137 "src/parser.y"
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
#line 1651 "src/parser.c"
    break;

  case 6: /* statement: variable_declaration  */
#line 154 "src/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1657 "src/parser.c"
    break;

  case 7: /* statement: expression_statement  */
#line 155 "src/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1663 "src/parser.c"
    break;

  case 8: /* statement: if_statement  */
#line 156 "src/parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1669 "src/parser.c"
    break;

  case 9: /* statement: while_statement  */
#line 157 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1675 "src/parser.c"
    break;

  case 10: /* statement: for_statement  */
#line 158 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1681 "src/parser.c"
    break;

  case 11: /* statement: function_declaration  */
#line 159 "src/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1687 "src/parser.c"
    break;

  case 12: /* statement: class_declaration  */
#line 160 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1693 "src/parser.c"
    break;

  case 13: /* statement: return_statement  */
#line 161 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1699 "src/parser.c"
    break;

  case 14: /* statement: break_statement  */
#line 162 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1705 "src/parser.c"
    break;

  case 15: /* statement: continue_statement  */
#line 163 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1711 "src/parser.c"
    break;

  case 16: /* statement: block_statement  */
#line 164 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1717 "src/parser.c"
    break;

  case 17: /* statement: empty_statement  */
#line 165 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1723 "src/parser.c"
    break;

  case 18: /* statement: switch_statement  */
#line 166 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1729 "src/parser.c"
    break;

  case 19: /* statement: try_statement  */
#line 167 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1735 "src/parser.c"
    break;

  case 20: /* class_declaration: CLASS IDENTIFIER class_extends_opt class_body asi_semicolon  */
#line 173 "src/parser.y"
    {
        (yyval.node) = create_class_declaration((yyvsp[-3].str), (yyvsp[-2].node), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1744 "src/parser.c"
    break;

  case 21: /* class_extends_opt: %empty  */
#line 180 "src/parser.y"
                  { (yyval.node) = NULL; }
#line 1750 "src/parser.c"
    break;

  case 22: /* class_extends_opt: EXTENDS IDENTIFIER  */
#line 181 "src/parser.y"
                         { (yyval.node) = create_identifier((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1756 "src/parser.c"
    break;

  case 23: /* class_body: LBRACE class_element_list_opt RBRACE  */
#line 186 "src/parser.y"
    {
        (yyval.node) = create_class_body((yyvsp[-1].class_element_list)->elements, (yyvsp[-1].class_element_list)->element_count);
        free((yyvsp[-1].class_element_list));
    }
#line 1765 "src/parser.c"
    break;

  case 24: /* class_element_list_opt: %empty  */
#line 194 "src/parser.y"
    {
        (yyval.class_element_list) = malloc(sizeof(ClassElementList));
        (yyval.class_element_list)->elements = malloc(sizeof(ASTNode*) * 0);
        (yyval.class_element_list)->element_count = 0;
    }
#line 1775 "src/parser.c"
    break;

  case 25: /* class_element_list_opt: class_element_list  */
#line 200 "src/parser.y"
    {
        (yyval.class_element_list) = (yyvsp[0].class_element_list);
    }
#line 1783 "src/parser.c"
    break;

  case 26: /* class_element_list: class_element  */
#line 207 "src/parser.y"
    {
        (yyval.class_element_list) = malloc(sizeof(ClassElementList));
        (yyval.class_element_list)->elements = malloc(sizeof(ASTNode*) * 1);
        (yyval.class_element_list)->elements[0] = (yyvsp[0].node);
        (yyval.class_element_list)->element_count = 1;
    }
#line 1794 "src/parser.c"
    break;

  case 27: /* class_element_list: class_element_list class_element  */
#line 214 "src/parser.y"
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
#line 1813 "src/parser.c"
    break;

  case 28: /* class_element: static_opt method_definition  */
#line 232 "src/parser.y"
    {
        (yyval.node) = create_class_method((yyvsp[0].method_def)->kind, (yyvsp[0].method_def)->key, (yyvsp[0].method_def)->value, (yyvsp[-1].int_val));
        free((yyvsp[0].method_def)->key);
        free((yyvsp[0].method_def));
    }
#line 1823 "src/parser.c"
    break;

  case 29: /* class_element: static_opt property_definition SEMICOLON  */
#line 238 "src/parser.y"
    {
        (yyval.node) = create_class_property((yyvsp[-1].prop_def)->key, (yyvsp[-1].prop_def)->value, (yyvsp[-2].int_val));
        free((yyvsp[-1].prop_def)->key);
        free((yyvsp[-1].prop_def));
    }
#line 1833 "src/parser.c"
    break;

  case 30: /* static_opt: %empty  */
#line 246 "src/parser.y"
                  { (yyval.int_val) = 0; }
#line 1839 "src/parser.c"
    break;

  case 31: /* static_opt: STATIC  */
#line 247 "src/parser.y"
             { (yyval.int_val) = 1; }
#line 1845 "src/parser.c"
    break;

  case 32: /* method_definition: CONSTRUCTOR LPAREN parameter_list_opt RPAREN block_statement  */
#line 252 "src/parser.y"
    {
        (yyval.method_def) = malloc(sizeof(MethodDefinition));
        (yyval.method_def)->kind = strdup("constructor");
        (yyval.method_def)->key = strdup("constructor");
        (yyval.method_def)->value = create_function_declaration("constructor", (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-2].param_list));
    }
#line 1857 "src/parser.c"
    break;

  case 33: /* method_definition: IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement  */
#line 260 "src/parser.y"
    {
        (yyval.method_def) = malloc(sizeof(MethodDefinition));
        (yyval.method_def)->kind = strdup("method");
        (yyval.method_def)->key = strdup((yyvsp[-4].str));
        (yyval.method_def)->value = create_function_declaration((yyvsp[-4].str), (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-4].str));
        free((yyvsp[-2].param_list));
    }
#line 1870 "src/parser.c"
    break;

  case 34: /* property_definition: IDENTIFIER  */
#line 272 "src/parser.y"
    {
        (yyval.prop_def) = malloc(sizeof(PropertyDefinition));
        (yyval.prop_def)->key = strdup((yyvsp[0].str));
        (yyval.prop_def)->value = NULL;
        free((yyvsp[0].str));
    }
#line 1881 "src/parser.c"
    break;

  case 35: /* property_definition: IDENTIFIER EQUALS expression  */
#line 279 "src/parser.y"
    {
        (yyval.prop_def) = malloc(sizeof(PropertyDefinition));
        (yyval.prop_def)->key = strdup((yyvsp[-2].str));
        (yyval.prop_def)->value = (yyvsp[0].node);
        free((yyvsp[-2].str));
    }
#line 1892 "src/parser.c"
    break;

  case 36: /* variable_declaration: VAR IDENTIFIER optional_initializer asi_semicolon  */
#line 290 "src/parser.y"
    {
        (yyval.node) = create_variable_declaration("var", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1901 "src/parser.c"
    break;

  case 37: /* variable_declaration: LET IDENTIFIER optional_initializer asi_semicolon  */
#line 295 "src/parser.y"
    {
        (yyval.node) = create_variable_declaration("let", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1910 "src/parser.c"
    break;

  case 38: /* variable_declaration: CONST IDENTIFIER optional_initializer asi_semicolon  */
#line 300 "src/parser.y"
    {
        (yyval.node) = create_variable_declaration("const", (yyvsp[-2].str), (yyvsp[-1].node));
        free((yyvsp[-2].str));
    }
#line 1919 "src/parser.c"
    break;

  case 39: /* optional_initializer: %empty  */
#line 307 "src/parser.y"
                  { (yyval.node) = NULL; }
#line 1925 "src/parser.c"
    break;

  case 40: /* optional_initializer: EQUALS expression  */
#line 308 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1931 "src/parser.c"
    break;

  case 41: /* expression_statement: expression asi_semicolon  */
#line 314 "src/parser.y"
    {
        (yyval.node) = create_expression_statement((yyvsp[-1].node));
    }
#line 1939 "src/parser.c"
    break;

  case 42: /* asi_semicolon: SEMICOLON  */
#line 321 "src/parser.y"
                { (yyval.node) = NULL; }
#line 1945 "src/parser.c"
    break;

  case 43: /* asi_semicolon: NEWLINE  */
#line 322 "src/parser.y"
              { (yyval.node) = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); }
#line 1951 "src/parser.c"
    break;

  case 44: /* asi_semicolon: %empty  */
#line 323 "src/parser.y"
                  { (yyval.node) = NULL; printf("PARSER: ASI - Automatically inserted semicolon\n"); }
#line 1957 "src/parser.c"
    break;

  case 45: /* empty_statement: SEMICOLON  */
#line 329 "src/parser.y"
    {
        (yyval.node) = create_empty_statement();
    }
#line 1965 "src/parser.c"
    break;

  case 46: /* block_statement: LBRACE statements RBRACE  */
#line 337 "src/parser.y"
    {
        (yyval.node) = create_block_statement((yyvsp[-1].node)->data.program.statements, (yyvsp[-1].node)->data.program.statement_count);
        free((yyvsp[-1].node));
    }
#line 1974 "src/parser.c"
    break;

  case 47: /* block_statement: LBRACE RBRACE  */
#line 342 "src/parser.y"
    {
        ASTNode** body = malloc(sizeof(ASTNode*) * 0);
        (yyval.node) = create_block_statement(body, 0);
    }
#line 1983 "src/parser.c"
    break;

  case 48: /* if_statement: IF LPAREN expression RPAREN statement  */
#line 351 "src/parser.y"
    {
        (yyval.node) = create_if_statement((yyvsp[-2].node), (yyvsp[0].node), NULL);
    }
#line 1991 "src/parser.c"
    break;

  case 49: /* if_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 355 "src/parser.y"
    {
        (yyval.node) = create_if_statement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1999 "src/parser.c"
    break;

  case 50: /* while_statement: WHILE LPAREN expression RPAREN statement  */
#line 363 "src/parser.y"
    {
        (yyval.node) = create_while_statement((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2007 "src/parser.c"
    break;

  case 51: /* for_statement: FOR LPAREN for_init SEMICOLON for_cond SEMICOLON for_iter RPAREN statement  */
#line 371 "src/parser.y"
    {
        (yyval.node) = create_for_statement((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2015 "src/parser.c"
    break;

  case 52: /* for_init: %empty  */
#line 377 "src/parser.y"
                  { (yyval.node) = NULL; }
#line 2021 "src/parser.c"
    break;

  case 53: /* for_init: variable_declaration_no_semi  */
#line 378 "src/parser.y"
                                   { (yyval.node) = (yyvsp[0].node); }
#line 2027 "src/parser.c"
    break;

  case 54: /* for_init: expression  */
#line 379 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2033 "src/parser.c"
    break;

  case 55: /* for_cond: %empty  */
#line 383 "src/parser.y"
                  { (yyval.node) = NULL; }
#line 2039 "src/parser.c"
    break;

  case 56: /* for_cond: expression  */
#line 384 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2045 "src/parser.c"
    break;

  case 57: /* for_iter: %empty  */
#line 388 "src/parser.y"
                  { (yyval.node) = NULL; }
#line 2051 "src/parser.c"
    break;

  case 58: /* for_iter: expression  */
#line 389 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2057 "src/parser.c"
    break;

  case 59: /* variable_declaration_no_semi: VAR IDENTIFIER optional_initializer  */
#line 394 "src/parser.y"
    {
        (yyval.node) = create_variable_declaration("var", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 2066 "src/parser.c"
    break;

  case 60: /* variable_declaration_no_semi: LET IDENTIFIER optional_initializer  */
#line 399 "src/parser.y"
    {
        (yyval.node) = create_variable_declaration("let", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 2075 "src/parser.c"
    break;

  case 61: /* variable_declaration_no_semi: CONST IDENTIFIER optional_initializer  */
#line 404 "src/parser.y"
    {
        (yyval.node) = create_variable_declaration("const", (yyvsp[-1].str), (yyvsp[0].node));
        free((yyvsp[-1].str));
    }
#line 2084 "src/parser.c"
    break;

  case 62: /* switch_statement: SWITCH LPAREN expression RPAREN block_statement  */
#line 413 "src/parser.y"
    {
        (yyval.node) = create_switch_statement((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2092 "src/parser.c"
    break;

  case 63: /* try_statement: TRY block_statement CATCH LPAREN IDENTIFIER RPAREN block_statement  */
#line 421 "src/parser.y"
    {
        // 简化处理：将 catch 参数忽略，只使用 catch 块
        (yyval.node) = create_try_statement((yyvsp[-5].node), (yyvsp[0].node), NULL);
        free((yyvsp[-2].str));
    }
#line 2102 "src/parser.c"
    break;

  case 64: /* try_statement: TRY block_statement CATCH LPAREN IDENTIFIER RPAREN block_statement FINALLY block_statement  */
#line 427 "src/parser.y"
    {
        (yyval.node) = create_try_statement((yyvsp[-7].node), (yyvsp[-2].node), (yyvsp[0].node));
        free((yyvsp[-4].str));
    }
#line 2111 "src/parser.c"
    break;

  case 65: /* try_statement: TRY block_statement FINALLY block_statement  */
#line 432 "src/parser.y"
    {
        (yyval.node) = create_try_statement((yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 2119 "src/parser.c"
    break;

  case 66: /* function_declaration: FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement  */
#line 440 "src/parser.y"
    {
        (yyval.node) = create_function_declaration((yyvsp[-4].str), (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-4].str));
        free((yyvsp[-2].param_list));
    }
#line 2129 "src/parser.c"
    break;

  case 67: /* parameter_list_opt: %empty  */
#line 449 "src/parser.y"
    {
        (yyval.param_list) = malloc(sizeof(ParamList));
        (yyval.param_list)->parameters = malloc(sizeof(char*) * 0);
        (yyval.param_list)->parameter_count = 0;
    }
#line 2139 "src/parser.c"
    break;

  case 68: /* parameter_list_opt: parameter_list  */
#line 455 "src/parser.y"
    {
        (yyval.param_list) = (yyvsp[0].param_list);
    }
#line 2147 "src/parser.c"
    break;

  case 69: /* parameter_list: IDENTIFIER  */
#line 462 "src/parser.y"
    {
        (yyval.param_list) = malloc(sizeof(ParamList));
        (yyval.param_list)->parameters = malloc(sizeof(char*) * 1);
        (yyval.param_list)->parameters[0] = (yyvsp[0].str);
        (yyval.param_list)->parameter_count = 1;
    }
#line 2158 "src/parser.c"
    break;

  case 70: /* parameter_list: parameter_list COMMA IDENTIFIER  */
#line 469 "src/parser.y"
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
#line 2177 "src/parser.c"
    break;

  case 71: /* return_statement: RETURN expression_opt asi_semicolon  */
#line 488 "src/parser.y"
    {
        (yyval.node) = create_return_statement((yyvsp[-1].node));
    }
#line 2185 "src/parser.c"
    break;

  case 72: /* function_expression: FUNCTION IDENTIFIER LPAREN parameter_list_opt RPAREN block_statement  */
#line 495 "src/parser.y"
    {
        (yyval.node) = create_function_expression((yyvsp[-4].str), (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-4].str));
        free((yyvsp[-2].param_list));
    }
#line 2195 "src/parser.c"
    break;

  case 73: /* function_expression: FUNCTION LPAREN parameter_list_opt RPAREN block_statement  */
#line 501 "src/parser.y"
    {
        (yyval.node) = create_function_expression(NULL, (yyvsp[-2].param_list)->parameters, (yyvsp[-2].param_list)->parameter_count, (yyvsp[0].node));
        free((yyvsp[-2].param_list));
    }
#line 2204 "src/parser.c"
    break;

  case 74: /* break_statement: BREAK asi_semicolon  */
#line 510 "src/parser.y"
    {
        (yyval.node) = create_break_statement();
    }
#line 2212 "src/parser.c"
    break;

  case 75: /* continue_statement: CONTINUE asi_semicolon  */
#line 517 "src/parser.y"
    {
        (yyval.node) = create_continue_statement();
    }
#line 2220 "src/parser.c"
    break;

  case 76: /* expression_opt: %empty  */
#line 523 "src/parser.y"
                  { (yyval.node) = NULL; }
#line 2226 "src/parser.c"
    break;

  case 77: /* expression_opt: expression  */
#line 524 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2232 "src/parser.c"
    break;

  case 78: /* expression: assignment_expression  */
#line 529 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2238 "src/parser.c"
    break;

  case 79: /* assignment_expression: conditional_expression  */
#line 533 "src/parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2244 "src/parser.c"
    break;

  case 80: /* assignment_expression: left_hand_side EQUALS assignment_expression  */
#line 535 "src/parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2252 "src/parser.c"
    break;

  case 81: /* assignment_expression: left_hand_side PLUS_EQ assignment_expression  */
#line 539 "src/parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_ADD_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2260 "src/parser.c"
    break;

  case 82: /* assignment_expression: left_hand_side MINUS_EQ assignment_expression  */
#line 543 "src/parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_SUB_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2268 "src/parser.c"
    break;

  case 83: /* assignment_expression: left_hand_side STAR_EQ assignment_expression  */
#line 547 "src/parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_MUL_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2276 "src/parser.c"
    break;

  case 84: /* assignment_expression: left_hand_side SLASH_EQ assignment_expression  */
#line 551 "src/parser.y"
    {
        (yyval.node) = create_assignment_expression(OP_DIV_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2284 "src/parser.c"
    break;

  case 85: /* left_hand_side: IDENTIFIER  */
#line 558 "src/parser.y"
                 { (yyval.node) = create_identifier((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2290 "src/parser.c"
    break;

  case 86: /* left_hand_side: member_expression  */
#line 559 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2296 "src/parser.c"
    break;

  case 87: /* left_hand_side: call_expression  */
#line 560 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2302 "src/parser.c"
    break;

  case 88: /* left_hand_side: array_literal  */
#line 561 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2308 "src/parser.c"
    break;

  case 89: /* left_hand_side: object_literal  */
#line 562 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2314 "src/parser.c"
    break;

  case 90: /* conditional_expression: logical_or_expression  */
#line 566 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2320 "src/parser.c"
    break;

  case 91: /* conditional_expression: logical_or_expression QUESTION expression COLON conditional_expression  */
#line 568 "src/parser.y"
    {
        (yyval.node) = create_conditional_expression((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2328 "src/parser.c"
    break;

  case 92: /* logical_or_expression: logical_and_expression  */
#line 574 "src/parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2334 "src/parser.c"
    break;

  case 93: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 576 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_OR, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2342 "src/parser.c"
    break;

  case 94: /* logical_and_expression: equality_expression  */
#line 582 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2348 "src/parser.c"
    break;

  case 95: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 584 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_AND, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2356 "src/parser.c"
    break;

  case 96: /* equality_expression: relational_expression  */
#line 590 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2362 "src/parser.c"
    break;

  case 97: /* equality_expression: equality_expression EQ_EQ relational_expression  */
#line 592 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2370 "src/parser.c"
    break;

  case 98: /* equality_expression: equality_expression NOT_EQ relational_expression  */
#line 596 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_NEQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2378 "src/parser.c"
    break;

  case 99: /* equality_expression: equality_expression STRICT_EQ relational_expression  */
#line 600 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_STRICT_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2386 "src/parser.c"
    break;

  case 100: /* equality_expression: equality_expression STRICT_NOT_EQ relational_expression  */
#line 604 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_STRICT_NEQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2394 "src/parser.c"
    break;

  case 101: /* relational_expression: additive_expression  */
#line 610 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2400 "src/parser.c"
    break;

  case 102: /* relational_expression: relational_expression LT additive_expression  */
#line 612 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_LT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2408 "src/parser.c"
    break;

  case 103: /* relational_expression: relational_expression LE additive_expression  */
#line 616 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_LE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2416 "src/parser.c"
    break;

  case 104: /* relational_expression: relational_expression GT additive_expression  */
#line 620 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_GT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2424 "src/parser.c"
    break;

  case 105: /* relational_expression: relational_expression GE additive_expression  */
#line 624 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_GE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2432 "src/parser.c"
    break;

  case 106: /* additive_expression: multiplicative_expression  */
#line 630 "src/parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2438 "src/parser.c"
    break;

  case 107: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 632 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_ADD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2446 "src/parser.c"
    break;

  case 108: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 636 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_SUB, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2454 "src/parser.c"
    break;

  case 109: /* multiplicative_expression: unary_expression  */
#line 642 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2460 "src/parser.c"
    break;

  case 110: /* multiplicative_expression: multiplicative_expression STAR unary_expression  */
#line 644 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_MUL, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2468 "src/parser.c"
    break;

  case 111: /* multiplicative_expression: multiplicative_expression SLASH unary_expression  */
#line 648 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_DIV, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2476 "src/parser.c"
    break;

  case 112: /* multiplicative_expression: multiplicative_expression PERCENT unary_expression  */
#line 652 "src/parser.y"
    {
        (yyval.node) = create_binary_expression(OP_MOD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2484 "src/parser.c"
    break;

  case 113: /* unary_expression: postfix_expression  */
#line 658 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2490 "src/parser.c"
    break;

  case 114: /* unary_expression: PLUS unary_expression  */
#line 660 "src/parser.y"
    {
        (yyval.node) = create_unary_expression(OP_ADD, (yyvsp[0].node));
    }
#line 2498 "src/parser.c"
    break;

  case 115: /* unary_expression: MINUS unary_expression  */
#line 664 "src/parser.y"
    {
        (yyval.node) = create_unary_expression(OP_SUB, (yyvsp[0].node));
    }
#line 2506 "src/parser.c"
    break;

  case 116: /* unary_expression: BANG unary_expression  */
#line 668 "src/parser.y"
    {
        (yyval.node) = create_unary_expression(OP_NOT, (yyvsp[0].node));
    }
#line 2514 "src/parser.c"
    break;

  case 117: /* unary_expression: PLUS_PLUS unary_expression  */
#line 672 "src/parser.y"
    {
        (yyval.node) = create_unary_expression(OP_PRE_INC, (yyvsp[0].node));
    }
#line 2522 "src/parser.c"
    break;

  case 118: /* unary_expression: MINUS_MINUS unary_expression  */
#line 676 "src/parser.y"
    {
        (yyval.node) = create_unary_expression(OP_PRE_DEC, (yyvsp[0].node));
    }
#line 2530 "src/parser.c"
    break;

  case 120: /* postfix_expression: postfix_expression PLUS_PLUS  */
#line 685 "src/parser.y"
    {
        (yyval.node) = create_unary_expression(OP_POST_INC, (yyvsp[-1].node));
    }
#line 2538 "src/parser.c"
    break;

  case 121: /* postfix_expression: postfix_expression MINUS_MINUS  */
#line 689 "src/parser.y"
    {
        (yyval.node) = create_unary_expression(OP_POST_DEC, (yyvsp[-1].node));
    }
#line 2546 "src/parser.c"
    break;

  case 125: /* call_expression: member_expression LPAREN argument_list_opt RPAREN  */
#line 703 "src/parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2555 "src/parser.c"
    break;

  case 126: /* call_expression: call_expression LPAREN argument_list_opt RPAREN  */
#line 708 "src/parser.y"
    {
        (yyval.node) = create_call_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2564 "src/parser.c"
    break;

  case 128: /* member_expression: member_expression DOT IDENTIFIER  */
#line 718 "src/parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-2].node), create_identifier((yyvsp[0].str)), 0);
        free((yyvsp[0].str));
    }
#line 2573 "src/parser.c"
    break;

  case 129: /* member_expression: member_expression LBRACKET expression RBRACKET  */
#line 723 "src/parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-3].node), (yyvsp[-1].node), 1);
    }
#line 2581 "src/parser.c"
    break;

  case 130: /* member_expression: call_expression DOT IDENTIFIER  */
#line 727 "src/parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-2].node), create_identifier((yyvsp[0].str)), 0);
        free((yyvsp[0].str));
    }
#line 2590 "src/parser.c"
    break;

  case 131: /* member_expression: call_expression LBRACKET expression RBRACKET  */
#line 732 "src/parser.y"
    {
        (yyval.node) = create_member_expression((yyvsp[-3].node), (yyvsp[-1].node), 1);
    }
#line 2598 "src/parser.c"
    break;

  case 132: /* new_expression: NEW member_expression LPAREN argument_list_opt RPAREN  */
#line 740 "src/parser.y"
    {
        (yyval.node) = create_new_expression((yyvsp[-3].node), (yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2607 "src/parser.c"
    break;

  case 133: /* new_expression: NEW member_expression  */
#line 745 "src/parser.y"
    {
        (yyval.node) = create_new_expression((yyvsp[0].node), NULL, 0);
    }
#line 2615 "src/parser.c"
    break;

  case 134: /* primary_expression: IDENTIFIER  */
#line 751 "src/parser.y"
                 { (yyval.node) = create_identifier((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2621 "src/parser.c"
    break;

  case 135: /* primary_expression: NUMBER  */
#line 752 "src/parser.y"
             { (yyval.node) = create_number((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2627 "src/parser.c"
    break;

  case 136: /* primary_expression: STRING  */
#line 753 "src/parser.y"
             { (yyval.node) = create_string((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2633 "src/parser.c"
    break;

  case 137: /* primary_expression: TEMPLATE_STRING  */
#line 754 "src/parser.y"
                      { (yyval.node) = create_string((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 2639 "src/parser.c"
    break;

  case 138: /* primary_expression: REGEXP_LITERAL  */
#line 755 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2645 "src/parser.c"
    break;

  case 139: /* primary_expression: TRUE  */
#line 756 "src/parser.y"
           { (yyval.node) = create_boolean(1); }
#line 2651 "src/parser.c"
    break;

  case 140: /* primary_expression: FALSE  */
#line 757 "src/parser.y"
            { (yyval.node) = create_boolean(0); }
#line 2657 "src/parser.c"
    break;

  case 141: /* primary_expression: NULL_LITERAL  */
#line 758 "src/parser.y"
                   { (yyval.node) = create_null(); }
#line 2663 "src/parser.c"
    break;

  case 142: /* primary_expression: UNDEFINED  */
#line 759 "src/parser.y"
                { (yyval.node) = create_undefined(); }
#line 2669 "src/parser.c"
    break;

  case 143: /* primary_expression: THIS  */
#line 760 "src/parser.y"
           { (yyval.node) = create_this_expression(); }
#line 2675 "src/parser.c"
    break;

  case 144: /* primary_expression: SUPER  */
#line 761 "src/parser.y"
            { (yyval.node) = create_super_expression(); }
#line 2681 "src/parser.c"
    break;

  case 145: /* primary_expression: array_literal  */
#line 762 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2687 "src/parser.c"
    break;

  case 146: /* primary_expression: object_literal  */
#line 763 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2693 "src/parser.c"
    break;

  case 147: /* primary_expression: arrow_function  */
#line 764 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2699 "src/parser.c"
    break;

  case 148: /* primary_expression: function_expression  */
#line 765 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2705 "src/parser.c"
    break;

  case 149: /* primary_expression: LPAREN expression RPAREN  */
#line 766 "src/parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 2711 "src/parser.c"
    break;

  case 150: /* argument_list_opt: %empty  */
#line 771 "src/parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 0);
        (yyval.arg_list)->argument_count = 0;
    }
#line 2721 "src/parser.c"
    break;

  case 151: /* argument_list_opt: argument_list  */
#line 777 "src/parser.y"
    {
        (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 2729 "src/parser.c"
    break;

  case 152: /* argument_list: expression  */
#line 784 "src/parser.y"
    {
        ArgList* list = malloc(sizeof(ArgList));
        list->arguments = malloc(sizeof(ASTNode*));
        list->arguments[0] = (yyvsp[0].node);
        list->argument_count = 1;
        (yyval.arg_list) = list;
    }
#line 2741 "src/parser.c"
    break;

  case 153: /* argument_list: argument_list COMMA expression  */
#line 792 "src/parser.y"
    {
        ArgList* list = (yyvsp[-2].arg_list);
        int new_count = list->argument_count + 1;
        ASTNode** new_args = malloc(sizeof(ASTNode*) * new_count);
        
        for (int i = 0; i < list->argument_count; i++) {
            new_args[i] = list->arguments[i];
        }
        
        new_args[list->argument_count] = (yyvsp[0].node);
        
        free(list->arguments);
        list->arguments = new_args;
        list->argument_count = new_count;
        (yyval.arg_list) = list;
    }
#line 2762 "src/parser.c"
    break;

  case 154: /* array_literal: LBRACKET array_element_list_opt RBRACKET  */
#line 813 "src/parser.y"
    {
        (yyval.node) = create_array_literal((yyvsp[-1].arg_list)->arguments, (yyvsp[-1].arg_list)->argument_count);
        free((yyvsp[-1].arg_list));
    }
#line 2771 "src/parser.c"
    break;

  case 155: /* array_element_list_opt: %empty  */
#line 821 "src/parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 0);
        (yyval.arg_list)->argument_count = 0;
    }
#line 2781 "src/parser.c"
    break;

  case 156: /* array_element_list_opt: array_element_list  */
#line 827 "src/parser.y"
    {
        (yyval.arg_list) = (yyvsp[0].arg_list);
    }
#line 2789 "src/parser.c"
    break;

  case 157: /* array_element_list: %empty  */
#line 834 "src/parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 0);  // 改为0个元素
        (yyval.arg_list)->argument_count = 0;
    }
#line 2799 "src/parser.c"
    break;

  case 158: /* array_element_list: expression  */
#line 840 "src/parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 1);
        (yyval.arg_list)->arguments[0] = (yyvsp[0].node);
        (yyval.arg_list)->argument_count = 1;
    }
#line 2810 "src/parser.c"
    break;

  case 159: /* array_element_list: spread_element  */
#line 847 "src/parser.y"
    {
        (yyval.arg_list) = malloc(sizeof(ArgList));
        (yyval.arg_list)->arguments = malloc(sizeof(ASTNode*) * 1);
        (yyval.arg_list)->arguments[0] = (yyvsp[0].node);
        (yyval.arg_list)->argument_count = 1;
    }
#line 2821 "src/parser.c"
    break;

  case 160: /* array_element_list: array_element_list COMMA  */
#line 854 "src/parser.y"
    {
        // 暂时忽略尾部空元素
        (yyval.arg_list) = (yyvsp[-1].arg_list);
    }
#line 2830 "src/parser.c"
    break;

  case 161: /* array_element_list: array_element_list COMMA expression  */
#line 859 "src/parser.y"
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
#line 2849 "src/parser.c"
    break;

  case 162: /* array_element_list: array_element_list COMMA spread_element  */
#line 874 "src/parser.y"
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
#line 2868 "src/parser.c"
    break;

  case 163: /* object_literal: LBRACE property_list_opt RBRACE  */
#line 893 "src/parser.y"
    {
        (yyval.node) = create_object_literal((yyvsp[-1].property_list)->properties, (yyvsp[-1].property_list)->property_count);
        free((yyvsp[-1].property_list));
    }
#line 2877 "src/parser.c"
    break;

  case 164: /* property_list_opt: %empty  */
#line 901 "src/parser.y"
    {
        (yyval.property_list) = malloc(sizeof(PropertyList));
        (yyval.property_list)->properties = malloc(sizeof(ASTNode*) * 0);
        (yyval.property_list)->property_count = 0;
    }
#line 2887 "src/parser.c"
    break;

  case 165: /* property_list_opt: property_list  */
#line 907 "src/parser.y"
    {
        (yyval.property_list) = (yyvsp[0].property_list);
    }
#line 2895 "src/parser.c"
    break;

  case 166: /* property_list: property  */
#line 914 "src/parser.y"
    {
        (yyval.property_list) = malloc(sizeof(PropertyList));
        (yyval.property_list)->properties = malloc(sizeof(ASTNode*) * 1);
        (yyval.property_list)->properties[0] = (yyvsp[0].node);
        (yyval.property_list)->property_count = 1;
    }
#line 2906 "src/parser.c"
    break;

  case 167: /* property_list: property_list COMMA property  */
#line 921 "src/parser.y"
    {
        int old_count = (yyvsp[-2].property_list)->property_count;
        ASTNode** new_props = malloc(sizeof(ASTNode*) * (old_count + 1));
        
        for (int i = 0; i < old_count; i++) {
            new_props[i] = (yyvsp[-2].property_list)->properties[i];
        }
        new_props[old_count] = (yyvsp[0].node);
        
        free((yyvsp[-2].property_list)->properties);
        (yyvsp[-2].property_list)->properties = new_props;
        (yyvsp[-2].property_list)->property_count = old_count + 1;
        (yyval.property_list) = (yyvsp[-2].property_list);
    }
#line 2925 "src/parser.c"
    break;

  case 168: /* property: IDENTIFIER COLON expression  */
#line 939 "src/parser.y"
    {
        (yyval.node) = create_property(create_identifier((yyvsp[-2].str)), (yyvsp[0].node), 0, 0);
        free((yyvsp[-2].str));
    }
#line 2934 "src/parser.c"
    break;

  case 169: /* property: IDENTIFIER  */
#line 944 "src/parser.y"
    {
        (yyval.node) = create_property(create_identifier((yyvsp[0].str)), create_identifier((yyvsp[0].str)), 1, 0);
        free((yyvsp[0].str));
    }
#line 2943 "src/parser.c"
    break;

  case 170: /* property: STRING COLON expression  */
#line 949 "src/parser.y"
    {
        (yyval.node) = create_property(create_string((yyvsp[-2].str)), (yyvsp[0].node), 0, 0);
        free((yyvsp[-2].str));
    }
#line 2952 "src/parser.c"
    break;

  case 171: /* property: LBRACKET expression RBRACKET COLON expression  */
#line 954 "src/parser.y"
    {
        (yyval.node) = create_property((yyvsp[-3].node), (yyvsp[0].node), 0, 1);
    }
#line 2960 "src/parser.c"
    break;

  case 172: /* arrow_function: LPAREN parameter_list_opt RPAREN ARROW expression  */
#line 962 "src/parser.y"
    {
        ASTNode* body = create_expression_statement((yyvsp[0].node));
        (yyval.node) = create_arrow_function((yyvsp[-3].param_list), body);
        free((yyvsp[-3].param_list));
    }
#line 2970 "src/parser.c"
    break;

  case 173: /* arrow_function: LPAREN parameter_list_opt RPAREN ARROW block_statement  */
#line 968 "src/parser.y"
    {
        (yyval.node) = create_arrow_function((yyvsp[-3].param_list), (yyvsp[0].node));
        free((yyvsp[-3].param_list));
    }
#line 2979 "src/parser.c"
    break;

  case 174: /* arrow_function: IDENTIFIER ARROW expression  */
#line 973 "src/parser.y"
    {
        ParamList* param_list = malloc(sizeof(ParamList));
        param_list->parameters = malloc(sizeof(char*) * 1);
        param_list->parameters[0] = strdup((yyvsp[-2].str));
        param_list->parameter_count = 1;
        
        ASTNode* body = create_expression_statement((yyvsp[0].node));
        (yyval.node) = create_arrow_function(param_list, body);
        free((yyvsp[-2].str));
        free(param_list->parameters);
        free(param_list);
    }
#line 2996 "src/parser.c"
    break;

  case 175: /* arrow_function: IDENTIFIER ARROW block_statement  */
#line 986 "src/parser.y"
    {
        ParamList* param_list = malloc(sizeof(ParamList));
        param_list->parameters = malloc(sizeof(char*) * 1);
        param_list->parameters[0] = strdup((yyvsp[-2].str));
        param_list->parameter_count = 1;
        
        (yyval.node) = create_arrow_function(param_list, (yyvsp[0].node));
        free((yyvsp[-2].str));
        free(param_list->parameters);
        free(param_list);
    }
#line 3012 "src/parser.c"
    break;

  case 176: /* spread_element: DOT_DOT_DOT expression  */
#line 1002 "src/parser.y"
    {
        (yyval.node) = create_spread_element((yyvsp[0].node));
    }
#line 3020 "src/parser.c"
    break;


#line 3024 "src/parser.c"

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

#line 1007 "src/parser.y"


void yyerror(ScannerState *scanner, const char *s) {
    (void)scanner;
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
