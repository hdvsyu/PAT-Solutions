#include <cstdlib>
#include <cstdio>

int get (int *nums, double x, int l, int r) {
    int mid = (l + r) / 2;
    if (l >= r) return mid;
    if (nums[mid] < x) return get(nums, x, mid + 1, r);
    if (nums[mid] - x < 0.1) return mid;
    else return get(nums, x, l, mid);
}

int cmp (const void *a, const void *b) {
    int arg1 = *static_cast<const int *>(a);
    int arg2 = * static_cast<const int *>(b);
    
    if (arg1 > arg2) return 1;
    if (arg1 < arg2) return -1;
    return 0;
}

int main () {
    int n = 0, p = 0;
    scanf("%d %d", &n, &p);
    int *nums = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, n, sizeof(nums[0]), cmp);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        int j = get(nums, nums[i] * 1.0 / p, 0, i);
        cnt = i - j + 1 > cnt ? i - j + 1 : cnt;
    }
    printf("%d\n", cnt);
    delete [] nums;
    return 0;
}