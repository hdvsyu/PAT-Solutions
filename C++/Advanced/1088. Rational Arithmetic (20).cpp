#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

long getGcd (long a, long b) {
    if (b == 0) return a;
    return getGcd(b, a % b);
}

void printNum(long a, long b) {
    if (a < 0) printf("(");
    if (a == 0) printf("0");
    if (a / b != 0) printf("%ld", a / b);
    if (a % b != 0) {
        if (a / b != 0) {
            printf(" %ld/%ld", abs(a) % b, b);
        } else {
            printf("%ld/%ld", a % b, b);
        }
    }
    if (a < 0) printf(")");
}

void sum (long a1, long b1, long a2, long b2) {
    printNum(a1, b1);
    printf(" + ");
    printNum(a2, b2);
    printf(" = ");
    long a = a1 * b2 + a2 * b1;
    long b = b1 * b2;
    long gcd = abs(getGcd(a, b));
    a /= gcd;
    b /= gcd;
    printNum(a, b);
}

void difference (long a1, long b1, long a2, long b2) {
    printNum(a1, b1);
    printf(" - ");
    printNum(a2, b2);
    printf(" = ");
    long a = a1 * b2 - a2 * b1;
    long b = b1 * b2;
    long gcd = abs(getGcd(a, b));
    a /= gcd;
    b /= gcd;
    printNum(a, b);
}

void product (long a1, long b1, long a2, long b2) {
    printNum(a1, b1);
    printf(" * ");
    printNum(a2, b2);
    printf(" = ");
    long t = abs(getGcd(a1, b2));
    a1 /= t;
    b2 /= t;
    t = abs(getGcd(a2, b1));
    a2 /= t;
    b1 /= t;
    long a = a1 * a2;
    long b = b1 * b2;
    long gcd = abs(getGcd(a, b));
    a /= gcd;
    b /= gcd;
    printNum(a, b);
}

void quotient (long a1, long b1, long a2, long b2) {
    printNum(a1, b1);
    printf(" / ");
    printNum(a2, b2);
    printf(" = ");
    if (a2 == 0) {
        printf("Inf");
    } else {
        if (a2 < 0) {
            a2 = -a2;
            b2 = -b2;
        }
        long t = abs(getGcd(a1, a2));
        a1 /= t;
        a2 /= t;
        t = abs(getGcd(b2, b1));
        b2 /= t;
        b1 /= t;
        long a = a1 * b2;
        long b = b1 * a2;
        long gcd = abs(getGcd(a, b));
        a /= gcd;
        b /= gcd;
        printNum(a, b);
    }
}

int main () {
    long a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    long gcd1 = abs(getGcd(a1, b1)), gcd2 = abs(getGcd(a2, b2));
    a1 /= gcd1;
    b1 /= gcd1;
    a2 /= gcd2;
    b2 /= gcd2;
    sum(a1, b1, a2, b2);
    printf("\n");
    difference(a1, b1, a2, b2);
    printf("\n");
    product(a1, b1, a2, b2);
    printf("\n");
    quotient(a1, b1, a2, b2);
    return 0;
}
