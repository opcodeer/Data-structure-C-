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
int Heightoftree(treenode* root){
    if(root==NULL) return 0;
    else{
        int leftheight = Heightoftree(root->left);
        int rightheight = Heightoftree(root->right);
        if(leftheight>rightheight){
            return leftheight+1;
        }else{
            return rightheight+1;
        }
    }
}
int main()
{
	treenode* root = new treenode(1);
	root->left = new treenode(2);
	root->right = new treenode(3);
	root->left->left = new treenode(4);
    int height = Heightoftree(root);
    cout<<"The height of the given binary tree is "<<height<<endl;
	return 0;
}
