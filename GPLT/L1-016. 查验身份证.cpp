#include <iostream>

int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool check(char *s) {
    int sum = 0;
    for (int i = 0; i <= 16; i++) {
        if (!isdigit(s[i])) return false;
        sum += (s[i] - '0') * weight[i];
    }
    return s[17] == m[sum % 11];
}

int main() {
    int n = 0, flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[18];
        scanf("%s", s);
        if (!check(s)) {
            printf("%s\n", s);
            flag = 1;
        }
    }
    if (!flag) printf("All passed");
    return 0;
}
