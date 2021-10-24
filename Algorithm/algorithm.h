#ifndef _ALGOH_
#define _ALGOH_

#include "graph.h"
#include "heap.h"


typedef struct qnode{
    int id;
    int attributes[2];
    struct qnode *next;
} Qnode;


void reverseDijkstra(Graph *g, int s, int *type_cnt, int *len_cnt);
void printPaths(int t, int *tree, Graph *g);





#endif
