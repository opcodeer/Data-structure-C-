/* C++ Program to find LCA of n1 and n2 using one traversal
* of Binary Tree */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree node
class node {
    public:
	node *left, *right;
	int key;
};

node* newnode(int key)
{
	node* temp = new node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

node* findLCA(node* root, int n1, int n2)
{
	// Base case
	if (root == NULL)
		return NULL;

	if (root->key == n1 || root->key == n2)
		return root;

	node* left_lca = findLCA(root->left, n1, n2);
	node* right_lca = findLCA(root->right, n1, n2);

	if (left_lca && right_lca)
		return root;

	return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
	node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
	return 0;
}
