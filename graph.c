/*
 * graph.c
 * Téma: Hamiltonova cesta a cyklus v grafu 
 * Implementace: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich prosinec 2022
 */
#include "graph.h"


/*Function writting down our counts of nodes in the structure. 
Allocate the right amount of memory for two dimensional arrays. 
Filling the array with zeros. */
void initGraph (TGraph *graph, int V) {
    graph->V = V;
    graph->array = (TEdge**)malloc(V * sizeof(TEdge*));
    if(graph->array ==NULL)
       exit(1);

    for (int i = 0; i < V; i++)
    {
        graph->array[i] = (TEdge*)malloc(V * sizeof(TEdge));
        if(graph->array[i] == NULL)
            exit(1);
        for (int j = 0; j < V; j++)
            graph->array[i][j].data = 0;
    }
}
//function of initializing paths
void initPath (TPath *path, int V) {
    path->V = V;
    path->array = (TEdge*)malloc(V * sizeof(TEdge));
    if(path->array ==NULL)
       exit(1);

    for (int i = 0; i < V; i++)
        path->array[i].data = 0;
}

/*pass index with 1 placing, and writting down in our 0 matrix,
 which  we initializing with procedure of initGraph. In the same index we writting down 1 */
void insertConn (TGraph *graph, int v, int e) { 
    graph->array[v][e].data = 1; 
}
/*Fuction of printing graph with correct way.*/
void printGraph (TGraph *graph, int V, int cnt) {
    printf("[graph %d]\n", cnt);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (j < V-1)
                printf("%d-", graph->array[i][j].data); 
            else if (j == V-1)
                printf("%d", graph->array[i][j].data);
        }
        printf("\n");
    }
}
//algoritm of Hamiltonian graph search
bool algo (TGraph *graph, TPath *path, int curr_node, int V) {
    if (curr_node + 1 == V) 
    {
        if (graph->array[path->array[curr_node].data][path->array[0].data].data == 1)
            return true;
        else
            return false;
    }
    
    for (int i = 1; i < V; i++)
    {
        if ((graph->array[path->array[curr_node].data][i].data) == 1)
        {
            for (int j = 0; j < curr_node+1; j++)
                if (path->array[j].data == i)
                    return false;

            path->array[curr_node + 1].data = i;

            if (algo (graph, path, curr_node+1, V))
                return true;
            
            path->array[curr_node + 1].data = 0;
        }
    }
    
    return false;
}
//function of creating, initializing, cheching & making output out of path
bool cycle (TGraph *graph, int V) {
    TPath path;
    initPath(&path, V);

    int curr_node = 0;

    if (algo(graph, &path, curr_node, V))
    {
        printf("Result: It is a Hamilton graph\n");
        printf("Hamilton cycle is ");
        for (int i = 0; i < V; i++)
            printf("%d-", path.array[i].data);
        printf("%d\n", path.array[0].data);
        printf("\n");
        return true;
    }
    printf("Result: It is not a Hamilton graph\n");
    printf("\n");
    return false;
}