#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MB 1024 * 1024
#define MEMORY_BLOCK 10 * MB


int main() {
    struct rusage usage;

    for (int i = 0; i < 10; ++i) {
        int *p_mem = (int*)(malloc(MEMORY_BLOCK));

        // initialize allocated memory with zeros
        memset(p_mem, 0, MEMORY_BLOCK);
        // get current usage
        getrusage(RUSAGE_SELF, &usage);


        printf("\n10 MB of memory were allocated\n");
        printf("\tSystem CPU time used: %ld.%06ld sec\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("\tMaximum resident set size: %ld\n", usage.ru_maxrss);

        sleep(1);
    }


    return EXIT_SUCCESS;
}
