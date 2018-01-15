#include <cstdio>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct node {
    string id;
    int gp, gm, gf, g;
};

map<string, int> kv;
node *students;

int main() {
    int p = 0, m = 0, n = 0, index = 0, tnum = 0;
    scanf("%d %d %d", &p, &m, &n);
    students = new node[10010];
    char tid[21];
    for (int i = 0; i < p; i++) {
        scanf("%s %d", tid, &tnum);
        index++;
        kv[tid] = index;
        students[index].id = tid;
        students[index].gp = tnum;
        students[index].gf = students[index].gm = -1;
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%s %d", tid, &tnum);
        if (kv[tid] != 0) {
            students[kv[tid]].gm = tnum;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s %d", tid, &tnum);
        if (kv[tid] != 0) {
            students[kv[tid]].gf = tnum;
        }
    }
    
    auto cmp = [](node a, node b) { return a.g != b.g ? a.g < b.g : a.id > b.id; };
    priority_queue<node, vector<node>, decltype(cmp)> q(cmp);
    for (int i = 1; i <= index; i++) {
        if (students[i].gm > students[i].gf)
            students[i].g = (int)(0.4 * students[i].gm + 0.6 * students[i].gf + 0.5);
        else
            students[i].g = students[i].gf;
        
        if (students[i].gp >= 200 && students[i].g >= 60) {
            q.push(students[i]);
        }
    }
    
    while (!q.empty()) {
        printf("%s %d %d %d %d\n", q.top().id.c_str(), q.top().gp, q.top().gm, q.top().gf, q.top().g);
        q.pop();
    }

    return 0;
}
