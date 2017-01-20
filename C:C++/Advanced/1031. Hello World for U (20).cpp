#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = ((int)s.length() + 2) / 3 - 1;
    for (int i = 0; i < n; i++) {
        cout << s[i];
        for (int j = 0; j < s.length() - 2 * n - 2; j++) {
            cout << " ";
        }
        cout << s[s.length() - 1 - i] << endl;
    }
    cout << s.substr(n, s.length() - 2 * n);
    return 0;
}
