#include <iostream>
#include "..\ADT's\Queue\Queue.h"

using namespace std;

struct Pair
{
    char character;
    int index;
};

int firstUniqChar(string s)
{
    Queue<Pair> q(100);
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        q.enqueue({s[i], i});
        freq[s[i] - 'a']++;
    }
    while (!q.isEmpty() && freq[q.queueFront().character - 'a'] > 1)
    {
        q.dequeue();
    }
    if (q.isEmpty())
        return -1;

    return q.queueFront().index;
}

int main()
{
    string s = "";
    cout << firstUniqChar(s) << endl;
    return 0;
}