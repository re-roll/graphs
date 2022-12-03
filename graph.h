#ifndef GRAPH_H
#define GRAPH_H

/* Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Hlavičkový soubor pro graph.c
 * Vytvořili: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich prosinec 2022
*/

typedef struct listElement {
    int data;
    struct listElement *nextElement;
} ListElementT;

typedef struct list {
	ListElementT *firstElement;
} ListT;

typedef struct graph{
    int size;
    struct list *array;
} GraphT;

#endif
