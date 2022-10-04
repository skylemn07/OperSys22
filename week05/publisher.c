#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    char text[1024]; 
    int n = atoi(argv[1]);
    
    mkfifo("/tmp/ex1", 0777);
    
    int fd = open("/tmp/ex1", O_WRONLY);
    
    while (1){
      printf("Publisher text: ");
      fgets(text, 1024, stdin);
      printf("%c", '\n');


      for(int i = 0; i < n; i++){
        write(fd, text, sizeof(char) * 1024);
        sleep(1);
      }
    }
    close(fd);
    return 0;
}
