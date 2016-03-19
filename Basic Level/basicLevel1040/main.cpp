#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    long *p = new long[s.length()];
    long *t = new long[s.length()];
    for (int i = 0; i < s.length(); i++) {
        int j = s.length() - 1 - i;
        
        if (s[i] == 'P') {
            if (i == 0) {
                p[i] = 1;
            } else {
                p[i] = p[i - 1] + 1;
            }
        } else {
            if (i == 0) {
                p[i] = 0;
            } else {
                p[i] = p[i - 1];
            }
        }
        
        if (s[j] == 'T') {
            
            if (j == s.length() - 1) {
                t[j] = 1;
            } else {
                t[j] = t[j + 1] + 1;
            }
        } else {
            if (j == s.length() - 1) {
                t[j] = 0;
            } else {
                t[j] = t[j + 1];
            }
        }
    }
    
    long long total = 0;
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == 'A') {
            total = (total + (p[i] * t[i]) % 1000000007) % 1000000007;
        }
    }
    
    cout << total << endl;
    
    
    delete [] p;
    delete [] t;
    return 0;
}
