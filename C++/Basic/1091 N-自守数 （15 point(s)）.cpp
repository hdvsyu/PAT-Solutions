#include <iostream>
#include <string>

using namespace std;

void is_self_guard_and_output(int num) {
    for (int var1 = 1; var1 < 10; var1++) {
        string s = to_string(var1 * num * num);
        if (to_string(num).size() > s.size()) continue;
        
        if (s.substr(s.size() - to_string(num).size(), to_string(num).size()) == to_string(num)) {
            cout << var1 << " " << s << endl;
            return;
        }
    }
    cout << "No\n";
}

int main() {
    int m = 0, num = 0;
    cin >> m;
    for (int var1 = 0; var1 < m; var1++) {
        cin >> num;
        is_self_guard_and_output(num);
    }
    return 0;
}