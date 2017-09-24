
/*
 * Binary Search Tree implementation in c++.
 * @author: ArvindRS
 * @date: 09/23/2017
 */

#include <iostream>

using namespace std;

class BST {
private:
	// Node class definition
	class Node {
	public:
		int data;
		Node *left;
		Node *right;
		Node(int datat) {
			data = datat;
			left = NULL;
			right = NULL;
		}
	};
	Node *root;

	// Private overloaded insert function
	Node *insert(Node *current, Node *temp) {
		if(current == NULL)
			return temp;
		else if(temp->data <= current->data)
			current->left = insert(current->left, temp);
		else if(temp->data > current->data)
			current->right = insert(current->right, temp);
	}

	// private overloaded delete function
	Node *delete_node(Node *current, int data) {
		if(current == NULL) {
			cout << data << " not found!" << endl;
			return current;
		}
		else if(data < current->data)
			current->left = delete_node(current->left, data);
		else if(data > current->data)
			current->right = delete_node(current->right, data);
		else {
			// Found the data. Next step check which of the delete conditions for BST matches.
			// Case 1: Node to be deleted has no left or right children
			if(current->left == NULL && current->right == NULL) {
				current = NULL;
				delete current;
			}
			// Case 2: Node to be deleted has one child
			else if(current->left == NULL) {
				current = current->right;
			}
			else if(current->right == NULL) {
				current = current->left;
			}
			// case 3: Node to be deleted has two children
			else {
				Node *successor = find_min(current->right);
				current->data = successor->data;
				current->right = delete_node(current->right, successor->data);
			}
		}
		return current;
	}

	// Private overloaded inorder function
	void display_inorder(Node *current) {
		if(current != NULL) {
			display_inorder(current->left);
			cout << current->data << " ";
			display_inorder(current->right);
		}
	}

public:
	// Public constructor
	BST() {
		root = NULL;
	}

	// Methods to manipulate the tree
	// Method to check if the tree is empty
	bool is_empty() {
		return (root == NULL);
	}

	// Method to insert into the tree
	void insert(int data) {
		Node *temp = new Node(data);
		root = insert(root, temp);
	}

	// Method to delete an element from the tree
	void delete_node(int data) {
		root = delete_node(root, data);
	}

	// Method to find the minimum element
	Node *find_min(Node *current) {
		while(current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	// Method to print the elements of the tree inorder
	void display_inorder() {
		display_inorder(root);
		cout << endl;
	}

};

int main() {

	BST bst;

	cout << bst.is_empty() << endl;
	bst.insert(5);
	bst.insert(3);
	bst.insert(4);
	bst.insert(8);
	bst.insert(6);
	bst.insert(7);

	bst.display_inorder();

	bst.delete_node(6);
	bst.display_inorder();
	bst.delete_node(7);
	bst.display_inorder();
	bst.delete_node(5);
	bst.display_inorder();
	bst.delete_node(5);

	return 0;
}