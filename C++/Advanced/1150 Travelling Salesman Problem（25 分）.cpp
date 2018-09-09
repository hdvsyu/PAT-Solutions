#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int graph[210][210];

const int inf = 99999;

void init_graph() {
    for (int i = 0; i < 210; i++) {
        fill(graph[i], graph[i] + 210, inf);
    }
}

bool is_cycle(int *arr, int m, int n, int &path_dist) {
    int start = arr[0];
    vector<int> cnt(n+1, 0);
    cnt[arr[0]] += 1;
    for (int i = 1; i < m; i++) {
        cnt[arr[i]] += 1;
        if (graph[arr[i]][start] == inf) {
            path_dist = -1;
            return false;
        } else {
            path_dist += graph[arr[i]][start];
            start = arr[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0)
            return false;
    }
    return arr[0] == arr[m-1];
}

bool is_simple_cycle(int *arr, int m, int n) {
    vector<int> cnt(n+1, 0);
    for (int i = 1; i < m; i++) {
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 1) return false;
    }
    return true;
}


int main() {
    init_graph();
    int n = 0, m= 0, a = 0, b = 0, dist = 0, k = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &dist);
        graph[a][b] = graph[b][a] = dist;
    }
    scanf("%d", &k);
    map<int, int> short_path;
    for (int i = 0; i < k; i++) {
        scanf("%d", &m);
        int *arr = new int[m];
        for (int j = 0;j < m; j++) {
            scanf("%d", &arr[j]);
        }
        int path_dist = 0;
        if (is_cycle(arr, m, n, path_dist) == false) {
            if (path_dist == -1) {
                printf("Path %d: NA (Not a TS cycle)\n", i+1);
            } else {
                printf("Path %d: %d (Not a TS cycle)\n", i+1, path_dist);
            }
        } else {
            short_path[path_dist] = i+1;
            if (is_simple_cycle(arr, m, n) == true) {
                printf("Path %d: %d (TS simple cycle)\n", i+1, path_dist);
            } else {
                printf("Path %d: %d (TS cycle)\n", i+1, path_dist);
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", short_path.begin()->second, short_path.begin()->first);
    return 0;
}
