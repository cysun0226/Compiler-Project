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
	MethodBodyVisitor(Node* r) {root = r};
	virtual ~MethodBodyVisitor();

	void visit();
	// traverse AST tree
	// 用 case 來呼叫 class 中的各個 function 產生 Instruction

	void visitLocalVar();
	void visitStatic();
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

private:
	Node* root;
	std::vector<Instruction> instructions;
};


/* LHSVisitor */
// procedure Visit(LocalReferencing n)
// procedure Visit(StaticReferencing n)
// procedure Visit(FieldReferencing n)
// procedure Visit(ArrayReferencing n)

class LHSVisitor {
private:
	Node* root;

public:
	LHSVisitor (Node* root);
	virtual ~LHSVisitor ();

	void visit();
	// traverse AST tree
	// 用 case 來呼叫 class 中的各個 function

	void visitDeclaring(Node* node);
	// 根據 symbol table 幫每個 var 標好在 machine code stack 中的 addr

	void visitField(Node* node);
	// 把 function, procedure 等標上 label

	void visitArrayRef(Node* node);
	// 把 array 的表示換成實際的 address

};






#endif
