#ifndef _GRAPHH_
#define _GRAPHH_

typedef struct node{
    struct edge *adjList;
} Node;

typedef struct edge{
    int tail;
    int rel;
    struct edge *next;   
} Edge;

typedef struct graph{
    Node *nodes;
    int n;
} Graph;

void createNode(Node *newNode);
Edge* createEdge(int v, int rel);
Graph* createGraph();
void insertEdge(Graph *g, int head, Edge *e);
int nodeBelongsInGraph(Graph g, int head);
void printGraph(Graph g);

#endif