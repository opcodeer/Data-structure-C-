#include <bits/stdc++.h>
using namespace std;

class node {
    public:
	int key;
	node *left, *right;
};

node* newnode(int item)
{
	node* temp = new node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

node* insert(node* node, int key)
{
	if (node == NULL)
		return newnode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	    return node;
}

node* deletenode(node* root, int k)
{
	// Base case
	if (root == NULL)
		return root;

	if (root->key > k) {
		root->left = deletenode(root->left, k);
		return root;
	}
	else if (root->key < k) {
		root->right = deletenode(root->right, k);
		return root;
	}

	if (root->left == NULL) {
		node* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == NULL) {
		node* temp = root->left;
		delete root;
		return temp;
	}

	else {

		node* succParent = root;
		node* succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		if (succParent != root)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;

		root->key = succ->key;

		delete succ;
		return root;
	}
}

int main()
{
	node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);

	inorder(root);

	root = deletenode(root, 20);
	inorder(root);
    cout<<endl;
	root = deletenode(root, 70);
    cout<<"BST tree after deleting single child node "<<endl;
	inorder(root);
    cout<<endl;
	root = deletenode(root, 50);
    cout<<"BST tree after deleting both child node"<<endl;
	inorder(root);
    cout<<endl;
	return 0;
}
