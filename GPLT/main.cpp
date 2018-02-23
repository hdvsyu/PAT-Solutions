#include <iostream>
#include <cstdlib>

struct frac {
    long a, b;
}temp;

long gcd(long a, long b) {
    if (a % b == 0) return abs(b);
    return gcd(b, a % b);
}

struct frac get_sum(struct frac sum, struct frac temp) {
    long t = gcd(sum.a * temp.b + sum.b * temp.a, sum.b * temp.b);
    struct frac result = {(sum.a * temp.b + sum.b * temp.a) / t, (sum.b * temp.b) / t};
    return result;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    struct frac sum = {0, 1};
    for (int i = 0; i < n; i++) {
        scanf("%ld/%ld", &temp.a, &temp.b);
        sum = get_sum(sum, temp);
    }
    if (sum.a == 0) printf("0");
    if (abs(sum.a / sum.b) > 0) {
        printf("%ld", sum.a / sum.b);
        sum.a %= sum.b;
        if (sum.a != 0) printf(" ");
    }
    if (sum.a != 0) printf("%ld/%ld", sum.a, sum.b);
    return 0;
}
