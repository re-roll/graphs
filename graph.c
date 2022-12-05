/*graph.c
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
    printf("%d-%d\n", v, e);
}