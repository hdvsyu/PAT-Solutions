#include <string>
#include <iostream>
using namespace std;

string getStand(string num, int n) {
    string fn = num;
    fn.append(".").append(n, '0');
    
    // find the first no-zero digit and first point from head to rail.
    int digit = -1, point = -1;
    for (int i = 0; i < fn.length(); i++) {
        if (digit == -1 && fn[i] != '0' && fn[i] != '.') digit = i;
        if (point == -1 && fn[i] == '.') point = i;
    }

    string result = "0.";
    if (digit != -1) {
        
        int i = digit;
        while (result.size() != 2 + n) {
            if (fn[i] != '.') {
                result += fn[i];
            }
            i++;
        }
        result += "*10^" + to_string(point < digit ? point - digit + 1: point - digit);
        
    } else {
        result.append(n, '0');
        result += "*10^0";
    }
    return result;
}

int main() {
    int n = 0;
    string a, b;
    cin >> n >> a >> b;
    string s1 = getStand(a, n);
    string s2 = getStand(b, n);
    if (s1 == s2) {
        cout << "YES " << s1 << endl;
    } else {
        cout << "NO " << s1 << " " << s2 << endl;
    }
}
