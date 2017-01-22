#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100001;
int c[N];

int lowbit (int pos) {
    return pos & (-pos);
}

void add (int pos, int val) {
    while (pos < N) {
        c[pos] += val;
        pos += lowbit(pos);
    }
}

int getSum (int pos) {
    int result = 0;
    while (pos > 0) {
        result += c[pos];
        pos -= lowbit(pos);
    }
    return result;
}

int findMid (int pos) {
    int low = 0, high = N, mid = (low + high) >> 1;;
    while(high - 1 > low) {
        mid = (low + high) >> 1;
        int t = getSum(mid);
        if(t < pos) low = mid;
        else high = mid;
    }
    return low + 1;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        char *s = (char *) malloc(10 * sizeof(char));
        scanf("%s", s);
        if (strcmp(s, "Pop") == 0) {
            if (v.size() == 0) {
                printf("Invalid\n");
            } else {
                cout << v.back() << endl;
                add(v.back(), -1);
                v.pop_back();
            }
        } else if (strcmp(s, "PeekMedian") == 0) {
            if (v.size() == 0) {
                printf("Invalid\n");
            } else {
                printf("%d\n", findMid(v.size() % 2 == 0 ? (int)v.size() / 2 : ((int)v.size() + 1) / 2));
            }
        } else { // s == "Push"
            int key = 0;
            scanf("%d", &key);
            v.push_back(key);
            add(key, 1);
        }
    }
    return 0;
}
