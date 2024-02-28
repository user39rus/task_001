#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROM_S 7
#define LEN_S 15
char roman[ROM_S] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int arabic[ROM_S] = {1, 5, 10, 50, 100, 500, 1000};

void roman_notation(char *romnum);

int main() {
    char romnum[LEN_S];
    scanf("%s", romnum);
    roman_notation(romnum);
    return 0;
}

void roman_notation(char *romnum) {
    int num = 0;
    int t = 0;
    int len = 0;

    num = 0;
    len = strlen(romnum);
    for (int i = len - 1; i >= 0; i--) {
        int j;
        for (j = 0; j < ROM_S; ++j)
            if (roman[j] == romnum[i]) break;

        if (arabic[j] < t) {
            t = arabic[j];
            num -= t;
        } else {
            t = arabic[j];
            num += t;
        }
    }
    printf("%d", num);
}