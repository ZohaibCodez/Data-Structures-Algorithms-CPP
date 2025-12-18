#include<iostream>
using namespace std;

class Graph
{
private:
    int **adjMatrix; // Adjacency matrix of the graph
    int maxVertices; // Max number of vertices which can be present in the graph
    int n;           // Current number of vertices present in the graph
    bool *visited;   // Array to keep track of visited/unvisited vertices
public:
    Graph(int maxV, int currV);

    // Constructor to allocate and initialize an empty graph of the specified size. Here,
    // maxV indicates the max # of vertices and currV indicates the current # of vertices
    ~Graph(); // Destructor
    bool addVertex(int &v);
    // Adds a new vertex to the graph. This function should store the number of the newly inserted vertex into the reference parameter v 
    bool addEdge(int u, int v); // Adds the edge <u,v> to the graph
    bool removeEdge(int u, int v);// Removes the edge <u,v> from the graph
};