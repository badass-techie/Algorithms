#include <iostream>
#include <linkedlist.cpp>

using std::cout;
using std::endl;

class Stack {
public:
    LinkedList* storage;

    Stack() {
        this->storage = new LinkedList();
    }

    void push(int data) {
        this->storage->prepend(data);
    }

    int pop() {
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
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.peek() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}
