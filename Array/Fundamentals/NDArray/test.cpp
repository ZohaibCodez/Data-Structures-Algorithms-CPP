#include <iostream>

using namespace std;

int main()
{
    int *a;

    *a = new int{1};

    for(int i = 0;i < 2;i++){
        cout << a[i]  << " ";
    }
    cout << endl;
    return 0;
}