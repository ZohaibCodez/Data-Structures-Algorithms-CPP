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
        for (int i = 0; i < S; i++)
        {
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
        return double(n / S);
    }
    int getHashValue(string name)
    {
        int i = 0;
        int sum = 0;
        int len = name.length();
        while (i < len)
        {
            // cout << name[i] << " ";
            sum += int(name[i]);
            // cout << sum;
            i++;
        }
        return sum % S;
    }
    bool insert(string name)
    {
        if (isFull())
        {
            cout << "table is full" << endl;
            return false;
        }
        int location = getHashValue(name);
        int index = location;
        // cout << index;
        // cout << table[index];
        // if(table[index] != ""){
        //     table[index] = name;
        //     n++;
        //     return true;
        // }
        while (table[index] != "")
        {
            // cout << table[index];
            cout << index << "->";
            index = (index + 1) % S;
            if (index == location)
            {
                return false;
            }
        }
        table[index] = name;
        // cout << table[index];
        n++;
        return true;
    }
    bool search(string name){
        int location = getHashValue(name);
        int index = location;
        while(table[index] != ""){
            cout << index << "->";
            index = (index+1) % S;
            if(table[index] == name){
                return true;
            }
            if(index == location){
                return false;
            }
        }
        return false;
    }
    bool remove(string name){
        if(isEmpty()){
            return false;
        }
        int location = getHashValue(name);
        int index = location;
        while(table[index] != ""){
            cout << index << "->";
            index = (index+1) % S;
            if(table[index] == name){
                table[index] = "";
                n--;
                return true;
            }
            if(index == location){
                return false;
            }
        }
        return false;
    }
    void display(){
        for(int i = 0; i < S;i++){
            if(table[i] == ""){
                cout << i << "->";
                cout << "Empty" << endl;
                continue;
            }
            cout << i << "->";
            cout << table[i] << endl;
        }
    }
};

#endif