#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<int> pre, in, post;

void getPost(int a, int b, int r) {
    if (b > r)
        return;
    int i = b;
    while (i < r && in[i] != pre[a]) i++;
    getPost(a + 1, b, i - 1);
    getPost(a + i - b + 1, i + 1, r);
    post.push_back(in[i]);
}

int main() {
    int n = 0, t = 0;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < 2 * n; i++) {
        string op;
        cin >> op;
        if (op == "Push") {
            cin >> t;
            pre.push_back(t);
            s.push(t);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    getPost(0, 0, n - 1);
    cout << post[0];
    for (int i = 1; i < n; i++)
        cout << " " << post[i];
    return 0;
}
