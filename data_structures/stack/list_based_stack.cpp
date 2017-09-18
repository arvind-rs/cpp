
/*
 * This is a simple Stack ADT implementation in c++ using a list structure.
 * @author: ArvindRS
 * @date: 09/18/2017
 */

#include <iostream>
using namespace std;

class Stack {

private:
	// Inner class to represent the Node structure
	class Node {
	public:
		int data;
		Node *next;
		Node(int d, Node *n = NULL) {
			data = d; // Cannot use the same name for formal parameters as the local variable name. eg: data = data leads to errors.
			next = n;
		}
	};
	// Declaring the head node
	Node *head;
public:
	// Public constructor
	Stack() {
		head = NULL;
	}

	// List of member functions

	// Function to check if the stack is empty
	bool is_empty() {
		return (head == NULL);
	}

	// Function to look at the top of the stack
	int peek() {
		if(head != NULL) return head->data;
	}

	// Function to push a data item on to the stack
	void push(int data) {
		Node *temp = new Node(data);
		if(head == NULL) {
			temp->next = NULL; // This line is unnecessary as I've already initialized the *next with NULL using the Node's constructor
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}

	// Function to pop the stack
	int pop() {
		// Copying the head node to a temp so that we can explicitly delete that node as there is no garbage collection in c++
		Node *temp = head;
		head = head->next;
		int data = temp->data;
		delete temp;
		return data;
	}

};

int main() {

	// Creating the Stack object
	Stack s;

	cout << "Is the stack empty? " << s.is_empty() << endl;

	s.push(5);
	s.push(10);
	s.push(15);
	cout << "Is the stack empty? " << s.is_empty() << endl;

	cout << "Top of Stack: " << s.peek() << endl;
	s.push(20);
	cout << "Top of Stack: " << s.peek() << endl;

	cout << "Popping stack: " << s.pop() << endl;
	cout << "Popping stack: " << s.pop() << endl;
	cout << "Popping stack: " << s.pop() << endl;
	cout << "Top of Stack: " << s.peek() << endl;
}