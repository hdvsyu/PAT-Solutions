#include <cstdio>

int main() {
    double poly[1001] = {0.0}, result[2001] = {0.0}, an = 0;
    int k = 0, n = 0, cnt = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &an);
        poly[n] = an;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &an);
        for (int i = 0; i <= 1000; i++) {
            result[i+n] += poly[i] * an;
        }
    }
    
    for (int i = 2000; i >= 0; i--) {
        if (result[i] != 0.0) {
            cnt++;
        }
    }
    printf("%d", cnt);
    
    for (int i = 2000; i >= 0; i--) {
        if (result[i] != 0.0) {
            printf(" %d %.1f", i, result[i]);
        }
    }
    
    return 0;
}
