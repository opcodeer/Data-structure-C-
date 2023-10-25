#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int item) {
        data = item;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    node* root;

    BinaryTree() {
        root = NULL;
    }

    void leftView() {
        int max_level = 0;
        leftViewUtil(root, 1, &max_level);
    }

private:
    void leftViewUtil(node* root, int level, int* max_level) {
        if (root == NULL)
            return;

        if (*max_level < level) {
            cout << root->data << " ";
            *max_level = level;
        }

        leftViewUtil(root->left, level + 1, max_level);
        leftViewUtil(root->right, level + 1, max_level);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new node(10);
    tree.root->left = new node(2);
    tree.root->right = new node(3);
    tree.root->left->left = new node(7);
    tree.root->left->right = new node(8);
    tree.root->right->right = new node(15);
    tree.root->right->left = new node(12);
    tree.root->right->right->left = new node(14);

    cout << "Left view of the binary tree :\n";
    tree.leftView();

    return 0;
}
