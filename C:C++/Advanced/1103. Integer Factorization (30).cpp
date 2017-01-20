#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector<int> fac, final_path, path;
int maxFacSum = -1;

void init(int n, int p) {
    int i = 1, temp = 0;
    while (temp <= n) {
        fac.push_back(temp);
        temp = pow(i, p);
        i++;
    }
}

void dfs (int cur, int k, int n, int facSum) {
    if (k == 0 && n == 0) {
        if (maxFacSum < facSum) {
            maxFacSum = facSum;
            final_path = path;
        }
        return;
    }
    if (k < 0 || n < 0) return;
    
    if (cur >= 1) {
        path.push_back(cur);
        dfs(cur, k - 1, n - fac[cur], facSum + cur);
        path.pop_back();
        dfs(cur - 1, k, n, facSum);
    }
}

int main() {
    int k = 0, n = 0, p = 0;
    scanf("%d %d %d", &n, &k, &p);
    init(n, p);
    dfs(fac.size() - 1, k, n, 0);
    if (maxFacSum == -1) printf("Impossible");
    else {
        printf("%d = %d^%d", n, final_path[0], p);
        for (int i = 1; i < final_path.size(); i++) {
            printf(" + %d^%d", final_path[i], p);
        }
    }
    return 0;
}