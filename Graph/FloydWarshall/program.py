# Python Program for Floyd Warshall Algorithm

# Number of vertices in the graph
import math
V = 4

# Define infinity as the large
# enough value. This value will be
# used for vertices not connected to each other
INF = math.inf

# Solves all pair shortest path
# via Floyd Warshall Algorithm


def floydWarshall(graph):
    """ dist[][] will be the output
    matrix that will finally
            have the shortest distances
            between every pair of vertices """
    """ initializing the solution matrix
	same as input graph matrix
	OR we can say that the initial
	values of shortest distances
	are based on shortest paths considering no
	intermediate vertices """

    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))

    """ Add all vertices one by one
	to the set of intermediate
	vertices.
	---> Before start of an iteration,
	we have shortest distances
	between all pairs of vertices
	such that the shortest
	distances consider only the
	vertices in the set
	{0, 1, 2, .. k-1} as intermediate vertices.
	----> After the end of a
	iteration, vertex no. k is
	added to the set of intermediate
	vertices and the
	set becomes {0, 1, 2, .. k}
	"""
    print(f"A0 -> ")
    printSolution(dist)
    print("\n\n")

    for k in range(V):

        # pick all vertices as source one by one
        for i in range(V):

            # Pick all vertices as destination for the
            # above picked source
            for j in range(V):

                # If vertex k is on the shortest path from
                # i to j, then update the value of dist[i][j]
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]
                                 )

                if((i == j) or (j == k) or (i == k)):
                    continue
                else:
                    if(dist[i][j] > (dist[i][k] + dist[k][j])):
                        sign = ">"
                    elif(dist[i][j] == (dist[i][k] + dist[k][j])):
                        sign = "="
                    else:
                        sign = "<"

                    print(
                        f"A{k+1} [{i+1},{j+1}]  =     A{k} [{i+1},{j+1}] <--> A{k} [{i+1},{k+1}] + A{k} [{k+1},{j+1}] ")
                    print(
                        f"A{k+1} [{i+1},{j+1}]  =     {dist[i][j]} <--> {dist[i][k]} + {dist[k][j]} ")
                    print(
                        f"A{k+1} [{i+1},{j+1}]  =     {dist[i][j]} <--> {dist[i][k] + dist[k][j]} ")
                    print(
                        f"A{k+1} [{i+1},{j+1}]  =     {dist[i][j]}   {sign}  {dist[i][k] + dist[k][j]} ")
                    print("\n\n")

        print(f"A{k+1} -> ")
        printSolution(dist)
        print("\n\n\n\n")


# A utility function to print the solution
def printSolution(dist):
    print("Following matrix shows the shortest distances\
between every pair of vertices")
    for i in range(V):
        for j in range(V):
            if(dist[i][j] == INF):
                print("%7s" % ("INF"), end=" "),
            else:
                print("%7d" % (dist[i][j]), end=" "),
            if j == V-1:
                print("")


# Driver program to test the above program
# Let us create the following weighted graph
"""
			10
	(0)------->(3)
		|		 /|\
	5 |		 |
		|		 | 1
	\|/		 |
	(1)------->(2)
			3		 """
graph = [[0, 3, INF, 7],
         [8, 0, 2, INF],
         [5, INF, 0, 1],
         [2, INF, INF, 0]
         ]


# graph = [[0, 3, 6, INF, INF, INF, INF],
#          [3, 0, 2, 1, INF, INF, INF],
#          [6, 2, 0, 1, 4, 2, INF],
#          [INF, 1, 1, 0, 2, INF, 4],
#          [INF, INF, 4, 2, 0, 2, 1],
#          [INF, INF, 2, INF, 2, 0, 1],
#          [INF, INF, INF, 4, 1, 1, 0]]


graph = [[0, 3, 8, INF, -4],
         [INF, 0, INF, 1, 7],
         [INF, 4, 0, INF, INF],
         [2, INF, -5, 0, INF],
         [INF, INF, INF, 6, 0]
         ]

V = len(graph)
# Print the solution
floydWarshall(graph)
# This code is contributed by Mythri J L
