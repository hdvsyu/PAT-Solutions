#include <cstdio>
#include <cstdlib>
#include <vector>

struct node {
    int key, next;
}nodes[100000];

void print(std::vector<int> list) {
    if (list.size() == 0) return;
    for (int i = 0; i < list.size() - 1; i++) {
        printf("%05d %d %05d\n", list[i], nodes[list[i]].key, list[i+1]);
    }
    printf("%05d %d -1\n", list[list.size() - 1], nodes[list[list.size() - 1]].key);
}

int main() {
    int first = 0, n = 0, temp = 0, visit[100000] = {0};
    scanf("%d %d", &first, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        scanf("%d %d", &nodes[temp].key, &nodes[temp].next);
    }
    
    std::vector<int> dup, reg;
    while (first != -1) {
        if (visit[abs(nodes[first].key)]) {
            dup.push_back(first);
        } else {
            visit[abs(nodes[first].key)] = 1;
            reg.push_back(first);
        }
        first = nodes[first].next;
    }
    print(reg);
    print(dup);
    return 0;
}
