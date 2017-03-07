#include <cstdio>
#include <queue>

using namespace std;

int **graph, *degree;

void createArray(int n) {
//    create graph
    graph = new int* [n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int [n];
    }
    
//    create degree
    degree = new int [n];
}

void initializerArray(int n) {
//    init graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
//        init degree
        degree[i] = 0;
    }
}

void printDegree(int n) {
    printf("%d", degree[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", degree[i]);
    }
    printf("\n");
}

// all vertices of even degree
bool isEulerian(int n) {
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

// two vertices of odd degree
bool isSemiEulerian(int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) {
            cnt++;
        }
    }
    if (cnt == 2) {
        return true;
    } else {
        return false;
    }
}

// bfs
bool isConnected(int n) {
    int *isVisited = new int [n];
    int pre = 0;
    queue<int> q;
    q.push(pre);
    isVisited[pre] = true;
    while (!q.empty()) {
        pre = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (!isVisited[i] && graph[pre][i] == 1) {
                q.push(i);
                isVisited[i] = true;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    createArray(n);
    initializerArray(n);
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = 1;
        degree[a - 1]++;
        degree[b - 1]++;
    }
    
    printDegree(n);
    
    if (isConnected(n)) {
        if (isEulerian(n)) {
            printf("Eulerian");
        } else if (isSemiEulerian(n)) {
            printf("Semi-Eulerian");
        } else {
            printf("Non-Eulerian");
        }
    } else {
        printf("Non-Eulerian");
    }
    return 0;
}