echo "\n---- scan test00     ----\n" > scan_result.txt # > new file
./scanner_out < ./scan_test/scanner-test00.p >> scan_result.txt
echo "\n---- scan test01     ----\n" >> scan_result.txt # >> append
./scanner_out < ./scan_test/scanner-test01.p >> scan_result.txt
echo "\n---- scan test02     ----\n" >> scan_result.txt
./scanner_out < ./scan_test/scanner-test02-pragma.p >> scan_result.txt
echo "\n---- scan test03-nest----\n" >> scan_result.txt
./scanner_out < ./scan_test/scanner-test03-nested-comments.p >> scan_result.txt
echo "\n---- scan test03-run-comment ----\n" >> scan_result.txt
./scanner_out < ./scan_test/scanner-test03-runaway-comments.p >> scan_result.txt
echo "\n---- scan test03-run-string ----\n" >> scan_result.txt
./scanner_out < ./scan_test/scanner-test03-runaway-string.p >> scan_result.txt
echo "\n---- scan test-longname     ----\n" >> scan_result.txt
./scanner_out < ./scan_test/test-longname.p >> scan_result.txt


echo "\n"
cat scan_result.txt

