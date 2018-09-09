#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>


using namespace std;

int father[100010];

void init_father() {
    for (int i = 0; i < 100010; i++) {
        father[i] = i;
    }
}

int find_father(int x) {
    while (father[x] != x) {
        x = father[x];
    }
    return x;
}

void union_father(int a, int b) {
    int a_father = find_father(a), b_father = find_father(b);
    father[a_father] = b_father;
}

bool is_cluster(vector<set<int>> v, int g[], int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
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
