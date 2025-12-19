#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph
{
private:
    list<int> *adjList; // Array of lists for adjacency
    int maxVertices;
    int n;
    bool *visited;
    void DFS(int v) // private
    {
        visited[v - 1] = true;
        cout << v << " ";

        for (int u : adjList[v - 1])
        {
            if (!visited[u - 1])
                DFS(u);
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

            for (int u : adjList[v - 1])
            {
                if (!visited[u - 1])
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

        adjList = new list<int>[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            adjList[i] = other.adjList[i];
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

    adjList = new list<int>[maxVertices];
    visited = new bool[maxVertices];

    for (int i = 0; i < maxVertices; i++)
        visited[i] = false;
}

Graph::~Graph()
{
    delete[] adjList;
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
    if (u < 1 || u > n || v < 1 || v > n || u == v)
        return false;

    adjList[u - 1].push_back(v);
    adjList[v - 1].push_back(u);

    // Maintain sorted order for DFS/BFS increasing traversal
    adjList[u - 1].sort();
    adjList[v - 1].sort();

    return true;
}

bool Graph::removeEdge(int u, int v)
{
    if (u < 1 || u > n || v < 1 || v > n || u == v)
        return false;

    adjList[u - 1].remove(v);
    adjList[v - 1].remove(u);

    return true;
}

bool Graph::isEmpty()
{
    for (int i = 0; i < n; i++)
    {
        if (!adjList[i].empty())
            return false;
    }
    return true;
}

bool Graph::isComplete()
{
    if (n <= 1)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (adjList[i].size() != n - 1)
            return false;
    }
    return true;
}

void Graph::clear()
{
    for (int i = 0; i < n; i++)
    {
        adjList[i].clear();
    }
}

int Graph::Degree(int v)
{
    if (v < 1 || v > n)
        return -1;

    return adjList[v - 1].size();
}

void Graph::display()
{
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << " -> ";
        for (int v : adjList[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}
