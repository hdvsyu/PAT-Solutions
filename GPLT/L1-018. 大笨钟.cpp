#include <iostream>

int main() {
    int h = 0, m = 0;
    scanf("%d:%d", &h, &m);
    if (h < 12 || (h == 12 && m == 0)) {
        printf("Only %02d:%02d.  Too early to Dang.", h, m);
    } else {
        for (int i = 0; i < h - 12; i++) printf("Dang");
        if (m > 0) printf("Dang");
    }
    return 0;
}
