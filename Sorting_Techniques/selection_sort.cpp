// Selection sorting technique

#include <iostream>
#include <vector>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(std::vector<int> &arr, int n){
    int min_index;
    for (int i = 0; i < n; i++){
        min_index = i;
        for (int j = i + 1; j < n; j++){
            if (arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

int main(){
    std::vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    selection_sort(arr, n);
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}
