#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int inf = 999999;

int **graph;
bool *isVisited;
int *dist;

void initGraph(int n, int m) {
    graph = new int* [n + m];
    for (int i = 0; i < n + m; i++) {
        graph[i] = new int[n + m];
        for (int j = 0; j < n + m; j++) {
            graph[i][j] = inf;
        }
        graph[i][i] = 0;
    }
}

int toInt(char *p, int n) {
    int num = 0, start = 0;
    if (p[0] == 'G') start = 1;
    for (int i = start; i < strlen(p); i++) {
        num = num * 10 + p[i] - '0';
    }
    if (p[0] == 'G') return num - 1 + n;
    else return num - 1;
}

void initStatus(int n, int m) {
    if (isVisited == NULL) {
        isVisited = new bool[n + m];
    }
    if (dist == NULL) {
        dist = new int[n + m];
    }
    for (int i = 0; i < n + m; i++) {
        isVisited[i] = false;
        dist[i] = inf;
    }
}

int findMinDist(int n, int m) {
    int min = 0;
    for (int i = 1; i < n + m; i++) {
        if (isVisited[min] == true || (isVisited[i] == false && dist[min] > dist[i])) {
            min = i;
        }
    }
    if (isVisited[min] == true) return -1;
    else return min;
}

void dijkstra(int s, int n, int m) {
    dist[s] = 0;
    while (true) {
        s = findMinDist(n, m);
        if (s == -1) {
            break;
        }
        isVisited[s] = true;
        for (int i = 0; i < n + m; i++) {
            if (dist[i] > dist[s] + graph[s][i]) {
                dist[i] = dist[s] + graph[s][i];
            }
        }
    }
}

void updateG(int g, int ds, int n, int &finalG, double &min, double &aver) {
    double tmin = inf, taver = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > ds || dist[i] == inf) {
            return;
        }
        if (dist[i] < tmin) {
            tmin = dist[i];
        }
        taver += dist[i] * 1.0 / n;
    }
    
    if (tmin > min) {
        min = tmin;
        aver = taver;
        finalG = g;
    } else if (abs(tmin - min) <= 0.00001) {
        if (taver < aver) {
            aver = taver;
            finalG = g;
        }
    }
}

int main() {
    int n = 0, m = 0, k = 0, ds = 0, temp = 0;
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    initGraph(n, m);
    for (int i = 0; i < k; i++) {
        char p1[6], p2[6];
        scanf("%s %s %d", p1, p2, &temp);
        int p1i = toInt(p1, n);
        int p2i = toInt(p2, n);
        graph[p1i][p2i] = graph[p2i][p1i] = temp;
    }
    int finalG = n + m;
    double min = -1, aver = inf;
    
    for (int i = n; i < n + m; i++) {
        initStatus(n, m);
        dijkstra(i, n, m);
        updateG(i, ds, n, finalG, min, aver);
    }
    if (finalG == n + m) {
        printf("No Solution\n");
    } else {
        printf("G%d\n", finalG - n + 1);
        printf("%.1f %.1f\n", min, aver);
//        printf("%.1f %.1f\n", min, aver + 0.05);
    }
    return 0;
}
