#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int main () {
    int n = 0, m = 0 ;
    scanf("%d %d", &n, &m);
    map<int, int> order;
    for (int i = 1; i <= m; i++) {
        int t = 0;
        scanf("%d", &t);
        order[t] = i;
    }
    int l = 0;
    scanf("%d", &l);
    int *stripes = new int [l];
    for (int i = 0; i < l; i++) {
        scanf("%d", &stripes[i]);
    }
    int *len = new int[l], i = 0;
//    int len[100], i = 0;
    memset(len, 0, sizeof(len[0]));
    map<int, int> maxLen;
    while (order[stripes[i]] == 0) i++;
    len[i] = 1;
    maxLen[stripes[i]]++;
    for (i += 1; i < l; i++) {
        for (auto it = order.begin(); order[stripes[i]] != 0 && it != order.end(); it++) {
            if (it->second <= order[stripes[i]]) {
                len[i] = max(maxLen[it->first] + 1, len[i]);
            }
        }
        maxLen[stripes[i]] = len[i];
    }
    printf("%d", len[l - 1]);
    delete [] len;
    delete [] stripes;
    return 0;
}