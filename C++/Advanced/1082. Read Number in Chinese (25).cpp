#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, string> initMap() {
    map<char, string> res;
    res['0'] = "ling"; res['1'] = "yi"; res['2'] = "er"; res['3'] = "san";
    res['4'] = "si"; res['5'] = "wu"; res['6'] = "liu"; res['7'] = "qi";
    res['8'] = "ba"; res['9'] = "jiu";
    return res;
}

map<int, string> initSiteMap() {
    map<int, string> res;
    res[2] = "Shi"; res[3] = "Bai"; res[4] = "Qian"; res[5] = "Wan";
    res[6] = "Shi"; res[7] = "Bai"; res[8] = "Qian"; res[9] = "Yi";
    return res;
}

int main() {
    string num;
    cin >> num;
    if (num[0] == '-') {
        cout << "Fu ";
        num = num.substr(1);
    }
    map<char, string> unit = initMap();
    map<int, string> site = initSiteMap();
    bool isZero = false;
    cout << unit[num[0]];
    if (num.length() > 1) {
        cout << " " << site[num.length()];
    }
    num = num.substr(1);
    while (num.length() > 0) {
        if (num[0] == '0') {
            isZero = true;
            if (num.length() == 5) {
                cout << " " << site[5];
            }
        } else {
            if (isZero) {
                cout << " ling";
            }
            isZero = false;
            cout << " " << unit[num[0]];
            if (num.length() > 1) {
                cout << " " << site[num.length()];
            }
        }
        num = num.substr(1);
    }
        cout << "Hello World." << endl;
    return 0;
}
