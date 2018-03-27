#include <iostream>
#include <string>

using namespace std;

string read(string source) {
    string result;
    int cnt = 1;
    for (int i = 1; i < source.size(); i++) {
        if (source[i] != source[i-1]) {
            result += to_string(source[i-1] - '0') + to_string(cnt);
            cnt = 0;
        }
        cnt++;
    }
    result += to_string(*source.rbegin() - '0') + to_string(cnt);
    return result;
}

int main() {
    int d = 0, n = 0;
    scanf("%d %d", &d, &n);
    string s = to_string(d);
    for (int i = 1; i < n; i++)
        s = read(s);
    printf("%s", s.c_str());
    return 0;
}
