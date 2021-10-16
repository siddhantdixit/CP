#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int> s;
    s.insert(7);
    s.insert(10);
    s.insert(3);
    s.insert(8);

    auto res = s.find(3);
    if(res!=s.end())
    {
        cout<<"Found";
    }
    else
    {
        cout<<"Not Found";
    }

    set<int,greater<int>> ms;
    ms.insert(7);
    ms.insert(3);
    ms.insert(10);
    ms.insert(2);
    ms.insert(15);
    ms.insert(6);

    for(int i:ms)
    {
        cout<<i<<" ";
    }
    return 0;

}