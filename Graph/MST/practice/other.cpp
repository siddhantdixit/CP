/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int weight;

    Edge()
    {

    }

    Edge(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }

    static bool comp(const Edge &e1, const Edge &e2)
    {
        if (e2.weight > e1.weight)
            return true;
        else
            return false;
    }
};

// class Graph
// {
//     vector<Edge> *adj;

// };

class MST
{
    vector<Edge> *adj;
    vector<Edge> edges;
    int V;

    public:
    MST(int V)
    {
        this->V = V;
        adj = new vector<Edge>(V + 1);
    }

    void addEdge(int u, int v, int weight)
    {
        edges.push_back(Edge(u, v, weight));
    }

    bool isSeperateComponent(unordered_set<int> &bigSet, vector<unordered_set<int>> &otherSets, int u, int v)
    {
        if(bigSet.find(u)!=bigSet.end() && bigSet.find(v)!=bigSet.end())
        {
            unordered_set<int> s = {u,v};
            otherSets.push_back(s);
            bigSet.erase(u);
            bigSet.erase(v);
            return true;
        }

        else if(bigSet.find(u)!=bigSet.end())
        {
            
            for(unordered_set<int> &os:otherSets)
            {
                if(os.find(v)!=os.end())
                {
                    os.insert(u);
                    break;
                }
            }
            bigSet.erase(u);
            return true;
        }

        else if(bigSet.find(v)!=bigSet.end())
        {
            
            for(unordered_set<int> &os:otherSets)
            {
                if(os.find(u)!=os.end())
                {
                    os.insert(v);
                    break;
                }
            }
            bigSet.erase(v);
            return true;
        }

        // else
        // {
        //     unordered_set<int> *ref1;
        //     unordered_set<int> *ref2;

        //     for(unordered_set<int> os:otherSets)
        //     {
        //         if(os.find(u)!=os.end())
        //         {
        //             ref1 = &os;
        //         }
        //         if(os.find(v)!=os.end())
        //         {
        //             ref2 = &os;
        //         }
        //         if(ref1 == ref2)
        //         {
        //             return false;
        //         }
        //     }
        //     ref1->insert(ref2->begin(),ref2->end());
        //     *ref2 = unordered_set<int>();
        //     return true;
        // }
        
        else
        {
            int ref1=INT_MIN;
            int ref2=INT_MAX;
            for(int i=0;i<otherSets.size();i++)
            {
                if(otherSets[i].find(u)!=otherSets[i].end())
                {
                    ref1 = i;
                }
                if(otherSets[i].find(v)!=otherSets[i].end())
                {
                    ref2 = i;
                }
                if(ref1==ref2)
                {
                    return false;
                }
            }
            otherSets[ref1].insert(otherSets[ref2].begin(),otherSets[ref2].end());
            otherSets[ref2]=unordered_set<int>();
            return true;

        }
        

    }

    void generateMST()
    {
        sort(edges.begin(), edges.end(), Edge::comp);
        unordered_set<int> bigSet;
        vector<unordered_set<int>> othersets;
        vector<Edge> minimumSpanningTree;

        for(int i=1;i<=V;i++)
        {
            bigSet.insert(i);
        }


        for (Edge e : edges)
        {
            if(isSeperateComponent(bigSet,othersets,e.u,e.v))
            {
                minimumSpanningTree.push_back(e);
            }
        }

        int cost = 0;
        for(Edge e:minimumSpanningTree)
        {
            // cout<<e.u<<" "<<e.v<<" "<<e.weight<<"\n";
            cost+=e.weight;
        }
        cout<<cost<<"\n";
    }
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    // vector<Edge> x;
    // x.push_back(Edge(1, 2, 4));
    // x.push_back(Edge(4, 5, 3));
    // x.push_back(Edge(7, 1, 1));
    // x.push_back(Edge(8, 3, 2));
    // x.push_back(Edge(3, 3, 7));

    // sort(x.begin(), x.end(), Edge::comp);

    int V;int M;
    int a,b,w;
    cin>>V>>M;

    MST ms(V);
    for(int i=0;i<M;i++)
    {
        cin>>a>>b>>w;
        ms.addEdge(a, b, w);
    }
    ms.generateMST();
    return 0;
}