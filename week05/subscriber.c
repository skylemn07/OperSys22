#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    char text[1024];
    int fd = open("/tmp/ex1", O_RDONLY);

    for(;;){
        strcpy(text, "");
        read(fd, text, sizeof(char) * 1024);
        printf("Subscriber gets: %s\n", text);
    }
    
     close(fd);
    return 0;
}
