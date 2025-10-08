#include <iostream>
#include "..\..\ADT's\Stack\Stack.h"
using namespace std;

struct Pair
{
    int x, y;
};

bool is_valid(int x, int y, int row, int col, char maze[6][6], bool visited[6][6])
{
    return (x >= 0 && x < row && y >= 0 && y < col &&
            maze[x][y] != '*' && !visited[x][y]);
}

void solve_maze(char maze[6][6], Pair start, Pair dest, int row, int col)
{
    bool visited[6][6] = {false};
    Stack<Pair> st;

    st.push(start);
    visited[start.x][start.y] = true;

    // Parent tracking for path printing
    Pair parent[6][6];
    parent[start.x][start.y] = {-1, -1};

    int dx[] = {-1, 1, 0, 0}; // up, down
    int dy[] = {0, 0, -1, 1}; // left, right

    bool found = false;

    while (!st.isEmpty())
    {
        Pair curr = st.stackTop();
        st.pop();

        if (curr.x == dest.x && curr.y == dest.y)
        {
            found = true;
            break;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curr.x + dx[dir];
            int ny = curr.y + dy[dir];

            if (is_valid(nx, ny, row, col, maze, visited))
            {
                visited[nx][ny] = true;
                st.push({nx, ny});
                parent[nx][ny] = curr; // remember how we reached here
            }
        }
    }

    if (found)
    {
        cout << "Solved" << endl;
        // Reconstruct path from dest -> start
        Stack<Pair> path;
        Pair p = dest;
        while (p.x != -1 && p.y != -1)
        {
            path.push(p);
            p = parent[p.x][p.y];
        }

        while (!path.isEmpty())
        {
            cout << "(" << path.stackTop().x << "," << path.stackTop().y << ")";
            path.pop();
            if (!path.isEmpty())
                cout << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Unsolved" << endl;
    }
}

int main()
{
    char maze1[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', ' ', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}};

    Pair start = {2, 0};
    Pair dest = {4, 5};

    solve_maze(maze1, start, dest, 6, 6);

    char maze2[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', '*', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}};

    solve_maze(maze2, start, dest, 6, 6);

    return 0;
}
