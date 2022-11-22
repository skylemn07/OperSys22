#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

typedef struct dirent dirent;

int main() {
    DIR *pDir;
    dirent *pDirent;

    pDir = opendir("/");

    if (pDir == NULL) {
        printf("Cannot open root directory");
        return 0;
    }

    pDirent = readdir(pDir);
    while(pDirent != NULL) {
        printf("%s\n", pDirent->d_name);
        pDirent = readdir(pDir);
    }

    closedir(pDir);
    return 0;
}
