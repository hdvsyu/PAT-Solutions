#include <cstdio>
#include <cmath>

int main() {
    int num = 0;
    scanf("%d", &num);
    int sq = sqrt(num), index = 0, len = 0;
    for (int i = 2; i <= sq; i++) {
        long temp = 1, j = i;
        while(true) {
            temp *= j;
            if (num % temp != 0) break;
            if (j - i + 1 > len) {
                index = i;
                len = j - i + 1;
            }
            j++;
        }
    }
    if (len == 0) printf("1\n%d", num);
    else {
        printf("%d\n%d", len, index);
        for (int i = 1; i < len; i++) {
            printf("*%d", index + i);
        }
    }
}
