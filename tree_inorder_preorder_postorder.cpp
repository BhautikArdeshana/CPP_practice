#include <iostream>
#include <string>
using namespace std;



struct tree {
	int val;
	tree* left;
	tree* right;
};

tree *Root=nullptr;
struct tree* search(tree *root,int val) {
	if (root == nullptr || root->val == val) {
		return root;
	}
	if (val > root->val) {
		search(root->right,val);
	}
	if (val < root->val) {
		search(root->left,val);
	}
}
tree* NewNode(int key) {
	tree* tmp = new tree;
	tmp->val = key;
	tmp->left = tmp->right = nullptr;
	return tmp;
}
tree * insert(tree* root,int key) {
	if (root == nullptr) {
		return  NewNode(key);
	}
	if (key < root->val) {
		root->left = insert(root->left, key);
	}
	else if (key > root->val) {
		root->right = insert(root->right, key);
	}
	return root;
}

/*
		 10
		/  \
	    5  20
	   /\	/ \
	  2 7  15 25
*/
//Inorder(Left, Root, Right) : 4 2 5 1 3
//Preorder(Root, Left, Right) : 1 2 4 5 3
//Postorder(Left, Right, Root) : 4 5 2 3 1
void print_inorder(tree *root){
	if (root == NULL) {
		return;
	}
	print_inorder(root->left);
	cout << " val= " << root->val;
	print_inorder(root->right);
}
void print_preorder(tree *root) {
	if (root == NULL) {
		return;
	}
	cout << " val= " << root->val;
	print_preorder(root->left);
	print_preorder(root->right);
	
}
void print_postorder(tree* root) {

	if (root == NULL) {
		return;
	}
	print_postorder(root->left);
	print_postorder(root->right);
	cout << " val= " << root->val;
}
tree* largest_second(tree *root) {
	if (root->right->right == nullptr) {
		return root;
	}
	largest_second(root->right);
}
tree* min_second(tree* root) {
	if (root->left->left == nullptr) {
		return root;
	}
	min_second(root->left);
	
}
int main()
{
	cout << "In Main" << endl;
	//Root=insert(Root, 10);
	/*insert(Root, 20);
	insert(Root, 5);
	insert(Root, 15);
	insert(Root, 25);
	insert(Root, 7);
	insert(Root, 2);*/

	Root=insert(Root, 50);
	insert(Root, 30);
	insert(Root, 20);
	insert(Root, 40);
	insert(Root, 70);
	insert(Root, 60);
	insert(Root, 80);


	cout << "preorder print" << endl;
	print_preorder(Root);
	cout << endl;
	cout << "inorder print" << endl;
	print_inorder(Root);
	cout << endl;
	cout << "postorder print" << endl;
	print_postorder(Root);
	cout << endl;

	tree* pre_large = largest_second(Root);
	cout << "2nd largest = " << pre_large->val << endl;
	tree* minimum_second = min_second(Root);
	cout << "2nd min = " << minimum_second->val << endl;
}
