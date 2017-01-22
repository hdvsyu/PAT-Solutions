#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int len = 27 * 27 * 27;

vector<vector<int> > net(len);
int times[len], isVisited[len];

struct Gang {
    int index, cnt;
    Gang(int m_index, int m_cnt) {
        index = m_index; cnt = m_cnt;
    }
};

bool cmp (struct Gang a, struct Gang b) {
    return a.index < b.index;
}

int getIndex (char *name) {
    int index = 0;
    for (int i = 0; i < 3; i++) {
        index = index * 26 + name[i] - 'A';
    }
    return index;
}

void printName (int index) {
    printf("%c", index / (26 * 26) + 'A');
    printf("%c", index % (26 * 26) / 26 + 'A');
    printf("%c", index % 26 + 'A');
}

void dfs (int &cnt, int cur, int &head, int &total) {
    for (auto it = net[cur].begin(); it != net[cur].end(); it++) {
        if (!isVisited[*it]) {
            isVisited[*it] = 1;
            if (times[head] < times[*it]) head = *it;
            cnt++;
            total += times[*it];
            dfs(cnt, *it, head, total);
        }
    }
}

int main () {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        char name1[4], name2[4];
        int time = 0;
        scanf("%s %s %d", name1, name2, &time);
        int index1 = getIndex(name1), index2 = getIndex(name2);
        net[index1].push_back(index2);
        net[index2].push_back(index1);
        times[index1] += time;
        times[index2] += time;
    }
    
    vector<struct Gang> ans;
    for (int i = 0; i < len; i++) {
        int cnt = 1, head = i, total = times[i];;
        if (!isVisited[i] && net[i].size() != 0) {
            isVisited[i] = 1;
            dfs(cnt, i, head, total);
        }
        if (cnt > 2 && total > 2 * k) {
            struct Gang g(head, cnt);
            ans.push_back(g);
        }
    }
    printf("%lu\n", ans.size());
    sort(ans.begin(), ans.end(), cmp);
    for (auto it = ans.begin(); it != ans.end(); it++) {
        printName(it->index);
        printf(" %d\n", it->cnt);
    }
    return 0;
}