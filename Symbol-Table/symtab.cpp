#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <iomanip>
#include "symtab.h"
#include <vector>
#include <string>
#include <map>
#include "node.h"
string RED_BOLD = "\x1b[;31;1m";
string RED_END = "\033[0m";
string GRN = "\x1b[;32;1m";
string RESET = "\x1b[0;m";
using namespace std;

int scope_id = 0;

std::vector<Symtab*> symtabStack;
std::vector<string> errMsg;
std::string nf = "not func";
std::string PROG = "PROGRAM";
std::string PROG_PARA = "PROG_PARA";
std::string INT = "INTEGER";
map<string, string>::iterator iter;


struct Symtab* newSymtab(string func_name, int scope_id) {
  struct Symtab *sym = new Symtab;
  sym->func_name = func_name;
  sym->scope = scope_id;
  return sym;
}

bool searchID(string id)
{
  for (int i = symtabStack.size()-1; i >= 0; i--) {
    iter = symtabStack[i]->symtab.find(id);
    if (iter != symtabStack[i]->symtab.end()) // id exists
      return true;
  }
  return false;
}

bool searchDupID(string id)
{
  iter = symtabStack.back()->symtab.find(id);
  if (iter != symtabStack.back()->symtab.end()) // id exists
    return true;
  else
    return false;
}

void printErrMsg()
{
  cout << "\n----- Error messages -----\n" << endl;

  if(errMsg.empty()) {
    cout << GRN + "[No Semantic Error]﻿" + RESET << endl << endl;
    return;
  }

  for (size_t i = 0; i < errMsg.size(); i++) {
    cout << errMsg[i] << endl;
  }
  cout << endl;
}

string redeclare(int line_no, string id)
{
  string err;
  err = RED_BOLD + "[error]" + RED_END + " line " + to_string(line_no) + ": redeclaration of " + "\'" + id + "\'";
  return err;
}

void printSymtab(Symtab* s)
{
  // header
  if (s->scope == 0)
    cout << "----- global scope symbol table -----" << endl;
  else
    cout << "----- scope " << s->scope << " symbol table -----" << endl;

  if (s->func_name != nf)
    cout << "(function " << s->func_name << ")" << endl;

  cout << "------------------------------------------------------" << endl;
  cout << "| " << std::left << setw(15) << "id" << "|  " <<  std::left << setw(15) << "type" << "|  " <<  std::left << setw(15) <<  "scope"  << "|" << endl;
  cout << "------------------------------------------------------" << endl;

  // print content
  map<string, string>::iterator iter;
  for(iter = s->symtab.begin(); iter != s->symtab.end(); iter++) {
    if (s->scope != 0)
      cout << "| " << std::left << setw(15) << iter->first << "|  " << std::left << setw(15) << iter->second << "|  " << std::left << setw(15) << s->scope << "|" << endl;
    else
      cout << "| " << std::left << setw(15) << iter->first << "|  " << std::left << setw(15) << iter->second << "|  " << std::left << setw(15) << "global" << "|" << endl;
  }

  cout << "------------------------------------------------------" << endl << endl;
  // end
  // if (s->scope == 0)
  //   cout << "----- global scope symbol table end -----" << endl;
  // else
  //   cout << "----- scope " << s->scope << " symbol table end -----" << endl << endl;
}

void divideScope(struct Node *node, int ident) {

    static char blank[1024];
    for(int i=0; i<ident; i++)
        blank[i] = ' ';
    blank[ident] = 0;

    // open scope
    if (node->nodeType == RE_PROG) {
      cout << "\n----- global scope -----\n" << endl;
      Symtab* newtab = newSymtab(nf, scope_id);
      newtab->symtab[node->sibling[1]->strValue + "(PROG)"] = PROG;
      symtabStack.push_back(newtab);
      // scope_id++;

      // Symtab* newtab = newSymtab(nf, scope_id);
      // newtab->symtab[node->sibling[1]->strValue] = PROG;

      for (size_t i = 0; i < node->sibling[3]->childs.size(); i++) {
        string para_id = node->sibling[3]->childs[i]->strValue;
        if(!searchDupID(para_id))
          newtab->symtab[node->sibling[3]->childs[i]->strValue] = PROG_PARA;
        else
          errMsg.push_back(redeclare(node->sibling[3]->childs[i]->line_num,para_id));
      }



    }

    if (node->nodeType == RE_FUNC) {
      scope_id++;
      node->scope_id = scope_id;
      node->parent->parent->childs.back()->childs[2]->scope_id = scope_id; // add scope_id to END
      symtabStack.back()->symtab[node->sibling[1]->strValue] = "FUNCTION"; // insert function name into scope

      Symtab* newtab = newSymtab(node->sibling[1]->strValue, scope_id);
      newtab->symtab[node->sibling[1]->strValue] = "FUNCTION";

      if(!node->sibling[2]->childs[0]->childs.empty()) // if function have parameters
      {
        for (size_t i = 0; i < node->sibling[2]->childs[0]->childs[0]->childs.size(); i++) {
          string para_id = node->sibling[2]->childs[0]->childs[0]->childs[i]->strValue;
          string para_type = node->sibling[2]->childs[0]->childs[1]->strValue;
          int line_no = node->sibling[2]->childs[0]->childs[0]->childs[i]->line_num;
          if(!searchDupID(para_id))
            newtab->symtab[para_id] = para_type;
          else
            errMsg.push_back(redeclare(line_no,para_id));
        }
      }


      symtabStack.push_back(newtab);

      cout << "\n----- scope " << scope_id << " -----\n" << endl;
    }

    if (node->nodeType == RE_PROC) {
      scope_id++;
      node->scope_id = scope_id;
      node->parent->parent->childs.back()->childs[2]->scope_id = scope_id; // add scope_id to END
      symtabStack.back()->symtab[node->sibling[1]->strValue] = "PROCEDURE"; // insert function name into scope

      Symtab* newtab = newSymtab(node->sibling[1]->strValue, scope_id);
      newtab->symtab[node->sibling[1]->strValue] = "PROCEDURE";

      for (size_t i = 0; i < node->sibling[2]->childs[0]->childs[0]->childs.size(); i++) {
        newtab->symtab[node->sibling[2]->childs[0]->childs[0]->childs[i]->strValue] = node->sibling[2]->childs[0]->childs[1]->strValue;
      }

      symtabStack.push_back(newtab);

      cout << "\n----- scope " << scope_id << " -----\n" << endl;
    }


    // insert decl symbol
    if (node->nodeType == NODE_DECL && node->childs.size()>2) {
      for (size_t i = 0; i < node->childs[1]->childs.size(); i++) { // decl id list
        string var_id = node->childs[1]->childs[i]->strValue;
        string var_type = node->childs[2]->strValue;

        if(!searchDupID(var_id)) {
          symtabStack.back()->symtab[var_id] = var_type;
          if(node->childs[2]->nodeType == RE_ARR) {
            std::string arrType = node->childs[2]->childs[2]->strValue;
            if (node->childs[2]->childs[2]->nodeType == RE_ARR) arrType = "ARRAY";
            symtabStack.back()->symtab[node->childs[1]->childs[i]->strValue] = "ARRAY(" + arrType + ")";
          }
        }
        else
          errMsg.push_back(redeclare(node->childs[1]->childs[i]->line_num,var_id));
      }
    }






    switch(node->nodeType) {
        case OP_ADD           : printf("%s|-ADD\n", blank); break;
        case OP_SUB           : printf("%s|-SUB\n", blank); break;
        case NODE_INT         : printf("%s|-%d\n", blank, node->iValue); ident += 3; break;
        case NODE_STMT        : printf("%s|-STMT\n", blank); ident += 3; break;
        case NODE_TERM        : printf("%s|-TERM\n", blank); ident += 3; break;
        case NODE_PROGRAM     : printf("%s|-PROGRAM \n", blank); ident += 3; break;
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
        case OP_MINUS         : printf("%s|-MINUS\n", blank);ident += 3; break;
        case PUC_LPAREN       : printf("%s|- ( \n", blank);ident += 3; break;
        case PUC_RPAREN       : printf("%s|- ) \n", blank);ident += 3; break;
        case PUC_DOT          : printf("%s|- . \n", blank);ident += 3; break;
        case RE_NOT           : printf("%s|-NOT\n", blank);ident += 3; break;
        case RE_VAR           : printf("%s|-VAR\n", blank);ident += 3; break;
        case RE_ASGMNT        : printf("%s|-ASSIGN \n", blank);ident += 3; break;
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

    if (node->nodeType == PUC_DOT && node->parent->childs[0]->nodeType == RE_PROG) {
      cout << "\n----- global scope end -----\n" << endl;
      printSymtab(symtabStack.back());
      symtabStack.pop_back();
      printErrMsg();
    }


    if (node->nodeType == RE_END && node->parent->parent->nodeType != NODE_START && symtabStack.size()>1 ) {
      cout << "\n----- scope " << node->scope_id << " end -----\n" << endl;
      printSymtab(symtabStack.back());
      symtabStack.pop_back();
    }


	if (!node->childs.empty())
	{
		for (size_t i = 0; i < node->childs.size(); i++)
		{
      node->childs[i]->parent = node;
      for (int j = 0; j < node->childs.size(); j++) {
        node->childs[i]->sibling.push_back(node->childs[j]);
      }
      divideScope(node->childs[i], ident);
		}
	}
}
