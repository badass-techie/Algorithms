// selection sort - O(n^2)

#include <iostream>

// helper to find minimum element in array using linear search
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

void selection_sort(int arr[], int n){
    int left = 0;
    do{
        int min_index = left + argmin(arr + left, n - left);   // slice array by applying an offset of 'left' to the pointer and size

        if (min_index != left){
            int temp = arr[left];
            arr[left] = arr[min_index];
            arr[min_index] = temp;
        }
        ++left;
    } while(left < n-1);
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    for(int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    return 0;
}
