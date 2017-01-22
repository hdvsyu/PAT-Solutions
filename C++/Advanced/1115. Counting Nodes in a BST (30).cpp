#include <cstdio>
#include <vector>

using namespace std;

struct Node {
    int level, val;
    struct Node *left, *right;
};

int h = 0;
vector<struct Node *> v;

struct Node* insert(struct Node *root, int x, int l) {
    if (root == NULL) {
        root = new struct Node();
        root->val = x;
        root->level = l;
        v.push_back(root);
        h = l > h ? l : h;
    } else if (root->val >= x) {
        root->left = insert(root->left, x, l + 1);
    } else {
        root->right = insert(root->right, x, l + 1);
    }
    return root;
}

int main () {
    int n = 0;
    scanf("%d", &n);
    struct Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x = 0;
        scanf("%d", &x);
        root = insert(root, x, 1);
    }
    
    int n1 = 0, n2 = 0;
    for (vector<struct Node *>::iterator i = v.begin(); i != v.end(); i++) {
        if ((*i)->level == h) n1++;
        if ((*i)->level == h - 1) n2++;
    }
    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}

