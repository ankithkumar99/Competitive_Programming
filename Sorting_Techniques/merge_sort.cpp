// Merge Sort 

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> arr, int first, int mid, int last){

}

void merge_sort(vector<int> arr, int first, int last){
    if(first < last){
        int mid = ( first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid+1, last);
        merge(arr, first, mid, last);
    }    
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    vector<int> arr1;
    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}