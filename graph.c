/*graph.c
* Téma: Hamiltonova cesta a cyklus v grafu 
* Implementace: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich prosinec 2022
*/
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initGraph (TGraph *graph, int V) {
    graph->V = 0;

    for (int i = 0; i < V; i++)
    {
        graph->array[i].firstIndex = 0;
        graph->array[i].secondIndex = 0;
    }
}

void insertConn (TGraph *graph, int v, int e, int V) {
    graph = (TGraph*)malloc(sizeof(struct Graph));

    if (graph == NULL)
        exit(1);

    graph->array = (TEdge*)malloc(V * sizeof(struct Edge));

    if (graph->array == NULL)
        exit(1);
    
    initGraph(graph, V);

    graph->V = V;
    graph->array->firstIndex = v;
    graph->array->secondIndex = e;

    printGraph(graph, V);
}

void printGraph (TGraph *graph, int V) {
    char matrix[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if ((i == graph->array->firstIndex) && (j == graph->array->secondIndex))
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }

    matrix[graph->array->firstIndex][graph->array->secondIndex] = 1;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}