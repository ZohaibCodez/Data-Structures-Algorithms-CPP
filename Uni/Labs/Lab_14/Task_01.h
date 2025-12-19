#ifndef TASK_01_H
#define TASK_01_H

#include <iostream>
#include <queue>
using namespace std;

class Graph
{
private:
    int **adjMatrix; // Adjacency matrix of the graph
    int maxVertices; // Max number of vertices which can be present in the graph
    int n;           // Current number of vertices present in the graph
    bool *visited;   // Array to keep track of visited/unvisited vertices
    void DFS(int v)
    {
        visited[v - 1] = true;
        cout << v << " ";

        for (int u = 1; u <= n; u++)
        {
            if (adjMatrix[v - 1][u - 1] == 1 && !visited[u - 1])
            {
                DFS(u);
            }
        }
    }

    void runBFS(int start)
    {
        queue<int> q;

        visited[start - 1] = true;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            cout << v << " ";

            for (int u = 1; u <= n; u++)
            {
                if (adjMatrix[v - 1][u - 1] == 1 && !visited[u - 1])
                {
                    visited[u - 1] = true;
                    q.push(u);
                }
            }
        }
    }

public:
    Graph(int maxV, int currV);

    // Constructor to allocate and initialize an empty graph of the specified size. Here,
    // maxV indicates the max # of vertices and currV indicates the current # of vertices
    ~Graph(); // Destructor
    bool addVertex(int &v);
    // Adds a new vertex to the graph. This function should store the number of the newly inserted vertex into the reference parameter v
    bool addEdge(int u, int v);    // Adds the edge <u,v> to the graph
    bool removeEdge(int u, int v); // Removes the edge <u,v> from the graph
    bool isEmpty();
    bool isComplete();
    void clear();
    int Degree(int v);
    void display();

    void DFS()
    {
        for (int i = 0; i < n; i++)
            visited[i] = false;

        int start;
        cout << "Enter starting vertex for DFS: ";
        cin >> start;

        if (start < 1 || start > n)
            return;

        DFS(start);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(i + 1);
            }
        }
    }
    Graph(const Graph &other)
    {
        maxVertices = other.maxVertices;
        n = other.n;

        adjMatrix = new int *[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            adjMatrix[i] = new int[maxVertices];
        }

        for (int i = 0; i < maxVertices; i++)
        {
            for (int j = 0; j < maxVertices; j++)
            {
                adjMatrix[i][j] = other.adjMatrix[i][j];
            }
        }

        visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            visited[i] = other.visited[i];
        }
    }

    void BFS()
    {
        for (int i = 0; i < n; i++)
            visited[i] = false;

        int start;
        cout << "Enter starting vertex for BFS: ";
        cin >> start;

        if (start < 1 || start > n)
            return;

        runBFS(start);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                runBFS(i + 1);
            }
        }
    }
};
Graph::Graph(int maxV, int currV)
{
    maxVertices = maxV;
    if (currV < maxV)
    {
        n = currV;
    }
    else
    {
        n = 0;
    }

    adjMatrix = new int *[maxVertices];
    for (int i = 0; i < maxVertices; i++)
    {
        adjMatrix[i] = new int[maxVertices];
    }

    for (int i = 0; i < maxVertices; i++)
    {
        for (int j = 0; j < maxVertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    visited = new bool[maxVertices];
    for (int i = 0; i < maxVertices; i++)
    {
        visited[i] = false;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < maxVertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    delete[] visited;
}

bool Graph::addVertex(int &v)
{
    if (n == maxVertices)
        return false;

    n++;
    v = n;
    return true;
}

bool Graph::addEdge(int u, int v)
{
    if (u >= 1 && u <= n && v >= 1 && v <= n)
    {
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
        return true;
    }

    return false;
}

bool Graph::removeEdge(int u, int v)
{
    if (u >= 1 && u <= n && v >= 1 && v <= n)
    {
        adjMatrix[u - 1][v - 1] = 0;
        adjMatrix[v - 1][u - 1] = 0;
        return true;
    }
    return false;
}

bool Graph::isEmpty()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool Graph::isComplete()
{
    if (n <= 1)
        return true;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (adjMatrix[i][j] == 0)
                return false;
        }
    }
    return true;
}

void Graph::clear()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::display()
{
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::Degree(int v)
{
    if (v < 1 || v > n)
        return -1;

    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (adjMatrix[v - 1][j] == 1)
            count++;
    }
    return count;
}

#endif