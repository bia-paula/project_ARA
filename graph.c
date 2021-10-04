#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

//Creates a new Node v
Node* createNode(int head) {
    Node* newNode = malloc(sizeof(Node));
    newNode->head = head;
    newNode->next = NULL;
    newNode->adjList = NULL;
    return newNode;
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
  g->n = 0;
  g->nodes = NULL;
  return g;
}

//Inserts newNode to Graph g
void insertNode(Graph *g, Node *newNode){
    //Increment number of nodes
    g->n++;
    //Insert at beggining
    newNode->next = g->nodes;
    g->nodes = newNode;
}

//Inserts Edge tail to Node head
void insertEdge(Graph *g, int head, Edge *tail){
    Node *aux = g->nodes;

    while(aux != NULL){
        if (aux->head == head){
            //Insert at beggining
            tail->next = aux->adjList;
            aux->adjList = tail;
            break;
        }
        aux = aux->next;
    }

    if (aux == NULL){
        perror("Error Inserting Edge");
        exit(1);
    }
}

//Checks if Node v is already in Graph g
int nodeBelongsInGraph(Graph *g, int head){
    int ret = 0;
    Node *aux = g->nodes;

    while(aux !=NULL){
        if(aux->head == head){
            ret = 1;
            break;
        }
        aux = aux->next;
    }

    return ret;

}

void printGraph(Graph *g){
    Node *n = g->nodes;
    Edge *e;

    printf("#Nodes: %d\n", g->n);

    while (n != NULL){
        printf("\nHead: %d\n", n->head);
        e = n->adjList;

        while(e != NULL){
            printf("\t Tail: %d Rel: %d\n", e->tail, e->rel);
            e = e->next;
        }
        n = n->next;
    }
}
