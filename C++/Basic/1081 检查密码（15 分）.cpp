#include <cstdio>
#include <cstring>
#include <cctype>

bool contain_number(char * s) {
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (isdigit(s[i])) return true;
    }
    return false;
}

bool contain_alpha(char * s) {
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (isalpha(s[i])) return true;
    }
    return false;
}

bool contain_other_character(char * s) {
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '.') return true;
    }
    return false;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        char s[100];
        fgets(s , sizeof s, stdin);
        if (strlen(s) - 1 < 6) {
            printf("Your password is tai duan le.\n");
        } else {
            if (!contain_number(s)) {
                printf("Your password needs shu zi.\n");
            } else if (!contain_alpha(s)) {
                printf("Your password needs zi mu.\n");
            } else if (contain_other_character(s)) {
                printf("Your password is tai luan le.\n");
            } else {
                printf("Your password is wan mei.\n");
            }
        }
    }
    return 0;
}
