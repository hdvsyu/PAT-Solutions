#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct Node {
    int key, address, next;
};

int main() {
    int n = 0, head = 0, m = 0;
    cin >> n >> head;
    vector<struct Node> v(100000);
    for (int i = 0; i < n; i++) {
        struct Node t;
        cin >> t.address >> t.key >> t.next;
        v[t.address] = t;
    }
    struct Node *nodes = new struct Node[n];
    for (int i = 0; head != -1; i++) {
        nodes[m++] = v[head];
        head = v[head].next;
    }
    
    qsort(nodes, m, sizeof(nodes[0]), [](const void *a, const void *b){
        const struct Node arg1 = *static_cast<const struct Node *>(a);
        const struct Node arg2 = *static_cast<const struct Node *>(b);
        
        if (arg1.key > arg2.key) return 1;
        return -1;
    });
    
    if (m != 0) {
        printf("%d %05d\n", m, nodes[0].address);
        for (int i = 0; i < m; i++) {
            if (i != m - 1)
                printf("%05d %d %05d\n", nodes[i].address, nodes[i].key, nodes[i + 1].address);
            else
                printf("%05d %d -1\n", nodes[i].address, nodes[i].key);
            
        }
    } else {
        cout << 0 << " -1";
    }
    delete [] nodes;
    return 0;
}
