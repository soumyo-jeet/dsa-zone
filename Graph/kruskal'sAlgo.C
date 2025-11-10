#include<stdio.h>
#include<stdlib.h>
#include<climits>

typedef struct MinSpanTree {
    int arr[20];
    int i;
} minSpanTree;

typedef struct EdgeDiary {
    int val, u, v;
} edgeDiary;

void adjacencyMat(int mat[20][20], int v)
{
    printf("Give the adjacency matrix: ");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int totalEdges(int mat[20][20], int v)
{
    int totalE = 0;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i < j)
            {
                if(mat[i][j] != 0) totalE ++;
            }
        }
    }

    return totalE;
}

void initParent(int arr[20], int v)
{
    for(int i = 0; i < v; i++)
    {
        arr[i] = i;
    }
}

void initRank(int arr[20], int v)
{
    for(int i = 0; i < v; i++)
    {
        arr[i] = 0;
    }
}

edgeDiary *createSortedEdgeDiary (int mat[20][20], int s) 
{
    int totalE = totalEdges(mat, s);
    edgeDiary *ed = (edgeDiary *) malloc(sizeof(edgeDiary) * totalE);
    int id = 0;

    while(id < totalE)
    {
        int minE = INT_MAX, u, v;
        for(int i = 0; i < s; i ++)
        {
            for(int j = 0; j < s; j ++)
            {
                if(mat[i][j] != 0 && minE >= mat[i][j])
                {
                    minE = mat[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ed[id].val = minE;
        ed[id].u = u;
        ed[id].v = v;
        mat[u][v] = 0;
        mat[v][u] = 0;

        id++;
    }

    return ed;
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

int getParent(int v, int parent[])
{
    if(v == parent[v]) return v;

    // branch compress
    parent[v] = getParent(parent[v], parent);
    return parent[v];
}

// merge smaller set to larger set ( merge by parents ) -> disjoint merge
void unionByRank(int u, int v, int pu, int pv, int rank[], int parent[])
{
    if(rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }

    else if(rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }

    else
    {
        parent[pv] = pu;
        rank[pu] ++;
    }
}


void kruskalAlgo(edgeDiary *ed, int e, int v)
{
    minSpanTree *t = initMinSpanTree(v);
    int cost = 0, ec = 0, id = 0;
    int parent[v], rank[v];
    initParent(parent, v);
    initRank(rank, v);


    while(ec < v - 1 && id < e)
    {
        int u = ed[id].u;
        int v = ed[id].v;
        int pu = getParent(u, parent);
        int pv = getParent(v, parent);


        // same parent => both belongs to same set 
        // => they are already connected 
        // => further edge will make a cycle
        if(pu != pv)
        {
            unionByRank(u, v, pu, pv, rank, parent);
            cost += ed[id].val;
            t[u].arr[t[u].i ++] = v;
            t[v].arr[t[v].i ++] = u;
            ec ++;
        }
        id++;
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
    int totalE = totalEdges(adjMat, v);

    edgeDiary *ed = createSortedEdgeDiary(adjMat, v);
    printf("\nThe edge diary: \n");
    for(int i = 0; i < totalE; i++)
    {
        printf("%d -> %d, %d\n", ed[i].val, ed[i].u, ed[i].v);
    }



    kruskalAlgo(ed, totalE, v);

    free(ed);
}