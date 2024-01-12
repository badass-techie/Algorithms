#include <iostream>

using std::cout;
using std::endl;


class BST {
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

private:
    Node* max_value_node(Node* current) {   // pass by value (copy)
        while (current->right != nullptr) {
            current = current->right;   // loop down to find the rightmost leaf
        }
        return current;
    }

public:
    Node* root;

    BST() {
        this->root = nullptr;
    }

    // insert
    Node* insert(Node*& current, int data) {
        if (current == nullptr) {
            this->root = new Node(data);  // base case (encountered a leaf node)
        } else if (data < current->data) {
            if (current->left == nullptr) {
                current->left = new Node(data);
            } else {
                current->left = insert(current->left, data);  // recursive case (move to left)
            }
        } else if (data > current->data) {
            if (current->right == nullptr) {
                current->right = new Node(data);
            } else {
                current->right = insert(current->right, data);    // recursive case (move to right)
            }
        } else {
            cout << "Duplicate data: " << data << endl;
        }
        return current;
    }

    // search
    bool search(int data) {
        Node* current = this->root;
        while (current != nullptr) {
            if (data == current->data) {
                // if data is equal to current node, then return true
                return true;
            } else if (data < current->data) {
                // if data is less than current node, then move to left
                current = current->left;
            } else {
                // if data is greater than current node, then move to right
                current = current->right;
            }
        }
        return false;
    }

    // delete
    void delete_node(Node*& current, int data) {
        if (current == nullptr)
            return; // base case (encountered a leaf node)
        else if (data < current->data)
            delete_node(current->left, data);  // recursive case (move to left)
        else if (data > current->data)
            delete_node(current->right, data); // recursive case (move to right)
        else {  // found the node to be deleted
            // case 1: no children
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                current = nullptr;
            }
            // case 2: one child
            else if (current->left == nullptr) {
                Node* temp = current;
                current = current->right; // promote the right child
                delete temp;    // delete the old current
            } else if (current->right == nullptr) {
                Node* temp = current;
                current = current->left;  // promote the left child
                delete temp;    // delete the old current
            }
            // case 3: two children
            else {
                Node* temp = max_value_node(current->left);   // promote the largest node of the left subtree
                current->data = temp->data;
                delete_node(current->left, temp->data);   // delete the node that was in its place
            }
        }
    }

    // inorder traversal using recursion
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // print
    void print() {
        cout << "Inorder: ";
        inorder(this->root);
        cout << endl << endl;
    }

    // destructor
    ~BST() {
        delete this->root;
    }

};

int main(){
    BST bst;
    bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.print();
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);
    bst.print();
    bst.delete_node(bst.root, 20);
    bst.print();
    bst.delete_node(bst.root, 30);
    bst.print();
    bst.delete_node(bst.root, 50);
    bst.print();
    cout << "Found 50: " << bst.search(50) << endl;
    cout << "Found 60: " << bst.search(60) << endl;
    return 0;
}
