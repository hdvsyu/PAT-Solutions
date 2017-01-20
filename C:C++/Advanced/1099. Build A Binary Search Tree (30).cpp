#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

struct child {
    int l, r;
};

struct node {
    int index;
    struct node *left, *right;
    string val;
};

void createTree(const vector<struct child> &nodes, struct node *root) {
    if (root == NULL || (nodes[root->index].l == nodes[root->index].r && nodes[root->index].r == -1))
        return;
    if (nodes[root->index].l != -1) {
        root->left = new struct node();
        root->left->index = nodes[root->index].l;
    }
    if (nodes[root->index].r != -1) {
        root->right = new struct node();
        root->right->index = nodes[root->index].r;
    }
    createTree(nodes, root->left);
    createTree(nodes, root->right);
}

void levelOrder(struct node *root) {
    queue<struct node*> q;
    q.push(root);
    while (q.size() != 0) {
        struct node *r = q.front();
        q.pop();
        if (r->left != NULL)
            q.push(r->left);
        if (r->right != NULL)
            q.push(r->right);
        if (r->index == 0) {
            cout << r->val;
        } else {
            cout << " " << r->val;
        }
    }
}

bool insertValue(struct node *root, int val) {
    if (root->val.size() == 0) {
        if (root->left != NULL) {
            if (insertValue(root->left, val)) {
                return true;
            } else {
                root->val = to_string(val);
                return true;
            }
        } else {
            if (root->val.size() == 0) {
                root->val = to_string(val);
                return true;
            }
            return root->right != NULL ? insertValue(root->right, val) : false;
        }
    }
    return root->right != NULL ? insertValue(root->right, val) : false;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<struct child> nodes;
    for (int i = 0; i < n; i++) {
        struct child c;
        scanf("%d %d", &c.l, &c.r);
        nodes.push_back(c);
    }
    struct node *root = new struct node();
    root->index = 0;
    createTree(nodes, root);
    int *nums = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, n, sizeof *nums, [](const void *a, const void *b) {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
        
        if(arg1 < arg2) return -1;
        if(arg1 > arg2) return 1;
        return 0;
    });
    for (int i = 0; i < n; i++) {
        insertValue(root, nums[i]);
    }
    levelOrder(root);
    delete [] nums;
    delete root;
    return 0;
}
