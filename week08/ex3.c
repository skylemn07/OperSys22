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
    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
  13167 anastas+  20   0   43748  42120   1132 S   1,0   0,3   0:00.01 ex3
  13208 anastas+  20   0   74480  72696   1088 S   1,0   0,5   0:00.02 ex3
  14043 anastas+  20   0   94968  93432   1236 S   1,0   0,6   0:00.03 ex3
------------------------------------------------------------------------------------
  We may notice that over time the program needs more and more memory.
 */
