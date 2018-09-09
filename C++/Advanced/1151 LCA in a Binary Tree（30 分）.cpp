#include <cstdio>
#include <map>

using namespace std;

map<int, int> pos;

int *in, *pre;

void lca(int inl, int inr, int pre_root, int a, int b) {
    if (inl > inr) return;
    int in_root = pos[pre[pre_root]], a_in_index = pos[a], b_in_index = pos[b];
    if (a_in_index < in_root && b_in_index < in_root) {
        lca(inl, in_root-1, pre_root+1, a, b);
    } else if ((a_in_index < in_root && b_in_index > in_root) ||
               (a_in_index > in_root && b_in_index < in_root)) {
        printf("LCA of %d and %d is %d.\n", a, b, in[in_root]);
    } else if (a_in_index > in_root && b_in_index > in_root) {
        lca(in_root+1, inr, pre_root+1+(in_root-inl), a, b);
    } else {
        if (a_in_index == in_root) {
            printf("%d is an ancestor of %d.\n", a, b);
        } else if (b_in_index == in_root) {
            printf("%d is an ancestor of %d.\n", b, a);
        }
    }
}

int main() {
    int m = 0, n = 0, a = 0, b = 0;
    scanf("%d %d", &m, &n);
    in = new int[n+1];
    pre = new int[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (pos[a] == 0 && pos[b] == 0) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (pos[a] == 0) {
            printf("ERROR: %d is not found.\n", a);
        } else if (pos[b] == 0) {
            printf("ERROR: %d is not found.\n", b);
        } else {
            lca(1, n, 1, a, b);
        }
    }
    return 0;
}
