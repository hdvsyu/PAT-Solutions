#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int *nums = new int[10001];
    int n = 0;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t = 0;
        scanf("%d", &t);
        nums[t]++;
        v.push_back(t);
        
    }
    
    bool state = false;
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        if (nums[v[i]] == 1) {
            state = true;
            result = v[i];
            break;
        }
    }
    if (state) {
        printf("%d", result);
    } else {
        printf("None");
    }
    delete [] nums;
    return 0;
}
