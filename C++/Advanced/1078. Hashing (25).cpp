#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int MAX = 20000;

int getPrime (bool *prime, int m) {
    memset(prime, true, MAX);
    prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        for (int j = 2; j * i < MAX; j++) {
            prime[i * j] = false;
        }
    }
    while (!prime[m]) {
        m++;
    }
    return m;
}

void printIndex(map<int, bool> &h, int index, int m) {
    for (int i = 0; i < m; i++) {
        int t = (index + i * i) % m;
        if (!h[t]) {
            h[t] = true;
            printf("%d", t);
            return;
        }
    }
    printf("-");
}

int main() {
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    bool prime[MAX];
    m = getPrime(prime, m);
    map<int, bool> h;
    for (int i = 0; i < n; i++) {
        int t = 0;
        scanf("%d", &t);
        if (i != 0) printf(" ");
        printIndex(h, t % m, m);
    }
    return 0;
}
