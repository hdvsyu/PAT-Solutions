#include <cstdio>
#include <cstring>

int toInt(char *z, int s, int e) {
    int num = 0;
    for (int i = s; i <= e; i++) {
        num = num * 10 + z[i] - '0';
    }
    return num;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    char z[30];
    for (int i = 0; i < n; i++) {
        scanf("%s", z);
        int znum = toInt(z, 0, strlen(z) - 1);
        int a = toInt(z, 0, strlen(z) / 2 - 1);
        int b = toInt(z, strlen(z) / 2, strlen(z) - 1);
        if ((a * b != 0) && znum % (a * b) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
