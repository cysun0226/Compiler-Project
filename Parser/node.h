#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include <string>
using namespace std;

struct Node;
enum ntype {
	VALUE_INVALID,
    NODE_INT,
    NODE_TERM,
    NODE_PROGRAM,
		NODE_ID,
		NODE_DECL,
    NODE_STMT,
    NODE_EXPR,
		NODE_VAR,
		NODE_ID_LT,
    OP_ADD,
    OP_SUB,
		PUC_COMMA,
		PUC_LBRAC,
		PUC_RBRAC,
		PUC_DOTDOT,
		PUC_COLON,
		PUC_SEMI,
		TY_INT,
		NODE_STDTYPE,
		NODE_TYPE,
		RE_ARR,
		RE_OF,
		NODE_NUM,
		NODE_STRING,
		NODE_LAMDBA,
		NODE_OPTVAR,
		NODE_RELOP,
		NODE_MULOP,
		NODE_ADDOP,
		NODE_FACTOR,
		NODE_TREM,
		NODE_SI_EXPR,
		NODE_EXPR_LI,
		NODE_PROC_STMT,
		NODE_TAIL,
		NODE_COMP_STMT,
		NODE_STMT_LI,
		NODE_OPT_STMT,
		NODE_PARAM_LI,
		NODE_ARG,
		NODE_SPROG_H,
		NODE_SPROG_DECL,
		NODE_SPROG_DECLS,
		NODE_IF_STMT,
		NODE_START,
		OP_notEQUAL,
		OP_GE,
		OP_LE,
		OP_EQUAL,
		OP_GT,
		OP_LT,
		OP_MUL,
		OP_DIV,
		OP_PLUS,
		OP_MINUS,
		PUC_LPAREN,
		PUC_RPAREN,
		PUC_DOT,
		RE_NOT,
		RE_VAR,
		RE_ASGMNT,
		RE_IF,
		RE_THEN,
		RE_ELSE,
		RE_WHILE,
		RE_DO,
		RE_BEGIN,
		RE_END,
		RE_FUNC,
		RE_PROC,
		RE_PROG,
		RE_CONST,
		RE_TYPE,
		TY_REAL,
		TY_STR
};

// #include "symtab.h"
typedef struct Node {
    int nodeType;
    struct Node *parent;
	vector<Node*> childs;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    /* items for Array */
    int idxstart;
    int idxend;
    int arraydepth;
    struct Node *ref;

    /* Values for general use */
    int iValue;
    double rValue;
    char valueValid;
    char* string;

    /* Indicates which OP */
    char op;

} Node;

struct Node* newNode(int type);
void deleteNode(struct Node* node);
void addChild(struct Node *node, struct Node *child);
void printTree(struct Node *node, int ident);

#endif
