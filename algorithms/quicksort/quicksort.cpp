
/*
 * QuickSort implementation in c++.
 * @author: ArvindRS
 * @date: 09/20/2017
 */

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// Function to get an array of random numbers
int *get_random_array(int size) {
	int *a = new int[size];
	srand(time(NULL)); // seed the random number generator
	for(int i = 0; i < size; i++)
		a[i] = (rand() % size);
	return a;
}

// Helper function to swap two numbers in an array
void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// Function to sort each partition
int partition(int a[], int lo, int hi) {

	// Here lo is the pivot
	int i = lo, j = hi + 1;
	while(true) {
		while(a[++i] < a[lo]) 
			if(i == hi) break;
		while(a[lo] < a[--j])
			if(j == lo) break;
		if(i >= j) break;
		swap(a,i,j);
	}

	// Move the pivot to it's position in the end
	swap(a,lo,j);

	return j;
}

// Function to apply QuickSort
int sort(int a[], int lo, int hi) {

	if(lo < hi) {
		int pivot = partition(a,lo,hi);
		sort(a,lo,pivot-1);
		sort(a,pivot+1,hi);
	}
}

// Helper function to display an array
void display(int a[], int size) {
	for(int i = 0; i < size; i++)
		cout << " " << a[i];
	cout << endl;
}

// Main function
int main() {

	int test1_n = 10;
	int *test1_a = get_random_array(test1_n);
	sort(test1_a,0,test1_n-1);
	display(test1_a,test1_n);
}