#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n = 0, m = 0, t = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int g2 = 0;
        scanf("%d", &g2);
        priority_queue<int> q;
        for (int j = 0; j < n-1; j++) {
            scanf("%d", &t);
            if (t >= 0 && t <= m) q.push(t);
        }
        q.pop(); // min
        int g1 = 0, div = q.size() - 1;
        while (q.size() > 1) {
            g1 += q.top();
            q.pop();
        }
        printf("%d\n", (int)((g1 * 1.0 / div + g2) / 2.0 + 0.5));
    }
    return 0;
}
