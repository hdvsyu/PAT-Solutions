#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main () {
    int n = 0, sum = 0;
    scanf("%d", &n);
    int *dis = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        int t = 0;
        scanf("%d", &t);
        dis[i] = dis[i - 1] + t;
        sum += t;
    }
    int m = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        int t = dis[b - 1] - dis[a - 1];
        printf("%d\n", min(t, sum - t));
    }
    delete [] dis;
    return 0;
}