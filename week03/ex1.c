#include <stdio.h>
#include <malloc.h>

void foo(int *p){
    *p = 2022 - *p;
}

int main() {
    const int x = 10;
    const int* q = &x;
    int* p;
    p = (const int*) malloc(5);
    for (int i = 0; i < 5; i++){
        *(p+i) = x;
        printf("%d ", p+i);
    }

    printf("%c", '\n');
    int a;
    for (int i = 0; i < 5; i++){
        scanf("%d", &a);
        *(p+i) = a;
        foo((p+i));
    }

    free(p);

    return 0;
}
