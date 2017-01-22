#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> prime;

void setPrime () {
    int *nums = new int[500000];
    memset(nums, 1, 500000);
    for (int i = 2; i * i < 500000; i++) {
        for (int j = 2; i * j < 500000; j++) {
            nums[i * j] = 0;
        }
    }
    for (int i = 2; i < 500000; i++) {
        if (nums[i]) {
            prime.push_back(i);
        }
    }
    delete [] nums;
}

int main() {
    setPrime();
    long num = 0;
    scanf("%ld", &num);
    printf("%ld=", num);
    if (num == 1) {
        printf("1");
    }
    bool state = false;
    for (int i = 0; num != 1; i++) {
        int cnt = 0;
        while (num != 1 && num % prime[i] == 0) {
            cnt++;
            num /= prime[i];
        }
        
        if (cnt >= 1) {
            if (state) {
                printf("*");
            }
            if (cnt == 1) {
                printf("%d", prime[i]);
            } else if (cnt > 1) {
                printf("%d^%d", prime[i], cnt);
            }
            state = true;
        }
    }
    return 0;
}
