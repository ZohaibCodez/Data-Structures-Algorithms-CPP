#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>

using namespace std;

class Process
{
private:
    int processId;
    string processName;
    int executionTime;

public:
    Process()
    {
        processId = 0;
        processName = "";
        executionTime = 0;
    }

    Process(int id, string name, int time)
    {
        this->processId = id;
        this->processName = name;
        this->executionTime = time;
    }

    int getId()
    {
        return this->processId;
    }
    string getName()
    {
        return this->processName;
    }
    int getExecutionTime()
    {
        return this->executionTime;
    }
    void setExecutionTime(int t)
    {
        this->executionTime = t;
    }
};

#endif