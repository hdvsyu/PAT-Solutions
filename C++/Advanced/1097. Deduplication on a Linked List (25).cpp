#include <cstdio>
#include <vector>
#include <set>
using namespace std;

class Node {
public:
    int address, key, next;
};

int main() {
    int h = 0, n = 0;
    scanf("%d %d", &h, &n);
    vector<Node> v(100000);
    for (int i = 0; i < n; i++) {
        Node t;
        scanf("%d %d %d", &t.address, &t.key, &t.next);
        v[t.address] = t;
    }
    vector<Node> rs, re;
    set<int> s;
    for (int i = 0; i < n; i++) {
        Node node = v[h];
        if(s.find(node.key) != s.end() || s.find(-node.key) != s.end()) {
            re.push_back(node);
        } else {
            rs.push_back(node);
            s.insert(node.key);
        }
        h = node.next;
        if (h == -1) {
            break;
        }
    }
    
    for (int i = 0; i < rs.size(); i++) {
        if (i == rs.size() - 1) printf("%05d %d -1\n", rs[i].address, rs[i].key);
        else printf("%05d %d %05d\n", rs[i].address, rs[i].key, rs[i+1].address);
    }
    
    for (int i = 0; i < re.size(); i++) {
        if (i == re.size() - 1) printf("%05d %d -1\n", re[i].address, re[i].key);
        else printf("%05d %d %05d\n", re[i].address, re[i].key, re[i+1].address);
    }
    return 0;
}
