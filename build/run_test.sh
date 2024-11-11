echo "Running!"

echo "Original File: "
echo " "
cat test_1.c
echo "_________________"
echo " "
echo " "

echo "Compiler Output: "
echo " "
./compile test_1.c
echo "_________________"
echo " "
echo " "

echo "Assembly Output: "
echo " "
cat output.s
echo "_________________"
echo " "
echo " "

gcc output.s -o output

echo "Return Value: "
./output
echo $?




