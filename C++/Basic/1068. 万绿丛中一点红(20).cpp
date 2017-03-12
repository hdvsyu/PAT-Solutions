#include <cstdio>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int> > pic;

bool isGreatThanTOL(int a, int b, int tol) {
    if (fabs(pic[a][b] - pic[a - 1][b])     <= tol) return false;
    if (fabs(pic[a][b] - pic[a - 1][b + 1]) <= tol) return false;
    if (fabs(pic[a][b] - pic[a - 1][b - 1]) <= tol) return false;
    if (fabs(pic[a][b] - pic[a][b + 1])     <= tol) return false;
    if (fabs(pic[a][b] - pic[a][b - 1])     <= tol) return false;
    if (fabs(pic[a][b] - pic[a + 1][b + 1]) <= tol) return false;
    if (fabs(pic[a][b] - pic[a + 1][b])     <= tol) return false;
    if (fabs(pic[a][b] - pic[a + 1][b - 1]) <= tol) return false;
    return true;
}

int main() {
    int m = 0, n = 0, tol = 0;
    scanf("%d %d %d", &m, &n, &tol);
    
    pic.resize(n + 2);
    for (int i = 0; i < n + 2; i++) {
        pic[i].resize(m + 2);
    }
    
    map<int, int> unique;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &pic[i][j]);
            unique[pic[i][j]]++;
        }
    }
    
    int a = 0, b = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (unique[pic[i][j]] == 1 && isGreatThanTOL(i, j, tol)) {
                cnt++;
                a = i;
                b = j;
            }
        }
    }
    
    if (cnt == 0) {
        printf("Not Exist\n");
    } else if (cnt == 1) {
        printf("(%d, %d): %d\n", b, a, pic[a][b]);
    } else {
        printf("Not Unique\n");
    }
    return 0;
}
