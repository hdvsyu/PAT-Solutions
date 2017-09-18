#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vertex;

int bfs(vector<int> v, int n) {
    bool *visit = new bool[n];
    fill(visit, visit + n, false);
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        vector<int> list = vertex[v[i]];
        visit[v[i]] = true;
        for (int j = 0; j < list.size(); j++) {
            if (!visit[list[j]]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n = 0, m = 0, a = 0, b = 0, k = 0;
    scanf("%d %d", &n, &m);
    vertex.resize(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int nv = 0;
        scanf("%d", &nv);
        vector<int> v(nv);
        for (int j = 0; j < nv; j++) {
            scanf("%d", &v[j]);
        }
        if (bfs(v, n) == m) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
