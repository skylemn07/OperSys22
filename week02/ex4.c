#include <stdio.h>
#include <string.h>
#include <ctype.h>


int count(char s[], char b){
    int ans = 0;
    for (int i = 0; i < strlen(s) - 1; i++){
        if (s[i] == b) ans++;
    }
    return ans;
}

void countAll(char s[]){
    for(int i = 0; i < strlen(s) - 1; i++){
        if(i + 2 == strlen(s)) {
            printf("%c:%d", s[i], count(s, s[i]));
        } else {
            printf("%c:%d, ", s[i], count(s, s[i]));
        }

    }
}



int main()
{
    char str[256];
    fgets(str, 256, stdin);

    for (int i = 0; i < strlen(str) - 1; i++){
        str[i] = tolower(str[i]);
    }

    countAll(str);

    return 0;
}

