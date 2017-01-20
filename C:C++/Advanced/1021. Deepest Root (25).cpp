#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int> > m;

int *visited, *level;
void dfs (int cur) {
    for (int i = 0; i < m[cur].size(); i++) {
        if (visited[m[cur][i]] == 0) {
            visited[m[cur][i]] = 1;
            dfs(m[cur][i]);
        }
    }
}

int getMax (int n) {
    int maxValue = level[1];
    for (int i = 2; i <= n; i++) {
        if (level[i] > maxValue) {
            maxValue = level[i];
        }
    }
    return maxValue;
}

int bfs (int cur, int n) {
    queue<int> r;
    r.push(cur);
    fill(visited, visited + n + 1, 0);
    fill(level, level + n + 1, 0);
    level[cur] = 1; visited[cur] = 1;
    while (r.size() != 0) {
        cur = r.front();
        r.pop();
        for (int i = 0; i < m[cur].size(); i++) {
            int c = m[cur][i];
            if (visited[c] == 0) {
                visited[c] = 1;
                r.push(c);
                level[c] = level[cur] + 1;
            }
        }
    }
    return getMax(n);
}

int main () {
    int n = 0;
    scanf("%d", &n);
    m.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    
    int k = 0;
    visited = new int [n + 1];
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs(i);
            k++;
        }
    }
    
    if (k != 1) printf("Error: %d components\n", k);
    else {
        level = new int [n + 1];
        int maxValue = -1;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int v = bfs(i, n);
            if (v > maxValue) {
                ans.clear();
                ans.push_back(i);
                maxValue = v;
            } else if (v == maxValue) {
                ans.push_back(i);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            printf("%d\n", ans[i]);
        }
    }
    delete [] level;
    delete [] visited;
    return 0;
}