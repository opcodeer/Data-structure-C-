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

    void rightView() {
        int max_level = 0;
        rightViewUtil(root, 1, &max_level);
    }

private:
    void rightViewUtil(node* root, int level, int* max_level) {
        if (root == NULL)
            return;

        if (*max_level < level) {
            cout << root->data <<" ";
            *max_level = level;
        }

        rightViewUtil(root->right, level + 1, max_level);
        rightViewUtil(root->left, level + 1, max_level);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new node(1);
    tree.root->left = new node(2);
    tree.root->right = new node(3);
    tree.root->left->left = new node(4);
    tree.root->left->right = new node(5);
    tree.root->right->left = new node(6);
    tree.root->right->right = new node(7);
    tree.root->right->right->right = new node(8);

    cout << "Right view of the binary tree :\n";
    tree.rightView();

    return 0;
}
