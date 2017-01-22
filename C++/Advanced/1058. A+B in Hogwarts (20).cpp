#include <cstdio>

int main() {
    int g1 = 0, s1 = 0, k1 = 0, g2 = 0, s2 = 0, k2 = 0, c = 0;
    scanf("%d.%d.%d", &g1, &s1, &k1);
    scanf("%d.%d.%d", &g2, &s2, &k2);
    int k3 = (k1 + k2) % 29;
    c = (k1 + k2) / 29;
    int s3 = (s1 + s2 + c) % 17;
    c = (s1 + s2 + c) / 17;
    int g3 = g1 + g2 + c;
    printf("%d.%d.%d", g3, s3, k3);
    return 0;
}
