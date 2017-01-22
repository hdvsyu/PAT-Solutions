#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
bool *isVisited;
unsigned long query (const vector<vector<int> > &net, queue<int> q, int l) {
    if (l == 0) return 0;
    queue<int> qt;
    while (q.size() != 0) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < net[v].size(); i++) {
            if (!isVisited[net[v][i]]) {
                qt.push(net[v][i]);
                isVisited[net[v][i]] = true;
            }
        }
    }
    return query(net, qt, l - 1) + qt.size();
}

int main () {
    int n = 0, l = 0;
    scanf("%d %d", &n, &l);
    vector<vector<int> > net(n + 1);
    for (int i = 1; i <= n; i++) {
        int m = 0;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int t = 0;
            scanf("%d", &t);
            net[t].push_back(i);
        }
    }
    
    int k = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int t = 0;
        scanf("%d", &t);
        queue<int> q;
        isVisited = new bool[n + 1];
        fill(isVisited, isVisited + n + 1, false);
        q.push(t);
        isVisited[t] = true;
        printf("%lu\n", query(net, q, l));
    }
    delete [] isVisited;
    return 0;
}
