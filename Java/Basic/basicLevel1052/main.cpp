#include <vector>
#include <iostream>

using namespace std;

vector<string> parse(string s) {
    bool isStart = false;
    vector<string> v;
    string temp = "";
    v.push_back(temp);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            isStart = true;
        } else if (s[i] == ']') {
            isStart = false;
            v.push_back(temp);
            temp = "";
        } else {
            if (isStart) {
                temp += s[i];
            }
        }
    }
    return v;
}


int main() {
    string temp;
    getline(cin, temp);
    vector<string> hand = parse(temp);
    getline(cin, temp);
    vector<string> eye = parse(temp);
    getline(cin, temp);
    vector<string> mouth = parse(temp);
    
    int k = 0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num[5];
        cin>> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
        
        if (num[0] >= hand.size() || num[0] < 1 || num[4] >= hand.size() || num[4] < 1 || num[1] >= eye.size()
            || num[1] < 1 || num[3] >= eye.size() || num[3] < 1 || num[2] >= mouth.size() || num[2] < 1) {
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        
        cout << hand[num[0]] + "(" + eye[num[1]] + mouth[num[2]] + eye[num[3]] + ")"
        + hand[num[4]] << endl;
    }
    
    return 0;
}

