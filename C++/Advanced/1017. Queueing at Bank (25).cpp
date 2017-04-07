#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

struct node {
    int time, p;
};

bool cmp(struct node a, struct node b) {
    return a.time < b.time;
}

int main() {
    int n = 0, k = 0, cnt = 0, waiting = 0;
    scanf("%d %d", &n, &k);
    struct node *arr = new struct node [n];
    for (int i = 0; i < n; i++) {
        int hour = 0, minute = 0, second = 0;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &arr[i].p);
        arr[i].time = hour * 3600 + minute * 60 + second;
        arr[i].p *= 60;
    }
    sort(arr, arr + n, cmp);
    
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++) {
        if (arr[i].time > 17 * 3600) {
            break;
        } else {
            cnt++;
            if (q.size() < k) {
                if (arr[i].time < 8 * 3600) {
                    waiting += 8 * 3600 - arr[i].time;
                    arr[i].time = 8 * 3600;
                }
                q.push(arr[i].time + arr[i].p);
            } else {
                int temp = q.top();
                q.pop();
                if (arr[i].time < temp) {
                    waiting += temp - arr[i].time;
                    q.push(temp + arr[i].p);
                } else {
                    q.push(arr[i].time + arr[i].p);
                }
            }
        }
    }
    printf("%.1f", waiting * 1.0 / cnt / 60);
    delete [] arr;
    return 0;
}
