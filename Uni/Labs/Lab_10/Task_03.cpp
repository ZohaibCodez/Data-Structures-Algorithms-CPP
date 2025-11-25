#include <iostream>
#include <iomanip>
using namespace std;

int getRandomNumber(int start, int end)
{
    return rand() % (end - start + 1) + start;
}

int experiment(int tableSize)
{
    // implementation of the following function.
    bool* table = new bool[tableSize];
    for(int i = 0;i < tableSize;i++){
        table[i] = false;
    }
    int counter = 0;
    while(true){
        int temp = getRandomNumber(0,100);
        int sp = temp % tableSize;
        if(table[sp] == true){
            break;
        }
        table[sp] = true;
        counter++;
    }
    delete[] table;
    return counter;
}

int main()
{
    srand(static_cast<unsigned>(time(0))); // seed random generator
    const int numExperiments = 50;
    cout << "Table Size\tAverage Inserted\n";
    cout << "-----------\t----------------\n";
    // Run experiments for table sizes 10, 20, 30, ..., 100
    for (int S = 10; S <= 100; S += 10)
    {
        double totalInserted = 0.0;
        for (int i = 0; i < numExperiments; i++)
            totalInserted += experiment(S);
        double averageInserted = totalInserted / numExperiments;
        cout << setw(5) << S << "\t\t" << fixed << setprecision(2)
             << averageInserted << endl;
    }
}