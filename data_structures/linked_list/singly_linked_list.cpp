
/*
 * C++ implementation of the singly linked list.
 * @author: ArvindRS
 * @date: 09/17/2017
 */

#include <iostream>
#include <algorithm>
using namespace std;

class List {

private:
	class Node {
	public:
		int data;
		Node *next;
	};

public:
	// Data member
	Node *head;
	// Constructor
	List() {
		head = NULL;
	}

	// Member function to test if the list is empty
	bool is_empty() {
		return head == NULL;
	}

	// Member function to insert an element to the list
	void insert(int data) {
		// Need to explicitly allocate memory here else a segmentation fault occurs
		Node *temp = new Node();

		temp->data = data;
		temp->next = head;
		head = temp;
	}

	// Member function to display the list
	void print() {
		Node *current = head;
		while(current != NULL) {
			cout << " " << current->data;
			current = current->next;
		}
		cout << endl;
	}

	// Member function to search for an element
	int search(int data) {
		Node *current = head;
		int position = -1;
		while(current != NULL) {
			position++;
			if(current->data == data)
				break;
			current = current->next;
		}
		if(current == NULL)
			return -1;
		return position;
	}

	// Member function to delete an element
	void delete_element(int data) {
		if(is_empty()) {
			cout << "List is empty!\n";
			return;
		}
		Node *current = head;
		Node *previous = NULL;
		while(current != NULL && current->data != data) {
			previous = current;
			current = current->next;
		}
		if(current == NULL) {
			cout << "Data not found:" << data << endl;
			return;
		}

		if(previous == NULL) {
			// This means we are deleting the head node
			head = current->next;
		}
		else {
			previous->next = current->next;
		}
		delete current;
	}
};

int main() {

	List list;

	cout << list.is_empty() << endl;

	// Adding elements to the list
	list.insert(5);
	list.insert(10);
	list.insert(15);
	list.print();

	int find = 20;
	cout << "Element "<< find<<" found at position " << list.search(find) << endl;

	list.delete_element(10);
	list.print();
	list.delete_element(20);
	list.insert(20);
	list.print();
	list.delete_element(20);
	list.print();
}