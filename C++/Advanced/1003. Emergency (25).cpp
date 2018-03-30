#include <cstdio>

const int inf = 999999;
int recur[501], c[501][501], dist[501], visit[501], cnt[501], recurs[501];

int find_index(int n) {
    int min = -1;
    for (int i = 0; i < n; i++) {
        if (!visit[i] && (min == -1 || dist[i] < dist[min]))
            min = i;
    }
    return min;
}

int main() {
    
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            c[i][j] = inf;
        }
        dist[i] = inf;
    }
    
    int n = 0, m = 0, c1 = 0, c2 = 0, a = 0, b = 0, l = 0;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &recur[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &l);
        c[a][b] = c[b][a] = l;
    }
    
    dist[c1] = 0;
    cnt[c1] = 1;
    recurs[c1] = recur[c1];
    while (true) {
        int index = find_index(n);
        if (index == -1) break;
        visit[index] = 1;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                if (dist[i] > dist[index] + c[index][i]) {
                    dist[i] = dist[index] + c[index][i];
                    cnt[i] = cnt[index];
                    recurs[i] = recurs[index] + recur[i];
                } else if (dist[i] == dist[index] + c[index][i]) {
                    cnt[i] += cnt[index];
                    if (recurs[i] < recurs[index] + recur[i]) {
                        recurs[i] = recurs[index] + recur[i];
                    }
                }
            }
        }
    }
    printf("%d %d", cnt[c2], recurs[c2]);
    return 0;
}
