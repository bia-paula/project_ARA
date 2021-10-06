#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int MAX_N = 65535; //maximum number of nodes in an internet

//Creates a new Node v
void createNode(Node *newNode) {
    newNode->adjList = NULL;
}

//Creates an Edge with tail v
Edge* createEdge(int tail, int rel){
    Edge* newEdge = malloc(sizeof(Edge));
    newEdge->tail = tail;
    newEdge->rel = rel;
    newEdge->next = NULL;
    return newEdge;
}

//Create an empty Graph
Graph* createGraph() {
    Graph *g = malloc(sizeof(Graph));
    //Allocate array of nodes
    g->nodes = (Node *) malloc (MAX_N * sizeof(Node));

    //Initialize nodes
    for (int i=0; i<MAX_N; i++)
        createNode(&(g->nodes[i]));

    return g;
}

//Inserts Edge tail to Node head
void insertEdge(Graph *g, int head, Edge *tail){
    Node *aux = &(g->nodes[head]);

    if (aux == NULL){
        perror("Error Inserting Edge");
        exit(1);
    }
    
    //Checks if node was already in graph
    if(!nodeBelongsInGraph(*g, head))
        g->n++; //updates number of nodes

    //Insert at beggining
    tail->next = aux->adjList;
    aux->adjList = tail;    
}

//Checks if Node v is already in Graph g
int nodeBelongsInGraph(Graph g, int head){
    
    if(g.nodes[head].adjList == NULL)
        return 0;
    else
        return 1;

}

void printGraph(Graph g){
    Edge *e;

    printf("#Nodes: %d\n", g.n);

    for(int i=0; i<MAX_N; i++){
        if(nodeBelongsInGraph(g,i)) 
            printf("\nHead: %d\n", i);
            e = g.nodes[i].adjList;

            while(e != NULL){
                printf("\t Tail: %d Rel: %d\n", e->tail, e->rel);
                e = e->next;
            }

    }

}
