#include<utility>
#include<vector>
#include<iostream>
#include<queue>
#include<bits/stdc++.h>

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


    void shortestPath(int u,int v)
    {
        vector<int> parent (V,-1);
        BFS(u,parent);
        vector<int> path = pathTrace(u,v,parent);
        cout<<"Shortest Path : \n";
        for(int i:path)
        {
            cout<<i<<" -> ";
        }
    }

    vector<int> pathTrace(int u,int v,vector<int> &parent)
    {
        vector<int> path;
        for(int e=v;e!=-1;e=parent[e])
        {
            path.push_back(e);
        }
        reverse(path.begin(),path.end());
        if(path[0]==u)
        {
            return path;
        }
        else
        {
            return {};
        }
    }

    void BFS(int vertex,vector<int> &parent)
    {
        queue<int> q;
        vector<bool> visited(V,false);
        visited[vertex] = true;
        q.push(vertex);
        while(!q.empty())
        {
            int ele = q.front();
            q.pop();
            // cout<<ele<<" -> ";
            for(int u:adj[ele])
            {
                if(!visited[u])
                {
                    q.push(u);
                    visited[u] = true;
                    parent[u] = ele;
                }
            }
        }
    }
};

int main()
{
    Graph g(8);
    g.addEdge(2,1);
    g.addEdge(1,0);
    g.addEdge(0,3);
    g.addEdge(3,7);
    g.addEdge(3,4);
    g.addEdge(4,7);
    g.addEdge(6,7);
    g.addEdge(4,6);
    g.addEdge(4,5);
    g.addEdge(6,5);


    // g.DFS(0);
    // g.BFS(3);
    // g.printGraph();
    g.shortestPath(2,7);
    return 0;
}