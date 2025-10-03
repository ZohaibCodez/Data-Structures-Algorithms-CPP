#include <iostream>
#include "..\..\ADT's\Queue\Queue.h"
using namespace std;

int timeRequiredToBuy(int tickets[], int n, int k)
{
    Queue<int> q;
    for (int i = 0; i < n; ++i)
        q.enqueue(i);

    int time = 0;
    while (!q.isEmpty())
    {
        int idx = q.queueFront();
        q.dequeue();
        if (tickets[idx] > 0)
        {
            tickets[idx]--;
            time++;
            if (idx == k && tickets[idx] == 0)
                return time;
            if (tickets[idx] > 0)                       
                q.enqueue(idx);
        }
    }
    return time;
}

int main()
{
    int tickets1[] = {3,5,3,7};
    int n1 = 4, k1 = 2;
    cout << timeRequiredToBuy(tickets1, n1, k1) << endl;

    int tickets2[] = {5, 1, 1, 1};
    int n2 = 4, k2 = 0;
    cout << timeRequiredToBuy(tickets2, n2, k2) << endl;

    return 0;
}