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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    NEWLINE = 273,                 /* NEWLINE  */
    IDENTIFIER = 274,              /* IDENTIFIER  */
    NUMBER = 275,                  /* NUMBER  */
    STRING = 276,                  /* STRING  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    STAR = 279,                    /* STAR  */
    SLASH = 280,                   /* SLASH  */
    PERCENT = 281,                 /* PERCENT  */
    EQUALS = 282,                  /* EQUALS  */
    EQ_EQ = 283,                   /* EQ_EQ  */
    NOT_EQ = 284,                  /* NOT_EQ  */
    STRICT_EQ = 285,               /* STRICT_EQ  */
    STRICT_NOT_EQ = 286,           /* STRICT_NOT_EQ  */
    LT = 287,                      /* LT  */
    LE = 288,                      /* LE  */
    GT = 289,                      /* GT  */
    GE = 290,                      /* GE  */
    BANG = 291,                    /* BANG  */
    AND = 292,                     /* AND  */
    OR = 293,                      /* OR  */
    PLUS_PLUS = 294,               /* PLUS_PLUS  */
    MINUS_MINUS = 295,             /* MINUS_MINUS  */
    PLUS_EQ = 296,                 /* PLUS_EQ  */
    MINUS_EQ = 297,                /* MINUS_EQ  */
    STAR_EQ = 298,                 /* STAR_EQ  */
    SLASH_EQ = 299,                /* SLASH_EQ  */
    LPAREN = 300,                  /* LPAREN  */
    RPAREN = 301,                  /* RPAREN  */
    LBRACE = 302,                  /* LBRACE  */
    RBRACE = 303,                  /* RBRACE  */
    LBRACKET = 304,                /* LBRACKET  */
    RBRACKET = 305,                /* RBRACKET  */
    SEMICOLON = 306,               /* SEMICOLON  */
    COMMA = 307,                   /* COMMA  */
    DOT = 308,                     /* DOT  */
    COLON = 309,                   /* COLON  */
    QUESTION = 310,                /* QUESTION  */
    ERROR = 311,                   /* ERROR  */
    POSTFIX = 312                  /* POSTFIX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
