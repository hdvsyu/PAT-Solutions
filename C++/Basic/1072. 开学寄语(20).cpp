#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, m = 0, temp = 0, k = 0, snum = 0, fnum = 0; // snm is student num, fum is forbid num
    scanf("%d %d", &n, &m);
    bool *forbid = new bool[10000];
    fill(forbid, forbid + 10000, false);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        forbid[temp] = true;
    }
    for (int i = 0; i < n; i++) {
        char name[10];
        bool flag = false; // is print name?
        scanf("%s %d", name, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            if (forbid[temp]) {
                if (!flag) {
                    printf("%s:", name);
                    flag = true;
                }
                printf(" %04d", temp);
                fnum++;
            }
        }
        if (flag) {
            printf("\n");
            snum++;
        }
    }
    printf("%d %d\n", snum, fnum);
    return 0;
}
