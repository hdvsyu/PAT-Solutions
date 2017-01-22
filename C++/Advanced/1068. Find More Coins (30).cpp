#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp (int arg1, int arg2) {
    if (arg1 > arg2) return 1;
    return 0;
}

int main () {
    vector<int> coins;
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int c = 0;
        scanf("%d", &c);
        if (c <= m) {
            coins.push_back(c);
        }
    }
    sort(coins.begin(), coins.end(), cmp);
    n = coins.size();
    
    int *dp = new int [m + 1];
    int **s = new int* [n];
    for (int i = 0; i < n; i++) {
        s[i] = new int [m + 1];
        fill(s[i], s[i] + m, 0);
    }
    fill(dp, dp + m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= coins[i]; j--) {
            if (dp[j] <= dp[j - coins[i]] + coins[i]) {
                dp[j] = dp[j - coins[i]] + coins[i];
                s[i][j] = 1;
            }
        }
    }
    
    if (dp[m] != m) printf("No Solution");
    else {
        int i = n - 1, j = m;
        vector<int> result;
        while (i >= 0) {
            if (s[i][j] == 1) {
                result.push_back(coins[i]);
                j -= coins[i];
            }
            i--;
        }
        for (int i = 0; i < result.size(); i++) {
            printf("%d", result[i]);
            if (i != result.size() - 1) printf(" ");
        }
    }
    
    for (int i = 0; i < n; i++) {
        delete [] s[i];
    }
    delete [] s;
    delete [] dp;
    return 0;
}
