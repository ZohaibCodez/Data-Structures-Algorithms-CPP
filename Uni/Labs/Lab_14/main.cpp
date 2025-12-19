#include <iostream>
#include "Task_01.h"
using namespace std;

int main()
{
    int maxV, currV;
    cout << "Enter max vertices of the graph: ";
    cin >> maxV;
    cout << "Enter current number of vertices: ";
    cin >> currV;

    Graph g(maxV, currV);

    int choice;
    do
    {
        cout << "1. Add Vertex" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Remove Edge" << endl;
        cout << "4. Display Adjacency Matrix" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Complete" << endl;
        cout << "7. Degree of Vertex" << endl;
        cout << "8. DFS Traversal" << endl;
        cout << "9. BFS Traversal" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int v;
            if (g.addVertex(v))
                cout << "Vertex " << v << " added." << endl;
            else
                cout << "Graph is full!" << endl;
            break;
        }
        case 2:
        {
            int u, v;
            cout << "Enter two vertices to add edge: ";
            cin >> u >> v;
            if (g.addEdge(u, v))
                cout << "Edge added." << endl;
            else
                cout << "Invalid vertices or edge exists." << endl;
            break;
        }
        case 3:
        {
            int u, v;
            cout << "Enter two vertices to remove edge: ";
            cin >> u >> v;
            if (g.removeEdge(u, v))
                cout << "Edge removed." << endl;
            else
                cout << "Invalid vertices or edge does not exist." << endl;
            break;
        }
        case 4:
            g.display();
            break;
        case 5:
            cout << (g.isEmpty() ? "Graph is empty." : "Graph is not empty.") << endl;
            break;
        case 6:
            cout << (g.isComplete() ? "Graph is complete." : "Graph is not complete.") << endl;
            break;
        case 7:
        {
            int v;
            cout << "Enter vertex to check degree: ";
            cin >> v;
            int deg = g.Degree(v);
            if (deg == -1)
                cout << "Invalid vertex." << endl;
            else
                cout << "Degree of vertex " << v << " is " << deg << endl;
            break;
        }
        case 8:
            g.DFS();
            cout << endl;
            break;
        case 9:
            g.BFS();
            cout << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
