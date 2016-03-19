#include <iostream>
#include <algorithm>
using namespace std;
struct People {
    string name;
    int high;
};

bool cmp(People p1, People p2) {
    if (p1.high < p2.high) {
        return true;
    } else if (p1.high > p2.high) {
        return false;
    } else {
        return p1.name > p2.name;
    }
}

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    struct People *peoples = new struct People [n];
    for (int i = 0; i < n; i++) {
        cin >> peoples[i].name >> peoples[i].high;
    }
    
    sort(peoples, peoples + n, cmp);
    
    int per = n / k;
    for (int i = k; i >= 1; i--) {
        int len = 0;
        int index = 0;
        if (i == k) {
            len = n - k * per + per;
            index = n-1;
        } else {
            len = per;
            index = i * per - 1;
        }
        
        People *temp = new People[len];
        int left = len / 2;
        int right = len / 2;
        temp[left] = peoples[index--];
        left--;
        right++;
        while (left >= 0 && right < len) {
            temp[left--] = peoples[index--];
            temp[right++] = peoples[index--];
        }
        
        if (left >= 0) {
            temp[left] = peoples[index];
        } else if (right < len) {
            temp[right] = peoples[index];
        }
        
        for (int j = 0; j < len - 1; j++) {
            cout << temp[j].name << " ";
        }
        cout << temp[len - 1].name<< endl;;
    }
    
    delete [] peoples;
    return 0;
}


