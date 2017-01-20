#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int address, data, next;
};

int main() {
    int head = 0, n = 0, k = 0;
    scanf("%d %d %d", &head, &n, &k);
    vector<struct Node> v(100000);
    for (int i = 0; i < n; i++) {
        struct Node node;
        scanf("%d %d %d", &node.address, &node.data, &node.next);
        v[node.address] = node;
    }
    
    vector<struct Node> nodes;
    for (int i = 0; head != -1; i++) {
        nodes.push_back(v[head]);
        head = v[head].next;
    }
    
    k = k > nodes.size() ? k % nodes.size() : k;
    for (int i = 0; i <= nodes.size() - k; i += k) {
        reverse(nodes.begin() + i, nodes.begin() + i + k);
    }
    
    for (int i = 0; i < nodes.size(); i++) {
        if (i != nodes.size() - 1) {
            printf("%05d %d %05d\n", nodes[i].address, nodes[i].data, nodes[i + 1].address);
        } else {
            printf("%05d %d -1\n", nodes[i].address, nodes[i].data);
        }
    }
    return 0;
}
