#include <iostream>

using namespace std;

int countSquares(int k, int cx, int cy, int px, int py)
{
    // First i am initializing count to zero. As the point(px,py) is not contained in any square of grid yet
    int count = 0;

    // Here i am checking the specified problem's condition that the size must be in between 1 and 512
    if (k < 1 || k > 512)
        return count;

    // Here i am finding a top, bottom, left and right of a square. As k is size of whole square so using correct arithmetic operation, I can get its top, bottom, left and right. Here i imagine that i am finding top, bottom, left and right of a square by visualizing some square of size k on some graph
    int top = cy - k;
    int bottom = cy + k;
    int left = cx - k;
    int right = cx + k;

    // Now checking that the specified point(given in parameter) actually falls between top and bottom and left and right then count must be 1. If point doesn't comes, then count remains 0
    if (px >= left && px <= right && py >= top && py <= bottom)
    {
        count = 1;
    }

    // if there is only one square case. In above i check if point lies in between the coordinates of that one square , then in count variable there must be one, otherwise 0
    if (k == 1)
        return count;

    // according to problem, our new square is of size half of the current square and new square is have to be formed on every corner of the square. Square has four corners. So top,bottom,left,right there must be square of half of actual size square
    int newSize = k / 2;

    // now deep diving , i can say that i am crawling(recursing) going down in all of the four squares that might formed on our actual square corner and then same way, finding point between that square and so on ...!
    count += countSquares(newSize, cx - k, cy - k, px, py);
    count += countSquares(newSize, cx + k, cy - k, px, py);
    count += countSquares(newSize, cx - k, cy + k, px, py);
    count += countSquares(newSize, cx + k, cy + k, px, py);

    // Returning count here :)
    return count;
}

int main()
{
    int k, x, y;
    cin >> k >> x >> y;
    cout << countSquares(k, 1024, 1024, x, y) << endl;

    return 0;
}