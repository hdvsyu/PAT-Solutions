#include <cstdio>
#include <vector>

using namespace std;

int main () {
    int n = 0, b = 0;
    scanf("%d %d", &n, &b);
    vector<int> v;
    do {
       v.push_back(n % b);
        n /= b;
    } while (n != 0);
    bool equal = true;
    for (int i = 0; i < v.size() / 2; i++) {
        if (v[i] != v[v.size() - i - 1]) {
            equal = false;
        }
    }
    printf("%s\n", equal ? "Yes" : "No");
    printf("%d", v[v.size() - 1]);
    for (int i = v.size() - 2; i >= 0; i--) {
        printf(" %d", v[i]);
    }
    return 0;
}
