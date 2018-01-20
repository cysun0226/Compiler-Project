echo "\n---- parse test00     ----\n" > parse_result.txt # > new file
echo "\n---- parse test00     ----\n" > result.txt # > new file
cat ./test/test00-runtime-range-check.p | ./out >> parse_result.txt
echo "\n---- parse test01     ----\n" >> parse_result.txt # >> append
echo "\n---- parse test01     ----\n" >> result.txt # >> append
cat ./test/test01-global-var.p | ./out >> parse_result.txt
echo "\n---- parse test02     ----\n" >> parse_result.txt
echo "\n---- parse test02     ----\n" >> result.txt
cat ./test/test02-uninitialized-var.p | ./out >> parse_result.txt
echo "\n---- parse test04     ----\n" >> parse_result.txt 
echo "\n---- parse test04     ----\n" >> result.txt 
cat ./test/test04.p | ./out >> parse_result.txt
echo "\n---- parse test-const ----\n" >> parse_result.txt
echo "\n---- parse test-const ----\n" >> result.txt
cat ./test/test-constant.p | ./out >> parse_result.txt
echo "\n---- parse test-func  ----\n" >> parse_result.txt
echo "\n---- parse test-func  ----\n" >> result.txt
cat ./test/test-function.p | ./out >> parse_result.txt
echo "\n---- parse test-mini  ----\n" >> parse_result.txt
echo "\n---- parse test-mini  ----\n" >> result.txt
cat ./test/test-mini.p | ./out >> parse_result.txt
echo "\n---- parse test-optr2 ----\n" >> parse_result.txt
echo "\n---- parse test-optr2 ----\n" >> result.txt
cat ./test/test-operator2.p | ./out>> parse_result.txt
echo "\n---- parse test-optr  ----\n" >> parse_result.txt
echo "\n---- parse test-optr  ----\n" >> result.txt
cat ./test/test-operator.p | ./out >> parse_result.txt
echo "\n---- parse test-proc  ----\n" >> parse_result.txt
echo "\n---- parse test-proc  ----\n" >> result.txt
cat ./test/test-procedure.p | ./out >> parse_result.txt
echo "\n---- parse test-recur ----\n" >> parse_result.txt
echo "\n---- parse test-recur ----\n" >> result.txt
cat ./test/test-recursion.p | ./out >> parse_result.txt

echo "\n"
cat result.txt

echo "\n\nThe parse result is in [parse_result.txt] "
echo "use [cat parse_result.txt] to see."

