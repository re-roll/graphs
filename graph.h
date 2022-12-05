#ifndef GRAPH_H
#define GRAPH_H

/* Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Hlavičkový soubor pro graph.c
 * Vytvořili: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich, prosinec 2022
*/

#define STR_MAX 100

typedef struct Edge {
    int firstIndex;
    int secondIndex;
} TEdge;

typedef struct Graph {
    int V;
    TEdge *array;
} TGraph;

void initGraph (TGraph *graph, int V);
void insertConn (TGraph *graph, int v, int e, int V);
void printGraph (TGraph *graph, int V);

#endif
