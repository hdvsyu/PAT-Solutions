#include <queue>
#include <cstdio>

using namespace std;

int main() {
    int n1 = 0, n2 = 0;
    queue<int> q1, q2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int t = 0;
        scanf("%d", &t);
        q1.push(t);
    }
    
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int t = 0;
        scanf("%d", &t);
        q2.push(t);
    }
    
    int n = (n1 + n2) % 2 == 0 ? (n1 + n2) / 2 -1 : (n1 + n2) / 2;
    int result = 0;
    for (int i = 0; i <= n; i++) {
        if (q1.size() == 0 || (q2.size() != 0 && q1.front() >= q2.front())) {
            result = q2.front();
            q2.pop();
        } else {
            result = q1.front();
            q1.pop();
        }
    }
    printf("%d", result);
    return 0;
}
