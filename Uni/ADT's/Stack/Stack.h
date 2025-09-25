#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T *data;
    int capacity;
    int top;

public:
    // Default Constructor
    Stack()
    {
        capacity = 100;
        data = new T[this->capacity];
        top = -1;
    }
    // Parameterized Constructor
    Stack(int size)
    {
        if (size > 0)
        {
            this->capacity = size;
            data = new T[this->capacity];
            top = -1;
        }
        else
            exit(0);
    }

    // Copy Constructor
    Stack(const Stack &other)
    {
        this->capacity = other.capacity;
        this->top = other.top;
        this->data = new T[this->capacity];
        for (int i = 0; i <= top; i++)
        {
            this->data[i] = other.data[i];
        }
    }

    // Assignment Operator
    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            delete[] data;
            this->capacity = other.capacity;
            this->top = other.top;
            this->data = new T[this->capacity];
            for (int i = 0; i <= top; i++)
            {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push(T value)
    {
        if (this->isFull())
        {
            throw overflow_error("Stack Overflow");
        }
        this->data[++this->top] = value;
    }

    T pop()
    {
        if (this->isEmpty())
        {
            throw underflow_error("Stack Underflow");
        }
        return this->data[this->top--];
    }

    bool isFull()
    {
        return (this->top == this->capacity - 1);
    }

    bool isEmpty()
    {
        return (this->top == -1);
    }

    int getTop()
    {
        return this->top;
    }

    T stackTop()
    {
        return this->data[top];
    }

    // Destructor
    ~Stack()
    {
        delete[] data;
    }
};

#endif