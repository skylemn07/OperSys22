#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RESOURCES_NUMBER 3
#define PROCCESSES_NUMBER 5

bool processCanBeExecuted(int pIdx, int R[PROCCESSES_NUMBER][RESOURCES_NUMBER], int A[RESOURCES_NUMBER]) {
    for (int rIdx = 0; rIdx < RESOURCES_NUMBER; ++rIdx) {
        if (R[pIdx][rIdx] > A[rIdx])
            return false;
    }
    return true;
}

void executeProcess(int pIdx, bool finished[PROCCESSES_NUMBER], int C[PROCCESSES_NUMBER][RESOURCES_NUMBER], int A[RESOURCES_NUMBER]) {
    // free the resources that were occupied by this proccess	
    for (int rIdx = 0; rIdx < RESOURCES_NUMBER; ++rIdx) {
        A[rIdx] += C[pIdx][rIdx];
    }
    finished[pIdx] = true;
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        perror("Cannot open file \"input.txt\"\n");
        return EXIT_FAILURE;
    }

    int E[RESOURCES_NUMBER]; 
    int A[RESOURCES_NUMBER]; 
    int C[PROCCESSES_NUMBER][RESOURCES_NUMBER]; 
    int R[PROCCESSES_NUMBER][RESOURCES_NUMBER]; 

    
    for (int eIdx = 0; eIdx < RESOURCES_NUMBER; ++eIdx) {
        fscanf(fp, "%d", &E[eIdx]);
    }
    
    for (int aIdx = 0; aIdx < RESOURCES_NUMBER; ++aIdx) {
        fscanf(fp, "%d", &A[aIdx]);
    }
    
    for (int pIdx = 0; pIdx < PROCCESSES_NUMBER; ++pIdx) {
        for (int rIdx = 0; rIdx < RESOURCES_NUMBER; ++rIdx) {
            fscanf(fp, "%d", &C[pIdx][rIdx]);
        }
    }
    
    for (int pIdx = 0; pIdx < PROCCESSES_NUMBER; ++pIdx) {
        for (int rIdx = 0; rIdx < RESOURCES_NUMBER; ++rIdx) {
            fscanf(fp, "%d", &R[pIdx][rIdx]);
        }
    }

    fclose(fp);
    
    bool finished[PROCCESSES_NUMBER];
    int finishedProcNum = 0; 
    bool wasDeadlock = false;
    
    for(int pIdx = 0; pIdx < PROCCESSES_NUMBER; ++pIdx) {
        finished[pIdx] = false;
    }
    
    while (!wasDeadlock && finishedProcNum != PROCCESSES_NUMBER) {
        wasDeadlock = true; 
        for (int pIdx = 0; pIdx < PROCCESSES_NUMBER; ++pIdx) {
            if (!finished[pIdx]) { 
                if (processCanBeExecuted(pIdx, R, A)) {
                    executeProcess(pIdx, finished, C, A);
                    ++finishedProcNum;
                    wasDeadlock = false; 
                }
            }
        }
    }

    if (!wasDeadlock) {
        printf("No deadlocks detected\n");
    } else {
        for (int pIdx = 0; pIdx < PROCCESSES_NUMBER; ++pIdx) {
            if (!finished[pIdx])
                printf("Process #%d causes deadlock\n", pIdx + 1);
        }
    }

    return 0;
}
