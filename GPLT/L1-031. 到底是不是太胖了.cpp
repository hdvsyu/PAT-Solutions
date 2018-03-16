#include <cstdio>
#include <cmath>

int main() {
    int n = 0, h = 0, w = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &h, &w);
        double standard = (h - 100) * 0.9 * 2;
        if (std::abs(w - standard) < standard * 0.1) {
            printf("You are wan mei!\n");
        } else {
            if (w > standard) printf("You are tai pang le!\n");
            else printf("You are tai shou le!\n");
        }
    }
    return 0;
}

