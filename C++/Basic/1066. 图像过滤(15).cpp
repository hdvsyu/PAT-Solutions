#include <cstdio>

int main() {
    int m = 0, n = 0, a = 0, b = 0, val = 0;
    scanf("%d %d %d %d %d", &m, &n, &a, &b, &val);
    
    int **pic = new int *[m];
    for (int i = 0; i < m; i++) {
        pic[i] = new int [n];
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &pic[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) {
                printf(" ");
            }
            if (pic[i][j] >= a && pic[i][j] <= b) {
                printf("%03d", val);
            } else {
                printf("%03d", pic[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}