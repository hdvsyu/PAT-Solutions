#include <cstdio>

bool havePositive(int *nums, int k) {
    for (int i = 0; i < k; i++) {
        if (nums[i] >= 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int k = 0;
    scanf("%d", &k);
    int sum = -1, current = 0, currentI = 0, indexI = 0, indexJ = 0;
    int *nums = new int[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &nums[i]);
        current += nums[i];
        if (current > sum) {
            sum = current;
            indexI = currentI;
            indexJ = i;
        } else if (current < 0){
            current = 0;
            currentI = i + 1;
        }
    }
    if (havePositive(nums, k)) {
        printf("%d %d %d\n", sum, nums[indexI], nums[indexJ]);
    } else {
        printf("0 %d %d\n", nums[0], nums[k - 1]);
    }
    delete [] nums;
    return 0;
}
