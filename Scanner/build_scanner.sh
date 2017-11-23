flex standard-pascal-no-yacc.l
cc lex.yy.c -ll -o scanner_out

echo ""
echo "---------------------------"
echo "Scanner build finish."
echo ""
echo "use \"./scanner_out < [test file]\" to see scan result"
echo "use \"./scanner_test.sh\" to scan multiple files"
echo "use \"ls ./scan_test/\" to see test case"
