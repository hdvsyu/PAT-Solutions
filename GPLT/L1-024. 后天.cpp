#include <cstdio>

int main() {
    int d = 0;
    scanf("%d", &d);
    printf("%d", (d + 1) % 7 + 1);
    return 0;
}
