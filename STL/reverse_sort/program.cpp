#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // vector<int> x{6,3,8,3,1,0,2};
    vector<pair<int,int>> x;
    x.push_back(make_pair(5,1));
    x.push_back(make_pair(2,2));
    x.push_back(make_pair(7,4));
    x.push_back(make_pair(3,3));

    sort(x.begin(),x.end());
    reverse(x.begin(),x.end());
    for(pair<int,int> i:x)
    {
        cout<<i.first<<" "<<i.second<<" \n";
    }
    return 0;
}