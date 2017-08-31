#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct custmer {
    int st, lt; // service and lift time
};

vector<custmer> custmers;
vector<queue<int>> wins;

int popEarlyFormWins() {
    int early = 0;
    for (int i = 1; i < wins.size(); i++) {
        if (custmers[wins[i].front()].lt < custmers[wins[early].front()].lt) {
            early = i;
        }
    }
    
    wins[early].pop();
    return early;
}

int main() {
    int n = 0, m = 0, k = 0, q = 0;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    custmers.resize(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &custmers[i].st);
    }
    
    wins.resize(n);
    for (int i = 0; i < m * n && i < k; i++) {
        if (i < n) {
            custmers[i].lt = custmers[i].st;
        } else {
            int index = wins[i % n].back();
            custmers[i].lt = custmers[index].lt + custmers[i].st;
        }
        wins[i % n].push(i);
    }
    
    for (int i = m * n; i < k; i++) {
        int early = popEarlyFormWins();
        int index = wins[early].back();
        custmers[i].lt = custmers[index].lt + custmers[i].st;
        wins[early].push(i);
    }
    
    int index = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d", &index);
        if (custmers[index - 1].lt - custmers[index - 1].st >= 540) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", custmers[index - 1].lt / 60 + 8, custmers[index - 1].lt % 60);
        }
    }
    
    return 0;
}
