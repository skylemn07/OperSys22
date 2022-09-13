#include <stdio.h>
void Tribonacci (int n){
    int t0 = 0, t1 = 1, t2 = 1, t3;

    if (n == 0) {
        printf("%d\n", t0);
    }
    if (n == 1) {
        printf("%d\n", t1);
    }
    if (n == 2) {
        printf("%d\n", t2);
    } else {
        for (int i = 2; i < n; ++i) {
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }

        printf("%d\n", t3);
    }

}

int main() {
    int n = 4; int n1 = 36;
    Tribonacci(n);
    Tribonacci(n1);

    return 0;
}
