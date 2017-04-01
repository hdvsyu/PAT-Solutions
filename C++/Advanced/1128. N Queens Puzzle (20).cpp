#include <cmath>
#include <cstdio>

using namespace std;

bool isSameDiagonal(int *q, int n, int current) {
    for (int i = 1; i < current; i++) {
        if (fabs(i - current) / fabs(q[i] - q[current]) == 1) {
            return false;
        }
    }
    return true;
}

bool isNQueues(int *q, int n) {
    bool *row = new bool[n + 1]; // same row
    for (int i = 2; i <= n; i++) {
        row[q[i - 1]] = true;
        if (row[q[i]] || !isSameDiagonal(q, n, i) || fabs(q[i] - q[i - 1]) <= 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int k = 0;
    scanf("%d", &k);
    int *q = new int[1010];
    for (int c = 0; c < k; c++) {
        int n = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &q[i]);
        }
        if (n >= 4 && isNQueues(q, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}