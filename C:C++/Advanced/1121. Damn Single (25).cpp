#include <cstdio>
#include <set>
#include <iterator>

using namespace std;

int main() {
    
    int n = 0;
    scanf("%d", &n);
    int *couple = new int[100000];
    int *isCoupleAttent = new int[100000];
    for (int i = 0; i < 100000; i++) {
        couple[i] = -1;
        isCoupleAttent[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        scanf("%d %dd", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    
    int m = 0;
    scanf("%d", &m);
    int *guest = new int[m];
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &guest[i]);
        if (couple[guest[i]] != -1) {
            isCoupleAttent[couple[guest[i]]] = 1;
        }
    }
    
    set<int> s;
    for (int i = 0; i < m; i++) {
        if (!isCoupleAttent[guest[i]]) {
            s.insert(guest[i]);
        }
    }
    
    printf("%d\n", s.size());
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) {
            printf(" ");
        }
        printf("%05d", *it);
    }
    delete [] isCoupleAttent;
    delete [] guest;
    delete [] couple;
    
}