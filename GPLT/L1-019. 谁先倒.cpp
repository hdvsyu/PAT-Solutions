#include <cstdio>

int main() {
    int a_max = 0, b_max = 0, n = 0, a = 0, b = 0, c = 0, d = 0, a_d = 0, b_d = 0;
    scanf("%d %d %d", &a_max, &b_max, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a + c == b && a + c == d) continue;
        else if (a + c == b) a_d++;
        else if (a + c == d) b_d++;
        if (a_d == a_max + 1 || b_d == b_max + 1) {
            if (a_d == a_max + 1) printf("A\n%d", b_d);
            else printf("B\n%d", a_d);
            break;
        }
    }
    return 0;
}
