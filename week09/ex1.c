#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BITS (0b10000000)

typedef struct PageFrame {
    unsigned int ind;
    unsigned int bits;
} PageFrame;

int main() {
    printf("Enter the number of pages:\n");
    int pageCount;
    scanf("%d", &pageCount);

    FILE *inputFile = fopen("Lab 09 input.txt", "r");

    PageFrame *pageFrames = (PageFrame*)(malloc(pageCount * sizeof(PageFrame)));

    for (int i = 0; i < pageCount; ++i) {
        PageFrame frame = {0, 0};
        pageFrames[i] = frame;
    }

    int hit = 0, all = 0;
    int fill = 0;

    while(!feof(inputFile)) {
        bool isHit = false;

        PageFrame buf;
        fscanf(inputFile, "%d", &buf.ind);

        buf.bits = BITS;
        int minBit = BITS << 1;
        int min = 0;

        all++;

        bool found = false;

        for (int i = 0; i < pageCount; i++) {
            pageFrames[i].bits >>= 1;

            if (pageFrames[i].ind == buf.ind) {
                pageFrames[i].bits |= BITS;
                isHit = true;
                found = true;
                if (isHit) hit++;
            }

            if (pageFrames[i].bits < minBit) {
                minBit = pageFrames[i].bits;
                min = i;
            }
        }

        if(found) continue;

        if(fill < pageCount){
            pageFrames[fill++] = buf;
            continue;
        }

        
        pageFrames[min] = buf;
    }

    double ratio = (double)(hit) / (all - hit - 1);
    printf("hit: %d, miss: %d, ratio: %f\n", hit, all - hit - 1, ratio);
    free(pageFrames);
    fclose(inputFile);

    return 0;
}
