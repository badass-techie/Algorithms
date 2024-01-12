#include <iostream>

using std::cout;
using std::endl;

// A list where each element stores a reference to the next element
template <typename T>
class LinkedList {
    class Node {
    public:
        T data;
        Node* next;

        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };

public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void prepend(T data) {
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
    }

    void append(T data) {
        Node* new_node = new Node(data);
        if (this->head == nullptr) {
            this->head = new_node;
        } else {
            Node* current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void insert(T data, int n) {
        Node* new_node = new Node(data);
        if (n == 0) {
            new_node->next = this->head;
            this->head = new_node;
        } else {
            Node* current = this->head;
            int i = 0;
            while (i < n - 1) {
                current = current->next;
                i++;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void delete_at(int n) {
        if (n == 0) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        } else {
            Node* current = this->head;
            int i = 0;
            while (i < n - 1) {
                current = current->next;
                i++;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    Node delete_first() {
        Node* temp = this->head;
        this->head = this->head->next;
        Node deleted = *temp;
        delete temp;
        return deleted;
    }

    bool is_empty() {
        return this->head == nullptr;
    }

    T& operator[](int n) {
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

    void print() {
        Node* current = this->head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// int main(int argc, char const *argv[]){
//     LinkedList<int> list;
//     list.append(1);
//     list.append(2);
//     list.append(3);
//     list.append(4);
//     list.print();
//     list.insert(5, 2);
//     list.print();
//     list.delete_at(2);
//     list.print();
//     for (int i = 0; i < 4; i++) {
//         cout << list[i] << " ";
//     }
//     return 0;
// }
