sudo chmod 777 lofsdisk 
cd lofsdisk

sudo touch file1
sudo touch file2
sudo chmod 777 file1
sudo chmod 777 file2  
sudo echo "Anastasia" > file1
sudo echo "Palashkina" > file2

mkdir bin
mkdir lib
mkdir lib64
mkdir lib/x86_64-linux-gnu

cp -v /bin/bash ./bin
cp -v /bin/cat ./bin
cp -v /bin/echo ./bin
cp -v /bin/ls ./bin

list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

list="$(ldd /bin/bash | egrep -o '/lib64.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

list="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

list="$(ldd /bin/cat | egrep -o '/lib64.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

list="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

list="$(ldd /bin/echo | egrep -o '/lib64.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

list="$(ldd /bin/ls | egrep -o '/lib64.*\.[0-9]')"
for i in $list;
do cp  -v "$i" ".${i}";
done

gcc ../ex2.c -o ex2.out 
sudo chroot . ./ex2.out > ../ex2.txt
echo "" >> ../ex2.txt
./ex2.out >> ../ex2.txt
