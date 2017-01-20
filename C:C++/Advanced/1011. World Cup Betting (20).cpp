#include <cstdio>

int main() {
    double profit = 1;
    for (int i = 0; i < 3; i++) {
        double w = 0, t = 0, l = 0;
        scanf("%lf %lf %lf", &w, &t, &l);
        if (w > t && w > l) {
            printf("W ");
            profit *= w;
        } else if (t > w && t > l) {
            printf("T ");
            profit *= t;
        } else {
            printf("L ");
            profit *= l;
        }
    }
    printf("%.2f", (profit * 0.65 - 1) * 2);
    return 0;
}
