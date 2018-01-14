#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

string add(string s, string t) {
    int carry = 0;
    string result;
    for (int i = 0; i < s.length(); i++) {
        result += (s[i] + t[i] - '0' - '0' + carry) % 10 + '0';
        carry = (s[i] + t[i] - '0' - '0' + carry) / 10;
    }
    if (carry != 0) result += carry + '0';
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s, t, sum;
    cin >> s;
    int cnt = 0;
    while (!isPalindrome(s) && cnt < 10) {
        cnt++;
        t = s;
        reverse(t.begin(), t.end());
        sum = add(s, t);
        printf("%s + %s = %s\n", s.c_str(), t.c_str(), sum.c_str());
        s = sum;
    }
    if (cnt == 10) {
        printf("Not found in 10 iterations.\n");
    } else {
        printf("%s is a palindromic number.\n", s.c_str());
    }
    return 0;
}
