#include <iostream>
#include "heap.cpp"

class PriorityQueue {
private:
    Heap heap;

public:
    // insert
    void push(int key) {
        heap.push(key);
    }

    // delete
    void pop() {
        heap.pop();
    }

    // get the top element
    int peek() {
        return heap.peek();
    }
};

int main() {
    return 0;
}
