#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdbool.h>

typedef struct dirent dirent;

int main() {
    DIR* pDir;
    dirent *pDirents[20];

    pDir = opendir("tmp/");

    if (pDir == NULL) {
        printf("cannot open tmp/\n");
        return 0;
    }

    int pDirentsSize = 0;
    while(true) {
        pDirents[pDirentsSize] = readdir(pDir);

        if (pDirents[pDirentsSize] == NULL) break;
        ++pDirentsSize;
    }

    closedir(pDir);

    printf("File - Hard Links\n");
    
    for (int i = 0; i < pDirentsSize; ++i) {
        int countLinksToINode = 0;
        
        for (int j = 0; j < pDirentsSize; ++j) {
            if (pDirents[i]->d_ino == pDirents[j]->d_ino) {
                ++countLinksToINode;
            }
        }
    
        if (countLinksToINode >= 2) {
            printf("%s - ", pDirents[i]->d_name);

            for (int j = 0; j < pDirentsSize; ++j) {
                if (pDirents[i]->d_ino == pDirents[j]->d_ino) {
                    if(j + 1 == pDirentsSize) printf("%s", pDirents[j]->d_name);
                    else printf("%s, ", pDirents[j]->d_name);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
