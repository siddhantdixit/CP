def countRooms(maze,N,M):

    def DFS(maze,i,j):
        maze[i][j] = '#'

        # North
        if(i!=0 and maze[i-1][j]=='.'):
            DFS(maze,i-1,j)

        # East
        if(j!=(M-1) and maze[i][j+1]=='.'):
            DFS(maze,i,j+1)

        # South
        if(i!=(N-1) and maze[i+1][j]=='.'):
            DFS(maze,i+1,j)

        # West
        if(j!=0 and maze[i][j-1]=='.'):
            DFS(maze,i,j-1)


    rooms = 0
    for i in range(N):
        for j in range(M):
            if maze[i][j]=='.':
                DFS(maze,i,j)
                rooms+=1
    
    return rooms
    

N, M = map(int,input().split())
maze = list()

for i in range(N):
    line = input()
    maze.append(list(line))

print(countRooms(maze,N,M))
