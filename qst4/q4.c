#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9 // Number of vertices in the graph

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int n) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int readGraph(int graph[V][V]) {
    int value;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (scanf("%d", &value) != 1) return 0; // Read error
            if (value < 0) return -1; // Negative weight found
            graph[i][j] = value;
        }
    }
    return 1; // Successful read
}

int main() {
    int graph[V][V];
    while (1) {
        printf("Enter the adjacency matrix for the graph (enter EOF to exit):\n");
        int result = readGraph(graph);
        if (feof(stdin)) break; // Exit loop if EOF is reached
        if (result == -1) {
            printf("Error: Negative weight detected.\n");
        } else if (result == 0) {
            printf("Error: Incorrect input format.\n");
            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            dijkstra(graph, 0);
        }
    }
    return 0;
}
