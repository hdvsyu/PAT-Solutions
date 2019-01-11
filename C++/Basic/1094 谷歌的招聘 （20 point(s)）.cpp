#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    int l = 0, k = 0;
    scanf("%d %d", &l, &k);
    char s[1010];
    scanf("%s", s);
    string str = s;
    for (int i = 0; i <= l - k; i++) {
        string tmp = str.substr(i, k);
        if (is_prime(stoi(tmp))) {
            printf("%s", tmp.c_str());
            return 0;
        }
    }
    printf("404");
    return 0;
}