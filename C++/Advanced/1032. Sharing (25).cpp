#include <cstdio>
#include <vector>

using namespace std;

struct Node {
    int address, next;
    char data;
};

int main() {
    int add1 = -1, add2 = -1, n = 0;
    scanf("%d %d %d", &add1, &add2, &n);
    struct Node *nodes = new struct Node[100000];
    for (int i = 0; i < n; i++) {
        struct Node t;
        scanf("%d %c %d", &t.address, &t.data, &t.next);
        nodes[t.address] = t;
    }
    
    struct Node *list = new struct Node[100000];
    while (add1 != -1) {
        list[nodes[add1].address] = nodes[add1];
        add1 = nodes[add1].next;
    }

    bool haveCommon = false;
    while (add2 != -1) {
        if (list[nodes[add2].address].data != '\0') {
            haveCommon = true;
            break;
        }
        add2 = nodes[add2].next;
    }
    
    if (haveCommon) {
        printf("%05d\n", list[nodes[add2].address].address);
    } else {
        printf("-1\n");
    }
    delete [] list;
    delete [] nodes;
    return 0;
}
