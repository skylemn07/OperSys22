#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

    int result = 0;

    for (int i = start; i < end; i++){
        result += u[i] * v[i];
    }

    return result;
}


int main(void) {
    FILE *file;
    file = fopen("temp.txt", "a");
    if(file == NULL){
        return EXIT_FAILURE;
    }
    int u[120];
    int v[120];
    for(int i = 0; i < 120; i++){
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    pid_t child;
    int n;
    scanf("%d", &n);
    pid_t arrp[n];

    for (int i = 0; i < n; i++){
        child = fork();

        if (child == 0){
            arrp[i] = getpid();
            break;
        }
    }

    for (int i = 0; i < n; i++){
        if(getpid() == arrp[i]){
            unsigned long res = 0;
            res = dotprod(u, v, i * (120 / n), (i + 1) * (120 / n) + 1);
            fprintf(file, "%lu ", res);
            exit(EXIT_SUCCESS);
        }
    }
    fclose(file);
    file = fopen("temp.txt", "r");

    for(int i = 0; i < n; i++){
        wait(NULL);
    }
    unsigned long res = 0;
    for(int i = 0; i < n; i++){
        unsigned long tmp;
        fscanf(file, "%lu", &tmp);
        res += tmp;
    }
    printf("%lu", res);


    return EXIT_SUCCESS;
}
