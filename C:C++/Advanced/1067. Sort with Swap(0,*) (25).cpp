#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    scanf("%d", &n);
    int *pos = new int[n];
    int unsort = 0;
    for (int i = 0; i < n; i++) {
        int num  = 0;
        scanf("%d", &num);
        pos[num] = i;
        if (i != pos[i] && i != 0) unsort++;
    }
    int cnt = 0, k = 0;
    while (unsort > 0) {
        if (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            cnt++;
            unsort--;
        } else {
            while (k < n) {
                if (k != pos[k]) {
                    swap(pos[0], pos[k]);
                    cnt++;
                    break;
                }
                k++;
            }
        }
    }
    printf("%d\n", cnt);
    delete [] pos;
    return 0;
}
