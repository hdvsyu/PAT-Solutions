#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* leftRotate(struct Node *tree) {
    struct Node *temp = tree->right;
    tree->right = temp->left;
    temp->left = tree;
    return temp;
}

struct Node* rightRotate(struct Node *tree) {
    struct Node *temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}

int getHeight(struct Node *tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int l = getHeight(tree->left);
        int r = getHeight(tree->right);
        return l > r ? l + 1 : r + 1;
    }
}

struct Node* leftRightRotate(struct Node *tree) {
    tree->left = leftRotate(tree->left);
    tree = rightRotate(tree);
    return tree;
}

struct Node* rightLeftRotate(struct Node *tree) {
    tree->right = rightRotate(tree->right);
    tree = leftRotate(tree);
    return tree;
}

struct Node* insert(struct Node *tree, int val) {
    if (tree == NULL) {
        tree = new struct Node();
        tree->val = val;
        return tree;
    }
    if (tree->val > val) {
        tree->left = insert(tree->left, val);
        int l = getHeight(tree->left);
        int r = getHeight(tree->right);
        if (l - r >= 2) {
            if (val < tree->left->val) {
                tree = rightRotate(tree);
            } else {
                tree = leftRightRotate(tree);
            }
        }
    } else {
        tree->right = insert(tree->right, val);
        int l = getHeight(tree->left);
        int r = getHeight(tree->right);
        if (r - l >= 2) {
            if (val > tree->right->val) {
                tree = leftRotate(tree);
            } else {
                tree = rightLeftRotate(tree);
            }
        }
    }
    return tree;
}

int isComplete = 1, after = 0;

vector<int> levelOrder(struct Node *tree) {
    vector<int> v;
    queue<struct Node *> queue;
    queue.push(tree);
    while (queue.size() != 0) {
        struct Node *temp = queue.front();
        queue.pop();
        v.push_back(temp->val);
        if (temp->left != NULL) {
            if (after) {
                isComplete = 0;
            }
            queue.push(temp->left);
        } else {
            after = 1;
        }
        if (temp->right != NULL) {
            if (after) {
                isComplete = 0;
            }
            queue.push(temp->right);
        } else {
            after = 1;
        }
    }
    
    return v;
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            printf("%d", v[i]);
        } else {
            printf(" %d", v[i]);
        }
    }
    printf("\n");
}

int main() {
    int n = 0;
    scanf("%d", &n);
    struct Node *tree = NULL;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        tree = insert(tree, temp);
    }
    
    vector<int> v = levelOrder(tree);
    print(v);
    if (isComplete) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}