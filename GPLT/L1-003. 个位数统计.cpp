#include <iostream>
#include <cstring>

int main() {
    char s[1010];
    scanf("%s", s);
    int *num = new int[10];
    for (int i = 0; i <= 9; i++) num[i] = 0;
    for (int i = 0; i < strlen(s); i++)
        num[s[i] - '0']++;
    for (int i = 0; i <= 9; i++)
        if (num[i] != 0) printf("%d:%d\n", i, num[i]);
    delete [] num;
    return 0;
}
