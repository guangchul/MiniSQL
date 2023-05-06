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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../parse/bison.y"

#include <stdio.h>
#include <string.h>
#include "../node/parseNodes.h"
#include "ptype.h"
void yyerror(yyscan_t yyscanner, char *str);
int flexable(int type);
int calcLength(int type, int length);
char* fnc_itoa(int number);
typedef union YYSTYPE YYSTYPE;
extern int yylex (YYSTYPE * yylval_param , yyscan_t yyscanner);

#line 84 "../parse/bison.c"

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

#include "bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_FCONST = 4,                     /* FCONST  */
  YYSYMBOL_SCONST = 5,                     /* SCONST  */
  YYSYMBOL_BCONST = 6,                     /* BCONST  */
  YYSYMBOL_XCONST = 7,                     /* XCONST  */
  YYSYMBOL_Op = 8,                         /* Op  */
  YYSYMBOL_ICONST = 9,                     /* ICONST  */
  YYSYMBOL_PARAM = 10,                     /* PARAM  */
  YYSYMBOL_TYPECAST = 11,                  /* TYPECAST  */
  YYSYMBOL_DOT_DOT = 12,                   /* DOT_DOT  */
  YYSYMBOL_COLON_EQUALS = 13,              /* COLON_EQUALS  */
  YYSYMBOL_EQUALS_GREATER = 14,            /* EQUALS_GREATER  */
  YYSYMBOL_LESS_EQUALS = 15,               /* LESS_EQUALS  */
  YYSYMBOL_GREATER_EQUALS = 16,            /* GREATER_EQUALS  */
  YYSYMBOL_NOT_EQUALS = 17,                /* NOT_EQUALS  */
  YYSYMBOL_ABORT_P = 18,                   /* ABORT_P  */
  YYSYMBOL_ABSOLUTE_P = 19,                /* ABSOLUTE_P  */
  YYSYMBOL_ACCESS = 20,                    /* ACCESS  */
  YYSYMBOL_ACTION = 21,                    /* ACTION  */
  YYSYMBOL_ADD_P = 22,                     /* ADD_P  */
  YYSYMBOL_ADMIN = 23,                     /* ADMIN  */
  YYSYMBOL_AFTER = 24,                     /* AFTER  */
  YYSYMBOL_AGGREGATE = 25,                 /* AGGREGATE  */
  YYSYMBOL_ALL = 26,                       /* ALL  */
  YYSYMBOL_ALSO = 27,                      /* ALSO  */
  YYSYMBOL_ALTER = 28,                     /* ALTER  */
  YYSYMBOL_ALWAYS = 29,                    /* ALWAYS  */
  YYSYMBOL_ANALYSE = 30,                   /* ANALYSE  */
  YYSYMBOL_ANALYZE = 31,                   /* ANALYZE  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_ANY = 33,                       /* ANY  */
  YYSYMBOL_ARRAY = 34,                     /* ARRAY  */
  YYSYMBOL_AS = 35,                        /* AS  */
  YYSYMBOL_ASC = 36,                       /* ASC  */
  YYSYMBOL_ASSERTION = 37,                 /* ASSERTION  */
  YYSYMBOL_ASSIGNMENT = 38,                /* ASSIGNMENT  */
  YYSYMBOL_ASYMMETRIC = 39,                /* ASYMMETRIC  */
  YYSYMBOL_AT = 40,                        /* AT  */
  YYSYMBOL_ATTACH = 41,                    /* ATTACH  */
  YYSYMBOL_ATTRIBUTE = 42,                 /* ATTRIBUTE  */
  YYSYMBOL_AUTHORIZATION = 43,             /* AUTHORIZATION  */
  YYSYMBOL_BACKWARD = 44,                  /* BACKWARD  */
  YYSYMBOL_BEFORE = 45,                    /* BEFORE  */
  YYSYMBOL_BEGIN_P = 46,                   /* BEGIN_P  */
  YYSYMBOL_BETWEEN = 47,                   /* BETWEEN  */
  YYSYMBOL_BIGINT = 48,                    /* BIGINT  */
  YYSYMBOL_BINARY = 49,                    /* BINARY  */
  YYSYMBOL_BIT = 50,                       /* BIT  */
  YYSYMBOL_BOOLEAN_P = 51,                 /* BOOLEAN_P  */
  YYSYMBOL_BOTH = 52,                      /* BOTH  */
  YYSYMBOL_BY = 53,                        /* BY  */
  YYSYMBOL_CACHE = 54,                     /* CACHE  */
  YYSYMBOL_CALL = 55,                      /* CALL  */
  YYSYMBOL_CALLED = 56,                    /* CALLED  */
  YYSYMBOL_CASCADE = 57,                   /* CASCADE  */
  YYSYMBOL_CASCADED = 58,                  /* CASCADED  */
  YYSYMBOL_CASE = 59,                      /* CASE  */
  YYSYMBOL_CAST = 60,                      /* CAST  */
  YYSYMBOL_CATALOG_P = 61,                 /* CATALOG_P  */
  YYSYMBOL_CHAIN = 62,                     /* CHAIN  */
  YYSYMBOL_CHAR_P = 63,                    /* CHAR_P  */
  YYSYMBOL_CHARACTER = 64,                 /* CHARACTER  */
  YYSYMBOL_CHARACTERISTICS = 65,           /* CHARACTERISTICS  */
  YYSYMBOL_CHECK = 66,                     /* CHECK  */
  YYSYMBOL_CHECKPOINT = 67,                /* CHECKPOINT  */
  YYSYMBOL_CLASS = 68,                     /* CLASS  */
  YYSYMBOL_CLOSE = 69,                     /* CLOSE  */
  YYSYMBOL_CLUSTER = 70,                   /* CLUSTER  */
  YYSYMBOL_COALESCE = 71,                  /* COALESCE  */
  YYSYMBOL_COLLATE = 72,                   /* COLLATE  */
  YYSYMBOL_COLLATION = 73,                 /* COLLATION  */
  YYSYMBOL_COLUMN = 74,                    /* COLUMN  */
  YYSYMBOL_COLUMNS = 75,                   /* COLUMNS  */
  YYSYMBOL_COMMENT = 76,                   /* COMMENT  */
  YYSYMBOL_COMMENTS = 77,                  /* COMMENTS  */
  YYSYMBOL_COMMIT = 78,                    /* COMMIT  */
  YYSYMBOL_COMMITTED = 79,                 /* COMMITTED  */
  YYSYMBOL_CONCURRENTLY = 80,              /* CONCURRENTLY  */
  YYSYMBOL_CONFIGURATION = 81,             /* CONFIGURATION  */
  YYSYMBOL_CONFLICT = 82,                  /* CONFLICT  */
  YYSYMBOL_CONNECTION = 83,                /* CONNECTION  */
  YYSYMBOL_CONSTRAINT = 84,                /* CONSTRAINT  */
  YYSYMBOL_CONSTRAINTS = 85,               /* CONSTRAINTS  */
  YYSYMBOL_CONTENT_P = 86,                 /* CONTENT_P  */
  YYSYMBOL_CONTINUE_P = 87,                /* CONTINUE_P  */
  YYSYMBOL_CONVERSION_P = 88,              /* CONVERSION_P  */
  YYSYMBOL_COPY = 89,                      /* COPY  */
  YYSYMBOL_COST = 90,                      /* COST  */
  YYSYMBOL_CREATE = 91,                    /* CREATE  */
  YYSYMBOL_CROSS = 92,                     /* CROSS  */
  YYSYMBOL_CSV = 93,                       /* CSV  */
  YYSYMBOL_CUBE = 94,                      /* CUBE  */
  YYSYMBOL_CURRENT_P = 95,                 /* CURRENT_P  */
  YYSYMBOL_CURRENT_CATALOG = 96,           /* CURRENT_CATALOG  */
  YYSYMBOL_CURRENT_DATE = 97,              /* CURRENT_DATE  */
  YYSYMBOL_CURRENT_ROLE = 98,              /* CURRENT_ROLE  */
  YYSYMBOL_CURRENT_SCHEMA = 99,            /* CURRENT_SCHEMA  */
  YYSYMBOL_CURRENT_TIME = 100,             /* CURRENT_TIME  */
  YYSYMBOL_CURRENT_TIMESTAMP = 101,        /* CURRENT_TIMESTAMP  */
  YYSYMBOL_CURRENT_USER = 102,             /* CURRENT_USER  */
  YYSYMBOL_CURSOR = 103,                   /* CURSOR  */
  YYSYMBOL_CYCLE = 104,                    /* CYCLE  */
  YYSYMBOL_DATA_P = 105,                   /* DATA_P  */
  YYSYMBOL_DATABASE = 106,                 /* DATABASE  */
  YYSYMBOL_DAY_P = 107,                    /* DAY_P  */
  YYSYMBOL_DEALLOCATE = 108,               /* DEALLOCATE  */
  YYSYMBOL_DEC = 109,                      /* DEC  */
  YYSYMBOL_DECIMAL_P = 110,                /* DECIMAL_P  */
  YYSYMBOL_DECLARE = 111,                  /* DECLARE  */
  YYSYMBOL_DEFAULT = 112,                  /* DEFAULT  */
  YYSYMBOL_DEFAULTS = 113,                 /* DEFAULTS  */
  YYSYMBOL_DEFERRABLE = 114,               /* DEFERRABLE  */
  YYSYMBOL_DEFERRED = 115,                 /* DEFERRED  */
  YYSYMBOL_DEFINER = 116,                  /* DEFINER  */
  YYSYMBOL_DELETE_P = 117,                 /* DELETE_P  */
  YYSYMBOL_DELIMITER = 118,                /* DELIMITER  */
  YYSYMBOL_DELIMITERS = 119,               /* DELIMITERS  */
  YYSYMBOL_DEPENDS = 120,                  /* DEPENDS  */
  YYSYMBOL_DESC = 121,                     /* DESC  */
  YYSYMBOL_DETACH = 122,                   /* DETACH  */
  YYSYMBOL_DICTIONARY = 123,               /* DICTIONARY  */
  YYSYMBOL_DISABLE_P = 124,                /* DISABLE_P  */
  YYSYMBOL_DISCARD = 125,                  /* DISCARD  */
  YYSYMBOL_DISTINCT = 126,                 /* DISTINCT  */
  YYSYMBOL_DO = 127,                       /* DO  */
  YYSYMBOL_DOCUMENT_P = 128,               /* DOCUMENT_P  */
  YYSYMBOL_DOMAIN_P = 129,                 /* DOMAIN_P  */
  YYSYMBOL_DOUBLE_P = 130,                 /* DOUBLE_P  */
  YYSYMBOL_DROP = 131,                     /* DROP  */
  YYSYMBOL_EACH = 132,                     /* EACH  */
  YYSYMBOL_ELSE = 133,                     /* ELSE  */
  YYSYMBOL_ENABLE_P = 134,                 /* ENABLE_P  */
  YYSYMBOL_ENCODING = 135,                 /* ENCODING  */
  YYSYMBOL_ENCRYPTED = 136,                /* ENCRYPTED  */
  YYSYMBOL_END_P = 137,                    /* END_P  */
  YYSYMBOL_ENUM_P = 138,                   /* ENUM_P  */
  YYSYMBOL_ESCAPE = 139,                   /* ESCAPE  */
  YYSYMBOL_EVENT = 140,                    /* EVENT  */
  YYSYMBOL_EXCEPT = 141,                   /* EXCEPT  */
  YYSYMBOL_EXCLUDE = 142,                  /* EXCLUDE  */
  YYSYMBOL_EXCLUDING = 143,                /* EXCLUDING  */
  YYSYMBOL_EXCLUSIVE = 144,                /* EXCLUSIVE  */
  YYSYMBOL_EXECUTE = 145,                  /* EXECUTE  */
  YYSYMBOL_EXISTS = 146,                   /* EXISTS  */
  YYSYMBOL_EXPLAIN = 147,                  /* EXPLAIN  */
  YYSYMBOL_EXTENSION = 148,                /* EXTENSION  */
  YYSYMBOL_EXTERNAL = 149,                 /* EXTERNAL  */
  YYSYMBOL_EXTRACT = 150,                  /* EXTRACT  */
  YYSYMBOL_FALSE_P = 151,                  /* FALSE_P  */
  YYSYMBOL_FAMILY = 152,                   /* FAMILY  */
  YYSYMBOL_FETCH = 153,                    /* FETCH  */
  YYSYMBOL_FILTER = 154,                   /* FILTER  */
  YYSYMBOL_FIRST_P = 155,                  /* FIRST_P  */
  YYSYMBOL_FLOAT_P = 156,                  /* FLOAT_P  */
  YYSYMBOL_FOLLOWING = 157,                /* FOLLOWING  */
  YYSYMBOL_FOR = 158,                      /* FOR  */
  YYSYMBOL_FORCE = 159,                    /* FORCE  */
  YYSYMBOL_FOREIGN = 160,                  /* FOREIGN  */
  YYSYMBOL_FORWARD = 161,                  /* FORWARD  */
  YYSYMBOL_FREEZE = 162,                   /* FREEZE  */
  YYSYMBOL_FROM = 163,                     /* FROM  */
  YYSYMBOL_FULL = 164,                     /* FULL  */
  YYSYMBOL_FUNCTION = 165,                 /* FUNCTION  */
  YYSYMBOL_FUNCTIONS = 166,                /* FUNCTIONS  */
  YYSYMBOL_GENERATED = 167,                /* GENERATED  */
  YYSYMBOL_GLOBAL = 168,                   /* GLOBAL  */
  YYSYMBOL_GRANT = 169,                    /* GRANT  */
  YYSYMBOL_GRANTED = 170,                  /* GRANTED  */
  YYSYMBOL_GREATEST = 171,                 /* GREATEST  */
  YYSYMBOL_GROUP_P = 172,                  /* GROUP_P  */
  YYSYMBOL_GROUPING = 173,                 /* GROUPING  */
  YYSYMBOL_GROUPS = 174,                   /* GROUPS  */
  YYSYMBOL_HANDLER = 175,                  /* HANDLER  */
  YYSYMBOL_HAVING = 176,                   /* HAVING  */
  YYSYMBOL_HEADER_P = 177,                 /* HEADER_P  */
  YYSYMBOL_HOLD = 178,                     /* HOLD  */
  YYSYMBOL_HOUR_P = 179,                   /* HOUR_P  */
  YYSYMBOL_IDENTITY_P = 180,               /* IDENTITY_P  */
  YYSYMBOL_IF_P = 181,                     /* IF_P  */
  YYSYMBOL_ILIKE = 182,                    /* ILIKE  */
  YYSYMBOL_IMMEDIATE = 183,                /* IMMEDIATE  */
  YYSYMBOL_IMMUTABLE = 184,                /* IMMUTABLE  */
  YYSYMBOL_IMPLICIT_P = 185,               /* IMPLICIT_P  */
  YYSYMBOL_IMPORT_P = 186,                 /* IMPORT_P  */
  YYSYMBOL_IN_P = 187,                     /* IN_P  */
  YYSYMBOL_INCLUDE = 188,                  /* INCLUDE  */
  YYSYMBOL_INCLUDING = 189,                /* INCLUDING  */
  YYSYMBOL_INCREMENT = 190,                /* INCREMENT  */
  YYSYMBOL_INDEX = 191,                    /* INDEX  */
  YYSYMBOL_INDEXES = 192,                  /* INDEXES  */
  YYSYMBOL_INHERIT = 193,                  /* INHERIT  */
  YYSYMBOL_INHERITS = 194,                 /* INHERITS  */
  YYSYMBOL_INITIALLY = 195,                /* INITIALLY  */
  YYSYMBOL_INLINE_P = 196,                 /* INLINE_P  */
  YYSYMBOL_INNER_P = 197,                  /* INNER_P  */
  YYSYMBOL_INOUT = 198,                    /* INOUT  */
  YYSYMBOL_INPUT_P = 199,                  /* INPUT_P  */
  YYSYMBOL_INSENSITIVE = 200,              /* INSENSITIVE  */
  YYSYMBOL_INSERT = 201,                   /* INSERT  */
  YYSYMBOL_INSTEAD = 202,                  /* INSTEAD  */
  YYSYMBOL_INT_P = 203,                    /* INT_P  */
  YYSYMBOL_INTEGER = 204,                  /* INTEGER  */
  YYSYMBOL_INTERSECT = 205,                /* INTERSECT  */
  YYSYMBOL_INTERVAL = 206,                 /* INTERVAL  */
  YYSYMBOL_INTO = 207,                     /* INTO  */
  YYSYMBOL_INVOKER = 208,                  /* INVOKER  */
  YYSYMBOL_IS = 209,                       /* IS  */
  YYSYMBOL_ISNULL = 210,                   /* ISNULL  */
  YYSYMBOL_ISOLATION = 211,                /* ISOLATION  */
  YYSYMBOL_JOIN = 212,                     /* JOIN  */
  YYSYMBOL_KEY = 213,                      /* KEY  */
  YYSYMBOL_LABEL = 214,                    /* LABEL  */
  YYSYMBOL_LANGUAGE = 215,                 /* LANGUAGE  */
  YYSYMBOL_LARGE_P = 216,                  /* LARGE_P  */
  YYSYMBOL_LAST_P = 217,                   /* LAST_P  */
  YYSYMBOL_LATERAL_P = 218,                /* LATERAL_P  */
  YYSYMBOL_LEADING = 219,                  /* LEADING  */
  YYSYMBOL_LEAKPROOF = 220,                /* LEAKPROOF  */
  YYSYMBOL_LEAST = 221,                    /* LEAST  */
  YYSYMBOL_LEFT = 222,                     /* LEFT  */
  YYSYMBOL_LEVEL = 223,                    /* LEVEL  */
  YYSYMBOL_LIKE = 224,                     /* LIKE  */
  YYSYMBOL_LIMIT = 225,                    /* LIMIT  */
  YYSYMBOL_LISTEN = 226,                   /* LISTEN  */
  YYSYMBOL_LOAD = 227,                     /* LOAD  */
  YYSYMBOL_LOCAL = 228,                    /* LOCAL  */
  YYSYMBOL_LOCALTIME = 229,                /* LOCALTIME  */
  YYSYMBOL_LOCALTIMESTAMP = 230,           /* LOCALTIMESTAMP  */
  YYSYMBOL_LOCATION = 231,                 /* LOCATION  */
  YYSYMBOL_LOCK_P = 232,                   /* LOCK_P  */
  YYSYMBOL_LOCKED = 233,                   /* LOCKED  */
  YYSYMBOL_LOGGED = 234,                   /* LOGGED  */
  YYSYMBOL_MAPPING = 235,                  /* MAPPING  */
  YYSYMBOL_MATCH = 236,                    /* MATCH  */
  YYSYMBOL_MATERIALIZED = 237,             /* MATERIALIZED  */
  YYSYMBOL_MAXVALUE = 238,                 /* MAXVALUE  */
  YYSYMBOL_METHOD = 239,                   /* METHOD  */
  YYSYMBOL_MINUTE_P = 240,                 /* MINUTE_P  */
  YYSYMBOL_MINVALUE = 241,                 /* MINVALUE  */
  YYSYMBOL_MODE = 242,                     /* MODE  */
  YYSYMBOL_MONTH_P = 243,                  /* MONTH_P  */
  YYSYMBOL_MOVE = 244,                     /* MOVE  */
  YYSYMBOL_NAME_P = 245,                   /* NAME_P  */
  YYSYMBOL_NAMES = 246,                    /* NAMES  */
  YYSYMBOL_NATIONAL = 247,                 /* NATIONAL  */
  YYSYMBOL_NATURAL = 248,                  /* NATURAL  */
  YYSYMBOL_NCHAR = 249,                    /* NCHAR  */
  YYSYMBOL_NEW = 250,                      /* NEW  */
  YYSYMBOL_NEXT = 251,                     /* NEXT  */
  YYSYMBOL_NO = 252,                       /* NO  */
  YYSYMBOL_NONE = 253,                     /* NONE  */
  YYSYMBOL_NOT = 254,                      /* NOT  */
  YYSYMBOL_NOTHING = 255,                  /* NOTHING  */
  YYSYMBOL_NOTIFY = 256,                   /* NOTIFY  */
  YYSYMBOL_NOTNULL = 257,                  /* NOTNULL  */
  YYSYMBOL_NOWAIT = 258,                   /* NOWAIT  */
  YYSYMBOL_NULL_P = 259,                   /* NULL_P  */
  YYSYMBOL_NULLIF = 260,                   /* NULLIF  */
  YYSYMBOL_NULLS_P = 261,                  /* NULLS_P  */
  YYSYMBOL_NUMERIC = 262,                  /* NUMERIC  */
  YYSYMBOL_OBJECT_P = 263,                 /* OBJECT_P  */
  YYSYMBOL_OF = 264,                       /* OF  */
  YYSYMBOL_OFF = 265,                      /* OFF  */
  YYSYMBOL_OFFSET = 266,                   /* OFFSET  */
  YYSYMBOL_OIDS = 267,                     /* OIDS  */
  YYSYMBOL_OLD = 268,                      /* OLD  */
  YYSYMBOL_ON = 269,                       /* ON  */
  YYSYMBOL_ONLY = 270,                     /* ONLY  */
  YYSYMBOL_OPERATOR = 271,                 /* OPERATOR  */
  YYSYMBOL_OPTION = 272,                   /* OPTION  */
  YYSYMBOL_OPTIONS = 273,                  /* OPTIONS  */
  YYSYMBOL_OR = 274,                       /* OR  */
  YYSYMBOL_ORDER = 275,                    /* ORDER  */
  YYSYMBOL_ORDINALITY = 276,               /* ORDINALITY  */
  YYSYMBOL_OTHERS = 277,                   /* OTHERS  */
  YYSYMBOL_OUT_P = 278,                    /* OUT_P  */
  YYSYMBOL_OUTER_P = 279,                  /* OUTER_P  */
  YYSYMBOL_OVER = 280,                     /* OVER  */
  YYSYMBOL_OVERLAPS = 281,                 /* OVERLAPS  */
  YYSYMBOL_OVERLAY = 282,                  /* OVERLAY  */
  YYSYMBOL_OVERRIDING = 283,               /* OVERRIDING  */
  YYSYMBOL_OWNED = 284,                    /* OWNED  */
  YYSYMBOL_OWNER = 285,                    /* OWNER  */
  YYSYMBOL_PARALLEL = 286,                 /* PARALLEL  */
  YYSYMBOL_PARSER = 287,                   /* PARSER  */
  YYSYMBOL_PARTIAL = 288,                  /* PARTIAL  */
  YYSYMBOL_PARTITION = 289,                /* PARTITION  */
  YYSYMBOL_PASSING = 290,                  /* PASSING  */
  YYSYMBOL_PASSWORD = 291,                 /* PASSWORD  */
  YYSYMBOL_PLACING = 292,                  /* PLACING  */
  YYSYMBOL_PLANS = 293,                    /* PLANS  */
  YYSYMBOL_POLICY = 294,                   /* POLICY  */
  YYSYMBOL_POSITION = 295,                 /* POSITION  */
  YYSYMBOL_PRECEDING = 296,                /* PRECEDING  */
  YYSYMBOL_PRECISION = 297,                /* PRECISION  */
  YYSYMBOL_PRESERVE = 298,                 /* PRESERVE  */
  YYSYMBOL_PREPARE = 299,                  /* PREPARE  */
  YYSYMBOL_PREPARED = 300,                 /* PREPARED  */
  YYSYMBOL_PRIMARY = 301,                  /* PRIMARY  */
  YYSYMBOL_PRIOR = 302,                    /* PRIOR  */
  YYSYMBOL_PRIVILEGES = 303,               /* PRIVILEGES  */
  YYSYMBOL_PROCEDURAL = 304,               /* PROCEDURAL  */
  YYSYMBOL_PROCEDURE = 305,                /* PROCEDURE  */
  YYSYMBOL_PROCEDURES = 306,               /* PROCEDURES  */
  YYSYMBOL_PROGRAM = 307,                  /* PROGRAM  */
  YYSYMBOL_PUBLICATION = 308,              /* PUBLICATION  */
  YYSYMBOL_QUOTE = 309,                    /* QUOTE  */
  YYSYMBOL_RANGE = 310,                    /* RANGE  */
  YYSYMBOL_READ = 311,                     /* READ  */
  YYSYMBOL_REAL = 312,                     /* REAL  */
  YYSYMBOL_REASSIGN = 313,                 /* REASSIGN  */
  YYSYMBOL_RECHECK = 314,                  /* RECHECK  */
  YYSYMBOL_RECURSIVE = 315,                /* RECURSIVE  */
  YYSYMBOL_REF_P = 316,                    /* REF_P  */
  YYSYMBOL_REFERENCES = 317,               /* REFERENCES  */
  YYSYMBOL_REFERENCING = 318,              /* REFERENCING  */
  YYSYMBOL_REFRESH = 319,                  /* REFRESH  */
  YYSYMBOL_REINDEX = 320,                  /* REINDEX  */
  YYSYMBOL_RELATIVE_P = 321,               /* RELATIVE_P  */
  YYSYMBOL_RELEASE = 322,                  /* RELEASE  */
  YYSYMBOL_RENAME = 323,                   /* RENAME  */
  YYSYMBOL_REPEATABLE = 324,               /* REPEATABLE  */
  YYSYMBOL_REPLACE = 325,                  /* REPLACE  */
  YYSYMBOL_REPLICA = 326,                  /* REPLICA  */
  YYSYMBOL_RESET = 327,                    /* RESET  */
  YYSYMBOL_RESTART = 328,                  /* RESTART  */
  YYSYMBOL_RESTRICT = 329,                 /* RESTRICT  */
  YYSYMBOL_RETURNING = 330,                /* RETURNING  */
  YYSYMBOL_RETURNS = 331,                  /* RETURNS  */
  YYSYMBOL_REVOKE = 332,                   /* REVOKE  */
  YYSYMBOL_RIGHT = 333,                    /* RIGHT  */
  YYSYMBOL_ROLE = 334,                     /* ROLE  */
  YYSYMBOL_ROLLBACK = 335,                 /* ROLLBACK  */
  YYSYMBOL_ROLLUP = 336,                   /* ROLLUP  */
  YYSYMBOL_ROUTINE = 337,                  /* ROUTINE  */
  YYSYMBOL_ROUTINES = 338,                 /* ROUTINES  */
  YYSYMBOL_ROW = 339,                      /* ROW  */
  YYSYMBOL_ROWS = 340,                     /* ROWS  */
  YYSYMBOL_RULE = 341,                     /* RULE  */
  YYSYMBOL_SAVEPOINT = 342,                /* SAVEPOINT  */
  YYSYMBOL_SCHEMA = 343,                   /* SCHEMA  */
  YYSYMBOL_SCHEMAS = 344,                  /* SCHEMAS  */
  YYSYMBOL_SCROLL = 345,                   /* SCROLL  */
  YYSYMBOL_SEARCH = 346,                   /* SEARCH  */
  YYSYMBOL_SECOND_P = 347,                 /* SECOND_P  */
  YYSYMBOL_SECURITY = 348,                 /* SECURITY  */
  YYSYMBOL_SELECT = 349,                   /* SELECT  */
  YYSYMBOL_SEQUENCE = 350,                 /* SEQUENCE  */
  YYSYMBOL_SEQUENCES = 351,                /* SEQUENCES  */
  YYSYMBOL_SERIALIZABLE = 352,             /* SERIALIZABLE  */
  YYSYMBOL_SERVER = 353,                   /* SERVER  */
  YYSYMBOL_SESSION = 354,                  /* SESSION  */
  YYSYMBOL_SESSION_USER = 355,             /* SESSION_USER  */
  YYSYMBOL_SET = 356,                      /* SET  */
  YYSYMBOL_SETS = 357,                     /* SETS  */
  YYSYMBOL_SETOF = 358,                    /* SETOF  */
  YYSYMBOL_SHARE = 359,                    /* SHARE  */
  YYSYMBOL_SHOW = 360,                     /* SHOW  */
  YYSYMBOL_SIMILAR = 361,                  /* SIMILAR  */
  YYSYMBOL_SIMPLE = 362,                   /* SIMPLE  */
  YYSYMBOL_SKIP = 363,                     /* SKIP  */
  YYSYMBOL_SMALLINT = 364,                 /* SMALLINT  */
  YYSYMBOL_SNAPSHOT = 365,                 /* SNAPSHOT  */
  YYSYMBOL_SOME = 366,                     /* SOME  */
  YYSYMBOL_SQL_P = 367,                    /* SQL_P  */
  YYSYMBOL_STABLE = 368,                   /* STABLE  */
  YYSYMBOL_STANDALONE_P = 369,             /* STANDALONE_P  */
  YYSYMBOL_START = 370,                    /* START  */
  YYSYMBOL_STATEMENT = 371,                /* STATEMENT  */
  YYSYMBOL_STATISTICS = 372,               /* STATISTICS  */
  YYSYMBOL_STDIN = 373,                    /* STDIN  */
  YYSYMBOL_STDOUT = 374,                   /* STDOUT  */
  YYSYMBOL_STORAGE = 375,                  /* STORAGE  */
  YYSYMBOL_STORED = 376,                   /* STORED  */
  YYSYMBOL_STRICT_P = 377,                 /* STRICT_P  */
  YYSYMBOL_STRIP_P = 378,                  /* STRIP_P  */
  YYSYMBOL_SUBSCRIPTION = 379,             /* SUBSCRIPTION  */
  YYSYMBOL_SUBSTRING = 380,                /* SUBSTRING  */
  YYSYMBOL_SUPPORT = 381,                  /* SUPPORT  */
  YYSYMBOL_SYMMETRIC = 382,                /* SYMMETRIC  */
  YYSYMBOL_SYSID = 383,                    /* SYSID  */
  YYSYMBOL_SYSTEM_P = 384,                 /* SYSTEM_P  */
  YYSYMBOL_TABLE = 385,                    /* TABLE  */
  YYSYMBOL_TABLES = 386,                   /* TABLES  */
  YYSYMBOL_TABLESAMPLE = 387,              /* TABLESAMPLE  */
  YYSYMBOL_TABLESPACE = 388,               /* TABLESPACE  */
  YYSYMBOL_TEMP = 389,                     /* TEMP  */
  YYSYMBOL_TEMPLATE = 390,                 /* TEMPLATE  */
  YYSYMBOL_TEMPORARY = 391,                /* TEMPORARY  */
  YYSYMBOL_TEXT_P = 392,                   /* TEXT_P  */
  YYSYMBOL_THEN = 393,                     /* THEN  */
  YYSYMBOL_TIES = 394,                     /* TIES  */
  YYSYMBOL_TIME = 395,                     /* TIME  */
  YYSYMBOL_TIMESTAMP = 396,                /* TIMESTAMP  */
  YYSYMBOL_TO = 397,                       /* TO  */
  YYSYMBOL_TRAILING = 398,                 /* TRAILING  */
  YYSYMBOL_TRANSACTION = 399,              /* TRANSACTION  */
  YYSYMBOL_TRANSFORM = 400,                /* TRANSFORM  */
  YYSYMBOL_TREAT = 401,                    /* TREAT  */
  YYSYMBOL_TRIGGER = 402,                  /* TRIGGER  */
  YYSYMBOL_TRIM = 403,                     /* TRIM  */
  YYSYMBOL_TRUE_P = 404,                   /* TRUE_P  */
  YYSYMBOL_TRUNCATE = 405,                 /* TRUNCATE  */
  YYSYMBOL_TRUSTED = 406,                  /* TRUSTED  */
  YYSYMBOL_TYPE_P = 407,                   /* TYPE_P  */
  YYSYMBOL_TYPES_P = 408,                  /* TYPES_P  */
  YYSYMBOL_UNBOUNDED = 409,                /* UNBOUNDED  */
  YYSYMBOL_UNCOMMITTED = 410,              /* UNCOMMITTED  */
  YYSYMBOL_UNENCRYPTED = 411,              /* UNENCRYPTED  */
  YYSYMBOL_UNION = 412,                    /* UNION  */
  YYSYMBOL_UNIQUE = 413,                   /* UNIQUE  */
  YYSYMBOL_UNKNOWN = 414,                  /* UNKNOWN  */
  YYSYMBOL_UNLISTEN = 415,                 /* UNLISTEN  */
  YYSYMBOL_UNLOGGED = 416,                 /* UNLOGGED  */
  YYSYMBOL_UNTIL = 417,                    /* UNTIL  */
  YYSYMBOL_UPDATE = 418,                   /* UPDATE  */
  YYSYMBOL_USER = 419,                     /* USER  */
  YYSYMBOL_USING = 420,                    /* USING  */
  YYSYMBOL_VACUUM = 421,                   /* VACUUM  */
  YYSYMBOL_VALID = 422,                    /* VALID  */
  YYSYMBOL_VALIDATE = 423,                 /* VALIDATE  */
  YYSYMBOL_VALIDATOR = 424,                /* VALIDATOR  */
  YYSYMBOL_VALUE_P = 425,                  /* VALUE_P  */
  YYSYMBOL_VALUES = 426,                   /* VALUES  */
  YYSYMBOL_VARCHAR_P = 427,                /* VARCHAR_P  */
  YYSYMBOL_VARIADIC = 428,                 /* VARIADIC  */
  YYSYMBOL_VARYING = 429,                  /* VARYING  */
  YYSYMBOL_VERBOSE = 430,                  /* VERBOSE  */
  YYSYMBOL_VERSION_P = 431,                /* VERSION_P  */
  YYSYMBOL_VIEW = 432,                     /* VIEW  */
  YYSYMBOL_VIEWS = 433,                    /* VIEWS  */
  YYSYMBOL_VOLATILE = 434,                 /* VOLATILE  */
  YYSYMBOL_WHEN = 435,                     /* WHEN  */
  YYSYMBOL_WHERE = 436,                    /* WHERE  */
  YYSYMBOL_WHITESPACE_P = 437,             /* WHITESPACE_P  */
  YYSYMBOL_WINDOW = 438,                   /* WINDOW  */
  YYSYMBOL_WITH = 439,                     /* WITH  */
  YYSYMBOL_WITHIN = 440,                   /* WITHIN  */
  YYSYMBOL_WITHOUT = 441,                  /* WITHOUT  */
  YYSYMBOL_WORK = 442,                     /* WORK  */
  YYSYMBOL_WRAPPER = 443,                  /* WRAPPER  */
  YYSYMBOL_WRITE = 444,                    /* WRITE  */
  YYSYMBOL_XML_P = 445,                    /* XML_P  */
  YYSYMBOL_XMLATTRIBUTES = 446,            /* XMLATTRIBUTES  */
  YYSYMBOL_XMLCONCAT = 447,                /* XMLCONCAT  */
  YYSYMBOL_XMLELEMENT = 448,               /* XMLELEMENT  */
  YYSYMBOL_XMLEXISTS = 449,                /* XMLEXISTS  */
  YYSYMBOL_XMLFOREST = 450,                /* XMLFOREST  */
  YYSYMBOL_XMLNAMESPACES = 451,            /* XMLNAMESPACES  */
  YYSYMBOL_XMLPARSE = 452,                 /* XMLPARSE  */
  YYSYMBOL_XMLPI = 453,                    /* XMLPI  */
  YYSYMBOL_XMLROOT = 454,                  /* XMLROOT  */
  YYSYMBOL_XMLSERIALIZE = 455,             /* XMLSERIALIZE  */
  YYSYMBOL_XMLTABLE = 456,                 /* XMLTABLE  */
  YYSYMBOL_YEAR_P = 457,                   /* YEAR_P  */
  YYSYMBOL_YES_P = 458,                    /* YES_P  */
  YYSYMBOL_ZONE = 459,                     /* ZONE  */
  YYSYMBOL_NOT_LA = 460,                   /* NOT_LA  */
  YYSYMBOL_NULLS_LA = 461,                 /* NULLS_LA  */
  YYSYMBOL_WITH_LA = 462,                  /* WITH_LA  */
  YYSYMBOL_463_ = 463,                     /* ';'  */
  YYSYMBOL_464_ = 464,                     /* '='  */
  YYSYMBOL_465_ = 465,                     /* ','  */
  YYSYMBOL_466_ = 466,                     /* '('  */
  YYSYMBOL_467_ = 467,                     /* ')'  */
  YYSYMBOL_468_ = 468,                     /* '.'  */
  YYSYMBOL_469_ = 469,                     /* '>'  */
  YYSYMBOL_470_ = 470,                     /* '<'  */
  YYSYMBOL_471_ = 471,                     /* '\''  */
  YYSYMBOL_YYACCEPT = 472,                 /* $accept  */
  YYSYMBOL_multi = 473,                    /* multi  */
  YYSYMBOL_stmt = 474,                     /* stmt  */
  YYSYMBOL_DeleteStmt = 475,               /* DeleteStmt  */
  YYSYMBOL_UpdateStmt = 476,               /* UpdateStmt  */
  YYSYMBOL_update_value_list = 477,        /* update_value_list  */
  YYSYMBOL_delete_where_clause = 478,      /* delete_where_clause  */
  YYSYMBOL_update_where_clause = 479,      /* update_where_clause  */
  YYSYMBOL_simple_where_list = 480,        /* simple_where_list  */
  YYSYMBOL_simple_where_single = 481,      /* simple_where_single  */
  YYSYMBOL_SelectStmt = 482,               /* SelectStmt  */
  YYSYMBOL_opt_target_list = 483,          /* opt_target_list  */
  YYSYMBOL_opt_target = 484,               /* opt_target  */
  YYSYMBOL_opt_target_all = 485,           /* opt_target_all  */
  YYSYMBOL_opt_target_normal = 486,        /* opt_target_normal  */
  YYSYMBOL_opt_target_as = 487,            /* opt_target_as  */
  YYSYMBOL_opt_target_no_as = 488,         /* opt_target_no_as  */
  YYSYMBOL_from_clause = 489,              /* from_clause  */
  YYSYMBOL_from_list = 490,                /* from_list  */
  YYSYMBOL_where_clause = 491,             /* where_clause  */
  YYSYMBOL_where_list = 492,               /* where_list  */
  YYSYMBOL_where_single = 493,             /* where_single  */
  YYSYMBOL_condition_op = 494,             /* condition_op  */
  YYSYMBOL_InsertStmt = 495,               /* InsertStmt  */
  YYSYMBOL_columnsList = 496,              /* columnsList  */
  YYSYMBOL_identList = 497,                /* identList  */
  YYSYMBOL_valuesList = 498,               /* valuesList  */
  YYSYMBOL_multiValue = 499,               /* multiValue  */
  YYSYMBOL_singleValue = 500,              /* singleValue  */
  YYSYMBOL_CreateStmt = 501,               /* CreateStmt  */
  YYSYMBOL_TableElementList = 502,         /* TableElementList  */
  YYSYMBOL_columnDef = 503,                /* columnDef  */
  YYSYMBOL_Nullable = 504,                 /* Nullable  */
  YYSYMBOL_ColId = 505,                    /* ColId  */
  YYSYMBOL_TypeName = 506,                 /* TypeName  */
  YYSYMBOL_table_name = 507,               /* table_name  */
  YYSYMBOL_Iconst = 508,                   /* Iconst  */
  YYSYMBOL_col_name_keyword = 509,         /* col_name_keyword  */
  YYSYMBOL_unreserved_keyword = 510        /* unreserved_keyword  */
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
#define YYFINAL  370
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  472
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  438
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  511

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   717


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   471,
     466,   467,     2,     2,   465,     2,   468,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   463,
     470,   464,   469,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   175,   175,   182,   192,   193,   194,   195,   196,   197,
     200,   211,   223,   233,   243,   244,   247,   248,   251,   261,
     270,   279,   289,   298,   310,   320,   330,   342,   352,   363,
     370,   371,   372,   373,   376,   382,   389,   392,   399,   407,
     410,   418,   427,   430,   438,   447,   450,   451,   454,   462,
     471,   478,   488,   489,   492,   502,   511,   520,   529,   538,
     550,   560,   571,   581,   593,   606,   607,   608,   611,   621,
     626,   632,   638,   645,   651,   658,   664,   671,   672,   673,
     676,   685,   691,   698,   708,   709,   713,   717,   721,   728,
     729,   730,   731,   732,   736,   744,   745,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,   765,   766,   767,   768,   769,   770,   771,
     772,   773,   774,   775,   776,   777,   778,   779,   780,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   790,   791,
     792,   793,   794,   795,   796,   797,   798,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   832,   833,   834,
     835,   836,   837,   838,   839,   840,   841,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   852,   853,   854,
     855,   856,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   888,   889,   890,   891,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   934,
     935,   936,   937,   938,   939,   940,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   991,   992,   993,   994,
     995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "FCONST",
  "SCONST", "BCONST", "XCONST", "Op", "ICONST", "PARAM", "TYPECAST",
  "DOT_DOT", "COLON_EQUALS", "EQUALS_GREATER", "LESS_EQUALS",
  "GREATER_EQUALS", "NOT_EQUALS", "ABORT_P", "ABSOLUTE_P", "ACCESS",
  "ACTION", "ADD_P", "ADMIN", "AFTER", "AGGREGATE", "ALL", "ALSO", "ALTER",
  "ALWAYS", "ANALYSE", "ANALYZE", "AND", "ANY", "ARRAY", "AS", "ASC",
  "ASSERTION", "ASSIGNMENT", "ASYMMETRIC", "AT", "ATTACH", "ATTRIBUTE",
  "AUTHORIZATION", "BACKWARD", "BEFORE", "BEGIN_P", "BETWEEN", "BIGINT",
  "BINARY", "BIT", "BOOLEAN_P", "BOTH", "BY", "CACHE", "CALL", "CALLED",
  "CASCADE", "CASCADED", "CASE", "CAST", "CATALOG_P", "CHAIN", "CHAR_P",
  "CHARACTER", "CHARACTERISTICS", "CHECK", "CHECKPOINT", "CLASS", "CLOSE",
  "CLUSTER", "COALESCE", "COLLATE", "COLLATION", "COLUMN", "COLUMNS",
  "COMMENT", "COMMENTS", "COMMIT", "COMMITTED", "CONCURRENTLY",
  "CONFIGURATION", "CONFLICT", "CONNECTION", "CONSTRAINT", "CONSTRAINTS",
  "CONTENT_P", "CONTINUE_P", "CONVERSION_P", "COPY", "COST", "CREATE",
  "CROSS", "CSV", "CUBE", "CURRENT_P", "CURRENT_CATALOG", "CURRENT_DATE",
  "CURRENT_ROLE", "CURRENT_SCHEMA", "CURRENT_TIME", "CURRENT_TIMESTAMP",
  "CURRENT_USER", "CURSOR", "CYCLE", "DATA_P", "DATABASE", "DAY_P",
  "DEALLOCATE", "DEC", "DECIMAL_P", "DECLARE", "DEFAULT", "DEFAULTS",
  "DEFERRABLE", "DEFERRED", "DEFINER", "DELETE_P", "DELIMITER",
  "DELIMITERS", "DEPENDS", "DESC", "DETACH", "DICTIONARY", "DISABLE_P",
  "DISCARD", "DISTINCT", "DO", "DOCUMENT_P", "DOMAIN_P", "DOUBLE_P",
  "DROP", "EACH", "ELSE", "ENABLE_P", "ENCODING", "ENCRYPTED", "END_P",
  "ENUM_P", "ESCAPE", "EVENT", "EXCEPT", "EXCLUDE", "EXCLUDING",
  "EXCLUSIVE", "EXECUTE", "EXISTS", "EXPLAIN", "EXTENSION", "EXTERNAL",
  "EXTRACT", "FALSE_P", "FAMILY", "FETCH", "FILTER", "FIRST_P", "FLOAT_P",
  "FOLLOWING", "FOR", "FORCE", "FOREIGN", "FORWARD", "FREEZE", "FROM",
  "FULL", "FUNCTION", "FUNCTIONS", "GENERATED", "GLOBAL", "GRANT",
  "GRANTED", "GREATEST", "GROUP_P", "GROUPING", "GROUPS", "HANDLER",
  "HAVING", "HEADER_P", "HOLD", "HOUR_P", "IDENTITY_P", "IF_P", "ILIKE",
  "IMMEDIATE", "IMMUTABLE", "IMPLICIT_P", "IMPORT_P", "IN_P", "INCLUDE",
  "INCLUDING", "INCREMENT", "INDEX", "INDEXES", "INHERIT", "INHERITS",
  "INITIALLY", "INLINE_P", "INNER_P", "INOUT", "INPUT_P", "INSENSITIVE",
  "INSERT", "INSTEAD", "INT_P", "INTEGER", "INTERSECT", "INTERVAL", "INTO",
  "INVOKER", "IS", "ISNULL", "ISOLATION", "JOIN", "KEY", "LABEL",
  "LANGUAGE", "LARGE_P", "LAST_P", "LATERAL_P", "LEADING", "LEAKPROOF",
  "LEAST", "LEFT", "LEVEL", "LIKE", "LIMIT", "LISTEN", "LOAD", "LOCAL",
  "LOCALTIME", "LOCALTIMESTAMP", "LOCATION", "LOCK_P", "LOCKED", "LOGGED",
  "MAPPING", "MATCH", "MATERIALIZED", "MAXVALUE", "METHOD", "MINUTE_P",
  "MINVALUE", "MODE", "MONTH_P", "MOVE", "NAME_P", "NAMES", "NATIONAL",
  "NATURAL", "NCHAR", "NEW", "NEXT", "NO", "NONE", "NOT", "NOTHING",
  "NOTIFY", "NOTNULL", "NOWAIT", "NULL_P", "NULLIF", "NULLS_P", "NUMERIC",
  "OBJECT_P", "OF", "OFF", "OFFSET", "OIDS", "OLD", "ON", "ONLY",
  "OPERATOR", "OPTION", "OPTIONS", "OR", "ORDER", "ORDINALITY", "OTHERS",
  "OUT_P", "OUTER_P", "OVER", "OVERLAPS", "OVERLAY", "OVERRIDING", "OWNED",
  "OWNER", "PARALLEL", "PARSER", "PARTIAL", "PARTITION", "PASSING",
  "PASSWORD", "PLACING", "PLANS", "POLICY", "POSITION", "PRECEDING",
  "PRECISION", "PRESERVE", "PREPARE", "PREPARED", "PRIMARY", "PRIOR",
  "PRIVILEGES", "PROCEDURAL", "PROCEDURE", "PROCEDURES", "PROGRAM",
  "PUBLICATION", "QUOTE", "RANGE", "READ", "REAL", "REASSIGN", "RECHECK",
  "RECURSIVE", "REF_P", "REFERENCES", "REFERENCING", "REFRESH", "REINDEX",
  "RELATIVE_P", "RELEASE", "RENAME", "REPEATABLE", "REPLACE", "REPLICA",
  "RESET", "RESTART", "RESTRICT", "RETURNING", "RETURNS", "REVOKE",
  "RIGHT", "ROLE", "ROLLBACK", "ROLLUP", "ROUTINE", "ROUTINES", "ROW",
  "ROWS", "RULE", "SAVEPOINT", "SCHEMA", "SCHEMAS", "SCROLL", "SEARCH",
  "SECOND_P", "SECURITY", "SELECT", "SEQUENCE", "SEQUENCES",
  "SERIALIZABLE", "SERVER", "SESSION", "SESSION_USER", "SET", "SETS",
  "SETOF", "SHARE", "SHOW", "SIMILAR", "SIMPLE", "SKIP", "SMALLINT",
  "SNAPSHOT", "SOME", "SQL_P", "STABLE", "STANDALONE_P", "START",
  "STATEMENT", "STATISTICS", "STDIN", "STDOUT", "STORAGE", "STORED",
  "STRICT_P", "STRIP_P", "SUBSCRIPTION", "SUBSTRING", "SUPPORT",
  "SYMMETRIC", "SYSID", "SYSTEM_P", "TABLE", "TABLES", "TABLESAMPLE",
  "TABLESPACE", "TEMP", "TEMPLATE", "TEMPORARY", "TEXT_P", "THEN", "TIES",
  "TIME", "TIMESTAMP", "TO", "TRAILING", "TRANSACTION", "TRANSFORM",
  "TREAT", "TRIGGER", "TRIM", "TRUE_P", "TRUNCATE", "TRUSTED", "TYPE_P",
  "TYPES_P", "UNBOUNDED", "UNCOMMITTED", "UNENCRYPTED", "UNION", "UNIQUE",
  "UNKNOWN", "UNLISTEN", "UNLOGGED", "UNTIL", "UPDATE", "USER", "USING",
  "VACUUM", "VALID", "VALIDATE", "VALIDATOR", "VALUE_P", "VALUES",
  "VARCHAR_P", "VARIADIC", "VARYING", "VERBOSE", "VERSION_P", "VIEW",
  "VIEWS", "VOLATILE", "WHEN", "WHERE", "WHITESPACE_P", "WINDOW", "WITH",
  "WITHIN", "WITHOUT", "WORK", "WRAPPER", "WRITE", "XML_P",
  "XMLATTRIBUTES", "XMLCONCAT", "XMLELEMENT", "XMLEXISTS", "XMLFOREST",
  "XMLNAMESPACES", "XMLPARSE", "XMLPI", "XMLROOT", "XMLSERIALIZE",
  "XMLTABLE", "YEAR_P", "YES_P", "ZONE", "NOT_LA", "NULLS_LA", "WITH_LA",
  "';'", "'='", "','", "'('", "')'", "'.'", "'>'", "'<'", "'\\''",
  "$accept", "multi", "stmt", "DeleteStmt", "UpdateStmt",
  "update_value_list", "delete_where_clause", "update_where_clause",
  "simple_where_list", "simple_where_single", "SelectStmt",
  "opt_target_list", "opt_target", "opt_target_all", "opt_target_normal",
  "opt_target_as", "opt_target_no_as", "from_clause", "from_list",
  "where_clause", "where_list", "where_single", "condition_op",
  "InsertStmt", "columnsList", "identList", "valuesList", "multiValue",
  "singleValue", "CreateStmt", "TableElementList", "columnDef", "Nullable",
  "ColId", "TypeName", "table_name", "Iconst", "col_name_keyword",
  "unreserved_keyword", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-444)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,  -364,  -138,  -178,  4124,  5952,     3,  -444,  -444,  -444,
    -444,  -444,  -444,    28,  5952,    28,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -152,  -444,  -444,  -444,  -444,  -444,  3667,  -444,  -444,  -320,
    -444,   -87,  -444,  -427,  -385,  -413,  5952,  4124,  -380,  5952,
    4581,  -444,  5952,  -444,  5952,   462,  -444,  5952,  -369,  -407,
    5952,  -444,   920,  -444,  -444,  -444,  5038,  -416,  -405,  -443,
    -444,   -40,  -444,   462,  5495,   -19,  -444,  -429,  -429,  -423,
    -444,  -406,  5952,  -444,   920,   -18,  -444,  -429,  -436,  5952,
    -444,   462,  5952,  -444,    -7,  5952,  -444,  -444,  -444,  -444,
    -444,  -444,  -404,   -27,  -410,  -408,  1378,  1836,  -444,  -444,
    -444,  3210,    -7,  5952,  -444,    -7,  -401,  5952,   -26,  2294,
    2752,    -7,  5952,  3210,  -444,   -19,  -397,  -444,  -444,    59,
    -184,  -444,  -444,  -444,   462,  -444,   462,  -444,  -444,  -444,
    -444,  -444,  -422,  -444,  -394,  -444,  -444,   920,  -444,   920,
    -444,  -444,  -429,  -444,  -444,    -7,  -389,  -190,  -444,   -25,
     -23,    -7,  -444,    -7,   -20,   -17,  3210,  -444,  -444,  -444,
    -444,  -444,  -444,  -415,  -444,  -444,  -444,  -392,  -444,  5952,
    -444
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       9,     0,     0,     0,    36,     0,     0,     2,     8,     7,
       6,     5,     4,     0,     0,     0,    86,   147,   148,   149,
     150,   151,   152,   153,   154,    34,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    97,    98,    99,
     100,   166,   167,   168,   169,   170,   171,   172,   173,   101,
     102,   174,   175,   176,   177,   178,   103,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     104,   105,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   106,
     229,   230,   231,   107,   232,   233,   234,   108,   235,   236,
     237,   238,   239,   240,   241,   242,   109,   110,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   111,   262,   263,
     264,   265,   112,   113,   114,   266,   267,   268,   269,   270,
     271,   272,   273,   115,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   116,   117,   294,   295,   296,   118,
     297,   298,   299,   119,   300,   120,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   121,   311,   122,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     123,   323,   124,   326,   324,   325,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   125,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     126,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   127,   376,   377,
     378,   379,   128,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   129,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   130,   131,
     404,   405,   132,   406,   133,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   134,   135,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   436,   437,   438,
      47,    28,    30,    31,    32,    33,    37,    88,    87,     0,
       1,     9,    94,     0,    15,    70,     0,    36,    53,     0,
       0,    43,     0,     3,     0,     0,    10,     0,     0,    46,
      48,    29,     0,    27,    40,    35,    38,    17,     0,     0,
      81,     0,    79,     0,     0,    14,    18,     0,     0,     0,
      71,     0,     0,    49,     0,    52,    54,     0,     0,     0,
      44,     0,     0,    11,     0,     0,    80,    93,    89,    90,
      92,    91,    96,     0,     0,     0,     0,     0,    65,    66,
      67,     0,     0,     0,    69,     0,    68,    50,     0,     0,
       0,     0,     0,     0,    41,    16,     0,    12,    82,     0,
      85,    21,    78,    77,     0,    19,     0,    20,    25,    26,
      24,    72,     0,    75,     0,    51,    59,     0,    55,     0,
      56,    64,     0,    60,    62,     0,     0,     0,    83,     0,
       0,     0,    73,     0,     0,     0,     0,    13,    95,    84,
      22,    23,    76,     0,    57,    58,    61,     0,    74,     0,
      63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -444,  -444,  -292,  -444,  -444,  -444,  -444,  -444,  -384,  -390,
    -444,  -444,  -293,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -396,  -395,  -391,  -444,  -444,  -444,  -444,  -403,  -376,  -444,
    -444,  -340,  -444,    -4,  -444,    71,  -444,  -444,  -444
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,     7,     8,     9,   397,   386,   423,   405,   406,
      10,   360,   361,   362,   363,   364,   365,   378,   389,   393,
     415,   416,   441,    11,   388,   409,   446,   472,   407,    12,
     399,   400,   488,   408,   432,   373,   460,   367,   368
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     366,   369,   402,   370,     1,   436,   449,   436,   427,   436,
     374,   376,   449,   436,   449,   449,   417,   442,   448,   433,
     421,    13,   425,   428,   426,    14,   451,   453,   438,    15,
       2,   372,   452,   439,   440,   438,   382,   455,   417,   384,
     439,   440,   443,   491,   444,   492,   465,   467,   457,   422,
     491,   385,   508,   387,   478,   480,   392,   411,   412,   424,
     445,   462,   459,   463,   474,   468,   470,   485,   486,   473,
     487,   499,   493,   417,   417,   481,   509,   483,   498,   383,
     489,   494,   490,   495,   391,   458,   375,     0,     0,     0,
     503,   496,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   417,     0,   417,     0,     0,     0,     0,     0,   497,
       0,     0,     0,     0,     3,   502,     0,   473,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   437,   450,   437,
       0,   437,     0,     0,   450,   437,   450,   450,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   390,   366,     0,   394,   396,     0,   398,     0,
     401,     0,     0,   410,     0,     0,   413,   431,   418,     0,
       0,     0,   420,     0,     0,     0,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,   447,     0,
     418,     0,     0,     0,     0,   454,     0,     0,   456,     0,
       0,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   469,     0,   471,
     461,   476,   500,   475,   501,   418,   418,   504,   482,   484,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,    16,   371,     0,     0,     0,
       0,   402,     0,   418,     0,   418,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    26,
      27,    28,   507,     0,     0,     0,     0,     0,     0,    29,
      30,     0,    31,    32,    33,   510,    34,    35,    36,    37,
      38,     0,    39,    40,     0,    41,    42,    43,    44,    45,
      46,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,     0,     0,     0,    57,    58,    59,
      60,    61,     0,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,     0,     0,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,     0,    84,    85,    86,
      87,    88,    89,     0,    90,    91,    92,    93,     0,     0,
      94,    95,    96,    97,    98,     0,    99,   100,   101,     0,
     102,   103,   104,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,     0,   115,   116,   117,   118,
       0,   119,     0,   120,     0,     0,     0,   121,   122,   123,
     124,     0,   125,   126,     0,   127,   128,   129,     0,   130,
     131,   132,   133,   134,     0,   135,   136,   137,   138,     0,
     139,   140,   141,   142,   143,   144,   145,     0,   146,     0,
     147,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,     0,     0,   156,     0,   157,   158,   159,   160,   161,
       0,     0,   162,   163,     0,   164,     0,     0,   165,   166,
     167,     0,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,     0,     0,   201,   202,   203,     0,     0,   204,   205,
     206,     0,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     0,   218,   219,   220,   221,   222,
     223,   224,   225,     0,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,   254,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,     0,   270,   271,   272,   273,   274,     0,   275,   276,
     277,   278,   279,     0,   280,   281,   282,   283,     0,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,   299,   300,     0,   301,     0,
     302,   303,   304,   305,   306,     0,   307,   308,   309,     0,
       0,   310,   311,   312,   313,   314,     0,   315,   316,   317,
     318,   319,   320,   321,     0,     0,   322,   323,   324,   325,
     326,     0,     0,   327,   328,   329,   330,   331,   332,   333,
       0,   334,     0,   335,   336,   337,   338,     0,     0,   339,
       0,     0,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,     0,    16,     0,     0,     0,     0,   403,   402,
       0,     0,     0,   404,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,    29,    30,     0,
      31,    32,    33,     0,    34,    35,    36,    37,    38,     0,
      39,    40,     0,    41,    42,    43,    44,    45,    46,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,    54,
      55,    56,     0,     0,     0,    57,    58,    59,    60,    61,
       0,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,     0,     0,    71,    72,    73,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,    83,     0,    84,    85,    86,    87,    88,
      89,     0,    90,    91,    92,    93,     0,     0,    94,    95,
      96,    97,    98,     0,    99,   100,   101,     0,   102,   103,
     104,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,   114,     0,   115,   116,   117,   118,     0,   119,
       0,   120,     0,     0,     0,   121,   122,   123,   124,     0,
     125,   126,     0,   127,   128,   129,     0,   130,   131,   132,
     133,   134,     0,   135,   136,   137,   138,     0,   139,   140,
     141,   142,   143,   144,   145,     0,   146,     0,   147,   148,
     149,   150,   151,   152,   153,     0,   154,     0,   155,     0,
       0,   156,     0,   157,   158,   159,   160,   161,     0,     0,
     162,   163,     0,   164,     0,     0,   165,   166,   167,     0,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,     0,
       0,   201,   202,   203,     0,     0,   204,   205,   206,     0,
     207,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,     0,   218,   219,   220,   221,   222,   223,   224,
     225,     0,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,   254,     0,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,     0,
     270,   271,   272,   273,   274,     0,   275,   276,   277,   278,
     279,     0,   280,   281,   282,   283,     0,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,   299,   300,     0,   301,     0,   302,   303,
     304,   305,   306,     0,   307,   308,   309,     0,     0,   310,
     311,   312,   313,   314,     0,   315,   316,   317,   318,   319,
     320,   321,     0,     0,   322,   323,   324,   325,   326,     0,
       0,   327,   328,   329,   330,   331,   332,   333,     0,   334,
       0,   335,   336,   337,   338,     0,     0,   339,     0,     0,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
       0,    16,     0,     0,     0,     0,   414,   402,     0,     0,
       0,   404,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,    29,    30,     0,    31,    32,
      33,     0,    34,    35,    36,    37,    38,     0,    39,    40,
       0,    41,    42,    43,    44,    45,    46,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,    54,    55,    56,
       0,     0,     0,    57,    58,    59,    60,    61,     0,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,     0,
       0,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,    83,     0,    84,    85,    86,    87,    88,    89,     0,
      90,    91,    92,    93,     0,     0,    94,    95,    96,    97,
      98,     0,    99,   100,   101,     0,   102,   103,   104,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     0,
     114,     0,   115,   116,   117,   118,     0,   119,     0,   120,
       0,     0,     0,   121,   122,   123,   124,     0,   125,   126,
       0,   127,   128,   129,     0,   130,   131,   132,   133,   134,
       0,   135,   136,   137,   138,     0,   139,   140,   141,   142,
     143,   144,   145,     0,   146,     0,   147,   148,   149,   150,
     151,   152,   153,     0,   154,     0,   155,     0,     0,   156,
       0,   157,   158,   159,   160,   161,     0,     0,   162,   163,
       0,   164,     0,     0,   165,   166,   167,     0,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,     0,     0,   201,
     202,   203,     0,     0,   204,   205,   206,     0,   207,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
       0,   218,   219,   220,   221,   222,   223,   224,   225,     0,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
     254,     0,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,     0,   270,   271,
     272,   273,   274,     0,   275,   276,   277,   278,   279,     0,
     280,   281,   282,   283,     0,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,   299,   300,     0,   301,     0,   302,   303,   304,   305,
     306,     0,   307,   308,   309,     0,     0,   310,   311,   312,
     313,   314,     0,   315,   316,   317,   318,   319,   320,   321,
       0,     0,   322,   323,   324,   325,   326,     0,     0,   327,
     328,   329,   330,   331,   332,   333,     0,   334,     0,   335,
     336,   337,   338,     0,     0,   339,     0,     0,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,     0,    16,
       0,     0,     0,     0,   464,   402,     0,     0,     0,   404,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,    29,    30,     0,    31,    32,    33,     0,
      34,    35,    36,    37,    38,     0,    39,    40,     0,    41,
      42,    43,    44,    45,    46,     0,     0,    47,    48,    49,
      50,    51,     0,    52,    53,    54,    55,    56,     0,     0,
       0,    57,    58,    59,    60,    61,     0,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,     0,     0,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,    83,
       0,    84,    85,    86,    87,    88,    89,     0,    90,    91,
      92,    93,     0,     0,    94,    95,    96,    97,    98,     0,
      99,   100,   101,     0,   102,   103,   104,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     0,   114,     0,
     115,   116,   117,   118,     0,   119,     0,   120,     0,     0,
       0,   121,   122,   123,   124,     0,   125,   126,     0,   127,
     128,   129,     0,   130,   131,   132,   133,   134,     0,   135,
     136,   137,   138,     0,   139,   140,   141,   142,   143,   144,
     145,     0,   146,     0,   147,   148,   149,   150,   151,   152,
     153,     0,   154,     0,   155,     0,     0,   156,     0,   157,
     158,   159,   160,   161,     0,     0,   162,   163,     0,   164,
       0,     0,   165,   166,   167,     0,     0,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,     0,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,     0,     0,   201,   202,   203,
       0,     0,   204,   205,   206,     0,   207,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,     0,   218,
     219,   220,   221,   222,   223,   224,   225,     0,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,   254,     0,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,     0,   270,   271,   272,   273,
     274,     0,   275,   276,   277,   278,   279,     0,   280,   281,
     282,   283,     0,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,   299,
     300,     0,   301,     0,   302,   303,   304,   305,   306,     0,
     307,   308,   309,     0,     0,   310,   311,   312,   313,   314,
       0,   315,   316,   317,   318,   319,   320,   321,     0,     0,
     322,   323,   324,   325,   326,     0,     0,   327,   328,   329,
     330,   331,   332,   333,     0,   334,     0,   335,   336,   337,
     338,     0,     0,   339,     0,     0,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,     0,    16,     0,     0,
       0,     0,   466,   402,     0,     0,     0,   404,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    29,    30,     0,    31,    32,    33,     0,    34,    35,
      36,    37,    38,     0,    39,    40,     0,    41,    42,    43,
      44,    45,    46,     0,     0,    47,    48,    49,    50,    51,
       0,    52,    53,    54,    55,    56,     0,     0,     0,    57,
      58,    59,    60,    61,     0,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,     0,     0,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,    83,     0,    84,
      85,    86,    87,    88,    89,     0,    90,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,     0,    99,   100,
     101,     0,   102,   103,   104,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,   114,     0,   115,   116,
     117,   118,     0,   119,     0,   120,     0,     0,     0,   121,
     122,   123,   124,     0,   125,   126,     0,   127,   128,   129,
       0,   130,   131,   132,   133,   134,     0,   135,   136,   137,
     138,     0,   139,   140,   141,   142,   143,   144,   145,     0,
     146,     0,   147,   148,   149,   150,   151,   152,   153,     0,
     154,     0,   155,     0,     0,   156,     0,   157,   158,   159,
     160,   161,     0,     0,   162,   163,     0,   164,     0,     0,
     165,   166,   167,     0,     0,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     0,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,     0,     0,   201,   202,   203,     0,     0,
     204,   205,   206,     0,   207,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,     0,   218,   219,   220,
     221,   222,   223,   224,   225,     0,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,   254,     0,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,     0,   270,   271,   272,   273,   274,     0,
     275,   276,   277,   278,   279,     0,   280,   281,   282,   283,
       0,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,   299,   300,     0,
     301,     0,   302,   303,   304,   305,   306,     0,   307,   308,
     309,     0,     0,   310,   311,   312,   313,   314,     0,   315,
     316,   317,   318,   319,   320,   321,     0,     0,   322,   323,
     324,   325,   326,     0,     0,   327,   328,   329,   330,   331,
     332,   333,     0,   334,     0,   335,   336,   337,   338,     0,
       0,   339,     0,     0,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,     0,    16,     0,     0,     0,     0,
     477,   402,     0,     0,     0,   404,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,    29,
      30,     0,    31,    32,    33,     0,    34,    35,    36,    37,
      38,     0,    39,    40,     0,    41,    42,    43,    44,    45,
      46,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,     0,     0,     0,    57,    58,    59,
      60,    61,     0,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,     0,     0,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,     0,    84,    85,    86,
      87,    88,    89,     0,    90,    91,    92,    93,     0,     0,
      94,    95,    96,    97,    98,     0,    99,   100,   101,     0,
     102,   103,   104,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,     0,   115,   116,   117,   118,
       0,   119,     0,   120,     0,     0,     0,   121,   122,   123,
     124,     0,   125,   126,     0,   127,   128,   129,     0,   130,
     131,   132,   133,   134,     0,   135,   136,   137,   138,     0,
     139,   140,   141,   142,   143,   144,   145,     0,   146,     0,
     147,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,     0,     0,   156,     0,   157,   158,   159,   160,   161,
       0,     0,   162,   163,     0,   164,     0,     0,   165,   166,
     167,     0,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,     0,     0,   201,   202,   203,     0,     0,   204,   205,
     206,     0,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     0,   218,   219,   220,   221,   222,
     223,   224,   225,     0,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,   254,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,     0,   270,   271,   272,   273,   274,     0,   275,   276,
     277,   278,   279,     0,   280,   281,   282,   283,     0,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,   299,   300,     0,   301,     0,
     302,   303,   304,   305,   306,     0,   307,   308,   309,     0,
       0,   310,   311,   312,   313,   314,     0,   315,   316,   317,
     318,   319,   320,   321,     0,     0,   322,   323,   324,   325,
     326,     0,     0,   327,   328,   329,   330,   331,   332,   333,
       0,   334,     0,   335,   336,   337,   338,     0,     0,   339,
       0,     0,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,     0,    16,     0,     0,     0,     0,   479,   402,
       0,     0,     0,   404,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,    29,    30,     0,
      31,    32,    33,     0,    34,    35,    36,    37,    38,     0,
      39,    40,     0,    41,    42,    43,    44,    45,    46,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,    54,
      55,    56,     0,     0,     0,    57,    58,    59,    60,    61,
       0,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,     0,     0,    71,    72,    73,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,    83,     0,    84,    85,    86,    87,    88,
      89,     0,    90,    91,    92,    93,     0,     0,    94,    95,
      96,    97,    98,     0,    99,   100,   101,     0,   102,   103,
     104,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,   114,     0,   115,   116,   117,   118,     0,   119,
       0,   120,     0,     0,     0,   121,   122,   123,   124,     0,
     125,   126,     0,   127,   128,   129,     0,   130,   131,   132,
     133,   134,     0,   135,   136,   137,   138,     0,   139,   140,
     141,   142,   143,   144,   145,     0,   146,     0,   147,   148,
     149,   150,   151,   152,   153,     0,   154,     0,   155,     0,
       0,   156,     0,   157,   158,   159,   160,   161,     0,     0,
     162,   163,     0,   164,     0,     0,   165,   166,   167,     0,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,     0,
       0,   201,   202,   203,     0,     0,   204,   205,   206,     0,
     207,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,     0,   218,   219,   220,   221,   222,   223,   224,
     225,     0,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,   254,     0,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,     0,
     270,   271,   272,   273,   274,     0,   275,   276,   277,   278,
     279,     0,   280,   281,   282,   283,     0,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,     0,   299,   300,     0,   301,     0,   302,   303,
     304,   305,   306,     0,   307,   308,   309,     0,     0,   310,
     311,   312,   313,   314,     0,   315,   316,   317,   318,   319,
     320,   321,     0,     0,   322,   323,   324,   325,   326,     0,
       0,   327,   328,   329,   330,   331,   332,   333,     0,   334,
       0,   335,   336,   337,   338,     0,     0,   339,     0,     0,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    26,    27,    28,     0,     0,     0,
       0,     0,   379,     0,    29,    30,     0,    31,    32,    33,
       0,    34,    35,    36,    37,    38,     0,    39,    40,     0,
      41,    42,    43,    44,    45,    46,     0,     0,    47,    48,
      49,    50,    51,     0,    52,    53,    54,    55,    56,     0,
       0,     0,    57,    58,    59,    60,    61,     0,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,     0,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
      83,     0,    84,    85,    86,    87,    88,    89,     0,    90,
      91,    92,    93,     0,     0,    94,    95,    96,    97,    98,
       0,    99,   100,   101,     0,   102,   103,   104,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,   114,
       0,   115,   116,   117,   118,     0,   119,     0,   120,     0,
       0,     0,   121,   122,   123,   124,     0,   125,   126,     0,
     127,   128,   129,     0,   130,   131,   132,   133,   134,     0,
     135,   136,   137,   138,     0,   139,   140,   141,   142,   143,
     144,   145,     0,   146,     0,   147,   148,   149,   150,   151,
     152,   153,     0,   154,     0,   155,     0,     0,   156,     0,
     157,   158,   159,   160,   161,     0,     0,   162,   163,     0,
     164,     0,     0,   165,   166,   167,     0,     0,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,     0,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,     0,     0,   201,   202,
     203,     0,     0,   204,   205,   206,     0,   207,     0,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,     0,
     218,   219,   220,   221,   222,   223,   224,   225,     0,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,   254,
       0,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,     0,   270,   271,   272,
     273,   274,     0,   275,   276,   277,   278,   279,     0,   280,
     281,   282,   283,     0,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
     299,   300,     0,   301,     0,   302,   303,   304,   305,   306,
       0,   307,   308,   309,     0,     0,   310,   311,   312,   313,
     314,     0,   315,   316,   317,   318,   319,   320,   321,     0,
       0,   322,   323,   324,   325,   326,     0,     0,   327,   328,
     329,   330,   331,   332,   333,     0,   334,     0,   335,   336,
     337,   338,     0,     0,   339,     0,     0,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,    16,     0,     0,
       0,     0,     0,     0,     0,   380,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    29,    30,     0,    31,    32,    33,     0,    34,    35,
      36,    37,    38,     0,    39,    40,     0,    41,    42,    43,
      44,    45,    46,     0,     0,    47,    48,    49,    50,    51,
       0,    52,    53,    54,    55,    56,     0,     0,     0,    57,
      58,    59,    60,    61,     0,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,     0,     0,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,    83,     0,    84,
      85,    86,    87,    88,    89,     0,    90,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,     0,    99,   100,
     101,     0,   102,   103,   104,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,   114,     0,   115,   116,
     117,   118,     0,   119,     0,   120,     0,     0,     0,   121,
     122,   123,   124,     0,   125,   126,     0,   127,   128,   129,
       0,   130,   131,   132,   133,   134,     0,   135,   136,   137,
     138,     0,   139,   140,   141,   142,   143,   144,   145,     0,
     146,     0,   147,   148,   149,   150,   151,   152,   153,     0,
     154,     0,   155,     0,     0,   156,     0,   157,   158,   159,
     160,   161,     0,     0,   162,   163,     0,   164,     0,     0,
     165,   166,   167,     0,     0,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     0,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,     0,     0,   201,   202,   203,     0,     0,
     204,   205,   206,     0,   207,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,     0,   218,   219,   220,
     221,   222,   223,   224,   225,     0,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,   254,     0,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,     0,   270,   271,   272,   273,   274,     0,
     275,   276,   277,   278,   279,     0,   280,   281,   282,   283,
       0,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,   299,   300,     0,
     301,     0,   302,   303,   304,   305,   306,     0,   307,   308,
     309,     0,     0,   310,   311,   312,   313,   314,     0,   315,
     316,   317,   318,   319,   320,   321,     0,     0,   322,   323,
     324,   325,   326,     0,     0,   327,   328,   329,   330,   331,
     332,   333,     0,   334,     0,   335,   336,   337,   338,     0,
       0,   339,     0,     0,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    24,   395,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,    29,    30,
       0,    31,    32,    33,     0,    34,    35,    36,    37,    38,
       0,    39,    40,     0,    41,    42,    43,    44,    45,    46,
       0,     0,    47,    48,    49,    50,    51,     0,    52,    53,
      54,    55,    56,     0,     0,     0,    57,    58,    59,    60,
      61,     0,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,     0,     0,    71,    72,    73,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,    83,     0,    84,    85,    86,    87,
      88,    89,     0,    90,    91,    92,    93,     0,     0,    94,
      95,    96,    97,    98,     0,    99,   100,   101,     0,   102,
     103,   104,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,   114,     0,   115,   116,   117,   118,     0,
     119,     0,   120,     0,     0,     0,   121,   122,   123,   124,
       0,   125,   126,     0,   127,   128,   129,     0,   130,   131,
     132,   133,   134,     0,   135,   136,   137,   138,     0,   139,
     140,   141,   142,   143,   144,   145,     0,   146,     0,   147,
     148,   149,   150,   151,   152,   153,     0,   154,     0,   155,
       0,     0,   156,     0,   157,   158,   159,   160,   161,     0,
       0,   162,   163,     0,   164,     0,     0,   165,   166,   167,
       0,     0,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,     0,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
       0,     0,   201,   202,   203,     0,     0,   204,   205,   206,
       0,   207,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     0,   218,   219,   220,   221,   222,   223,
     224,   225,     0,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,   254,     0,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
       0,   270,   271,   272,   273,   274,     0,   275,   276,   277,
     278,   279,     0,   280,   281,   282,   283,     0,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     0,   299,   300,     0,   301,     0,   302,
     303,   304,   305,   306,     0,   307,   308,   309,     0,     0,
     310,   311,   312,   313,   314,     0,   315,   316,   317,   318,
     319,   320,   321,     0,     0,   322,   323,   324,   325,   326,
       0,     0,   327,   328,   329,   330,   331,   332,   333,     0,
     334,     0,   335,   336,   337,   338,     0,     0,   339,     0,
       0,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    26,    27,    28,     0,     0,
       0,     0,     0,   419,     0,    29,    30,     0,    31,    32,
      33,     0,    34,    35,    36,    37,    38,     0,    39,    40,
       0,    41,    42,    43,    44,    45,    46,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,    54,    55,    56,
       0,     0,     0,    57,    58,    59,    60,    61,     0,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,     0,
       0,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,    83,     0,    84,    85,    86,    87,    88,    89,     0,
      90,    91,    92,    93,     0,     0,    94,    95,    96,    97,
      98,     0,    99,   100,   101,     0,   102,   103,   104,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     0,
     114,     0,   115,   116,   117,   118,     0,   119,     0,   120,
       0,     0,     0,   121,   122,   123,   124,     0,   125,   126,
       0,   127,   128,   129,     0,   130,   131,   132,   133,   134,
       0,   135,   136,   137,   138,     0,   139,   140,   141,   142,
     143,   144,   145,     0,   146,     0,   147,   148,   149,   150,
     151,   152,   153,     0,   154,     0,   155,     0,     0,   156,
       0,   157,   158,   159,   160,   161,     0,     0,   162,   163,
       0,   164,     0,     0,   165,   166,   167,     0,     0,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,     0,     0,   201,
     202,   203,     0,     0,   204,   205,   206,     0,   207,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
       0,   218,   219,   220,   221,   222,   223,   224,   225,     0,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
     254,     0,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,     0,   270,   271,
     272,   273,   274,     0,   275,   276,   277,   278,   279,     0,
     280,   281,   282,   283,     0,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,   299,   300,     0,   301,     0,   302,   303,   304,   305,
     306,     0,   307,   308,   309,     0,     0,   310,   311,   312,
     313,   314,     0,   315,   316,   317,   318,   319,   320,   321,
       0,     0,   322,   323,   324,   325,   326,     0,     0,   327,
     328,   329,   330,   331,   332,   333,     0,   334,     0,   335,
     336,   337,   338,     0,     0,   339,     0,     0,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,    16,     0,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,    29,    30,     0,    31,    32,    33,     0,    34,
      35,    36,    37,    38,     0,    39,    40,     0,    41,    42,
      43,    44,    45,    46,     0,     0,    47,    48,    49,    50,
      51,     0,    52,    53,    54,    55,    56,     0,     0,     0,
      57,    58,    59,    60,    61,     0,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,     0,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,    83,     0,
      84,    85,    86,    87,    88,    89,     0,    90,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,     0,    99,
     100,   101,     0,   102,   103,   104,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,   114,     0,   115,
     116,   117,   118,     0,   119,     0,   120,     0,     0,     0,
     121,   122,   123,   124,     0,   125,   126,     0,   127,   128,
     129,     0,   130,   131,   132,   133,   134,     0,   135,   136,
     137,   138,     0,   139,   140,   141,   142,   143,   144,   145,
       0,   146,     0,   147,   148,   149,   150,   151,   152,   153,
       0,   154,     0,   155,     0,     0,   156,     0,   157,   158,
     159,   160,   161,     0,     0,   162,   163,     0,   164,     0,
       0,   165,   166,   167,     0,     0,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,     0,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,     0,     0,   201,   202,   203,     0,
       0,   204,   205,   206,     0,   207,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,     0,   218,   219,
     220,   221,   222,   223,   224,   225,     0,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,   254,     0,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,     0,   270,   271,   272,   273,   274,
       0,   275,   276,   277,   278,   279,     0,   280,   281,   282,
     283,     0,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,   299,   300,
       0,   301,     0,   302,   303,   304,   305,   306,     0,   307,
     308,   309,     0,     0,   310,   311,   312,   313,   314,     0,
     315,   316,   317,   318,   319,   320,   321,     0,     0,   322,
     323,   324,   325,   326,     0,     0,   327,   328,   329,   330,
     331,   332,   333,     0,   334,     0,   335,   336,   337,   338,
       0,     0,   339,     0,     0,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,    29,
      30,     0,    31,    32,    33,     0,    34,    35,    36,    37,
      38,     0,    39,    40,     0,    41,    42,    43,    44,    45,
      46,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,     0,     0,     0,    57,    58,    59,
      60,    61,     0,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,     0,     0,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,     0,    84,    85,    86,
      87,    88,    89,     0,    90,    91,    92,    93,     0,     0,
      94,    95,    96,    97,    98,     0,    99,   100,   101,     0,
     102,   103,   104,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,     0,   115,   116,   117,   118,
       0,   119,     0,   120,     0,     0,     0,   121,   122,   123,
     124,     0,   125,   126,     0,   127,   128,   129,     0,   130,
     131,   132,   133,   134,     0,   135,   136,   137,   138,     0,
     139,   140,   141,   142,   143,   144,   145,     0,   146,     0,
     147,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,     0,     0,   156,     0,   157,   158,   159,   160,   161,
       0,     0,   162,   163,     0,   164,     0,     0,   165,   166,
     167,     0,     0,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,     0,     0,   201,   202,   203,     0,     0,   204,   205,
     206,     0,   207,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     0,   218,   219,   220,   221,   222,
     223,   224,   225,     0,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,   254,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,     0,   270,   271,   272,   273,   274,     0,   275,   276,
     277,   278,   279,     0,   280,   281,   282,   283,     0,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,   299,   300,     0,   301,     0,
     302,   303,   304,   305,   306,     0,   307,   308,   309,     0,
       0,   310,   311,   312,   313,   314,     0,   315,   316,   317,
     318,   319,   320,   321,     0,     0,   322,   323,   324,   325,
     326,     0,     0,   327,   328,   329,   330,   331,   332,   333,
       0,   334,     0,   335,   336,   337,   338,     0,     0,   339,
       0,     0,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359
};

static const yytype_int16 yycheck[] =
{
       4,     5,     9,     0,    91,    32,    32,    32,    48,    32,
      14,   163,    32,    32,    32,    32,   392,   408,   414,   403,
     436,   385,   465,    63,   467,   163,   417,   418,   464,   207,
     117,     3,   468,   469,   470,   464,   356,   421,   414,   466,
     469,   470,   465,   465,   467,   467,   436,   437,   424,   465,
     465,   436,   467,   466,   449,   450,   436,   426,   465,   464,
     466,   471,   466,   471,   465,   441,   442,   464,     9,   445,
     254,   261,   466,   449,   450,   451,   468,   453,   467,   371,
     464,   477,   466,   479,   377,   425,    15,    -1,    -1,    -1,
     493,   482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   477,    -1,   479,    -1,    -1,    -1,    -1,    -1,   485,
      -1,    -1,    -1,    -1,   201,   491,    -1,   493,    -1,    -1,
     496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   274,   274,
      -1,   274,    -1,    -1,   274,   274,   274,   274,    -1,    -1,
      -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,   377,    -1,   379,   380,    -1,   382,    -1,
     384,    -1,    -1,   387,    -1,    -1,   390,   427,   392,    -1,
      -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,
     414,    -1,    -1,    -1,    -1,   419,    -1,    -1,   422,    -1,
      -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,   443,
     467,   467,   467,   447,   467,   449,   450,   467,   452,   453,
     467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   471,     3,   463,    -1,    -1,    -1,
      -1,     9,    -1,   477,    -1,   479,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,   496,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,   509,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    -1,    -1,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   113,    -1,   115,   116,   117,
     118,   119,   120,    -1,   122,   123,   124,   125,    -1,    -1,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,    -1,
     138,   139,   140,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,    -1,   154,   155,   156,   157,
      -1,   159,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,   170,   171,    -1,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,    -1,   206,    -1,
     208,    -1,    -1,   211,    -1,   213,   214,   215,   216,   217,
      -1,    -1,   220,   221,    -1,   223,    -1,    -1,   226,   227,
     228,    -1,    -1,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,   252,   253,    -1,   255,   256,    -1,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,    -1,    -1,   271,   272,   273,    -1,    -1,   276,   277,
     278,    -1,   280,    -1,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    -1,   293,   294,   295,   296,   297,
     298,   299,   300,    -1,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    -1,   331,   332,    -1,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,    -1,   350,   351,   352,   353,   354,    -1,   356,   357,
     358,   359,   360,    -1,   362,   363,   364,   365,    -1,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,    -1,   383,   384,    -1,   386,    -1,
     388,   389,   390,   391,   392,    -1,   394,   395,   396,    -1,
      -1,   399,   400,   401,   402,   403,    -1,   405,   406,   407,
     408,   409,   410,   411,    -1,    -1,   414,   415,   416,   417,
     418,    -1,    -1,   421,   422,   423,   424,   425,   426,   427,
      -1,   429,    -1,   431,   432,   433,   434,    -1,    -1,   437,
      -1,    -1,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,    -1,     3,    -1,    -1,    -1,    -1,   466,     9,
      -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,   113,    -1,   115,   116,   117,   118,   119,
     120,    -1,   122,   123,   124,   125,    -1,    -1,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,    -1,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,   152,    -1,   154,   155,   156,   157,    -1,   159,
      -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
     170,   171,    -1,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,    -1,   206,    -1,   208,    -1,
      -1,   211,    -1,   213,   214,   215,   216,   217,    -1,    -1,
     220,   221,    -1,   223,    -1,    -1,   226,   227,   228,    -1,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
     250,   251,   252,   253,    -1,   255,   256,    -1,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,    -1,
      -1,   271,   272,   273,    -1,    -1,   276,   277,   278,    -1,
     280,    -1,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,    -1,   293,   294,   295,   296,   297,   298,   299,
     300,    -1,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
      -1,   331,   332,    -1,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,    -1,
     350,   351,   352,   353,   354,    -1,   356,   357,   358,   359,
     360,    -1,   362,   363,   364,   365,    -1,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,    -1,   383,   384,    -1,   386,    -1,   388,   389,
     390,   391,   392,    -1,   394,   395,   396,    -1,    -1,   399,
     400,   401,   402,   403,    -1,   405,   406,   407,   408,   409,
     410,   411,    -1,    -1,   414,   415,   416,   417,   418,    -1,
      -1,   421,   422,   423,   424,   425,   426,   427,    -1,   429,
      -1,   431,   432,   433,   434,    -1,    -1,   437,    -1,    -1,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
      -1,     3,    -1,    -1,    -1,    -1,   466,     9,    -1,    -1,
      -1,   471,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    -1,
      -1,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,   113,    -1,   115,   116,   117,   118,   119,   120,    -1,
     122,   123,   124,   125,    -1,    -1,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,    -1,   138,   139,   140,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
     152,    -1,   154,   155,   156,   157,    -1,   159,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,    -1,   170,   171,
      -1,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,    -1,   206,    -1,   208,    -1,    -1,   211,
      -1,   213,   214,   215,   216,   217,    -1,    -1,   220,   221,
      -1,   223,    -1,    -1,   226,   227,   228,    -1,    -1,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
     252,   253,    -1,   255,   256,    -1,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,    -1,    -1,   271,
     272,   273,    -1,    -1,   276,   277,   278,    -1,   280,    -1,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
      -1,   293,   294,   295,   296,   297,   298,   299,   300,    -1,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,    -1,   331,
     332,    -1,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,    -1,   350,   351,
     352,   353,   354,    -1,   356,   357,   358,   359,   360,    -1,
     362,   363,   364,   365,    -1,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
      -1,   383,   384,    -1,   386,    -1,   388,   389,   390,   391,
     392,    -1,   394,   395,   396,    -1,    -1,   399,   400,   401,
     402,   403,    -1,   405,   406,   407,   408,   409,   410,   411,
      -1,    -1,   414,   415,   416,   417,   418,    -1,    -1,   421,
     422,   423,   424,   425,   426,   427,    -1,   429,    -1,   431,
     432,   433,   434,    -1,    -1,   437,    -1,    -1,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,    -1,     3,
      -1,    -1,    -1,    -1,   466,     9,    -1,    -1,    -1,   471,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    -1,    -1,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    93,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,   113,
      -1,   115,   116,   117,   118,   119,   120,    -1,   122,   123,
     124,   125,    -1,    -1,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,    -1,   138,   139,   140,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,   152,    -1,
     154,   155,   156,   157,    -1,   159,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,    -1,   170,   171,    -1,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,    -1,   183,
     184,   185,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,    -1,   206,    -1,   208,    -1,    -1,   211,    -1,   213,
     214,   215,   216,   217,    -1,    -1,   220,   221,    -1,   223,
      -1,    -1,   226,   227,   228,    -1,    -1,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,   249,   250,   251,   252,   253,
      -1,   255,   256,    -1,   258,    -1,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,    -1,    -1,   271,   272,   273,
      -1,    -1,   276,   277,   278,    -1,   280,    -1,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,    -1,   293,
     294,   295,   296,   297,   298,   299,   300,    -1,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,    -1,   331,   332,    -1,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,    -1,   350,   351,   352,   353,
     354,    -1,   356,   357,   358,   359,   360,    -1,   362,   363,
     364,   365,    -1,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,    -1,   383,
     384,    -1,   386,    -1,   388,   389,   390,   391,   392,    -1,
     394,   395,   396,    -1,    -1,   399,   400,   401,   402,   403,
      -1,   405,   406,   407,   408,   409,   410,   411,    -1,    -1,
     414,   415,   416,   417,   418,    -1,    -1,   421,   422,   423,
     424,   425,   426,   427,    -1,   429,    -1,   431,   432,   433,
     434,    -1,    -1,   437,    -1,    -1,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,    -1,     3,    -1,    -1,
      -1,    -1,   466,     9,    -1,    -1,    -1,   471,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    -1,    -1,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    -1,    81,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    -1,    -1,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,   113,    -1,   115,
     116,   117,   118,   119,   120,    -1,   122,   123,   124,   125,
      -1,    -1,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,   170,   171,    -1,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,    -1,
     206,    -1,   208,    -1,    -1,   211,    -1,   213,   214,   215,
     216,   217,    -1,    -1,   220,   221,    -1,   223,    -1,    -1,
     226,   227,   228,    -1,    -1,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,   249,   250,   251,   252,   253,    -1,   255,
     256,    -1,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,    -1,    -1,   271,   272,   273,    -1,    -1,
     276,   277,   278,    -1,   280,    -1,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,    -1,   293,   294,   295,
     296,   297,   298,   299,   300,    -1,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,    -1,   331,   332,    -1,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,    -1,   350,   351,   352,   353,   354,    -1,
     356,   357,   358,   359,   360,    -1,   362,   363,   364,   365,
      -1,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,    -1,   383,   384,    -1,
     386,    -1,   388,   389,   390,   391,   392,    -1,   394,   395,
     396,    -1,    -1,   399,   400,   401,   402,   403,    -1,   405,
     406,   407,   408,   409,   410,   411,    -1,    -1,   414,   415,
     416,   417,   418,    -1,    -1,   421,   422,   423,   424,   425,
     426,   427,    -1,   429,    -1,   431,   432,   433,   434,    -1,
      -1,   437,    -1,    -1,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,    -1,     3,    -1,    -1,    -1,    -1,
     466,     9,    -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    -1,    -1,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   113,    -1,   115,   116,   117,
     118,   119,   120,    -1,   122,   123,   124,   125,    -1,    -1,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,    -1,
     138,   139,   140,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,    -1,   154,   155,   156,   157,
      -1,   159,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,   170,   171,    -1,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,    -1,   206,    -1,
     208,    -1,    -1,   211,    -1,   213,   214,   215,   216,   217,
      -1,    -1,   220,   221,    -1,   223,    -1,    -1,   226,   227,
     228,    -1,    -1,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,   252,   253,    -1,   255,   256,    -1,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,    -1,    -1,   271,   272,   273,    -1,    -1,   276,   277,
     278,    -1,   280,    -1,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    -1,   293,   294,   295,   296,   297,
     298,   299,   300,    -1,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    -1,   331,   332,    -1,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,    -1,   350,   351,   352,   353,   354,    -1,   356,   357,
     358,   359,   360,    -1,   362,   363,   364,   365,    -1,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,    -1,   383,   384,    -1,   386,    -1,
     388,   389,   390,   391,   392,    -1,   394,   395,   396,    -1,
      -1,   399,   400,   401,   402,   403,    -1,   405,   406,   407,
     408,   409,   410,   411,    -1,    -1,   414,   415,   416,   417,
     418,    -1,    -1,   421,   422,   423,   424,   425,   426,   427,
      -1,   429,    -1,   431,   432,   433,   434,    -1,    -1,   437,
      -1,    -1,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,    -1,     3,    -1,    -1,    -1,    -1,   466,     9,
      -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,   113,    -1,   115,   116,   117,   118,   119,
     120,    -1,   122,   123,   124,   125,    -1,    -1,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,    -1,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,   152,    -1,   154,   155,   156,   157,    -1,   159,
      -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
     170,   171,    -1,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,    -1,   206,    -1,   208,    -1,
      -1,   211,    -1,   213,   214,   215,   216,   217,    -1,    -1,
     220,   221,    -1,   223,    -1,    -1,   226,   227,   228,    -1,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
     250,   251,   252,   253,    -1,   255,   256,    -1,   258,    -1,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,    -1,
      -1,   271,   272,   273,    -1,    -1,   276,   277,   278,    -1,
     280,    -1,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,    -1,   293,   294,   295,   296,   297,   298,   299,
     300,    -1,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
      -1,   331,   332,    -1,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,    -1,
     350,   351,   352,   353,   354,    -1,   356,   357,   358,   359,
     360,    -1,   362,   363,   364,   365,    -1,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,    -1,   383,   384,    -1,   386,    -1,   388,   389,
     390,   391,   392,    -1,   394,   395,   396,    -1,    -1,   399,
     400,   401,   402,   403,    -1,   405,   406,   407,   408,   409,
     410,   411,    -1,    -1,   414,   415,   416,   417,   418,    -1,
      -1,   421,   422,   423,   424,   425,   426,   427,    -1,   429,
      -1,   431,   432,   433,   434,    -1,    -1,   437,    -1,    -1,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   471,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    37,    38,    -1,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    -1,    85,    86,    87,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
     113,    -1,   115,   116,   117,   118,   119,   120,    -1,   122,
     123,   124,   125,    -1,    -1,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,    -1,   138,   139,   140,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,   152,
      -1,   154,   155,   156,   157,    -1,   159,    -1,   161,    -1,
      -1,    -1,   165,   166,   167,   168,    -1,   170,   171,    -1,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,    -1,
     183,   184,   185,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,    -1,   206,    -1,   208,    -1,    -1,   211,    -1,
     213,   214,   215,   216,   217,    -1,    -1,   220,   221,    -1,
     223,    -1,    -1,   226,   227,   228,    -1,    -1,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,   249,   250,   251,   252,
     253,    -1,   255,   256,    -1,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,    -1,    -1,   271,   272,
     273,    -1,    -1,   276,   277,   278,    -1,   280,    -1,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,    -1,
     293,   294,   295,   296,   297,   298,   299,   300,    -1,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,    -1,   331,   332,
      -1,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,    -1,   350,   351,   352,
     353,   354,    -1,   356,   357,   358,   359,   360,    -1,   362,
     363,   364,   365,    -1,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,    -1,
     383,   384,    -1,   386,    -1,   388,   389,   390,   391,   392,
      -1,   394,   395,   396,    -1,    -1,   399,   400,   401,   402,
     403,    -1,   405,   406,   407,   408,   409,   410,   411,    -1,
      -1,   414,   415,   416,   417,   418,    -1,    -1,   421,   422,
     423,   424,   425,   426,   427,    -1,   429,    -1,   431,   432,
     433,   434,    -1,    -1,   437,    -1,    -1,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    -1,    -1,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    -1,    81,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    -1,    -1,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,   113,    -1,   115,
     116,   117,   118,   119,   120,    -1,   122,   123,   124,   125,
      -1,    -1,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,   170,   171,    -1,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,    -1,
     206,    -1,   208,    -1,    -1,   211,    -1,   213,   214,   215,
     216,   217,    -1,    -1,   220,   221,    -1,   223,    -1,    -1,
     226,   227,   228,    -1,    -1,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,   249,   250,   251,   252,   253,    -1,   255,
     256,    -1,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,    -1,    -1,   271,   272,   273,    -1,    -1,
     276,   277,   278,    -1,   280,    -1,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,    -1,   293,   294,   295,
     296,   297,   298,   299,   300,    -1,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,    -1,   331,   332,    -1,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,    -1,   350,   351,   352,   353,   354,    -1,
     356,   357,   358,   359,   360,    -1,   362,   363,   364,   365,
      -1,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,    -1,   383,   384,    -1,
     386,    -1,   388,   389,   390,   391,   392,    -1,   394,   395,
     396,    -1,    -1,   399,   400,   401,   402,   403,    -1,   405,
     406,   407,   408,   409,   410,   411,    -1,    -1,   414,   415,
     416,   417,   418,    -1,    -1,   421,   422,   423,   424,   425,
     426,   427,    -1,   429,    -1,   431,   432,   433,   434,    -1,
      -1,   437,    -1,    -1,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      -1,    -1,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,   113,    -1,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,   125,    -1,    -1,   128,
     129,   130,   131,   132,    -1,   134,   135,   136,    -1,   138,
     139,   140,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,   152,    -1,   154,   155,   156,   157,    -1,
     159,    -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,
      -1,   170,   171,    -1,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,    -1,   183,   184,   185,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,    -1,   206,    -1,   208,
      -1,    -1,   211,    -1,   213,   214,   215,   216,   217,    -1,
      -1,   220,   221,    -1,   223,    -1,    -1,   226,   227,   228,
      -1,    -1,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
     249,   250,   251,   252,   253,    -1,   255,   256,    -1,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
      -1,    -1,   271,   272,   273,    -1,    -1,   276,   277,   278,
      -1,   280,    -1,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,    -1,   293,   294,   295,   296,   297,   298,
     299,   300,    -1,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,    -1,   331,   332,    -1,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
      -1,   350,   351,   352,   353,   354,    -1,   356,   357,   358,
     359,   360,    -1,   362,   363,   364,   365,    -1,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,    -1,   383,   384,    -1,   386,    -1,   388,
     389,   390,   391,   392,    -1,   394,   395,   396,    -1,    -1,
     399,   400,   401,   402,   403,    -1,   405,   406,   407,   408,
     409,   410,   411,    -1,    -1,   414,   415,   416,   417,   418,
      -1,    -1,   421,   422,   423,   424,   425,   426,   427,    -1,
     429,    -1,   431,   432,   433,   434,    -1,    -1,   437,    -1,
      -1,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    37,    38,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    -1,
      -1,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,   113,    -1,   115,   116,   117,   118,   119,   120,    -1,
     122,   123,   124,   125,    -1,    -1,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,    -1,   138,   139,   140,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
     152,    -1,   154,   155,   156,   157,    -1,   159,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,    -1,   170,   171,
      -1,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,    -1,   206,    -1,   208,    -1,    -1,   211,
      -1,   213,   214,   215,   216,   217,    -1,    -1,   220,   221,
      -1,   223,    -1,    -1,   226,   227,   228,    -1,    -1,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
     252,   253,    -1,   255,   256,    -1,   258,    -1,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,    -1,    -1,   271,
     272,   273,    -1,    -1,   276,   277,   278,    -1,   280,    -1,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
      -1,   293,   294,   295,   296,   297,   298,   299,   300,    -1,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,    -1,   331,
     332,    -1,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,    -1,   350,   351,
     352,   353,   354,    -1,   356,   357,   358,   359,   360,    -1,
     362,   363,   364,   365,    -1,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
      -1,   383,   384,    -1,   386,    -1,   388,   389,   390,   391,
     392,    -1,   394,   395,   396,    -1,    -1,   399,   400,   401,
     402,   403,    -1,   405,   406,   407,   408,   409,   410,   411,
      -1,    -1,   414,   415,   416,   417,   418,    -1,    -1,   421,
     422,   423,   424,   425,   426,   427,    -1,   429,    -1,   431,
     432,   433,   434,    -1,    -1,   437,    -1,    -1,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,     3,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    -1,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,   113,    -1,
     115,   116,   117,   118,   119,   120,    -1,   122,   123,   124,
     125,    -1,    -1,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,    -1,   138,   139,   140,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,   152,    -1,   154,
     155,   156,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,   170,   171,    -1,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,    -1,   183,   184,
     185,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
      -1,   206,    -1,   208,    -1,    -1,   211,    -1,   213,   214,
     215,   216,   217,    -1,    -1,   220,   221,    -1,   223,    -1,
      -1,   226,   227,   228,    -1,    -1,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,   249,   250,   251,   252,   253,    -1,
     255,   256,    -1,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,    -1,    -1,   271,   272,   273,    -1,
      -1,   276,   277,   278,    -1,   280,    -1,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    -1,   293,   294,
     295,   296,   297,   298,   299,   300,    -1,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    -1,   331,   332,    -1,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,    -1,   350,   351,   352,   353,   354,
      -1,   356,   357,   358,   359,   360,    -1,   362,   363,   364,
     365,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,    -1,   383,   384,
      -1,   386,    -1,   388,   389,   390,   391,   392,    -1,   394,
     395,   396,    -1,    -1,   399,   400,   401,   402,   403,    -1,
     405,   406,   407,   408,   409,   410,   411,    -1,    -1,   414,
     415,   416,   417,   418,    -1,    -1,   421,   422,   423,   424,
     425,   426,   427,    -1,   429,    -1,   431,   432,   433,   434,
      -1,    -1,   437,    -1,    -1,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    -1,    -1,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,   113,    -1,   115,   116,   117,
     118,   119,   120,    -1,   122,   123,   124,   125,    -1,    -1,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,    -1,
     138,   139,   140,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,    -1,   154,   155,   156,   157,
      -1,   159,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,   170,   171,    -1,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,    -1,   206,    -1,
     208,    -1,    -1,   211,    -1,   213,   214,   215,   216,   217,
      -1,    -1,   220,   221,    -1,   223,    -1,    -1,   226,   227,
     228,    -1,    -1,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,   252,   253,    -1,   255,   256,    -1,
     258,    -1,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,    -1,    -1,   271,   272,   273,    -1,    -1,   276,   277,
     278,    -1,   280,    -1,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    -1,   293,   294,   295,   296,   297,
     298,   299,   300,    -1,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    -1,   331,   332,    -1,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,    -1,   350,   351,   352,   353,   354,    -1,   356,   357,
     358,   359,   360,    -1,   362,   363,   364,   365,    -1,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,    -1,   383,   384,    -1,   386,    -1,
     388,   389,   390,   391,   392,    -1,   394,   395,   396,    -1,
      -1,   399,   400,   401,   402,   403,    -1,   405,   406,   407,
     408,   409,   410,   411,    -1,    -1,   414,   415,   416,   417,
     418,    -1,    -1,   421,   422,   423,   424,   425,   426,   427,
      -1,   429,    -1,   431,   432,   433,   434,    -1,    -1,   437,
      -1,    -1,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    91,   117,   201,   349,   418,   473,   474,   475,   476,
     482,   495,   501,   385,   163,   207,     3,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    37,
      38,    40,    41,    42,    44,    45,    46,    47,    48,    50,
      51,    53,    54,    55,    56,    57,    58,    61,    62,    63,
      64,    65,    67,    68,    69,    70,    71,    75,    76,    77,
      78,    79,    81,    82,    83,    85,    86,    87,    88,    89,
      90,    93,    94,    95,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   113,   115,   116,   117,   118,   119,   120,
     122,   123,   124,   125,   128,   129,   130,   131,   132,   134,
     135,   136,   138,   139,   140,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   152,   154,   155,   156,   157,   159,
     161,   165,   166,   167,   168,   170,   171,   173,   174,   175,
     177,   178,   179,   180,   181,   183,   184,   185,   186,   188,
     189,   190,   191,   192,   193,   194,   196,   198,   199,   200,
     201,   202,   203,   204,   206,   208,   211,   213,   214,   215,
     216,   217,   220,   221,   223,   226,   227,   228,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   249,   250,   251,   252,   253,
     255,   256,   258,   260,   261,   262,   263,   264,   265,   267,
     268,   271,   272,   273,   276,   277,   278,   280,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   293,   294,
     295,   296,   297,   298,   299,   300,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   331,   332,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     350,   351,   352,   353,   354,   356,   357,   358,   359,   360,
     362,   363,   364,   365,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   383,
     384,   386,   388,   389,   390,   391,   392,   394,   395,   396,
     399,   400,   401,   402,   403,   405,   406,   407,   408,   409,
     410,   411,   414,   415,   416,   417,   418,   421,   422,   423,
     424,   425,   426,   427,   429,   431,   432,   433,   434,   437,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     483,   484,   485,   486,   487,   488,   505,   509,   510,   505,
       0,   463,     3,   507,   505,   507,   163,   465,   489,    35,
     468,   505,   356,   474,   466,   436,   478,   466,   496,   490,
     505,   484,   436,   491,   505,    26,   505,   477,   505,   502,
     503,   505,     9,   466,   471,   480,   481,   500,   505,   497,
     505,   426,   465,   505,   466,   492,   493,   500,   505,    35,
     505,   436,   465,   479,   464,   465,   467,    48,    63,   203,
     392,   427,   506,   480,     9,   505,    32,   274,   464,   469,
     470,   494,   494,   465,   467,   466,   498,   505,   492,    32,
     274,   494,   468,   494,   505,   480,   505,   500,   503,   466,
     508,   467,   471,   471,   466,   481,   466,   481,   500,   505,
     500,   505,   499,   500,   465,   505,   467,   466,   493,   466,
     493,   500,   505,   500,   505,   464,     9,   254,   504,   480,
     480,   465,   467,   466,   492,   492,   494,   500,   467,   261,
     467,   467,   500,   499,   467,   467,   500,   505,   467,   468,
     505
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   472,   473,   473,   474,   474,   474,   474,   474,   474,
     475,   476,   477,   477,   478,   478,   479,   479,   480,   480,
     480,   480,   480,   480,   481,   481,   481,   482,   483,   483,
     484,   484,   484,   484,   485,   485,   485,   486,   486,   486,
     487,   487,   487,   488,   488,   488,   489,   489,   490,   490,
     490,   490,   491,   491,   492,   492,   492,   492,   492,   492,
     493,   493,   493,   493,   493,   494,   494,   494,   495,   496,
     496,   497,   497,   498,   498,   499,   499,   500,   500,   500,
     501,   502,   502,   503,   504,   504,   505,   505,   505,   506,
     506,   506,   506,   506,   507,   508,   508,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     0,
       4,     5,     3,     5,     2,     0,     2,     0,     1,     3,
       3,     3,     5,     5,     3,     3,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     3,     0,     1,     3,     0,
       3,     5,     0,     2,     4,     0,     2,     0,     1,     2,
       3,     4,     2,     0,     1,     3,     3,     5,     5,     3,
       3,     5,     3,     7,     3,     1,     1,     1,     6,     3,
       0,     1,     3,     3,     5,     1,     3,     3,     3,     1,
       6,     1,     3,     4,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
        yyerror (yyscanner, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, yyscanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, yyscan_t yyscanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yyscanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, yyscan_t yyscanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, yyscanner);
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
                 int yyrule, yyscan_t yyscanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], yyscanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, yyscanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, yyscan_t yyscanner)
{
  YY_USE (yyvaluep);
  YY_USE (yyscanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t yyscanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, yyscanner);
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
  case 2: /* multi: stmt  */
#line 176 "../parse/bison.y"
        {
		List* list = (List*)newList();
		lappend(list, (yyvsp[0].node));
		(yyval.list) = list;
		(*((yy_extra_type **) (yyscanner)))->list = (void*)list;
	}
#line 3279 "../parse/bison.c"
    break;

  case 3: /* multi: multi ';' stmt  */
#line 183 "../parse/bison.y"
        {
		if((yyvsp[0].node) != (void*)0){
			lappend((yyvsp[-2].list), (yyvsp[0].node));
			(yyval.list) = (yyvsp[-2].list);
			(*((yy_extra_type **) (yyscanner)))->list = (void*)(yyvsp[-2].list);
		}
	}
#line 3291 "../parse/bison.c"
    break;

  case 4: /* stmt: CreateStmt  */
#line 192 "../parse/bison.y"
                {(yyval.node) = (Node*)(yyvsp[0].createStmt);}
#line 3297 "../parse/bison.c"
    break;

  case 5: /* stmt: InsertStmt  */
#line 193 "../parse/bison.y"
                    {(yyval.node) = (Node*)(yyvsp[0].insertStmt);}
#line 3303 "../parse/bison.c"
    break;

  case 6: /* stmt: SelectStmt  */
#line 194 "../parse/bison.y"
                    {(yyval.node) = (Node*)(yyvsp[0].selectStmt);}
#line 3309 "../parse/bison.c"
    break;

  case 7: /* stmt: UpdateStmt  */
#line 195 "../parse/bison.y"
                    {(yyval.node) = (Node*)(yyvsp[0].updateStmt);}
#line 3315 "../parse/bison.c"
    break;

  case 8: /* stmt: DeleteStmt  */
#line 196 "../parse/bison.y"
                    {(yyval.node) = (Node*)(yyvsp[0].deleteStmt);}
#line 3321 "../parse/bison.c"
    break;

  case 9: /* stmt: %empty  */
#line 197 "../parse/bison.y"
          {(yyval.node) = (void*)0;}
#line 3327 "../parse/bison.c"
    break;

  case 10: /* DeleteStmt: DELETE_P FROM ColId delete_where_clause  */
#line 201 "../parse/bison.y"
        {
		DeleteStmt* deleteStmt = (DeleteStmt*)makeNode(DeleteStmt);
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = (yyvsp[-1].str);
		deleteStmt->fromClause = fromClause;
		deleteStmt->whereClause = (yyvsp[0].list);
		(yyval.deleteStmt) = deleteStmt;
	}
#line 3340 "../parse/bison.c"
    break;

  case 11: /* UpdateStmt: UPDATE ColId SET update_value_list update_where_clause  */
#line 212 "../parse/bison.y"
        {
		UpdateStmt* updateStmt = (UpdateStmt*)makeNode(UpdateStmt);
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = (yyvsp[-3].str);
		updateStmt->fromClause = fromClause;
		updateStmt->updateValueList = (yyvsp[-1].list);
		updateStmt->whereClause = (yyvsp[0].list);
		(yyval.updateStmt) = updateStmt;
	}
#line 3354 "../parse/bison.c"
    break;

  case 12: /* update_value_list: ColId '=' singleValue  */
#line 224 "../parse/bison.y"
        {
		UpdateValue* updateValue = (UpdateValue*)makeNode(UpdateValue);
		updateValue->filed = (yyvsp[-2].str);
		updateValue->val = (yyvsp[0].str);
		List* list = (List*)newList();
		lappend(list, updateValue);
		(yyval.list) = list;
		
	}
#line 3368 "../parse/bison.c"
    break;

  case 13: /* update_value_list: update_value_list ',' ColId '=' singleValue  */
#line 234 "../parse/bison.y"
        {
		UpdateValue* updateValue = (UpdateValue*)makeNode(UpdateValue);
		updateValue->filed = (yyvsp[-2].str);
		updateValue->val = (yyvsp[0].str);
		lappend((yyvsp[-4].list), updateValue);
		(yyval.list) = (yyvsp[-4].list);
	}
#line 3380 "../parse/bison.c"
    break;

  case 14: /* delete_where_clause: WHERE simple_where_list  */
#line 243 "../parse/bison.y"
                                             {(yyval.list) = (yyvsp[0].list);}
#line 3386 "../parse/bison.c"
    break;

  case 15: /* delete_where_clause: %empty  */
#line 244 "../parse/bison.y"
          {(yyval.list) = (void*)0;}
#line 3392 "../parse/bison.c"
    break;

  case 16: /* update_where_clause: WHERE simple_where_list  */
#line 247 "../parse/bison.y"
                                             {(yyval.list) = (yyvsp[0].list);}
#line 3398 "../parse/bison.c"
    break;

  case 17: /* update_where_clause: %empty  */
#line 248 "../parse/bison.y"
          {(yyval.list) = (void*)0;}
#line 3404 "../parse/bison.c"
    break;

  case 18: /* simple_where_list: simple_where_single  */
#line 252 "../parse/bison.y"
        {
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = (yyvsp[0].whereSingle);
		lappend(list, whereCondition);
		(yyval.list) = list;
	}
#line 3418 "../parse/bison.c"
    break;

  case 19: /* simple_where_list: simple_where_list AND simple_where_single  */
#line 262 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = (yyvsp[0].whereSingle);
		lappend((yyvsp[-2].list), whereCondition);
		(yyval.list) = (yyvsp[-2].list);
	}
#line 3431 "../parse/bison.c"
    break;

  case 20: /* simple_where_list: simple_where_list OR simple_where_single  */
#line 271 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 0;
		whereCondition->whereSingle = (yyvsp[0].whereSingle);
		lappend((yyvsp[-2].list), whereCondition);
		(yyval.list) = (yyvsp[-2].list);
	}
#line 3444 "../parse/bison.c"
    break;

  case 21: /* simple_where_list: '(' simple_where_list ')'  */
#line 280 "../parse/bison.y"
        {
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = (yyvsp[-1].list);
		lappend(list, whereCondition);
		(yyval.list) = list;
	}
#line 3458 "../parse/bison.c"
    break;

  case 22: /* simple_where_list: simple_where_list AND '(' simple_where_list ')'  */
#line 290 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = (yyvsp[-1].list);
		lappend((yyvsp[-4].list), whereCondition);
		(yyval.list) = (yyvsp[-4].list);
	}
#line 3471 "../parse/bison.c"
    break;

  case 23: /* simple_where_list: simple_where_list OR '(' simple_where_list ')'  */
#line 299 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 1;
		whereCondition->list = (yyvsp[-1].list);
		lappend((yyvsp[-4].list), whereCondition);
		(yyval.list) = (yyvsp[-4].list);
	}
#line 3484 "../parse/bison.c"
    break;

  case 24: /* simple_where_single: ColId condition_op singleValue  */
#line 311 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-1].str);
		whereSingle->left.isVal = 0;
		whereSingle->left.field = (yyvsp[-2].str);
		whereSingle->right.isVal = 1;
		whereSingle->right.val = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3498 "../parse/bison.c"
    break;

  case 25: /* simple_where_single: singleValue condition_op singleValue  */
#line 321 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-1].str);
		whereSingle->left.isVal = 1;
		whereSingle->left.val = (yyvsp[-2].str);
		whereSingle->right.isVal = 1;
		whereSingle->right.val = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3512 "../parse/bison.c"
    break;

  case 26: /* simple_where_single: singleValue condition_op ColId  */
#line 331 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-1].str);
		whereSingle->left.isVal = 1;
		whereSingle->left.val = (yyvsp[-2].str);
		whereSingle->right.isVal = 0;
		whereSingle->right.field = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3526 "../parse/bison.c"
    break;

  case 27: /* SelectStmt: SELECT opt_target_list from_clause where_clause  */
#line 343 "../parse/bison.y"
        {
		SelectStmt* selectStmt = (SelectStmt*)makeNode(SelectStmt);
		selectStmt->optTargetList = (yyvsp[-2].list);
		selectStmt->fromClause = (yyvsp[-1].list);
		selectStmt->whereClause = (yyvsp[0].list);
		(yyval.selectStmt) = selectStmt;
	}
#line 3538 "../parse/bison.c"
    break;

  case 28: /* opt_target_list: opt_target  */
#line 353 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)(yyvsp[0].optTarget);
		if(optTarget != (void*)0 && (optTarget->isAll == 1 || optTarget->name != (void*)0)) {
			List* list = (List*)newList();
			lappend(list, (yyvsp[0].optTarget));
			(yyval.list) = list;
		} else {
			(yyval.list) = (void*)0;
		}
	}
#line 3553 "../parse/bison.c"
    break;

  case 29: /* opt_target_list: opt_target_list ',' opt_target  */
#line 364 "../parse/bison.y"
        {
		lappend((yyvsp[-2].list), (yyvsp[0].optTarget));
		(yyval.list) = (yyvsp[-2].list);
	}
#line 3562 "../parse/bison.c"
    break;

  case 30: /* opt_target: opt_target_all  */
#line 370 "../parse/bison.y"
                           {(yyval.optTarget) = (yyvsp[0].optTarget);}
#line 3568 "../parse/bison.c"
    break;

  case 31: /* opt_target: opt_target_normal  */
#line 371 "../parse/bison.y"
                            {(yyval.optTarget) = (yyvsp[0].optTarget);}
#line 3574 "../parse/bison.c"
    break;

  case 32: /* opt_target: opt_target_as  */
#line 372 "../parse/bison.y"
                        {(yyval.optTarget) = (yyvsp[0].optTarget);}
#line 3580 "../parse/bison.c"
    break;

  case 33: /* opt_target: opt_target_no_as  */
#line 373 "../parse/bison.y"
                           {(yyval.optTarget) = (yyvsp[0].optTarget);}
#line 3586 "../parse/bison.c"
    break;

  case 34: /* opt_target_all: ALL  */
#line 377 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 1;
		(yyval.optTarget) = optTarget;
	}
#line 3596 "../parse/bison.c"
    break;

  case 35: /* opt_target_all: ColId '.' ALL  */
#line 383 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 1;
		optTarget->tableAlias = (yyvsp[-2].str);
		(yyval.optTarget) = optTarget;
	}
#line 3607 "../parse/bison.c"
    break;

  case 36: /* opt_target_all: %empty  */
#line 389 "../parse/bison.y"
          {}
#line 3613 "../parse/bison.c"
    break;

  case 37: /* opt_target_normal: ColId  */
#line 393 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->name = (yyvsp[0].str);
		(yyval.optTarget) = optTarget;
	}
#line 3624 "../parse/bison.c"
    break;

  case 38: /* opt_target_normal: ColId '.' ColId  */
#line 400 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->tableAlias = (yyvsp[-2].str);
		optTarget->name = (yyvsp[0].str);
		(yyval.optTarget) = optTarget;
	}
#line 3636 "../parse/bison.c"
    break;

  case 39: /* opt_target_normal: %empty  */
#line 407 "../parse/bison.y"
          {}
#line 3642 "../parse/bison.c"
    break;

  case 40: /* opt_target_as: ColId AS ColId  */
#line 411 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->name = (yyvsp[-2].str);
		optTarget->alias = (yyvsp[0].str);
		(yyval.optTarget) = optTarget;
	}
#line 3654 "../parse/bison.c"
    break;

  case 41: /* opt_target_as: ColId '.' ColId AS ColId  */
#line 419 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->tableAlias = (yyvsp[-4].str);
		optTarget->name = (yyvsp[-2].str);
		optTarget->alias = (yyvsp[0].str);
		(yyval.optTarget) = optTarget;
	}
#line 3667 "../parse/bison.c"
    break;

  case 42: /* opt_target_as: %empty  */
#line 427 "../parse/bison.y"
          {}
#line 3673 "../parse/bison.c"
    break;

  case 43: /* opt_target_no_as: ColId ColId  */
#line 431 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->name = (yyvsp[-1].str);
		optTarget->alias = (yyvsp[0].str);
		(yyval.optTarget) = optTarget;
	}
#line 3685 "../parse/bison.c"
    break;

  case 44: /* opt_target_no_as: ColId '.' ColId ColId  */
#line 439 "../parse/bison.y"
        {
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->tableAlias = (yyvsp[-3].str);
		optTarget->name = (yyvsp[-1].str);
		optTarget->alias = (yyvsp[0].str);
		(yyval.optTarget) = optTarget;
	}
#line 3698 "../parse/bison.c"
    break;

  case 45: /* opt_target_no_as: %empty  */
#line 447 "../parse/bison.y"
          {}
#line 3704 "../parse/bison.c"
    break;

  case 46: /* from_clause: FROM from_list  */
#line 450 "../parse/bison.y"
                            {(yyval.list) = (yyvsp[0].list);}
#line 3710 "../parse/bison.c"
    break;

  case 47: /* from_clause: %empty  */
#line 451 "../parse/bison.y"
          {(yyval.list) = (void*)0;}
#line 3716 "../parse/bison.c"
    break;

  case 48: /* from_list: ColId  */
#line 455 "../parse/bison.y"
        {
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = (yyvsp[0].str);
		List* list = (List*)newList();
		lappend(list, fromClause);
		(yyval.list) = list;
	}
#line 3728 "../parse/bison.c"
    break;

  case 49: /* from_list: ColId ColId  */
#line 463 "../parse/bison.y"
        {
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = (yyvsp[-1].str);
		fromClause->alias = (yyvsp[0].str);
		List* list = (List*)newList();
		lappend(list, fromClause);
		(yyval.list) = list;
	}
#line 3741 "../parse/bison.c"
    break;

  case 50: /* from_list: from_list ',' ColId  */
#line 472 "../parse/bison.y"
        {
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = (yyvsp[0].str);
		lappend((yyvsp[-2].list), fromClause);
		(yyval.list) = (yyvsp[-2].list);
	}
#line 3752 "../parse/bison.c"
    break;

  case 51: /* from_list: from_list ',' ColId ColId  */
#line 479 "../parse/bison.y"
        {
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = (yyvsp[-1].str);
		fromClause->alias = (yyvsp[0].str);
		lappend((yyvsp[-3].list), fromClause);
		(yyval.list) = (yyvsp[-3].list);
	}
#line 3764 "../parse/bison.c"
    break;

  case 52: /* where_clause: WHERE where_list  */
#line 488 "../parse/bison.y"
                               {(yyval.list) = (yyvsp[0].list);}
#line 3770 "../parse/bison.c"
    break;

  case 53: /* where_clause: %empty  */
#line 489 "../parse/bison.y"
          {(yyval.list) = (void*)0;}
#line 3776 "../parse/bison.c"
    break;

  case 54: /* where_list: where_single  */
#line 493 "../parse/bison.y"
        {
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = (yyvsp[0].whereSingle);
		lappend(list, whereCondition);
		(yyval.list) = list;
	}
#line 3790 "../parse/bison.c"
    break;

  case 55: /* where_list: where_list AND where_single  */
#line 503 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = (yyvsp[0].whereSingle);
		lappend((yyvsp[-2].list), whereCondition);
		(yyval.list) = (yyvsp[-2].list);
	}
#line 3803 "../parse/bison.c"
    break;

  case 56: /* where_list: where_list OR where_single  */
#line 512 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 0;
		whereCondition->whereSingle = (yyvsp[0].whereSingle);
		lappend((yyvsp[-2].list), whereCondition);
		(yyval.list) = (yyvsp[-2].list);
	}
#line 3816 "../parse/bison.c"
    break;

  case 57: /* where_list: where_list AND '(' where_list ')'  */
#line 521 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = (yyvsp[-1].list);
		lappend((yyvsp[-4].list), whereCondition);
		(yyval.list) = (yyvsp[-4].list);
	}
#line 3829 "../parse/bison.c"
    break;

  case 58: /* where_list: where_list OR '(' where_list ')'  */
#line 530 "../parse/bison.y"
        {
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 1;
		whereCondition->list = (yyvsp[-1].list);
		lappend((yyvsp[-4].list), whereCondition);
		(yyval.list) = (yyvsp[-4].list);
	}
#line 3842 "../parse/bison.c"
    break;

  case 59: /* where_list: '(' where_list ')'  */
#line 539 "../parse/bison.y"
        {
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = (yyvsp[-1].list);
		lappend(list, whereCondition);
		(yyval.list) = list;
	}
#line 3856 "../parse/bison.c"
    break;

  case 60: /* where_single: ColId condition_op singleValue  */
#line 551 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-1].str);
		whereSingle->left.isVal = 0;
		whereSingle->left.field = (yyvsp[-2].str);
		whereSingle->right.isVal = 1;
		whereSingle->right.val = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3870 "../parse/bison.c"
    break;

  case 61: /* where_single: ColId '.' ColId condition_op singleValue  */
#line 561 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-1].str);
		whereSingle->left.isVal = 0;
		whereSingle->left.tableAlias = (yyvsp[-4].str);
		whereSingle->left.field = (yyvsp[-2].str);
		whereSingle->right.isVal = 1;
		whereSingle->right.val = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3885 "../parse/bison.c"
    break;

  case 62: /* where_single: ColId condition_op ColId  */
#line 572 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-1].str);
		whereSingle->left.isVal = 0;
		whereSingle->left.field = (yyvsp[-2].str);
		whereSingle->right.isVal = 0;
		whereSingle->right.field = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3899 "../parse/bison.c"
    break;

  case 63: /* where_single: ColId '.' ColId condition_op ColId '.' ColId  */
#line 582 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-3].str);
		whereSingle->left.isVal = 0;
		whereSingle->left.tableAlias = (yyvsp[-6].str);
		whereSingle->left.field = (yyvsp[-4].str);
		whereSingle->right.isVal = 0;
		whereSingle->right.tableAlias = (yyvsp[-2].str);
		whereSingle->right.field = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3915 "../parse/bison.c"
    break;

  case 64: /* where_single: singleValue condition_op singleValue  */
#line 594 "../parse/bison.y"
        {
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = (yyvsp[-1].str);
		whereSingle->left.isVal = 1;
		whereSingle->left.val = (yyvsp[-2].str);
		whereSingle->right.isVal = 1;
		whereSingle->right.val = (yyvsp[0].str);
		(yyval.whereSingle) = whereSingle;
	}
#line 3929 "../parse/bison.c"
    break;

  case 65: /* condition_op: '='  */
#line 606 "../parse/bison.y"
                  {(yyval.str) = "=";}
#line 3935 "../parse/bison.c"
    break;

  case 66: /* condition_op: '>'  */
#line 607 "../parse/bison.y"
              {(yyval.str) = ">";}
#line 3941 "../parse/bison.c"
    break;

  case 67: /* condition_op: '<'  */
#line 608 "../parse/bison.y"
              {(yyval.str) = "<";}
#line 3947 "../parse/bison.c"
    break;

  case 68: /* InsertStmt: INSERT INTO table_name columnsList VALUES valuesList  */
#line 612 "../parse/bison.y"
        {
		InsertStmt* insertStmt = (InsertStmt*)makeNode(InsertStmt);
		insertStmt->tableNode = (yyvsp[-3].tableNode);
		insertStmt->columnsList = (yyvsp[-2].list);
		insertStmt->valuesList = (yyvsp[0].list);
		(yyval.insertStmt) = insertStmt;
	}
#line 3959 "../parse/bison.c"
    break;

  case 69: /* columnsList: '(' identList ')'  */
#line 622 "../parse/bison.y"
        {
		(yyval.list) = (yyvsp[-1].list);
	}
#line 3967 "../parse/bison.c"
    break;

  case 70: /* columnsList: %empty  */
#line 626 "../parse/bison.y"
        {
		List* list = (List*)newList();
		(yyval.list) = list;
	}
#line 3976 "../parse/bison.c"
    break;

  case 71: /* identList: ColId  */
#line 633 "../parse/bison.y"
        {
		List* list = (List*)newList();
		lappend(list, (yyvsp[0].str));
		(yyval.list) = list;
	}
#line 3986 "../parse/bison.c"
    break;

  case 72: /* identList: identList ',' ColId  */
#line 639 "../parse/bison.y"
        {
		lappend((yyvsp[-2].list), (yyvsp[0].str));
		(yyval.list) = (yyvsp[-2].list);
	}
#line 3995 "../parse/bison.c"
    break;

  case 73: /* valuesList: '(' multiValue ')'  */
#line 646 "../parse/bison.y"
        {
		List* list = (List*)newList();
		lappend(list, (yyvsp[-1].list));
		(yyval.list) = list;
	}
#line 4005 "../parse/bison.c"
    break;

  case 74: /* valuesList: valuesList ',' '(' multiValue ')'  */
#line 652 "../parse/bison.y"
        {
		lappend((yyvsp[-4].list), (yyvsp[-1].list));
		(yyval.list) = (yyvsp[-4].list);
	}
#line 4014 "../parse/bison.c"
    break;

  case 75: /* multiValue: singleValue  */
#line 659 "../parse/bison.y"
        {
		List* list = (List*)newList();
		lappend(list, (yyvsp[0].str));
		(yyval.list) = list;
	}
#line 4024 "../parse/bison.c"
    break;

  case 76: /* multiValue: multiValue ',' singleValue  */
#line 665 "../parse/bison.y"
        {
		lappend((yyvsp[-2].list), (yyvsp[0].str));
		(yyval.list) = (yyvsp[-2].list);
	}
#line 4033 "../parse/bison.c"
    break;

  case 77: /* singleValue: '\'' ColId '\''  */
#line 671 "../parse/bison.y"
                             {(yyval.str) = (yyvsp[-1].str);}
#line 4039 "../parse/bison.c"
    break;

  case 78: /* singleValue: '\'' ICONST '\''  */
#line 672 "../parse/bison.y"
                           {(yyval.str) = fnc_itoa((yyvsp[-1].ival));}
#line 4045 "../parse/bison.c"
    break;

  case 79: /* singleValue: ICONST  */
#line 673 "../parse/bison.y"
                 {(yyval.str) = fnc_itoa((yyvsp[0].ival));}
#line 4051 "../parse/bison.c"
    break;

  case 80: /* CreateStmt: CREATE TABLE table_name '(' TableElementList ')'  */
#line 677 "../parse/bison.y"
        {
		CreateStmt* createStmt = (CreateStmt*)makeNode(CreateStmt);
		createStmt->tableNode = (yyvsp[-3].tableNode);
		createStmt->tableElementList = (yyvsp[-1].list);
		(yyval.createStmt) = createStmt;
	}
#line 4062 "../parse/bison.c"
    break;

  case 81: /* TableElementList: columnDef  */
#line 686 "../parse/bison.y"
        {
		List* list = (List*)newList();
		lappend(list, (yyvsp[0].columnNode));
		(yyval.list) = list;
	}
#line 4072 "../parse/bison.c"
    break;

  case 82: /* TableElementList: TableElementList ',' columnDef  */
#line 692 "../parse/bison.y"
        {
		lappend((yyvsp[-2].list), (yyvsp[0].columnNode));
		(yyval.list) = (yyvsp[-2].list);
	}
#line 4081 "../parse/bison.c"
    break;

  case 83: /* columnDef: ColId TypeName Iconst Nullable  */
#line 699 "../parse/bison.y"
        {
		ColumnNode* columnNode = (ColumnNode*)makeNode(ColumnNode);
		columnNode->fieldName = (yyvsp[-3].str);
		columnNode->length = calcLength((yyvsp[-2].ival), (yyvsp[-1].ival));
		columnNode->flag = (yyvsp[-2].ival) << 2 | (yyvsp[0].ival) << 1 | flexable((yyvsp[-2].ival));
		(yyval.columnNode) = columnNode;
	}
#line 4093 "../parse/bison.c"
    break;

  case 84: /* Nullable: NOT NULLS_P  */
#line 708 "../parse/bison.y"
                      {(yyval.ival) = 0;}
#line 4099 "../parse/bison.c"
    break;

  case 85: /* Nullable: %empty  */
#line 709 "../parse/bison.y"
          {(yyval.ival) = 1;}
#line 4105 "../parse/bison.c"
    break;

  case 86: /* ColId: IDENT  */
#line 714 "../parse/bison.y"
        {
		(yyval.str) = (yyvsp[0].str);
	}
#line 4113 "../parse/bison.c"
    break;

  case 87: /* ColId: unreserved_keyword  */
#line 718 "../parse/bison.y"
        {
		(yyval.str) = (yyvsp[0].keyword);
	}
#line 4121 "../parse/bison.c"
    break;

  case 88: /* ColId: col_name_keyword  */
#line 722 "../parse/bison.y"
        {
		(yyval.str) = (yyvsp[0].keyword);
	}
#line 4129 "../parse/bison.c"
    break;

  case 89: /* TypeName: CHAR_P  */
#line 728 "../parse/bison.y"
                 {(yyval.ival) = 1;}
#line 4135 "../parse/bison.c"
    break;

  case 90: /* TypeName: INT_P  */
#line 729 "../parse/bison.y"
               {(yyval.ival) = 3;}
#line 4141 "../parse/bison.c"
    break;

  case 91: /* TypeName: VARCHAR_P  */
#line 730 "../parse/bison.y"
                   {(yyval.ival) = 4;}
#line 4147 "../parse/bison.c"
    break;

  case 92: /* TypeName: TEXT_P  */
#line 731 "../parse/bison.y"
                {(yyval.ival) = 5;}
#line 4153 "../parse/bison.c"
    break;

  case 93: /* TypeName: BIGINT  */
#line 732 "../parse/bison.y"
                {(yyval.ival) = 6;}
#line 4159 "../parse/bison.c"
    break;

  case 94: /* table_name: IDENT  */
#line 737 "../parse/bison.y"
        {
		TableNode* tableNode = (TableNode*)makeNode(TableNode);
		tableNode->tableName = (yyvsp[0].str);
		(yyval.tableNode) = tableNode;
	}
#line 4169 "../parse/bison.c"
    break;

  case 95: /* Iconst: '(' ICONST ')'  */
#line 744 "../parse/bison.y"
                       {(yyval.ival) = (yyvsp[-1].ival);}
#line 4175 "../parse/bison.c"
    break;

  case 96: /* Iconst: %empty  */
#line 745 "../parse/bison.y"
                {(yyval.ival) = 0;}
#line 4181 "../parse/bison.c"
    break;


#line 4185 "../parse/bison.c"

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
      yyerror (yyscanner, YY_("syntax error"));
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
                      yytoken, &yylval, yyscanner);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yyscanner);
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
  yyerror (yyscanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, yyscanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yyscanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1175 "../parse/bison.y"


int flexable(int type) {
	if(type == 4 || type == 5){
		return 1;
	}
	return 0;
}

int calcLength(int type, int length) {
	if(length > 0){
		return length;
	}
	switch(type) {
		case 1:
			length = 1;
			break;
		case 2:
			length = 2;
			break;
		case 3:
			length = 4;
			break;
		case 6:
			length = 8;
			break;
		case 4:
			length = 1;
			break;
	}
	return length;
}

char* fnc_itoa(int number) {
	int _number = number;
	int len = 0;
	for(;;) {
		len++;
		if((_number = _number / 10) == 0){
			break;
		}
	}
	_number = number;
	char* buff = malloc(len + 1);
	*(buff + len) = 0;
	for(;len > 0; len--) {
		int i = _number % 10;
		*(buff + (len - 1)) = i + 0x30;
		_number = _number / 10;
	}
	return buff;
}

void yyerror(yyscan_t yyscanner, char *str) {
	fprintf(stderr, "error:%s\n", str);
	(*((yy_extra_type **) (yyscanner)))->list = (void*)0;
}

int yywrap() {
	return 1;
}
