#include <iostream>
#include "queue.cpp"
// #include "stack.cpp"

using std::cout;
using std::endl;


template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
class BinaryTree {
public:
    Node<T>* root;

    BinaryTree() {
        this->root = nullptr;
    }

    // preorder traversal using recursion
    void preorder(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // inorder traversal using recursion
    void inorder(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // postorder traversal using recursion
    void postorder(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // breadth first search
    void bfs() {
        if (this->root == nullptr) {
            return;
        }
        Node<T>* current = this->root;
        Queue<Node<T>*> queue;
        queue.enqueue(current);
        while (!queue.is_empty()) {
            current = queue.peek();
            cout << current->data << " ";
            queue.dequeue();
            if (current->left != nullptr) {
                queue.enqueue(current->left);
            }
            if (current->right != nullptr) {
                queue.enqueue(current->right);
            }
        }
    }

    // alternative implementation for depth first search (preorder)
    // void dfs() {
    //     if (this->root == nullptr) {
    //         return;
    //     }
    //     Node<T>* current = this->root;
    //     Stack<Node<T>*> stack;
    //     stack.push(current);
    //     while (!stack.is_empty()) {
    //         current = stack.peek();
    //         stack.pop();
    //         cout << current->data << " ";
    //         if (current->right != nullptr) {
    //             stack.push(current->right);
    //         }
    //         if (current->left != nullptr) {
    //             stack.push(current->left);
    //         }
    //     }
    // }

    // print
    void print() {
        cout << "Inorder: ";
        inorder(this->root);
        cout << endl;
        cout << "Preorder: ";
        preorder(this->root);
        cout << endl;
        cout << "Postorder: ";
        postorder(this->root);
        cout << endl;
    }

    // destructor
    ~BinaryTree() {
        delete this->root;
    }
};

// reverse the tree
template <typename T>
void reverse_tree(Node<T>* node) {
    // base case of recursion
    if (node == nullptr) {
        return;
    }

    // swap left and right children of this node
    Node<T>* temp = node->left;
    node->left = node->right;
    node->right = temp;

    // recursively reverse left and right subtrees
    reverse_tree(node->left);
    reverse_tree(node->right);
}

int main(){
    BinaryTree<int> tree;
    tree.root = new Node<int>(1);
    tree.root->left = new Node<int>(2);
    tree.root->right = new Node<int>(3);
    tree.root->left->left = new Node<int>(4);
    tree.root->left->right = new Node<int>(5);
    tree.root->right->left = new Node<int>(6);
    tree.root->right->right = new Node<int>(7);
    tree.print();
    cout << "BFS: ";
    tree.bfs();
    cout << endl << endl;

    cout << "Reversed: " << endl;
    reverse_tree(tree.root);
    tree.print();
    return 0;
}
