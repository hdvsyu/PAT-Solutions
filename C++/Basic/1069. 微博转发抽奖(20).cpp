#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int m = 0, n = 0, s = 0;
    cin >> m >> n >> s;
    vector<string> forward(m + 1);
    for (int i = 1; i <= m; i++) {
        string nickname;
        cin >> nickname;
        forward[i] = nickname;
    }
    
    if (s > m) {
        cout << "Keep going..." << endl;
    } else {
        map<string, bool> winner;
        cout << forward[s] << endl;
        winner[forward[s]] = true;
        int i = s;
        while (i < m) {
            int cnt = 0;
            while (i < m && cnt < n) {
                i++;
                if (winner[forward[i]] == false) {
                    cnt++;
                }
            }
            if (n == cnt) {
                cout << forward[i] << endl;
                winner[forward[i]] = true;
            }
        }
    }
    return 0;
}