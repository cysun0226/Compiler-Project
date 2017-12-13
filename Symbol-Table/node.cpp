#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;
extern int line_no;

struct Node* newNode(int type) {
    struct Node *node = new Node;
    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;

    return node;
}

void copyNode(Node* new_node, Node* old) {
  new_node->strValue = old->strValue;
  new_node->nodeType = old->nodeType;
  new_node->parent = old->parent;
  new_node->number = old->number;
  new_node->line_num = old->line_num;
  for (int i = 0; i < old->childs.size(); i++) {
    new_node->childs.push_back(old->childs[i]);
  }
}

void moveChild(Node* new_node, Node* old)
{
  new_node->childs.clear();
  for (int i = 0; i < old->childs.size(); i++) {
    new_node->childs.push_back(old->childs[i]);
  }
}

void addChild(Node* node, Node *child) {
    child->parent = node;
	  node->childs.push_back(child);
}

void deleteChild(Node* node) {
	  node->childs.clear();
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
        case OP_ADD           : printf("%s|-ADD\n", blank); break;
        case OP_SUB           : printf("%s|-SUB\n", blank); break;
        case NODE_INT         : printf("%s|-%d\n", blank, node->iValue); ident += 3; break;
        case NODE_STMT        : printf("%s|-STMT\n", blank); ident += 3; break;
        case NODE_TERM        : printf("%s|-TERM\n", blank); ident += 3; break;
        case NODE_PROGRAM     : printf("%s|-PROGRAM\n", blank); ident += 3; break;
    		case NODE_ID          : printf("%s|-[ID] ", blank); cout << node->strValue << " (line " << node->line_num << ")" << endl; ident += 3; break;
        case ID_TOK           : printf("%s|-ID_TOK\n", blank); ident += 3; break;
    		case NODE_DECL        : printf("%s|-DECL\n", blank); ident += 3; break;
        case NODE_EXPR        : printf("%s|-EXPR\n", blank); ident += 3; break;
        case NODE_VAR         : printf("%s|-VAR(NODE)\n", blank); ident += 3; break;
        case NODE_ID_LT       : printf("%s|-ID_LIST\n", blank); ident += 3; break;
        case PUC_COMMA        : printf("%s|- ,\n", blank); ident += 3; break;
        case PUC_LBRAC        : printf("%s|- [ \n", blank); ident += 3; break;
        case PUC_RBRAC        : printf("%s|- ]\n", blank); ident += 3; break;
        case PUC_DOTDOT       : printf("%s|- ..\n", blank); ident += 3; break;
        case PUC_COLON        : printf("%s|- :\n", blank); ident += 3; break;
        case PUC_SEMI         : printf("%s|- ;\n", blank); ident += 3; break;
        case TY_INT           : printf("%s|-INTEGER(type)\n", blank);ident += 3;break;
        case NODE_STDTYPE     : printf("%s|-STDTYPE\n", blank);ident += 3;break;
        case NODE_TYPE        : printf("%s|-TYPE\n", blank);ident += 3;break;
        case RE_ARR           : printf("%s|-ARRAY\n", blank);ident += 3;break;
        case RE_OF            : printf("%s|-OF\n", blank);ident += 3;break;
        case NODE_NUM         : printf("%s|-[NUM] ", blank); cout << node->number << endl; ident += 3; break;
        case NUM_TOK          : printf("%s|-NUM_TOK\n", blank); ident += 3;break;
        case NODE_LAMDBA      : printf("%s|- (LAMDBA)\n", blank); ident += 3;break;
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
        case NODE_DECLS       : printf("%s|-DECLS\n", blank);ident += 3; break;
        case NODE_SPROG_DECLS_LI : printf("%s|-SPROG_DECLS_LI\n", blank);ident += 3; break;


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

void reduce(Node* node);

Node* convertTree(Node* node)
{
  switch (node->nodeType)
  {
    case NODE_ID_LT: {
      std::vector<Node> id_list;
      Node* new_il = newNode(NODE_ID_LT);
      Node* il; il = node;
      while (il->childs[0]->nodeType == NODE_ID_LT) {
        Node* new_id = new Node;
        copyNode(new_id, il->childs[2]);
        addChild(new_il, new_id);
        // id_list.push_back(new_id);
        il = il->childs[0];
      }
      Node* new_id = new Node;
      copyNode(new_id, il->childs[0]);
      // id_list.push_back(new_id);
      addChild(new_il, new_id);
      //
      // for (int i = 0; i < id_list.size(); i++) {
      //   addChild(new_il, id_list[i]);
      // }
      return new_il;
      break;
    }


    default:
      // printf("default:%d\n", node->nodeType);
    break;

  }

  Node* root = new Node;
  root->nodeType = node->nodeType;
  root->line_num = node->line_num;
  root->parent = node->parent;
  if(node->nodeType == NODE_ID) root->strValue = node->strValue;
  if(node->nodeType == NODE_NUM) root->number = node->number;

  if (!node->childs.empty())
	{
		for (size_t i = 0; i < node->childs.size(); i++)
		{
      Node* new_child = convertTree(node->childs[i]);
      if(new_child->nodeType == NODE_ID_LT){
        for (int i = 0; i < new_child->childs.size(); i++) {
          addChild(root, new_child->childs[i]);
        }
      }
      else
        addChild(root, new_child);
		}
	}
  return root;
}

Node* copyTree(Node* node)
{
  Node* cp = new Node;
  cp->nodeType = node->nodeType;
  if(node->nodeType == NODE_ID) cp->strValue = node->strValue;
  if(node->nodeType == NODE_NUM) cp->number = node->number;
  cp->line_num = node->line_num;
  cp->parent = node->parent;

  if (!node->childs.empty())
	{
		for (size_t i = 0; i < node->childs.size(); i++)
		{
      addChild(cp, copyTree(node->childs[i]));
		}
	}
  return cp;
}

void copyChild(Node* node, std::vector<Node*> ori)
{
  node->childs.clear();
  for (int i = 0; i < ori.size(); i++) {
    addChild(node, ori[i]);
  }
}

void copyChildinverse(Node* node, std::vector<Node*> ori)
{
  node->childs.clear();
  for (int i = ori.size()-1; i >= 0; i--) {
    reduce(ori[i]);
    addChild(node, ori[i]);
  }
}

void reduceTYPE(Node* node)
{
  // standard_type
  if (node->childs[0]->nodeType == NODE_STDTYPE){
    node->nodeType = node->childs[0]->childs[0]->nodeType;
    delete node->childs[0]->childs[0]; // STDTYPE
    delete node->childs[0];
    node->childs.clear();
    return;
  }

  // ARRAY
  if (node->childs[0]->nodeType == RE_ARR){
    node->nodeType = RE_ARR;
    node->childs.erase(node->childs.begin());
    return;
  }

}

void removeLAMDBA(Node* node)
{
  if (node->childs[0]->nodeType == NODE_LAMDBA)
    node->parent->childs.erase(node->parent->childs.begin());
}

void reduceDECLlist(Node* node)
{
  removeLAMDBA(node);

  int cur_type = node->nodeType;

  if(node->childs[0]->nodeType != cur_type)
    return;

  std::vector<Node*> list;
  Node* dl; dl = node;
  while (dl->childs[0]->nodeType == cur_type) {
    Node* newDECL = new Node;
    copyNode(newDECL, dl);
    newDECL->childs.erase(newDECL->childs.begin());
    list.push_back(newDECL);
    dl = dl->childs[0];
  }
  if(cur_type == NODE_DECL) node->nodeType = NODE_DECLS;
  if(cur_type == NODE_SPROG_DECLS) node->nodeType = NODE_SPROG_DECLS_LI;
  copyChildinverse(node, list);

  for (int i = 0; i < node->childs.size(); i++)
  {
    reduce(node->childs[i]);
  }

  if(node->nodeType == NODE_SPROG_DECLS_LI)
  {
    for (int i = 0; i < node->childs.size(); i++)
    {
      if(node->childs[i]->nodeType == NODE_SPROG_DECLS) {
          if (node->childs[i]->childs[0]->nodeType == NODE_SPROG_DECL)
            node->childs[i] = node->childs[i]->childs[0];
      }
    }
  }
}

void reduceDECL(Node* node)
{
  reduceDECLlist(node);
  // declarations -> LAMDBA, remove node
  std::vector<Node*> tmp(node->childs);

  // declarations -> VAR identifier_list COLON type SEMICOLON
  if (node->childs[0]->nodeType == NODE_VAR && node->childs[3]->nodeType == NODE_TYPE) {
    node->childs.clear();
    addChild(node, tmp[0]);
    addChild(node, tmp[1]);
    addChild(node, tmp[3]);
    return;
  }
  // declarations VAR identifier_list COLON identifier_list SEMICOLON
  if (node->childs[0]->nodeType == NODE_VAR && node->childs[3]->nodeType == NODE_TYPE) {
    node->childs.clear();
    addChild(node, tmp[0]);
    addChild(node, tmp[1]);
    addChild(node, tmp[3]);
    return;
  }

  // declarations -> CONST identifier_list EQUAL num_tok SEMICOLON
  if (node->childs[0]->nodeType == RE_CONST) {
    node->childs.clear();
    addChild(node, tmp[0]);
    addChild(node, tmp[1]);
    reduce(tmp[3]);
    addChild(node, tmp[3]);
    return;
  }

  // declarations -> TYPE identifier_list EQUAL type SEMICOLON
  if (node->childs[0]->nodeType == RE_TYPE) {
    node->childs.clear();
    addChild(node, tmp[0]);
    addChild(node, tmp[1]);
    addChild(node, tmp[3]);
    return;
  }
}

void reduceList(Node* node)
{
  int node_type = node->nodeType;
  if (node->childs[0]->nodeType != node_type) return;

  std::vector<Node*> list;
  Node* new_il = newNode(node_type);
  Node* il; il = node;
  while (il->childs[0]->nodeType == node_type) {
    list.push_back(il->childs[2]);
    il = il->childs[0];
  }
  list.push_back(il->childs[0]);
  copyChildinverse(node, list);
}

void reduceSTMTList(Node* node)
{
  int node_type = node->nodeType;
  if (node->nodeType == NODE_STMT_LI) {
    std::vector<Node*> list;
    Node* new_il = newNode(node_type);
    Node* il; il = node;
    while (il->childs[0]->nodeType == node_type) {
      list.push_back(il->childs[2]);
      il = il->childs[0];
    }
    list.push_back(il->childs[0]);
    copyChildinverse(node, list);
  }

  if (!node->childs.empty()) {
    for (size_t i = 0; i < node->childs.size(); i++){
      reduceSTMTList(node->childs[i]);
    }
  }
}


void reduceOPTVAR(Node* node)
{
  removeLAMDBA(node);

  if(node->childs[0]->nodeType == RE_VAR){
    reduce(node->childs[0]);
    node->parent->childs[0] = node->childs[0];
  }
}

void reduceTAIL(Node* node)
{
  if(node->childs[0]->nodeType == NODE_LAMDBA) {
    node->parent->childs.pop_back();
  }
}

void reduceFACTOR(Node* node)
{
  if(node->parent->childs.size() == 1) {
    node->parent->childs.clear();
    for (int i = 0; i < node->childs.size(); i++) {
      reduce(node->childs[i]);
      node->parent->childs.push_back(node->childs[i]);
    }
  }
}

void reduceLAMDBA_TOK(Node* node)
{
  if (node->nodeType == ID_TOK || node->nodeType == NUM_TOK) {
    // node->parent->childs[0] = node->childs[0];
    copyNode(node, node->childs[0]);
    node->childs.clear();
    return;
  }

  if (node->nodeType == NODE_TAIL && node->childs.size()>3 && node->childs[3]->childs[0]->nodeType == NODE_LAMDBA) {
    node->childs.pop_back();
    return;
  }


  if ( !node->childs.empty() && node->childs[0]->nodeType == NODE_LAMDBA && node->nodeType == NODE_TAIL) {
    node->childs.clear();
    node->parent->childs.pop_back();
    return;
    // node->parent->childs.erase(node->parent->childs.end());
  }

  if (!node->childs.empty()) {
    for (size_t i = 0; i < node->childs.size(); i++){
      reduceLAMDBA_TOK(node->childs[i]);
    }
  }
}

void reduce(Node* node)
{
  int node_type = node->nodeType;

  switch (node_type)
  {
    case NODE_ID_LT       : reduceList(node); break;
    case NODE_STMT_LI     : reduceList(node); break;
    case NODE_EXPR_LI     : reduceList(node); break;
    case NODE_DECL        : reduceDECL(node); break;
    case NODE_TYPE        : reduceTYPE(node); break;
    case NODE_SPROG_DECLS : reduceDECLlist(node); break;
    case NODE_OPTVAR      : reduceOPTVAR(node); break;
    case NODE_OPT_STMT    : reduce(node->childs[0]); node->parent->childs[1] = node->childs[0]; break;
    case NODE_TAIL        : reduceTAIL(node); break;
    case NODE_FACTOR      : reduceFACTOR(node); break;
  }

  if (!node->childs.empty()) {
    for (size_t i = 0; i < node->childs.size(); i++){
      reduce(node->childs[i]);
		}
	}
}



Node* buildAstTree(Node* node)
{
  Node* ast_root;
  Node* cp;
  cp = copyTree(node);
  ast_root = cp;
  reduceLAMDBA_TOK(ast_root);
  reduce(ast_root);
  reduceSTMTList(ast_root);


  // ast_root = convertTree(cp);
  // convertTree(ast_root);

  return ast_root;
}
