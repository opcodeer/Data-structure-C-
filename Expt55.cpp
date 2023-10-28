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
node* newNode(int val){
    node* n = new node(val);
}
class BinarySearchTree {
public:
    node* root;

    BinarySearchTree() {
        root = NULL;
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

    node* search(node* root, int key) {
        if (root == NULL || root->key == key) {
            return root;
        }

        if (root->key < key) {
            return search(root->right, key);
        }

        return search(root->left, key);
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

    int key = 6;

    node* result = bst.search(bst.root, key);
    if (result == NULL) {
        cout << key << " not found" << endl;
    }
    else {
        cout << key << " found" << endl;
    }

    key = 60;

    result = bst.search(bst.root, key);
    if (result == NULL) {
        cout << key << " not found" << endl;
    }
    else {
        cout << key << " found" << endl;
    }

    return 0;
}
