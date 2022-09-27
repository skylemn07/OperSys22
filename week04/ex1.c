#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



int main(void){
    pid_t child1, child2;
    clock_t t, t1, t2;
    child1 = fork();

    t = clock();
    
    if (child1 == 0){
        printf("ID child1: %d\nParent ID of child1: %d\n", getpid(), getppid());
        printf("Time for child1 process %f\n", ((float)(clock() - t))/CLOCKS_PER_SEC * 1000);
    } else{
        child2 = fork();
        t2 = clock();
        if (child2 == 0){
            printf("ID child2: %d\nParent ID of child2: %d\n", getpid(), getppid());
            printf("Time for child2 process %f\n", ((float)(clock() - t2))/CLOCKS_PER_SEC * 1000);
        } else{
            printf("ID: %d\nParent ID: %d\n", getpid(), getppid());
            printf("Time for parent process %f\n", ((float)(clock() - t))/CLOCKS_PER_SEC * 1000);
        }
    }


    return EXIT_SUCCESS;

}
