#include <queue>
#include <cstdio>
#include <functional>
#include <vector>
 
using namespace std;
 
int main() {
    int n = 0;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        q.push(temp);
    }
    
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        
        q.push((a + b) / 2);
    }
    printf("%d", q.top());
}