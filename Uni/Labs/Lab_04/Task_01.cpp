#include <iostream>
#include <vector>
using namespace std;

struct Pair
{
    int x;
    int y;
};

bool is_valid(int x, int y, int row, int col, char maze[6][6], bool visited[6][6])
{
    return (x >= 0 && x < row && y >= 0 && y < col &&
            maze[x][y] != '*' && !visited[x][y]);
}

bool arrays(char maze[6][6], Pair curr, Pair dest, int row, int col, bool visited[6][6], vector<Pair> &path)
{
    visited[curr.x][curr.y] = true;
    path.push_back(curr);

    if (curr.x == dest.x && curr.y == dest.y)
        return true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = curr.x + dx[dir];
        int ny = curr.y + dy[dir];

        if (is_valid(nx, ny, row, col, maze, visited))
        {
            if (arrays(maze, {nx, ny}, dest, row, col, visited, path))
                return true;
        }
    }
    path.pop_back();
    return false;
}

void solve_maze(char maze[6][6], Pair s, Pair d, int row, int col)
{
    bool visited[6][6] = {false};
    vector<Pair> path;

    if (arrays(maze, s, d, row, col, visited, path))
    {
        cout << "Solved" << endl;
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << "(" << path[i].x << "," << path[i].y << ")";
            if (i != path.size() - 1)
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