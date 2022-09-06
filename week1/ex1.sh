mkdir ~/week1
cd ~/week1
cd /usr/bin
find -name "*gcc*" | sort -r | tail -n 5 | tee ~/week1/ex1.txt
