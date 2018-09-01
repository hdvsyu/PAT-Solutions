#include <cstdio>
#include <vector>

int main () {
    int n = 0, b = 0;
    scanf("%d %d", &n, &b);
    std::vector<int> v;
    do {
        v.push_back(n % b);
        n /= b;
    } while (n != 0);
    bool equal = true;
    for (int i = 0; i < v.size() / 2; i++) {
        if (v[i] != v[v.size() - i - 1]) {
            equal = false;
        }
    }
    printf("%s\n", equal ? "Yes" : "No");
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        if (it == v.rbegin()) printf("%d", *it);
        else printf(" %d", *it);
    }
    return 0;
}
