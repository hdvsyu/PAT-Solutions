#include <string>
#include <iostream>

using namespace std;

int main () {
    string s;
    getline(cin, s);
    int n = s.size();
    int **len = new int* [n];
    for (int i = 0; i < n; i++) {
        len[i] = new int [n];
    }
    for (int i = 0; i < n; i++) {
        len[i][i] = 1;
        if (i > 0 && s[i] == s[i - 1]) len[i][i - 1] = 1;
    }
    
    int maxLen = 1;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                len[i][j] = len[i + 1][j - 1];
                if (len[i][j] == 1) maxLen = max(maxLen, j - i + 1);
            } else len[i][j] = 0;
        }
    }
    printf("%d", maxLen);
    for (int i = 0; i < n; i++) {
        delete [] len[i];
    }
    delete [] len;
    return 0;
}