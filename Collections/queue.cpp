#include <iostream>
#include <linkedlist.cpp>

using std::cout;
using std::endl;

// A linear collection where items inserted are removed in the same order (FIFO)
class Queue {
public:
    LinkedList* storage;

    Queue(): storage(new LinkedList()) {
    }

    void enqueue(int data) {
        this->storage->append(data);
    }

    int dequeue() {
        return this->storage->delete_first().data;
    }

    int peek() {
        return (*(this->storage))[0];
    }

    void print() {
        this->storage->print();
    }
};

int main(int argc, char const *argv[])
{
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.peek() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    return 0;
}
