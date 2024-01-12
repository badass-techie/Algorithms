#include <iostream>
#include "heap.cpp"

void heapsort(std::vector<int>& arr) {
    Heap heap;

    // insert all array elements into a heap
    for (int i = 0; i < arr.size(); i++)
        heap.push(arr[i]);

    // remove the smallest elements from the heap one by one and insert into the array
    for (int i = 0; i < arr.size(); i++)
        arr[i] = heap.pop();
}

int main() {
    std::vector<int> arr = {5, 1, 4, 2, 8};
    heapsort(arr);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " "; // 1 2 4 5 8
    }
    
    return 0;
}
