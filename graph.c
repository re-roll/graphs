/*
 * graph.c
 * Téma: Hamiltonova cesta a cyklus v grafu 
 * Implementace: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich prosinec 2022
 */
#include "graph.h"

void initGraph (TGraph *graph, int V) {
    graph->V = V;
    graph->array = (TEdge**)malloc(V * sizeof(TEdge*));
    if(graph->array ==NULL){
       exit(1);
    }

    for (int i = 0; i < V; i++)
    {
        graph->array[i] = (TEdge*)malloc(V * sizeof(TEdge));
        if(graph->array[i] == NULL){
            exit(1);
        }
        for (int j = 0; j < V; j++)
        {
            graph->array[i][j].isEdge = 0;
        }   
    }
}

void insertConn (TGraph *graph, int v, int e) {
    graph->array[v][e].isEdge = 1;
}

void printGraph (TGraph *graph, int V, int cnt) {
    printf("[graph %d]\n", cnt);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (j < V-1)
                printf("%d-", graph->array[i][j].isEdge);
            else if (j == V-1)
                printf("%d", graph->array[i][j].isEdge);
        }
        printf("\n");
    }
}

void isHamiltonian (TGraph *graph) {
    if (graph->array[0][0].isEdge == 0)
        printf("Result: It is Hamilton graph\n");
    else
        printf("Result: It is not a Hamilton graph\n"); 
    printf("\n"); 
}