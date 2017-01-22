#include <cstdio>

int findNearM (int *sum, int l, int r, int v) {
    int mid = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (sum[mid] >= v) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main () {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int *sum = new int [n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        scanf("%d", &t);
        sum[i] = sum[i - 1] + t;
    }
    
    int nearM = 100000;
    for (int i = 0; i < n; i++) {
        int j = findNearM(sum, 1, n, sum[i] + m);
        if (sum[j] - sum[i] - m >= 0 && sum[j] - sum[i] - m < nearM) nearM = sum[j] - sum[i] - m;
    }
    
    for (int i = 0; i < n; i++) {
        int j = findNearM(sum, 1, n, sum[i] + m + nearM);
        if (sum[j] - sum[i] - m == nearM) {
            printf("%d-%d\n", i + 1, j);
        }
    }
    delete [] sum;
    return 0;
}
