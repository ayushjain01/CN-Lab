#include <stdio.h>
#define INF 1000

int min(int a, int b)
{
    int c;
    c = (a > b) ? b : a;
    return c;
}
void dijkstras(int vertices, int graph[6][6], int source, int visited[6], int distance[6], int prev[6])
{
    int minDistance = INF, minIndex, count = 0;
    // Step 1 -
    for (int i = 0; i < vertices; i++)

        // Step 2 - Initialize visited array to 0, add source as prev node for every node, store distance from source to node in distance array and mark source as visited

        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
            distance[i] = graph[source][i];
            prev[i] = source;
        }
    visited[source] = 1;

    // Step 3 - Repeat Vertices - 1 times
    count = 1;
    while (count < vertices - 1)
    {
        minDistance = INF;
        minIndex = 0;
        // Step 4 - Pick node w such that, visited[w] = 0 and distance[w] is minimum
        for (int i = 0; i < vertices; i++)
        {
            if (distance[i] < minDistance && visited[i] == 0 && distance[i] != 0)
            {
                minDistance = distance[i];
                minIndex = i;
            }
        }
        // Step 5 - Mark w as visited
        visited[minIndex] = minIndex;
        // Step 6 - Recalculate distances for all unvisited nodes and store minimum distance.
        for (int i = 0; i < vertices; i++)
            if (!visited[i])
                if (minDistance + graph[minIndex][i] < distance[i])
                {
                    distance[i] = minDistance + graph[minIndex][i];
                    prev[i] = minIndex;
                }
        count++;
    }
}
void printResult(int vertices, int source, int distance[INF], int prev[INF])
{
    printf("\nShortest Path\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("\nFrom Source: %d to Destination: %d via :%d with Distance : %d", source, i, prev[i], distance[i]);
    }
}
void main()
{
    // Create cost matrix and identify source.
    int source, vertices;
    printf("\nEnter number of vertices : ");
    scanf("%d", &vertices);
    int graph[vertices][vertices], visited[vertices], distance[vertices], prev[vertices];
    printf("\nEnter adjacency cost matrix :\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter source : ");
    scanf("%d", &source);
    dijkstras(vertices, graph, source, visited, distance, prev);
    printResult(vertices, source, distance, prev);
}
// 0 2 3 4 999 999 2 0 999 1 6 2 3 999 0 4 3 999 4 1 4 0 2 999 999 6 3 2 0 8 999 2 999 999 8 0