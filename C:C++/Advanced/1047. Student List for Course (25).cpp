#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp (char *a, char *b) {
    for (int i = 0; i < 5; i++) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    return true;
}

int main () {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    vector<vector<char *> > v(k+1);
    for (int i = 0; i < n; i++) {
        char *name = new char[5];
        int c = 0;
        scanf("%s %d", name, &c);
        for (int j = 0; j < c; j++) {
            int a = 0;
            scanf("%d", &a);
            v[a].push_back(name);
        }
    }
    
    for (int i = 1; i <= k; i++) {
        printf("%d %lu\n", i, v[i].size());
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); j++) {
            printf("%s\n", v[i][j]);
        }
    }
    return 0;
}
