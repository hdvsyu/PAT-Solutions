#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++) {
        if (b.find(a[i]) == string::npos) {
            printf("%c", a[i]);
        }
    }
    return 0;
}
