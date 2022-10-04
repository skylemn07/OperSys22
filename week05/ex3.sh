gcc ex3.c -o ex3

echo > ex3.txt
/bin/time -p -a -o ex3.txt ./ex3 100000000 1
/bin/time -p -a -o ex3.txt ./ex3 100000000 2
/bin/time -p -a -o ex3.txt ./ex3 100000000 4
/bin/time -p -a -o ex3.txt ./ex3 100000000 10
/bin/time -p -a -o ex3.txt ./ex3 100000000 100
