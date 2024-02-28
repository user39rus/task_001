#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROM_S 7
#define ARAB_S 13
#define LEN_S 15

void roman_notation(char *romnum);
void arabic_notification(int arabnum); // 123

int main() {
    int n;
    if (scanf("%d", &n) == 1 && (n == 1 || n == 2)) {
        if (n == 1) {
            char romnum[LEN_S];
            scanf("%s", romnum);
            roman_notation(romnum);
        }
        if (n == 2) {
            int arabnum;
            scanf("%d", &arabnum);
            arabic_notification(arabnum);
        }
    } else
        printf("n/a");
    return 0;
}

void arabic_notification(int arabnum) {
    char *roman_a[ARAB_S] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arabic_a[ARAB_S] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char rom[LEN_S] = "";
    while (arabnum > 0) {
        for (int i = 0; i < ARAB_S; i++) {
            while (arabnum >= arabic_a[i]) {
                strcat(rom, roman_a[i]);
                arabnum = arabnum - arabic_a[i];
            }
        }
    }
    printf("%s", rom);
}

void roman_notation(char *romnum) {
    char roman[ROM_S] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int arabic[ROM_S] = {1, 5, 10, 50, 100, 500, 1000};
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