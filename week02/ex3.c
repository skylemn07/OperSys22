#include <stdio.h>

long long pow1(int b, int c){
    long long ans = 1;
    while(c != 0){
        ans = ans * b;
        c -= 1;
    }
    return ans;
}

long long convertToTen(long long a, int b) {
    if (b == 10) {
        return a;
    } else {
        long long ot = 0;
        int i = 0;
        while (a != 0) {
            ot = ot + (long)pow1(b, i) * (a % 10);
            i += 1;
            a = a / 10;
        }
        return ot;
    }
}

void convert(long long a, int b, int c){
    long long out = convertToTen(a, b);
    long long ans = 0; int i = 0;
    char len[256];
    while (out > 0){
        ans = ans + pow1(10, i) * (out % c);
        i += 1;
        out = out / c;
    }
    sprintf(len, "%lld", ans);
    printf("result of converting %s", len);
}
int main()
{
    char str[256];
    fgets(str, 256, stdin);
    long long a;
    int b; int c;
    sscanf(str, "%lld %d %d", &a, &b, &c);

    int corr = 0;
    long long a1 = a;

    while (corr == 0 && a1 > 0){
        if(a1 % 10 >= b) corr += 1;
        a1 = a1 / 10;
    }

    if((b > 10 || b < 2) || (c > 10 || c < 2) || corr > 0) {
        printf("cannot convert");
    } else {
        convert (a, b, c);
    }

    return 0;
}
