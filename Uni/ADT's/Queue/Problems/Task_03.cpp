#include <iostream>
#include "..\Queue.h"
#include "..\..\Stack\Stack.h"

using namespace std;

int hungryStudents(int students[], int sandwiches[])
{
    int counter = 0;
    Queue<int> students_queue(sizeof(students) / sizeof(students[0]));
    Stack<int> sandwiches_stack(sizeof(students) / sizeof(students[0]));
}

int main()
{
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    return 0;
}