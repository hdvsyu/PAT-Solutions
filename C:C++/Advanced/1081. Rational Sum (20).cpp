#include <cstdio>
#include <cstdlib>

long getGcd (long a, long b) {
    if (b == 0) return std::abs(a);
    return getGcd(b, a % b);
}

void add (long &a1, long &b1, long a2, long b2) {
    long gcd = getGcd(a2, b2);
    a2 /= gcd; b2 /= gcd;
    a1 = a1 * b2 + a2 * b1;
    b1 = b1 * b2;
    gcd = getGcd(a1, b1);
    a1 /= gcd; b1 /= gcd;
}

int main () {
    int n = 0;
    scanf("%d", &n);
    long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        long c = 0, d = 0;
        scanf("%ld/%ld", &c, &d);
        add(a, b, c, d);
    }
    if (a % b == 0) {
        printf("%ld", a / b);
    } else {
        if (a > b) printf("%ld ", a / b);
        printf("%ld/%ld", a % b, b);
    }
    return 0;
}