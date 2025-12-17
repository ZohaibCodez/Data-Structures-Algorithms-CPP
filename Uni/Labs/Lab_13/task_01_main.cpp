#include <iostream>
#include "Task_01.h"
using namespace std;

int main()
{
    StudentMaxHeap heap(20);
    // ---- Add multiple sample students ----
    heap.insert(10, 3.2);
    heap.insert(5, 3.9);
    heap.insert(12, 3.5);
    heap.insert(3, 3.9); // Same CGPA as roll 5 (tie-break: smallerroll first)
    heap.insert(7, 2.8);
    heap.insert(18, 3.7);
    heap.insert(1, 4.0); // Highest CGPA
    heap.insert(20, 3.4);
    heap.insert(11, 3.7); // Same CGPA as roll 18 (tie-break)
    heap.insert(4, 3.8);
    cout << "===== Level Order After Insertions =====\n";
    heap.levelOrder();
    cout << endl;
    cout << "\nHeight of the heap: " << heap.height() << endl;
    // ---- Remove top student twice ----
    int roll;
    double cg;
    if (heap.removeBestStudent(roll, cg))
    {
        cout << "Removed Student - Roll No: " << roll
             << ", CGPA: " << cg << endl;
    }
    if (heap.removeBestStudent(roll, cg))
    {
        cout << "Removed Student - Roll No: " << roll
             << ", CGPA: " << cg << endl;
    }
    cout << "\n===== Level Order After Two Removals =====\n";
    heap.levelOrder();
    cout << "\nHeight of the heap: " << heap.height() << endl;
    return 0;
}