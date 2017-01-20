#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > cities;
int *visited;

void dfs (int cur, int ban) {
    for (int i = 0; i < cities[cur].size(); i++) {
        int c = cities[cur][i];
        if (!visited[c] && c != ban) {
            visited[c] = 1;
            dfs(c, ban);
        }
    }
}

int main () {
    int n = 0, m = 0, k = 0;
    scanf("%d %d %d", &n, &m, &k);
    cities.resize(n + 1);
    visited = new int [n + 1];
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        cities[a].push_back(b);
        cities[b].push_back(a);
    }
    
    for (int i = 0; i < k; i++) {
        int t = 0, cnt = -1;
        scanf("%d", &t);
        
        fill(visited, visited + n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && j != t) {
                cnt++;
                visited[j] = 1;
                dfs(j, t);
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
