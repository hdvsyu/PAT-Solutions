#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct node {
    char name[22], status[10];
    int month, time, day, hour, minute;
};

int cmp(const void *a, const void *b) {
    struct node an = *static_cast<const struct node *>(a);
    struct node bn = *static_cast<const struct node *>(b);
    int res = strcmp(an.name, bn.name);
    return res != 0 ? res : an.time - bn.time;
}

double billFromZero(struct node call, int *rate) {
    double total = rate[call.hour] * call.minute;
    for (int i = 0; i < call.hour; i++) {
        total += rate[i] * 60;
    }
    total += rate[24] * 60 * call.day;
    return total / 100.0;
}

int main() {
    int rate[25] = {0};
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    int n = 0;
    scanf("%d", &n);
    struct node *data = new struct node [n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d:%d %s", data[i].name,
              &data[i].month, &data[i].day, &data[i].hour, &data[i].minute, data[i].status);
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }
    qsort(data, n, sizeof(data[0]), cmp);
    
    map<string, vector<struct node> > custom;
    for (int i = 1; i < n; i++) {
        if (strcmp(data[i].name, data[i - 1].name) == 0 &&
            strcmp(data[i - 1].status, "on-line") == 0 &&
            strcmp(data[i].status, "off-line") == 0) {
            custom[data[i - 1].name].push_back(data[i - 1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
    
    for (auto it : custom) {
        vector<struct node> temp = it.second;
        printf("%s %02d\n", it.first.c_str(), temp[0].month);
        double total = 0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                   temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute,
                   temp[i].day, temp[i].hour, temp[i].minute,
                   temp[i].time - temp[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    delete [] data;
    return 0;
}
