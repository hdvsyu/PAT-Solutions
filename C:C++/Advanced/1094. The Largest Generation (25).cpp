#include <cstdio>
#include <queue>

using namespace std;

int matrix[100][100], isVisited[100], level = 1;

void bfs (queue<int> q, int &largest, int l, int n) {
    queue<int> t;
    while (q.size() != 0) {
        int cur = q.front();
        q.pop();
        isVisited[cur] = 1;
        for (int i = 1; i <= n; i++) {
            if (matrix[cur][i] == 1 && !isVisited[i]) {
                t.push(i);
            }
        }
    }
    if (t.size() > largest) {
        largest = t.size();
        level = l + 1;
    }
    if (t.size() != 0) {
        bfs(t, largest, l + 1, n);
    }
}

int main () {
    int n = 0, m = 0;;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int id = 0, k = 0;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            int p = 0;
            scanf("%d", &p);
            matrix[id][p] = matrix[p][id] = 1;
        }
    }
    int largest = 1;
    queue<int> q;
    q.push(1);
    bfs(q, largest, 1, n);
    printf("%d %d", largest, level);
    return 0;
}
