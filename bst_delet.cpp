// C program to demonstrate delete operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 

struct node
{
	int key;
	struct node* left, * right;
};

// A utility function to create a new BST node 
struct node* newNode(int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST 
void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

struct node* minval(struct node *root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

struct node* deletenode(struct node *root, int key) {
	if (root == nullptr) return root;
	if (key < root->key) {
		root->left= deletenode(root->left, key);
	}
	else if (key > root->key) {
		root->right = deletenode(root->right, key);
	}
	else {
		// case 1 leaf node or case 2 root node have only one node either left or right.
		if (root->left == nullptr) {
			struct node* tmp = root->right;
			free (root);
			return tmp;
		}
		else if (root->right == nullptr) {
			struct node* tmp = root->left;
			free(root);
			return tmp;
		}
		struct node* minvaluenode = minval(root->right);
		root->key = minvaluenode->key;
		root->right= deletenode(root->right, minvaluenode->key);
	}
	return root;
}

// Driver Program to test above functions 
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	printf("Inorder traversal of the given tree \n");
	inorder(root);

	printf("\nDelete 20\n");
	root = deletenode(root, 20);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 30\n");
	root = deletenode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deletenode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	return 0;
}
