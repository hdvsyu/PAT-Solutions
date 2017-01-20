#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int main () {
    double poly1[1001], poly2[1001];
    memset(poly1, 0, sizeof(poly1));
    memset(poly2, 0, sizeof(poly2));
    int k = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int t = 0;
        scanf("%d", &t);
        scanf("%lf", &poly1[t]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int t = 0;
        scanf("%d", &t);
        scanf("%lf", &poly2[t]);
    }
    
    double poly[2001];
    memset(poly, 0, sizeof(poly));
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            poly[i + j] += poly1[i] * poly2[j];
        }
    }
    
    int cnt = 0;
    for (int i = 2000; i >= 0; i--) {
        if (poly[i] != 0) {
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--) {
        if (poly[i] != 0) {
            printf(" %d %.1f", i, poly[i]);
        }
    }
    return 0;
}