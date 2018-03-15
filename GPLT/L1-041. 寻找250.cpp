#include <cstdio>

int main() {
    int i = 0, temp = 0;
    while (~scanf("%d", &temp)) {
        i++;
        if (temp == 250) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
