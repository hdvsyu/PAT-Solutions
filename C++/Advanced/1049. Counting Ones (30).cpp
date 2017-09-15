#include <cstdio>

int main() {
    int n = 0, cur = 1, left = 0, right = 0, now = 0, ans = 0;
    scanf("%d", &n);
    while (n / cur != 0) {
        left = n / (cur * 10);
        right = n % cur;
        now = n % (cur * 10) / cur;
        if (now == 0) {
            ans += left * cur;
        } else if (now == 1) {
            ans += left * cur + right + 1;
        } else {
            ans += (left + 1) * cur;
        }
        cur *= 10;
    }
    printf("%d\n", ans);
}
