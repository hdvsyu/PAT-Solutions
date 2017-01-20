#include <stack>
#include <cstdio>

using namespace std;

int main() {
    int m = 0, n = 0, k = 0;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        int *nums = new int[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &nums[j]);
        }
        
        int max = n;
        stack<int> s;
        bool state = true;
        for (int j = n - 1; j >= 0; j--) {
            if (max == nums[j]) {
                max--;
                while (s.size() != 0 && s.top() == max) {
                    max--;
                    s.pop();
                }
            } else {
                s.push(nums[j]);
                if (j != n - 1 && s.size() == m) {
                    state = false;
                }
            }
        }
        printf("%s\n", state && s.size() == 0 ? "YES" : "NO");
        delete [] nums;
    }
    return 0;
}
