#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> x{5,6,7,2,3,4};
    sort(x.rbegin(),x.rend());
    for(int i:x)
    cout<<i<<" ";
    
    return 0;
}