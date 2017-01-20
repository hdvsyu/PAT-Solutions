#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    string shop, eva;
    getline(cin, shop);
    getline(cin, eva);
    int extra = 0;
    for (int i = 0; i < eva.length(); i++) {
        auto t = find(shop.begin(), shop.end(), eva[i]);
        if (t == shop.end()) {
            extra++;
        } else {
            shop.erase(t);
        }
    }
    string result = extra == 0 ? ("Yes " + to_string(shop.length())) : ("No " + to_string(extra));
    cout << result;
    return 0;
}
