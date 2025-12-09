#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cmath>
using namespace std;

class MinHeap
{
private:
    int *data;
    int height;
    int no_of_elements;

public:
    MinHeap(int _height)
    {
        height = _height;
        no_of_elements = 0;
        data = new int[int(pow(2, height)) - 1];
    }
    void insert(int v)
    {
        if (no_of_elements < (pow(2, height) - 1))
        {
            data[no_of_elements] = v;
            no_of_elements++;
            int i = no_of_elements - 1;
            while (i != 0 && data[i] < data[(i - 1) / 2])
            {
                swap(data[i], data[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }
    }

    void createHeap()
    {
        int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
        int i;
        for (i = 0; i < 8; i++)
        {
            insert(A[i]);
        }
    }

    void heapify_down(int i)
    {
        while (i < no_of_elements)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int min = i;

            if (left < no_of_elements && data[left] < data[min])
            {
                min = left;
            }

            if (right < no_of_elements && data[right] < data[min])
            {
                min = right;
            }

            if (min == i)
            {
                break;
            }

            swap(data[i], data[min]);

            i = min;
        }
    }

    int min()
    {
        if (no_of_elements == 0)
        {
            throw runtime_error("Heap is Empty");
        }

        return data[0];
    }

    int extract_min()
    {
        if (no_of_elements == 0)
        {
            throw runtime_error("Heap is Empty");
        }

        int min_value = data[0];

        data[0] = data[no_of_elements - 1];
        no_of_elements--;

        heapify_down(0);

        return min_value;
    }

    void remove(int i)
    {
        if (i >= no_of_elements)
        {
            return;
        }
        data[i] = data[no_of_elements - 1];
        no_of_elements--;

        heapify_down(i);
    }

    void increase_val(int i, int new_value)
    {
        if (i >= no_of_elements)
            return;
        data[i] = new_value;
        heapify_down(i);
    }

    void decrease_val(int i, int new_value)
    {
        if (i >= no_of_elements)
            return;
        data[i] = new_value;

        while (i > 0 && data[i] < data[(i - 1) / 2])
        {
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int size() const
    {
        return no_of_elements;
    }

    int get(int i) const
    {
        return data[i];
    }
};

#endif