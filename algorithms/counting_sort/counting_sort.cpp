
/*
 * Counting sort implementation in c++.
 * @author: ArvindRS
 * @date: 09/20/2017
 */

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// Function declarations
int *get_random_array(int size);
void sort(int a[], int size);
void display(int a[], int size);

// Main function
int main() {

	// Test cases
	int test1_n = 10;
	int *test1_a = get_random_array(test1_n);
	sort(test1_a,test1_n);
	display(test1_a,test1_n);
}

// Function to apply counting sort on the array
void sort(int a[], int size) {

	// Find the max element in the input array
	int max = 0;
	for(int i = 0; i < size; i++) {
		if(a[i] > max)
			max = a[i];
	}

	// Create a bucket array of size: max + 1
	int *buckets = new int[max + 1];

	// Initialize the buckets to 0
	for(int i = 0; i < max +1; i++)
		buckets[i] = 0;

	// For each number in the array, increment the corresponding bucket value
	for(int i = 0; i < size; i++) {
		buckets[a[i]]++;
	}

	// Now for each bucket value, write it back to the array
	int i, j;
	for(i = j = 0; i < max + 1; i++) {
		while(buckets[i] > 0) {
			buckets[i]--;
			a[j++] = i;
		}
	}
}

// Function to display the array
void display(int a[], int size) {
	for(int i = 0; i < size; i++)
		cout << " " << a[i];
	cout << endl;
}


// Function to create an array of random numbers of the given size
int *get_random_array(int size) {
	int *a = new int[size];
	// Seed the random number generator
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		a[i] = rand() % size;
	return a;
}