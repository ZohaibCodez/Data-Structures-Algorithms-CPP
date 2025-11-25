#include <iostream>
#include "HashTable.cpp"

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of a table: " << endl;
    cin >> n;
    HashTable table(n);
    int choice;

    while (true)
    {
        cout << "1. Insert a name" << endl;
        cout << "2. Search for a name" << endl;
        cout << "3. Remove a name" << endl;
        cout << "4. Display the Hash Table \n5. Display Load Factor of the table\n6. Exit\n" << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        if (choice == 1)
        {
            string name;
            cout << "Enter a name: " << endl;
            cin >> name;
            table.insert(name);
        }
        else if (choice == 2)
        {
            string name;
            cout << "Enter a name: " << endl;
            cin >> name;
            table.search(name);
        }
        else if (choice == 3)
        {
            string name;
            cout << "Enter a name: " << endl;
            cin >> name;
            table.remove(name);
        }
        else if (choice == 4)
        {
            table.display();
        }
        else if (choice == 5)
        {
            table.loadFactor();
        }
        else if (choice == 6)
        {
            break;
        }
    }
}