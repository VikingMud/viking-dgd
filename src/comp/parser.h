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
     STRING = 258,
     NOMASK = 259,
     NIL = 260,
     BREAK = 261,
     ELSE = 262,
     CASE = 263,
     WHILE = 264,
     DEFAULT = 265,
     STATIC = 266,
     CONTINUE = 267,
     INT = 268,
     RLIMITS = 269,
     FLOAT = 270,
     FOR = 271,
     INHERIT = 272,
     VOID = 273,
     IF = 274,
     CATCH = 275,
     SWITCH = 276,
     VARARGS = 277,
     MAPPING = 278,
     PRIVATE = 279,
     DO = 280,
     RETURN = 281,
     ATOMIC = 282,
     MIXED = 283,
     OBJECT = 284,
     LARROW = 285,
     RARROW = 286,
     PLUS_PLUS = 287,
     MIN_MIN = 288,
     LSHIFT = 289,
     RSHIFT = 290,
     LE = 291,
     GE = 292,
     EQ = 293,
     NE = 294,
     LAND = 295,
     LOR = 296,
     PLUS_EQ = 297,
     MIN_EQ = 298,
     MULT_EQ = 299,
     DIV_EQ = 300,
     MOD_EQ = 301,
     LSHIFT_EQ = 302,
     RSHIFT_EQ = 303,
     AND_EQ = 304,
     XOR_EQ = 305,
     OR_EQ = 306,
     COLON_COLON = 307,
     DOT_DOT = 308,
     ELLIPSIS = 309,
     STRING_CONST = 310,
     IDENTIFIER = 311,
     INT_CONST = 312,
     FLOAT_CONST = 313,
     MARK = 314,
     HASH = 315,
     HASH_HASH = 316,
     INCL_CONST = 317,
     NR_TOKENS = 318
   };
#endif
/* Tokens.  */
#define STRING 258
#define NOMASK 259
#define NIL 260
#define BREAK 261
#define ELSE 262
#define CASE 263
#define WHILE 264
#define DEFAULT 265
#define STATIC 266
#define CONTINUE 267
#define INT 268
#define RLIMITS 269
#define FLOAT 270
#define FOR 271
#define INHERIT 272
#define VOID 273
#define IF 274
#define CATCH 275
#define SWITCH 276
#define VARARGS 277
#define MAPPING 278
#define PRIVATE 279
#define DO 280
#define RETURN 281
#define ATOMIC 282
#define MIXED 283
#define OBJECT 284
#define LARROW 285
#define RARROW 286
#define PLUS_PLUS 287
#define MIN_MIN 288
#define LSHIFT 289
#define RSHIFT 290
#define LE 291
#define GE 292
#define EQ 293
#define NE 294
#define LAND 295
#define LOR 296
#define PLUS_EQ 297
#define MIN_EQ 298
#define MULT_EQ 299
#define DIV_EQ 300
#define MOD_EQ 301
#define LSHIFT_EQ 302
#define RSHIFT_EQ 303
#define AND_EQ 304
#define XOR_EQ 305
#define OR_EQ 306
#define COLON_COLON 307
#define DOT_DOT 308
#define ELLIPSIS 309
#define STRING_CONST 310
#define IDENTIFIER 311
#define INT_CONST 312
#define FLOAT_CONST 313
#define MARK 314
#define HASH 315
#define HASH_HASH 316
#define INCL_CONST 317
#define NR_TOKENS 318




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 92 "parser.y"
{
    Int number;			/* lex input */
    xfloat real;		/* lex input */
    unsigned short type;	/* internal */
    struct _node_ *node;	/* internal */
}
/* Line 1489 of yacc.c.  */
#line 182 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

