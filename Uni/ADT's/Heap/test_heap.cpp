#include <iostream>
using namespace std;

#include "heap.h"     // include your heap class here

// Helper to print the heap array
void printHeap(const MinHeap &h)
{
    cout << "Heap: ";
    for (int i = 0; i < h.size(); i++)
    {
        cout << h.get(i) << " ";
    }
    cout << endl;
}

int main()
{
    MinHeap h(4); // height = 4, capacity = 2^4 - 1 = 15

    cout << "=== INSERT TEST ===" << endl;
    h.insert(50);
    h.insert(20);
    h.insert(30);
    h.insert(10);
    h.insert(40);
    h.insert(25);

    printHeap(h);

    cout << "\nMin element: " << h.min() << endl;

    cout << "\n=== EXTRACT MIN TEST ===" << endl;
    cout << "Extracting: " << h.extract_min() << endl;
    printHeap(h);

    cout << "\nExtracting again: " << h.extract_min() << endl;
    printHeap(h);

    cout << "\n=== REMOVE TEST ===" << endl;
    cout << "Removing index 2" << endl;
    h.remove(2);
    printHeap(h);

    cout << "\n=== INCREASE VALUE TEST ===" << endl;
    cout << "Increasing index 1 to 100" << endl;
    h.increase_val(1, 100);
    printHeap(h);

    cout << "\n=== DECREASE VALUE TEST ===" << endl;
    cout << "Decreasing index 3 to 5" << endl;
    h.decrease_val(3, 5);
    printHeap(h);

    cout << "\n=== FINAL EXTRACT ALL ===" << endl;
    while (h.size() > 0)
    {
        cout << h.extract_min() << " ";
    }
    cout << endl;

    return 0;
}
