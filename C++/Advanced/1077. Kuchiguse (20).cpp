#include <stack>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

stack<char> suffix (vector<string> v) {
    stack<char> s;
    for (auto i = v[0].rbegin(); i != v[0].rend(); i++) {
        s.push(*i);
        for (int j = 1; j < v.size(); j++) {
            if (v[j].size() >= s.size() && v[j][v[j].size() - s.size()] != s.top()) {
                s.pop();
                return s;
            }
        }
    }
    return s;
}

int main () {
    int n = 0;
    cin >> n;
    getchar();
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        getline(cin, v[i]);
    }
    stack<char> s = suffix(v);
    if (s.size() == 0) {
        cout << "nai";
    }
    while (s.size() != 0) {
        cout << s.top();
        s.pop();
    }
    return 0;
}
