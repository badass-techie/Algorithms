#include <iostream>

using std::cout;
using std::endl;


class Node {
public:
    int data;
    Node* previous, * next;

    Node(int data) {
        this->data = data;
        this->previous = nullptr;
        this->next = nullptr;
    }
};

// A list where each element stores a reference to the next and previous elements
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        this->head = nullptr;
    }

    // append the list
    void append(int data) {
        Node* new_node = new Node(data);
        if (this->head == nullptr) {
            // if list is empty i.e head is null
            this->head = new_node; // then head is new node
        } else {
            // otherwise move to the last element
            Node* current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }

            // then set 'next' of last element to point to new node
            current->next = new_node;
            current->next->previous = current;
        }
    }

    // insert at position n
    void insert(int data, int n) {
        Node* new_node = new Node(data);
        if (n == 0) {
            // if n is 0, then insert new node before head
            new_node->next = this->head;
            this->head = new_node;
        } else {
            // otherwise move to the nth element
            Node* current = this->head;
            int i = 0;
            while (i < n - 1) {
                current = current->next;
                i++;
            }

            // then insert new node after current node
            new_node->next = current->next;
            new_node->next->previous = new_node;
            new_node->previous = current;
            current->next = new_node;
        }
    }

    // delete at position n
    void delete_at(int n) {
        if (n == 0) {
            // if n is 0, then set head to next node and delete previous head
            Node* temp = this->head;
            this->head = this->head->next;
            this->head->previous = nullptr;
            delete temp;
        } else {
            // otherwise move to the nth element
            Node* current = this->head;
            int i = 0;
            while (i < n - 1) {
                current = current->next;
                i++;
            }

            // then delete current node
            Node* temp = current->next;
            current->next = current->next->next;
            current->next->previous = current;
            delete temp;
        }
    }

    //get data at position n with subscript operator
    int& operator[](int n) {
        Node* current = this->head;
        int i = 0;
        while (i < n) {
            current = current->next;
            i++;
        }
        if (current == nullptr)
            throw std::runtime_error("Index out of bounds");
        return current->data;
    }

    // print elements
    void print() {
        Node* current = this->head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // print elements in reverse
    void print_reverse() {
        Node* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->previous;
        }
        cout << endl;
    }
};


int main(int argc, char const *argv[])
{
    DoublyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.print();
    list.print_reverse();
    list.insert(5, 2);
    list.print();
    list.print_reverse();
    list.delete_at(2);
    list.print();
    list.print_reverse();
    for (int i = 0; i < 4; i++) {
        cout << list[i] << " ";
    }
    return 0;
}
