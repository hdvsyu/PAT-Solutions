#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct test {
    string number;
    int score, locnum, locrnk, rnk;
};

bool cmp(const struct test &a, const struct test &b) {
    if (a.score > b.score) return true;
    if (a.score < b.score) return false;
    return a.number < b.number;
}

int main() {
    int n = 0;
    cin >> n;
    vector<struct test> v;
    for (int i = 1; i <= n; i++) {
        int k = 0;
        cin >> k;
        struct test *arr = new struct test[k];
        for (int j = 0; j < k; j++) {
            struct test t;
            cin >> t.number >> t.score;
            t.locnum = i;
            arr[j] = t;
        }
        qsort(arr, k, sizeof(arr[0]), [](const void *a, const void *b){
            const struct test arg1 = *static_cast<const struct test *>(a);
            const struct test arg2 = *static_cast<const struct test *>(b);
            
            if (arg1.score > arg2.score) return -1;
            if (arg1.score < arg2.score) return 1;
            return 0;
        });
        for (int j = 0; j < k; j++) {
            arr[j].locrnk = j > 0 && arr[j].score == arr[j - 1].score ?arr[j].locrnk = arr[j - 1].locrnk : j+1;
            v.push_back(arr[j]);
        }
        delete [] arr;
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        v[i].rnk = i > 0 && v[i].score == v[i - 1].score ? v[i].rnk = v[i - 1].rnk : i + 1;
        cout << v[i].number << " "<< v[i].rnk << " " << v[i].locnum << " " << v[i].locrnk << endl;
    }
    return 0;
}
