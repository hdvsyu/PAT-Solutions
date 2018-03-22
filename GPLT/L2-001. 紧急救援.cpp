#include <iostream>
#include <vector>

using namespace std;

const int inf = 999999;

int city[501][501];
int num[501], dist[501], cnt[501], total[501], pre[501];
bool visit[501];

int find_index(int n) {
    int min = -1;
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            if (min == -1) min = i;
            else if (dist[i] < dist[min]) min = i;
        }
    }
    return min;
}

void print(int s, int d) {
    if (d == s) return;
    print(s, pre[d]);
    printf(" %d", d);
}

void dijkstra(int s, int d, int n) {
    dist[s] = 0;
    total[s] = num[s];
    cnt[s] = 1;
    while (true) {
        int index = find_index(n);
        if (index == -1) break;
        visit[index] = true;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                if (dist[i] > dist[index] + city[index][i]) {
                    dist[i] = dist[index] + city[index][i];
                    cnt[i] = cnt[index];
                    total[i] = num[i] + total[index];
                    pre[i] = index;
                } else if (dist[i] == dist[index] + city[index][i]) {
                    cnt[i] += cnt[index];
                    if (total[i] < total[index] + num[i]) {
                        total[i] = total[index] + num[i];
                        pre[i] = index;
                    }
                }
            }
        }
    }
}

int main() {
    int n = 0, m = 0, s = 0, d = 0, c1 = 0, c2 = 0, len = 0;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i <= 500; i++) {
        dist[i] = inf;
        for (int j = 0; j <= 500; j++) {
            if (i != j) city[i][j] = inf;
        }
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &c1, &c2, &len);
        city[c1][c2] = city[c2][c1] = len;
    }
    
    dijkstra(s, d, n);
    
    printf("%d %d\n%d", cnt[d], total[d], s);
    print(s, d);
    return 0;
}


