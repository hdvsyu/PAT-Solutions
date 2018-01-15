#include <string>
#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;
    while (cin >> a) {
        if (a[2] == 'T') printf("%d", a[0]-'A'+1);
    }
    return 0;
}
