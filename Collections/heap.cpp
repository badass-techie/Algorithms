#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> storage; // storage

    // return parent index of the node at i
    int parent(int i) { 
        return (i - 1) / 2; 
    }

    // return the left child index of the node at i
    int left(int i) { 
        return (2 * i + 1); 
    }

    // return the right child index of the node at i
    int right(int i) { 
        return (2 * i + 2); 
    }

    // Function to heapify the node at index i up the tree
    void heapify_up(int i) {
        if (i > 0 && storage[parent(i)] > storage[i]) {   // if node at index i and its parent violate the heap property
            std::swap(storage[i], storage[parent(i)]);    // swap them
            heapify_up(parent(i));  //heapify up on parent
        }
    }

    // Function to heapify the node at index i down the tree
    void heapify_down(int i) {
        // Get left and right child of node at index i
        int l = left(i);
        int r = right(i);

        // find the smallest between the node and its left and right child
        int smallest = i;

        if (l < storage.size() && storage[l] < storage[i])
            smallest = l;

        if (r < storage.size() && storage[r] < storage[smallest])
            smallest = r;

        // if either child is smaller and the heap property is violated
        if (smallest != i) {
            std::swap(storage[i], storage[smallest]); // swap with parent
            heapify_down(smallest);     // heapify down on smaller child
        }
    }

public:
    // insert
    void push(int key) {
        storage.push_back(key); // Insert at the end
        int index = storage.size() - 1;
        heapify_up(index); // Heapify the new node up to its correct position
    }

    // pop
    int pop() {
        if (storage.size() == 0){
            std::cout << "Heap is empty";
            return -1;
        }

        int top = storage.front();
        storage[0] = storage.back(); // Replace the root of the heap with the last element of the vector
        storage.pop_back(); // Remove the last element

        heapify_down(0); // Heapify the new root down to its correct position

        return top;
    }

    // peek
    int peek() {
        if (storage.size() == 0){
            std::cout << "Heap is empty";
            return -1;
        }

        return storage.front();
    }
};

int main() {
    Heap heap;

    heap.push(3);
    heap.push(2);
    heap.push(15);

    std::cout << heap.pop() << "\n"; // 2
    std::cout << heap.pop() << "\n"; // 3

    heap.push(5);
    heap.push(4);
    heap.push(45);

    std::cout << heap.pop() << "\n"; // 4
    std::cout << heap.pop() << "\n"; // 5
    std::cout << heap.pop() << "\n"; // 15
    std::cout << heap.pop() << "\n"; // 45

    return 0;
}
