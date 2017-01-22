#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int getFather (int *father, int x) {
    if (father[x] == x) return x;
    return getFather(father, father[x]);
}

int main () {
    int n = 0;
    scanf("%d", &n);
    vector<vector<int> > hobbies(1001);
    for (int i = 1; i <= n; i++) {
        int k = 0;
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            int t = 0;
            scanf("%d", &t);
            hobbies[t].push_back(i);
        }
    }
    
    int *father = new int[n + 1];
    for (int i = 0; i <= n; i++) father[i] = i;
    for (int i = 1; i <= 1000; i++) {
        if (hobbies[i].size() != 0) {
            int v = getFather(father, hobbies[i][0]);
            for (int j = 1; j < hobbies[i].size(); j++) {
                int u = getFather(father, father[hobbies[i][j]]);
                if (v != u) father[u] = v;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        father[i] = getFather(father, i);
    }
    
    int *cluster = new int[n + 1];
    fill(cluster, cluster + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cluster[father[i]]++;
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (cluster[i] > 0) ans.push_back(cluster[i]);
    }
    sort(ans.begin(), ans.end());
    
    printf("%ld\n", ans.size());
    for (auto i = ans.rbegin(); i != ans.rend(); i++) {
        if (i != ans.rbegin()) printf(" ");
        printf("%d", *i);
        
    }
    delete [] cluster;
    delete [] father;
    return 0;
}
