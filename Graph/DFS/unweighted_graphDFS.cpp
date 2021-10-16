#include<utility>
#include<vector>
#include<iostream>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    vector<bool> visited;

    public:
    Graph(int noOfVertex)
    {
        V = noOfVertex;
        adj = new vector<int>[noOfVertex];
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << " :\n";
            for (int u: adj[i])
            {
                cout << "-> Node " << u << "\n";
            }
        }
    }

    private:
    void DFS_util(int vertex)
    {
        cout<<vertex<<" -> ";
        visited[vertex] = true;
        for(int u:adj[vertex])
        {
            if(!visited[u])
            {
                DFS_util(u);
            }
        }
    }

    public:
    void DFS(int vertex)
    {
        visited = vector<bool>(V);
        DFS_util(vertex);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);


    g.DFS(0);
    return 0;
}