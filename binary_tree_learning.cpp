// Binary_Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <stack>
#include <queue>
#include <climits>

using namespace std;


struct btnode {
		int data;
		btnode *left;
		btnode *right;
};

class btree {
public:
//	btree();
//	~btree();
	btnode* insert(btnode *root, int data);
	btnode* binary_insert(btnode *root, int data);
	btnode* GetNewNode(int data);
	bool search(btnode *root, int element);
	void display(btnode *root);
	void inorder(btnode *root);
	void postorder(btnode *root);
	void preorder(btnode *root);
	void preorder_no_recursion(btnode *root);
	void inorder_no_recursion(btnode *root);
	void postorder_no_recursion(btnode *root);
	void level_order_traversal(btnode *root);
	int find_max(btnode *root);
	int find_min(btnode *root);
	int find_min_no_recursion(btnode *root);
	btnode* delete_node(btnode *root,int data);
	btnode *Find_Max_node_in_BST(btnode *root);
	btnode *Find_Min_node_in_BST(btnode *root);
	bool isbst(btnode *root);
	int isBSTUtil(btnode *root, int min, int max);
	btnode* get_node_address(btnode *root, int data);
	int lowest_common_ancestor(btnode *root, btnode *node1, btnode *node2);
	int get_successor(btnode* node, int data);
	int get_predecessor(btnode* node, int data);
};

btnode *btree::GetNewNode(int data) {
	btnode* node = new btnode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

btnode *btree::insert(btnode *root, int data) {

	if (root == NULL) {

		root = GetNewNode(data);		
	}
	else if (data <= root->data) {

		root->left = insert(root->left, data);
	}
	else if (data > root->data) {

		root->right = insert(root->right, data);
	}

	return root;
}

btnode *btree::binary_insert(btnode *root, int data) {

	btnode *newnode = new btnode();
	newnode->left = NULL;
	newnode->right = NULL;
	btnode *temp;

	if (root == NULL) {

		root = newnode;
		root->data = data;
		return root;
	}

	queue<btnode *> myqueue;

	myqueue.push(root);

	// Level Order Traversal to find the empty node to insert the element.

	while (!myqueue.empty()) {
		root = myqueue.front();
		myqueue.pop();

		if (root->left)
		{
			myqueue.push(root->left);
		}
		else {
			root->left = newnode;
			root->data = data;
			return root;
		}

		if (root->right)
		{
			myqueue.push(root->right);
		}
		else {
			root->right = newnode;
			root->data = data;			
			return root;
		}
	}

	return root;
}

bool btree::search(btnode *root, int element) {

	// Check for the valid tree;
	if (root == NULL) return false;
		
	if (root->data == element) return true;
		
	if (element <= root->data) {
		search(root->left, element);
	}
	else {
		search(root->right, element);
	}
}

void btree::inorder(btnode *root) {

	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);
}

void btree::inorder_no_recursion(btnode *root) {

	std::stack<btnode *> mystack;

	while (!mystack.empty() || root){
		if (root) {
			mystack.push(root);
			root = root->left;
		}
		else {
			root = mystack.top();
			mystack.pop();
			cout << root->data << " ";
			root = root->right;
		}
	}	
}

void btree::postorder(btnode *root) {

	if (root == NULL)
		return;
	postorder(root->left);	
	postorder(root->right);
	cout << root->data<<" ";
}

void btree::postorder_no_recursion(btnode *root) {

	std::stack<btnode *> mystack;

	if (!root)
		return;
	mystack.push(root);
	btnode *prev = NULL;
	while (!mystack.empty()) {

		btnode *curr = mystack.top();

		if (!prev || prev->left == curr || prev->right == curr) {

			if (curr->left)
				mystack.push(curr->left);
			else if (curr->right)
				mystack.push(curr->right);

		} else if (curr->left == prev) {

			if (curr->right){
				mystack.push(curr->right);
			}

		} else {

			cout << curr->data << " ";
			mystack.pop();

		}

		prev = curr;
	}

}

void btree::preorder(btnode *root) {

	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	
}



void btree::preorder_no_recursion(btnode *root) {

	std::stack<btnode *> mystack;

	while (!mystack.empty() || root) {

		if (root) {
			cout << root->data << " ";
			mystack.push(root);
			root = root->left;

		}
		else {
			root = mystack.top();
			mystack.pop();
			root = root->right;
		}
	}
}


void btree::display(btnode *root) {

	if (root == NULL) {
		cout << "Tree is empty";
	}
}



void btree::level_order_traversal(btnode *root) {

	if (root == NULL) {
		cout << "Tree is empty";
		return;
	}

	std::queue<btnode *> myqueue;

	myqueue.push(root);

	while (!myqueue.empty()) {

		btnode *temp = myqueue.front();			
		
		cout << temp->data << " ";		
			
		if (temp->left) {
			myqueue.push(temp->left);
		}

		if (temp->right) {
			myqueue.push(temp->right);
		}
		myqueue.pop();
	}

}

int btree::find_max(btnode *root) {

	int value=0;
	int lvalue, rvalue, temp,max = INT_MIN;

	if (root != NULL) {		
		temp = root->data;
		lvalue = find_max(root->left);
		rvalue = find_max(root->right);

		if (lvalue > rvalue) {
			max = lvalue;
		}
		else {
			max = rvalue;
		}
		if (temp > max)
			max = temp;
	}

	return max;

}

int btree::find_min(btnode *root) {

	int value = 0;
	int lvalue, rvalue, temp, min = INT_MAX;

	if (root != NULL) {
		temp = root->data;
		lvalue = find_min(root->left);
		rvalue = find_min(root->right);

		if (lvalue < rvalue) {
			min = lvalue;
		}
		else {
			min = rvalue;
		}
		if (temp < min)
			min = temp;
	}
	return min;
}

int btree::find_min_no_recursion(btnode *root) {

	queue<btnode *> myqueue;

	if (root == NULL){
		cout << "Tree is Empty" << endl;
		return 0;
	}

	myqueue.push(root);

	int min = INT_MAX;

	while (!myqueue.empty()) {

		btnode *temp = myqueue.front();
		myqueue.pop();

		if (min > temp->data) {
			min = temp->data;
		}

		if (temp->left) {
			myqueue.push(temp->left);
		}

		if (temp->right) {
			myqueue.push(temp->right);
		}

	}

	return min;
}


// Binary Search Tree Deletion.

btnode * btree::delete_node(btnode *root, int data) {
	// Check root is not NULL.

	if (root == NULL) {
		cout << "Tree is Empty";
		return root;
	}

	// Case 1: Delete the node and return NULL to Parent.

	if (data < root->data) {
		root->left = delete_node(root->left, data);
	}
	else if (data > root->data) {
		root->right = delete_node(root->right, data);
	}
	else if ((root->left == NULL) && (root->right == NULL)) {
		// Case 1 : The node is Leaf Node.	
		delete root;
		root = NULL;
	}
	else if (root->left == NULL) {
		// Case 2: The node has One Child;
		btnode *temp = root;
		root = root->right;
		delete temp;
		return root;
	}
	else if (root->right == NULL) {
		// Case 2: The node has One Child;
		btnode *temp = root;
		root = root->left;
		delete temp;
		return root;
	}
	else {
		// Case 3: A Delete node has Two Children.
		btnode *temp = root;
		temp = Find_Max_node_in_BST(root->left);
		root->data = temp->data;
		root->left = delete_node(root->left, root->data);
	}
	return root;
}

btnode *btree::Find_Max_node_in_BST(btnode *root) {

	// Return NULL if root is empty.

	if (root == NULL) {
		cout << "Tree is Empty" << endl;
		return NULL;
	}

	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

btnode *btree::Find_Min_node_in_BST(btnode *root) {

	// Return NULL if root is empty.

	if (root == NULL) {
		cout << "Tree is Empty" << endl;
		return NULL;
	}

	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

// Check Binary Tree is Binary Search Tree.

bool btree::isbst(btnode *root) {

	return(isBSTUtil(root, INT_MIN, INT_MAX));
}

int btree::isBSTUtil(btnode *root, int min, int max) {

	if (root == NULL) {		
		return true;
	}

	if ((root->data > min) && (root->data < max) && (isBSTUtil(root->left, min, root->data)) && (isBSTUtil(root->right, root->data, max))) {

		return true;
	}

}

btnode* btree::get_node_address(btnode *root, int data) {

	if (root == NULL) {		
		return root;
	}

	if (root->data == data) {
		return root;
	}

	if (data < root->data) {
		get_node_address(root->left, data);

	}
	else  {
		get_node_address(root->right, data);
	}
}

int btree::lowest_common_ancestor(btnode *root, btnode *node1, btnode *node2) {

	if (root == NULL) {
		return 0;
	}

	while (1) {
		if ((node1->data < root->data) && (node2->data > root->data) || (node1->data > root->data) && (node2->data < root->data)) {

			return root->data;
		}

		if (node1->data < root->data) {

			root = root->left;
		}
		else {

			root = root->right;
		}
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	btree btree_obj;
	btnode *root_ptr = NULL;
	root_ptr = btree_obj.insert(root_ptr, 7);
	root_ptr = btree_obj.insert(root_ptr, 4);
	root_ptr = btree_obj.insert(root_ptr, 9);

	root_ptr = btree_obj.insert(root_ptr, 2);
	root_ptr = btree_obj.insert(root_ptr, 5);
/*	root_ptr = btree_obj.insert(root_ptr, 3);*/

	if (root_ptr == NULL) {
		cout << "After insertion , tree is empty. Insert Properly.";
		exit(0);
	}

/*	cout << "Pre Order Traversal" << endl;
	btree_obj.preorder(root_ptr);
	cout << endl;

	cout << "Pre Order Traversal - No Recursion" << endl;
	btree_obj.preorder_no_recursion(root_ptr);
	cout << endl;

	cout << "In-Order Traveersal" << endl;
	btree_obj.inorder(root_ptr);
	cout << endl;

	cout << "In Order Traversal - No Recursion" << endl;
	btree_obj.inorder_no_recursion(root_ptr);
	cout << endl;

	cout << "Post-Order Traveersal" << endl;
	btree_obj.postorder(root_ptr);
	cout << endl;

	cout << "In Order Traversal - No Recursion" << endl;
	btree_obj.postorder_no_recursion(root_ptr);
	cout << endl;

	cout << "Post Order - No Recursion" << endl;
	btree_obj.postorder_no_recursion(root_ptr);
	cout << endl;
	*/
	cin.clear();
	// Search Operation.
	int search_val;
/*	cout << "Enter the value to searched in" << endl;
	cin >> search_val;	*/

/*	bool bval = btree_obj.search(root_ptr, 5);

	if (bval == true) {
		cout << "Node Found" << endl;
	
	} else {
		cout << "Node Not Found" << endl;
	}
*/
/*	cout << "Level Order Traversal - No Recursion" << endl;
	btree_obj.level_order_traversal(root_ptr);
	cout << endl;

	cout << "Find Max Element" << endl;
	int x = btree_obj.find_max(root_ptr);
	cout <<x <<endl;

	cout << "Find Min Element" << endl;
	x = btree_obj.find_min(root_ptr);
	cout << x << endl;

	cout << "Delete a Node" << endl;
	root_ptr = btree_obj.delete_node(root_ptr,9) ;
	
	cout << "In Order Traversal - After Deletion 9" << endl;
	btree_obj.inorder_no_recursion(root_ptr);
	cout << endl;


	cout << "Delete a Node" << endl;
	root_ptr = btree_obj.delete_node(root_ptr, 5);
	cout << endl;

	cout << "In Order Traversal - After Deletion 5" << endl;
	btree_obj.inorder_no_recursion(root_ptr);
	cout << endl;

	cout << "Check Tree is BST" << endl;
	bool c = btree_obj.isbst(root_ptr);

	if (c == true) {

		cout << "\nThis is Binary Search Tree" << endl;
	}
	else {
		cout << "This is Not a Binary Search Tree" << endl;
	}	


	btnode *temp = btree_obj.get_node_address(root_ptr, 9);
	btnode *temp2 = btree_obj.get_node_address(root_ptr, 5);

	if (temp != NULL && temp2 != NULL) {

		int lca = btree_obj.lowest_common_ancestor(root_ptr, temp, temp2);
		cout << "Lowest Common Ancestor" << lca << endl;
	}

	

//	cout << "The node Data" << root_ptr->data;

	int ssr = btree_obj.get_successor(root_ptr, 4);
	cout << "The successor Data: " << ssr<<endl;

	 ssr = btree_obj.get_successor(root_ptr, 5);
	cout << "The successor Data: " << ssr << endl;

	ssr = btree_obj.get_successor(root_ptr, 9);
	cout << "The successor Data: " << ssr << endl;

	ssr = btree_obj.get_predecessor(root_ptr,5);
	cout << "The predecessor Data: " << ssr << endl;

	cin.get();
	cin >> search_val;
	return 0;
}

int btree::get_successor(btnode* root, int data) {

	btnode *current_node = get_node_address(root, data);

	if (current_node == NULL) {
		return NULL;
	}

	// Case 1: Node has Right SubTree.
	// Find Minimum value at Right Sub Tree.

	if (current_node->right != NULL) {
		
		btnode *temp = current_node->right;
		while (temp->left != NULL) {
			temp = temp->left;
		}

		return temp->data;		
	}
	else {

		// Case 2: Node has no Right SubTree.
		btnode *ancestor = root;
		btnode *successor = NULL;

		while (current_node != ancestor) {

			if (current_node->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}

		if (successor) {
			return successor->data;
		}
		else {
			return -1;
		}

	}

}


int btree::get_predecessor(btnode* root, int data) {

	btnode *current_node = get_node_address(root, data);

	if (current_node == NULL) return -1;

	if (root->left != NULL) {

		btnode* temp = root;
		temp = Find_Max_node_in_BST(root->left);
		return temp->data;
	}

	btnode *predecessor = NULL;
	btnode *ancestor = root;
	while (ancestor != NULL) {

		if (current_node->data > ancestor->data) {
			predecessor = ancestor;
			ancestor = ancestor->right;
		}
		else {
			ancestor = ancestor->left;
		}

	}

	return predecessor->data;

}


