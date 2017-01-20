#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int level;
    double val;
    vector<int> child;
};

struct Node *tree;

void dfs (int root, int l) {
    vector<int> q = tree[root].child;
    for (int i = 0; i < q.size(); i++) {
        tree[q[i]].level = l;
        dfs(q[i], l + 1);
    }
}

int main () {
    int n = 0;
    double p = 0, r = 0;
    scanf("%d %lf %lf", &n, &p, &r);
    tree = new struct Node [n];
    for (int i = 0; i < n; i++) {
        int k = 0;
        scanf("%d", &k);
        if (k == 0) scanf("%lf", &tree[i].val);
        for (int j = 0; j < k; j++) {
            int id = 0;
            scanf("%d", &id);
            tree[i].child.push_back(id);
        }
    }
    
    dfs(0, 1);
    double total = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i].child.size() == 0) {
            total += tree[i].val * p * pow(r / 100 + 1, tree[i].level);
        }
    }
    printf("%.1f", total);
    delete [] tree;
    return 0;
}
