#include <cstdio>
#include <map>

using namespace std;

int main() {
    int m = 0, n = 0;
    map<int, int> matrix;
    scanf("%d %d", &m,&n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int bits = 0;
            scanf("%d", &bits);
            matrix[bits]++;
        }
    }
    for (map<int, int>::iterator j = matrix.begin(); j != matrix.end(); j++) {
        if (j->second > m * n / 2) {
            printf("%d", j->first);
        }
    }
    return 0;
}
