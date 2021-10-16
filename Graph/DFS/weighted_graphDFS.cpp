#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<pair<int, int>> *adj;
    vector<bool> visited;

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

    void DFS_Until(int vertex)
    {
        cout<<vertex<<" -> ";
        visited[vertex] = true;
        for(pair<int,int> u:adj[vertex])
        {
            if(!visited[u.first])
            {
                DFS_Until(u.first);
            }
        }
    }

    void DFS(int vertex)
    {
        visited = vector<bool>(V,false);
        DFS_Until(vertex);
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

    // g.printGraph();
    g.DFS(3);
    return 0;
}