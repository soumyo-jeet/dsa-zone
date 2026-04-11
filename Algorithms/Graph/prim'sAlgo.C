#include<stdio.h>
#include<stdlib.h>
#include<climits>

typedef struct MinSpanTree {
    int arr[20];
    int i;
} minSpanTree;

void adjacencyMat(int mat[20][20], int v)
{
    printf("Give the adjacency matrix: ");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

minSpanTree *initMinSpanTree(int v)
{
    minSpanTree *t = (minSpanTree *) malloc(sizeof(minSpanTree) * v);
    for(int i = 0; i < v; i++)
    {
        t[i].i = 0;
    }

    return t;
}

void initVisited(int visited[20], int v)
{
    for(int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
}

int primAlgo(int mat[20][20], int v)
{
    minSpanTree *t = initMinSpanTree(v);
    int visited[20], n = 0, nodes[v], cost = 0;
    initVisited(visited, v);

    nodes[n ++] = 0, visited[0] = 1;

    // untill traverising through all the vertices
    while(n < v)
    {
        int minE = INT_MAX, minR, minC;

        // consider the rows of the vertices has been a part of the nodes array (considered vertices)
        for(int i = 0; i < n; i ++)
        {
            int r = nodes[i];

            // find the post vertex connected by the minimum edge
            for(int j = 0; j < v; j ++)
            {
                if(mat[r][j] != 0 && minE >= mat[r][j] && visited[j] != 1)
                {
                    minE = mat[r][j];
                    minR = r;
                    minC = j;
                }
            }

        }

        // mark the found vertex as considered
        nodes[n ++] = minC;
        visited[minC] = 1;
        t[minR].arr[t[minR].i ++] = minC;
        t[minC].arr[t[minC].i ++] = minR;
        cost += minE;
    }

    printf("\nMST: \n");
    for(int i = 0; i < v; i++)
    {
        printf("Vertex %d:-> ", i);
        for(int j = 0; j < t[i].i; j ++)
        {
            printf("%d ", t[i].arr[j]);
        } 
        printf("\n");    
    }

    printf("cost: %d\n", cost);

    free(t);
}

int main()
{
    int v;
    printf("Number of vertices: ");
    scanf("%d", &v);
    int adjMat[20][20];
    adjacencyMat(adjMat,v);

    primAlgo(adjMat, v);
}