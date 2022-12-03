#ifndef GRAPH_H
#define GRAPH_H

/* Předmět: Algoritmy (IAL) - FIT VUT v Brně
 * Hlavičkový soubor pro graph.c
 * Vytvořili: Oleksii Fedorchenko, Dmitrii Ivanuhskin, Zlata Valakhanovich prosinec 2022
*/

typedef struct {
    int data;
    struct ListElement *nextElement;
} ListElement;

typedef struct {
	ListElement *firstElement;
} List;

typedef struct {
    int size;
    struct List *array;
} Graph;

#endif
