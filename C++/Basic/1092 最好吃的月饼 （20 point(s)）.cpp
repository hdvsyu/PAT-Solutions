#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    unsigned int n = 0, m = 0, t = 0, flag = 0;
    cin >> n >> m;
    vector<unsigned int> v(n+1, 0);
    for (int var1 = 0; var1 < m; var1++) {
        for (int var2 = 1; var2 <= n; var2++) {
            cin >> t;
            v[var2] += t;
        }
    }
    unsigned int max = *max_element(v.begin(), v.end());
    cout << max << endl;
    for (unsigned int var1 = 1; var1 <= n; var1++) {
        if (v[var1] == max) {
            if (flag) cout << " ";
            cout << var1;
            flag = 1;
        }
    }
    return 0;
}
