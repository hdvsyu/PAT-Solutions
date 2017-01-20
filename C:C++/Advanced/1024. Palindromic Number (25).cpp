#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string removeHeadZero (string s) {
    int i = 0;
    while (i < s.size() && s[i] == '0') i++;
    return s.substr(i);
}

string add (string t, string n) {
    string s;
    t = removeHeadZero(t);
    int temp = 0;
    int i = t.size() - 1, j = n.size() - 1;
    while (i >= 0 && j >= 0) {
        int num = temp + t[i] - '0' + n[j] - '0';
        s = to_string(num % 10) + s;
        temp = num / 10;
        i--; j--;
    } 
    while (i >= 0) {
        int num = temp + t[i] - '0';
        s = to_string(num % 10) + s;
        temp = num / 10;
        i--;
    }

    while (j >= 0) {
        int num = temp + n[j] - '0';
        s = to_string(num % 10) + s;
        temp = num / 10;
        j--;
    }

    if (temp == 1) s = "1" + s;
    return s;
} 

int main () {
    int k = 0;
    string n;
    cin >> n >> k;
    bool state = false;
    for (int i = 0; i < k; i++) {
        string t = n;
        reverse(t.begin(), t.end());
        if (t == n) {
            cout << n << endl << i << endl;
            state = true;
            break;
        }
        n = add(t, n);
    }
    if (!state) cout << n << endl << k << endl;
    return 0;
}
