
/*
 * A Queue implementation in c++ using a list structure.
 * @author: ArvindRS
 * @date: 09/19/2017
 */

#include <iostream>
using namespace std;

class Queue {

private:
	// Inner class for the Node object
	class Node {
	public:
		int data;
		Node *next;
	};

	// Sentinel variables
	Node *front, *back;
public:
	// Public constructor
	Queue() {
		front = back = NULL;
	}

	// List of member functions
	// Function to check if the queue is empty
	bool is_empty() {
		return (front == NULL);
	}

	// Function to enqueue
	void enqueue(int data) {
		Node *temp = new Node();
		temp->data = data;
		if(front == NULL) {
			temp->next = NULL;
			back = front = temp;
		}
		else {
			temp->next = back;
			back = temp;
		}
	}

	// Function to dequeue
	int dequeue() {
		if(is_empty()) {
			cout << "Error! queue is empty!" << endl;
			return -1;
		}
		Node *current = back;
		Node *previous = NULL;
		while(current != front) {
			previous = current;
			current = current->next;
		}
		int data = current->data;
		if(previous == NULL) {
			front = back = NULL;
		}
		else {
			previous->next = NULL;
			front = previous;
		}
		delete current;
		return data;
	}

	// Function to display the contents of the queue
	void display() {
		Node *current = back;
		while(current != NULL) {
			cout << " " << current->data;
			current = current->next;
		}
		cout << endl;
	}
};

int main() {

	// Creating the queue object
	Queue q;

	cout << "Is the queue empty? " << q.is_empty() << endl;

	// Enqueuing items to the queue
	q.enqueue(5);
	q.enqueue(10);
	q.enqueue(15);
	cout << "Is the queue empty? " << q.is_empty() << endl;

	// Display the queue
	q.display();

	q.enqueue(20);

	// Display the queue
	q.display();

	// Dequeuing items
	cout << "Dequeue: " << q.dequeue() << endl;
	// Display the queue
	q.display();
	cout << "Dequeue: " << q.dequeue() << endl;
	cout << "Dequeue: " << q.dequeue() << endl;
	cout << "Dequeue: " << q.dequeue() << endl;
}