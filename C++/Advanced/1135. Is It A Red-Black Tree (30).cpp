#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int find(vector<int> tree, int s, int e) {
    int i = s+1;
    while (i <= e && abs(tree[s]) > abs(tree[i])) i++;
    return i;
}

bool solve4(vector<int> tree, int s, int e) {
    if (s > e) return true;
    int i = find(tree, s, e);
    if (tree[s] < 0) {
        if (s+1 <= e && tree[s+1] < 0) return false;
        if (i <= e && tree[i] < 0) return false;
    }
    return solve4(tree, s+1, i-1) && solve4(tree, i, e);
}

int getH(vector<int> tree, int s, int e) {
    if (s > e) return 1;
    int i = find(tree, s, e);
    int l = getH(tree, s+1, i-1);
    int r = getH(tree, i, e);
    return tree[s] > 0 ? max(l, r) + 1 : max(l, r);
}

bool solve5(vector<int> tree, int s, int e) {
    if (s > e) return true;
    int i = find(tree, s, e);
    int l = getH(tree, s+1, i-1);
    int r = getH(tree, i, e);
    if (l != r) return false;
    return solve5(tree, s+1, i-1) && solve5(tree, i, e);
}

bool isRBT(vector<int> tree, int n) {
    if (tree[0] < 0) return false;
    if (!solve4(tree, 0, n-1)) return false;
    if (!solve5(tree, 0, n-1)) return false;
    return true;
}

int main() {
    int k = 0, n = 0;
    scanf("%d", &k);
    vector<int> tree;
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        tree.resize(n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &tree[j]);
        }
        if (isRBT(tree, n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
