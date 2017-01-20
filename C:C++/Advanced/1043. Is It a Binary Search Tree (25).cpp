#include <cstdio>
#include <vector>

using namespace std;

int *pre, isMirror = 0;

void getPost (vector<int> &post, int root, int tail) {
    if (root > tail) {
        return;
    }
    int i = root + 1, j = tail;
    if (!isMirror) {
        while (i <= tail && pre[root] > pre[i]) i++;
        while (j > root && pre[root] <= pre[j]) j--;
        if (i - j != 1) return;
        getPost (post, root + 1, j);
        getPost (post, i, tail);
    } else {
        while (i <= tail && pre[root] <= pre[i]) i++;
        while (j > root && pre[root] > pre[j]) j--;
        if (i - j != 1) return;
        getPost(post, root + 1, j);
        getPost(post, i, tail);
    }
    post.push_back(pre[root]);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    pre = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    vector<int> post;
    getPost (post, 0, n - 1);
    if (post.size() != n) {
        isMirror = 1;
        post.clear();
        getPost(post, 0, n - 1);
    }
    if (post.size() == n) {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < post.size(); i++) {
            printf(" %d", post[i]);
        }
    } else {
        printf("NO");
    }
    delete [] pre;
    return 0;
}
