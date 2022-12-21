#include <stdio.h>
int bellman(int g[40][40], int V, int E, int edge[40][2], int source)
{
    int distance[40], parent[40], flag = 1, i, k, j, u, v, source;

    for (int i = 0; i < V; i++)
    {
        distance[i] = 1000;
        parent[i] = -1;
    }

    distance[source - 1] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            u = edge[j][0];
            v = edge[j][1];
            if (distance[v] > distance[u] + g[u][v])
            {
                distance[v] = distance[u] + g[u][v];
                parent[v] = u;
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        u = edge[j][0];
        v = edge[j][1];
        if (distance[v] > distance[u] + g[u][v])
            flag = 0;
    }

    if (flag)
    {
        for (int i = 0; i < V; i++)
        {
            printf("Vertex->%d Cost ->%d Parent ->%d\n", i + 1, distance[i], parent[i] + 1);
        }
    }

    return flag;
}

void main()
{
    int g[40][40], edge[40][2], i, j, k = 0, v, source;

    printf("Enter the number of vertices\n");
    scanf("%d", &v);

    printf("Enter the graph\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j] != 0)
            {
                edge[k][0] = i;
                edge[k++][1] = j;
            }
        }
    }
    printf("Enter the Source\n");
    scanf("%d", &source);
    if (bellman(g, v, k, edge, source))
    {
        printf("No negative weight cycle exist");
    }
    else
    {
        printf("Negative weight cycle exists");
    }
}
