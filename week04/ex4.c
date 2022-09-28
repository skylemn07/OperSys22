#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1001

int main() {
    char command[BUFFER_SIZE];

    while(1) {
        printf("> ");
        fgets(command, 1001, stdin);
        int pid = fork();
        if (pid == 0){
            system(command&);
            exit(EXIT_SUCCESS);
        }
        
    }

    return EXIT_SUCCESS;
}
