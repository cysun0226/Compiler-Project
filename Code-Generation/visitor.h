#ifndef __VISITOR_H__
#define __VISITOR_H__

#include <vector>
#include <string>
#include <map>
#include "node.h"
#include "symtab.h"
using namespace std;

typedef struct Instruction {
	int line;
	string instr;
} Instruction;

typedef struct AddrTab {
	int top_addr;
	int scope;
	map<string, int> addrtab;
	map<string, string> load_tab;
	map<string, string> store_tab;
} AddrTab;

//

/* MethodBodyVisitor */
// Constants
// local storage
// Static references
// Expressions
// Assignment
// Field references? (struct?)
// Array references
// Conditional execution (if/else)
// Loops

class MethodBodyVisitor {
public:
	MethodBodyVisitor(Node* r, std::vector<Symtab*> st, std::vector<AddrTab> at);
	// virtual ~MethodBodyVisitor();

	void visit(Node* node, int ident);
	// traverse AST tree
	// 用 case 來呼叫 class 中的各個 function 產生 Instruction

	void visitLocalVar();
	void visitStatic(Node* node);
	// 依 LHSVisitor 標好的 addr 產生 load 指令

	void visitConstant(Node* node);
	// 產生把 const push 進 stack 的 machine code

	void visitAssignment(Node* node);
	// 依 visitDeclaring 產生出的 address 存值
	// * 有 load/store

	void visitExpression(Node* node);
	// 依 visitDeclaring 產生出的 address 讀/存值來作運算

	void visitArrayRef(Node* node);
	// load array

	void visitCondExec(Node* node);
	// 把 if/else 條件換成 branch 並標上 label

	void visitLoop(Node* node);
	// 同上，while 和 for 版

	void printAddrTab();

private:
	void generateExprInstr(Node* node, Node* exprNode);
	// void calTermConstValue(Node* node);
	// void calTermValue(Node* node);
	Node* root;
	std::vector<Instruction> instructions;
	std::vector<Symtab*> symtabs;
	std::vector<AddrTab> addrtabs;
};


/* LHSVisitor */
// procedure Visit(LocalReferencing n)
// procedure Visit(StaticReferencing n)
// procedure Visit(FieldReferencing n)
// procedure Visit(ArrayReferencing n)

class LHSVisitor {
private:
	Node* root;
	std::vector<Symtab*> symtabs;
	std::vector<AddrTab> addrtabs;

public:
	LHSVisitor (Node* root, std::vector<Symtab*> st);
	// virtual ~LHSVisitor ();

	void visit(Node* node, int ident);
	// traverse AST tree
	// 用 case 來呼叫 class 中的各個 function

	void visitDeclaring(Node* node);
	// 根據 symbol table 幫每個 var 標好在 machine code stack 中的 addr

	void visitField(Node* node);
	// 把 function, procedure 等標上 label
	// MethodBodyVisitor 的 Loop/Cond 再做
	// 把每個 node 標上 scope symtab 已經做了

	void visitArrayRef(Node* node);
	// 把 array 的表示換成實際的 address

	std::vector<AddrTab> get_addrtab();

};






#endif
