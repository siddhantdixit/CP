#include<utility>
#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<pair<int,int>> grph[],int u,int v,int wt)
{
    grph[u].push_back(make_pair(v,wt));
    grph[v].push_back(make_pair(u,wt));
}

void printGraph(vector<pair<int,int>> grph[],int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<"Node "<<i<<" :\n";
        for(pair<int,int> ele:grph[i])
        {
            cout<<"-> Node "<<ele.first<< "  =  "<<ele.second<<"\n";
        }
    }
}

int main()
{
    int V = 5;
    vector<pair<int,int>> grph[V];
    addEdge(grph, 0, 1, 10);
    addEdge(grph, 0, 4, 20);
    addEdge(grph, 1, 2, 30);
    addEdge(grph, 1, 3, 40);
    addEdge(grph, 1, 4, 50);
    addEdge(grph, 2, 3, 60);
    addEdge(grph, 3, 4, 70);

    printGraph(grph,V);
    return 0;
}