#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data; // Data of the node
    int hd;   // Horizontal distance of the node
    node* left;
    node* right;

    // Constructor of tree node
    node(int key) {
        data = key;
        hd = INT_MAX;
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

    // Method that prints the bottom view.
    void bottomView() {
        if (root == NULL)
            return;

        int hd = 0;
        map<int, int> m;
        queue<node*> q;

        root->hd = hd;
        q.push(root);

        while (!q.empty()) {
            node* temp = q.front();
            q.pop();

            hd = temp->hd;
            m[hd] = temp->data;

            if (temp->left != NULL) {
                temp->left->hd = hd - 1;
                q.push(temp->left);
            }

            if (temp->right != NULL) {
                temp->right->hd = hd + 1;
                q.push(temp->right);
            }
        }

        for (auto i = m.begin(); i != m.end(); ++i)
            cout << i->second << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.root = new node(20);
    tree.root->left = new node(8);
    tree.root->right = new node(22);
    tree.root->left->left = new node(5);
    tree.root->left->right = new node(3);
    tree.root->right->left = new node(4);
    tree.root->right->right = new node(25);
    tree.root->left->right->left = new node(10);
    tree.root->left->right->right = new node(14);

    cout << "Bottom view of the given binary tree :\n";
    tree.bottomView();
    return 0;
}
