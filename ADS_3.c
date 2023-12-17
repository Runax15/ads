/*Write a program to implement Dijkstra’s algorithm to find shortest distance between
two nodes of a user defined graph. Use Adjacency Matrix/List to represent a graph.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int minDistance(int dist[], int visited[], int nodes)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < nodes; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int dest, int nodes)
{
    int dist[MAX_NODES], visited[MAX_NODES] = {0};

    for (int i = 0; i < nodes; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 0; count < nodes - 1; count++)
    {
        int u = minDistance(dist, visited, nodes);
        visited[u] = 1;
        for (int v = 0; v < nodes; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Shortest distance from node %d to node %d: %d\n", src, dest, dist[dest]);
}

int main()
{
    int nodes, edges;
    printf("Enter number of nodes and edges: ");
    scanf("%d%d", &nodes, &edges);

    int graph[MAX_NODES][MAX_NODES] = {{0}};
    printf("Enter edges and weights (node1 node2 weight):\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // For undirected graph
    }

    int source, destination;
    printf("Enter source and destination nodes: ");
    scanf("%d%d", &source, &destination);

    dijkstra(graph, source, destination, nodes);

    return 0;
}