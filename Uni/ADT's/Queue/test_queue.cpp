#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

void testBasicOperations()
{
    cout << "=== Test 1: Basic Operations ===" << endl;
    Queue<int> q(5);

    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.queueFront() << endl;
    cout << "Rear element: " << q.queueRear() << endl;
    cout << "Size: " << q.getSize() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front after dequeues: " << q.queueFront() << endl;
    cout << endl;
}

void testCircularBehavior()
{
    cout << "=== Test 2: Circular Array Behavior ===" << endl;
    Queue<int> q(4); // Can hold 3 elements (4-1)

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Queue full? " << (q.isFull() ? "Yes" : "No") << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    // Now add more to test wrap-around
    q.enqueue(4);
    q.enqueue(5);

    cout << "After circular wrap:" << endl;
    cout << "Front: " << q.queueFront() << endl;
    cout << "Rear: " << q.queueRear() << endl;
    cout << endl;
}

void testOverflowUnderflow()
{
    cout << "=== Test 3: Overflow and Underflow ===" << endl;
    Queue<int> q(3); // Can hold 2 elements

    try
    {
        q.enqueue(100);
        q.enqueue(200);
        cout << "Enqueued 2 elements successfully" << endl;
        q.enqueue(300); // This should throw overflow
    }
    catch (const overflow_error &e)
    {
        cout << "Caught overflow: " << e.what() << endl;
    }

    try
    {
        q.dequeue();
        q.dequeue();
        cout << "Dequeued 2 elements successfully" << endl;
        q.dequeue(); // This should throw underflow
    }
    catch (const underflow_error &e)
    {
        cout << "Caught underflow: " << e.what() << endl;
    }
    cout << endl;
}

void testCopyConstructor()
{
    cout << "=== Test 4: Copy Constructor ===" << endl;
    Queue<int> q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    Queue<int> q2(q1);

    cout << "Original queue front: " << q1.queueFront() << endl;
    cout << "Copied queue front: " << q2.queueFront() << endl;

    q1.dequeue();
    cout << "After dequeue from original:" << endl;
    cout << "Original front: " << q1.queueFront() << endl;
    cout << "Copied front (should be unchanged): " << q2.queueFront() << endl;
    cout << endl;
}

void testAssignmentOperator()
{
    cout << "=== Test 5: Assignment Operator ===" << endl;
    Queue<int> q1(5);
    q1.enqueue(100);
    q1.enqueue(200);

    Queue<int> q2(3);
    q2 = q1;

    cout << "Assigned queue front: " << q2.queueFront() << endl;
    cout << "Assigned queue size: " << q2.getSize() << endl;

    // Test self-assignment
    q1 = q1;
    cout << "Self-assignment successful" << endl;
    cout << endl;
}

void testStringQueue()
{
    cout << "=== Test 6: Queue with Strings ===" << endl;
    Queue<string> q(5);

    q.enqueue("Hello");
    q.enqueue("World");
    q.enqueue("Queue");

    cout << "Front: " << q.queueFront() << endl;
    cout << "Rear: " << q.queueRear() << endl;

    while (!q.isEmpty())
    {
        cout << "Dequeued: " << q.dequeue() << endl;
    }
    cout << "Queue is now empty" << endl;
    cout << endl;
}

void testDefaultConstructor()
{
    cout << "=== Test 7: Default Constructor ===" << endl;
    Queue<int> q; // Default capacity = 100

    for (int i = 1; i <= 10; i++)
    {
        q.enqueue(i * 10);
    }

    cout << "Enqueued 10 elements in default queue" << endl;
    cout << "Front: " << q.queueFront() << endl;
    cout << "Rear: " << q.queueRear() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << endl;
}

void testFullCycle()
{
    cout << "=== Test 8: Full Enqueue-Dequeue Cycle ===" << endl;
    Queue<int> q(6);

    cout << "Enqueuing 5 elements..." << endl;
    for (int i = 1; i <= 5; i++)
    {
        q.enqueue(i);
        cout << i << " ";
    }
    cout << endl;

    cout << "Dequeuing all elements..." << endl;
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << endl;
}

int main()
{
    cout << "========== QUEUE CLASS TESTING ==========" << endl
         << endl;

    testBasicOperations();
    testCircularBehavior();
    testOverflowUnderflow();
    testCopyConstructor();
    testAssignmentOperator();
    testStringQueue();
    testDefaultConstructor();
    testFullCycle();

    cout << "========== ALL TESTS COMPLETED ==========" << endl;

    return 0;
}