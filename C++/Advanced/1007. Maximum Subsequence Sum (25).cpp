#include <cstdio>

int main() {
    int k = 0, sum = -1, tsum = 0, start = 0, tstart = 0, end = 0, all_neg = 1;
    scanf("%d", &k);
    int *num = new int[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &num[i]);
        if (num[i] >= 0) all_neg = 0;
        tsum += num[i];
        if (tsum < 0) {
            tsum = 0;
            tstart = i+1;
        } else if (tsum > sum) {
            sum = tsum;
            end = i;
            start = tstart;
        }
    }
    if (all_neg) printf("0 %d %d", num[0], num[k-1]);
    else printf("%d %d %d", sum, num[start], num[end]);
    return 0;
}
