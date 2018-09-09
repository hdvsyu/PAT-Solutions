#include <cstdio>
#include <set>

int main() {
    int n = 0;
    scanf("%d", &n);
    std::set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i / 2 + i / 3 + i / 5);
    }
    printf("%d", s.size());
    return 0;
}
