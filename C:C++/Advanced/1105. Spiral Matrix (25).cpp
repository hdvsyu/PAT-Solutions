#include <cstdio>
#include <cmath>
#include <cstdlib>

int cmp (const void *a, const void *b) {
    int arg1 = *static_cast<const int *>(a);
    int arg2 = *static_cast<const int *>(b);
    
    if (arg1 < arg2) return -1;
    if (arg2 < arg1) return 1;
    return 0;
}

int main () {
    int N = 0;
    scanf("%d", &N);
    int n = sqrt(N);
    while (N % n != 0 ) {
        n--;
    }
    
    int *nums = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, N, sizeof(nums[0]), cmp);
    
    int m = N / n;
    if (m < n) {
        int temp = m;
        m = n;
        n = temp;
    }
    int **spiral = new int* [m + 2];
    for (int i = 0; i <= m + 1; i++) {
        spiral[i] = new int [n + 2];
        spiral[i][0] = spiral[i][n + 1] = -1;
        if (i == 0 || i == m + 1) {
            for (int j = 1; j <= n; j++) {
                spiral[i][j] = -1;
            }
        } else {
            for (int j = 1; j <= n; j++) {
                spiral[i][j] = 0;
            }
        }
    }
    
    int i = 1, j = 0;
    while (N > 0) {
        while (spiral[i][j + 1] == 0) { j++; N--; spiral[i][j] = nums[N]; }
        while (spiral[i + 1][j] == 0) { i++; N--; spiral[i][j] = nums[N]; }
        while (spiral[i][j - 1] == 0) { j--; N--; spiral[i][j] = nums[N]; }
        while (spiral[i - 1][j] == 0) { i--; N--; spiral[i][j] = nums[N]; }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) printf("%d", spiral[i][1]);
            else printf(" %d", spiral[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i <= m + 1; i++) {
        delete [] spiral[i];
    }
    delete [] spiral;
    delete [] nums;
    
    return 0;
}
