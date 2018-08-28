#include <cstdio>
#include <set>
#include <vector>

using namespace std;

vector<set<int>> vs(1010);

bool is_topological(int *query, int n) {
    int *in = new int[n+1];
    for (int i = 1; i <= n; i++) {
        in[i] = vs[i].size();
    }
    
    for (int i = 0; i < n; i++) {
        if (in[query[i]] != 0) return false;
        for (int j = 1; j <= n; j++) {
            if (vs[j].find(query[i]) != vs[j].end()) {
                in[j]--;
            }
        }
    }
    return true;
}

int main() {
    int n = 0, m = 0, start = 0, end = 0, k = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &start, &end);
        vs[end].insert(start);
    }
    scanf("%d", &k);
    vector<int> ans;
    for (int i = 0; i < k ; i++) {
        int *query = new int[n+1];
        for (int j = 0; j < n; j++) {
            scanf("%d", &query[j]);
        }
        if (!is_topological(query, n)) {
            ans.push_back(i);
        }
        delete [] query;
    }
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}
