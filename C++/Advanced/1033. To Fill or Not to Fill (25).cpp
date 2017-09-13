#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct sta {
    double dis, price;
    sta(int d, double p) {
        dis = d;
        price = p;
    }
};

vector<struct sta> gas;

bool cmp(sta a, sta b) {
    return a.dis < b.dis;
}

int findLower(int cur, int cmax, int davg) {
    for (int i = cur + 1; i < gas.size() && gas[i].dis - gas[cur].dis <= cmax * davg; i++) {
        if (gas[cur].price >= gas[i].price) {
            return i;
        }
    }
    return -1;
}

int findMin(int cur, int cmax, int davg) {
    int inf = 999999, min = 0;
    for (int i = cur + 1; i < gas.size() && gas[i].dis - gas[cur].dis <= cmax * davg; i++) {
        if (gas[i].price < inf) {
            min = i;
            inf = gas[i].price;
        }
    }
    if (inf == 999999) return -1;
    else return min;
}

int main() {
    int n = 0, cur = 0;
    double cmax = 0, d = 0, davg = 0, p = 0, temp = 0, tank = 0, total = 0;
    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &p, &temp);
        if (temp == d) gas.push_back(sta(temp, 0));
        else gas.push_back(sta(temp, p));
    }
    
    sort(gas.begin(), gas.end(), cmp);
    
    if (gas[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    
    while (true) {
        int low = findLower(cur, cmax, davg);
        if (low == -1) {
            low = findMin(cur, cmax, davg);
            if (low == -1) {
                break;
            } else {
                total += (cmax - tank) * gas[cur].price;
                tank = cmax - (gas[low].dis - gas[cur].dis) * 1.0 / davg;
            }
        } else {
            if ((gas[low].dis - gas[cur].dis) * 1.0 / davg >= tank) {
                total += gas[cur].price * ((gas[low].dis - gas[cur].dis) * 1.0 / davg - tank);
                tank = 0;
            } else {
                tank -= (gas[low].dis - gas[cur].dis) * 1.0 / davg;
            }
        }
        cur = low;
    }
    
    if (gas[cur].dis + cmax * davg < d) {
        printf("The maximum travel distance = %.2f", gas[cur].dis + cmax * davg);
    } else {
        printf("%.2f", total + gas[cur].price * ((d - gas[cur].dis) * 1.0 / davg) - tank);
    }
    return 0;
}
