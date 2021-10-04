#ifndef _GRAPHH_
#define _GRAPHH_

typedef struct node{
    int head;
    struct edge *adjList;
    struct node *next;
} Node;

typedef struct edge{
    int tail;
    int rel;
    struct edge *next;
    
} Edge;

typedef struct graph{
    int n;
    Node *nodes;
    
} Graph;

Node* createNode(int v);
Edge* createEdge(int v, int rel);
Graph* createGraph();
void insertNode(Graph *g, Node *newNode);
void insertEdge(Graph *g, int head, Edge *e);
int nodeBelongsInGraph(Graph *g, int v);
void printGraph(Graph *g);

#endif