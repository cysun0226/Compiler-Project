#ifndef __SYMTAB_H__
#define __SYMTAB_H__

#include <vector>
#include <string>
#include <map>
#include "node.h"
using namespace std;

typedef struct Array {
	int start_idx;
	int end_idx;
	std::vector<Array> dimension;
	int d_num;
	string type;
} Array;

typedef struct Symtab {
	map<string, string> symtab; // ID, type
	map<string, bool> symInit;
	map<string, int> func_data;
	// map<string, int> jvm_location;
	map<string, Array> arrTab;
	// label
	string func_name;
	int scope;
} Symtab;

struct Symtab* newSymtab(string func_name, int scope_id);
bool divideScope(Node* node, int);
std::vector<Symtab*> getSymtab();
// void addChild(struct Node *node, struct Node *child);
// void printTree(struct Node *node, int ident);
// Node* buildAstTree(struct Node *node);

void printSymtab(Symtab* s);


#endif
