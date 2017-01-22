#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int getIndex(char *s) {
    return 26 * 26 * 10 * (s[0] - 'A') + 26 * 10 * (s[1] - 'A') + 10 * (s[2] - 'A') + (s[3] - '0');
}

int main() {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    vector<set<int> > v(26 * 26 * 26 * 10 + 1);
    for (int i = 0; i < k; i++) {
        int index = 0, N = 0;
        scanf("%d %d", &index, &N);
        for (int j = 0; j < N; j++) {
            char s[5];
            scanf("%s", s);
            v[getIndex(s)].insert(index);
        }
    }
    for (int i = 0; i < n; i++) {
        char str[5];
        scanf("%s", str);
        set<int> s = v[getIndex(str)];
        printf("%s %lu", str, s.size());
        for (set<int>::iterator j = s.begin(); j != s.end(); j++) {
            printf(" %d", *j);
        }
        printf("\n");
    }
    return 0;
}
