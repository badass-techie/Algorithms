// bubble sort - O(n^2)

#include <iostream>

void bubble_sort(int arr[], int n){
    // return value is void - this means we are modifying the array inplace
    int left = 0;
    do{
        for(int i = n-1; i > left; --i){
            if (arr[i] < arr[i-1]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            }
        }
        ++left;
    } while(left < n-1);
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, n);
    for(int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    return 0;
}
