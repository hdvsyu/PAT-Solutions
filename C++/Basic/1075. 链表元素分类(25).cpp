#include <cstdio>
#include <vector>

using namespace std;

struct node {
    int first, value, next;
};

vector<node> neg, lesser, greater;

void spit(node *nodes, int first, int k) {
    while (first != -1) {
        if (nodes[first].value < 0) {
            neg.push_back(nodes[first]);
        } else if (nodes[first].value <= k) {
            lesser.push_back(nodes[first]);
        } else {
            greater.push_back(nodes[first]);
        }
        first = nodes[first].next;
    }
}

vector<node> ans;
void merge() {
    ans = neg;
    for (int i = 0; i < lesser.size(); i++) {
        ans.push_back(lesser[i]);
    }
    for (int i = 0; i < greater.size(); i++) {
        ans.push_back(greater[i]);
    }
}

void printAns() {
    int i = 0;
    for (; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i].first, ans[i].value, ans[i+1].first);
    }
    printf("%05d %d -1\n", ans[i].first, ans[i].value);
}

int main() {
    int first = 0, n = 0, k = 0, temp = 0;
    scanf("%d %d %d", &first, &n, &k);
    node nodes[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        scanf("%d %d", &nodes[temp].value, &nodes[temp].next);
        nodes[temp].first = temp;
    }
    spit(nodes, first, k);
    merge();
    printAns();
    
    return 0;
}
