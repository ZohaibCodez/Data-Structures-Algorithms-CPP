#include "Task_02.cpp"
#include <iostream>
using namespace std;

int main()
{
    BST st;
    int choice;

    while (true)
    {
        cout << "1. Insert a new node" << endl;
        cout << "2. Search for a node " << endl;
        cout << "3. See the list of nodes" << endl;
        cout << "4. Delete a node" << endl;
        cout << "5. Double the tree" << endl;
        cout << "6. Quit\n"
             << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int number;
            cout << "Enter a Number: " << endl;
            cin >> number;
            st.insert(number);
        }
        else if (choice == 2)
        {
            int number;
            cout << "Enter a Number: " << endl;
            cin >> number;
            st.search(number);
        }
        else if (choice == 3)
        {
            st.inOrder();
        }
        else if (choice == 4)
        {
            int number;
            cout << "Enter a Number: " << endl;
            cin >> number;
            st.deleteMethod(number);
        }
        else if (choice == 5)
        {
            st.doubleTree();
        }
        else if (choice == 6)
        {
            break;
        }
    }
}