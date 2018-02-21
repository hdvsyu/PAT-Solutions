#include <iostream>
#include <cstring>

int main() {
    char s[][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char num[12];
    scanf("%s", num);
    for (int i = 0; i < strlen(num) - 1; i++) {
        if (i == 0 && num[i] == '-') printf("fu ");
        else if (i == 0 && num[i] == '+') continue;
        else printf("%s ", s[num[i] - '0']);
    }
    printf("%s", s[num[strlen(num) - 1] - '0']);
    return 0;
}
