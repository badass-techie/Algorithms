#include <iostream>
#include "linkedlist.cpp"

using std::cout;
using std::endl;

// A linear collection where items inserted are removed in the same order (FIFO)
template <typename T>
class Queue {
public:
    LinkedList<T>* storage;

    Queue(): storage(new LinkedList<T>()) {
    }

    void enqueue(T data) {
        this->storage->append(data);
    }

    T dequeue() {
        return this->storage->delete_first().data;
    }

    T peek() {
        return (*(this->storage))[0];
    }

    bool is_empty() {
        return this->storage->is_empty();
    }

    void print() {
        this->storage->print();
    }
};

// int main(int argc, char const *argv[])
// {
//     Queue<int> queue;
//     queue.enqueue(1);
//     queue.enqueue(2);
//     queue.enqueue(3);
//     cout << queue.peek() << endl;
//     cout << queue.dequeue() << endl;
//     cout << queue.dequeue() << endl;
//     cout << queue.dequeue() << endl;
//     return 0;
// }
