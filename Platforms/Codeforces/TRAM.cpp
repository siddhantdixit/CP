#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N=0;
    int tram_cap = 0;
    int T;
    cin>>T;
    while(T--)
    {
        int a;
        int b;
        cin>>a>>b;
        N-=a;
        N+=b;
        tram_cap = max(tram_cap,N);
    }
    cout<<tram_cap;
    return 0;
}
