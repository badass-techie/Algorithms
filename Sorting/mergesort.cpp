// merge sort
// time complexity - O(nlogn)
// space complexity - O(n)

#include <iostream>

// combine two halves
void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;     // size of left temp array
    int n2 = r - m;         // size of right temp  array
    int L[n1], R[n2];       // initialize temp arrays

    // copy data from arr[l..r] to left and right arrays
    for(int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            ++i;
        }
        else{
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // copy the remaining elements of L[], if there are any
    while(i < n1){
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // copy the remaining elements of R[], if there are any
    while(j < n2){
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// half array recursively then call merge
void merge_sort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;    // find middle point
        merge_sort(arr, l, m);       // sort first half
        merge_sort(arr, m + 1, r);   // sort second half
        merge(arr, l, m, r);        // merge the sorted halves
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0, n-1);
    for(int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    return 0;
}
