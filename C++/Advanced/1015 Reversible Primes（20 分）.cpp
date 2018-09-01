#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int convert_new_num(int n, int d) {
    string s;
    do {
        s += to_string(n % d);
        n /= d;
    } while (n != 0);
    int result = 0, radix = 1;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        result += radix * (s[i] - '0');
        radix *= d;
    }
    return result;
}

int main() {
    int n = 0, d = 0;
    while (true) {
        scanf("%d", &n);
        if (n < 0) break;
        scanf("%d", &d);
        printf("%s\n", is_prime(n) && is_prime(convert_new_num(n, d)) ? "Yes" : "No");
    }
    return 0;
}
