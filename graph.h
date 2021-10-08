#ifndef _GRAPHH_
#define _GRAPHH_

#define MAX_N 65535 //maximum number of nodes in an internet

typedef struct edge{
    int tail;
    int rel;
    struct edge *next;
    int prev_t;   
} Edge;

typedef struct route{
    int dest;
    int length;
    Edge *via;
} Route;

typedef struct node{
    int head;
    Edge *adjList;
    Route *routeList;
} Node;

typedef struct graph{
    Node *nodes;
    int n;
} Graph;

void createNode(Node *newNode, int head);
Edge* createEdge(int v, int rel);
Graph* createGraph();
void insertEdge(Graph *g, int head, Edge *e);
int nodeBelongsInGraph(Graph *g, int head);
void printGraph(Graph *g);

#endif