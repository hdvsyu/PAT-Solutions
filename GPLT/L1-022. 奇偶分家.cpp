#include <cstdio>

int main() {
    int n = 0, temp = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp % 2 == 0) cnt++;
    }
    printf("%d %d", n-cnt, cnt);
    return 0;
}
