#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int cmp(const void *a, const void *b) {
    int arg1 = *static_cast<const int*>(a);
    int arg2 = *static_cast<const int*>(b);
    
    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *array = new int[n];
    int *sorted = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sorted[i] = array[i];
    }
    
    
    qsort(sorted, n, sizeof(int), cmp);
    vector<int> v;
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        
        if (sorted[i] == array[i] && sorted[i] == max) {
            v.push_back(array[i]);
        }
    }
    
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            cout << v[0];
        } else {
            cout << " " << v[i];
            
        }
    }
    cout << endl;
    return 0;
}