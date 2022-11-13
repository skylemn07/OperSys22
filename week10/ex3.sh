touch ex3.txt
touch _ex3.txt
echo "Anastasia" > _ex3.txt

chmod 660 _ex3.txt
ls -l _ex3.txt >> ex3.txt

chmod 775 _ex3.txt
ls -l _ex3.txt >> ex3.txt

chmod 777 _ex3.txt
ls -l _ex3.txt >> ex3.txt

echo "1) 660 = rw- for owner, rw- for group, --- for other" >> ex3.txt
echo "2) 775 = rwx for owner, rwx for group, r-x for other" >> ex3.txt
echo "3) 777 = rwx for onwer, rwx for group, rwx for other" >> ex3.txt
