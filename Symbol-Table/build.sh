#!/bin/bash
bison -d parser.y
bison -d parser.y -o parser.cc
lex scanner.l
gcc -c lex.yy.c -o lexout
g++ std=c++11 lexout parser.cc node.cpp symtab.cpp -o out

echo " "
echo "-------------------------------"
echo "Parser build finish."
echo ""
echo "use  \"./clean_parser.sh\" to remove build files"
echo "use  \"ls ./test/\" to see test case"
echo "use  \"./parser_test.sh\" or \"cat [test file] | ./out\" to see parse result"

exit 0
