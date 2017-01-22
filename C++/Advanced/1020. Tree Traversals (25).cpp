#include <cstdio>
#include <cstring>
int *post, *in, *level;

void getLevel (int s, int e, int r, int l) {
    if (s > e) return;
    int i = s;
    while (i <= e && in[i] != post[r]) i++;
    getLevel(s, i - 1, r - e + i - 1, 2 * l + 1);
    getLevel(i + 1, e, r - 1, 2 * l + 2);
    level[l] = post[r];
}

int main () {
    int n = 0;
    scanf("%d", &n);
    post = new int[n], in = new int[n], level = new int[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    memset(level, -1, 100000);
    getLevel(0, n - 1, n - 1, 0);
    printf("%d", level[0]);
    for (int i = 1; n > 1; i++) {
        if (level[i] != -1) {
            printf(" %d", level[i]);
            n--;
        }
    }
    delete [] level;
    delete [] in;
    delete [] post;
    return 0;
}
