#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v(100);

int flag = 0;

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int n = q.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            int root = q.front();
            q.pop();
            if (v[root].size() == 0) cnt++;
            for (int j = 0; j < v[root].size(); j++) {
                q.push(v[root][j]);
            }
        }
        if (flag) printf(" ");
        flag = 1;
        printf("%d", cnt);
    }
}

int main() {
    int n = 0, m = 0, id = 0, k = 0, t = 0;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            v[id].push_back(t);
        }
    }
    bfs();
    return 0;
}
