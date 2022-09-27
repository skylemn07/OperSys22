#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1001

int main() {
    char command[BUFFER_SIZE];

    while(1) {
        printf("> ");
        fgets(command, 1001, stdin);
        system(command);
    }

    return EXIT_SUCCESS;
}
