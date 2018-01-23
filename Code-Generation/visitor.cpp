#include <iostream>
#include "visitor.h"
#include "node.h"

using namespace std;

std::vector<Instruction> instructions;
int cur_scope = 0;
int node_id = 0;
string program_name;

bool cmpByLine(const Instruction &a, const Instruction &b){
    return a.line < b.line;
}

bool is_integer(double x) {
	return x == (int)x;
}

void print_node(Node* node, int ident)
{
	// int ident = id;
	// id += 3;
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
}

void codeGenerate(string file_name, std::vector<Instruction> instrs, Node* root){
	// string file_name = "compiler";
	fstream fp;
  fp.open(file_name, ios::out);
	program_name = root->childs[1]->strValue;
	fp << ".class public " << program_name << endl;
	fp << ".super java/lang/Object" << endl << endl;

	// main
	fp << ".method public static main([Ljava/lang/String;)V" << endl;
	fp << "\t.limit stack 100" << endl;
	fp << "\t.limit locals 100" << endl << endl;

	std::sort(instrs.begin(), instrs.end(), cmpByLine);
	for (int i = 0; i < instrs.size(); i++) {
		fp << "\t" + instrs[i].instr << endl;
	}

	fp << "\treturn" << endl << endl;
	fp << ".end method" << endl;

	fp.close();
}

/* MethodBodyVisitor */

MethodBodyVisitor::MethodBodyVisitor(Node* r, std::vector<Symtab*> st, std::vector<AddrTab> at)
{
	root = r;
	addrtabs = at;
	symtabs = st;
}

void MethodBodyVisitor::visit(Node* node, int ident)
{
	print_node(node, ident);
	switch (node->nodeType) {
		// case NODE_VAR: visitLocalVar(node); break;

	}

	if (!node->childs.empty()){
		for (size_t i = 0; i < node->childs.size(); i++) {
      visit(node->childs[i], ident+3);
		}
	}
}

void MethodBodyVisitor::visitLocalVar()
{
	for (int i = 0; i < addrtabs.size(); i++) {
		map<string, int>::iterator iter;
		for(iter = addrtabs[i].addrtab.begin(); iter != addrtabs[i].addrtab.end(); iter++) {
			/* load */
			if(symtabs[i]->symtab[iter->first] == "INTEGER" || symtabs[i]->symtab[iter->first] == "REAL") {
				string l_instr, s_instr;
				if(symtabs[i]->symtab[iter->first] == "INTEGER") {
					l_instr = "iload " + to_string(iter->second);
					s_instr = "istore " + to_string(iter->second);
				}
				else {
					l_instr = "dload " + to_string(iter->second);
					s_instr = "dstore " + to_string(iter->second);
				}

				addrtabs[i].load_tab[iter->first] = l_instr;
				addrtabs[i].store_tab[iter->first] = s_instr;
			}
	  }
	}
}

void MethodBodyVisitor::visitConstant(Node* node)
{

}

void MethodBodyVisitor::visitAssignment(Node* node)
{
	if(node->nodeType == RE_ASGMNT){
		Instruction new_instr;
		new_instr.line = node->line_num;
		new_instr.scope = node->scope_id;
		int x = 0;

		if(node->sibling[2]->nodeType == NODE_NUM){
			int num = node->sibling[2]->number;
			if(is_integer(num))
				new_instr.instr = "ldc " + to_string(num);
			else
				new_instr.instr = "ldc2_w " + to_string(num);
			instructions.push_back(new_instr);
		}

		if(node->sibling[2]->nodeType == NODE_EXPR) {
			for (int i = 0; i < node->sibling[2]->instr.size(); i++) {
				new_instr.line = node->line_num + x;
				x += 0.01;
				new_instr.instr = node->sibling[2]->instr[i];
				instructions.push_back(new_instr);
			}
		}

			// LHS
			new_instr.line = node->line_num + x;
			if(node->sibling[0]->childs[0]->nodeType == NODE_ID) {
				string id = node->sibling[0]->childs[0]->strValue;
				map<string, int>::iterator iter;
				iter = addrtabs[node->scope_id].addrtab.find(id);
				if(iter != addrtabs[node->scope_id].addrtab.end()) {
					new_instr.instr = addrtabs[node->scope_id].store_tab[id];
				}
				else {
					for (int i = node->scope_id; i >= 0; i--) {
						iter = addrtabs[i].addrtab.find(id);
						if(iter != addrtabs[i].addrtab.end()) {
							new_instr.instr = addrtabs[i].store_tab[id];
							break;
						}
					}
				}
				instructions.push_back(new_instr);
		}

	}

	if (!node->childs.empty()){
		for (size_t i = 0; i < node->childs.size(); i++) {
      visitAssignment(node->childs[i]);
		}
	}
}

// void calTermValue(Node* node) {
// 	if(node->nodeType == NODE_TREM && node->childs[0]->nodeType != NODE_TREM && node->sibling.size()>1) {
// 		switch (node->sibling[1]->nodeType) {
// 			case OP_ADD:
// 				node->number = node->childs[0]->number + node->sibling[2]->childs[0]->number;
// 				node->parent->number = node->childs[0]->number + node->sibling[2]->childs[0]->number;
// 				break;
// 			case OP_SUB:
// 				node->number = node->childs[0]->number - node->sibling[2]->childs[0]->number;
// 				node->parent->number = node->childs[0]->number - node->sibling[2]->childs[0]->number;
// 				break;
// 			case OP_MUL:
// 				node->number = node->childs[0]->number * node->sibling[2]->childs[0]->number;
// 				node->parent->number = node->childs[0]->number * node->sibling[2]->childs[0]->number;
// 				break;
// 			case OP_DIV:
// 				node->number = node->childs[0]->number / node->sibling[2]->childs[0]->number;
// 				node->parent->number = node->childs[0]->number / node->sibling[2]->childs[0]->number;
// 				break;
// 		}
// 	}
//
// 	if(node->nodeType == NODE_TREM && )
//
//
//
// 	if (!node->childs.empty()){
// 		for (size_t i = 0; i < node->childs.size(); i++) {
//       calTermValue(node->childs[i]);
// 		}
// 	}
// }

void MethodBodyVisitor::generateExprInstr(Node* node, Node* exprNode) {
	int is_int = true;
	if(node->nodeType == OP_ADD || node->nodeType == OP_SUB || node->nodeType == OP_MUL || node->nodeType == OP_DIV) {
		if(node->sibling[0]->nodeType == NODE_NUM) {
			if(is_integer(node->sibling[0]->number))
				exprNode->instr.push_back("ldc " + to_string(node->sibling[0]->number));
			else{
				exprNode->instr.push_back("ldc2_w " + to_string(node->sibling[0]->number));
				is_int = false;
			}
		}

		if(node->sibling[0]->nodeType == NODE_ID) {
			string id = node->sibling[0]->strValue;
			map<string, int>::iterator iter;
			iter = addrtabs[node->scope_id].addrtab.find(node->strValue);
			if(iter != addrtabs[node->scope_id].addrtab.end()) {
				exprNode->instr.push_back(addrtabs[node->scope_id].load_tab[id]);
			}
			else {
				for (int i = node->scope_id; i >= 0; i--) {
					iter = addrtabs[i].addrtab.find(id);
					if(iter != addrtabs[i].addrtab.end()) {
						exprNode->instr.push_back(addrtabs[i].load_tab[id]);
						break;
					}
				}
			}
		}
	}

	if (!node->childs.empty()){
		for (size_t i = 0; i < node->childs.size(); i++) {
      generateExprInstr(node->childs[i], exprNode);
		}
	}

	if(node->nodeType == OP_ADD || node->nodeType == OP_SUB || node->nodeType == OP_MUL || node->nodeType == OP_DIV) {
		if(node->sibling[2]->childs[0]->nodeType == NODE_NUM) {
			if(is_integer(node->sibling[0]->number))
				exprNode->instr.push_back("ldc " + to_string(node->sibling[0]->number));
			else{
				exprNode->instr.push_back("ldc2_w " + to_string(node->sibling[0]->number));
				is_int = false;
			}
		}

		if(node->sibling[2]->childs[0]->nodeType == NODE_ID) {
			string id = node->sibling[2]->childs[0]->strValue;
			map<string, int>::iterator iter;
			iter = addrtabs[node->scope_id].addrtab.find(id);
			if(iter != addrtabs[node->scope_id].addrtab.end()) {
				exprNode->instr.push_back(addrtabs[node->scope_id].load_tab[id]);
				if(symtabs[node->scope_id]->symtab[id] == "REAL")
					is_int = false;
			}
			else {
				for (int i = node->scope_id; i >= 0; i--) {
					iter = addrtabs[i].addrtab.find(id);
					if(iter != addrtabs[i].addrtab.end()) {
						exprNode->instr.push_back(addrtabs[i].load_tab[id]);
						if(symtabs[i]->symtab[id] == "REAL")
							is_int = false;
						break;
					}
				}
			}
		}

		switch (node->nodeType) {
			case OP_ADD: {
				if(is_int)
					exprNode->instr.push_back("iadd");
				else
					exprNode->instr.push_back("dadd");
				break;
			}
			case OP_SUB: {
				if(is_int)
					exprNode->instr.push_back("isub");
				else
					exprNode->instr.push_back("dsub");
				break;
			}
			case OP_MUL: {
				if(is_int)
					exprNode->instr.push_back("imul");
				else
					exprNode->instr.push_back("dmul");
				break;
			}
			case OP_DIV: {
				if(is_int)
					exprNode->instr.push_back("idiv");
				else
					exprNode->instr.push_back("ddiv");
				break;
			}
		}
	}
}

void MethodBodyVisitor::visitExpression(Node* node)
{
	if(node->nodeType == NODE_EXPR) {
		generateExprInstr(node, node);
	}

	if (!node->childs.empty()){
		for (size_t i = 0; i < node->childs.size(); i++) {
      visitExpression(node->childs[i]);
		}
	}
}

void MethodBodyVisitor::visitArrayRef(Node* node)
{

}

void MethodBodyVisitor::visitCondExec(Node* node)
{

}

void MethodBodyVisitor::visitLoop(Node* node)
{

}

void MethodBodyVisitor::printAddrTab()
{
	for (int i = 0; i < addrtabs.size(); i++) {
		map<string, int>::iterator iter;
		cout << "--- scope " << i << " ---" << endl;
		for(iter = addrtabs[i].addrtab.begin(); iter != addrtabs[i].addrtab.end(); iter++) {
			cout << iter->first << " addr = " << iter->second << endl;
			cout << addrtabs[i].load_tab[iter->first] << endl;
			cout << addrtabs[i].store_tab[iter->first] << endl;
		}
	}
}

std::vector<Instruction> MethodBodyVisitor::getInstructions(){
	return instructions;
}


/* LHSVisitor */
LHSVisitor::LHSVisitor(Node* r, std::vector<Symtab*> st)
{
	root = r;
	symtabs = st;
}

void LHSVisitor::visit(Node* node, int ident)
{
	// print_node(node, ident);
	node->LRvalue = RIGHT;

	if(node->nodeType == RE_ASGMNT) {
		node->sibling[0]->childs[0]->LRvalue = LEFT;
	}

	if (!node->childs.empty()) {
		for (size_t i = 0; i < node->childs.size(); i++) {
      node->childs[i]->parent = node;
      for (int j = 0; j < node->childs.size(); j++) {
        node->childs[i]->sibling.push_back(node->childs[j]);
      }
      visit(node->childs[i], ident+3);
		}
	}
}

void LHSVisitor::visitDeclaring(Node* node)
{
	for (int i = 0; i < symtabs.size(); i++) {
		AddrTab new_addrtab;
		new_addrtab.scope = symtabs[i]->scope;
		new_addrtab.top_addr = 0;

		map<string, string>::iterator iter;
		for(iter = symtabs[i]->symtab.begin(); iter != symtabs[i]->symtab.end(); iter++) {
			if(iter->second == "INTEGER") {
				new_addrtab.addrtab[iter->first] = new_addrtab.top_addr;
			}
			else {
				new_addrtab.addrtab[iter->first] = new_addrtab.top_addr;
			}

			new_addrtab.top_addr += 2;
	  }

		addrtabs.push_back(new_addrtab);
	}
}

void LHSVisitor::visitField(Node* node){
}

void LHSVisitor::visitArrayRef(Node* node){
	for (int i = 0; i < symtabs.size(); i++) {
		// int top = addrtabs[i].top_addr;
		map<string, Array>::iterator iter;
		for(iter = symtabs[i]->arrTab.begin(); iter != symtabs[i]->arrTab.end(); iter++) {
			int size;
			addrtabs[i].addrtab[iter->first] = addrtabs[i].top_addr;
			if(iter->second.d_num == 0) {
				size = iter->second.end_idx - iter->second.start_idx + 1;
			}
			else {
				for (int d = 0; d < iter->second.d_num; d++) {
					int nxt_size = iter->second.dimension[d].end_idx - iter->second.dimension[d].start_idx + 1;
					size = size*nxt_size;
				}
			}
			addrtabs[i].top_addr += size*2;
	  }
	}
}

std::vector<AddrTab> LHSVisitor::get_addrtab() {
	return addrtabs;
}
