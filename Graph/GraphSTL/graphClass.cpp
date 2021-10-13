#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<pair<int, int>> *adj;

public:
    Graph(int no_of_Vertex)
    {
        V = no_of_Vertex;
        adj = new vector<pair<int,int>> [V];
    }

    void addEdge(int u, int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << " :\n";
            for (pair<int, int> ele : adj[i])
            {
                cout << "-> Node " << ele.first << "  =  " << ele.second << "\n";
            }
        }
    }
};

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0,1,10);
    g.addEdge(0,4,20);
    g.addEdge(1,2,30);
    g.addEdge(1,3,40);
    g.addEdge(1,4,50);
    g.addEdge(2,3,60);
    g.addEdge(3,4,70);

    g.printGraph();
    return 0;
}