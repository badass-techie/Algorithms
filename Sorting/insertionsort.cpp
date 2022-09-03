// insertion sort 
// time complexity - O(n^2)
// space complexity - O(1)

#include <iostream>

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        // shift elements to the right till we find the correct position for key
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        
        arr[j+1] = key; // insert key at the correct position
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, n);
    for(int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    return 0;
}
