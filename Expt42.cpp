#include <bits/stdc++.h>
using namespace std;

class treenode {
public:
	int data;
	treenode* left;
	treenode* right;
	treenode(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
void inorder(treenode* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	treenode* root = new treenode(1);
	root->left = new treenode(2);
	root->right = new treenode(3);
	root->left->left = new treenode(4);
	cout<<"The inorder traversal of above created binary tree is "<<endl;
	inorder(root);
	return 0;
}
