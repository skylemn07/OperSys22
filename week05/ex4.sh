gcc ex4.c -o ex4

echo > ex4.txt
/bin/time -p -a -o ex4.txt ./ex4 100000000 1
/bin/time -p -a -o ex4.txt ./ex4 100000000 2
/bin/time -p -a -o ex4.txt ./ex4 100000000 4
/bin/time -p -a -o ex4.txt ./ex4 100000000 10
/bin/time -p -a -o ex4.txt ./ex4 100000000 100
