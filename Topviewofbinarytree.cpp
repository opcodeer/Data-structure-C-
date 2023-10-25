#include <bits/stdc++.h>
using namespace std;

class node {
public:
    node* left;
    node* right;
    int hd;
    int data;

    node(int key) {
        left = NULL;
        right = NULL;
        data = key;
    }
};

class BinaryTree {
public:
    node* root;

    BinaryTree() {
        root = NULL;
    }

    void topView() {
        if (root == NULL)
            return;

        queue<node*> q;
        map<int, int> m;
        int hd = 0;
        root->hd = hd;

        q.push(root);

        cout << "The top view of the tree is : \n";

        while (!q.empty()) {
            node* current = q.front();
            q.pop();
            hd = current->hd;

            if (m.count(hd) == 0)
                m[hd] = current->data;

            if (current->left) {
                current->left->hd = hd - 1;
                q.push(current->left);
            }
            if (current->right) {
                current->right->hd = hd + 1;
                q.push(current->right);
            }
        }

        for (auto i = m.begin(); i != m.end(); i++) {
            cout << i->second << " ";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.root = new node(1);
    tree.root->left = new node(2);
    tree.root->right = new node(3);
    tree.root->left->right = new node(4);
    tree.root->left->right->right = new node(5);
    tree.root->left->right->right->right = new node(6);
    tree.topView();
    return 0;
}
