#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

struct Thread{
    pthread_t id;
    int i;
    char message[256];
};

void* thr (void* arg){
    struct Thread* a = (struct Thread*) arg;
    printf("ID: %ld\n", a->id);
    printf("%s\n", a->message);
    pthread_exit(NULL);
}

int main(){
    int n;
    scanf("%d", &n);

    struct Thread arr[n];
    for (int i = 0; i < n; i++){
        printf("Thread %d is created\n", i);
        arr[i].i = i;
        sprintf(arr[i].message, "Hello from thread %d", i);
        pthread_create(&arr[i].id, NULL, thr, &arr[i]);
        usleep(1);
    }

    for(int i = 0; i < n; i++){
        pthread_join(arr[i].id, NULL);
    }

    return EXIT_SUCCESS;
}
