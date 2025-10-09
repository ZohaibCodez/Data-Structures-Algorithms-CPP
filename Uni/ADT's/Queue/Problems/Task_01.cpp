#include <iostream>
#include "..\Queue.h"

using namespace std;

struct Pair
{
    char character;
    int index;
};

int findFirstChar(string s)
{
    int freq[26] = {0};
    Queue<Pair> q(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        q.enqueue({s[i], i});
        freq[s[i] - 'a']++;
    }
    while (!q.isEmpty() && freq[q.queueFront().character - 'a'] > 1)
    {
        q.dequeue();
    }

    if(q.isEmpty()) return -1;

    return q.queueFront().index;
}

int main()
{
    string s = "aabb";
    cout << findFirstChar(s) << endl;
    return 0;
}