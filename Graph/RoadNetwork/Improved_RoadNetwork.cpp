#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

// Road Network Graph to Store Distance between cities

// Adjency List


class Edge
{
    public:
    string target_city;
    int distance;

    Edge(string target_city,int distance)
    {
        this->target_city = target_city;
        this->distance = distance;
    }
};


class Graph
{
    unordered_map<string,vector<Edge>> connections;

    public:
    void addVertex(string city)
    {
        vector<Edge> edgelist;
        connections[city] = edgelist;
    }


    void addEdge(string city1,string city2,int distance)
    {
        connections[city1].push_back(Edge(city2,distance));
        connections[city2].push_back(Edge(city1,distance));
    }


    string getNearestCity(string city)
    {
        string nearest_city;
        int min_dist = INT_MAX;
        for(Edge eg:connections[city])
        {
            if(eg.distance < min_dist)
            {
                min_dist = eg.distance;
                nearest_city = eg.target_city;
            }
        }
        return nearest_city;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Graph myg;
    myg.addVertex("Seattle");
    myg.addVertex("San Francisco");
    myg.addVertex("Los Angeles");
    myg.addVertex("Las Vegas");
    myg.addVertex("Denver");
    myg.addVertex("Phoenix");

    myg.addEdge("Seattle","San Francisco",808);
    myg.addEdge("Seattle","Denver",1316);
    myg.addEdge("San Francisco","Los Angeles",388);
    myg.addEdge("San Francisco","Las Vegas",568);
    myg.addEdge("Los Angeles","Las Vegas",269);
    myg.addEdge("Los Angeles","Phoenix",372);
    myg.addEdge("Las Vegas","Phoenix",297);
    myg.addEdge("Las Vegas","Denver",748);
    myg.addEdge("Phoenix","Denver",821);

    cout<<myg.getNearestCity("Seattle");
    return 0;
}