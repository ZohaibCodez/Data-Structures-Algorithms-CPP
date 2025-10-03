#include "Process.h"
#include "..\..\..\ADT's\Queue\Queue.h"
#include "Scheduler.h"

using namespace std;

int main()
{
    Process arr[] = {
        Process(1, "notepad.exe", 20),
        Process(13, "mp3player.exe", 5),
        Process(4, "bcc.exe", 30),
        Process(11, "explorer.exe", 2)};

    Scheduler s(arr, 4, 5); // time quantum = 5
    s.assignProcessor();
    return 0;
}