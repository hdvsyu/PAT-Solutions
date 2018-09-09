#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

void compare(int m, double x) {
    if (m < x) printf(" Cong");
    else if (m == x) printf(" Ping");
    else printf(" Gai");
}

int main() {
    int x = 0, y = 0, m = 0, flag = 0;
    scanf("%d %d %d", &m, &x, &y);
    for (int a = 99; a >= 10; a--) {
        int b = a % 10 * 10 + a / 10;
        double c = 1.0 / x * abs(a - b);
        if (b == c * y) {
            printf("%d", a);
            compare(m, a);
            compare(m, b);
            compare(m, c);
            flag = 1;
            break;
        }
        
    }
    if (flag == 0) {
        printf("No Solution");
    }
}
