#include <cstdio>
#include <vector>
#include <set>
#include <iterator>
#include <functional>
#include <map>
#include <queue>

using namespace std;

int *father;

void init_father(int n) {
    father = new int[n+1];
    for (int i = 0; i <= n; i++) father[i] = i;
}

int find_father(int x) {
    if (father[x] == x) return x;
    return find_father(father[x]);
}

void union_father(int arg1, int arg2) {
    int fa = find_father(arg1);
    int fb = find_father(arg2);
    father[fa] = fb;
}

int main() {
    int n = 0, ki = 0, hobby = 0;
    scanf("%d", &n);
    init_father(n);
    vector<set<int> > hobbies(n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &ki);
        for (int j = 0; j < ki; j++) {
            scanf("%d", &hobby);
            hobbies[i].insert(hobby);
            for (int k = 1; k < i; k++) {
                if (hobbies[k].find(hobby) != hobbies[k].end()) {
                    union_father(i, k);
                }
            }
        }
    }
    
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        m[find_father(i)]++;
    }
    printf("%ld\n", m.size());
    
    priority_queue<int, vector<int>, less<int>> q;
    for (auto it = m.begin(); it != m.end(); it++) {
        q.push(it->second);
    }
    while (q.size() > 1) {
        printf("%d ", q.top());
        q.pop();
    }
    printf("%d", q.top());
    return 0;
}
