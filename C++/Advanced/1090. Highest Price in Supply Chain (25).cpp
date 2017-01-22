#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

struct Node {
    int level;
    vector<int> child;
};

struct Node *v;

void getLevel (int root, int l) {
    if (v[root].child.size() == 0) return ;
    for (vector<int>::iterator i = v[root].child.begin(); i != v[root].child.end(); i++) {
        v[*i].level = l;
        getLevel(*i, l + 1);
    }
}

int main () {
    int n = 0;
    double p = 0, r = 0;
    scanf("%d %lf %lf", &n, &p, &r);
    v = new struct Node[n];
    int root = 0;
    for (int i = 0; i < n; i++) {
        int supplier = 0;
        scanf("%d", &supplier);
        if (supplier == -1) root = i;
        else v[supplier].child.push_back(i);
    }
    
    getLevel(root, 1);
    int l = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].level > l) {
            cnt = 1;
            l = v[i].level;
        } else if (v[i].level == l) {
            cnt++;
        }
    }
    
    printf("%.2f %d", p * pow(r / 100 + 1, l) , cnt);
    delete [] v;
    return 0;
}
