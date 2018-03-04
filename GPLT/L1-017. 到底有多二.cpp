#include <iostream>
#include <cstring>

int main() {
    char s[51];
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '2') cnt++;
    }
    double r = 100;
    if (s[0] == '-') {
        r *= 1.5;
        r *= cnt * 1.0 / (strlen(s) - 1);
    } else {
        r *= cnt * 1.0 / strlen(s);
    }
    
    if ((s[strlen(s)-1] - '0') % 2 == 0) r *= 2;
    printf("%.2f%%", r);
    return 0;
}
