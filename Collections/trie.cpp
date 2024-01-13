#include <iostream>

using std::cout;
using std::endl;
using std::string;

class TrieNode {
public:
    bool endOfWord;
    TrieNode* children[26];
    
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        endOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) // if the node doesn't exist
                curr->children[c - 'a'] = new TrieNode();   // create a new node
            curr = curr->children[c - 'a']; // move to the next node
        }
        curr->endOfWord = true; // mark the last node as the end of the word
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) // if the node doesn't exist
                return false;   // the word doesn't exist
            curr = curr->children[c - 'a']; // move to the next node
        }
        return curr->endOfWord; // return true if the last node is the end of the word
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children[c - 'a'] == nullptr) // if the node doesn't exist
                return false;   // the prefix doesn't exist
            curr = curr->children[c - 'a']; // move to the next node
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // returns true
    cout << trie->search("app") << endl;     // returns false
    cout << trie->startsWith("app") << endl; // returns true
    trie->insert("app");
    cout << trie->search("app") << endl;     // returns true
    return 0;
}
