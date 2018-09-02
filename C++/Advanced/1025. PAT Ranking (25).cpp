#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

struct testee {
    char number[15];
    int score, locnum, locrnk;
};

bool cmp(testee a, testee b) {
    if (a.score > b.score) return true;
    if (a.score < b.score) return false;
    return strcmp(a.number, b.number) < 0 ;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<struct testee> v;
    for (int i = 1; i <= n; i++) {
        int k = 0;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            struct testee t;
            scanf("%s %d", t.number, &t.score);
            t.locnum = i;
            v.push_back(t);
        }
        sort(v.end() - k , v.end(), cmp);
        v[v.size() - k].locrnk = 1;
        int rank = 2;
        for (int j = (int)v.size() - k + 1; j < v.size(); j++) {
            if (v[j].score == v[j-1].score) v[j].locrnk = v[j-1].locrnk;
            else v[j].locrnk = rank;
            rank++;
        }
    }
    sort(v.begin(), v.end(), cmp);
    printf("%lu\n", v.size());
    int rank = 1;
    for (int i = 0; i < v.size(); i++) {
        if (i > 0 && v[i].score != v[i - 1].score) rank = i+1;
        printf("%s %d %d %d\n", v[i].number, rank, v[i].locnum, v[i].locrnk);
    }
    return 0;
}
