/*
 * Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Hlavičkový soubor pro graph.c
 * Vytvořili: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich, prosinec 2022
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STR_MAX 50

typedef struct Edge {
    bool isEdge;
} TEdge;

typedef struct Graph {
    int V;
    TEdge **array;
} TGraph;

void handleErrs (int code, char *string);
void readFile (int argc, char *argv[]);

void initGraph (TGraph *graph, int V);
void insertConn (TGraph *graph, int v, int e);
void printGraph (TGraph *graph, int V, int cnt);
void isHamiltonian (TGraph *graph);

#endif
