// selection sort 
// time complexity - O(n^2)
// space complexity - O(1)

#include <iostream>

// helper to find index of minimum element in array using linear search
int argmin(int arr[], int n){
    int min = arr[0];
    int min_index = 0;
    for(int i = 1; i < n; ++i){
        if (arr[i] < min){
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

// in selection sort you swap the minimum element of the array with the left element till the array is fully sorted
void selection_sort(int arr[], int n){
    int left = 0;
    do{
        int min_index = left + argmin(arr + left, n - left);   // slice array by applying an offset of 'left' to the pointer and size

        if (min_index != left){     // if minimum element is not at the left
            int temp = arr[left];
            arr[left] = arr[min_index];
            arr[min_index] = temp;  // swap the minimum and left element
        }
        ++left;                     // discard part of array already sorted
    } while(left < n-1);            // stop when length of unsorted part of array is 0
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    for(int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    return 0;
}
