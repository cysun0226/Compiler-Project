%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <fstream>
    #include "node.h"


    using namespace std;
    FILE *pFile;

    extern "C"
    {
        int yyparse(void);
        int yylex(void);
        int yywrap()
        {
          return 1;
        }

        void yyerror(const char *str)
        {
            fprintf(pFile, "error! \n");
            fclose(pFile);
            fprintf(stderr,"error: %s\n",str);
        }

    }

    Node* ASTROOT;


%}

%union
{
    struct Node* node;
    int number;
    char* string;
}

%token <node> AND
%token <node> ARRAY
%token <node> CASE
%token <node> CONST
%token <node> DIV
%token <node> DO
%token <node> DOWNTO
%nonassoc <node> ELSE
%token <node> END
%token <node> EXTERNAL

%token <node> FOR
%token <node> FORWARD
%token <node> FUNCTION
%token <node> GOTO
%token <node> IF
%token <node> IN

%token <node> INTEGER

%token <node> LABEL
%token <node> MOD
%token <node> NIL
%token <node> NOT

%token <node> OF
%token <node> OR
%token <node> OTHERWISE
%token <node> PACKED
%token <node> PBEGIN
%token <node> PFILE
%token <node> PROCEDURE
%token <node> PROGRAM
%token <node> RECORD
%token <node> REPEAT

%token <node> SET
%token <node> THEN
%token <node> TO
%token <node> TYPE
%token <node> UNTIL
%token <node> VAR
%token <node> WHILE
%token <node> WITH

%token <node> REAL

%token <string> ID
%token <node> ASSIGNMENT

%token <string> CHARACTER_STRING
%token <node> COLON
%token <node> COMMA
%token <node> DIGSEQ
%token <node> DOT
%token <node> DOTDOT
%token <node> EQUAL
%token <node> GE
%token <node> GT
%token <node> LBRAC

%token <node> LE
%token <node> LPAREN
%token <node> LT
%token <node> MINUS
%token <node> PLUS
%token <node> RBRAC
%token <node> REALNUMBER
%token <node> RPAREN
%token <node> SEMICOLON

%token <node> SLASH
%token <node> STAR
%token <node> STARSTAR
%token <node> notEQUAL
%token <node> NUM
%token <node> REAL_NUM

%type <node> prog identifier_list declarations type standard_type
%type <node> subprogram_declarations subprogram_declaration
%type <node> subprogram_head arguments parameter_list if_stmt
%type <node> optional_var compound_statement optional_statements
%type <node> statement_list statement variable tail term
%type <node> procedure_statement expression_list expression
%type <node> simple_expression factor addop mulop relop id_tok



%%

prog :
  PROGRAM id_tok LPAREN identifier_list RPAREN SEMICOLON
  declarations
  subprogram_declarations
  compound_statement
  DOT {
     printf("Reduction ( prog -> PROGRAM ID (identifier_list); \n");
     printf("                    declarations \n");
     printf("                    subprogram_declarations \n");
     printf("                    compound_statement \n");
     printf("                    .                             )\n");

     fprintf(pFile, "Parse finish. \n");

     $$ = newNode(NODE_START);
     addChild($$, newNode(RE_PROG));
     addChild($$, $2);
     addChild($$, newNode(PUC_LPAREN));
     addChild($$, $4);
     addChild($$, newNode(PUC_RPAREN));
     addChild($$, newNode(PUC_SEMI));
     addChild($$, $7);
     addChild($$, $8);
     addChild($$, $9);
     addChild($$, newNode(PUC_DOT));
     ASTROOT = $$;
  }
;


identifier_list :
    ID {
      printf("Reduction ( identifier_list -> ID )\n");
      $$ = newNode(NODE_ID_LT);
      Node* id_node = newNode(NODE_ID);
      // printf("ID $1 = %s \n", $1);
      // cout << "ID $1 = " << $1 << endl;
      id_node->strValue = $1;
      addChild($$, id_node);
    }
  | identifier_list COMMA ID {
      printf("Reduction ( identifier_list -> identifier_list , ID )\n");
      $$ = newNode(NODE_ID_LT);
      addChild($$, $1);
      addChild($$, newNode(PUC_COMMA));
      Node* id_node = newNode(NODE_ID);
      id_node->strValue = $3;
      addChild($$, id_node);
    }
  ;

id_tok :
  ID {
    // printf("Reduction ( id_tok -> ID )\n");
    $$ = newNode(ID_TOK);
    Node* id_node = newNode(NODE_ID);
    // printf("ID $1 = %s \n", $1);
    // cout << "ID $1 = " << $1 << endl;
    id_node->strValue = $1;
    addChild($$, id_node);
  }
  ;

declarations :
    declarations VAR identifier_list COLON type SEMICOLON {
      printf("Reduction ( declarations -> declarations VAR identifier_list : type ; )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, $1);
      addChild($$, newNode(NODE_VAR));
      addChild($$, $3);
      addChild($$, newNode(PUC_COLON));
      addChild($$, $5);
      addChild($$, newNode(PUC_SEMI));
    }
  | declarations VAR identifier_list COLON identifier_list SEMICOLON {
      printf("Reduction ( declarations -> declarations VAR identifier_list : id ; )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, $1);
      addChild($$, newNode(NODE_VAR));
      addChild($$, $3);
      addChild($$, newNode(PUC_COLON));
      addChild($$, $5);
      addChild($$, newNode(PUC_SEMI));
    }
  | declarations CONST identifier_list EQUAL NUM SEMICOLON {
    printf("Reduction ( declarations -> declarations CONST identifier_list = NUM ; )\n");
    $$ = newNode(NODE_DECL); // $$ = declarations
    addChild($$, $1);
    addChild($$, newNode(RE_CONST));
    addChild($$, $3);
    addChild($$, newNode(OP_EQUAL));
    addChild($$, newNode(NODE_NUM));
    addChild($$, newNode(PUC_SEMI));
    }
  | declarations TYPE identifier_list EQUAL type SEMICOLON  {
    printf("Reduction ( declarations -> declarations TYPE identifier_list = type ; )\n");
    $$ = newNode(NODE_DECL); // $$ = declarations
    addChild($$, $1);
    addChild($$, newNode(RE_TYPE));
    addChild($$, $3);
    addChild($$, newNode(OP_EQUAL));
    addChild($$, $5);
    addChild($$, newNode(PUC_SEMI));
    }
  /*| PROCEDURE id arguments SEMICOLON {
      printf("Reduction ( declarations -> PROCEDURE id arguments SEMICOLON )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, newNode(RE_PROC));
      addChild($$, newNode(NODE_ID));
      addChild($$, $3);
      addChild($$, newNode(PUC_SEMI));
    }*/
  | {
      printf("Reduction ( declarations -> LAMDBA )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, newNode(NODE_LAMDBA));
    }
  ;


type :
    standard_type {
      printf("Reduction ( type -> standard_type )\n");

      $$ = newNode(NODE_TYPE);
      addChild($$, $1);
    }
  | ARRAY LBRAC NUM DOTDOT NUM RBRAC OF type {
      printf("Reduction ( type -> ARRAY [NUM .. NUM] OF type )\n");

      $$ = newNode(NODE_TYPE);
      addChild($$, newNode(RE_ARR));
      addChild($$, newNode(PUC_LBRAC));
      addChild($$, newNode(NODE_NUM));
      addChild($$, newNode(PUC_DOTDOT));
      addChild($$, newNode(NODE_NUM));
      addChild($$, newNode(PUC_RBRAC));
      addChild($$, newNode(RE_OF));
      addChild($$, $8);
    }
  | ARRAY LBRAC id_tok DOTDOT NUM RBRAC OF type {
      printf("Reduction ( type -> ARRAY [ID .. NUM] OF type )\n");

      $$ = newNode(NODE_TYPE);
      addChild($$, newNode(RE_ARR));
      addChild($$, newNode(PUC_LBRAC));
      addChild($$, $3);
      addChild($$, newNode(PUC_DOTDOT));
      addChild($$, newNode(NODE_NUM));
      addChild($$, newNode(PUC_RBRAC));
      addChild($$, newNode(RE_OF));
      addChild($$, $8);
    }
  | ARRAY LBRAC NUM DOTDOT id_tok RBRAC OF type {
      printf("Reduction ( type -> ARRAY [NUM .. ID] OF type )\n");

      $$ = newNode(NODE_TYPE);
      addChild($$, newNode(RE_ARR));
      addChild($$, newNode(PUC_LBRAC));
      addChild($$, newNode(NODE_NUM));
      addChild($$, newNode(PUC_DOTDOT));
      addChild($$, $5);
      addChild($$, newNode(PUC_RBRAC));
      addChild($$, newNode(RE_OF));
      addChild($$, $8);
    }
  | ARRAY LBRAC id_tok DOTDOT id_tok RBRAC OF type {
      printf("Reduction ( type -> ARRAY [id .. id] OF type )\n");

      $$ = newNode(NODE_TYPE);
      addChild($$, newNode(RE_ARR));
      addChild($$, newNode(PUC_LBRAC));
      addChild($$, $3);
      addChild($$, newNode(PUC_DOTDOT));
      addChild($$, $5);
      addChild($$, newNode(PUC_RBRAC));
      addChild($$, newNode(RE_OF));
      addChild($$, $8);
    }
  ;


standard_type :
    INTEGER {
      printf("Reduction ( standard_type -> INTEGER )\n");
      $$ = newNode(NODE_STDTYPE);
      addChild($$, newNode(TY_INT));
    }
  | REAL {
      printf("Reduction ( standard_type -> REAL )\n");
      $$ = newNode(NODE_STDTYPE);
      addChild($$, newNode(TY_REAL));
    }
  | CHARACTER_STRING {
      printf("Reduction ( standard_type -> CHARACTER_STRING )\n");
      $$ = newNode(NODE_STDTYPE);
      addChild($$, newNode(TY_STR));
    }
  /*
  | identifier_list {
      printf("Reduction ( standard_type -> identifier_list )\n");
      $$ = newNode(NODE_STDTYPE);
      addChild($$, $1);
    }
  */
  ;



subprogram_declarations :
  subprogram_declarations subprogram_declaration SEMICOLON {
      printf("Reduction ( subprogram_declarations -> subprogram_declarations subprogram_declaration ; )\n");
      $$ = newNode(NODE_SPROG_DECLS);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, newNode(PUC_SEMI));
   }
 | {
      printf("Reduction ( subprogram_declarations -> LAMDBA )\n");
      $$ = newNode(NODE_SPROG_DECLS);
      addChild($$, newNode(NODE_LAMDBA));
   }
 ;


subprogram_declaration :
  subprogram_head	declarations compound_statement {
      printf("Reduction ( subprogram_declaration -> subprogram_head declarations compound_statement )\n");
      $$ = newNode(NODE_SPROG_DECL);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


subprogram_head :
    FUNCTION id_tok arguments COLON standard_type SEMICOLON {
      printf("Reduction ( subprogram_head -> FUNCTION id arguments : standard_type ; )\n");
      $$ = newNode(NODE_SPROG_H);
      addChild($$, newNode(RE_FUNC));
      addChild($$, $2);
      addChild($$, $3);
      addChild($$, newNode(PUC_COLON));
      addChild($$, $5);
      addChild($$, newNode(PUC_SEMI));
    }
  | PROCEDURE id_tok arguments SEMICOLON {
      printf("Reduction ( subprogram_head -> PROCEDURE id arguments ; )\n");
      $$ = newNode(NODE_SPROG_H);
      addChild($$, newNode(RE_PROC));
      addChild($$, $2);
      addChild($$, $3);
      addChild($$, newNode(PUC_SEMI));
    }
  ;


arguments :
    LPAREN parameter_list RPAREN {
      printf("Reduction ( arguments -> (parameter_list) )\n");
      $$ = newNode(NODE_ARG);
      addChild($$, newNode(PUC_LPAREN));
      addChild($$, $2);
      addChild($$, newNode(PUC_RPAREN));
    }
  | {
      printf("Reduction ( arguments -> LAMDBA )\n");
      $$ = newNode(NODE_ARG);
      addChild($$, newNode(NODE_LAMDBA));
    }
  ;


parameter_list :
    optional_var identifier_list COLON type {
      printf("Reduction ( parameter_list -> optional_var identifier_list : type )\n");
      $$ = newNode(NODE_PARAM_LI);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, newNode(PUC_COLON));
      addChild($$, $4);
    }
  | optional_var identifier_list COLON identifier_list {
    printf("Reduction ( parameter_list -> optional_var identifier_list : identifier_list )\n");
    $$ = newNode(NODE_PARAM_LI);
    addChild($$, $1);
    addChild($$, $2);
    addChild($$, newNode(PUC_COLON));
    addChild($$, $4);
    }
  | optional_var identifier_list COLON type SEMICOLON parameter_list {
      printf("Reduction ( parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
      $$ = newNode(NODE_PARAM_LI);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, newNode(PUC_COLON));
      addChild($$, $4);
      addChild($$, newNode(PUC_SEMI));
      addChild($$, $6);
    }
  ;


optional_var :
  VAR {
      printf("Reduction ( optional_var -> VAR )\n");
      $$ = newNode(NODE_OPTVAR);
      addChild($$, newNode(RE_VAR));
    }
  | {
      printf("Reduction ( optional_var -> LAMDBA )\n");
      $$ = newNode(NODE_OPTVAR);
      addChild($$, newNode(NODE_LAMDBA));
    }
  ;


compound_statement :
    PBEGIN optional_statements END {
      printf("Reduction ( compound_statement -> begin optional_statements end )\n");
      $$ = newNode(NODE_COMP_STMT);
      addChild($$, newNode(RE_BEGIN));
      addChild($$, $2);
      addChild($$, newNode(RE_END));
    }
  ;


optional_statements :
    statement_list {
      printf("Reduction ( optional_statements -> statement_list )\n");
      $$ = newNode(NODE_OPT_STMT);
      addChild($$, $1);
    }
  ;


statement_list :
    statement {
      printf("Reduction ( statement_list -> statement )\n");
      $$ = newNode(NODE_STMT_LI);
      addChild($$, $1);
    }
  | statement_list SEMICOLON statement {
      printf("Reduction ( statement_list -> statement_list ; statement )\n");
      $$ = newNode(NODE_STMT_LI);
      addChild($$, $1);
      addChild($$, newNode(PUC_SEMI));
      addChild($$, $3);
    }
  ;


statement :
    variable ASSIGNMENT expression {
      printf("Reduction ( statement -> variable := expression )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, $1);
      addChild($$, newNode(RE_ASGMNT));
      addChild($$, $3);
    }
  | procedure_statement {
      printf("Reduction ( statement -> procedure_statement )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, $1);
    }
  | compound_statement {
      printf("Reduction ( statement -> compound_statement )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, $1);
    }
  | IF expression THEN if_stmt {
      printf("Reduction ( statement -> IF expression THEN if_stmt )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, newNode(RE_IF));
      addChild($$, $2);
      addChild($$, newNode(RE_THEN));
      addChild($$, $4);
    }
  | WHILE expression DO statement {
      printf("Reduction ( statement -> WHILE expression DO statement )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, newNode(RE_WHILE));
      addChild($$, $2);
      addChild($$, newNode(RE_DO));
      addChild($$, $4);
    }
  | {
      printf("Reduction ( statement -> lambda )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, newNode(NODE_LAMDBA));
  }
  ;


if_stmt :
    statement ELSE statement {
        printf("Reduction ( if_stmt -> statement ELSE statement )\n");
        $$ = newNode(NODE_IF_STMT);
        addChild($$, $1);
        addChild($$, newNode(RE_ELSE));
        addChild($$, $3);
    }
  | statement {
        printf("Reduction ( if_stmt -> statement )\n");
        $$ = newNode(NODE_IF_STMT);
        addChild($$, $1);
    }


variable :
  id_tok tail {
      printf("Reduction ( variable -> id tail )\n");
      $$ = newNode(NODE_VAR);
      addChild($$, $1);
      addChild($$, $2);
    }
;


tail :
  LBRAC expression RBRAC tail {
      printf("Reduction ( tail -> [expression] tail )\n");
      $$ = newNode(NODE_TAIL);
      addChild($$, newNode(PUC_LBRAC));
      addChild($$, $2);
      addChild($$, newNode(PUC_RBRAC));
      addChild($$, $4);
    }
  | {
      printf("Reduction ( tail -> lambda )\n");
      $$ = newNode(NODE_TAIL);
      addChild($$, newNode(NODE_LAMDBA));
  }
  ;


procedure_statement :
  id_tok {
      printf("Reduction ( procedure_statement -> ID )\n");
      $$ = newNode(NODE_PROC_STMT);
      addChild($$, $1);
    }
  | id_tok LPAREN expression_list RPAREN {
      printf("Reduction ( procedure_statement -> ID (expression_list) )\n");
      $$ = newNode(NODE_PROC_STMT);
      addChild($$, $1);
      addChild($$, newNode(PUC_LPAREN));
      addChild($$, $3);
      addChild($$, newNode(PUC_RPAREN));
    }
  ;


expression_list :
   expression {
      printf("Reduction ( expression_list -> expression )\n");

      $$ = newNode(NODE_EXPR_LI);
      addChild($$, $1);
    }
  | expression_list COMMA expression {
      printf("Reduction ( expression_list -> expression_list, expression )\n");

      $$ = newNode(NODE_EXPR_LI);
      addChild($$, $1);
      addChild($$, newNode(PUC_COMMA));
      addChild($$, $3);
    }
  ;


expression :
    simple_expression {
      printf("Reduction ( expression -> simple_expression )\n");
      $$ = newNode(NODE_EXPR);
      addChild($$, $1);
    }
  | simple_expression relop simple_expression {
      printf("Reduction ( expression -> simple_expression relop simple_expression )\n");
      $$ = newNode(NODE_EXPR);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


simple_expression :
  term {
      printf("Reduction ( simple_expression -> term )\n");
      $$ = newNode(NODE_SI_EXPR);
      addChild($$, $1);
    }
  | simple_expression addop term {
      printf("Reduction ( simple_expression -> simple_expression addop term )\n");
      $$ = newNode(NODE_SI_EXPR);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


term :
  factor {
      printf("Reduction ( term -> factor )\n");
      $$ = newNode(NODE_TERM);
      addChild($$, $1);
    }
  | term mulop factor {
      printf("Reduction ( term -> term mulop factor )\n");
      $$ = newNode(NODE_TERM);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


factor :
    id_tok tail {
      printf("Reduction ( factor -> id tail )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, $1);
      addChild($$, $2);
    }
  | id_tok LPAREN expression_list RPAREN {
      printf("Reduction ( factor -> id ( expression_list ) )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, $1);
      addChild($$, newNode(PUC_LPAREN));
      addChild($$, $3);
      addChild($$, newNode(PUC_RPAREN));
    }
  | NUM {
      printf("Reduction ( factor -> NUM )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, newNode(NODE_NUM));
    }
  | CHARACTER_STRING {
      printf("Reduction ( factor -> CHARACTER_STRING )\n");
      $$ = newNode(NODE_FACTOR);
      addChild($$, newNode(NODE_STRING));
    }
  | addop NUM {
      printf("Reduction ( factor -> addop NUM )\n");
      $$ = newNode(NODE_FACTOR);
      addChild($$, $1);
      addChild($$, newNode(NODE_NUM));
    }
  | LPAREN expression RPAREN {
      printf("Reduction ( factor -> ( expression ) )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, newNode(PUC_LPAREN));
      addChild($$, $2);
      addChild($$, newNode(PUC_RPAREN));
    }
  | NOT factor {
      printf("Reduction ( factor -> NOT factor )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, newNode(RE_NOT));
      addChild($$, $2);
    }
   ;


addop :
      PLUS {
          printf("Reduction ( addop -> + )\n");

          $$ = newNode(NODE_ADDOP);
          addChild($$, newNode(OP_PLUS));
      }
   |  MINUS {
           printf("Reduction ( addop -> - )\n");

           $$ = newNode(NODE_ADDOP);
           addChild($$, newNode(OP_MINUS));
      }
   ;


mulop :
      STAR {
          printf("Reduction ( mulop -> * )\n");

          $$ = newNode(NODE_MULOP);
          addChild($$, newNode(OP_MUL));
      }
  |   SLASH{
          printf("Reduction ( mulop -> / )\n");

          $$ = newNode(NODE_MULOP);
          addChild($$, newNode(OP_DIV));
      }
  ;

relop :
    LT {
       printf("Reduction ( relop -> < )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_LT));
    }
  | GT {
       printf("Reduction ( relop -> > )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_GT));
    }
  | EQUAL {
       printf("Reduction ( relop -> = )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_EQUAL));
    }
  | LE {
       printf("Reduction ( relop -> <= )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_LE));
    }
  | GE {
       printf("Reduction ( relop -> >= )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_GE));
    }
  | notEQUAL {
       printf("Reduction ( relop -> != )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_notEQUAL));
    }
  ;

%%




int main()
{
    pFile = fopen( "result.txt", "a" );

    yyparse();
    printf("-----------------------------------------------\n");
    printTree(ASTROOT, 0);

    fclose(pFile);

    return 0;
}
