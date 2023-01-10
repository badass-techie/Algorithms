// binary search 
// time complexity - O(log n)
// space complexity - O(1)

#include <iostream>

// in binary search you split a presorted array in 2 halves,
// keep the half whose range covers the search element and discard the other half,
// and repeat until the element is found or the length of the array is 1
int binarySearch(int arr[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)  // while length of arr between l and r is greater than 1
    {
        int mid = l + (r - l) / 2;  // find the center of the array
        if (arr[mid] == x)          // if arr[mid] is x return
            return mid;
        if (arr[mid] < x)           // if arr[mid] is less than x discard left portion of arr by moving l to mid
            l = mid + 1;
        else                        // if arr[mid] is greater than x discard right portion of arr by moving r to mid
            r = mid - 1;            
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    std::cout << "Enter the number to be searched: ";
    std::cin >> x;
    int result = binarySearch(arr, n, x);
    if (result == -1)
        std::cout << "Element not found";
    else
        std::cout << "Element found at index " << result;
    return 0;
}
