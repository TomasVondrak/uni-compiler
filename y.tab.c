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

    #define SYMBOL_TABLE_MAX 1000
    #define RANGE_MAX_COUNT 500
    #define MAX_MESSAGES_COUNT 100
    #define MAX_MESSAGE_LENGTH 200
    #define ICG_LINE_LENGTH 1000
    #define ICG_LINE_COUNT 10000

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    // symbol table

    struct symbol {
        char *id_name;
        char *datatype;
        char *type;
        int line_number;
        int array_size;
    } symbol_table[SYMBOL_TABLE_MAX];

    int count = 0;
    char datatype[20];
    extern int count_n;

    void add_to_table(char, const char *);
    void insert_datatype(const char *);
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
    struct node * mknode(struct node *, struct node *, const char *);
    void print_inorder(struct node *);
    void print_tree(struct node* tree);
    void free_tree(struct node *tree);

    // semantics analysis

    char reserved_words[12][10] = {"int", "float", "char", "void", "if", "else", "while", "for", "return", "TRUE", "FALSE", "putchar"};
    int sem_errors = 0;
    char errors[MAX_MESSAGES_COUNT][MAX_MESSAGE_LENGTH];
    int sem_warnings = 0;
    char warnings[MAX_MESSAGES_COUNT][MAX_MESSAGE_LENGTH];
    int check_declaration(const char *);
    const char *get_type(const char *);
    const char *get_datatype(const char *);
    int check_types(const char *, const char *);
    int check_pointer_types(const char *, const char *, const char *);
    void check_return_datatype(const char *);
    const char *get_datatype_of_current_function();
    const char *get_id_of_current_function();
    struct node *handle_type_cast(int, struct node *, struct node *, const char *node_name);

    // intermediate code generation

    int ic_idx = 0;
    char icg[ICG_LINE_LENGTH][ICG_LINE_COUNT];
    int temp_var = 0;
    int label = 0;
    int is_for = 0;

    void print_line_to_icg(const char *);
    void print_str_to_icg(const char *);
    void new_line_to_icg();
    const char *datatype_to_icg(const char *);
    const char *pointer_to_icg_name_datatype(const char *);
    char *load_from_pointer(const char *, const char *, const char *);
    void print_icg();
    int get_array_size(const char *);
    void set_array_size(const char *, int);


#line 166 "y.tab.c"

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
#line 96 "parser.y"

    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;

    struct var_name2 {
        char name[100];
        struct node* nd;
        char datatype[20];
        char type[20];
    } nd_obj2;

    struct var_name3 {
        char name[100];
        struct node* nd;
        char if_body[10];
        char else_body[10];
        char next_body[10];
        char increment_body[10];
    } nd_obj3;

    struct var_name4 {
        char name[100];
        char icg_result[500];
        struct node* nd;
        char datatype[20];
        char type[20];
    } nd_obj4;

#line 310 "y.tab.c"

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
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_function_declaration = 47,      /* function_declaration  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_arguments_definition_section = 50, /* arguments_definition_section  */
  YYSYMBOL_arguments_definition = 51,      /* arguments_definition  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_argument_definition = 53,       /* argument_definition  */
  YYSYMBOL_datatype = 54,                  /* datatype  */
  YYSYMBOL_compound_statement = 55,        /* compound_statement  */
  YYSYMBOL_block = 56,                     /* block  */
  YYSYMBOL_item = 57,                      /* item  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_63_10 = 63,                     /* $@10  */
  YYSYMBOL_64_11 = 64,                     /* $@11  */
  YYSYMBOL_65_12 = 65,                     /* $@12  */
  YYSYMBOL_else = 66,                      /* else  */
  YYSYMBOL_67_13 = 67,                     /* $@13  */
  YYSYMBOL_condition = 68,                 /* condition  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_70_14 = 70,                     /* $@14  */
  YYSYMBOL_71_15 = 71,                     /* $@15  */
  YYSYMBOL_72_16 = 72,                     /* $@16  */
  YYSYMBOL_73_17 = 73,                     /* $@17  */
  YYSYMBOL_74_18 = 74,                     /* $@18  */
  YYSYMBOL_75_19 = 75,                     /* $@19  */
  YYSYMBOL_init = 76,                      /* init  */
  YYSYMBOL_expression = 77,                /* expression  */
  YYSYMBOL_arithmetic = 78,                /* arithmetic  */
  YYSYMBOL_relop = 79,                     /* relop  */
  YYSYMBOL_value = 80,                     /* value  */
  YYSYMBOL_argument_expression_section = 81, /* argument_expression_section  */
  YYSYMBOL_arguments_expression = 82,      /* arguments_expression  */
  YYSYMBOL_return = 83,                    /* return  */
  YYSYMBOL_84_20 = 84,                     /* $@20  */
  YYSYMBOL_85_21 = 85                      /* $@21  */
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
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

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
       0,   142,   142,   149,   152,   158,   164,   164,   174,   178,
     174,   189,   192,   198,   201,   201,   209,   215,   224,   229,
     233,   238,   245,   251,   254,   260,   264,   266,   260,   277,
     281,   277,   289,   293,   295,   289,   305,   308,   314,   314,
     318,   324,   354,   357,   363,   363,   378,   378,   390,   390,
     397,   405,   405,   425,   442,   442,   454,   454,   472,   478,
     487,   499,   508,   511,   514,   517,   523,   527,   531,   535,
     539,   543,   550,   559,   568,   577,   588,   609,   620,   630,
     660,   677,   681,   688,   694,   703,   703,   709,   709
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
  "declarations", "declaration", "function_definition", "$@1",
  "function_declaration", "$@2", "$@3", "arguments_definition_section",
  "arguments_definition", "$@4", "argument_definition", "datatype",
  "compound_statement", "block", "item", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "$@12", "else", "$@13", "condition", "statement", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "init", "expression",
  "arithmetic", "relop", "value", "argument_expression_section",
  "arguments_expression", "return", "$@20", "$@21", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-88)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -76,   -76,   -76,   -76,     4,    74,   -76,   -76,   -76,
     -22,   -76,   -76,   -26,   -76,    18,   -76,   -11,   -27,   -76,
     -76,   -76,    11,   -76,    -2,    31,     8,   -76,    -1,   -76,
     -76,    77,     9,    30,    34,    36,    77,    37,    77,    25,
      33,    40,    44,   -76,   -76,   -76,    74,    77,    54,   -76,
     -76,     1,   -76,    65,    59,   -76,    47,    63,    63,    88,
     -76,    77,   -76,    64,    66,    77,    77,   -76,    60,    78,
      70,    85,   -76,    35,   -76,    77,    77,    77,   -76,   -76,
      83,   -76,   -76,    89,   115,    90,   -76,   -76,   -76,   -76,
      86,    77,    93,   -76,    77,   119,    94,    60,    77,   -76,
      77,   -76,   -76,   105,   -76,    92,   111,   106,    63,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,    77,   -76,    77,   119,
     -76,   -76,   107,   -76,   119,   108,    74,   -76,   -76,   -76,
     -76,   110,   -26,   119,   -26,   119,    77,   -76,   -76,   -76,
     -76,   -76,   119,    47,   137,   117,   -76,   -76,   -76,   -26,
     -26,   -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    19,    20,    21,     0,     2,     3,     5,     6,
       0,     1,     4,     0,     8,     0,     7,     0,    85,    25,
      29,    32,     0,    54,    48,     0,     0,    23,     0,    37,
       9,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,    44,    22,    24,    36,    12,     0,     0,    72,
      73,    75,    74,     0,     0,    88,     0,     0,     0,     0,
      61,     0,    83,     0,    81,     0,     0,    46,    59,     0,
       0,    11,    13,     0,    80,     0,    82,     0,    77,    86,
       0,    42,    43,     0,     0,     0,    62,    63,    65,    64,
       0,     0,     0,    53,     0,    49,     0,    59,     0,    45,
       0,    10,    14,     0,    16,     0,     0,     0,     0,    30,
      66,    67,    68,    69,    70,    71,     0,    33,     0,    60,
      55,    84,     0,    47,    58,     0,     0,    17,    78,    76,
      79,     0,     0,    41,     0,    50,     0,    57,    15,    26,
      31,    34,    52,     0,    40,     0,    38,    35,    27,     0,
       0,    39,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   144,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,    26,     0,   -75,   -76,   125,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -53,   -54,   -76,
     -76,   -76,   -76,   -76,   -76,    56,   -35,   -76,   -76,   -28,
      79,   -76,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    13,     9,    17,    46,    70,
      71,   126,    72,    25,    16,    26,    27,    33,   143,   150,
      34,   132,    35,   134,   144,   147,   149,    83,    28,    68,
      97,    39,    40,    37,    69,    99,    84,    91,   116,    60,
      63,    64,    29,    31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    59,    80,    54,    11,    85,    10,    14,    15,   -87,
      62,     1,     2,     3,     4,    18,    19,    20,    21,    74,
      30,     1,     2,     3,     4,    18,    19,    20,    21,    38,
      95,    22,    76,    92,    23,    45,   -51,    24,    96,    77,
     105,    22,    36,    43,    23,    55,    73,    24,    62,   107,
       1,     2,     3,     4,    41,   131,   119,   140,   103,   141,
      42,    56,    65,   124,   104,    57,   121,    58,    61,    67,
      22,    66,   125,    23,   151,   152,    24,     1,     2,     3,
       4,   133,   -56,   135,    47,    75,    48,    81,    82,   145,
      49,    50,    51,    52,    78,    79,    93,    98,    47,    94,
      48,   142,   101,    53,    49,    50,    51,    52,    86,    87,
      88,    89,    86,    87,    88,    89,   100,    53,   102,   108,
      90,   109,   117,   118,   128,   120,    73,   110,   111,   112,
     113,   114,   115,   122,   127,    86,    87,    88,    89,    86,
      87,    88,    89,   129,   136,   130,   139,   137,   146,   148,
      12,    44,   138,   123,     0,   106
};

static const yytype_int16 yycheck[] =
{
       0,    36,    56,    31,     0,    58,     6,    29,    34,    36,
      38,     3,     4,     5,     6,     7,     8,     9,    10,    47,
      31,     3,     4,     5,     6,     7,     8,     9,    10,    31,
      65,    23,    31,    61,    26,    36,    38,    29,    66,    38,
      75,    23,    31,    35,    26,    36,    46,    29,    76,    77,
       3,     4,     5,     6,    23,   108,    91,   132,    23,   134,
      29,    31,    37,    98,    29,    31,    94,    31,    31,    29,
      23,    38,   100,    26,   149,   150,    29,     3,     4,     5,
       6,   116,    38,   118,    21,    31,    23,    24,    25,   143,
      27,    28,    29,    30,    29,    36,    32,    37,    21,    33,
      23,   136,    32,    40,    27,    28,    29,    30,    20,    21,
      22,    23,    20,    21,    22,    23,    38,    40,    33,    36,
      32,    32,    32,    37,    32,    32,   126,    12,    13,    14,
      15,    16,    17,    39,    29,    20,    21,    22,    23,    20,
      21,    22,    23,    32,    37,    39,    36,    39,    11,    32,
       6,    26,   126,    97,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    42,    43,    44,    45,    47,
      54,     0,    44,    46,    29,    34,    55,    48,     7,     8,
       9,    10,    23,    26,    29,    54,    56,    57,    69,    83,
      31,    84,    85,    58,    61,    63,    31,    74,    31,    72,
      73,    23,    29,    35,    57,    36,    49,    21,    23,    27,
      28,    29,    30,    40,    80,    36,    31,    31,    31,    77,
      80,    31,    80,    81,    82,    37,    38,    29,    70,    75,
      50,    51,    53,    54,    80,    31,    31,    38,    29,    36,
      69,    24,    25,    68,    77,    68,    20,    21,    22,    23,
      32,    78,    80,    32,    33,    77,    80,    71,    37,    76,
      38,    32,    33,    23,    29,    77,    81,    80,    36,    32,
      12,    13,    14,    15,    16,    17,    79,    32,    37,    77,
      32,    80,    39,    76,    77,    80,    52,    29,    32,    32,
      39,    68,    62,    77,    64,    77,    37,    39,    53,    36,
      55,    55,    77,    59,    65,    69,    11,    66,    32,    67,
      60,    55,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    46,    45,    48,    49,
      47,    50,    50,    51,    52,    51,    53,    53,    54,    54,
      54,    54,    55,    56,    56,    58,    59,    60,    57,    61,
      62,    57,    63,    64,    65,    57,    57,    57,    67,    66,
      66,    68,    68,    68,    70,    69,    71,    69,    72,    69,
      69,    73,    69,    69,    74,    69,    75,    69,    76,    76,
      77,    77,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    82,    82,    84,    83,    85,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     0,     3,     0,     0,
       7,     1,     0,     1,     0,     4,     2,     3,     1,     1,
       1,     1,     3,     1,     2,     0,     0,     0,    12,     0,
       0,     7,     0,     0,     0,     9,     2,     1,     0,     3,
       0,     3,     1,     1,     0,     4,     0,     5,     0,     4,
       6,     0,     7,     4,     0,     5,     0,     6,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     4,     4,
       2,     1,     0,     1,     3,     0,     4,     0,     3
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
#line 142 "parser.y"
                   {
        (yyval.nd_obj).nd = mknode(NULL, (yyvsp[0].nd_obj).nd, "program");
        head = (yyval.nd_obj).nd;
      }
#line 1484 "y.tab.c"
    break;

  case 3: /* declarations: declaration  */
#line 149 "parser.y"
                  {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "declarations");
      }
#line 1492 "y.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 152 "parser.y"
                               {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "declarations");
      }
#line 1500 "y.tab.c"
    break;

  case 5: /* declaration: function_definition  */
#line 158 "parser.y"
                          {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1508 "y.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 164 "parser.y"
                           {
        sprintf(icg[ic_idx++], " nounwind uwtable {\nentry:\n");
      }
#line 1516 "y.tab.c"
    break;

  case 7: /* function_definition: function_declaration $@1 compound_statement  */
#line 166 "parser.y"
                           {
        sprintf(icg[ic_idx++], "}\n");
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "function_definition");
        end_of_scope();
      }
#line 1526 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 174 "parser.y"
                  {
        add_to_table('F', (yyvsp[0].nd_obj).name);
        sprintf(icg[ic_idx++], "\ndefine %s @%s", (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj).name);
      }
#line 1535 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 178 "parser.y"
          {
        sprintf(icg[ic_idx++], "(");
        new_scope();
      }
#line 1544 "y.tab.c"
    break;

  case 10: /* function_declaration: datatype ID $@2 '(' $@3 arguments_definition_section ')'  */
#line 182 "parser.y"
                                       {
        sprintf(icg[ic_idx++], ")");
        (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-5].nd_obj).name);
      }
#line 1553 "y.tab.c"
    break;

  case 11: /* arguments_definition_section: arguments_definition  */
#line 189 "parser.y"
                           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "arguments_definition_section");
      }
#line 1561 "y.tab.c"
    break;

  case 12: /* arguments_definition_section: %empty  */
#line 192 "parser.y"
      {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "arguments_definition_section");
      }
#line 1569 "y.tab.c"
    break;

  case 13: /* arguments_definition: argument_definition  */
#line 198 "parser.y"
                          {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "arguments_definition");
      }
#line 1577 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 201 "parser.y"
                               {
        sprintf(icg[ic_idx++], ", ");
      }
#line 1585 "y.tab.c"
    break;

  case 15: /* arguments_definition: arguments_definition ',' $@4 argument_definition  */
#line 203 "parser.y"
                            {
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj).nd, "arguments_definition");
      }
#line 1593 "y.tab.c"
    break;

  case 16: /* argument_definition: datatype ID  */
#line 209 "parser.y"
                  {
        add_to_table('A', (yyvsp[0].nd_obj).name);
        sprintf(icg[ic_idx++], "%s %%%s", (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj).name);
        (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "argument_definition");
      }
#line 1604 "y.tab.c"
    break;

  case 17: /* argument_definition: datatype MUL ID  */
#line 215 "parser.y"
                      {
        add_to_table('P', (yyvsp[0].nd_obj).name);
        sprintf(icg[ic_idx++], "%s* %%%s", (yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj).name);
        (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "argument_definition");
      }
#line 1615 "y.tab.c"
    break;

  case 18: /* datatype: INT  */
#line 224 "parser.y"
          {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "i32");
      }
#line 1625 "y.tab.c"
    break;

  case 19: /* datatype: FLOAT  */
#line 229 "parser.y"
            {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1634 "y.tab.c"
    break;

  case 20: /* datatype: CHAR  */
#line 233 "parser.y"
           {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "i8");
      }
#line 1644 "y.tab.c"
    break;

  case 21: /* datatype: VOID  */
#line 238 "parser.y"
           {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1653 "y.tab.c"
    break;

  case 22: /* compound_statement: '{' block '}'  */
#line 245 "parser.y"
                    {
        (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
      }
#line 1661 "y.tab.c"
    break;

  case 23: /* block: item  */
#line 251 "parser.y"
           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "block");
      }
#line 1669 "y.tab.c"
    break;

  case 24: /* block: block item  */
#line 254 "parser.y"
                 {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "block");
      }
#line 1677 "y.tab.c"
    break;

  case 25: /* $@5: %empty  */
#line 260 "parser.y"
          {
        add_to_table('K', (yyvsp[0].nd_obj).name);
        new_scope();
        is_for = 1;
      }
#line 1687 "y.tab.c"
    break;

  case 26: /* $@6: %empty  */
#line 264 "parser.y"
                                        {
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-1].nd_obj3).increment_body);
      }
#line 1695 "y.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 266 "parser.y"
                      {
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", (yyvsp[-4].nd_obj3).else_body);
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-4].nd_obj3).if_body);
      }
#line 1704 "y.tab.c"
    break;

  case 28: /* item: FOR $@5 '(' statement ';' condition ';' $@6 statement ')' $@7 compound_statement  */
#line 269 "parser.y"
                           {
        struct node *temp = mknode((yyvsp[-6].nd_obj3).nd, (yyvsp[-3].nd_obj).nd, "CONDITION");
        struct node *temp2 = mknode((yyvsp[-8].nd_obj).nd, temp, "CONDITION");
        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj).nd, (yyvsp[-11].nd_obj).name);
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", (yyvsp[-6].nd_obj3).increment_body);
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-6].nd_obj3).next_body);
        end_of_scope();
      }
#line 1717 "y.tab.c"
    break;

  case 29: /* $@8: %empty  */
#line 277 "parser.y"
            {
        add_to_table('K', (yyvsp[0].nd_obj).name);
        new_scope();
        is_for = 1;
      }
#line 1727 "y.tab.c"
    break;

  case 30: /* $@9: %empty  */
#line 281 "parser.y"
                          {
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-1].nd_obj3).if_body);
      }
#line 1735 "y.tab.c"
    break;

  case 31: /* item: WHILE $@8 '(' condition ')' $@9 compound_statement  */
#line 283 "parser.y"
                           {
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj3).nd, (yyvsp[0].nd_obj).nd, (yyvsp[-6].nd_obj).name);
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", (yyvsp[-3].nd_obj3).else_body);
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-3].nd_obj3).next_body);
        end_of_scope();
      }
#line 1746 "y.tab.c"
    break;

  case 32: /* $@10: %empty  */
#line 289 "parser.y"
         {
        add_to_table('K', (yyvsp[0].nd_obj).name);
        new_scope();
        is_for = 0;
      }
#line 1756 "y.tab.c"
    break;

  case 33: /* $@11: %empty  */
#line 293 "parser.y"
                          {
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-1].nd_obj3).if_body);
      }
#line 1764 "y.tab.c"
    break;

  case 34: /* $@12: %empty  */
#line 295 "parser.y"
                           {
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", (yyvsp[-3].nd_obj3).next_body);
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-3].nd_obj3).else_body);
      }
#line 1773 "y.tab.c"
    break;

  case 35: /* item: IF $@10 '(' condition ')' $@11 compound_statement $@12 else  */
#line 298 "parser.y"
             {
        struct node *iff = mknode((yyvsp[-5].nd_obj3).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-8].nd_obj).name);
        (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", (yyvsp[-5].nd_obj3).next_body);
        sprintf(icg[ic_idx++], "\n%s:\n", (yyvsp[-5].nd_obj3).next_body);
        end_of_scope();
      }
#line 1785 "y.tab.c"
    break;

  case 36: /* item: statement ';'  */
#line 305 "parser.y"
                    {
        (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
    }
#line 1793 "y.tab.c"
    break;

  case 37: /* item: return  */
#line 308 "parser.y"
             {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1801 "y.tab.c"
    break;

  case 38: /* $@13: %empty  */
#line 314 "parser.y"
           { add_to_table('K', (yyvsp[0].nd_obj).name); new_scope(); }
#line 1807 "y.tab.c"
    break;

  case 39: /* else: ELSE $@13 compound_statement  */
#line 314 "parser.y"
                                                                           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[-2].nd_obj).name);
        end_of_scope();
      }
#line 1816 "y.tab.c"
    break;

  case 40: /* else: %empty  */
#line 318 "parser.y"
      {
        (yyval.nd_obj).nd = NULL;
      }
#line 1824 "y.tab.c"
    break;

  case 41: /* condition: expression relop expression  */
#line 324 "parser.y"
                                  {
        (yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
        char *loaded_var_1;
        char *loaded_var_2;
        if (is_for) {
            sprintf((yyval.nd_obj3).else_body, "L%d", label++);
            sprintf(icg[ic_idx++], "\tbr label %%%s\n", (yyval.nd_obj3).else_body);
            sprintf(icg[ic_idx++], "\n%s:\n", (yyval.nd_obj3).else_body);
            sprintf((yyval.nd_obj3).if_body, "L%d", label);
            loaded_var_1 = load_from_pointer((yyvsp[-2].nd_obj2).name, (yyvsp[-2].nd_obj2).type, (yyvsp[-2].nd_obj2).datatype);
            loaded_var_2 = load_from_pointer((yyvsp[0].nd_obj2).name, (yyvsp[0].nd_obj2).type, (yyvsp[0].nd_obj2).datatype);
            sprintf(icg[ic_idx++], "\t%%t%d = icmp %s %s %s, %s\n", temp_var, (yyvsp[-1].nd_obj).name, (yyvsp[-2].nd_obj2).datatype, loaded_var_1, loaded_var_2);
            sprintf(icg[ic_idx++], "\tbr i1 %%t%d, label %%L%d, label %%L%d\n", temp_var, label, label + 1);
            temp_var++;
            label++;
            sprintf((yyval.nd_obj3).next_body, "L%d", label++);
            sprintf((yyval.nd_obj3).increment_body, "L%d", label++);
        } else {
            loaded_var_1 = load_from_pointer((yyvsp[-2].nd_obj2).name, (yyvsp[-2].nd_obj2).type, (yyvsp[-2].nd_obj2).datatype);
            loaded_var_2 = load_from_pointer((yyvsp[0].nd_obj2).name, (yyvsp[0].nd_obj2).type, (yyvsp[0].nd_obj2).datatype);
            sprintf(icg[ic_idx++], "\t%%t%d = icmp %s %s %s, %s\n", temp_var, (yyvsp[-1].nd_obj).name, (yyvsp[-2].nd_obj2).datatype, loaded_var_1, loaded_var_2);
            sprintf(icg[ic_idx++], "\tbr i1 %%t%d, label %%L%d, label %%L%d\n", temp_var, label, label + 1);
            temp_var++;
            sprintf((yyval.nd_obj3).if_body, "L%d", label++);
            sprintf((yyval.nd_obj3).else_body, "L%d", label++);
            sprintf((yyval.nd_obj3).next_body, "L%d", label++);
        }
        free(loaded_var_1);
        free(loaded_var_2);
      }
#line 1859 "y.tab.c"
    break;

  case 42: /* condition: TRUE  */
#line 354 "parser.y"
           { add_to_table('K', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj3).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1867 "y.tab.c"
    break;

  case 43: /* condition: FALSE  */
#line 357 "parser.y"
            { add_to_table('K', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj3).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1875 "y.tab.c"
    break;

  case 44: /* $@14: %empty  */
#line 363 "parser.y"
                  {
        add_to_table('V', (yyvsp[0].nd_obj).name);
        sprintf(icg[ic_idx++], "\t%%%s = alloca %s\n", (yyvsp[0].nd_obj).name, (yyvsp[-1].nd_obj).name);
      }
#line 1884 "y.tab.c"
    break;

  case 45: /* statement: datatype ID $@14 init  */
#line 366 "parser.y"
             {
        (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
        int type_exception = check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).datatype);
        if (!strcmp((yyvsp[0].nd_obj2).type, "Pointer")) {
            sprintf(warnings[sem_warnings], "Line %d: assigning pointer to non-pointer variable.\n", count_n);
            sem_warnings++;
        }
        (yyval.nd_obj).nd = handle_type_cast(type_exception, (yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "definition");
        if (strcmp((yyvsp[0].nd_obj2).name, "NULL")) {
            sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%%s\n", (yyvsp[0].nd_obj2).datatype, (yyvsp[0].nd_obj2).name, (yyvsp[-3].nd_obj).name, (yyvsp[-2].nd_obj).name);
        }
      }
#line 1901 "y.tab.c"
    break;

  case 46: /* $@15: %empty  */
#line 378 "parser.y"
                      {
        add_to_table('P', (yyvsp[0].nd_obj).name);
        sprintf(icg[ic_idx++], "\t%%%s = alloca %s*\n", (yyvsp[0].nd_obj).name, (yyvsp[-2].nd_obj).name);
      }
#line 1910 "y.tab.c"
    break;

  case 47: /* statement: datatype MUL ID $@15 init  */
#line 381 "parser.y"
             {
        check_pointer_types((yyvsp[-4].nd_obj).name, (yyvsp[0].nd_obj2).datatype, (yyvsp[0].nd_obj2).type);
        struct node *id = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
        struct node *pointer = mknode((yyvsp[-4].nd_obj).nd, id, "pointer_name");
        (yyval.nd_obj).nd = mknode(pointer, (yyvsp[0].nd_obj2).nd, "pointer_definition");
        if (strcmp((yyvsp[0].nd_obj2).name, "NULL")) {
            sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%%s\n", (yyvsp[0].nd_obj2).datatype, (yyvsp[0].nd_obj2).name, (yyvsp[-4].nd_obj).name, (yyvsp[-2].nd_obj).name);
        }
      }
#line 1924 "y.tab.c"
    break;

  case 48: /* $@16: %empty  */
#line 390 "parser.y"
         { check_declaration((yyvsp[0].nd_obj).name); }
#line 1930 "y.tab.c"
    break;

  case 49: /* statement: ID $@16 '=' expression  */
#line 390 "parser.y"
                                                        {
        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[-3].nd_obj).name);
        int type_exception = check_types(id_datatype, (yyvsp[0].nd_obj2).datatype);
        (yyval.nd_obj).nd = handle_type_cast(type_exception, (yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "assignement");
        sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%%s\n", get_datatype((yyvsp[-3].nd_obj).name), (yyvsp[0].nd_obj2).name, get_datatype((yyvsp[-3].nd_obj).name), (yyvsp[-3].nd_obj).name);
      }
#line 1942 "y.tab.c"
    break;

  case 50: /* statement: MUL '(' expression ')' '=' expression  */
#line 397 "parser.y"
                                            {
        if (strcmp((yyvsp[-3].nd_obj2).type, "Pointer") || strcmp((yyvsp[-3].nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype)) {
            sprintf(warnings[sem_warnings], "Line %d: implicit cast to pointer.\n", count_n);
            sem_warnings++;
        }
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "dereference_assignement");
        sprintf(icg[ic_idx++], "\tstore %s %s, %s** %s\n", (yyvsp[0].nd_obj2).datatype, (yyvsp[0].nd_obj2).name, (yyvsp[-3].nd_obj2).datatype, (yyvsp[-3].nd_obj2).name);
      }
#line 1955 "y.tab.c"
    break;

  case 51: /* $@17: %empty  */
#line 405 "parser.y"
         { check_declaration((yyvsp[0].nd_obj).name); }
#line 1961 "y.tab.c"
    break;

  case 52: /* statement: ID $@17 '[' value ']' '=' expression  */
#line 405 "parser.y"
                                                                      {
    // TODO: tady všude chybí předání name, atd dovyšších pater
        const char *id_datatype = get_datatype((yyvsp[-6].nd_obj).name);
        const char *id_type = get_type((yyvsp[-6].nd_obj).name);
        if (strcmp(id_type, "Pointer") || strcmp(id_datatype, (yyvsp[0].nd_obj2).datatype)) {
            sprintf(warnings[sem_warnings], "Line %d: implicit cast.\n", count_n);
            sem_warnings++;
        }
        struct node *dereference = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-3].nd_obj4).nd, "dereference");
        (yyval.nd_obj).nd = mknode(dereference, (yyvsp[0].nd_obj2).nd, "dereference_assignement");
        char *loaded_value = load_from_pointer((yyvsp[-3].nd_obj4).icg_result, (yyvsp[-3].nd_obj4).type, (yyvsp[-3].nd_obj4).datatype);
        int array_size = get_array_size((yyvsp[-6].nd_obj).name);
        int new_temp_var = temp_var++;
        sprintf(icg[ic_idx++], "\t%%t%d = getelementptr inbounds [%d x %s], [%d x %s]* %%%s, %s 0, %s %s\n", new_temp_var, array_size, id_datatype, array_size, id_datatype, (yyvsp[-6].nd_obj).name, (yyvsp[0].nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype, loaded_value);
        free(loaded_value);
        char *loaded_expression = load_from_pointer((yyvsp[0].nd_obj2).name, (yyvsp[0].nd_obj2).type, (yyvsp[0].nd_obj2).datatype);
        sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%t%d\n", (yyvsp[0].nd_obj2).datatype, loaded_expression, id_datatype, new_temp_var);
        free(loaded_expression);
        temp_var++;
      }
#line 1986 "y.tab.c"
    break;

  case 53: /* statement: ID '(' argument_expression_section ')'  */
#line 425 "parser.y"
                                              { //TODO udělat specialní kategorii function_application a neduplikovat
        check_declaration((yyvsp[-3].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[-3].nd_obj).name);
        const char *id_type = get_type((yyvsp[-3].nd_obj).name);
        if (strcmp(id_type, "Function")) {
            sprintf(errors[sem_errors], "Line %d: Name \"%s\" is not a function!\n", count_n, (yyvsp[-3].nd_obj).name);
            sem_errors++;
        }
        strcpy((yyval.nd_obj).name, (yyvsp[-3].nd_obj).name);
        if (!strcmp(get_datatype((yyvsp[-3].nd_obj).name), "void")) {
            sprintf(icg[ic_idx++], "call %s @%s(%s)", get_datatype((yyvsp[-3].nd_obj).name), (yyvsp[-3].nd_obj).name, (yyvsp[-1].nd_obj4).icg_result);
        } else {
            sprintf(icg[ic_idx++], "\t%%t%d = call %s @%s(%s)", temp_var, get_datatype((yyvsp[-3].nd_obj).name), (yyvsp[-3].nd_obj).name, (yyvsp[-1].nd_obj4).icg_result);
            temp_var++;
        }
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj4).nd, NULL, (yyvsp[-3].nd_obj).name);
      }
#line 2008 "y.tab.c"
    break;

  case 54: /* $@18: %empty  */
#line 442 "parser.y"
              { add_to_table('K', (yyvsp[0].nd_obj).name); }
#line 2014 "y.tab.c"
    break;

  case 55: /* statement: PUTCHAR $@18 '(' value ')'  */
#line 442 "parser.y"
                                                            {
        if (strcmp((yyvsp[-1].nd_obj4).datatype, "i8")) {
            sprintf(errors[sem_errors], "Line %d: putchar accepts char.\n", count_n);
            sem_errors++;
        }
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj4).nd, NULL, (yyvsp[-4].nd_obj).name);
        char *loaded_var = load_from_pointer((yyvsp[-1].nd_obj4).icg_result, (yyvsp[-1].nd_obj4).type, (yyvsp[-1].nd_obj4).datatype);
        sprintf(icg[ic_idx++], "\t%%t%d = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0\n", temp_var);
        sprintf(icg[ic_idx++], "\tcall i32 (i8*, ...) @printf(i8* %%t%d, i8 %s)\n", temp_var, loaded_var);
        free(loaded_var);
        temp_var++;
      }
#line 2031 "y.tab.c"
    break;

  case 56: /* $@19: %empty  */
#line 454 "parser.y"
                  { add_to_table('P', (yyvsp[0].nd_obj).name); }
#line 2037 "y.tab.c"
    break;

  case 57: /* statement: datatype ID $@19 '[' value ']'  */
#line 454 "parser.y"
                                                                {
        set_array_size((yyvsp[-4].nd_obj).name, atoi((yyvsp[-1].nd_obj4).name));
        if (strcmp((yyvsp[-1].nd_obj4).datatype, "i32")) {
            sprintf(errors[sem_errors], "Line %d: array position qualificator needs to be int.\n", count_n);
            sem_errors++;
        }
        if (strcmp(get_type((yyvsp[-4].nd_obj).name), "Pointer")) {
            sprintf(errors[sem_errors], "Line %d: array qualificator not used to pointer. %s %s\n", count_n, get_type((yyvsp[-4].nd_obj).name), "Pointer");
            sem_errors++;
        }
        struct node *id = mknode(NULL, NULL, (yyvsp[-4].nd_obj).name);
        struct node *pointer = mknode((yyvsp[-5].nd_obj).nd, id, "pointer_name");
        (yyval.nd_obj).nd = mknode(pointer, (yyvsp[-1].nd_obj4).nd, "array");
        sprintf(icg[ic_idx++], "\t%%%s = alloca [%s x %s]\n", (yyvsp[-4].nd_obj).name, (yyvsp[-1].nd_obj4).name, (yyvsp[-5].nd_obj).name);
      }
#line 2057 "y.tab.c"
    break;

  case 58: /* init: '=' expression  */
#line 472 "parser.y"
                     {
        (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd;
        strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name);
      }
#line 2068 "y.tab.c"
    break;

  case 59: /* init: %empty  */
#line 478 "parser.y"
      {
        (yyval.nd_obj2).nd = mknode(NULL, NULL, "NULL");
        strcpy((yyval.nd_obj2).type, "null");
        strcpy((yyval.nd_obj2).datatype, "null");
        strcpy((yyval.nd_obj2).name, "NULL");
      }
#line 2079 "y.tab.c"
    break;

  case 60: /* expression: expression arithmetic expression  */
#line 487 "parser.y"
                                       {
        int type_exception = check_types((yyvsp[-2].nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype);
        (yyval.nd_obj2).nd = handle_type_cast(type_exception, (yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
        strcpy((yyval.nd_obj2).type, (yyvsp[-2].nd_obj2).type);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[-2].nd_obj2).datatype);
        sprintf((yyval.nd_obj2).name, "%%t%d", temp_var++);
        char *loaded_var_1 = load_from_pointer((yyvsp[-2].nd_obj2).name, (yyvsp[-2].nd_obj2).type, (yyvsp[-2].nd_obj2).datatype);
        char *loaded_var_2 = load_from_pointer((yyvsp[0].nd_obj2).name, (yyvsp[0].nd_obj2).type, (yyvsp[0].nd_obj2).datatype);
        sprintf(icg[ic_idx++], "\t%s = %s %s %s, %s\n",  (yyval.nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[-2].nd_obj2).datatype, loaded_var_1, loaded_var_2);
        free(loaded_var_1);
        free(loaded_var_2);
      }
#line 2096 "y.tab.c"
    break;

  case 61: /* expression: value  */
#line 499 "parser.y"
            {
        (yyval.nd_obj2).nd = (yyvsp[0].nd_obj4).nd;
        strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj4).type);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[0].nd_obj4).datatype);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj4).icg_result);
      }
#line 2107 "y.tab.c"
    break;

  case 62: /* arithmetic: ADD  */
#line 508 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 2115 "y.tab.c"
    break;

  case 63: /* arithmetic: SUB  */
#line 511 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 2123 "y.tab.c"
    break;

  case 64: /* arithmetic: MUL  */
#line 514 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 2131 "y.tab.c"
    break;

  case 65: /* arithmetic: DIV  */
#line 517 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 2139 "y.tab.c"
    break;

  case 66: /* relop: LT  */
#line 523 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "slt");
      }
#line 2148 "y.tab.c"
    break;

  case 67: /* relop: GT  */
#line 527 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "sgt");
      }
#line 2157 "y.tab.c"
    break;

  case 68: /* relop: LE  */
#line 531 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "sle");
      }
#line 2166 "y.tab.c"
    break;

  case 69: /* relop: GE  */
#line 535 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "sge");
      }
#line 2175 "y.tab.c"
    break;

  case 70: /* relop: EQ  */
#line 539 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "eq");
      }
#line 2184 "y.tab.c"
    break;

  case 71: /* relop: NE  */
#line 543 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj).name, "ne");
      }
#line 2193 "y.tab.c"
    break;

  case 72: /* value: NUMBER  */
#line 550 "parser.y"
             {
        insert_datatype("i32");
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj4).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).icg_result, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).type, "Constant");
        strcpy((yyval.nd_obj4).datatype, "i32");
      }
#line 2207 "y.tab.c"
    break;

  case 73: /* value: FLOAT_NUM  */
#line 559 "parser.y"
                {
        insert_datatype("float");
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj4).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).icg_result, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).type, "Constant");
        strcpy((yyval.nd_obj4).datatype, "float");
      }
#line 2221 "y.tab.c"
    break;

  case 74: /* value: CHARACTER  */
#line 568 "parser.y"
                {
        insert_datatype("i8");
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj4).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).name, (yyvsp[0].nd_obj).name);
        sprintf((yyval.nd_obj4).icg_result, "%d", (int) (yyvsp[0].nd_obj).name[1]);
        strcpy((yyval.nd_obj4).type, "Constant");
        strcpy((yyval.nd_obj4).datatype, "i8");
      }
#line 2235 "y.tab.c"
    break;

  case 75: /* value: ID  */
#line 577 "parser.y"
         {
        check_declaration((yyvsp[0].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).datatype, id_datatype);
        const char *id_type = get_type((yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).type, id_type);
        strcpy((yyval.nd_obj4).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).icg_result, "%");
        strcat((yyval.nd_obj4).icg_result, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj4).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 2251 "y.tab.c"
    break;

  case 76: /* value: ID '(' argument_expression_section ')'  */
#line 588 "parser.y"
                                             {
        check_declaration((yyvsp[-3].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[-3].nd_obj).name);
        strcpy((yyval.nd_obj4).datatype, id_datatype);
        const char *id_type = get_type((yyvsp[-3].nd_obj).name);
        if (strcmp(id_type, "Function")) {
            sprintf(errors[sem_errors], "Line %d: Name \"%s\" is not a function!\n", count_n, (yyvsp[-3].nd_obj).name);
            sem_errors++;
        }
        strcpy((yyval.nd_obj4).type, id_type);
        strcpy((yyval.nd_obj4).name, (yyvsp[-3].nd_obj).name);
        if (!strcmp(get_datatype((yyvsp[-3].nd_obj).name), "void")) {
            sprintf(icg[ic_idx++], "call %s @%s(%s)", get_datatype((yyvsp[-3].nd_obj).name), (yyvsp[-3].nd_obj).name, (yyvsp[-1].nd_obj4).icg_result);
            strcpy((yyval.nd_obj4).icg_result, "");
        } else {
            sprintf(icg[ic_idx++], "\t%%t%d = call %s @%s(%s)", temp_var, get_datatype((yyvsp[-3].nd_obj).name), (yyvsp[-3].nd_obj).name, (yyvsp[-1].nd_obj4).icg_result);
            sprintf((yyval.nd_obj4).icg_result, "%%t%d", temp_var);
            temp_var++;
        }
        (yyval.nd_obj4).nd = mknode((yyvsp[-1].nd_obj4).nd, NULL, (yyvsp[-3].nd_obj).name);
      }
#line 2277 "y.tab.c"
    break;

  case 77: /* value: '&' ID  */
#line 609 "parser.y"
             {
        strcpy((yyval.nd_obj4).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).icg_result, "* %");
        strcat((yyval.nd_obj4).icg_result, (yyvsp[0].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj4).datatype, id_datatype);
        strcpy((yyval.nd_obj4).type, "Pointer");
        check_declaration((yyvsp[0].nd_obj).name);
        struct node *id = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj4).nd = mknode(id, NULL, "address");
      }
#line 2293 "y.tab.c"
    break;

  case 78: /* value: MUL '(' expression ')'  */
#line 620 "parser.y"
                             {
        strcpy((yyval.nd_obj4).name, (yyvsp[-1].nd_obj2).name);
        char *loaded_var = load_from_pointer((yyvsp[-1].nd_obj2).name, (yyvsp[-1].nd_obj2).type, (yyvsp[-1].nd_obj2).datatype);
        sprintf((yyval.nd_obj4).icg_result, "%s", loaded_var);
        free(loaded_var);

        strcpy((yyval.nd_obj4).datatype, (yyvsp[-1].nd_obj2).datatype);
        strcpy((yyval.nd_obj4).type, "Variable");
        (yyval.nd_obj4).nd = mknode((yyvsp[-1].nd_obj2).nd, NULL, "dereference");
      }
#line 2308 "y.tab.c"
    break;

  case 79: /* value: ID '[' value ']'  */
#line 630 "parser.y"
                       {
        check_declaration((yyvsp[-3].nd_obj).name);
        // check id
        const char *id_datatype = get_datatype((yyvsp[-3].nd_obj).name);
        const char *id_type = get_type((yyvsp[-3].nd_obj).name);
        if (strcmp(id_type, "Pointer")) {
            sprintf(errors[sem_errors], "Line %d: Name \"%s\" is not a pointer!\n", count_n, (yyvsp[-3].nd_obj).name);
            sem_errors++;
        }
        int array_size = get_array_size((yyvsp[-3].nd_obj).name);
        // check value TODO
        const char *value_datatype = get_datatype((yyvsp[-1].nd_obj4).name);
        const char *value_type = get_type((yyvsp[-1].nd_obj4).name);
        // get pointer to array field
        char *loaded_value = load_from_pointer((yyvsp[-1].nd_obj4).icg_result, (yyvsp[-1].nd_obj4).type, (yyvsp[-1].nd_obj4).datatype);
        sprintf(icg[ic_idx++], "\t%%t%d = getelementptr inbounds [%d x %s], [%d x %s]* %%%s, %s 0, %s %s\n", temp_var, array_size, id_datatype, array_size, id_datatype, (yyvsp[-3].nd_obj).name, value_datatype, value_datatype, loaded_value);
        free(loaded_value);
        // load
        char new_ptr[5];
        sprintf(new_ptr, "%%t%d", temp_var);
         temp_var++;
        sprintf(icg[ic_idx++], "\t%%t%d = load %s, %s* %s\n", temp_var, id_datatype, id_datatype, new_ptr);
        // set node vars
        sprintf((yyval.nd_obj4).icg_result, "%%t%d", temp_var);
        sprintf((yyval.nd_obj4).name, "t%d", temp_var);
        strcpy((yyval.nd_obj4).type, "Pointer");
        strcpy((yyval.nd_obj4).datatype, id_datatype);
        temp_var++;
        (yyval.nd_obj4).nd = mknode((yyvsp[-1].nd_obj4).nd, NULL, "array_dereference");
      }
#line 2343 "y.tab.c"
    break;

  case 80: /* value: SUB value  */
#line 660 "parser.y"
                {
        if (strcmp((yyvsp[0].nd_obj4).datatype, "i32") && strcmp((yyvsp[0].nd_obj4).datatype, "float")) {
            sprintf(errors[sem_errors], "Line %d: unary minus on non number type\n", count_n);
            sem_errors++;
        }
        strcpy((yyval.nd_obj4).datatype, (yyvsp[0].nd_obj4).datatype);
        strcpy((yyval.nd_obj4).type, (yyvsp[0].nd_obj4).type);
        (yyval.nd_obj4).nd = mknode((yyvsp[0].nd_obj4).nd, NULL, "unary_minus");
        sprintf((yyval.nd_obj4).name, "t%d", temp_var);
        sprintf((yyval.nd_obj4).icg_result, "%%t%d", temp_var++);
        char *loaded_var = load_from_pointer((yyvsp[0].nd_obj4).icg_result, (yyvsp[0].nd_obj4).type, (yyvsp[0].nd_obj4).datatype);
        sprintf(icg[ic_idx++], "\t%s = sub %s 0, %s\n", (yyval.nd_obj4).icg_result, (yyvsp[0].nd_obj4).datatype, loaded_var);
        free(loaded_var);
      }
#line 2362 "y.tab.c"
    break;

  case 81: /* argument_expression_section: arguments_expression  */
#line 677 "parser.y"
                           {
        (yyval.nd_obj4).nd = (yyvsp[0].nd_obj4).nd;
        strcpy((yyval.nd_obj4).icg_result, (yyvsp[0].nd_obj4).icg_result);
      }
#line 2371 "y.tab.c"
    break;

  case 82: /* argument_expression_section: %empty  */
#line 681 "parser.y"
      {
        (yyval.nd_obj4).nd = NULL;
        strcpy((yyval.nd_obj4).icg_result, "");
      }
#line 2380 "y.tab.c"
    break;

  case 83: /* arguments_expression: value  */
#line 688 "parser.y"
            {
        (yyval.nd_obj4).nd = mknode((yyvsp[0].nd_obj4).nd, NULL, "arguments_expression");
        char *loaded_var = load_from_pointer((yyvsp[0].nd_obj4).icg_result, (yyvsp[0].nd_obj4).type, (yyvsp[0].nd_obj4).datatype);
        sprintf((yyval.nd_obj4).icg_result, "%s %s", (yyvsp[0].nd_obj4).datatype, loaded_var);
        free(loaded_var);
      }
#line 2391 "y.tab.c"
    break;

  case 84: /* arguments_expression: arguments_expression ',' value  */
#line 694 "parser.y"
                                     {
        (yyval.nd_obj4).nd = mknode((yyvsp[-2].nd_obj4).nd, (yyvsp[0].nd_obj4).nd, "arguments_expression");
        char *loaded_var = load_from_pointer((yyvsp[0].nd_obj4).icg_result, (yyvsp[0].nd_obj4).type, (yyvsp[0].nd_obj4).datatype);
        sprintf((yyval.nd_obj4).icg_result, "%s, %s %s", (yyvsp[-2].nd_obj4).icg_result, (yyvsp[0].nd_obj4).datatype, loaded_var);
        free(loaded_var);
      }
#line 2402 "y.tab.c"
    break;

  case 85: /* $@20: %empty  */
#line 703 "parser.y"
             { add_to_table('K', "return"); }
#line 2408 "y.tab.c"
    break;

  case 86: /* return: RETURN $@20 value ';'  */
#line 703 "parser.y"
                                                        {
        check_return_datatype((yyvsp[-1].nd_obj4).name);
        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return");
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj4).nd, "RETURN");
        sprintf(icg[ic_idx++], "\tret %s %s\n",  (yyvsp[-1].nd_obj4).datatype, (yyvsp[-1].nd_obj4).icg_result);
      }
#line 2419 "y.tab.c"
    break;

  case 87: /* $@21: %empty  */
#line 709 "parser.y"
             { add_to_table('K', "return"); }
#line 2425 "y.tab.c"
    break;

  case 88: /* return: RETURN $@21 ';'  */
#line 709 "parser.y"
                                                  {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "RETURN");
        sprintf(icg[ic_idx++], "\tret void\n");
      }
#line 2434 "y.tab.c"
    break;


#line 2438 "y.tab.c"

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

#line 715 "parser.y"


int check_declaration(const char *name) {
    if (search(name)) return 0;
    sprintf(errors[sem_errors], "Line %d: Name \"%s\" not declared before usage!\n", count_n, name);
    sem_errors++;
    return 1;
}

const char *get_type(const char *var) {
  for (int i = 0; i < count; i++) {
      if (!strcmp(symbol_table[i].id_name, var)) {
          return symbol_table[i].type;
      }
  }
  return "null";
}

const char *get_datatype(const char *var) {
  for (int i = 0; i < count; i++) {
      if (!strcmp(symbol_table[i].id_name, var)) {
          return symbol_table[i].datatype;
      }
  }
  return "null";
}

int check_types(const char *type1, const char *type2) {
    // declaration with no init
    if (!strcmp(type2, "null"))
        return -1;
    // both datatypes are same
    if (!strcmp(type1, type2))
        return 0;
    // both datatypes are different
    if (!strcmp(type1, "i32") && !strcmp(type2, "float"))
        return 1;
    if (!strcmp(type1, "float") && !strcmp(type2, "i32"))
        return 2;
    if (!strcmp(type1, "i32") && !strcmp(type2, "i8"))
        return 3;
    if (!strcmp(type1, "i8") && !strcmp(type2, "i32"))
        return 4;
    if (!strcmp(type1, "float") && !strcmp(type2, "i8"))
        return 5;
    if (!strcmp(type1, "i8") && !strcmp(type2, "float"))
        return 6;
    return -2;
}

struct node *handle_type_cast(int type_exception, struct node *left, struct node *right, const char *node_name) {
    if (type_exception > 0) {
        struct node *temp;
        switch (type_exception) {
            case 1:
                sprintf(warnings[sem_warnings], "Line %d: implicit float to int cast\n", count_n);
                temp = mknode(NULL, right, "floattoint");
                break;
            case 2:
                sprintf(warnings[sem_warnings], "Line %d: implicit int to float cast\n", count_n);
                temp = mknode(NULL, right, "inttofloat");
                break;
            case 3:
                sprintf(warnings[sem_warnings], "Line %d: implicit char to int cast\n", count_n);
                temp = mknode(NULL, right, "chartoint");
                break;
            case 4:
                sprintf(warnings[sem_warnings], "Line %d: implicit int to char cast\n", count_n);
                temp = mknode(NULL, right, "inttochar");
                break;
            case 5:
                sprintf(warnings[sem_warnings], "Line %d: implicit char to float cast\n", count_n);
                temp = mknode(NULL, right, "chartofloat");
                break;
            default:
                sprintf(warnings[sem_warnings], "Line %d: implicit float to char cast. %s %s\n", count_n, left->token, right->token);
                temp = mknode(NULL, right, "floattochar");
                break;
        }
        sem_warnings++;
        return mknode(left, temp, node_name);
    }
    return mknode(left, right, node_name);
}

int check_pointer_types(const char *datatype1,
                        const char *datatype2,
                        const char *type2) {
    // declaration with no init
    if (!strcmp(datatype2, "null"))
        return -1;
    // both datatypes are correct
    if ((!strcmp(type2, "Pointer") && !strcmp(datatype1, datatype2)) || (!strcmp(type2, "Constant") && !strcmp("i32", datatype2)))
        return 0;
    // both datatypes are different
    sprintf(errors[sem_errors], "Line %d: attempt to init pointer type with something else then pointer variable with correct type or address.\n", count_n);
    sem_errors++;
    return 1;
}

const char *get_datatype_of_current_function() {
    for (int i = count-1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].type, "Function")) {
            return symbol_table[i].datatype;
        }
    }
}

const char *get_id_of_current_function() {
    for (int i = count - 1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].type, "Function")) {
            return symbol_table[i].id_name;
        }
    }
}

void set_array_size(const char *name, int size) {
    for (int i = count - 1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].id_name, name)) {
            symbol_table[i].array_size = size;
            return;
        }
    }
}

int get_array_size(const char *name) {
    for (int i = count - 1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].id_name, name)) {
            return symbol_table[i].array_size;
        }
    }
}

void check_return_datatype(const char *value) {
    const char *func_datatype = get_datatype_of_current_function();
    const char *return_datatype = get_datatype(value);
    if (strcmp(func_datatype, return_datatype)) {
        sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", count_n);
		sem_errors++;
    }
}

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

struct node *mknode(struct node *left, struct node *right, const char *token) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    char *newstr = (char *) malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}

void print_tree(struct node* tree) {
    printf("\n\nInorder traversal of the Parse Tree is: \n\n");
    print_inorder(tree);
    printf("KONEC\n");
}

void print_inorder(struct node *tree) {
    int i;
    if (tree->left) {
        print_inorder(tree->left);
    }
    printf("%s, ", tree->token);
    if (tree->right) {
        print_inorder(tree->right);
    }
}

void insert_datatype(const char *const_datatype) {
        if (!const_datatype) {
            char temp[5];
            strcpy(temp, yytext);
            if (!strcmp(yytext, "int")) strcpy(temp, "i32");
            if (!strcmp(yytext, "char")) strcpy(temp, "i8");
            strcpy(datatype, temp);
        } else {
            strcpy(datatype, const_datatype);
        }
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
    symbol_table[count].array_size = 0;
    switch (symbol) {
        case 'K':
            symbol_table[count].datatype = strdup("N/A");
            symbol_table[count].type = strdup("Keyword");
            break;
        case 'V':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Variable");
            break;
        case 'C':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Constant");
            break;
        case 'F':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Function");
            break;
        case 'P':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Pointer");
            symbol_table[count].array_size = 1;
            break;
        case 'A':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Argument");
            break;
        default:
            yyerror("bad symbol");
            return;
    }
    count++;
}

void print_icg() {
    for (int i = 0; i <= ic_idx; i++) {
        printf("%s", icg[i]);
    }
}

void print_icg_in_file() {
    FILE *f = fopen("o.ll", "w");
    for (int i = 0; i <= ic_idx; i++) {
        fprintf(f, "%s", icg[i]);
    }
    fclose(f);
}

char *load_from_pointer(const char *var_name, const char *type, const char *datatype) {
    char *new_var = malloc (sizeof (char) * 5);
    if (!strcmp("Variable", type) || !strcmp("Pointer", type)) {
        sprintf(new_var, "%%t%d", temp_var);
        temp_var++;
        sprintf(icg[ic_idx++], "\t%s = load %s, %s* %s\n", new_var, datatype, datatype, var_name);
        return new_var;
    }
    sprintf(new_var, "%s", var_name);
    return new_var;
}

void print_symbol_table() {
    printf("\nSYMBOL\t\t\t\tDATATYPE\t\t\tTYPE\t\t\tARRAY_SIZE\t\t\tLINE NUMBER \n");
    printf("_________________________________________________________________________________________________________________________________\n\n");

	for(int i = 0; i < count; i++) {
		printf("%s\t\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t\n", symbol_table[i].id_name, symbol_table[i].datatype, symbol_table[i].type, symbol_table[i].array_size, symbol_table[i].line_number);
	}

	printf("\n");
}

void free_symbol_table() {
    for(int i = 0; i < count; i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }
}

void free_tree(struct node *tree) {
    if (tree->left) {
        free_tree(tree->left);
        free(tree->left);
    }
    if (tree->right) {
        free_tree(tree->right);
        free(tree->right);
    }
    free(tree->token);
}

int main() {
    sprintf(icg[ic_idx++], "declare i32 @printf(i8*, ...)\n");
    sprintf(icg[ic_idx++], "@.special_printf_format_char = constant [2 x i8] c\"%%c\"\n");
    yyparse();
    printf("\n\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    print_symbol_table();
    printf("\n\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    print_tree(head);
    free_symbol_table();
    free_tree(head);
    free(head);
    printf("\n\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n");
	if(sem_errors > 0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i = 0; i < sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
	if(sem_warnings > 0) {
		printf("Semantic analysis completed with %d warnings\n", sem_warnings);
		for(int i = 0; i < sem_warnings; i++){
			printf("\t - %s", warnings[i]);
		}
	} else {
		printf("Semantic analysis completed with no warnings");
	}
	printf("\n\n");
	printf("\n\t\t\t\t\t\t\t\t PHASE 4: INTERMEDIATE CODE GENERATION \n");
	printf("\n");
	// print_icg();
	print_icg_in_file();
	printf("\n");
}

void yyerror(const char *msg) {
    fprintf(stderr, "line %d: %s, %s\n", count_n, yytext, msg);
}
