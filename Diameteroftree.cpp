#include <iostream>
using namespace std;

class treenode {
public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(treenode* root) {
    if (root == NULL) return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

int diameter(treenode* root) {
    if (root == NULL) return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(max(ldiameter, rdiameter), lheight + rheight + 1);
}

int main() {
    treenode* root = new treenode(1);
    root->left = new treenode(2);
    root->right = new treenode(3);
    root->left->left = new treenode(4);
    
    int ans = diameter(root);
    cout << "Diameter of the tree is: " << ans << endl;
    
    return 0;
}
