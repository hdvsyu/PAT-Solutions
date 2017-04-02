#include <iostream>
#include <vector>
using namespace std;
struct node {
    string val;
    int left;
    int right;
};
vector<node> v;
int root;
string dfs(int index) {
    if (index == -1) return "";
    if (v[index].right != -1) {
        v[index].val = dfs(v[index].left) + v[index].val + dfs(v[index].right);
        if (index != root) v[index].val = '(' + v[index].val + ')';
    }
    return v[index].val;
}
int main() {
    int n;
    cin >> n;
    v.resize(n + 1);
    vector<bool> visit(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].val >> v[i].left >> v[i].right;
        if (v[i].left != -1) visit[v[i].left] = true;
        if (v[i].right != -1) visit[v[i].right] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            root = i;
            break;
        }
    }
    cout << dfs(root) << endl;
    return 0;
}