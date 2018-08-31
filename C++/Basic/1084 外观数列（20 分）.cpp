#include <cstdio>
#include <string>

using namespace std;

string generate_sequence(string s) {
    if (s.size() == 1) return s + to_string(1);
    string result;
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) cnt++;
        else {
            result += s[i-1] + to_string(cnt);
            cnt = 1;
        }
    }
    if (s[s.size() - 1] == s[s.size() -2]) {
        result += s[s.size() - 1] + to_string(cnt);
    } else {
        result += s[s.size() - 1] + to_string(1);
    }
    return result;
}


int main() {
    int d = 0, n = 0;
    scanf("%d %d", &d, &n);
    string s = to_string(d);
    for (int i = 1; i < n; i++) {
        s = generate_sequence(s);
    }
    printf("%s\n", s.c_str());
}
