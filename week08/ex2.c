#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MB 1024 * 1024
#define MEMORY_BLOCK 10 * MB

int main() {

    for (int i = 0; i < 10; ++i) {
        int *p_mem = (int*)(malloc(MEMORY_BLOCK));

        // initialize allocated memory with zeros
        memset(p_mem, 0, MEMORY_BLOCK);

        printf("10 MB of memory were allocated\n");
        sleep(1);
    }

    return 0;
}
/*
 procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 1  0      0 5574232 110240 3932344    0    0    67    21  232  241  1  0 98  0  0
10 MB of memory were allocated
 2  0      0 5566356 110240 3932300    0    0     0     0 3046 1994  0  0 99  0  0
10 MB of memory were allocated
 0  0      0 5556152 110248 3932300    0    0     0   120 4245 2672  0  0 100  0  0
10 MB of memory were allocated
 0  0      0 5545596 110248 3932300    0    0     0   472 4848 2607  0  0 100  0  0
10 MB of memory were allocated
 0  0      0 5535264 110248 3932300    0    0     0     4 4224 1758  0  0 100  0  0
10 MB of memory were allocated
 0  0      0 5524932 110256 3932300    0    0     0   104 4185 2584  0  0 100  0  0
10 MB of memory were allocated
 0  0      0 5514852 110256 3932300    0    0     0    16 4294 1939  0  0 100  0  0
10 MB of memory were allocated
 0  0      0 5504520 110256 3932300    0    0     0     0 4194 1720  0  0 100  0  0
10 MB of memory were allocated
 0  0      0 5494188 110256 3932300    0    0     0     0 4206 1744  0  0 100  0  0
10 MB of memory were allocated
 0  0      0 5486952 110256 3936460    0    0     0   164 4384 1947  0  0 100  0  0
10 MB of memory were allocated
------------------------------------------------------------------------------------
 We see that si and so equal 0, so we can conclude that system has enough memory.
 */
