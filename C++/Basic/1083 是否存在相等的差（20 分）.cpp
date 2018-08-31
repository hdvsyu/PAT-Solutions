#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n = 0, x = 0;
    scanf("%d", &n);
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        m[abs(x - i)]++;
    }
    for (auto it = m.rbegin(); it != m.rend(); it++) {
        if (it->second != 1)
            printf("%d %d\n", it->first, it->second);
    }
    return 0;
}
