touch ../week01/file.txt
touch ex2.txt
echo "Anastasia" > ../week01/file.txt

link ../week01/file.txt _ex2.txt

find ../ -inum $(ls -i ../week01/file.txt | awk '{print $1}') > ex2.txt
find ../ -inum $(ls -i ../week01/file.txt | awk '{print $1}') -exec rm {} \;

#file.txt was deleted, but in the task we should submit it
#so it was created again, but in week10 directory, not in week01
touch file.txt
echo "Anastasia" > file.txt
