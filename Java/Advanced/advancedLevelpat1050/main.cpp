#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s1, s2;
     getline(cin, s1);
     getline(cin, s2);
    
    set<char> s;
    for (int i = 0; i < s2.length(); i++) {
        s.insert(s2[i]);
    }
    
    for (int i = 0; i < s1.length(); i++) {
        char c = s1[i];
        if (s.count(c) == 0) {
            cout << c;
        }
    }
}
