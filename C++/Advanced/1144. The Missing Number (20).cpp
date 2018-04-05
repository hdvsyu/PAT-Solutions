#include <iostream>
#include <set>

int main() {
    int n = 0, t = 0, idx = 1;
    scanf("%d", &n);
    std::set<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > 0)  v.insert(t);
    }
    
    for (auto it = v.begin(); it != v.end(); it++, idx++) {
        if (*it != idx) break;
    }
    printf("%d", idx);
    return 0;
 }
