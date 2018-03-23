#include <cstdio>
#include <set>

int main() {
    int n = 0, t = 0;
    scanf("%d", &n);
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (s.size() > 0 && t < *s.rbegin())
            s.erase(*s.upper_bound(t));
        s.insert(t);
    }
    printf("%lu", s.size());
    return 0;
}
