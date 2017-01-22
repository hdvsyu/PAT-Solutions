#include <cstdio>

int main () {
    int n = 0, m = 0, *coins = new int[502];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int t = 0;
        scanf("%d", &t);
        coins[t]++;
    }
    int v1 = -1, v2 = -1;
    for (int i = 1; i <= 500 && i < m; i++) {
        if ((m != 2 * i && coins[i] >= 1 && m - i <= 500 && coins[m - i] >= 1) || (m == 2 * i && coins[i] >= 2)) {
            v1 = i;
            v2 = m - i;
            break;
        }
    }
    if (v1 == -1 && v2 == -1) {
        printf("No Solution");
    } else {
        printf("%d %d", v1, v2);
    }
    return 0;
}
