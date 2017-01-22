#include <cstdio>
#include <cmath>
#include <cstdlib>

int *inorder, *level;

void printPre (int s, int e, int root) {
    if (s > e) return;
    int n = e - s + 1;
    int l = log(n + 1) / log(2);
    int temp = n - pow(2, l) + 1;
    int rn = 0;
    if (temp <= pow(2, l - 1)) {
        rn = pow(2, l - 1) - 1;
    } else {
        rn = n - pow(2, l);
    }
    printPre(s, e - rn - 1, 2 * root + 1);
    printPre(e - rn + 1, e, 2 * root + 2);
    level[root] = inorder[e - rn];
}

int main () {
    int n = 0;
    scanf("%d", &n);
    inorder = new int[n], level = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    qsort(inorder, n, sizeof(inorder[0]), [](const void *a, const void *b){
        int arg1 = *static_cast<const int *>(a);
        int arg2 = *static_cast<const int *>(b);
        
        if (arg1 > arg2) return 1;
        if (arg2 > arg1) return -1;
        return 0;
    });
    printPre(0, n - 1, 0);
    printf("%d", level[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", level[i]);
    }
    delete [] inorder;
    delete [] level;
    return 0;
}
