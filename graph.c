/*graph.c
* Téma: Hamiltonova cesta a cyklus v grafu 
* Implementace: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich prosinec 2022
*/
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initNode(int data) {
    ListElementPtr newNode= (ListElementPtr)malloc(sizeof(struct ListElement));

    if (newNode == NULL)
        exit(1);
    
    newNode->data = data;
    newNode->nextElement = NULL;
}

void initGraph (int V) {
    GraphT *graph = (GraphT*)malloc(sizeof(struct Graph));

    if (graph == NULL)
        exit(1);
    
    graph->V = V;
    graph->array = (ListT*)malloc(V * sizeof(struct List));

    if (graph->array == NULL)
        exit(1);
    
    for (int i = 0; i < V; i++)
        graph->array[i].firstElement = NULL;
}

void readGraph (char *text) {
    
}
