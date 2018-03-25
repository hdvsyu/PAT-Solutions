#include <cstdio>

int main() {
    int n = 0, t = 0, cur = 0, time = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > cur) {
            time += (t - cur) * 6 + 5;
        } else {
            time += (cur - t) * 4 + 5;
        }
        cur = t;
    }
    printf("%d", time);
    return 0;
}

