#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void remove (vector<char> &v, char c) {
    for (auto i = v.begin(); i != v.end(); i++) {
        if (*i == c) {
            v.erase(i);
            return;
        }
    }
}

void add (vector<char> &v, char c) {
    for (int i = 0; i < v.size(); i++){
        if (v[i] == c) {
            return;
        }
    }
    v.push_back(c);
}

bool contain (const vector<char> &v, char c) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == c) {
            return true;
        }
    }
    return false;
}

int main () {
    int k = 0;
    char s[1002];
    scanf("%d %s", &k, s);
    int cnt = 0;
    char c = '.';
    vector<char> v;
    for (int i = 0; i < strlen(s); i++) {
        add(v, s[i]);
        if (s[i] == c) {
            cnt++;
        } else {
            if (cnt % k != 0) {
                remove(v, c);
            }
            cnt = 1;
            c = s[i];
        }
    }
    if (cnt % k != 0) {
        remove(v, c);
    }
    for (int i = 0; i < v.size(); i++) {
        printf("%c", v[i]);
    }
    printf("\n");
    for (int i = 0; i < strlen(s); i++) {
        printf("%c", s[i]);
        if (contain(v, s[i])) {
            i += k - 1;
        }
    }
    return 0;
}