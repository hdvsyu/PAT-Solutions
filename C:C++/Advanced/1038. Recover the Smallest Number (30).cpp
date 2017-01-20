#include <iostream>

using namespace std;

int cmp (const void *a, const void *b) {
    string arg1 = *static_cast<const string *>(a);
    string arg2 = *static_cast<const string *>(b);
    
    if (arg1 + arg2 > arg2 + arg1) return 1;
    if (arg1 + arg2 < arg2 + arg1) return -1;
    return 0;
}

int main () {
    int n = 0;
    cin >> n;
    string *num = new string [n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    qsort(num, n, sizeof(num[0]), cmp);
    string ans;
    for (int i = 0; i < n; i++) {
        ans += num[i];
    }
    while (ans.length() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if (ans.size() == 0) {
        cout << "0";
    } else {
        cout << ans;
    }
    delete [] num;
    return 0;
}