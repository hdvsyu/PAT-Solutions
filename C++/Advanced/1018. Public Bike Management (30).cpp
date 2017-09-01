#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

const int inf = 99999999;
int graph[510][510];
int weight[510];
bool visited[510];

void initGraph() {
    for (int i = 0; i < 510; i++)
        for (int j = 0; j < 510; j++)
            graph[i][j] = inf;
}

vector<int> path, tPath;
int sent = inf, back = inf, shortest = inf;

void dfs(int cur, int sp, int n, int tlen, int tSent, int tBack) {
    if (cur == sp) {
        if (shortest > tlen) {
            shortest = tlen;
            path = tPath;
            sent = tSent;
            back = tBack;
        } else if (shortest == tlen) {
            if (sent > tSent) {
                sent = tSent;
                back = tBack;
                path = tPath;
            } else if (sent == tSent) {
                if (back > tBack) {
                    back = tBack;
                    path = tPath;
                }
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (visited[i] == false && graph[cur][i] != inf) {
                visited[i] = true;
                tPath.push_back(i);
                if (weight[i] <= 0) {
                    if (abs(weight[i]) <= tBack) {
                        dfs(i, sp, n, tlen + graph[cur][i], tSent, tBack - abs(weight[i]));
                    } else {
                        dfs(i, sp, n, tlen + graph[cur][i], tSent + abs(weight[i]) - tBack, 0);
                    }
                } else {
                    dfs(i, sp, n, tlen + graph[cur][i], tSent,  tBack + abs(weight[i]));
                }
                visited[i] = false;
                tPath.pop_back();
            }
        }
    }
}

int main() {
    int cmax = 0, n = 0, sp = 0, m = 0, si = 0, sj = 0, tij = 0;;
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= cmax / 2;
    }
    initGraph();
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &si, &sj, &tij);
        graph[si][sj] = graph[sj][si] = tij;
    }
    dfs(0, sp, n, 0, 0, 0);
    printf("%d ", sent);
    printf("0");
    for (int i = 0; i < path.size(); i++) {
        printf("->%d", path[i]);
    }
    printf(" %d\n", back);
    return 0;
}
