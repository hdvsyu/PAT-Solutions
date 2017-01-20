#include <cstdio>

int final_len = 10000, final_team, routes, isVisited[500], teams[500], cities[500][500];

void dfs (int cur, int dest, int len, int team, int n) {
    if (cur == dest) {
        if (final_len > len) {
            final_len = len;
            routes = 1;
            final_team = team;
        } else if (final_len == len) {
            routes += 1;
            final_team = (final_team > team ? final_team : team);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isVisited[i] && cities[cur][i] != 0) {
            isVisited[i] = 1;
            dfs(i, dest, len + cities[cur][i], team + teams[i], n);
            isVisited[i] = 0;
        }
    }
}

int main () {
    int n = 0, m = 0, c1 = 0, c2 = 0;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &teams[i]);
    }
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0, l = 0;
        scanf("%d %d %d", &a, &b, &l);
        cities[a][b] = cities[b][a] = l;
    }

    isVisited[c1] = 1;
    dfs(c1, c2, 0, teams[c1], n);
    printf("%d %d", routes, final_team);
    return 0;
}
