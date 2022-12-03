#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/* Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Hlavičkový soubor pro graph.c
 * Vytvořili: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich, prosinec 2022
*/

typedef struct ListElement {
    int data;
    struct ListElement *nextElement;
} *ListElementPtr;

typedef struct List{
	ListElementPtr firstElement;
} ListT;

typedef struct Graph{
    int V;
    struct List *array;
} GraphT;

void initNode (int data);
void initGraph (int V);
void readGraph (char *text);

#endif
