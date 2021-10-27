#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, T;
    char inp;

    cin >> N;
    cin >> T;
    char arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> inp;
        arr[i] = inp;
    }

    for(int i=0;i<T;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(arr[j]=='G' && arr[j-1]=='B')
            {
                arr[j] = 'B';
                arr[j-1] = 'G';
                j+=1;
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        cout<<arr[i];
    }
    
    return 0;
}