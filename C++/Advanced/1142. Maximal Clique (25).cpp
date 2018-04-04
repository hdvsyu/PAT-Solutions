#include <iostream>

int vt[210][210];

void judge(int *arr, int n, int nv) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (!vt[arr[i]][arr[j]]) {
                printf("Not a Clique\n");
                return;
            }
        }
    }
    for (int i = 1; i <= nv; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (vt[i][arr[j]]) {
                cnt++;
            }
        }
        if (cnt == n) {
            printf("Not Maximal\n");
            return;
        }
    }
    printf("Yes\n");
}

int main() {
    int nv = 0, ne = 0, a = 0, b = 0, m = 0, k = 0;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &a, &b);
        vt[a][b] = vt[b][a] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        int *arr = new int[k];
        for (int j = 0; j < k; j++) {
            scanf("%d", &arr[j]);
        }
        judge(arr, k, nv);
    }
    return 0;
}
