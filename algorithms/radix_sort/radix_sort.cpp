
/*
 * Radix Sort implementation in c++.
 * @author: ArvindRS
 * @date: 09/20/2017
 */

#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Function declaration
void sort(int a[], int size);
int get_max_number_digit_count(int a[], int size);
int get_kth_digit(int number, int k);
void display(int a[], int size);

// Main function
int main() {

	// Test cases
	int test1_n = 10;
	int test1_a[] = {1234, 34, 179, 826, 256, 108, 329, 244, 621, 233, 402};
	sort(test1_a, test1_n);
	display(test1_a, test1_n);
}

// Function to apply the Radix sort algorithm
void sort(int a[], int size) {

	// Get the k value
	int k = get_max_number_digit_count(a,size);

	// Declare an array of queues of size 10
	queue<int> q[10];

	// For each k value, add the numbers to the array queues and dequeue them in order
	for(int i = 1; i <= k; i++) {

		// For each number in the input array, get the kth digit and add the number to the list corresponding to the digit
		for(int j = 0; j < size; j++) {
			int digit = get_kth_digit(a[j],i);
			q[digit].push(a[j]);
		}

		// Dequeue the numbers from the list in order and copy them to the array
		int j = 0;
		for(int l = 0; l < 10; l++) {
			while(q[l].size() > 0) {
				a[j++] = q[l].front();
				q[l].pop();
			}
		}
	}
}

// Function to get the k value
int get_max_number_digit_count(int a[], int size) {
	// Find the biggest number in the input array
	int max = 0;
	for(int i = 0; i < size; i++) {
		if(a[i] > max)
			max = a[i];
	}

	// Count the number of digits in the biggest number in the input array
	int k = 0;
	while(max > 0) {
		max /= 10;
		k++;
	}

	return k;
}

// Function to get the kth digit of a number
int get_kth_digit(int number, int k) {

	int digit = 0;
	while(k > 0) {
		digit = number % 10;
		number /= 10;
		k--;
	}

	return digit;
}

// Function to display an array
void display(int a[] ,int size) {
	for(int i = 0; i < size; i++)
		cout << " " << a[i];
	cout << endl;
}