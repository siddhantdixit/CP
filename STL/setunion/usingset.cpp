#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

int main()
{
    // Finding Union two sets

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    unordered_set<int> u;
    u.insert(5);
    u.insert(1);
    u.insert(2);

    unordered_set<int> x;
    x.insert(7);
    x.insert(6);
    x.insert(3);

    u.insert(x.begin(),x.end());

    for(int i:u)
    {
        cout<<i<<" ";
    }
    return 0;
}