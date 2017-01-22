#include <cstdio>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

double getSamilarity (const set<int> &a, const set<int> &b) {
    int cnt = 0, n = a.size() + b.size();
    set<int>::iterator i = a.begin(), j = b.begin();
    while (i != a.end() && j != b.end()) {
        if (*i == *j) {
            i++;
            j++;
            cnt++;
            n--;
        } else if (*i < *j) {
            i++;
        } else { // *i > *j
            j++;
        }
    }
    return cnt * 100.0 / n;
}

int main () {
    int n = 0;
    scanf("%d", &n);
    vector<set<int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        int m = 0, t = 0;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            v[i].insert(t);
        }
    }
    int k = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        printf("%.1f%%\n", getSamilarity(v[a], v[b]));
    }
    return 0;
}
