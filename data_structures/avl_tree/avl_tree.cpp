
/*
 * AVL tree implementation in c++.
 * @author: ArvindRS
 * @date: 09/24/2017
 */

#include <iostream>

using namespace std;

class AVLTree {

private:
	// Private Node class implementation
	class Node {
		public:
			int data;
			Node *left;
			Node *right;
			int height;
			Node(int data_p) {
				data = data_p;
				left = NULL;
				right = NULL;
				height = 1;
			}
	};

	// Declare the root node pointer
	Node *root;

	// Private method to get the balance factor of a given node
	int get_balance_factor(Node *current) {
		if(current->left == NULL && current->right == NULL)
			return 0; // Basically (0 - 0)
		else if(current->left == NULL)
			return (0 - current->right->height);
		else if(current->right == NULL)
			return (current->left->height - 0);
		else
			return (current->left->height - current->right->height);
	}

	// Private method to get the max height upto a given current node
	int max_height(Node *current) {
		if(current->left == NULL && current->right == NULL)
			return 0;
		else if(current->left == NULL)
			return current->right->height;
		else if(current->right == NULL)
			return current->left->height;
		else
			return max(current->left->height, current->right->height);
	}

	// Private overloaded insert method
	Node *insert(Node *current, Node *temp) {
		// Insert the temp node at the correct position 
		if(current == NULL)
			return temp;
		else if(temp->data <= current->data)
			current->left = insert(current->left, temp);
		else
			current->right = insert(current->right, temp);
		// Set the height of the current node
		current->height = 1 + max_height(current);
		// Call the rebalance_at() to rebalance the tree if required
		current = rebalance_at(current);
		// Return the current node
		return current;
	}

		// Private overloaded delete_node method
	Node *delete_node(Node *current, int data) {
		// Find the node containing the data and delete it
		if(current == NULL) {
			cout << "Element " << data << " not found!" << endl;
			return current;
		}
		else if(data < current->data)
			current->left = delete_node(current->left, data);
		else if(data > current->data)
			current->right = delete_node(current->right, data);
		else {
			// Check the three conditions for deletion in BST
			if(current->left == NULL && current->right == NULL) {
				Node *temp = current; // To prevent memory leakage
				current = NULL;
				delete temp;
			}
			else if(current->left == NULL) {
				Node *temp = current;
				current = current->right;
				delete temp;
			}
			else if(current->right == NULL) {
				Node *temp = current;
				current = current->left;
				delete temp;
			}
			else {
				Node *successor = find_min(current->right);
				current->data = successor->data; 							// We're not doing Node *temp = current; delete temp; here 
				current->right = delete_node(current->right, successor->data); // because we want to only update current node, not delete it.
			}			
		}
		// If we just deleted a leaf node, then we should return immediately instead of calling height on a NULL
		if(current == NULL)
			return current;
		// Set the height of the current node after deletion
		current->height = 1 + max_height(current);
		// Now to rebalance the tree as required after deletion
		current = rebalance_at(current);
		// Return the current node
		return current;
	}

	// Private method to perform the rebalancing operation
	Node *rebalance_at(Node *current) {
		// Check the balance factor of the current node
		int balance_factor = get_balance_factor(current);
		// Check if the balance factor falls in one of the 4 cases for rotation
		// If the balance factor is greater than 1 then it means the tree is left-heavy 
		if(balance_factor > 1) {
			// Case 1: Left-Left single rotation
			if(get_balance_factor(current->left) >= 1) {
				// Perform single rotation towards the right side
				current = rotate_right(current);
			}
			// Case 2: Left-Right double rotation
			else {
				// First left rotate on current's left child
				current->left = rotate_left(current->left);
				// Second right rotate on the current node
				current = rotate_right(current);
			}
		}
		// If the balance factor is less than 1 then it means the tree is right-heavy
		else if (balance_factor < -1) {
			// case 3: Right-Right single rotation
			if(get_balance_factor(current->right) <= -1) {
				// Perform a single rotation towards the left side
				current = rotate_left(current);
			}
			// Case 4: Right-Left double rotation
			else {
				// First right rotate on current's right child
				current->right = rotate_right(current->right);
				// Second left rotate on the current node
				current = rotate_left(current); 
			}
		}
		// Return the current node
		return current;
	}

	// Private method to find the minimum node from a given node
	Node *find_min(Node *current) {
		while(current->left != NULL)
			current = current->left;
		return current;
	}

	// Private method to rotate left on a given node
	Node *rotate_left(Node *current) {
		Node *new_root;
		Node *orphan;
		// Safety check
		if(current == NULL || current->right == NULL)
			return current;
		// Assign the new root node
		new_root = current->right;
		// Assign the left child of the new root to the orphan place holder
		orphan = new_root->left;
		// Assign current as new root's left child
		new_root->left = current;
		// Assign the orphan variable as current's right child
		current->right = orphan;
		// Reset the heights after the rotations
		current->height = 1 + max_height(current);
		new_root->height = 1 + max_height(new_root);
		// Return the new root
		return new_root;
	}

	// Private method to rotate right on a given node
	Node *rotate_right(Node *current) {
		Node *new_root;
		Node *orphan;
		// Safety check
		if(current == NULL || current->left == NULL)
			return current;
		// Assign current's left as the new root
		new_root = current->left;
		// Assign the right child of the new root to the orphan place holder
		orphan = new_root->right;
		// Assign current to be new root's right child
		new_root->right = current;
		// Assign orphan variable to be current's left child
		current->left = orphan;
		// Reset the heights after the rotations
		current->height = 1 + max_height(current);
		new_root->height = 1 + max_height(new_root);
		// Return the new root
		return new_root;
	}

	// Private overloaded inorder treversal function
	void display_inorder(Node *current) {
		if(current != NULL) {
			display_inorder(current->left);
			cout << current->data;
			display_inorder(current->right);
		}
	}

public:
	// Public constructor
	AVLTree() {
		root = NULL;
	}

	// Method to test if the tree is empty
	bool is_empty() {
		return (root == NULL);
	}

	// Method to insert an element
	void insert(int data) {
		Node *temp = new Node(data);
		root = insert(root, temp);
	}

	// Method to delete an element
	void delete_node(int data) {
		root = delete_node(root, data);
	}

	// Method to print the tree elements inorder
	void display_inorder() {
		display_inorder(root);
		cout << endl;
	}
};

// Main function
int main() {


	AVLTree avl;

	avl.insert(1);
	avl.insert(2);
	avl.insert(3);
	avl.display_inorder();
	avl.insert(8);
	avl.insert(9);
	avl.display_inorder();
	avl.insert(4);
	avl.display_inorder();
	avl.insert(5);
	avl.display_inorder();
	avl.delete_node(1);
	avl.display_inorder();
	avl.delete_node(4);
	avl.display_inorder();
	avl.delete_node(3);
	avl.display_inorder();
	avl.delete_node(2);
	avl.display_inorder();
	avl.delete_node(2);
}