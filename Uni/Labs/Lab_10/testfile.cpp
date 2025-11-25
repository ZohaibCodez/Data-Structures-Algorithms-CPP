#ifndef HASHTABLE
#define HASHTABLE

#include <string>
#include <iostream>

using namespace std;

class HashTable
{
private:
    string *table;
    int S; // Table size
    int n; // Current number of elements
public:
    HashTable(int size)
    {
        this->S = size;
        n = 0;
        table = new string[S];
        for(int i = 0; i < S; i++){
            table[i] = "";
        }
    }
    ~HashTable()
    {
        delete[] table;
    }
    bool isEmpty() // Checks whether the hash table is empty or not
    {
        return (n == 0);
    }
    bool isFull() // Checks whether the hash table is full or not
    {
        return n == S;
    }
    double loadFactor() // Calculates & returns the load factor of the hash table (n/S)
    {
        return double(n) / S;  // FIXED: Cast to double before division
    }
    int getHashValue(string name)
    {
        int i = 0;
        int sum = 0;
        int len = name.length();
        while (i < len)
        {
            sum += int(name[i]);
            i++;
        }
        return sum % S;
    }
    bool insert(string name){
        if(isFull()){  // Check if table is full
            return false;
        }
        
        int location = getHashValue(name);
        int index = location;
        
        // Linear probing to find empty slot
        while(table[index] != ""){
            cout << index;
            index = (index + 1) % S;
            if(index == location){  // Checked all slots, table is full
                return false;
            }
        }
        
        // Insert the name in the empty slot
        table[index] = name;
        n++;
        return true;
    }
    bool search(string name);
    bool remove(string name);
    void display();
};

#endif