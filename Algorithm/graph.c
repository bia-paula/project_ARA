#include "graph.h"
#include <stdlib.h>
#include <stdio.h>



//Creates a new Node v
void createNode(Node *newNode, int tail) {
    newNode->tail = tail;
    newNode->adjList = NULL;
    newNode->routeList = NULL;
}

//Creates an Edge with tail v
Edge* createEdge(int head, int rel){
    Edge* newEdge = malloc(sizeof(Edge));
    newEdge->head = head;
    newEdge->rel = rel;
    newEdge->next = NULL;
    newEdge->prev_t = 0;
    return newEdge;
}

//Create an empty Graph
Graph* createGraph() {
    Graph *g = malloc(sizeof(Graph));
    //Allocate array of nodes
    g->nodes = (Node *) malloc (MAX_N * sizeof(Node));
    g->n = 0;

    //Initialize nodes
    for (int i=0; i<MAX_N; i++)
        createNode(&(g->nodes[i]), i);

    return g;
}

//Inserts Edge tail to Node head
void insertEdge(Graph *g, int tail, Edge *head){
    Node *aux = &(g->nodes[tail]);

    if (aux == NULL){
        perror("Error Inserting Edge");
        exit(1);
    }
    
    //Checks if node was already in graph
    if(!nodeBelongsInGraph(g, tail))
        g->n++; //updates number of nodes

    //Insert at beggining
    head->next = aux->adjList;
    aux->adjList = head;    
}

//Checks if Node v is already in Graph g
int nodeBelongsInGraph(Graph *g, int tail){
    
    if(g->nodes[tail].adjList == NULL)
        return 0;
    else
        return 1;

}

void printGraph(Graph *g){
    Edge *e;

    printf("#Nodes: %d\n", g->n);

    for(int i=0; i<MAX_N; i++){
        if(nodeBelongsInGraph(g,i)) 
            printf("\nTail: %d\n", i);
            e = g->nodes[i].adjList;

            while(e != NULL){
                printf("\t Head: %d Rel: %d\n", e->head, e->rel);
                e = e->next;
            }

    }

}