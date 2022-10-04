#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(fd[1]);
        char text[1024];

        read(fd[0], text, sizeof(char) * 1024);
        printf("Subscriber gets: %s\n", text);
        close(fd[0]);

        exit(EXIT_SUCCESS);
    } else {
        close(fd[0]);
        char text[1024];
        printf("Text from publisher: ");
        fgets(text, 1024, stdin);
        text[strlen(text) - 1] = '\0';

        printf("%c", '\n');

        int n = strlen(text) + 1;
        write(fd[1], text, sizeof(char) * n);
        close(fd[1]);

        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
