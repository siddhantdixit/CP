#include<utility>
#include<vector>
#include<iostream>
#include<queue>

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

    void BFS(int vertex)
    {
        queue<int> q;
        vector<bool> visited(V,false);
        visited[vertex] = true;
        q.push(vertex);
        while(!q.empty())
        {
            int ele = q.front();
            q.pop();
            cout<<ele<<" -> ";
            for(int u:adj[ele])
            {
                if(!visited[u])
                {
                    q.push(u);
                    visited[u] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,4);
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.addEdge(4,3);
    g.addEdge(3,2);


    // g.DFS(0);
    g.BFS(3);
    return 0;
}