#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node {
    int address;
    int data;
    int next;
    
};

vector<struct Node> v(100000);
vector<struct Node> a;

void link(int firstAddress) {
    while (firstAddress != -1) {
        a.push_back(v[firstAddress]);
        firstAddress = v[firstAddress].next;
    }
}

void rev(int k) {
    for (int i = 0; i + k <= a.size(); i += k) {
        reverse(a.begin() + i, a.begin() + i + k);
    }
}

int main() {
    int firstAddress = 0, n = 0, k = 0;
    scanf("%d %d %d", &firstAddress, &n, &k);

    for (int i = 0; i < n; i++) {
        struct Node temp;
        scanf("%d %d %d", &temp.address, &temp.data, &temp.next);
        v[temp.address] = temp;
    }
    
    link(firstAddress);
    rev(k);
    
    for (int i = 0; i < a.size() - 1; i++) {
        printf("%05d %d %05d\n", a[i].address, a[i].data, a[i+1].address);
    }
    int end = a.size() - 1;
    printf("%05d %d -1", a[end].address, a[end].data);
    return 0;
}