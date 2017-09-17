
/*
 * Implementation of a recursive binary search in c++.
 * @author: ArvindRS
 * @date: 09/17/2017
 */

#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

int *get_random_array(int size);

int search(int arr[], int k, int lo, int hi);

int main() {

	int n;
	cout << "Enter the size of the array" << endl;
	cin >> n;

	int *arr = get_random_array(n);
	sort(arr,arr+n);

	for(int i = 0; i < n; i++)
		cout << " " << arr[i];
	cout << endl;

	cout << "Enter the number to search for" << endl;
	int k;
	cin >> k;

	int position = search(arr,k,0,n-1);
	if(position < 0) cout << "Number not found!" << endl;
	else cout << "Number " << k << " found at position " << position << endl;

	return 0;
}

// Function to get an array of pseudo-random numbers
int *get_random_array(int size) {

	int *arr = new int[size];

	srand(time(NULL));

	for(int i = 0; i < size; i++)
		arr[i] = rand() % size;

	return arr;
}

// Function to apply binary search recursively
int search(int arr[], int k, int lo, int hi) {

	if(lo >= hi) return -1;

	int mid = lo + (hi - lo) / 2;

	if(arr[mid] == k)
		return mid;
	else if(arr[mid] > k)
		return search(arr,k,lo,mid);
	else
		return search(arr,k,mid+1,hi);
}