#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
    char plate[8];
    int time, status;
};

int cmpByName(const void *a, const void *b) {
    struct node ai = *static_cast<const struct node*>(a);
    struct node bi = *static_cast<const struct node*>(b);
    int res = strcmp(ai.plate, bi.plate);
    return res == 0 ? (ai.time - bi.time) : (res < 0 ? -1 : 1);
}

bool cmpByTime(struct node a, struct node b) {
    if (a.time == b.time) return strcmp(a.plate, b.plate) < 0;
    return a.time < b.time;
}

vector<struct node> car;
int query(int &startIndex, int time, int cnt) {
    for (int i = startIndex; i < car.size(); i++) {
        if (car[i].time <= time) {
            if (car[i].status == 1) {
                cnt++;
            } else if (car[i].status == 0) {
                cnt--;
            }
        } else {
            startIndex = i;
            break;
        }
    }
    return cnt;
}

int main() {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    struct node *input = new struct node[n];
    for (int i = 0; i < n; i++) {
        char temp[4];
        int hour, minute, second;
        scanf("%s %d:%d:%d %s", input[i].plate, &hour, &minute, &second, temp);
        input[i].time = hour * 3600 + minute * 60 + second;
        strcmp(temp, "in") == 0 ? input[i].status = 1 : input[i].status = 0;
    }
    qsort(input, n, sizeof(*input), cmpByName);
    
    map<string, int> parkTime;
    int longestTime = 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(input[i - 1].plate, input[i].plate) == 0 &&
            input[i - 1].status == 1 && input[i].status == 0) {
            car.push_back(input[i - 1]);
            car.push_back(input[i]);
            parkTime[input[i].plate] += input[i].time - input[i - 1].time;
            if (longestTime < parkTime[input[i].plate]) {
                longestTime = parkTime[input[i].plate];
            }
        }
    }
    sort(car.begin(), car.end(), cmpByTime);
    
    int cnt = 0, startIndex = 0;
    for (int i = 0; i < k; i++) {
        int hour = 0, minute = 0, second = 0;
        scanf("%d:%d:%d", &hour, &minute, &second);
        int time = hour * 3600 + minute * 60 + second;
        cnt = query(startIndex, time, cnt);
        printf("%d\n", cnt);
    }
    
    for (auto it : parkTime) {
        if (it.second == longestTime) {
            printf("%s ", it.first.c_str());
        }
    }
    printf("%02d:%02d:%02d", longestTime / 3600, longestTime % 3600 / 60, longestTime % 60);
    return 0;
}
