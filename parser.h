/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    FOR = 261,                     /* FOR  */
    FUNCTION = 262,                /* FUNCTION  */
    VAR = 263,                     /* VAR  */
    LET = 264,                     /* LET  */
    CONST = 265,                   /* CONST  */
    RETURN = 266,                  /* RETURN  */
    BREAK = 267,                   /* BREAK  */
    CONTINUE = 268,                /* CONTINUE  */
    TRUE = 269,                    /* TRUE  */
    FALSE = 270,                   /* FALSE  */
    NULL_LITERAL = 271,            /* NULL_LITERAL  */
    UNDEFINED = 272,               /* UNDEFINED  */
    CLASS = 273,                   /* CLASS  */
    NEW = 274,                     /* NEW  */
    THIS = 275,                    /* THIS  */
    SUPER = 276,                   /* SUPER  */
    STATIC = 277,                  /* STATIC  */
    EXTENDS = 278,                 /* EXTENDS  */
    CONSTRUCTOR = 279,             /* CONSTRUCTOR  */
    NEWLINE = 280,                 /* NEWLINE  */
    IDENTIFIER = 281,              /* IDENTIFIER  */
    NUMBER = 282,                  /* NUMBER  */
    STRING = 283,                  /* STRING  */
    PLUS = 284,                    /* PLUS  */
    MINUS = 285,                   /* MINUS  */
    STAR = 286,                    /* STAR  */
    SLASH = 287,                   /* SLASH  */
    PERCENT = 288,                 /* PERCENT  */
    EQUALS = 289,                  /* EQUALS  */
    EQ_EQ = 290,                   /* EQ_EQ  */
    NOT_EQ = 291,                  /* NOT_EQ  */
    STRICT_EQ = 292,               /* STRICT_EQ  */
    STRICT_NOT_EQ = 293,           /* STRICT_NOT_EQ  */
    LT = 294,                      /* LT  */
    LE = 295,                      /* LE  */
    GT = 296,                      /* GT  */
    GE = 297,                      /* GE  */
    BANG = 298,                    /* BANG  */
    AND = 299,                     /* AND  */
    OR = 300,                      /* OR  */
    PLUS_PLUS = 301,               /* PLUS_PLUS  */
    MINUS_MINUS = 302,             /* MINUS_MINUS  */
    PLUS_EQ = 303,                 /* PLUS_EQ  */
    MINUS_EQ = 304,                /* MINUS_EQ  */
    STAR_EQ = 305,                 /* STAR_EQ  */
    SLASH_EQ = 306,                /* SLASH_EQ  */
    LPAREN = 307,                  /* LPAREN  */
    RPAREN = 308,                  /* RPAREN  */
    LBRACE = 309,                  /* LBRACE  */
    RBRACE = 310,                  /* RBRACE  */
    LBRACKET = 311,                /* LBRACKET  */
    RBRACKET = 312,                /* RBRACKET  */
    SEMICOLON = 313,               /* SEMICOLON  */
    COMMA = 314,                   /* COMMA  */
    DOT = 315,                     /* DOT  */
    COLON = 316,                   /* COLON  */
    QUESTION = 317,                /* QUESTION  */
    DOT_DOT_DOT = 318,             /* DOT_DOT_DOT  */
    ARROW = 319,                   /* ARROW  */
    TEMPLATE_STRING = 320,         /* TEMPLATE_STRING  */
    REGEXP_LITERAL = 321,          /* REGEXP_LITERAL  */
    SWITCH = 322,                  /* SWITCH  */
    CASE = 323,                    /* CASE  */
    DEFAULT = 324,                 /* DEFAULT  */
    TRY = 325,                     /* TRY  */
    CATCH = 326,                   /* CATCH  */
    FINALLY = 327,                 /* FINALLY  */
    ERROR = 328,                   /* ERROR  */
    POSTFIX = 329,                 /* POSTFIX  */
    ASSIGNMENT = 330,              /* ASSIGNMENT  */
    BITWISE_OR = 331,              /* BITWISE_OR  */
    BITWISE_XOR = 332,             /* BITWISE_XOR  */
    BITWISE_AND = 333,             /* BITWISE_AND  */
    EQUALITY = 334,                /* EQUALITY  */
    RELATIONAL = 335,              /* RELATIONAL  */
    SHIFT = 336,                   /* SHIFT  */
    ADDITIVE = 337,                /* ADDITIVE  */
    MULTIPLICATIVE = 338,          /* MULTIPLICATIVE  */
    EXPONENTIAL = 339,             /* EXPONENTIAL  */
    UNARY = 340,                   /* UNARY  */
    CALL = 341,                    /* CALL  */
    PRE_INC = 342,                 /* PRE_INC  */
    PRE_DEC = 343,                 /* PRE_DEC  */
    POST_INC = 344,                /* POST_INC  */
    POST_DEC = 345                 /* POST_DEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "src/parser.y"

    char* str;
    ASTNode* node;
    int int_val;
    ArgList* arg_list;
    ParamList* param_list;
    ClassElementList* class_element_list;
    MethodDefinition* method_def;
    PropertyDefinition* prop_def;
    PropertyList* property_list;

#line 166 "src/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (ScannerState *scanner);


#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */
