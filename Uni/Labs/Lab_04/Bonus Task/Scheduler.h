#ifndef SCHEDULAR_H
#define SCHEDULAR_H

#include "Process.h"
#include "..\..\..\ADT's\Queue\Queue.h"

using namespace std;

class Scheduler
{
private:
    Queue<Process> q;
    int timeQuantum;

public:
    Scheduler(Process arr[], int len, int tq)
    {
        for (int i = 0; i < len; i++)
        {
            Process p(arr[i].getId(), arr[i].getName(), arr[i].getExecutionTime());

            this->q.enqueue(p);
        }
        this->timeQuantum = tq;
    }
    void assignProcessor()
    {
        while (!q.isEmpty())
        {
            Process p = q.dequeue();
            cout << "Executing process " << p.getName() << " for " << timeQuantum << " units" << endl;
            int slice = timeQuantum;
            while (slice > 0 && p.getExecutionTime() > 0)
            {
                p.setExecutionTime(p.getExecutionTime() - 1);
                slice--;
            }
            if (p.getExecutionTime() > 0)
            {
                q.enqueue(p);
            }
            else
            {
                // cout << p.getName() << ", completed execution" << endl;
            }
        }
    }
};

#endif