#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

int main () {
    string s;
    getline(cin, s);
    map<string, int> m;
    for (int i = 0; i < s.length(); i++) {
        string word;
        while (isalnum(s[i])) {
            word += tolower(s[i]);
            i++;
        }
        if (word.size() != 0) {
            m[word]++;
        }
    }

    int max = -1;
    for (map<string, int>::iterator i = m.begin(); i != m.end(); i++) {
        if (i->second > max) {
            max = i->second;
            s = i->first;
        }
    }
    cout << s << " " << max;
    return 0;
}
