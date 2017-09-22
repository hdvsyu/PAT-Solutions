#include <cstdio>
#include <cstring>
#include <stack>
#include <deque>

using namespace std;

int main() {
    char radix[30], a[30], b[30];
    scanf("%s %s %s", radix, a, b);
    int ai = strlen(a) - 1, bi = strlen(b) - 1, carry = 0, ri = strlen(radix) - 1;
    deque<int> ans;
    while (ai >= 0 || bi >= 0) {
        int temp = radix[ri] - '0';
        if (temp == 0) temp = 10;
        if (ai >= 0 && bi >= 0) {
            ans.push_back((a[ai] - '0' + b[bi] - '0' + carry) % temp);
            carry = (a[ai] - '0' + b[bi] - '0' + carry) / temp;
            ai--;
            bi--;
            ri--;
        } else if (ai >= 0) {
            ans.push_back((a[ai] - '0' + carry) % temp);
            carry = (a[ai] - '0' + carry) / temp;
            ai--;
            ri--;
        } else if (bi >= 0) {
            ans.push_back((b[bi] - '0' + carry) % temp);
            carry = (b[bi] - '0' + carry) / temp;
            bi--;
            ri--;
        } else {
            break;
        }
    }
    if (carry != 0) {
        int temp = radix[ri] - '0';
        if (temp == 0) temp = 10;
        ans.push_back(carry % temp);
    }
    while (ans.size() != 0 && ans.back() == 0) {
        ans.pop_back();
    }
    if (ans.size() == 0) printf("0");
    else {
        while (ans.size() != 0) {
            printf("%d", ans.back());
            ans.pop_back();
        }
    }
    return 0;
}
