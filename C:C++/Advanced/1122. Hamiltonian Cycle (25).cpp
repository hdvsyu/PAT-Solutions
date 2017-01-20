#include <cstdio>

int **graph;

int isConnected(int *v, int n) {
    int pre = v[0];
    for (int i = 1; i < n; i++) {
        if (graph[pre][v[i]] != 1) {
            return 0;
        }
        pre = v[i];
    }
    return 1;
}

int isHamilt(int *v, int n) {
    if (v[0] != v[n - 1]) return 0;
    int *times = new int[n];
    for (int i = 0; i < n; i++) {
        times[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        times[v[i]]++;
    }
    
    for (int i = 1; i < n; i++) {
        if (i == v[0]) {
            if (times[i] != 2) {
                return 0;
            }
        } else {
            if (times[i] != 1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    graph = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        graph[i] = new int[n+1];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    int k = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int kn = 0;
        scanf("%d", &kn);
        int *v = new int[kn];
        for (int j = 0; j < kn; j++) {
            scanf("%d", &v[j]);
        }
        if (kn == n + 1 && isConnected(v, kn) && isHamilt(v, kn)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}