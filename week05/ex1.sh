gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

for i in `seq 1 $1`
do
 gnome-terminal -- ./subscriber &
done

./publisher $1




