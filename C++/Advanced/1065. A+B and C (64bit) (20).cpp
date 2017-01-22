#include <iostream>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long long a, b, c;
        bool flag = false;
        cin >> a >> b >> c;
        long t = a + b;
        if ((a > 0 && b > 0 && t <= 0) || ((a >= 0 || b >= 0) && t > c)) {
            flag = true;
        }
        cout << "Case #" << i << ": " << (flag ? "true" : "false") << endl;
    }
    return 0;
}
