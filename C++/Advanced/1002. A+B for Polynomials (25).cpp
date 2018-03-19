#include <cstdio>

int main() {
    double ploy[1001] = {0.0};
    int k = 0, n = 0, cnt = 0;
    double an = 0;
    for (int j = 0; j < 2; j++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %lf", &n, &an);
            ploy[n] += an;
        }
    }
    
    for (int i = 0; i <= 1000; i++) {
        if (ploy[i] != 0.0) cnt++;
    }
    
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (ploy[i] != 0.0) {
            printf(" %d %.1f", i, ploy[i]);
        }
    }
    return 0;
}

