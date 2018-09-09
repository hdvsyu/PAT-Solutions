#include <cstdio>
#include <vector>
#include <set>

using namespace std;

bool is_cluster(vector<set<int>> v, int g[], int k) {
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            if (i != j && v[g[i]].find(g[j]) != v[g[i]].end())
                return false;
        }
    }
    return true;
}

int main() {
    vector<set<int>> v(100010);
    int n = 0, m = 0, a = 0, b = 0, k = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v[a].insert(b);
        v[b].insert(a);
    }
    int g[1010];
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &g[j]);
        }
        printf("%s\n", is_cluster(v, g, k) ? "Yes" : "No");
    }
    return 0;
}
