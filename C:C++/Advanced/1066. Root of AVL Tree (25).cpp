#include <cstdio>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* rotateRight (struct Node *root) {
    struct Node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

struct Node* rotateLeft (struct Node *root) {
    struct Node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

struct Node* rotateLeftRight (struct Node *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

struct Node* rotateRightLeft (struct Node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

int getHigh (const struct Node *root) {
    if (root == NULL) return 0;
    int l = getHigh(root->left), r = getHigh(root->right);
    return l > r ? l + 1: r + 1;
}

struct Node* insert (struct Node *root, int val) {
    if (root == NULL) {
        root = new struct Node();
        root->val = val;
        root->left = root->right = NULL;
        return root;
    }
    if (root->val > val) {
        root->left = insert(root->left, val);
        if (getHigh(root->left) - getHigh(root->right) == 2) {
            if (root->left->val > val) {
                root = rotateRight (root);
            } else {
                root = rotateLeftRight(root);
            }
        }
    } else {
        root->right = insert(root->right, val);
        if (getHigh(root->left) - getHigh(root->right) == -2) {
            if (root->right->val < val) {
                root = rotateLeft(root);
            } else {
                root = rotateRightLeft(root);
            }
        }
    }
    return root;
}

int main () {
    struct Node *root = NULL;
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num = 0;
        scanf("%d", &num);
        root = insert(root, num);
    }
    printf("%d", root->val);
    delete root;
    return 0;
}
