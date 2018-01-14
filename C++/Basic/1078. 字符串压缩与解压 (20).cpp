#include <iostream>
#include <string>

using namespace std;

int main() {
    char c;
    scanf("%c", &c);
    getchar(); // \n\r
    string s;
    getline(cin, s);
    if (c == 'C') { // encode
        int i = 0, j = 1;
        while (i < s.length()) {
            while (j < s.length() && s[i] == s[j]) j++;
            if (j - i == 1) {
                printf("%c", s[i]);
                i = j;
                j++;
            } else {
                printf("%d%c", j - i, s[i]);
                i = j;
                j++;
            }
        }
    } else { // decode
        for (int i = 0; i < s.length(); i++) {
            int time = 0;
            while (isdigit(s[i])) {
                time = 10 * time + s[i] - '0';
                i++;
            }
            if (time != 0) {
                for (int j = 0; j < time; j++) {
                    printf("%c", s[i]);
                }
            } else {
                printf("%c", s[i]);
            }
        }
    }
    return 0;
}
