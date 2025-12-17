#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include <iostream>
#include <cmath>
using namespace std;

class Student
{
public:
    double cgpa; // Student’s CGPA
    int rollNo;  // Student’s roll number
    Student()
    {
        cgpa = 0.0;
        rollNo = 0;
    }
    Student(int r, double c)
    {
        rollNo = r;
        cgpa = c;
    }
};

class StudentMaxHeap
{
private:
    Student *st;  // Array of students which will be arranged like a Max Heap
    int currSize; // Current number of students present in the heap
    int maxSize;  // Maximum number of students that can be present in the heap

public:
    // bool removeBestStudent(int &rollNo, double &cgpa);
    StudentMaxHeap(int size) // Constructor
    {
        maxSize = size;
        currSize = 0;
        st = new Student[int(pow(2, maxSize)) - 1];
    }
    ~StudentMaxHeap() // Destructor
    {
        delete[] st;
    }
    bool isEmpty() // Checks whether the heap is empty or not
    {
        return (currSize == 0);
    }
    bool isFull() // Checks whether the heap is full or not
    {
        return maxSize == currSize;
    }

    void heapifyUp(int index)
    {
        while (index != 0 && st[index].cgpa > st[(index - 1) / 2].cgpa)
        {
            swap(st[index], st[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < currSize && st[left].cgpa > st[largest].cgpa)
        {
            largest = left;
        }

        if (right < currSize && st[right].cgpa > st[largest].cgpa)
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(st[i], st[largest]);
            heapifyDown(largest);
        }
    }

    bool isGreater(const Student &a, const Student &b)
    {
        return a.cgpa > b.cgpa;
    }
    bool insert(int rollNo, double cgpa)
    {
        Student newStudent(rollNo, cgpa);
        if (currSize < (pow(2, maxSize) - 1))
        {
            st[currSize] = newStudent;
            currSize++;
            int i = currSize - 1;
            while (i != 0 && st[i].cgpa > st[(i - 1) / 2].cgpa)
            {
                for (int i = 1; i < currSize; i++)
                {
                    if (st[i].cgpa == st[i - 1].cgpa && (st[i].rollNo > st[i - 1].rollNo))
                    {
                        swap(st[i], st[i - 1]);
                    }
                }
                swap(st[i], st[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            return true;
        }
        return false;
    }

    bool removeBestStudent(int &rollNo, double &cgpa)
    {
        rollNo = st[0].rollNo;
        cgpa = st[0].cgpa;
        st[0] = st[currSize - 1];
        currSize--;

        heapifyDown(0);
        return true;
    }

    // bool remove(int i)
    // {
    //     if (i >= currSize)
    //     {
    //         return false;
    //     }
    //     st[i] = st[currSize - 1];
    //     currSize--;

    //     heapifyDown(i);
    //     return true;
    // }

    void levelOrder()
    {
        cout << "Level-order: ";
        for (int i = 0; i < currSize; i++)
        {
            cout << "RollNo: " << st[i].rollNo << ", CGPA: " << st[i].cgpa;
            cout << endl;
        }
    }

    int height()
    {
        int maxHeight = -1;

        for (int i = 0; i < currSize; i++)
        {
            int level = floor(log2(i + 1));
            if (level > maxHeight)
            {
                maxHeight = level;
            }
        }

        return (maxHeight == -1 ? 0 : maxHeight + 1);
    }
};

#endif