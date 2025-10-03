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
    Scheduler(Process arr[], int len, int tq);
    void assignProcessor()
};

#endif