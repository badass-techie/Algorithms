// quick sort
// time complexity: O(nlogn)
// space complexity: O(logn)

#include <iostream>

using std::cout;

// helper to swap values of two variables
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// places the pivot at its correct position, smaller elements to its left, and larger elements to its right
int partition(int arr[], int low, int high) {
    // the goal is to swap the item from left that is larger than the pivot,
    // with the item from right that is smaller than the pivot,
    // as we traverse the array in both directions,
    // until the indices of the left and right items intersect,
    // at which point we swap the left item with the pivot
    // and return the new index of the pivot

    int pivot = arr[high];              // choose the last element as pivot (can be any element)
    int left_idx = low, right_idx = high - 1;   // initialize left and right indices

    while (left_idx <= right_idx) {
        if (arr[left_idx] <= pivot) {
            left_idx++;
        } else if (arr[right_idx] > pivot) {
            right_idx--;
        } else {
            // if the item from left is larger than pivot,
            // and the item from right is smaller than pivot,
            swap(arr[left_idx], arr[right_idx]);    // swap the two items
            left_idx++;
            right_idx--;
        }
    }
    swap(arr[left_idx], arr[high]);    // swap the pivot with the left item
    return left_idx;        // return the new index of the pivot
}

// quicksort is an algorithm that recursively partitions an array according to a 'pivot',
// moves elements greater than the pivot to its right, and elements less than the pivot to its left
void quick_sort(int arr[], int low, int high) {
    if (low < high) {                           // if length of array on this level is greater than 1
        int pi = partition(arr, low, high);    // partition array on this level

        // run quick_sort() recursively on children
        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
