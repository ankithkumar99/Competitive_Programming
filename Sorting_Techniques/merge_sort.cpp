// Merge Sort 

#include <iostream>
using namespace std;

// this function combines 2 subarrays
// first array is L[first...(mid-1)]
// second array is R[mid...last]
void merge(int arr[], int first, int mid, int last){
	int n1 = mid - first + 1;	// size of first array
	int n2 = last - mid;		// size of second array

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[first + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	// Merge the temp arrays back into arr[first...last]

	// Initial index of L array
	int i = 0;

	// Initial index of R array
	int j = 0;

	// Initial index of merged(arr) array
	int k = first;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// first is for first index and last is
// last index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int first,int last){
	if(first >= last){
		return;//returns recursively
	}
	int mid = (first + last -1)/2;
	mergeSort(arr, first, mid);
	mergeSort(arr, mid + 1, last);
	merge(arr, first, mid, last);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is :\t";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is :\t";
	printArray(arr, arr_size);
	return 0;
}