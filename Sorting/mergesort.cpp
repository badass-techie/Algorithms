// merge sort
// time complexity - O(nlogn)
// space complexity - O(n)

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void printarr(int* start, int length){
        for(int i = 0; i < length; ++i)
            cout<<*(start+i)<<" ";
        cout<<endl;
}

// splits an array into 2 halves then merges the halves back into the array in order
void merge(int arr[], int l, int m, int r){
    // split array into halves
    vector<int> left_half(arr + l, arr + m + 1);
    vector<int> right_half(arr + m + 1, arr + r + 1);

    // merge the halves back into arr[l..r]
    int i = 0, j = 0, k = l;
    while(i < left_half.size() && j < right_half.size()){
        if (left_half[i] <= right_half[j]){
            arr[k] = left_half[i];
            ++i;
            ++k;
        }
        else{
            arr[k] = right_half[j];
            ++j;
            ++k;
        }
    }

    // copy leftover elements of left_half[] if any
    while(i < left_half.size()){
        arr[k] = left_half[i];
        ++i;
        ++k;
    }

    // copy leftover elements of right_half[] if any
    while(j < right_half.size()){
        arr[k] = right_half[j];
        ++j;
        ++k;
    }
}

// mergesort is an algorithm that sorts a list by recursively splitting it into halves, 
// then merging back the halves such that elements are in order
// 
// (the only purpose of this function is recursion - it does not do anything on its own)
void merge_sort(int arr[], int l, int r){
    if (l < r){                     // if length of array on this level is greater than 1
        int m = l + (r - l) / 2;    // find middle point

        // run merge_sort() recursively on children
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);        // merge array on this level
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0, n-1);
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
