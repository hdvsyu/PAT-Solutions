#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> in, post;

struct tree {
    int val, level;
    struct tree *left, *right;
};

int findRootInInorder(int inl, int inr, int val) {
    for (int i = inl; i <= inr; i++) {
        if (in[i] == val) return i;
    }
    return -1;
}

struct tree *buildTree(int inl, int inr, int postRoot, struct tree *root, int level) {
    if (inl > inr) return NULL;
    if (root == NULL) root = new struct tree();
    int inRoot = findRootInInorder(inl, inr, post[postRoot]);
    root->val = post[postRoot];
    root->level = level;
    root->left = buildTree(inl, inRoot - 1, postRoot - inr + inRoot - 1, root->left, level + 1);
    root->right = buildTree(inRoot + 1, inr, postRoot - 1, root->right, level + 1);
    return root;
}

vector<vector<int> > getLevelOrder(struct tree *root) {
    vector<vector<int> > levelOrder(30);
    queue<struct tree *> q;
    q.push(root);
    while (!q.empty()) {
        struct tree *t = q.front();
        q.pop();
        levelOrder[t->level].push_back(t->val);
        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
    }
    return levelOrder;
}

void printZigZag(vector<vector<int> > levelOrder) {
    printf("%d", levelOrder[0][0]);
    for (int i = 1; i < levelOrder.size(); i++) {
        if (i % 2 == 0) {
            for (int j = levelOrder[i].size() - 1; j >= 0; j--) {
                printf(" %d", levelOrder[i][j]);
            }
        } else {
            for (int j = 0; j < levelOrder[i].size(); j++) {
                printf(" %d", levelOrder[i][j]);
            }
        }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    
    struct tree *root = buildTree(0, n - 1, n - 1, NULL, 0);
    vector<vector<int> > levelOrder = getLevelOrder(root);
    printZigZag(levelOrder);
    return 0;
}