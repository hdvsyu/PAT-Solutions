#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int non_negative_num(double c[], int start) {
    int cnt = 0;
    for (int i = start; i >= 0; i--)
        if (abs(c[i]) + 0.05 >= 0.1)
            cnt++;
    return cnt;
}

void print_poly(double c[], int start) {
    printf("%d", non_negative_num(c, start));
    if (non_negative_num(c, start) == 0) printf(" 0 0.0");
    for (int i = start; i >= 0; i--) {
        if (abs(c[i]) + 0.05 >= 0.1)
            printf(" %d %.1f", i, c[i]);
    }
}

double c1[5000], c2[5000], c3[5000];

int main() {
    int m = 0, n = 0, t = 0, max_1 = -1, max_2= -1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        max_1 = max_1 > t ? max_1 : t;
        scanf("%lf", &c1[t]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        max_2 = max_2 > t ? max_2 : t;
        scanf("%lf", &c2[t]);
    }
    
    int t_1 = max_1, t_2 = max_2;
    while (t_1 >= t_2) {
        double c = c1[t_1] / c2[t_2];
        c3[t_1 - t_2] = c;
        for (int i = t_1, j = t_2; j >= 0; j--, i--) {
            c1[i] -= c2[j] * c;
        }
        while (abs(c1[t_1]) < 0.000001) {
            t_1--;
        }
    }
    print_poly(c3, max_1 - max_2);
    printf("\n");
    print_poly(c1, t_1);
    return 0;
}
