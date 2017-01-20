#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int *weight;
vector<vector<int> > tree;

bool cmp (int a, int b) {
    if (weight[a] > weight[b]) return true;
    return false;
}

void dfs (int node, string path, int s) {
    if (tree[node].size() == 0 && s == weight[node]) {
        path += " " + to_string(weight[node]);
        cout << path << endl;
        return;
    }
    for (int i = 0; i < tree[node].size(); i++) {
        dfs (tree[node][i], path + " " + to_string(weight[node]), s - weight[node]);
    }
}

int main () {
    int n = 0, m = 0, s = 0;
    scanf("%d %d %d", &n, &m, &s);
    weight = new int [n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    tree.resize(n);
    for (int i = 0; i < m; i++) {
        int id = 0, k = 0;
        scanf("%d %d", &id, &k);
        tree[id].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &tree[id][j]);
        }
        sort(tree[id].begin(), tree[id].end(), cmp);
    }
    
    if (tree[0].size() == 0 && weight[0] == s) printf("%d", s); 
    for (int i = 0; i < tree[0].size(); i++) {
        string path = to_string(weight[0]);
        dfs(tree[0][i], path, s-weight[0]);
    }
    delete [] weight;
    return 0;
}
