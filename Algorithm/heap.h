#ifndef _HEAPH_
#define _HEAPH_

typedef struct lnode{
    int id;
    struct lnode *prev;
    struct lnode *next;
} LNode;

typedef struct list{
    LNode *first;
    LNode *last;
} List;

typedef struct heap{
    int *h_arr;
    int size;
    int *pos;
} Heap;

Heap * createHeap();
void freeHeap(Heap *heap);
int parentHeap(int id);
int leftSonHeap(int i);
int rightSonHeap(int i);

void swapHeap(Heap *heap, int i, int j);
void bubbleUpHeap(Heap *heap, int i, int **attributes);
void bubbleDownHeap(Heap *heap, int i, int **attributes);
void insertHeap( Heap *heap, int id, int **attributes);
int getMinHeap(Heap *heap, int **attributes);
void printHeap(Heap *heap, int **att);

int compareAttributes(int *att_x, int *att_y);
void changeValueAttr(Heap *heap, int id, int type, int len, int **attributes);
int * extensionOperation(int *x, int *y, int *res);

#endif