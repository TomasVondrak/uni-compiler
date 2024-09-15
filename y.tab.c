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
    #define MAX_MESSAGES_COUNT 50
    #define MAX_MESSAGE_LENGTH 200
    #define ICG_LINE_LENGTH 200
    #define ICG_LINE_COUNT 300

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    // symbol table

    struct symbol {
        char *id_name;
        char *datatype;
        char *type;
        int line_number;
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
    void print_line_to_icg(const char *);
    void print_str_to_icg(const char *);
    void new_line_to_icg();
    const char *datatype_to_icg(const char *);


#line 154 "y.tab.c"

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
#line 84 "parser.y"

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

#line 281 "y.tab.c"

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
  YYSYMBOL_else = 61,                      /* else  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_condition = 63,                 /* condition  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_66_10 = 66,                     /* $@10  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_init = 70,                      /* init  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_arithmetic = 72,                /* arithmetic  */
  YYSYMBOL_relop = 73,                     /* relop  */
  YYSYMBOL_value = 74,                     /* value  */
  YYSYMBOL_argument_expression_section = 75, /* argument_expression_section  */
  YYSYMBOL_arguments_expression = 76,      /* arguments_expression  */
  YYSYMBOL_return = 77,                    /* return  */
  YYSYMBOL_78_14 = 78,                     /* $@14  */
  YYSYMBOL_79_15 = 79                      /* $@15  */
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
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

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
       0,   109,   109,   116,   119,   125,   131,   131,   139,   146,
     139,   157,   160,   166,   169,   169,   175,   186,   190,   194,
     198,   205,   211,   214,   220,   220,   226,   226,   230,   230,
     235,   238,   244,   244,   248,   254,   257,   260,   266,   266,
     275,   275,   281,   281,   287,   294,   297,   297,   304,   304,
     320,   326,   335,   341,   347,   356,   359,   362,   365,   371,
     374,   377,   380,   383,   386,   392,   400,   408,   416,   425,
     434,   443,   449,   461,   464,   470,   473,   479,   479,   484,
     484
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
  "compound_statement", "block", "item", "$@5", "$@6", "$@7", "else",
  "$@8", "condition", "statement", "$@9", "$@10", "$@11", "$@12", "$@13",
  "init", "expression", "arithmetic", "relop", "value",
  "argument_expression_section", "arguments_expression", "return", "$@14",
  "$@15", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,  -100,  -100,  -100,  -100,    16,    40,  -100,  -100,  -100,
     -12,  -100,  -100,   -11,  -100,   124,  -100,    -2,    -6,  -100,
    -100,  -100,   167,     1,  -100,  -100,  -100,   -23,  -100,    -3,
       4,   -20,    86,  -100,     2,    39,  -100,  -100,  -100,   167,
      13,    33,    34,    37,    38,    45,  -100,    -3,    48,   167,
      43,   -10,  -100,    41,    44,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,    -3,    40,    50,  -100,   153,    27,    27,    -3,
      52,   167,  -100,    49,    54,    -3,  -100,  -100,    60,    64,
      39,    71,    72,  -100,    75,  -100,    70,  -100,  -100,    76,
     188,    79,    78,    81,    87,  -100,   167,    39,    60,    -3,
    -100,   167,  -100,  -100,  -100,    27,   -11,  -100,  -100,  -100,
    -100,  -100,  -100,    -3,   -11,  -100,    -3,  -100,  -100,  -100,
      39,    84,    40,    88,  -100,    39,   109,    39,  -100,  -100,
     153,  -100,  -100,    93,   -11,   -11,  -100,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    17,    18,    19,    20,     0,     2,     3,     5,     6,
       0,     1,     4,     0,     8,     0,     7,     0,    77,    24,
      26,    28,     0,     0,    46,    65,    66,    68,    67,     0,
       0,     0,     0,    22,     0,    45,    54,    31,     9,     0,
       0,     0,     0,     0,     0,    68,    72,     0,     0,    74,
       0,     0,    70,     0,    38,    21,    23,    30,    55,    56,
      58,    57,     0,    12,     0,    80,     0,     0,     0,     0,
       0,     0,    75,     0,    73,     0,    53,    40,    51,     0,
      52,     0,    11,    13,     0,    78,     0,    36,    37,     0,
       0,     0,     0,    71,     0,    69,     0,    43,    51,     0,
      39,     0,    10,    14,    16,     0,     0,    59,    60,    61,
      62,    63,    64,     0,     0,    71,     0,    47,    76,    41,
      50,     0,     0,     0,    27,    35,    34,    44,    49,    15,
       0,    32,    29,     0,     0,     0,    33,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,   129,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,    14,     0,   -99,  -100,   105,  -100,  -100,  -100,
    -100,  -100,   -63,   -64,  -100,  -100,  -100,  -100,  -100,    42,
     -28,  -100,  -100,   -18,  -100,  -100,  -100,  -100,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    13,     9,    17,    63,    81,
      82,   122,    83,    31,    16,    32,    33,    41,    42,    43,
     132,   134,    89,    34,    78,    98,    50,    48,    79,   100,
      35,    62,   113,    36,    73,    74,    37,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    51,    86,    53,    46,    91,    10,   124,    49,    54,
      58,    59,    60,    61,   -42,   126,    11,    14,    22,    70,
      44,    64,    76,    15,    25,    26,    45,    28,    29,    38,
     -79,    72,    47,    52,    80,   136,   137,    30,    57,    90,
      90,    92,   123,     1,     2,     3,     4,    97,    22,    65,
      44,    87,    88,    94,    25,    26,    45,    28,    29,    58,
      59,    60,    61,    84,    66,    67,   133,    30,    68,    69,
      77,   120,    58,    59,    60,    61,    49,    90,   118,    71,
      75,    95,   -48,   121,    93,   125,    85,    96,   127,     1,
       2,     3,     4,    18,    19,    20,    21,    99,    58,    59,
      60,    61,   101,   102,   104,   103,   105,    22,   106,    23,
     115,   114,    24,    25,    26,    27,    28,    29,   116,   117,
     131,    55,    84,   128,   130,   135,    30,     1,     2,     3,
       4,    18,    19,    20,    21,    12,   129,    56,     0,     0,
     119,     0,     0,     0,     0,    22,     0,    23,     0,     0,
      24,    25,    26,    27,    28,    29,     1,     2,     3,     4,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    23,     0,     0,    24,
      25,    26,    27,    28,    29,     0,     0,     0,    22,     0,
      44,     0,     0,    30,    25,    26,    45,    28,     0,     0,
     107,   108,   109,   110,   111,   112,     0,    30,    58,    59,
      60,    61
};

static const yytype_int16 yycheck[] =
{
       0,    29,    66,    23,    22,    68,     6,   106,    31,    29,
      20,    21,    22,    23,    37,   114,     0,    29,    21,    47,
      23,    39,    32,    34,    27,    28,    29,    30,    31,    31,
      36,    49,    31,    29,    62,   134,   135,    40,    36,    67,
      68,    69,   105,     3,     4,     5,     6,    75,    21,    36,
      23,    24,    25,    71,    27,    28,    29,    30,    31,    20,
      21,    22,    23,    63,    31,    31,   130,    40,    31,    31,
      29,    99,    20,    21,    22,    23,    31,   105,    96,    31,
      37,    32,    38,   101,    32,   113,    36,    33,   116,     3,
       4,     5,     6,     7,     8,     9,    10,    37,    20,    21,
      22,    23,    38,    32,    29,    33,    36,    21,    32,    23,
      32,    32,    26,    27,    28,    29,    30,    31,    37,    32,
      11,    35,   122,    39,    36,    32,    40,     3,     4,     5,
       6,     7,     8,     9,    10,     6,   122,    32,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    21,    -1,    23,    -1,    -1,
      26,    27,    28,    29,    30,    31,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    21,    -1,
      23,    -1,    -1,    40,    27,    28,    29,    30,    -1,    -1,
      12,    13,    14,    15,    16,    17,    -1,    40,    20,    21,
      22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    42,    43,    44,    45,    47,
      54,     0,    44,    46,    29,    34,    55,    48,     7,     8,
       9,    10,    21,    23,    26,    27,    28,    29,    30,    31,
      40,    54,    56,    57,    64,    71,    74,    77,    31,    78,
      79,    58,    59,    60,    23,    29,    74,    31,    68,    31,
      67,    71,    29,    23,    29,    35,    57,    36,    20,    21,
      22,    23,    72,    49,    74,    36,    31,    31,    31,    31,
      71,    31,    74,    75,    76,    37,    32,    29,    65,    69,
      71,    50,    51,    53,    54,    36,    64,    24,    25,    63,
      71,    63,    71,    32,    74,    32,    33,    71,    66,    37,
      70,    38,    32,    33,    29,    36,    32,    12,    13,    14,
      15,    16,    17,    73,    32,    32,    37,    32,    74,    70,
      71,    74,    52,    63,    55,    71,    55,    71,    39,    53,
      36,    11,    61,    64,    62,    32,    55,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    46,    45,    48,    49,
      47,    50,    50,    51,    52,    51,    53,    54,    54,    54,
      54,    55,    56,    56,    58,    57,    59,    57,    60,    57,
      57,    57,    62,    61,    61,    63,    63,    63,    65,    64,
      66,    64,    67,    64,    64,    64,    68,    64,    69,    64,
      70,    70,    71,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    78,    77,    79,
      77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     0,     3,     0,     0,
       7,     1,     0,     1,     0,     4,     2,     1,     1,     1,
       1,     3,     1,     2,     0,    10,     0,     6,     0,     7,
       2,     1,     0,     3,     0,     3,     1,     1,     0,     4,
       0,     5,     0,     4,     6,     1,     0,     5,     0,     6,
       2,     0,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     4,     2,     1,     0,     1,     3,     0,     4,     0,
       3
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
#line 109 "parser.y"
                   {
        (yyval.nd_obj).nd = mknode(NULL, (yyvsp[0].nd_obj).nd, "program");
        head = (yyval.nd_obj).nd;
      }
#line 1453 "y.tab.c"
    break;

  case 3: /* declarations: declaration  */
#line 116 "parser.y"
                  {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "declarations");
      }
#line 1461 "y.tab.c"
    break;

  case 4: /* declarations: declarations declaration  */
#line 119 "parser.y"
                               {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "declarations");
      }
#line 1469 "y.tab.c"
    break;

  case 5: /* declaration: function_definition  */
#line 125 "parser.y"
                          {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1477 "y.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 131 "parser.y"
                           {print_str_to_icg(" nounwind uwtable {"); new_line_to_icg(); print_line_to_icg("entry:"); }
#line 1483 "y.tab.c"
    break;

  case 7: /* function_definition: function_declaration $@1 compound_statement  */
#line 131 "parser.y"
                                                                                                                                          {
        print_line_to_icg("}\n");
        end_of_scope();
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "function_definition");
      }
#line 1493 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 139 "parser.y"
                  {
        add_to_table('F', (yyvsp[0].nd_obj).name);
        print_str_to_icg("define ");
        print_str_to_icg((yyvsp[-1].nd_obj).name);
        print_str_to_icg(" @");
        print_str_to_icg((yyvsp[0].nd_obj).name);
      }
#line 1505 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 146 "parser.y"
          {
        print_str_to_icg("(");
        new_scope();
      }
#line 1514 "y.tab.c"
    break;

  case 10: /* function_declaration: datatype ID $@2 '(' $@3 arguments_definition_section ')'  */
#line 150 "parser.y"
                                       {
        print_str_to_icg(")");
        (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-5].nd_obj).name);
      }
#line 1523 "y.tab.c"
    break;

  case 11: /* arguments_definition_section: arguments_definition  */
#line 157 "parser.y"
                           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "arguments_definition_section");
      }
#line 1531 "y.tab.c"
    break;

  case 12: /* arguments_definition_section: %empty  */
#line 160 "parser.y"
      {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "arguments_definition_section");
      }
#line 1539 "y.tab.c"
    break;

  case 13: /* arguments_definition: argument_definition  */
#line 166 "parser.y"
                          {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "arguments_definition");
      }
#line 1547 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 169 "parser.y"
                               { print_str_to_icg(", "); }
#line 1553 "y.tab.c"
    break;

  case 15: /* arguments_definition: arguments_definition ',' $@4 argument_definition  */
#line 169 "parser.y"
                                                                               {
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj).nd, "arguments_definition");
      }
#line 1561 "y.tab.c"
    break;

  case 16: /* argument_definition: datatype ID  */
#line 175 "parser.y"
                  {
        print_str_to_icg((yyvsp[-1].nd_obj).name);
        print_str_to_icg(" %");
        print_str_to_icg((yyvsp[0].nd_obj).name);
        add_to_table('V', (yyvsp[0].nd_obj).name);
        (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "argument_definition");
      }
#line 1574 "y.tab.c"
    break;

  case 17: /* datatype: INT  */
#line 186 "parser.y"
          {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1583 "y.tab.c"
    break;

  case 18: /* datatype: FLOAT  */
#line 190 "parser.y"
            {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1592 "y.tab.c"
    break;

  case 19: /* datatype: CHAR  */
#line 194 "parser.y"
           {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1601 "y.tab.c"
    break;

  case 20: /* datatype: VOID  */
#line 198 "parser.y"
           {
        insert_datatype(NULL);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1610 "y.tab.c"
    break;

  case 21: /* compound_statement: '{' block '}'  */
#line 205 "parser.y"
                    {
        (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
      }
#line 1618 "y.tab.c"
    break;

  case 22: /* block: item  */
#line 211 "parser.y"
           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "block");
      }
#line 1626 "y.tab.c"
    break;

  case 23: /* block: block item  */
#line 214 "parser.y"
                 {
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "block");
      }
#line 1634 "y.tab.c"
    break;

  case 24: /* $@5: %empty  */
#line 220 "parser.y"
          { add_to_table('K', (yyvsp[0].nd_obj).name); new_scope(); }
#line 1640 "y.tab.c"
    break;

  case 25: /* item: FOR $@5 '(' statement ';' condition ';' statement ')' compound_statement  */
#line 220 "parser.y"
                                                                                                                        {
        struct node *temp = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "CONDITION");
        struct node *temp2 = mknode((yyvsp[-6].nd_obj).nd, temp, "CONDITION");
        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj).nd, (yyvsp[-9].nd_obj).name);
        end_of_scope();
      }
#line 1651 "y.tab.c"
    break;

  case 26: /* $@6: %empty  */
#line 226 "parser.y"
            { add_to_table('K', (yyvsp[0].nd_obj).name); new_scope(); }
#line 1657 "y.tab.c"
    break;

  case 27: /* item: WHILE $@6 '(' condition ')' compound_statement  */
#line 226 "parser.y"
                                                                                              {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, (yyvsp[-5].nd_obj).name);
        end_of_scope();
      }
#line 1666 "y.tab.c"
    break;

  case 28: /* $@7: %empty  */
#line 230 "parser.y"
         { add_to_table('K', (yyvsp[0].nd_obj).name); new_scope(); }
#line 1672 "y.tab.c"
    break;

  case 29: /* item: IF $@7 '(' condition ')' compound_statement else  */
#line 230 "parser.y"
                                                                                                {
        struct node *iff = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-6].nd_obj).name);
        (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else");
        end_of_scope();
      }
#line 1682 "y.tab.c"
    break;

  case 30: /* item: statement ';'  */
#line 235 "parser.y"
                    {
        (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd;
    }
#line 1690 "y.tab.c"
    break;

  case 31: /* item: return  */
#line 238 "parser.y"
             {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 1698 "y.tab.c"
    break;

  case 32: /* $@8: %empty  */
#line 244 "parser.y"
           { add_to_table('K', (yyvsp[0].nd_obj).name); new_scope(); }
#line 1704 "y.tab.c"
    break;

  case 33: /* else: ELSE $@8 compound_statement  */
#line 244 "parser.y"
                                                                           {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[-2].nd_obj).name);
        end_of_scope();
      }
#line 1713 "y.tab.c"
    break;

  case 34: /* else: %empty  */
#line 248 "parser.y"
      {
        (yyval.nd_obj).nd = NULL;
      }
#line 1721 "y.tab.c"
    break;

  case 35: /* condition: expression relop expression  */
#line 254 "parser.y"
                                  { // TODO: dodělat kontrolu a and, or
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
      }
#line 1729 "y.tab.c"
    break;

  case 36: /* condition: TRUE  */
#line 257 "parser.y"
           { add_to_table('K', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1737 "y.tab.c"
    break;

  case 37: /* condition: FALSE  */
#line 260 "parser.y"
            { add_to_table('K', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1745 "y.tab.c"
    break;

  case 38: /* $@9: %empty  */
#line 266 "parser.y"
                  { add_to_table('V', (yyvsp[0].nd_obj).name); }
#line 1751 "y.tab.c"
    break;

  case 39: /* statement: datatype ID $@9 init  */
#line 266 "parser.y"
                                                       {
        (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
        int type_exception = check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).datatype);
        if (!strcmp((yyvsp[0].nd_obj2).type, "Pointer")) {
            sprintf(warnings[sem_warnings], "Line %d: assigning pointer to non-pointer variable.\n", count_n);
            sem_warnings++;
        }
        (yyval.nd_obj).nd = handle_type_cast(type_exception, (yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "definition");
      }
#line 1765 "y.tab.c"
    break;

  case 40: /* $@10: %empty  */
#line 275 "parser.y"
                      { add_to_table('P', (yyvsp[0].nd_obj).name); }
#line 1771 "y.tab.c"
    break;

  case 41: /* statement: datatype MUL ID $@10 init  */
#line 275 "parser.y"
                                                           {
        check_pointer_types((yyvsp[-4].nd_obj).name, (yyvsp[0].nd_obj2).datatype, (yyvsp[0].nd_obj2).type);
        struct node *id = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
        struct node *pointer = mknode((yyvsp[-4].nd_obj).nd, id, "pointer_name");
        (yyval.nd_obj).nd = mknode(pointer, (yyvsp[0].nd_obj2).nd, "pointer_definition");
      }
#line 1782 "y.tab.c"
    break;

  case 42: /* $@11: %empty  */
#line 281 "parser.y"
         { check_declaration((yyvsp[0].nd_obj).name); }
#line 1788 "y.tab.c"
    break;

  case 43: /* statement: ID $@11 '=' expression  */
#line 281 "parser.y"
                                                        {
        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[-3].nd_obj).name);
        int type_exception = check_types(id_datatype, (yyvsp[0].nd_obj2).datatype);
        (yyval.nd_obj).nd = handle_type_cast(type_exception, (yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "assignement");
      }
#line 1799 "y.tab.c"
    break;

  case 44: /* statement: MUL '(' expression ')' '=' expression  */
#line 287 "parser.y"
                                            {
        if (strcmp((yyvsp[-3].nd_obj2).type, "Pointer") || strcmp((yyvsp[-3].nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype)) {
            sprintf(warnings[sem_warnings], "Line %d: implicit cast to pointer.\n", count_n);
            sem_warnings++;
        }
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, "dereference_assignement");
      }
#line 1811 "y.tab.c"
    break;

  case 45: /* statement: expression  */
#line 294 "parser.y"
                 {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj2).nd;
      }
#line 1819 "y.tab.c"
    break;

  case 46: /* $@12: %empty  */
#line 297 "parser.y"
              { add_to_table('K', (yyvsp[0].nd_obj).name); }
#line 1825 "y.tab.c"
    break;

  case 47: /* statement: PUTCHAR $@12 '(' value ')'  */
#line 297 "parser.y"
                                                            {
        if (strcmp((yyvsp[-1].nd_obj2).datatype, "char")) {
            sprintf(errors[sem_errors], "Line %d: putchar accepts char. %s %s\n", count_n, (yyvsp[-1].nd_obj2).datatype, "char");
            sem_errors++;
        }
        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj2).nd, NULL, (yyvsp[-4].nd_obj).name);
      }
#line 1837 "y.tab.c"
    break;

  case 48: /* $@13: %empty  */
#line 304 "parser.y"
                  { add_to_table('P', (yyvsp[0].nd_obj).name); }
#line 1843 "y.tab.c"
    break;

  case 49: /* statement: datatype ID $@13 '[' value ']'  */
#line 304 "parser.y"
                                                                {
        if (strcmp((yyvsp[-1].nd_obj2).datatype, "int")) {
            sprintf(errors[sem_errors], "Line %d: array position qualificator needs to be int. %s %s\n", count_n, (yyvsp[-1].nd_obj2).datatype, "int");
            sem_errors++;
        }
        if (strcmp(get_type((yyvsp[-4].nd_obj).name), "Pointer")) {
            sprintf(errors[sem_errors], "Line %d: array qualificator not used to pointer. %s %s\n", count_n, get_type((yyvsp[-4].nd_obj).name), "Pointer");
            sem_errors++;
        }
        struct node *id = mknode(NULL, NULL, (yyvsp[-4].nd_obj).name);
        struct node *pointer = mknode((yyvsp[-5].nd_obj).nd, id, "pointer_name");
        (yyval.nd_obj).nd = mknode(pointer, (yyvsp[-1].nd_obj2).nd, "array");
      }
#line 1861 "y.tab.c"
    break;

  case 50: /* init: '=' expression  */
#line 320 "parser.y"
                     {
        (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd;
        strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name);
      }
#line 1872 "y.tab.c"
    break;

  case 51: /* init: %empty  */
#line 326 "parser.y"
      {
        (yyval.nd_obj2).nd = mknode(NULL, NULL, "NULL");
        strcpy((yyval.nd_obj2).type, "null");
        strcpy((yyval.nd_obj2).datatype, "null");
        strcpy((yyval.nd_obj2).name, "NULL");
      }
#line 1883 "y.tab.c"
    break;

  case 52: /* expression: expression arithmetic expression  */
#line 335 "parser.y"
                                       {
        int type_exception = check_types((yyvsp[-2].nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype);
        (yyval.nd_obj2).nd = handle_type_cast(type_exception, (yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
        strcpy((yyval.nd_obj2).type, (yyvsp[-2].nd_obj2).type);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[-2].nd_obj2).datatype);
      }
#line 1894 "y.tab.c"
    break;

  case 53: /* expression: '(' expression ')'  */
#line 341 "parser.y"
                         {
        (yyval.nd_obj2).nd = (yyvsp[-1].nd_obj2).nd;
        strcpy((yyval.nd_obj2).type, (yyvsp[-1].nd_obj2).type);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[-1].nd_obj2).datatype);
        strcpy((yyval.nd_obj2).name, (yyvsp[-1].nd_obj2).name);
      }
#line 1905 "y.tab.c"
    break;

  case 54: /* expression: value  */
#line 347 "parser.y"
            {
        (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd;
        strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name);
      }
#line 1916 "y.tab.c"
    break;

  case 55: /* arithmetic: ADD  */
#line 356 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1924 "y.tab.c"
    break;

  case 56: /* arithmetic: SUB  */
#line 359 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1932 "y.tab.c"
    break;

  case 57: /* arithmetic: MUL  */
#line 362 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1940 "y.tab.c"
    break;

  case 58: /* arithmetic: DIV  */
#line 365 "parser.y"
          {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1948 "y.tab.c"
    break;

  case 59: /* relop: LT  */
#line 371 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1956 "y.tab.c"
    break;

  case 60: /* relop: GT  */
#line 374 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1964 "y.tab.c"
    break;

  case 61: /* relop: LE  */
#line 377 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1972 "y.tab.c"
    break;

  case 62: /* relop: GE  */
#line 380 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1980 "y.tab.c"
    break;

  case 63: /* relop: EQ  */
#line 383 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1988 "y.tab.c"
    break;

  case 64: /* relop: NE  */
#line 386 "parser.y"
         {
        (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 1996 "y.tab.c"
    break;

  case 65: /* value: NUMBER  */
#line 392 "parser.y"
             {
        insert_datatype("int");
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).type, "Constant");
        strcpy((yyval.nd_obj2).datatype, "int");
      }
#line 2009 "y.tab.c"
    break;

  case 66: /* value: FLOAT_NUM  */
#line 400 "parser.y"
                {
        insert_datatype("float");
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).type, "Constant");
        strcpy((yyval.nd_obj2).datatype, "float");
      }
#line 2022 "y.tab.c"
    break;

  case 67: /* value: CHARACTER  */
#line 408 "parser.y"
                {
        insert_datatype("char");
        add_to_table('C', (yyvsp[0].nd_obj).name);
        (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).type, "Constant");
        strcpy((yyval.nd_obj2).datatype, "char");
      }
#line 2035 "y.tab.c"
    break;

  case 68: /* value: ID  */
#line 416 "parser.y"
         {
        check_declaration((yyvsp[0].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).datatype, id_datatype);
        const char *id_type = get_type((yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).type, id_type);
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
      }
#line 2049 "y.tab.c"
    break;

  case 69: /* value: ID '(' argument_expression_section ')'  */
#line 425 "parser.y"
                                             { // TODO: semantická analýza jestli jsou správný argumenty podle definice
        check_declaration((yyvsp[-3].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[-3].nd_obj).name);
        strcpy((yyval.nd_obj2).datatype, id_datatype);
        const char *id_type = get_type((yyvsp[-3].nd_obj).name);
        strcpy((yyval.nd_obj2).type, id_type);
        strcpy((yyval.nd_obj2).name, (yyvsp[-3].nd_obj).name);
        (yyval.nd_obj2).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, (yyvsp[-3].nd_obj).name);
      }
#line 2063 "y.tab.c"
    break;

  case 70: /* value: '&' ID  */
#line 434 "parser.y"
             {
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
        const char *id_datatype = get_datatype((yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).datatype, id_datatype);
        strcpy((yyval.nd_obj2).type, "Pointer");
        check_declaration((yyvsp[0].nd_obj).name);
        struct node *id = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
        (yyval.nd_obj2).nd = mknode(id, NULL, "address");
      }
#line 2077 "y.tab.c"
    break;

  case 71: /* value: MUL '(' expression ')'  */
#line 443 "parser.y"
                             { // insert type, co je na adrese expression ? ale jak to udělat - nutnost mít nějakou tabulku s tím co je na nějaké adrese - teď bude asi každej pointer na int zjednodušeně
        strcpy((yyval.nd_obj2).name, (yyvsp[-3].nd_obj).name);
        strcpy((yyval.nd_obj2).datatype, (yyvsp[-1].nd_obj2).datatype);
        strcpy((yyval.nd_obj2).type, "Variable");
        (yyval.nd_obj2).nd = mknode((yyvsp[-1].nd_obj2).nd, NULL, "dereference");
      }
#line 2088 "y.tab.c"
    break;

  case 72: /* value: SUB value  */
#line 449 "parser.y"
                {
        if (strcmp((yyvsp[0].nd_obj2).datatype, "int") && strcmp((yyvsp[0].nd_obj2).datatype, "float")) {
            sprintf(errors[sem_errors], "Line %d: unary minus on non number type\n", count_n);
            sem_errors++;
        }
        strcpy((yyval.nd_obj2).datatype, (yyvsp[0].nd_obj2).datatype);
        strcpy((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
        (yyval.nd_obj2).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "unary_minus");
      }
#line 2102 "y.tab.c"
    break;

  case 73: /* argument_expression_section: arguments_expression  */
#line 461 "parser.y"
                           {
        (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd;
      }
#line 2110 "y.tab.c"
    break;

  case 74: /* argument_expression_section: %empty  */
#line 464 "parser.y"
      {
        (yyval.nd_obj).nd = NULL;
      }
#line 2118 "y.tab.c"
    break;

  case 75: /* arguments_expression: value  */
#line 470 "parser.y"
            {
        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "arguments_expression");
      }
#line 2126 "y.tab.c"
    break;

  case 76: /* arguments_expression: arguments_expression ',' value  */
#line 473 "parser.y"
                                     {
        (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "arguments_expression");
      }
#line 2134 "y.tab.c"
    break;

  case 77: /* $@14: %empty  */
#line 479 "parser.y"
             { add_to_table('K', "return"); }
#line 2140 "y.tab.c"
    break;

  case 78: /* return: RETURN $@14 value ';'  */
#line 479 "parser.y"
                                                        {
        check_return_datatype((yyvsp[-1].nd_obj2).name);
        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return");
        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "RETURN");
      }
#line 2150 "y.tab.c"
    break;

  case 79: /* $@15: %empty  */
#line 484 "parser.y"
             { add_to_table('K', "return"); }
#line 2156 "y.tab.c"
    break;

  case 80: /* return: RETURN $@15 ';'  */
#line 484 "parser.y"
                                                  {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "RETURN");
      }
#line 2164 "y.tab.c"
    break;


#line 2168 "y.tab.c"

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

#line 489 "parser.y"


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
    if (!strcmp(type1, "int") && !strcmp(type2, "float"))
        return 1;
    if (!strcmp(type1, "float") && !strcmp(type2, "int"))
        return 2;
    if (!strcmp(type1, "int") && !strcmp(type2, "char"))
        return 3;
    if (!strcmp(type1, "char") && !strcmp(type2, "int"))
        return 4;
    if (!strcmp(type1, "float") && !strcmp(type2, "char"))
        return 5;
    if (!strcmp(type1, "char") && !strcmp(type2, "float"))
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
    if ((!strcmp(type2, "Pointer") && !strcmp(datatype1, datatype2)) || (!strcmp(type2, "Constant") && !strcmp("int", datatype2)))
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
    for (int i = count-1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].type, "Function")) {
            return symbol_table[i].id_name;
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
            strcpy(datatype, yytext);
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
            break;
        default:
            yyerror("bad symbol");
            return;
    }
    count++;
}

void print_line_to_icg(const char *line) {
    strcpy(icg[ic_idx], line);
    ic_idx++;
}

void print_str_to_icg(const char *str) {
    strcat(icg[ic_idx], str);
}

void new_line_to_icg() {
    ic_idx++;
}

void print_icg() {
    for (int i = 0; i <= ic_idx; i++) {
        printf("%s\n", icg[i]);
    }
}

void print_symbol_table() {
    printf("\nSYMBOL\t\t\tDATATYPE\t\tTYPE\t\t\tLINE NUMBER \n");
    printf("____________________________________________________________________________________________\n\n");

	for(int i = 0; i < count; i++) {
		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t\n", symbol_table[i].id_name, symbol_table[i].datatype, symbol_table[i].type, symbol_table[i].line_number);
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
    printf("\n\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    print_symbol_table();
    printf("\n\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    print_tree(head);
    free_symbol_table();
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
	print_icg();
	printf("\n");
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}
