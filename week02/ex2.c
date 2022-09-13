#include <stdio.h>
#include <string.h>
#define size 256

int main()
{
    char c = getchar();
    char chars[size];
    int i = 0;
    
    while (c != '.' && c != '\n') {
        chars[i] = c;
        c = getchar();
        i += 1;
    }
    
    printf("%c", '"');
    for(int j = i - 1; j >= 0; j--){
        printf("%c", chars[j]);
    }
    printf("%c", '"');
    return 0;
}
