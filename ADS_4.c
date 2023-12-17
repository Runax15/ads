/*4. Write a program to accept a graph (directed or undirected) from user and represent it
with Adjacency Matrix and perform BFS and DFS traversals on it.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

int adjMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void addEdge(int u, int v)
{
    adjMatrix[u][v] = 1;
    // For undirected graph, uncomment the line below:
    // adjMatrix[v][u] = 1;
}

void BFS(int start, int nodes)
{
    int queue[MAX_NODES], front = 0, rear = 0;
    visited[start] = 1, queue[rear++] = start;

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < nodes; i++)
        {
            if (adjMatrix[current][i] && !visited[i])
            {
                visited[i] = 1, queue[rear++] = i;
            }
        }       
    }
    printf("\n");
}

void DFS(int start, int nodes)
{
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < nodes; i++)
    {
        if (adjMatrix[start][i] && !visited[i])
        {   
            DFS(i, nodes);
        }
    }    
}

int main()
{
    int nodes, edges;
    printf("Enter number of nodes and edges: ");
    scanf("%d%d", &nodes, &edges);

    for (int i = 0; i < MAX_NODES; i++)
    {
        visited[i] = 0, memset(adjMatrix[i], 0, sizeof(adjMatrix[i]));
    }    
    printf("Enter edges (node1 node2):\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }

    int startNode;
    printf("Enter the starting node for traversal: ");
    scanf("%d", &startNode);

    printf("BFS traversal: ");
    BFS(startNode, nodes);

    memset(visited, 0, sizeof(visited));
    printf("DFS traversal: ");
    DFS(startNode, nodes);
    printf("\n");

    return 0;
}

/*
5 7 


1 2 
1 3
1 4
3 4
3 5
4 5
2 4


1
*/