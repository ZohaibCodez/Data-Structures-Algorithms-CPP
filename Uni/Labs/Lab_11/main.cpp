#include "Task_01.cpp"
#include <iostream>
using namespace std;

int main()
{
    StudentBST st;
    int choice;

    while (true)
    {
        cout << "1. Insert a new student" << endl;
        cout << "2. Search for a student " << endl;
        cout << "3. See the list of students" << endl;
        cout << "4. Delete a node" << endl;
        cout << "5. Display required CGPA Students" << endl;
        cout << "6. Quit\n"
             << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        if (choice == 1)
        {
            string name;
            int rollNumber;
            double cgpa;
            cout << "Enter a rollNumber: " << endl;
            cin >> rollNumber;
            cout << "Enter a name: " << endl;
            cin >> name;
            cout << "Enter a cgpa: " << endl;
            cin >> cgpa;
            st.insert(rollNumber, name, cgpa);
        }
        else if (choice == 2)
        {
            int rollNumber;
            cout << "Enter a rollNumber: " << endl;
            cin >> rollNumber;
            st.search(rollNumber);
        }
        else if (choice == 3)
        {
            st.InOrder();
        }
        else if (choice == 4)
        {
            int rollNumber;
            cout << "Enter a rollNumber: " << endl;
            cin >> rollNumber;
            st.remove(rollNumber);
        }
        else if (choice == 5)
        {
            double cgpa_start, cgpa_end;
            cout << "Enter Starting cgpa: " << endl;
            cin >> cgpa_start;
            cout << "Enter Ending cgpa: " << endl;
            cin >> cgpa_end;
            st.displayInRange(cgpa_start, cgpa_end);
        }
        else if (choice == 6)
        {
            break;
        }
    }
}