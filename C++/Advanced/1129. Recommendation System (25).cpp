#include <cstdio>
#include <set>
#include <vector>

using namespace std;

struct node {
    int item, cnt;
    node(int a, int b):item(a), cnt(b){}
    bool operator < (const struct node a) const {
        if (cnt > a.cnt) return true;
        if (cnt < a.cnt) return false;
        if (item < a.item) return true;
        return false;
    }
};

set<node> query;
vector<int> times(50010);

void printQuery(int k) {
    int i = 0;
    for (auto it = query.begin(); i < k && it != query.end(); it++, i++) {
        printf(" %d", it->item);
    }
    printf("\n");
}

int main() {
    int n = 0, k = 0, pre = 0, item = 0;;
    scanf("%d %d %d", &n, &k, &pre);
    for (int i = 1; i < n; i++) {
        scanf("%d", &item);
        printf("%d:", item);
        auto f = query.find(node(pre, times[pre]));
        if (f != query.end()) {
            query.erase(f);
        }
        times[pre]++;
        query.insert(node(pre, times[pre]));
        printQuery(k);
        pre = item;
    }
    return 0;
}
