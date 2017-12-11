#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

struct Node* newNode(int type) {
    struct Node *node = new Node;
    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;

    return node;
}

void addChild(Node* node, Node *child) {
    child->parent = node;

	  node->childs.push_back(child);
}

void deleteNode(struct Node *node) {
    if(node->string != NULL)
        free(node->string);
    free(node);
}

void printTree(struct Node *node, int ident) {
    static char blank[1024];

    for(int i=0; i<ident; i++)
        blank[i] = ' ';
    blank[ident] = 0;

    switch(node->nodeType) {
        case OP_ADD:
            printf("%s|-ADD\n", blank);
            break;
        case OP_SUB:
            printf("%s|-SUB\n", blank);
            break;
        case NODE_INT:
            printf("%s|-%d\n", blank, node->iValue);
            ident += 3;
            break;
        case NODE_STMT:
            printf("%s|-STMT\n", blank);
            ident += 3;
            break;
        case NODE_TERM:
            printf("%s|-TERM\n", blank);
            ident += 3;
            break;
        case NODE_PROGRAM:
            printf("%s|-PROGRAM\n", blank);
            ident += 3;
            break;
    		case NODE_ID:
    			printf("%s|-[ID] ", blank);
          cout << node->strValue << endl;
    			ident += 3;
    			break;
        case ID_TOK:
    			break;
    		case NODE_DECL:
    			printf("%s|-DECL\n", blank);
    			ident += 3;
    			break;
        case NODE_EXPR:
            printf("%s|-EXPR\n", blank);
            ident += 3;
            break;
        case NODE_VAR:
            printf("%s|-VAR\n", blank);
            ident += 3;
            break;
        case NODE_ID_LT:
            printf("%s|-ID_LIST\n", blank);
            ident += 3;
            break;
        case PUC_COMMA:
            printf("%s|- ,\n", blank);
            ident += 3;
            break;
        case PUC_LBRAC:
            printf("%s|- [ \n", blank);
            ident += 3;
            break;
        case PUC_RBRAC:
            printf("%s|- ]\n", blank);
            ident += 3;
            break;
        case PUC_DOTDOT:
            printf("%s|- ..\n", blank);
            ident += 3;
            break;
        case PUC_COLON:
            printf("%s|- :\n", blank);
            ident += 3;
            break;
        case PUC_SEMI:
            printf("%s|- ;\n", blank);
            ident += 3;
            break;
        case TY_INT:
            printf("%s|-INTEGER(type)\n", blank);
            ident += 3;
            break;
        case NODE_STDTYPE:
            printf("%s|-STDTYPE\n", blank);
            ident += 3;
            break;
        case NODE_TYPE:
            printf("%s|-TYPE\n", blank);
            ident += 3;
            break;
        case RE_ARR:
            printf("%s|-ARRAY\n", blank);
            ident += 3;
            break;
        case RE_OF:
            printf("%s|-OF\n", blank);
            ident += 3;
            break;
        case NODE_NUM:
            printf("%s|-[NUM] ", blank);
            cout << node->number << endl;
            ident += 3;
            break;
        case NUM_TOK:
            break;
        case NODE_LAMDBA:
            printf("%s|- (LAMDBA)\n", blank);
            ident += 3;
            break;
        case NODE_STRING      : printf("%s|-STRING\n", blank);ident += 3; break;
        case NODE_IF_STMT     : printf("%s|-IF_STMT\n", blank);ident += 3; break;
        case NODE_OPTVAR      : printf("%s|-OPTVAR\n", blank);ident += 3; break;
        case NODE_RELOP       : printf("%s|-RELOP\n", blank); ident += 3;break;
        case NODE_MULOP       : printf("%s|-MULOP\n", blank); ident += 3;break;
        case NODE_ADDOP       : printf("%s|-ADDOP\n", blank); ident += 3;break;
        case NODE_FACTOR      : printf("%s|-FACTOR\n", blank);ident += 3; break;
        case NODE_TREM        : printf("%s|-TERM\n", blank); ident += 3; break;
        case NODE_SI_EXPR     : printf("%s|-SI_EXPR\n", blank); ident += 3; break;
        case NODE_EXPR_LI     : printf("%s|-EXPR_LI\n", blank); ident += 3; break;
        case NODE_PROC_STMT   : printf("%s|-PROC_STMT\n", blank); ident += 3; break;
        case NODE_TAIL        : printf("%s|-TAIL\n", blank); ident += 3; break;
        case NODE_COMP_STMT   : printf("%s|-COMP_STMT\n", blank); ident += 3; break;
        case NODE_STMT_LI     : printf("%s|-STMT_LI\n", blank); ident += 3;break;
        case NODE_OPT_STMT    : printf("%s|-OPT_STMT\n", blank);ident += 3; break;
        case NODE_PARAM_LI    : printf("%s|-PARAM_LI\n", blank);ident += 3; break;
        case NODE_ARG         : printf("%s|-ARG\n", blank); ident += 3;break;
        case NODE_SPROG_H     : printf("%s|-SPROG\n", blank);ident += 3; break;
        case NODE_SPROG_DECL  : printf("%s|-SPROG_DECL\n", blank);ident += 3; break;
        case NODE_SPROG_DECLS : printf("%s|-SPROG_DECLS\n", blank); ident += 3;break;
        case NODE_START       : printf("%s|-START\n", blank); ident += 3;break;
        case OP_notEQUAL      : printf("%s|-NOTEQUAL\n", blank);ident += 3; break;
        case OP_GE            : printf("%s|- >=\n", blank);ident += 3; break;
        case OP_LE            : printf("%s|- <=\n", blank);ident += 3; break;
        case OP_EQUAL         : printf("%s|- =\n", blank); ident += 3;break;
        case OP_GT            : printf("%s|- >\n", blank); ident += 3;break;
        case OP_LT            : printf("%s|- <\n", blank); ident += 3;break;
        case OP_MUL           : printf("%s|-MUL\n", blank);ident += 3; break;
        case OP_DIV           : printf("%s|-DIV\n", blank);ident += 3; break;
        case OP_PLUS          : printf("%s|-ADD\n", blank);ident += 3; break;
        case OP_MINUS      : printf("%s|-MINUS\n", blank);ident += 3; break;
        case PUC_LPAREN       : printf("%s|- ( \n", blank);ident += 3; break;
        case PUC_RPAREN       : printf("%s|- ) \n", blank);ident += 3; break;
        case PUC_DOT          : printf("%s|- . \n", blank);ident += 3; break;
        case RE_NOT           : printf("%s|-NOT\n", blank);ident += 3; break;
        case RE_VAR           : printf("%s|-VAR\n", blank);ident += 3; break;
        case RE_ASGMNT        : printf("%s|-ASGMNT\n", blank);ident += 3; break;
        case RE_IF            : printf("%s|-IF\n", blank);ident += 3; break;
        case RE_THEN          : printf("%s|-THEN\n", blank); ident += 3;break;
        case RE_ELSE          : printf("%s|-ELSE\n", blank); ident += 3;break;
        case RE_WHILE         : printf("%s|-WHILE\n", blank);ident += 3; break;
        case RE_DO            : printf("%s|-DO\n", blank);ident += 3; break;
        case RE_BEGIN         : printf("%s|-BEGIN\n", blank);ident += 3; break;
        case RE_END           : printf("%s|-END\n", blank);ident += 3; break;
        case RE_FUNC          : printf("%s|-FUNCTION\n", blank);ident += 3; break;
        case RE_PROC          : printf("%s|-PROCEDURE\n", blank); ident += 3;break;
        case RE_PROG          : printf("%s|-PROGRAM\n", blank); ident += 3;break;
        case RE_CONST         : printf("%s|-CONST\n", blank); ident += 3;break;
        case RE_TYPE          : printf("%s|-TYPE\n", blank); ident += 3;break;
        case TY_REAL          : printf("%s|-REAL\n", blank);ident += 3; break;
        case TY_STR           : printf("%s|-STRING\n", blank);ident += 3; break;

        default:
            printf("%sdefault:%d\n", blank, node->nodeType);
          break;
    }

	if (!node->childs.empty())
	{
		for (size_t i = 0; i < node->childs.size(); i++)
		{
			printTree(node->childs[i], ident);
		}
	}
}
