#ifndef GRAPH_H
#define GRAPH_H

/* Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Hlavičkový soubor pro graph.c
 * Vytvořili: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich, prosinec 2022
*/

typedef struct ListElement {
    int data;
    struct ListElement *nextElement;
} ListElementT;

typedef struct List{
	ListElementT *firstElement;
} ListT;

typedef struct Graph{
    int size;
    struct list *array;
} GraphT;

#endif
