#ifndef PROCESS_H
#define PROCESS_H

#include <string>

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

    Process(int id, string name, int time);

    int getId();
    string getName();
    int getExecutionTime();
    void setExecutionTime(int t);
};

#endif