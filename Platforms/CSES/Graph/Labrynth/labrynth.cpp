#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

int N = 0;
int M = 0;
bool found = false;

deque<pair<int, int>> positions;

void DFS(vector<vector<char>> &maze, int i, int j)
{
    if (found)
    {
        return;
    }

    maze[i][j] = '#';
    //North
    if (i != 0)
    {
        if (maze[i - 1][j] == '.')
        {
            DFS(maze, i - 1, j);
        }
        if (maze[i - 1][j] == 'B' && found==false)
        {
            found = true;
            positions.push_front(make_pair(i - 1, j));
        }
    }
    // East
    if (j != (maze[i].size() - 1))
    {
        if (maze[i][j + 1] == '.')
        {
            DFS(maze, i, j + 1);
        }
        if (maze[i][j + 1] == 'B' && found==false)
        {
            found = true;
            positions.push_front(make_pair(i, j + 1));
        }
    }
    // South
    if (i != maze.size() - 1)
    {
        if (maze[i + 1][j] == '.')
        {
            DFS(maze, i + 1, j);
        }
        if (maze[i + 1][j] == 'B' && found==false)
        {
            found = true;
            positions.push_front(make_pair(i + 1, j));
        }
    }
    // West
    if (j != 0)
    {
        if (maze[i][j - 1] == '.')
        {
            DFS(maze, i, j - 1);
        }
        if (maze[i][j - 1] == 'B' && found==false)
        {
            found = true;
            positions.push_front(make_pair(i, j - 1));
        }
    }
    if (found)
    {
        positions.push_front(make_pair(i, j));
    }
}

void findPath(vector<vector<char>> &maze, int Ai, int Aj)
{
    maze[Ai][Aj] = '.';
    DFS(maze, Ai, Aj);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    char ele;
    cin >> n >> m;
    N = n;
    M = m;
    vector<vector<char>> maze(n);
    int Ai;
    int Aj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ele;
            maze[i].push_back(ele);
            if (ele == 'A')
            {
                Ai = i;
                Aj = j;
            }
        }
    }

    findPath(maze, Ai, Aj);

    // cout<<"Done";

    /*
    char x[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            x[i][j] = '.';
        }
    }

    for(pair<int,int> ele:positions)
    {
        x[ele.first][ele.second] = '#';
    }

    cout<<"\n\n\n\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<x[i][j];
        }
        cout<<"\n";
    }
    */

    if (found)
    {
        cout<<"YES\n";
        cout<<positions.size()-1<<"\n";

        for (int i = 0; i < positions.size()-1; i++)
        {
            if (positions[i].first == positions[i + 1].first)
            {
                if (positions[i + 1].second > positions[i].second)
                {
                    cout << "R";
                }
                else
                {
                    cout << "L";
                }
            }
            if (positions[i].second == positions[i + 1].second)
            {
                if (positions[i + 1].first > positions[i].first)
                {
                    cout << "D";
                }
                else
                {
                    cout << "U";
                }
            }
        }
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}