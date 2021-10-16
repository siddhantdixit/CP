#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>> &maze, int i, int j)
{
    maze[i][j] = '#';
    
    // North
    if(i!=0)
    {
        if(maze[i-1][j]=='.')
        {
            DFS(maze,i-1,j);
        }
    }
    //East
    if(j!=(maze[i].size()-1))
    {
        if(maze[i][j+1]=='.')
        {
            DFS(maze,i,j+1);
        }
    }
    //South
    if(i!=maze.size()-1)
    {
        if(maze[i+1][j]=='.')
        {
            DFS(maze,i+1,j);
        }
    }
    //West
    if(j!=0)
    {
        if(maze[i][j-1]=='.')
        {
            DFS(maze,i,j-1);
        }
    }
}

void countRooms(vector<vector<char>> maze)
{
    int cnt=0;
    for(int i=0;i<maze.size();i++)
    {
        for(int j=0;j<maze[i].size();j++)
        {
            if(maze[i][j]=='.')
            {
                DFS(maze,i,j);
                cnt+=1;
            }
        }
    }
    cout<<cnt;
}

int main()
{
    char inp;
    int N, M;
    cin >> N >> M;
    vector<vector<char>> maze(N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>inp;
            maze[i].push_back(inp);
        }
    }
    countRooms(maze);
    return 0;
}