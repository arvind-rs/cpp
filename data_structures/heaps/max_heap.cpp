
/*
 * Max heap implementation in c++.
 * @author: ArvindRS
 * @date: 09/22/2017
 */

#include <iostream>

using namespace std;

class MaxHeap {

private:
	int *heap;
	int size;
	int N;

public:
	// Public constructor
	MaxHeap() {
		heap = new int[1];
		size = 1;
		N = 0;
	}

	// Function to check if heap is empty
	bool is_empty() {
		return N == 0;
	}

	// Function to insert an element
	void insert(int data) {
		// If the array is full, resize the array
		if(N == size) resize(2 * size);
		heap[++N] = data;
		swim(N);
	}

	// Function to delete the max element
	int delete_max() {
		int data = heap[1];
		swap(1,N);
		// Set the previous Nth position as invalid
		heap[N--] = NULL;
		sink(1);
		// Resize the array if only 1/4th of the capacity is being used
		if(N > 0 && N == size / 4) resize(size / 2);
		return data;
	}

	// Function to display the heap
	void display() {
		for(int i = 1; i <= N; i++)
			cout << " " << heap[i];
		cout << endl;
	}

	// Function to get the max element
	int get_max() {
		return heap[1];
	}

private:
	// Function to percolate the data up to it's rightful position
	void swim(int k) {
		while(k / 2 > 0 && heap[k / 2] < heap[k]) {
			swap(k,k / 2);
			k = k / 2;
		}
	}

	// Function to percolate the data down to it's rightful position
	void sink(int k) {
		while(2 * k <= N) {
			int j = 2 * k;
			if(j < N && heap[j] < heap[j+1]) j++;
			if(heap[k] > heap[j]) break;
			swap(k,j);
			k = j;
		}
	}

	// Function to swap elements in two array positions
	void swap(int i, int j) {
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}

	// Function to resize the array
	void resize(int capacity) {
		int *copy = new int[capacity];
		for(int i = 0; i <= N; i++)
			copy[i] = heap[i];
		heap = copy;
		size = capacity;
	}
};

int main() {

	MaxHeap heap;

	cout << "is_empty:" << heap.is_empty() << endl;
	heap.insert(5);
	heap.insert(15);
	heap.insert(20);
	heap.insert(10);
	cout << "max element: " << heap.get_max() << endl;
	heap.display();
	cout << "delete max: " << heap.delete_max() << endl;
	heap.display();
	cout << "delete max: " << heap.delete_max() << endl;
	heap.display();
	cout << "delete max: " << heap.delete_max() << endl;
	heap.display();
}