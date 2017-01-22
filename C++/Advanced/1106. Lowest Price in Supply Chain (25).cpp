#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int level;
    vector<int> child;
};

struct Node *tree;

void setLevel (int level, int root) {
    if (tree[root].child.size() == 0) return;
    for (int i = 0; i < tree[root].child.size(); i++) {
        tree[tree[root].child[i]].level = level + 1;
        setLevel(level + 1, tree[root].child[i]);
    }
}

int main () {
    int n = 0;
    double p = 0, r = 0;
    scanf("%d %lf %lf", &n, &p, &r);
    tree = new struct Node[n];
    for (int i = 0; i < n; i++) {
        int k = 0;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int id = 0;
            scanf("%d", &id);
            tree[i].child.push_back(id);
        }
    }
    
    setLevel(0, 0);
    int l = n, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i].child.size() == 0) {
            if (tree[i].level < l) {
                l = tree[i].level;
                cnt = 1;
            } else if (tree[i].level == l) {
                cnt++;
            }
        }
    }
    printf("%.4f %d", p * pow(1 + r / 100, l), cnt);
    delete [] tree;
    return 0;
}
