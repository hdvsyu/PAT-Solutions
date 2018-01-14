#include <cstdio>

int *pre, *in;

bool isOuput = false;

int find(int inl, int inr, int x) {
    for (int i = inl; i <= inr; i++) {
        if (in[i] == x) return i;
    }
    return -1;
}

void printPost(int pl, int pr, int inl, int inr, int n) {
    if (pl > pr || isOuput) return;
    int inRoot = find(inl, inr, pre[pl]);
    printPost(pl + 1, pl + inRoot - inl, inl, inRoot - 1, n);
    printPost(pl + inRoot - inl + 1, pr, inRoot + 1, inr, n);
    if (!isOuput) {
        printf("%d", in[inRoot]);
        isOuput = true;
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    pre = new int[n];
    in = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    printPost(0, n-1, 0, n-1, n);
    delete [] pre;
    delete [] in;
    return 0;
}
