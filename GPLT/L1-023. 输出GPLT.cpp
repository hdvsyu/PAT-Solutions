#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    char s[10010];
    scanf("%s", s);
    int g = 0, p = 0, l = 0, t = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (toupper(s[i]) == 'G') g++;
        else if (toupper(s[i]) == 'P') p++;
        else if (toupper(s[i]) == 'L') l++;
        else if (toupper(s[i]) == 'T') t++;
    }
    
    while (g != 0 || p != 0 || l != 0 || t != 0) {
        if (g != 0) {printf("G"); g--;}
        if (p != 0) {printf("P"); p--;}
        if (l != 0) {printf("L"); l--;}
        if (t != 0) {printf("T"); t--;}
    }
    
    return 0;
}
