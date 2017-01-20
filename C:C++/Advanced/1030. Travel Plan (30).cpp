#include <cstdio>
#include <vector>

using namespace std;

struct City {
    int dis, cost;
};

struct City **cities;
int *isVisited;


int final_len = 100000, final_cost;
vector<int> final_path;
void dfs (int cur, int dest, int len, int cost, vector<int> &path, int n) {
    if (cur == dest) {
        if (len < final_len) {
            final_len = len;
            final_cost = cost;
            final_path = path;
        } else if (len == final_len && cost < final_cost) {
            final_cost = cost;
            final_path = path;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        struct City c = cities[cur][i];
        if (c.dis != -1 && !isVisited[i]) {
            isVisited[i] = 1;
            path.push_back(i);
            dfs(i, dest, len + c.dis, cost + c.cost, path, n);
            path.pop_back();
            isVisited[i] = 0;
        }
    }
}

void printPath() {
    for (int i = 0; i < final_path.size(); i++) {
        printf("%d ", final_path[i]);
    } 
}

int main () {
    int n = 0, m = 0, s = 0, d = 0;
    scanf("%d %d %d %d", &n, &m, &s, &d);
 
    cities = new struct City* [n];
    isVisited = new int [n];
    for (int i = 0; i < n; i++) {
        cities[i] = new struct City [n];
        isVisited[i] = 0;
        for (int j = 0; j < n; j++) {
            cities[i][j].dis = cities[i][j].dis = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        int a = 0, b = 0, dis = 0, cost = 0;
        scanf("%d %d %d %d", &a, &b, &dis, &cost);
        cities[a][b].dis = cities[b][a].dis = dis;
        cities[a][b].cost = cities[b][a].cost = cost;
    }

    vector<int> path;
    path.push_back(s);
    isVisited[s] = 1;
    dfs(s, d, 0, 0, path, n); 

    printPath();
    printf("%d %d", final_len, final_cost);

    for (int i = 0; i < n; i++) {
        delete [] cities[i];
    }
    delete [] cities;
    return 0;
}
