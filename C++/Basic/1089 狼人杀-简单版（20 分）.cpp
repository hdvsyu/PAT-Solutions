#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) { // two wolfware
            vector<int> sign(n+1, 1), lier;
            sign[i] = sign[j] = -1;
            for (int k = 1; k <= n; k++) {
                if (sign[abs(v[k])] * v[k] < 0) { // sb lie
                    lier.push_back(k);
                }
            }
            if (lier.size() == 2 && sign[lier[0]] * sign[lier[1]] < 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
