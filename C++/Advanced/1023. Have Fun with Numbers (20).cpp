#include <cstdio>
#include <cstring>

int main () {
    char *s = new char[22];
    scanf("%s", s);
    int *pers = new int[10], temp = 0, *pree = new int[10];
    for (int i = strlen(s) - 1; i >= 0; i--) {
        pers[s[i] - '0']++;
        temp += 2 * (s[i] - '0');
        s[i] = temp % 10 + '0';
        pree[s[i] - '0']++;
        temp /= 10;
    }
    if (temp != 0) pree[temp + '0']++;
    bool state = true;
    for (int i = 1; i <= 9; i++) {
        if (pers[i] != pree[i]) {
            state = false;
        }
    }
    if (state) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    if (temp != 0) printf("%d", temp);
    printf("%s", s);
    delete [] pree;
    delete [] pers;
    delete [] s;
    return 0;
}
