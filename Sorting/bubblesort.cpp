// bubble sort
// time complexity - O(n^2)
// space complexity - O(1)

#include <iostream>

// in bubble sort you iterate the array severally while you swap adjacent elements not in order, till the array is fully sorted
void bubble_sort(int arr[], int n){
    // return value is void - this means we are modifying the array inplace
    int left = 0;
    do{
        for(int i = n-1; i > left; --i){// traverse array
            if (arr[i] < arr[i-1]){     // if adjacent elements are not in order
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;          // swap them
            }
        }
        ++left;                         // discard part of array already sorted
    } while(left < n-1);                // stop when length of unsorted part of array is 0
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, n);
    for(int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    return 0;
}
