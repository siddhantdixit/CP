#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    public:
    vector<int> *adj;
    int vertex;

    vector<bool> visited;

    Graph(int noOfV)
    {
        vertex = noOfV;
        adj = new vector<int>[noOfV];
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph()
    {
        for(int i=0;i<vertex;i++)
        {
            cout<<i<<" : ";
            for(int C:adj[i])
            {
                cout<<C<<" -> ";
            }
            cout<<"\n";
        }
    }


    void connectedComponentes()
    {
        visited = vector<bool>(vertex,false);
        // DFS(0);
        int cnt=0;
        for(int i=0;i<vertex;i++)
        {
            if(!visited[i])
            {
                cnt++;
                DFS(i);                
                cout<<"\n";
            }
        }
        cout<<"Total Connected Components = "<<cnt;
    }

    void DFS(int u)
    {
        visited[u] = true;
        cout<<u<<" ";

        for(int i:adj[u])
        {
            if(!visited[i])
            {
                DFS(i);
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,4);
    
    g.connectedComponentes();
    // g.DFS(0);
}