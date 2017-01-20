#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n >= 1) {
        int *nums = new int[n + 2];
        int *leftMax = new int[n + 2];
        int *rightMin = new int[n + 2];
        for (int i = 1; i <= n; i++) {
            scanf("%d", &nums[i]);
            leftMax[i] = -1;
            rightMin[i] = 2100000000;
        }
        for (int i = 0; i <= n + 1; i++) {
            leftMax[i] = i == 0 ? -1 : (leftMax[i - 1] > nums[i] ? leftMax[i - 1] : nums[i]);
            rightMin[n + 1 - i] = i == 0 ? 2100000000 : (rightMin[n + 2 - i] < nums[n - i + 1] ? rightMin[n + 2 - i] : nums[n - i + 1]);
        }
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (nums[i] >= leftMax[i - 1] && nums[i] <= rightMin[i + 1]) {
                v.push_back(nums[i]);
            }
        }
        
        printf("%lu\n", v.size());
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                printf("%d", v[0]);
            } else {
                printf(" %d", v[i]);
            }
        }
        printf("\n");
        delete [] rightMin;
        delete [] leftMax;
        delete [] nums;
    }
    return 0;
}
