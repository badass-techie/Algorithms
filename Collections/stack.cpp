#include <iostream>
#include "linkedlist.cpp"

using std::cout;
using std::endl;

// A linear collection where items inserted are removed in reverse order (LIFO)
template <typename T>
class Stack {
public:
    LinkedList<T>* storage;

    Stack() {
        this->storage = new LinkedList<T>();
    }

    void push(T data) {
        this->storage->prepend(data);
    }

    T pop() {
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
//     Stack<int> stack;
//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     cout << stack.peek() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     return 0;
// }
