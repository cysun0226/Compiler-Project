%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <iostream>
    #include <fstream>
    #include "symtab.h"
    #include "visitor.h"
    #include "node.h"


    using namespace std;
    FILE *pFile;
    FILE *spFile;
    int line_no = 1;

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
            fprintf( pFile, "error! \n");
            fclose(pFile);
            fprintf( stderr,"error: %s\n",str);
        }

    }

    Node* PARSE_ROOT;


%}

%union
{
    struct Node* node;
    double number;
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
%token <number> NUM
%token <node> REAL_NUM

%type <node> prog identifier_list declarations type standard_type
%type <node> subprogram_declarations subprogram_declaration
%type <node> subprogram_head arguments parameter_list if_stmt
%type <node> optional_var compound_statement optional_statements
%type <node> statement_list statement variable tail term num_tok
%type <node> procedure_statement expression_list expression
%type <node> simple_expression factor addop mulop relop id_tok



%%

prog :
  PROGRAM id_tok LPAREN identifier_list RPAREN SEMICOLON
  declarations
  subprogram_declarations
  compound_statement
  DOT {
     fprintf( spFile, "Reduction ( prog -> PROGRAM ID (identifier_list); \n");
     fprintf( spFile, "                    declarations \n");
     fprintf( spFile, "                    subprogram_declarations \n");
     fprintf( spFile, "                    compound_statement \n");
     fprintf( spFile, "                    .                             )\n");

     fprintf( pFile, "Parse finish. \n");

     $$ = newNode(NODE_START);
     addChild($$, newNode(RE_PROG));
     addChild($$, $2);
     addChild($$, newNode(PUC_LPAREN));
     addChild($$, $4);
     addChild($$, newNode(PUC_RPAREN));
     addChild($$, $7);
     addChild($$, $8);
     addChild($$, $9);
     addChild($$, newNode(PUC_DOT));
     PARSE_ROOT = $$;
  }
;


identifier_list :
    ID {
      fprintf( spFile, "Reduction ( identifier_list -> ID )\n");
      $$ = newNode(NODE_ID_LT);
      Node* id_node = newNode(NODE_ID);
      id_node->strValue = $1;
      id_node->line_num = line_no;
      addChild($$, id_node);
    }
  | identifier_list COMMA ID {
      fprintf( spFile, "Reduction ( identifier_list -> identifier_list , ID )\n");
      $$ = newNode(NODE_ID_LT);
      addChild($$, $1);
      addChild($$, newNode(PUC_COMMA));
      Node* id_node = newNode(NODE_ID);
      id_node->strValue = $3;
      id_node->line_num = line_no;
      addChild($$, id_node);
    }
  ;

id_tok :
  ID {
    // fprintf( spFile, "Reduction ( id_tok -> ID )\n");
    $$ = newNode(ID_TOK);
    Node* id_node = newNode(NODE_ID);
    id_node->strValue = $1;
    id_node->line_num = line_no;
    addChild($$, id_node);
  }
  ;

num_tok :
  NUM {
    $$ = newNode(NUM_TOK);
    Node* id_node = newNode(NODE_NUM);
    id_node->number = $1;
    addChild($$, id_node);
  }
  ;

declarations :
    declarations VAR identifier_list COLON type SEMICOLON {
      fprintf( spFile, "Reduction ( declarations -> declarations VAR identifier_list : type ; )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, $1);
      addChild($$, newNode(NODE_VAR));
      addChild($$, $3);
      addChild($$, newNode(PUC_COLON));
      addChild($$, $5);
      addChild($$, newNode(PUC_SEMI));
    }
  | declarations VAR identifier_list COLON identifier_list SEMICOLON {
      fprintf( spFile, "Reduction ( declarations -> declarations VAR identifier_list : id ; )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, $1);
      addChild($$, newNode(NODE_VAR));
      addChild($$, $3);
      addChild($$, newNode(PUC_COLON));
      addChild($$, $5);
      addChild($$, newNode(PUC_SEMI));
    }
  | declarations CONST identifier_list EQUAL num_tok SEMICOLON {
    fprintf( spFile, "Reduction ( declarations -> declarations CONST identifier_list = NUM ; )\n");
    $$ = newNode(NODE_DECL); // $$ = declarations
    addChild($$, $1);
    addChild($$, newNode(RE_CONST));
    addChild($$, $3);
    addChild($$, newNode(OP_EQUAL));
    addChild($$, $5);
    addChild($$, newNode(PUC_SEMI));
    }
  | declarations TYPE identifier_list EQUAL type SEMICOLON  {
    fprintf( spFile, "Reduction ( declarations -> declarations TYPE identifier_list = type ; )\n");
    $$ = newNode(NODE_DECL); // $$ = declarations
    addChild($$, $1);
    addChild($$, newNode(RE_TYPE));
    addChild($$, $3);
    addChild($$, newNode(OP_EQUAL));
    addChild($$, $5);
    addChild($$, newNode(PUC_SEMI));
    }
  /*| PROCEDURE id arguments SEMICOLON {
      fprintf( spFile, "Reduction ( declarations -> PROCEDURE id arguments SEMICOLON )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, newNode(RE_PROC));
      addChild($$, newNode(NODE_ID));
      addChild($$, $3);
      addChild($$, newNode(PUC_SEMI));
    }*/
  | {
      fprintf( spFile, "Reduction ( declarations -> LAMDBA )\n");
      $$ = newNode(NODE_DECL);
      addChild($$, newNode(NODE_LAMDBA));
    }
  ;


type :
    standard_type {
      fprintf( spFile, "Reduction ( type -> standard_type )\n");

      $$ = newNode(NODE_TYPE);
      addChild($$, $1);
    }
  | ARRAY LBRAC num_tok DOTDOT num_tok RBRAC OF type {
      fprintf( spFile, "Reduction ( type -> ARRAY [NUM .. NUM] OF type )\n");

      $$ = newNode(NODE_TYPE);
      // addChild($$, newNode(RE_ARR));
      Node* arr_node = newNode(RE_ARR);
      arr_node->strValue = "ARRAY";
      arr_node->line_num = line_no;
      addChild($$, arr_node);
      addChild($$, $3);
      addChild($$, $5);
      addChild($$, $8);
    }
  | ARRAY LBRAC id_tok DOTDOT num_tok RBRAC OF type {
      fprintf( spFile, "Reduction ( type -> ARRAY [ID .. NUM] OF type )\n");

      $$ = newNode(NODE_TYPE);
      // addChild($$, newNode(RE_ARR));
      Node* arr_node = newNode(RE_ARR);
      arr_node->strValue = "ARRAY";
      arr_node->line_num = line_no;
      addChild($$, arr_node);
      addChild($$, $3);
      addChild($$, $5);
      addChild($$, $8);
    }
  | ARRAY LBRAC num_tok DOTDOT id_tok RBRAC OF type {
      fprintf( spFile, "Reduction ( type -> ARRAY [NUM .. ID] OF type )\n");
      $$ = newNode(NODE_TYPE);
      // addChild($$, newNode(RE_ARR));
      Node* arr_node = newNode(RE_ARR);
      arr_node->strValue = "ARRAY";
      arr_node->line_num = line_no;
      addChild($$, arr_node);
      addChild($$, $3);
      addChild($$, $5);
      addChild($$, $8);
    }
  | ARRAY LBRAC id_tok DOTDOT id_tok RBRAC OF type {
      fprintf( spFile, "Reduction ( type -> ARRAY [id .. id] OF type )\n");

      $$ = newNode(NODE_TYPE);
      // addChild($$, newNode(RE_ARR));
      Node* arr_node = newNode(RE_ARR);
      arr_node->strValue = "ARRAY";
      arr_node->line_num = line_no;
      addChild($$, arr_node);
      addChild($$, $3);
      addChild($$, $5);
      addChild($$, $8);
    }
  ;


standard_type :
    INTEGER {
      fprintf( spFile, "Reduction ( standard_type -> INTEGER )\n");
      $$ = newNode(NODE_STDTYPE);
      // addChild($$, newNode(TY_INT));

      Node* ty_node = newNode(TY_INT);
      ty_node->strValue = "INTEGER";
      addChild($$, ty_node);
    }
  | REAL {
      fprintf( spFile, "Reduction ( standard_type -> REAL )\n");
      $$ = newNode(NODE_STDTYPE);
      // addChild($$, newNode(TY_REAL));

      Node* ty_node = newNode(TY_REAL);
      ty_node->strValue = "REAL";
      addChild($$, ty_node);
    }
  | CHARACTER_STRING {
      fprintf( spFile, "Reduction ( standard_type -> CHARACTER_STRING )\n");
      $$ = newNode(NODE_STDTYPE);
      // addChild($$, newNode(TY_STR));

      Node* ty_node = newNode(TY_STR);
      ty_node->strValue = "STRING";
      addChild($$, ty_node);
    }
  /*
  | identifier_list {
      fprintf( spFile, "Reduction ( standard_type -> identifier_list )\n");
      $$ = newNode(NODE_STDTYPE);
      addChild($$, $1);
    }
  */
  ;



subprogram_declarations :
  subprogram_declarations subprogram_declaration SEMICOLON {
      fprintf( spFile, "Reduction ( subprogram_declarations -> subprogram_declarations subprogram_declaration ; )\n");
      $$ = newNode(NODE_SPROG_DECLS);
      addChild($$, $1);
      addChild($$, $2);
   }
 | {
      fprintf( spFile, "Reduction ( subprogram_declarations -> LAMDBA )\n");
      $$ = newNode(NODE_SPROG_DECLS);
      addChild($$, newNode(NODE_LAMDBA));
   }
 ;


subprogram_declaration :
  subprogram_head	declarations compound_statement {
      fprintf( spFile, "Reduction ( subprogram_declaration -> subprogram_head declarations compound_statement )\n");
      $$ = newNode(NODE_SPROG_DECL);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


subprogram_head :
    FUNCTION id_tok arguments COLON standard_type SEMICOLON {
      fprintf( spFile, "Reduction ( subprogram_head -> FUNCTION id arguments : standard_type ; )\n");
      $$ = newNode(NODE_SPROG_H);
      addChild($$, newNode(RE_FUNC));
      addChild($$, $2);
      addChild($$, $3);
      addChild($$, $5);
    }
  | PROCEDURE id_tok arguments SEMICOLON {
      fprintf( spFile, "Reduction ( subprogram_head -> PROCEDURE id arguments ; )\n");
      $$ = newNode(NODE_SPROG_H);
      addChild($$, newNode(RE_PROC));
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


arguments :
    LPAREN parameter_list RPAREN {
      fprintf( spFile, "Reduction ( arguments -> (parameter_list) )\n");
      $$ = newNode(NODE_ARG);
      addChild($$, $2);
    }
  | {
      fprintf( spFile, "Reduction ( arguments -> LAMDBA )\n");
      $$ = newNode(NODE_ARG);
      addChild($$, newNode(NODE_LAMDBA));
    }
  ;


parameter_list :
    optional_var identifier_list COLON type {
      fprintf( spFile, "Reduction ( parameter_list -> optional_var identifier_list : type )\n");
      $$ = newNode(NODE_PARAM_LI);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $4);
    }
  | optional_var identifier_list COLON identifier_list {
    fprintf( spFile, "Reduction ( parameter_list -> optional_var identifier_list : identifier_list )\n");
    $$ = newNode(NODE_PARAM_LI);
    addChild($$, $1);
    addChild($$, $2);
    addChild($$, $4);
    }
  | optional_var identifier_list COLON type SEMICOLON parameter_list {
      fprintf( spFile, "Reduction ( parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
      $$ = newNode(NODE_PARAM_LI);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $4);
      addChild($$, $6);
    }
  ;


optional_var :
  VAR {
      fprintf( spFile, "Reduction ( optional_var -> VAR )\n");
      $$ = newNode(NODE_OPTVAR);
      addChild($$, newNode(RE_VAR));
    }
  | {
      fprintf( spFile, "Reduction ( optional_var -> LAMDBA )\n");
      $$ = newNode(NODE_OPTVAR);
      addChild($$, newNode(NODE_LAMDBA));
    }
  ;


compound_statement :
    PBEGIN optional_statements END {
      fprintf( spFile, "Reduction ( compound_statement -> begin optional_statements end )\n");
      $$ = newNode(NODE_COMP_STMT);
      addChild($$, newNode(RE_BEGIN));
      addChild($$, $2);
      addChild($$, newNode(RE_END));
    }
  ;


optional_statements :
    statement_list {
      fprintf( spFile, "Reduction ( optional_statements -> statement_list )\n");
      $$ = newNode(NODE_OPT_STMT);
      addChild($$, $1);
    }
  ;


statement_list :
    statement {
      fprintf( spFile, "Reduction ( statement_list -> statement )\n");
      $$ = newNode(NODE_STMT_LI);
      addChild($$, $1);
    }
  | statement_list SEMICOLON statement {
      fprintf( spFile, "Reduction ( statement_list -> statement_list ; statement )\n");
      $$ = newNode(NODE_STMT_LI);
      addChild($$, $1);
      addChild($$, newNode(PUC_SEMI));
      addChild($$, $3);
    }
  ;


statement :
    variable ASSIGNMENT expression {
      fprintf( spFile, "Reduction ( statement -> variable := expression )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, $1);
      addChild($$, newNode(RE_ASGMNT));
      addChild($$, $3);
    }
  | procedure_statement {
      fprintf( spFile, "Reduction ( statement -> procedure_statement )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, $1);
    }
  | compound_statement {
      fprintf( spFile, "Reduction ( statement -> compound_statement )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, $1);
    }
  | IF expression THEN if_stmt {
      fprintf( spFile, "Reduction ( statement -> IF expression THEN if_stmt )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, newNode(RE_IF));
      addChild($$, $2);
      addChild($$, newNode(RE_THEN));
      addChild($$, $4);
    }
  | WHILE expression DO statement {
      fprintf( spFile, "Reduction ( statement -> WHILE expression DO statement )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, newNode(RE_WHILE));
      addChild($$, $2);
      addChild($$, newNode(RE_DO));
      addChild($$, $4);
    }
  | {
      fprintf( spFile, "Reduction ( statement -> lambda )\n");
      $$ = newNode(NODE_STMT);
      addChild($$, newNode(NODE_LAMDBA));
  }
  ;


if_stmt :
    statement ELSE statement {
        fprintf( spFile, "Reduction ( if_stmt -> statement ELSE statement )\n");
        $$ = newNode(NODE_IF_STMT);
        addChild($$, $1);
        addChild($$, newNode(RE_ELSE));
        addChild($$, $3);
    }
  | statement {
        fprintf( spFile, "Reduction ( if_stmt -> statement )\n");
        $$ = newNode(NODE_IF_STMT);
        addChild($$, $1);
    }


variable :
  id_tok tail {
      fprintf( spFile, "Reduction ( variable -> id tail )\n");
      $$ = newNode(NODE_VAR);
      addChild($$, $1);
      addChild($$, $2);
    }
;


tail :
  LBRAC expression RBRAC tail {
      fprintf( spFile, "Reduction ( tail -> [expression] tail )\n");
      $$ = newNode(NODE_TAIL);
      addChild($$, newNode(PUC_LBRAC));
      addChild($$, $2);
      addChild($$, newNode(PUC_RBRAC));
      addChild($$, $4);
    }
  | {
      fprintf( spFile, "Reduction ( tail -> lambda )\n");
      $$ = newNode(NODE_TAIL);
      addChild($$, newNode(NODE_LAMDBA));
  }
  ;


procedure_statement :
  id_tok {
      fprintf( spFile, "Reduction ( procedure_statement -> ID )\n");
      $$ = newNode(NODE_PROC_STMT);
      addChild($$, $1);
    }
  | id_tok LPAREN expression_list RPAREN {
      fprintf( spFile, "Reduction ( procedure_statement -> ID (expression_list) )\n");
      $$ = newNode(NODE_PROC_STMT);
      addChild($$, $1);
      addChild($$, newNode(PUC_LPAREN));
      addChild($$, $3);
      addChild($$, newNode(PUC_RPAREN));
    }
  ;


expression_list :
   expression {
      fprintf( spFile, "Reduction ( expression_list -> expression )\n");

      $$ = newNode(NODE_EXPR_LI);
      addChild($$, $1);
    }
  | expression_list COMMA expression {
      fprintf( spFile, "Reduction ( expression_list -> expression_list, expression )\n");

      $$ = newNode(NODE_EXPR_LI);
      addChild($$, $1);
      addChild($$, newNode(PUC_COMMA));
      addChild($$, $3);
    }
  ;


expression :
    simple_expression {
      fprintf( spFile, "Reduction ( expression -> simple_expression )\n");
      $$ = newNode(NODE_EXPR);
      addChild($$, $1);
    }
  | simple_expression relop simple_expression {
      fprintf( spFile, "Reduction ( expression -> simple_expression relop simple_expression )\n");
      $$ = newNode(NODE_EXPR);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


simple_expression :
  term {
      fprintf( spFile, "Reduction ( simple_expression -> term )\n");
      $$ = newNode(NODE_SI_EXPR);
      addChild($$, $1);
    }
  | simple_expression addop term {
      fprintf( spFile, "Reduction ( simple_expression -> simple_expression addop term )\n");
      $$ = newNode(NODE_SI_EXPR);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


term :
  factor {
      fprintf( spFile, "Reduction ( term -> factor )\n");
      $$ = newNode(NODE_TERM);
      addChild($$, $1);
    }
  | term mulop factor {
      fprintf( spFile, "Reduction ( term -> term mulop factor )\n");
      $$ = newNode(NODE_TERM);
      addChild($$, $1);
      addChild($$, $2);
      addChild($$, $3);
    }
  ;


factor :
    id_tok tail {
      fprintf( spFile, "Reduction ( factor -> id tail )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, $1);
      addChild($$, $2);
    }
  | id_tok LPAREN expression_list RPAREN {
      fprintf( spFile, "Reduction ( factor -> id ( expression_list ) )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, $1);
      addChild($$, newNode(PUC_LPAREN));
      addChild($$, $3);
      addChild($$, newNode(PUC_RPAREN));
    }
  | num_tok {
      fprintf( spFile, "Reduction ( factor -> NUM )\n");
      $$ = newNode(NODE_FACTOR);
      addChild($$, $1);
    }
  | CHARACTER_STRING {
      fprintf( spFile, "Reduction ( factor -> CHARACTER_STRING )\n");
      $$ = newNode(NODE_FACTOR);
      addChild($$, newNode(NODE_STRING));
    }
  | addop num_tok {
      fprintf( spFile, "Reduction ( factor -> addop NUM )\n");
      $$ = newNode(NODE_FACTOR);
      addChild($$, $1);
      addChild($$, $2);
    }
  | LPAREN expression RPAREN {
      fprintf( spFile, "Reduction ( factor -> ( expression ) )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, newNode(PUC_LPAREN));
      addChild($$, $2);
      addChild($$, newNode(PUC_RPAREN));
    }
  | NOT factor {
      fprintf( spFile, "Reduction ( factor -> NOT factor )\n");

      $$ = newNode(NODE_FACTOR);
      addChild($$, newNode(RE_NOT));
      addChild($$, $2);
    }
   ;


addop :
      PLUS {
          fprintf( spFile, "Reduction ( addop -> + )\n");

          $$ = newNode(NODE_ADDOP);
          addChild($$, newNode(OP_PLUS));
      }
   |  MINUS {
           fprintf( spFile, "Reduction ( addop -> - )\n");

           $$ = newNode(NODE_ADDOP);
           addChild($$, newNode(OP_MINUS));
      }
   ;


mulop :
      STAR {
          fprintf( spFile, "Reduction ( mulop -> * )\n");

          $$ = newNode(NODE_MULOP);
          addChild($$, newNode(OP_MUL));
      }
  |   SLASH{
          fprintf( spFile, "Reduction ( mulop -> / )\n");

          $$ = newNode(NODE_MULOP);
          addChild($$, newNode(OP_DIV));
      }
  ;

relop :
    LT {
       fprintf( spFile, "Reduction ( relop -> < )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_LT));
    }
  | GT {
       fprintf( spFile, "Reduction ( relop -> > )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_GT));
    }
  | EQUAL {
       fprintf( spFile, "Reduction ( relop -> = )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_EQUAL));
    }
  | LE {
       fprintf( spFile, "Reduction ( relop -> <= )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_LE));
    }
  | GE {
       fprintf( spFile, "Reduction ( relop -> >= )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_GE));
    }
  | notEQUAL {
       fprintf( spFile, "Reduction ( relop -> != )\n");

       $$ = newNode(NODE_RELOP);
       addChild($$, newNode(OP_notEQUAL));
    }
  ;

%%




int main()
{
    pFile = fopen( "result.txt", "a" );
    spFile = fopen( "parse_records.txt", "a" );

    yyparse();
    // printf( "------------------ parse tree --------------------\n");
    // printTree(PARSE_ROOT, 0);
    // printf( "\n------------------- ast tree ---------------------\n");
    Node* ast_root = new Node;
    ast_root = buildAstTree(PARSE_ROOT);
    // printTree(ast_root, 0);
    printf( "\n\n------------------- scope tree ---------------------\n\n");
    divideScope(ast_root, 0);
    printf( "\n\n------------------- code generate ---------------------\n\n");
    std::vector<Symtab*> symtabs = getSymtab();
    LHSVisitor lhs_visitor(ast_root, symtabs);
    lhs_visitor.visit(ast_root, 0);

    // lv.visit(ast_root, 0);

    // MethodBodyVisitor mv(ast_root);
    // mv.visit(ast_root, 0);



    fclose(pFile);

    return 0;
}
