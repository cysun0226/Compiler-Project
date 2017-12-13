#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include "symtab.h"
#include <vector>
#include <string>
#include <map>
#include "node.h"
using namespace std;

void divideScope(Node* node)
{
  if (!node->childs.empty()) {
    for (size_t i = 0; i < node->childs.size(); i++){
      divideScope(node->childs[i]);
		}
	}
}
