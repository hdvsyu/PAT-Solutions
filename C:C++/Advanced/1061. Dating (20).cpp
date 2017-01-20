#include <cstdio>
#include <cstring>
#include <cctype>
int main() {
    char *s1 = new char[60], *s2 = new char[60], *s3 = new char[60], *s4 = new char[60];
    scanf("%s %s %s %s", s1, s2, s3, s4);
    int week = -1, hour = -1;
    for (int i = 0; i < strlen(s1) && i < strlen(s2); i++) {
        if (week != - 1 && s1[i] == s2[i] && (isdigit(s1[i]) || (isupper(s1[i]) && s1[i] <= 'N'))) {
            if (isdigit(s1[i])) {
                hour = s1[i] - '0';
            } else {
                hour = 10 + (s1[i] - 'A');
            }
            break;
        }
        
        if (week == -1 && s1[i] == s2[i] && isupper(s1[i]) && s1[i] <= 'G') {
            week = s1[i] - 'A';
        }
    }
    
    int time = -1;
    for (int i = 0; i < strlen(s3) && i < strlen(s4); i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            time = i;
            break;
        }
    }
    
    char s[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    printf("%s %02d:%02d", s[week], hour, time);
    delete [] s1;
    delete [] s2;
    delete [] s3;
    delete [] s4;
    return 0;
}
