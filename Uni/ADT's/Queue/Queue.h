#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T *data;
    int capacity;
    int noOfElement;
    int front;
    int rear;

public:
    // Parameterized Constructor
    Queue(int c = 10)
    {
        if (c > 0)
        {
            this->capacity = c;
            this->noOfElement = 0;
            data = new T[capacity];
            front = 0;
            rear = -1;
        }
        else
        {
            throw invalid_argument("Capacity must be greater than 0");
        }
    }
    // Copy Constructor
    Queue(const Queue &other)
    {
        this->capacity = other.capacity;
        this->noOfElement = other.noOfElement;
        this->front = other.front;
        this->rear = other.rear;
        this->data = new T[this->capacity];
        for (int i = 0; i < noOfElement; i++)
        {
            this->data[i] = other.data[i];
        }
    }
    // Assignment Operator
    Queue &operator=(const Queue &other)
    {
        if (this != &other)
        {
            delete[] data;
            this->capacity = other.capacity;
            this->noOfElement = other.noOfElement;
            this->front = other.front;
            this->rear = other.rear;
            this->data = new T[this->capacity];
            for (int i = 0; i < noOfElement; i++)
            {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    }
    // Check if full
    bool isFull()
    {
        return noOfElement == capacity;
    }
    // Check if empty
    bool isEmpty()
    {
        return noOfElement == 0;
    }
    // Enqueue
    void enqueue(T value)
    {
        if (!isFull())
        {
            rear = (rear + 1) % capacity;
            data[rear] = value;
            noOfElement++;
        }
        else
        {
            throw out_of_range("Queue is full");
        }
    }
    // Dequeue
    T dequeue()
    {
        if (!isEmpty())
        {
            T e = data[front];
            front = (front + 1) % capacity;
            noOfElement--;
            return e;
        }
        else
        {
            throw underflow_error("Queue is empty");
        }
    }

    // Get current size
    int getSize()
    {
        return noOfElement;
    }

    // Get front element
    T queueFront()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is empty");
        }
        return data[front];
    }

    // Get rear element
    T queueRear()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is empty");
        }
        return data[rear];
    }

    // Destructor
    ~Queue()
    {
        delete[] data;
    }
};

#endif