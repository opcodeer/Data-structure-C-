#include <iostream>
using namespace std;

class node {
public:
    int key;
    node* left;
    node* right;

    node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};
node* newNode(int item) {
    return new node(item);
}
class BinarySearchTree {
public:
    node* root;

    BinarySearchTree() {
        // No need to initialize root here; it's automatically initialized to nullptr
    }

    node* insert(node* node, int key) {
        if (node == NULL) {
            return newNode(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        return node;
    }

    void inorder(node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.root = NULL;

    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);

    bst.inorder(bst.root);

    return 0;
}
