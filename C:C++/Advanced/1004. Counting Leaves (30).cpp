#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> leaf;
vector<vector<int> > tree;

void bfs (queue<int> level) {
    if (level.size() == 0) return;
    queue<int> q;
    int cnt = 0;
    while (level.size() != 0) {
        int r = level.front();
        level.pop();
        if (tree[r].size() == 0) cnt++;
        for (int i = 0; i < tree[r].size(); i++) {
            q.push(tree[r][i]);
        }
    }
    leaf.push_back(cnt);
    bfs(q);
}

int main () {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    tree.resize(n+1);
    for (int i = 0; i < m; i++) {
        int id = 0, k = 0, child = 0;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            tree[id].push_back(child);
        }
    }
    
    queue<int> level;
    level.push(1);
    bfs(level);
    
    printf("%d", leaf[0]);
    for (int i = 1; i < leaf.size(); i++) {
        printf(" %d", leaf[i]);
    }
    return 0;
}
