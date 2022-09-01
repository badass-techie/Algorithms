// binary search - O(log n)

#include <iostream>


int binarySearch(int arr[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
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
