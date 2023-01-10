#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::vector;
using std::endl;

class HashTableEntry{
    public:
        string key;
        int value;

        HashTableEntry(string k, int v): key(k), value(v){
        }
};

/* 
  A collection of a fixed size that uses a hash function to map keys to indexes where values are stored.
  This allows for constant time access to the values, unless there are collisions (entries with same hash value),
  in which case a linear search is performed across the collisions
*/
class HashTable{
    private: 
        vector<HashTableEntry> *table; //the table has two dimensions
                                // the first dimension is for hash values 0-n and the second is for collisions (entries with same hash value)
        int size;               //size of the table
                                
    public:
        HashTable(int size){
            table = new vector<HashTableEntry>[size];     //create an array of pointers to HashTableEntry objects
            this->size = size;
        }

        int hash_value(string key){
            int hash = 0;
            for(char c: key)
                hash = hash + (int)c;

            return hash % size;                   //return the hash value
        }

        void put(string key, int value){
            int hash = hash_value(key);           //get the hash value
            for (HashTableEntry entry : table[hash]) {  // perform linear search across collisions
                if (entry.key == key) {
                    entry.value = value;          //update the value if the key already exists
                    return;
                }
            }
            table[hash].push_back(HashTableEntry(key, value)); //create a new entry and add it to the table
        }

        int get(string key){
            int hash = hash_value(key);           //get the hash value
            
            for (HashTableEntry entry : table[hash]) {  // perform linear search across collisions
                if (entry.key == key) {
                    return entry.value;
                }
            }

            return -1;                            //return -1 if the key is not found
        }

        void remove(string key){
            int hash = hash_value(key);           //get the hash value
            
            for (int i = 0; i < table[hash].size(); i++) {  // perform linear search across collisions
                if (table[hash][i].key == key) {
                    table[hash].erase(table[hash].begin() + i); //remove the entry
                    return;
                }
            }
        }

        // overload << operator to print contents
        friend std::ostream& operator<<(std::ostream& os, const HashTable& ht){
            cout<< "Hash Table Contents: " << endl;
            for (int i = 0; i < ht.size; i++) {
                os << i << ":\t";
                for (HashTableEntry entry : ht.table[i]) {
                    os << entry.key << ":" << entry.value << ", ";
                }
                os << endl;
            }
            return os;
        }

        ~HashTable(){
            delete[] table;
        }
};

int main(int argc, char const *argv[]){
    HashTable ht(5);

    // add values
    ht.put("one", 1);
    ht.put("two", 2);
    ht.put("three", 3);
    ht.put("four", 4);
    ht.put("five", 5);
    ht.put("six", 6);
    ht.put("seven", 7);
    ht.put("eight", 8);
    ht.put("nine", 9);
    ht.put("ten", 10);

    // print contents
    cout << ht << endl;

    // get values
    cout << "one: " << ht.get("one") << endl;
    cout << "two: " << ht.get("two") << endl;
    cout << "three: " << ht.get("three") << endl;
    cout << "four: " << ht.get("four") << endl;
    cout << "five: " << ht.get("five") << endl;
    cout << "six: " << ht.get("six") << endl;
    cout << "seven: " << ht.get("seven") << endl;
    cout << "eight: " << ht.get("eight") << endl;
    cout << "nine: " << ht.get("nine") << endl;
    cout << "ten: " << ht.get("ten") << endl;

    // remove some values
    ht.remove("four");
    ht.remove("six");
    ht.remove("ten");

    // print contents again
    cout << ht << endl;

    return 0;
}
