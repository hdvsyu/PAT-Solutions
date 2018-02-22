#include <iostream>

int main() {
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (i != a && (i - a) % 5 == 0) printf("\n");
        printf("%5d", i);
    }
    printf("\nSum = %d", (b + a) * (b - a + 1) / 2);
    return 0;
}
