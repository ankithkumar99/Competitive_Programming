// Quick sort algorithm
// Note : see explanation below the code

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last){
    int pivot = first;
    int i, j = first;
    
    for (int i = first + 1; i <= last; i++){
        if (arr[i] <= arr[pivot]){
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[pivot]);
    return j;
}

void quick_sort(int arr[], int l, int r){
    // base condition
    if (l >= r){
        return;
    }
    
    int m = partition(arr, l, r);
    // now arr[m] is in final position and
    // left to mth element are less than arr[m]
    // right to mth element are greater or equal compared to arr[m]
    
    // then apply same procedure to left and right
    // subarrays recursively
    quick_sort(arr, l, m - 1);
    quick_sort(arr, m + 1, r);
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
    int arr[] = { 6 , 4 , 8 , 2 , 9 , 3 , 9 , 4 , 7 , 6 , 1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, 0, arr_size-1);
	printArray(arr, arr_size);
    return 0;
}


/**********************************************************************************

Explanation

arr = { 6 , 4 , 8 , 2 , 9 , 3 , 9 , 4 , 7 , 6 , 1 }

1)  pivot = p = 6       pivot is first element
    i = first + 1       i checks every element with pivot
    j = first           when i reaches last, j will be the final position of pivot
    
    1)  p
        6   4   8   2   9   3   9   4   7   6   1
        j   i
        check : a[i] <= a[p] -> true
                j++
                swap(a[i], a[j])
                i++
    
    2)  p
        6   4   8   2   9   3   9   4   7   6   1
        j       i
        check : a[i] <= a[p] -> false
                i++
        
    3)  p
        6   4   8   2   9   3   9   4   7   6   1
            j       i
        check : a[i] <= a[p] -> true
                j++
                swap(a[i], a[j])
                i++
        
    4)  p
        6   4   2   8   9   3   9   4   7   6   1
                j       i
        check : a[i] <= a[p] -> false
                i++
                
    5)  p
        6   4   2   8   9   3   9   4   7   6   1
                j           i
        check : a[i] <= a[p] -> true
                j++
                swap(a[i], a[j])
                i++
                
    6)  p
        6   4   2   3   9   8   9   4   7   6   1
                    j           i
        check : a[i] <= a[p] -> false
                i++
                
    7)  p
        6   4   2   3   9   8   9   4   7   6   1
                    j               i
        check : a[i] <= a[p] -> true
                j++
                swap(a[i], a[j])
                i++
                
    8)  p
        6   4   2   3   4   8   9   9   7   6   1
                        j               i
        check : a[i] <= a[p] -> false
                i++
                
    9)  p
        6   4   2   3   4   8   9   9   7   6   1
                        j                   i
        check : a[i] <= a[p] -> true
                j++
                swap(a[i], a[j])
                i++
                
    10) p
        6   4   2   3   4   6   9   9   7   8   1
                            j                   i
        check : a[i] <= a[p] -> true
                j++
                swap(a[i], a[j])
                i++
    
    after i reaches last, we get
    
    p
    6   4   2   3   4   6   1   9   7   8   9
                            j               i
    
    we swap p with j
    1   4   2   3   4   6   6   9   7   8   9
    [                   ]<= p < [           ]
        first                     second
    
    then we repeat same process for first and second subarrays recursively
    
**********************************************************************************/
