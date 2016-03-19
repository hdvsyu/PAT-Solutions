#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, p = 0;
    cin >> n >> p;
    long long a[100001];    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (n == 0 || p < 0) {
        cout << n;
        return 0;
    }
    
    sort(a, a + n);
    
    long cnt = 1;
    for (int i = n-1; i >= 1; i--) {
        int temp = 1;
        long long M = a[i];
        for (int j = i-cnt; j >= 0 && M * 1.0 / a[j] <= p ; j--) {
            temp = i - j + 1;
        }
        cnt = cnt > temp ? cnt : temp;
    }
    
    cout << cnt;
    return 0;
}