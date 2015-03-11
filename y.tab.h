/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PLUS = 258,
     SUB = 259,
     MULT = 260,
     DIV = 261,
     MOD = 262,
     EQUAL = 263,
     PROGRAM = 264,
     BEGIN_PROGRAM = 265,
     END_PROGRAM = 266,
     INTEGER = 267,
     ARRAY = 268,
     OF = 269,
     IF = 270,
     THEN = 271,
     ENDIF = 272,
     ELSE = 273,
     ELSEIF = 274,
     WHILE = 275,
     DO = 276,
     BEGINLOOP = 277,
     ENDLOOP = 278,
     BREAK = 279,
     CONTINUE = 280,
     EXIT = 281,
     READ = 282,
     WRITE = 283,
     AND = 284,
     OR = 285,
     NOT = 286,
     TRUE = 287,
     FALSE = 288,
     EQ = 289,
     NEQ = 290,
     LT = 291,
     GT = 292,
     LTE = 293,
     GTE = 294,
     SEMICOLON = 295,
     COLON = 296,
     COMMA = 297,
     QUESTION = 298,
     L_BRACKET = 299,
     R_BRACKET = 300,
     L_PAREN = 301,
     R_PAREN = 302,
     ASSIGN = 303,
     IDENT = 304,
     NUMBER = 305,
     COMMENT = 306,
     NEG = 307
   };
#endif
/* Tokens.  */
#define PLUS 258
#define SUB 259
#define MULT 260
#define DIV 261
#define MOD 262
#define EQUAL 263
#define PROGRAM 264
#define BEGIN_PROGRAM 265
#define END_PROGRAM 266
#define INTEGER 267
#define ARRAY 268
#define OF 269
#define IF 270
#define THEN 271
#define ENDIF 272
#define ELSE 273
#define ELSEIF 274
#define WHILE 275
#define DO 276
#define BEGINLOOP 277
#define ENDLOOP 278
#define BREAK 279
#define CONTINUE 280
#define EXIT 281
#define READ 282
#define WRITE 283
#define AND 284
#define OR 285
#define NOT 286
#define TRUE 287
#define FALSE 288
#define EQ 289
#define NEQ 290
#define LT 291
#define GT 292
#define LTE 293
#define GTE 294
#define SEMICOLON 295
#define COLON 296
#define COMMA 297
#define QUESTION 298
#define L_BRACKET 299
#define R_BRACKET 300
#define L_PAREN 301
#define R_PAREN 302
#define ASSIGN 303
#define IDENT 304
#define NUMBER 305
#define COMMENT 306
#define NEG 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 49 "mini_l.y"
{
    char* IntString;
    char* String;
    
    // struct attribute was here
    struct attribute
	{
		//char* name;
		char name [255];
		int type;
		char* size;
		char* code;
	};

    
    struct attribute myAttri; 
}
/* Line 1529 of yacc.c.  */
#line 171 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

