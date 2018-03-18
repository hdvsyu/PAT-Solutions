#include <cstdio>
#include <cstdlib>

void format(int x) {
    if (abs(x) < 1000) {
        printf("%d", x);
        return;
    }
    format(x / 1000);
    printf(",%03d", abs(x % 1000));
}

int main() {
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    format(a + b);
    return 0;
}
