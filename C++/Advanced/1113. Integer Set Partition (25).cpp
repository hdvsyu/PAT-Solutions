#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int cmp(const void* a, const void* b) {
    int arg1 = *static_cast<const int*>(a);
    int arg2 = *static_cast<const int*>(b);
    
    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *nums = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, n, sizeof *nums, cmp);
    
    int s2 = 0, s1 = 0;
    if (n % 2 == 0) {
        printf("0 ");
    } else {
        printf("1 ");
        s2 = nums[n / 2];
    }
    
    for (int i = 0; i < n / 2; i++) {
        s1 += nums[i];
        s2 += nums[n - i - 1];
    }
    printf("%d", s2 - s1);
    
    delete [] nums;
    return 0;
}
