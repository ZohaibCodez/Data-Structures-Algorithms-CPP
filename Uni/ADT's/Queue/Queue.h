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
    int count;
    int front;
    int rear;

public:
    // Default Constructor
    Queue()
    {
        capacity = 100;
        data = new T[capacity];
        count = 0;
        front = 0;
        rear = -1;
    }

    // Parameterized Constructor
    Queue(int size)
    {
        if (size > 0)
        {
            this->capacity = size;
            data = new T[capacity];
            count = 0;
            front = 0;
            rear = -1;
        }
        else
        {
            exit(0);
        }
    }

    // Copy Constructor
    Queue(const Queue &other)
    {
        this->capacity = other.capacity;
        this->count = other.count;
        this->front = other.front;
        this->rear = other.rear;
        this->data = new T[this->capacity];
        for (int i = 0; i <= capacity; i++)
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
            this->count = other.count;
            this->front = other.front;
            this->rear = other.rear;
            this->data = new T[this->capacity];
            for (int i = 0; i <= capacity; i++)
            {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    }

    void enqueue(T value)
    {
        if (this->isFull())
        {
            throw overflow_error("Queue Overflow");
        }
        this->data[++this->rear] = value;
        this->count++;
    }

    T dequeue()
    {
        if (this->isEmpty())
        {
            throw underflow_error("Queue Underflow");
        }
        this->count--;
        return this->data[this->front++];
    }

    bool isFull()
    {
        return (this->count == this->capacity);
    }

    bool isEmpty()
    {
        return this->count == 0;
    }

    int getSize()
    {
        return this->count;
    }

    T queueFront()
    {
        return this->data[this->front];
    }

    T queueRear()
    {
        return this->data[this->rear];
    }

    // Destructor
    ~Queue()
    {
        delete[] data;
    }
};

#endif