#include <stdlib.h>
#include <stdio.h>
#include "algorithm.h"

void reverseDijkstra(Graph *g, int t, int *type_cnt, int *len_cnt){
    Node v;
    Edge *u = NULL;
    int l[2];
    int new_est[2];
    int **attributes = malloc(MAX_N * sizeof(int *)); //Vector with atributes for each node: fist is rel, second is path length
    int *child = malloc(MAX_N * sizeof(int)); //Vector with parent of each node;

    int *aux = malloc(MAX_N*2*sizeof(int)); //Aux for attribute for continuous memory

    Heap *heap = createHeap(g->n);

    for(int i=0; i<MAX_N; i++){
        attributes[i] = &aux[i*2];

        //Check if node exists in graph
        if(!nodeBelongsInGraph(g, i)) continue; 

        attributes[i][0] = 4;
        attributes[i][1] = 0;
        child[i] = -1;

        insertHeap(heap, i, attributes);
    }

    printHeap(heap,attributes);

    changeValueAttr(heap, t, 1, 0, attributes);

    while(heap->size > 0){
        printf("\nCurrent heap\n");
        printHeap(heap, attributes);
        v = g->nodes[getMinHeap(heap, attributes)];
        u = v.adjList;
        printf("AFTER REMOVING HEAD\n");
        printHeap(heap, attributes);

        printf("Extending node %d with att [%d,%d]\n", v.tail, attributes[v.tail][0], attributes[v.tail][1]);
        

        //Update counters with best path found to v
        type_cnt[attributes[v.tail][0]-1]++;
        len_cnt[attributes[v.tail][1]]++;

        if(attributes[v.tail][1] == 0)
            printf("Node %d has len 0 to %d\n", v.tail, t);

        //u is in neighbor of v
        while(u != NULL){
            //Comparar atributos
            l[0] = u->rel;
            l[1] = 1;
            extensionOperation(l,attributes[v.tail], new_est);

            if (compareAttributes(attributes[u->head], new_est)){
                changeValueAttr(heap, u->head, new_est[0], new_est[1], attributes);
                child[u->head] = v.tail;
                printf("AFTER CHANEG----------\n");
                printHeap(heap, attributes);
            }
            u = u->next;
        }
    }

    printPaths(t, child, g);
}

void printPaths(int t, int *tree, Graph *g){
    printf("\n-- Paths to %d --\n", t);
    for(int i=0; i<MAX_N; i++){
        if (nodeBelongsInGraph(g,i))
            printf("%d -> %d\n", i, tree[i]);
    }
}







void insertQueue(Qnode **Q, int i, int attributes[2]){
    
    Qnode *new = malloc(sizeof(Qnode));

    new->id = i;
    new->attributes[0] = attributes[0];
    new->attributes[1] = attributes[1];

    new->next = *Q;
    *Q = new;
}




