#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int *p = new int[s.length()];
    int *t = new int[s.length()];
    for (int i = 0; i < s.length(); i++) {
        p[i] = i == 0 ? (s[i] == 'P' ? 1 : 0) : (s[i] == 'P' ? p[i - 1] + 1 : p[i - 1]);
        t[s.length() - 1 - i] = i == 0 ? (s[s.length() - 1] == 'T' ? 1 : 0) : (s[s.length() - 1 - i] == 'T' ? t[s.length() - i] + 1 : t[s.length() - i]);
    }
    long result = 0;
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == 'A') {
            result = ((p[i - 1] * t[i + 1] % 1000000007) + result) % 1000000007;
        }
    }
    cout << result;
    delete [] t;
    delete [] p;
    return 0;
}
