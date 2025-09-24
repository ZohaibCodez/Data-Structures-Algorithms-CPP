#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr)
{
    int i;
    cout << "Elements are " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return 0;
}

int LinearSearch(Array *arr, int key)
{
    int i = 0;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

int LinearSearch_Transposition(Array *arr, int key)
{
    int i = 0;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            int temp = arr->A[i - 1];
            arr->A[i - 1] = arr->A[i];
            arr->A[i] = temp;
            return i;
        }
    }
    return -1;
}

int BinarySearch(Array *arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr->length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr->A[mid])
            return mid;
        if (key < arr->A[mid])
            high = mid - 1;
        if (key > arr->A[mid])
            low = mid + 1;
    }
    return -1;
}

int RBinSearch(int arr[], int low, int high, int key)
{
    int mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        if (key < arr[mid])
            return RBinSearch(arr, low, mid - 1, key);
        else
            return RBinSearch(arr, mid + 1, high, key);
    }

    return -1;
}

int Get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

int Max(Array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(Array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(Array arr)
{
    int s = 0;
    int i;
    for (int i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}

float Avg(Array arr)
{
    return float(Sum(arr) / arr.length);
}

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B = new int[arr->length];
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void InsertSort(Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = x = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void ReArrange(struct Array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] > 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    Array arr = {{2, -3, 25, 10, -15, -7}, 20, 6};

    // Append(&arr, 10);
    // Insert(&arr, -2, 9);
    // Delete(&arr, 1);
    // cout << LinearSearch(&arr, 4) << endl;
    // cout << LinearSearch_Transposition(&arr, 4) << endl;
    // cout << BinarySearch(&arr, 6) << endl;
    // cout << RBinSearch(arr.A, 0, arr.length, 20) << endl;
    // cout << Get(arr, 1) << endl;
    // Set(&arr, 1, 15);
    // cout << Max(arr) << endl;
    // cout << Min(arr) << endl;
    // cout << Sum(arr) << endl;
    // cout << Avg(arr) << endl;
    // Reverse(&arr);
    // Reverse2(&arr);
    // InsertSort(&arr, 4);
    // cout << isSorted(arr) << endl;
    ReArrange(&arr);
    Display(arr);

    return 0;
}