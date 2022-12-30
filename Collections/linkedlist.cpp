#include <iostream>

using std::cout;
using std::endl;


class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    // prepend the list
    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
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
            current->next = new_node;
        }
    }

    // delete at position n
    void delete_at(int n) {
        if (n == 0) {
            // if n is 0, then set head to next node and delete previous head
            Node* temp = this->head;
            this->head = this->head->next;
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
            delete temp;
        }
    }

    // delete first
    Node delete_first() {
        Node* temp = this->head;
        this->head = this->head->next;
        Node deleted = *temp;
        delete temp;
        return deleted;
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
};


int main(int argc, char const *argv[])
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.print();
    list.insert(5, 2);
    list.print();
    list.delete_at(2);
    list.print();
    for (int i = 0; i < 4; i++) {
        cout << list[i] << " ";
    }
    return 0;
}
