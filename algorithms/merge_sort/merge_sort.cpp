
/*
 * Merge Sort implementation in c++.
 * @author: ArvindRS
 * @date: 09/20/2017
 */

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// Function to merge the sorted sub-arrays into one array
void merge(int a[], int size, int aux[], int aux_size, int lo, int mid, int hi) {

	for(int k = lo; k <= hi; k++) {
		aux[k] = a[k];
	}

	int i = lo, j = mid + 1;
	for(int k = lo; k <= hi; k++) {
		if(i > mid) a[k] = aux[j++]; // If i index is out of bounds, trivially copy the elements from j index
		else if(j > hi) a[k] = aux[i++]; // If j index is out of bounds, trivially copy the elements from i index
		else if(aux[i] < aux[j]) a[k] = aux[i++];
		else if(aux[j] < aux[i]) a[k] = aux[j++];
		else a[k] = aux[i++];
	}
}

// Function to recursively sort by dividing the array into two parts
void sort(int a[], int size, int aux[], int aux_size, int lo, int hi) {

	if(lo < hi) {
		int mid = lo + (hi - lo) / 2;
		sort(a,size,aux,aux_size,lo,mid);
		sort(a,size,aux,aux_size,mid+1,hi);
		merge(a,size,aux,aux_size,lo,mid,hi);
	}
}


// Wrapper function
void merge_sort(int a[], int size) {

	int aux[size];
	sort(a,size,aux,size,0,size -1);
}

// Function to display the array on the console
void display(int a[], int size) {
	for(int i = 0; i < size; i++)
		cout << " " << a[i];
	cout << endl;
}

// Function to generate an array of random numbers
int *random_array_generator(int size) {
	int *a = new int[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		a[i] = (rand() % size);
	return a;
}

int main() {

	// Test cases
	int a[] = {5,3,4,2};
	merge_sort(a,4);
	display(a,4);

	int s1 = 10;
	int *a1 = random_array_generator(s1);
	merge_sort(a1,s1);
	display(a1,s1);
}