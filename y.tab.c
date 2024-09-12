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
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    #define SYMBOL_TABLE_MAX 100
    #define RANGE_MAX_COUNT 50

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    // symbol table

    struct symbol {
        char * id_name;
        char * data_type;
        char * type;
        int line_number;
    } symbol_table[SYMBOL_TABLE_MAX]; // dynamically store later

    int count = 0;
    char type[10];
    extern int count_n;

    void add_to_table(char, const char *);
    void insert_type();
    int search(const char *);
    void print_symbol_table();
    void free_symbol_table();

    // help table to store ranges in symbol table
    int scope_symbol_array[RANGE_MAX_COUNT] = {0};
    int scope_symbol_array_top = 0;
    void new_scope();
    void end_of_scope();

    // abstract syntax tree

    struct node {
        struct node *left;
        struct node *right;
        char *token;
    };

    struct node *head;
    struct node * mknode(struct node *, struct node *, char *);
    void printInorder(struct node *);

    // semantics analysis

    void check_declaration(const char *name, const char *datatype, const char *type);
    char *get_type(const char *var);
    int check_types(const char *type1, const char *type2);



#line 131 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    CHAR = 260,                    /* CHAR  */
    VOID = 261,                    /* VOID  */
    RETURN = 262,                  /* RETURN  */
    FOR = 263,                     /* FOR  */
    WHILE = 264,                   /* WHILE  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    LT = 267,                      /* LT  */
    GT = 268,                      /* GT  */
    LE = 269,                      /* LE  */
    GE = 270,                      /* GE  */
    EQ = 271,                      /* EQ  */
    NE = 272,                      /* NE  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    ADD = 275,                     /* ADD  */
    SUB = 276,                     /* SUB  */
    DIV = 277,                     /* DIV  */
    MUL = 278,                     /* MUL  */
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    PUTCHAR = 281,                 /* PUTCHAR  */
    NUMBER = 282,                  /* NUMBER  */
    FLOAT_NUM = 283,               /* FLOAT_NUM  */
    ID = 284,                      /* ID  */
    CHARACTER = 285                /* CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define CHAR 260
#define VOID 261
#define RETURN 262
#define FOR 263
#define WHILE 264
#define IF 265
#define ELSE 266
#define LT 267
#define GT 268
#define LE 269
#define GE 270
#define EQ 271
#define NE 272
#define AND 273
#define OR 274
#define ADD 275
#define SUB 276
#define DIV 277
#define MUL 278
#define TRUE 279
#define FALSE 280
#define PUTCHAR 281
#define NUMBER 282
#define FLOAT_NUM 283
#define ID 284
#define CHARACTER 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "parser.y"

    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;

#line 251 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NE = 17,                        /* NE  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_ADD = 20,                       /* ADD  */
  YYSYMBOL_SUB = 21,                       /* SUB  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_MUL = 23,                       /* MUL  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_PUTCHAR = 26,                   /* PUTCHAR  */
  YYSYMBOL_NUMBER = 27,                    /* NUMBER  */
  YYSYMBOL_FLOAT_NUM = 28,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_CHARACTER = 30,                 /* CHARACTER  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_declarations = 43,              /* declarations  */
  YYSYMBOL_declaration = 44,               /* declaration  */
  YYSYMBOL_function_definition = 45,       /* function_definition  */
  YYSYMBOL_function_declaration = 46,      /* function_declaration  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_arguments_definition_section = 49, /* arguments_definition_section  */
  YYSYMBOL_arguments_definition = 50,      /* arguments_definition  */
  YYSYMBOL_argument_definition = 51,       /* argument_definition  */
  YYSYMBOL_datatype = 52,                  /* datatype  */
  YYSYMBOL_compound_statement = 53,        /* compound_statement  */
  YYSYMBOL_block = 54,                     /* block  */
  YYSYMBOL_item = 55,                      /* item  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_else = 59,                      /* else  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_condition = 61,                 /* condition  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_66_10 = 66,                     /* $@10  */
  YYSYMBOL_init = 67,                      /* init  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_arithmetic = 69,                /* arithmetic  */
  YYSYMBOL_relop = 70,                     /* relop  */
  YYSYMBOL_value = 71,                     /* value  */
  YYSYMBOL_argument_expression_section = 72, /* argument_expression_section  */
  YYSYMBOL_arguments_expression = 73,      /* arguments_expression  */
  YYSYMBOL_return = 74,                    /* return  */
  YYSYMBOL_75_11 = 75,                     /* $@11  */
  YYSYMBOL_76_12 = 76                      /* $@12  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
      31,    32,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    84,    87,    93,    99,   106,   106,   106,
     112,   115,   121,   124,   130,   138,   142,   146,   150,   157,
     163,   166,   172,   172,   177,   177,   180,   180,   184,   187,
     193,   193,   196,   202,   205,   208,   214,   214,   217,   217,
     222,   225,   228,   231,   231,   234,   234,   242,   245,   251,
     254,   257,   263,   266,   269,   272,   278,   281,   284,   287,
     290,   293,   299,   303,   307,   311,   314,   317,   321,   324,
     330,   333,   339,   342,   348,   348,   352,   352
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "VOID", "RETURN", "FOR", "WHILE", "IF", "ELSE", "LT", "GT", "LE", "GE",
  "EQ", "NE", "AND", "OR", "ADD", "SUB", "DIV", "MUL", "TRUE", "FALSE",
  "PUTCHAR", "NUMBER", "FLOAT_NUM", "ID", "CHARACTER", "'('", "')'", "','",
  "'{'", "'}'", "';'", "'='", "'['", "']'", "'&'", "$accept", "program",
  "declarations", "declaration", "function_definition",
  "function_declaration", "$@1", "$@2", "arguments_definition_section",
  "arguments_definition", "argument_definition", "datatype",
  "compound_statement", "block", "item", "$@3", "$@4", "$@5", "else",
  "$@6", "condition", "statement", "$@7", "$@8", "$@9", "$@10", "init",
  "expression", "arithmetic", "relop", "value",
  "argument_expression_section", "arguments_expression", "return", "$@11",
  "$@12", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      72,   -90,   -90,   -90,   -90,     7,    72,   -90,   -90,   -17,
     -21,   -90,   -90,   122,   -90,   -90,   -15,   -90,   -90,   -90,
     164,   -13,   -90,   -90,   -90,   -27,   -90,   150,    -6,   -18,
      84,   -90,   -12,    80,   -90,   -90,     1,   164,    -5,     2,
       4,    13,    15,    17,   -90,   150,    18,   164,   150,    -7,
     -90,     9,    19,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     150,   -90,    20,   -90,    24,   136,   136,   150,    39,   164,
     -90,    31,    33,    80,   -90,   -90,    32,    30,    80,    72,
     -90,    34,   -90,   -90,    40,   185,    41,    76,    44,    51,
     -90,   164,    32,   150,   -90,   164,    54,    62,   -90,    75,
     136,   -17,   -90,   -90,   -90,   -90,   -90,   -90,   150,   -17,
     -90,   150,   -90,   -90,   -90,    80,    67,   -90,    72,   -90,
      73,   -90,    80,   105,    80,   -90,   -90,    24,   -90,   -90,
      85,   -17,   -17,   -90,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    16,    17,    18,     0,     2,     3,     5,     0,
       0,     1,     4,     0,     6,     7,    74,    22,    24,    26,
       0,     0,    43,    62,    63,    65,    64,     0,     0,     0,
       0,    20,     0,    42,    51,    29,     0,     0,     0,     0,
       0,     0,     0,    65,    69,     0,     0,    71,     0,     0,
      67,     0,    36,    19,    21,    28,    52,    53,    55,    54,
       0,     8,     0,    77,     0,     0,     0,     0,     0,     0,
      72,     0,    70,    40,    50,    38,    48,     0,    49,    11,
      75,     0,    34,    35,     0,     0,     0,     0,    68,     0,
      66,     0,    48,     0,    37,     0,     0,    10,    12,     0,
       0,     0,    56,    57,    58,    59,    60,    61,     0,     0,
      68,     0,    44,    73,    39,    47,     0,     9,     0,    14,
       0,    25,    33,    32,    41,    46,    13,     0,    30,    27,
       0,     0,     0,    31,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   114,   -90,   -90,   -90,   -90,   -90,   -90,
       3,     0,   -89,   -90,    92,   -90,   -90,   -90,   -90,   -90,
     -63,   -62,   -90,   -90,   -90,   -90,    42,   -26,   -90,   -90,
     -11,   -90,   -90,   -90,   -90,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    36,    79,    96,    97,
      98,    29,    14,    30,    31,    39,    40,    41,   129,   131,
      84,    32,    76,    92,    46,    77,    94,    33,    60,   108,
      34,    71,    72,    35,    37,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    49,    81,    86,    47,    51,    10,    11,    15,    44,
      48,    52,   121,    56,    57,    58,    59,    13,    45,    68,
     123,   -76,    73,    50,    55,    74,    62,     1,     2,     3,
       4,    63,    61,    64,    78,    65,    70,   120,    75,    85,
      85,    87,   133,   134,    66,    20,    67,    21,    47,    69,
      22,    23,    24,    25,    26,    27,    80,   -45,    89,    56,
      57,    58,    59,    90,    28,   130,    91,   115,    95,    93,
     100,    88,   101,   109,    85,     1,     2,     3,     4,    99,
     113,   111,   122,   112,   116,   124,   117,     1,     2,     3,
       4,    16,    17,    18,    19,   118,    56,    57,    58,    59,
      56,    57,    58,    59,   119,    20,   125,    21,   110,   127,
      22,    23,    24,    25,    26,    27,   128,   132,    99,    53,
      12,   126,    54,     0,    28,     1,     2,     3,     4,    16,
      17,    18,    19,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,    21,     0,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     0,    20,     0,    42,
      82,    83,    28,    23,    24,    43,    26,    27,     0,     0,
       0,    20,     0,    42,     0,     0,    28,    23,    24,    43,
      26,    27,     0,     0,     0,    20,     0,    42,     0,     0,
      28,    23,    24,    43,    26,     0,     0,   102,   103,   104,
     105,   106,   107,     0,    28,    56,    57,    58,    59
};

static const yytype_int16 yycheck[] =
{
       0,    27,    64,    66,    31,    23,     6,     0,    29,    20,
      37,    29,   101,    20,    21,    22,    23,    34,    31,    45,
     109,    36,    48,    29,    36,    32,    37,     3,     4,     5,
       6,    36,    31,    31,    60,    31,    47,   100,    29,    65,
      66,    67,   131,   132,    31,    21,    31,    23,    31,    31,
      26,    27,    28,    29,    30,    31,    36,    38,    69,    20,
      21,    22,    23,    32,    40,   127,    33,    93,    38,    37,
      36,    32,    32,    32,   100,     3,     4,     5,     6,    79,
      91,    37,   108,    32,    95,   111,    32,     3,     4,     5,
       6,     7,     8,     9,    10,    33,    20,    21,    22,    23,
      20,    21,    22,    23,    29,    21,    39,    23,    32,    36,
      26,    27,    28,    29,    30,    31,    11,    32,   118,    35,
       6,   118,    30,    -1,    40,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    23,    -1,    -1,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    21,    -1,    23,
      24,    25,    40,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    21,    -1,    23,    -1,    -1,    40,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    21,    -1,    23,    -1,    -1,
      40,    27,    28,    29,    30,    -1,    -1,    12,    13,    14,
      15,    16,    17,    -1,    40,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    42,    43,    44,    45,    46,
      52,     0,    44,    34,    53,    29,     7,     8,     9,    10,
      21,    23,    26,    27,    28,    29,    30,    31,    40,    52,
      54,    55,    62,    68,    71,    74,    47,    75,    76,    56,
      57,    58,    23,    29,    71,    31,    65,    31,    37,    68,
      29,    23,    29,    35,    55,    36,    20,    21,    22,    23,
      69,    31,    71,    36,    31,    31,    31,    31,    68,    31,
      71,    72,    73,    68,    32,    29,    63,    66,    68,    48,
      36,    62,    24,    25,    61,    68,    61,    68,    32,    71,
      32,    33,    64,    37,    67,    38,    49,    50,    51,    52,
      36,    32,    12,    13,    14,    15,    16,    17,    70,    32,
      32,    37,    32,    71,    67,    68,    71,    32,    33,    29,
      61,    53,    68,    53,    68,    39,    51,    36,    11,    59,
      62,    60,    32,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    47,    48,    46,
      49,    49,    50,    50,    51,    52,    52,    52,    52,    53,
      54,    54,    56,    55,    57,    55,    58,    55,    55,    55,
      60,    59,    59,    61,    61,    61,    63,    62,    64,    62,
      62,    62,    62,    65,    62,    66,    62,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    75,    74,    76,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     0,     0,     7,
       1,     0,     1,     3,     2,     1,     1,     1,     1,     3,
       1,     2,     0,    10,     0,     6,     0,     7,     2,     1,
       0,     3,     0,     3,     1,     1,     0,     4,     0,     5,
       3,     6,     1,     0,     5,     0,     6,     2,     0,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     4,     2,
       1,     0,     1,     3,     0,     4,     0,     3
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
  case 2: /* program: declarations  */
#line 77 "parser.y"
                   {
        (yyval.nd_obj).nd = mknode(NULL, (yyvsp[0].nd_obj).nd, "program");
        head = (yyval.nd_obj).nd;
      }
#line 1415 "y.tab.c"
    break;

  case 3: /* declarations: declaration  */
#line 84 "parser.y"
                  {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "declarations");
      }
#line 1423 "y.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 87 "parser.y"
                               {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "declarations");
      }
#line 1431 "y.tab.c"
    break;

  case 5: /* declaration: function_definition  */
#line 93 "parser.y"
                          {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1439 "y.tab.c"
    break;

  case 6: /* function_definition: function_declaration compound_statement  */
#line 99 "parser.y"
                                              {
        end_of_scope();
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "function_definition");
      }
#line 1448 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 106 "parser.y"
                  { add_to_table('F', (yyvsp[0].nd_obj).name); }
#line 1454 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 106 "parser.y"
                                                      { new_scope(); }
#line 1460 "y.tab.c"
    break;

  case 9: /* function_declaration: datatype ID $@1 '(' $@2 arguments_definition_section ')'  */
#line 106 "parser.y"
                                                                                                        {
        (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-5].nd_obj).name);
      }
#line 1468 "y.tab.c"
    break;

  case 10: /* arguments_definition_section: arguments_definition  */
#line 112 "parser.y"
                           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "arguments_definition_section");
      }
#line 1476 "y.tab.c"
    break;

  case 11: /* arguments_definition_section: %empty  */
#line 115 "parser.y"
      {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "arguments_definition_section");
      }
#line 1484 "y.tab.c"
    break;

  case 12: /* arguments_definition: argument_definition  */
#line 121 "parser.y"
                          {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "arguments_definition");
      }
#line 1492 "y.tab.c"
    break;

  case 13: /* arguments_definition: arguments_definition ',' argument_definition  */
#line 124 "parser.y"
                                                   {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "arguments_definition");
      }
#line 1500 "y.tab.c"
    break;

  case 14: /* argument_definition: datatype ID  */
#line 130 "parser.y"
                  {
        add_to_table('V', (yyvsp[0].nd_obj).name);
        (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "argument_definition");
      }
#line 1510 "y.tab.c"
    break;

  case 15: /* datatype: INT  */
#line 138 "parser.y"
          {
        insert_type();
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1519 "y.tab.c"
    break;

  case 16: /* datatype: FLOAT  */
#line 142 "parser.y"
            {
        insert_type();
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1528 "y.tab.c"
    break;

  case 17: /* datatype: CHAR  */
#line 146 "parser.y"
           {
        insert_type();
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1537 "y.tab.c"
    break;

  case 18: /* datatype: VOID  */
#line 150 "parser.y"
           {
        insert_type();
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1546 "y.tab.c"
    break;

  case 19: /* compound_statement: '{' block '}'  */
#line 157 "parser.y"
                    {
        (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
      }
#line 1554 "y.tab.c"
    break;

  case 20: /* block: item  */
#line 163 "parser.y"
           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "block");
      }
#line 1562 "y.tab.c"
    break;

  case 21: /* block: block item  */
#line 166 "parser.y"
                 {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "block");
      }
#line 1570 "y.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 172 "parser.y"
          { add_to_table('K', (yyvsp[0].nd_obj).name); }
#line 1576 "y.tab.c"
    break;

  case 23: /* item: FOR $@3 '(' statement ';' condition ';' statement ')' compound_statement  */
#line 172 "parser.y"
                                                                                                           {
        struct node *temp = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "CONDITION");
        struct node *temp2 = mknode((yyvsp[-6].nd_obj).nd, temp, "CONDITION");
        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj).nd, (yyvsp[-9].nd_obj).name);
      }
#line 1586 "y.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 177 "parser.y"
            { add_to_table('K', (yyvsp[0].nd_obj).name); }
#line 1592 "y.tab.c"
    break;

  case 25: /* item: WHILE $@4 '(' condition ')' compound_statement  */
#line 177 "parser.y"
                                                                                 {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, (yyvsp[-5].nd_obj).name);
      }
#line 1600 "y.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 180 "parser.y"
         { add_to_table('K', (yyvsp[0].nd_obj).name); }
#line 1606 "y.tab.c"
    break;

  case 27: /* item: IF $@5 '(' condition ')' compound_statement else  */
#line 180 "parser.y"
                                                                                   {
        struct node *iff = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-6].nd_obj).name);
        (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
      }
#line 1615 "y.tab.c"
    break;

  case 28: /* item: statement ';'  */
#line 184 "parser.y"
                    {
        (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
    }
#line 1623 "y.tab.c"
    break;

  case 29: /* item: return  */
#line 187 "parser.y"
             {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1631 "y.tab.c"
    break;

  case 30: /* $@6: %empty  */
#line 193 "parser.y"
           { add_to_table('K', (yyvsp[0].nd_obj).name); }
#line 1637 "y.tab.c"
    break;

  case 31: /* else: ELSE $@6 compound_statement  */
#line 193 "parser.y"
                                                              {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[-2].nd_obj).name);
      }
#line 1645 "y.tab.c"
    break;

  case 32: /* else: %empty  */
#line 196 "parser.y"
      {
        (yyval.nd_obj).nd = NULL;
      }
#line 1653 "y.tab.c"
    break;

  case 33: /* condition: expression relop expression  */
#line 202 "parser.y"
                                  {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, (yyvsp[-1].nd_obj).name);
      }
#line 1661 "y.tab.c"
    break;

  case 34: /* condition: TRUE  */
#line 205 "parser.y"
           { add_to_table('K', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1669 "y.tab.c"
    break;

  case 35: /* condition: FALSE  */
#line 208 "parser.y"
            { add_to_table('K', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1677 "y.tab.c"
    break;

  case 36: /* $@7: %empty  */
#line 214 "parser.y"
                  { add_to_table('V', (yyvsp[0].nd_obj).name); }
#line 1683 "y.tab.c"
    break;

  case 37: /* statement: datatype ID $@7 init  */
#line 214 "parser.y"
                                                       {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, (yyvsp[-2].nd_obj).name);
      }
#line 1691 "y.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 217 "parser.y"
                      { add_to_table('P', (yyvsp[0].nd_obj).name); }
#line 1697 "y.tab.c"
    break;

  case 39: /* statement: datatype MUL ID $@8 init  */
#line 217 "parser.y"
                                                           {
        struct node *id = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
        struct node *pointer = mknode((yyvsp[-4].nd_obj).nd, id, "pointer_name");
        (yyval.nd_obj).nd = mknode(pointer, (yyvsp[0].nd_obj).nd, "pointer_definition");
      }
#line 1707 "y.tab.c"
    break;

  case 40: /* statement: ID '=' expression  */
#line 222 "parser.y"
                        {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "assignement");
      }
#line 1715 "y.tab.c"
    break;

  case 41: /* statement: MUL '(' expression ')' '=' expression  */
#line 225 "parser.y"
                                            {
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj).nd, "dereference_assignement");
      }
#line 1723 "y.tab.c"
    break;

  case 42: /* statement: expression  */
#line 228 "parser.y"
                 {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1731 "y.tab.c"
    break;

  case 43: /* $@9: %empty  */
#line 231 "parser.y"
              { add_to_table('K', (yyvsp[0].nd_obj).name); }
#line 1737 "y.tab.c"
    break;

  case 44: /* statement: PUTCHAR $@9 '(' value ')'  */
#line 231 "parser.y"
                                                            {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, (yyvsp[-4].nd_obj).name);
      }
#line 1745 "y.tab.c"
    break;

  case 45: /* $@10: %empty  */
#line 234 "parser.y"
                  { add_to_table('P', (yyvsp[0].nd_obj).name); }
#line 1751 "y.tab.c"
    break;

  case 46: /* statement: datatype ID $@10 '[' value ']'  */
#line 234 "parser.y"
                                                                {
        struct node *id = mknode(NULL, NULL, (yyvsp[-4].nd_obj).name);
        struct node *pointer = mknode((yyvsp[-5].nd_obj).nd, id, "pointer_name");
        (yyval.nd_obj).nd = mknode(pointer, (yyvsp[-1].nd_obj).nd, "array");
      }
#line 1761 "y.tab.c"
    break;

  case 47: /* init: '=' expression  */
#line 242 "parser.y"
                     {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1769 "y.tab.c"
    break;

  case 48: /* init: %empty  */
#line 245 "parser.y"
      {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "NULL");
      }
#line 1777 "y.tab.c"
    break;

  case 49: /* expression: expression arithmetic expression  */
#line 251 "parser.y"
                                       {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, (yyvsp[-1].nd_obj).name);
      }
#line 1785 "y.tab.c"
    break;

  case 50: /* expression: '(' expression ')'  */
#line 254 "parser.y"
                         {
        (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
      }
#line 1793 "y.tab.c"
    break;

  case 51: /* expression: value  */
#line 257 "parser.y"
            {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1801 "y.tab.c"
    break;

  case 52: /* arithmetic: ADD  */
#line 263 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1809 "y.tab.c"
    break;

  case 53: /* arithmetic: SUB  */
#line 266 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1817 "y.tab.c"
    break;

  case 54: /* arithmetic: MUL  */
#line 269 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1825 "y.tab.c"
    break;

  case 55: /* arithmetic: DIV  */
#line 272 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1833 "y.tab.c"
    break;

  case 56: /* relop: LT  */
#line 278 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1841 "y.tab.c"
    break;

  case 57: /* relop: GT  */
#line 281 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1849 "y.tab.c"
    break;

  case 58: /* relop: LE  */
#line 284 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1857 "y.tab.c"
    break;

  case 59: /* relop: GE  */
#line 287 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1865 "y.tab.c"
    break;

  case 60: /* relop: EQ  */
#line 290 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1873 "y.tab.c"
    break;

  case 61: /* relop: NE  */
#line 293 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1881 "y.tab.c"
    break;

  case 62: /* value: NUMBER  */
#line 299 "parser.y"
             {
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1890 "y.tab.c"
    break;

  case 63: /* value: FLOAT_NUM  */
#line 303 "parser.y"
                {
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1899 "y.tab.c"
    break;

  case 64: /* value: CHARACTER  */
#line 307 "parser.y"
                {
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1908 "y.tab.c"
    break;

  case 65: /* value: ID  */
#line 311 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1916 "y.tab.c"
    break;

  case 66: /* value: ID '(' argument_expression_section ')'  */
#line 314 "parser.y"
                                             {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, (yyvsp[-3].nd_obj).name);
      }
#line 1924 "y.tab.c"
    break;

  case 67: /* value: '&' ID  */
#line 317 "parser.y"
             {
        struct node *id = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(id, NULL, "address");
      }
#line 1933 "y.tab.c"
    break;

  case 68: /* value: MUL '(' expression ')'  */
#line 321 "parser.y"
                             {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "dereference");
      }
#line 1941 "y.tab.c"
    break;

  case 69: /* value: SUB value  */
#line 324 "parser.y"
                {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "unary_minus");
      }
#line 1949 "y.tab.c"
    break;

  case 70: /* argument_expression_section: arguments_expression  */
#line 330 "parser.y"
                           {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1957 "y.tab.c"
    break;

  case 71: /* argument_expression_section: %empty  */
#line 333 "parser.y"
      {
        (yyval.nd_obj).nd = NULL;
      }
#line 1965 "y.tab.c"
    break;

  case 72: /* arguments_expression: value  */
#line 339 "parser.y"
            {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "arguments_expression");
      }
#line 1973 "y.tab.c"
    break;

  case 73: /* arguments_expression: arguments_expression ',' value  */
#line 342 "parser.y"
                                     {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "arguments_expression");
      }
#line 1981 "y.tab.c"
    break;

  case 74: /* $@11: %empty  */
#line 348 "parser.y"
             { add_to_table('K', "return"); }
#line 1987 "y.tab.c"
    break;

  case 75: /* return: RETURN $@11 value ';'  */
#line 348 "parser.y"
                                                        {
        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return");
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "RETURN");
      }
#line 1996 "y.tab.c"
    break;

  case 76: /* $@12: %empty  */
#line 352 "parser.y"
             { add_to_table('K', "return"); }
#line 2002 "y.tab.c"
    break;

  case 77: /* return: RETURN $@12 ';'  */
#line 352 "parser.y"
                                                  {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "RETURN");
      }
#line 2010 "y.tab.c"
    break;


#line 2014 "y.tab.c"

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
  yyerror (YY_("memory exhausted"));
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

#line 357 "parser.y"


void new_scope() {
    scope_symbol_array[scope_symbol_array_top] = count;
    scope_symbol_array_top++;
}

void end_of_scope() {
    scope_symbol_array_top--;
    int new_count = scope_symbol_array[scope_symbol_array_top];
    for (int i = count - 1; i >= new_count; i--) {
        free(symbol_table[i].id_name);
		free(symbol_table[i].type);
    }
    count = new_count;
}

struct node * mknode(struct node *left, struct node *right, char *token) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    char *newstr = (char *) malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}

void printInorder(struct node *tree) {
    int i;
    if (tree->left) {
        printInorder(tree->left);
    }
    printf("%s, ", tree->token);
    if (tree->right) {
        printInorder(tree->right);
    }
}

void insert_type() {
        strcpy(type, yytext);
}

int search(const char *name) {
    for (int i = count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, name) == 0) {
            return -1;
            break;
        }
    }
    return 0;
}

void add_to_table(char symbol, const char *id_name) {
    print_symbol_table();
    if (search(id_name)) return;
    symbol_table[count].id_name = strdup(id_name);
    symbol_table[count].line_number = count_n;
    switch (symbol) {
        case 'K':
            symbol_table[count].data_type = strdup("N/A");
            symbol_table[count].type = strdup("Keyword");
            break;
        case 'V':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Variable");
            break;
        case 'C':
            symbol_table[count].data_type = strdup("CONST");
            symbol_table[count].type = strdup("Constant");
            break;
        case 'F':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Function");
            break;
        case 'P':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Pointer");
            break;
        default:
            yyerror("bad symbol");
            return;
    }
    count++;
}

void print_symbol_table() {
    printf("\nSYMBOL\t\t\tDATATYPE\t\tTYPE\t\t\tLINE NUMBER \n");
	printf("____________________________________________________________________________________________\n\n");

	for(int i = 0; i < count; i++) {
		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_number);
	}

	printf("\n");
}

void free_symbol_table() {
  for(int i = 0; i < count; i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
}

int main() {
    yyparse();
    print_symbol_table();
    printInorder(head);
    free_symbol_table();
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}
