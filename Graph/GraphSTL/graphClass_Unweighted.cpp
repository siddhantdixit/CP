#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int no_of_Vertex)
    {
        V = no_of_Vertex;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << " :\n";
            for (int u : adj[i])
            {
                cout << "-> Node " << u << "\n";
            }
        }
    }
};

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.printGraph();
    return 0;
}