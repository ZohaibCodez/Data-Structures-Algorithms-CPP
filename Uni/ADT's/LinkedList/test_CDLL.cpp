#include "CDLL.h"
#include <iostream>

using namespace std;

int main()
{
    // CDLinkedList<int> list;
    // list.insertAtHead(2);
    // list.insertAtHead(3);
    // list.insertAtTail(10);
    // list.insertAtTail(20);
    // list.insertAtTail(30);
    // list.insertAtTail(40);
    // cout << "Deleting tail...\n";
    // list.removeAtTail();
    // cout << "After 1 deletion: ";
    // list.displayList();
    // cout << endl;
    // cout << "Deleting tail again...\n";
    // list.removeAtTail();
    // cout << "After 2 deletions: ";
    // list.displayList();
    // cout << endl;
    // cout << "Deleting remaining...\n";
    // list.removeAtTail();
    // list.removeAtTail();
    // cout << "After deleting all nodes:\n";
    // list.displayList();
    // cout << endl;

    // CDLinkedList<int> list;
    // cout << "Removing from empty list...";
    // list.remove(10);
    // list.displayList();
    // cout << endl;
    // list.insertAtTail(10);
    // cout << "Before removing single element:";
    // list.displayList();
    // cout << endl;

    // list.remove(10);
    // cout << "After removing single element:";
    // list.displayList();
    // cout << endl;
    // list.insertAtTail(10);
    // list.insertAtTail(20);
    // list.insertAtTail(30);

    // cout << "Before removing head (10):";
    // list.displayList();
    // cout << endl;

    // list.remove(10);
    // cout << "After removing head: ";
    // list.displayList();
    // cout << endl;

    // cout << "Before removing tail (30): ";
    // list.displayList();
    // cout << endl;

    // list.remove(30);
    // cout << "After removing tail: ";
    // list.displayList();
    // cout << endl;

    // list.insertAtTail(30);
    // list.insertAtTail(40);
    // list.insertAtTail(50);

    // cout << "Before removing middle (40): ";
    // list.displayList();
    // cout << endl;

    // list.remove(40);
    // cout << "After removing middle (40): ";
    // list.displayList();
    // cout << endl;

    // cout << "Before removing non-existent (99): ";
    // list.displayList();
    // cout << endl;

    // list.remove(99);
    // cout << "After removing non-existent: ";
    // list.displayList();
    // cout << endl;

    // cout << "Removing all remaining elements...";
    // list.remove(20);
    // list.remove(30);
    // list.remove(50);
    // list.displayList();
    // cout << endl;

    // CDLinkedList<int> list;
    // cout << "Searching in empty list (10): " << list.search(10) << endl;

    // list.insertAtTail(5);
    // cout << "Searching for 5 (present): " << list.search(5) << endl;

    // cout << "Searching for 10 (absent): " << list.search(10) << endl;

    // list.insertAtTail(10);
    // list.insertAtTail(15);
    // list.insertAtTail(20);
    // cout << "Searching for 15 (present): " << list.search(15) << endl;

    // cout << "Searching for 20 (present at tail): " << list.search(20) << endl;

    // cout << "Searching for 99 (absent): " << list.search(99) << endl;

    // list.remove(10);
    // cout << "Searching for 10 after removal: " << list.search(10) << endl;

    // CDLinkedList<int> list;

    // cout << "Case 1: Updating in empty list (10 → 99)\n";
    // list.update(10, 99);
    // list.displayList();
    // cout << endl;

    // cout << "Case 2: Single node update (10 → 99)\n";
    // list.insertAtTail(10);
    // cout << "Before: ";
    // list.displayList();
    // cout << endl;

    // list.update(10, 99);
    // cout << "After:  ";
    // list.displayList();
    // cout << endl;

    // cout << "Case 3: Single node update (key not found)\n";
    // list.update(55, 77);
    // list.displayList();
    // cout << endl;

    // cout << "Case 4: Multi-node list (20 → 200)\n";
    // list.insertAtTail(20);
    // list.insertAtTail(30);
    // cout << "Before: ";
    // list.displayList();
    // cout << endl;

    // list.update(20, 200);
    // cout << "After:  ";
    // list.displayList();
    // cout << endl;

    // cout << "Case 5: Update head (99 → 11)\n";
    // list.update(99, 11);
    // list.displayList();
    // cout << endl;

    // cout << "Case 6: Update tail (30 → 333)\n";
    // list.update(30, 333);
    // list.displayList();
    // cout << endl;

    // cout << "Case 7: Non-existent key (500 → 9)\n";
    // list.update(500, 9);
    // list.displayList();
    // cout << endl;

    CDLinkedList<int> list;

    // 1️⃣ Empty list
    cout << "Case 1: Empty list" << endl;
    cout << "Count: " << list.countNodes() << endl; // Expected: 0
    cout << "----------------------" << endl;

    // 2️⃣ Single node
    list.insertAtTail(10);
    cout << "Case 2: Single node (10)" << endl;
    list.displayList();                               // Expected: 10
    cout << "\nCount: " << list.countNodes() << endl; // Expected: 1
    cout << "----------------------" << endl;

    // 3️⃣ Multiple nodes
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    cout << "Case 3: Multiple nodes (10 20 30 40)" << endl;
    list.displayList();
    cout << "\nCount: " << list.countNodes() << endl; // Expected: 4
    cout << "----------------------" << endl;

    // 4️⃣ After deleting one node
    list.remove(20);
    cout << "Case 4: After removing one (10 30 40)" << endl;
    list.displayList();
    cout << "\nCount: " << list.countNodes() << endl; // Expected: 3
    cout << "----------------------" << endl;

    // 5️⃣ After clearing the list
    list.remove(10);
    list.remove(30);
    list.remove(40);
    cout << "Case 5: After clearing all nodes" << endl;
    list.displayList();                               // Expected: (empty)
    cout << "\nCount: " << list.countNodes() << endl; // Expected: 0
    cout << "----------------------" << endl;

    return 0;
}