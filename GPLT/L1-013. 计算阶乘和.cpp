#include <iostream>

int main() {
    int n = 0, sum = 1;
    scanf("%d", &n);
    int *f = new int[n+1];
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * i;
        sum += f[i];
    }
    printf("%d", sum);
    return 0;
}
