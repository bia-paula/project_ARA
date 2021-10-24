#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "graph.h"

List * createList(){
    List *new = malloc(sizeof(List));

    new->first = NULL;
    new->last = NULL;

    return new;
}

void insertEndList(List *list, LNode *node){
    node->prev = list->last;
    list->last = node;

    if(list->first == NULL)
        list->first = node;
}

LNode* removeLNode(List *list){
    LNode *res = list->first;

    list->first = res->next;

    if(list->first != NULL)
        list->first->prev = NULL;
    
    return res;
}
















Heap * createHeap(){
    Heap *new = malloc(sizeof(Heap));

    new->h_arr = (int *)malloc(MAX_N * sizeof(int));
    new->size = 0;
    new->pos = (int*)malloc(MAX_N * sizeof(int));

    return new;

}

int parentHeap(int id){
    return (id-1)/2;
}

int leftSonHeap(int i){ 
    return (2*i + 1); 
}
  
int rightSonHeap(int i){ 
    return (2*i + 2);
}
  
// 1 if y < x
// 0 o.w. 
int compareAttributes(int *att_x, int *att_y){
    //Compare paths types of relationship first
    if (att_x[0] < att_y[0]){
        return 0;
    }
    else if (att_y[0] < att_x[0]){
        return 1;
    }
    //For the same relation untie with path length
    else if (att_y[1] < att_x[1]){
        return 1;
    }
    else {
        return 0;
    } //In case of tie consider x    
}

void swapHeap(Heap *heap, int i, int j){
    int node_i = heap->h_arr[i];
    int node_j = heap->h_arr[j];

    //Switch on position array
    heap->pos[node_i] = j;
    heap->pos[node_j] = i;

    //Switch on heap
    heap->h_arr[i] = node_j;
    heap->h_arr[j] = node_i;
}

void bubbleUpHeap(Heap *heap, int i, int **attributes){
    int node_i = heap->h_arr[i];
    int parent_i = heap->h_arr[parentHeap(i)];

    printf("Node %d on pos %d with parent on pos %d\n", node_i, i, parentHeap(i));
    printf("%d with [%d, %d] %d with [%d,%d]\n", node_i,attributes[node_i][0], attributes[node_i][1], parent_i, attributes[parent_i][0], attributes[parent_i][1] );
    //Rearrange to maintain min heap property
    //heap->h_arr[parentHeap(i)] > heap->h_arr[i])
    while (i != 0 && compareAttributes(attributes[parent_i], attributes[node_i])){
        printf("Swapping %d and %d\n", node_i,parent_i);
        swapHeap(heap, parentHeap(i), i);
        //Climb heap and continue to check
        i = parentHeap(i); 
        node_i = heap->h_arr[i];
        parent_i = heap->h_arr[parentHeap(i)];
    }
}

void bubbleDownHeap(Heap *heap, int i, int **attributes){
    int l = leftSonHeap(i);
    int r = rightSonHeap(i);
    int node_l = heap->h_arr[l];
    int node_r = heap->h_arr[r];
    int node_i = heap->h_arr[i];

    int smallest = i;

    if (l < heap->size && compareAttributes(attributes[node_i], attributes[node_l]))
        smallest = l;
    if (r < heap->size && compareAttributes(attributes[heap->h_arr[smallest]], attributes[node_r]))
        smallest = r;
    if (smallest != i){
        swapHeap(heap, i, smallest);
        bubbleDownHeap(heap, smallest, attributes);
    }
}

void insertHeap( Heap *heap, int id, int **attributes){
    int i = heap->size;
    heap->size++;

    //Insert node at end of heap
    heap->h_arr[i] = id; 
    //Save position of node
    heap->pos[id] = i;

    bubbleUpHeap(heap, i, attributes);
}

void changeValueAttr(Heap *heap, int id, int type, int len, int **attributes){
    int old_att[2];
    int i = heap->pos[id];

    old_att[0] = attributes[id][0];
    old_att[1] = attributes[id][1];

    attributes[id][0] = type;
    attributes[id][1] = len;

    //If new values are better -> bubble up
    if(compareAttributes(old_att, attributes[id])){
        bubbleUpHeap(heap, i, attributes);
    }
        
    else{
        bubbleDownHeap(heap, i, attributes);
    }    
}

int getMinHeap(Heap *heap, int **attributes){
    int root = heap->h_arr[0];

    heap->pos[root] = -1;

    if(heap->size == 1){
        heap->size--;
        return root;
    }

    heap->h_arr[0] = heap->h_arr[heap->size-1];
    heap->pos[heap->h_arr[0]] = 0;

    heap->size--;

    bubbleDownHeap(heap, 0, attributes);

    return root;
}

int * extensionOperation(int *att_x, int *att_y, int *res){
    if (att_x[0] == 4 || att_y[0] == 4){
        res[0] = 4;
    } else if(att_x[0] == 3 || att_y[0] == 1){
        res[0] = att_x[0];
        res[1] = att_x[1] + att_y[1];
    } else{
        res[0] = 4;
    }
    return res;
}

void printHeap(Heap *heap, int **att){
    int node;
    for(int i=0; i<heap->size; i++){
        node = heap->h_arr[i];
        printf("Node %d: att [%d, %d]\n",node, att[node][0], att[node][1]);
    }

    printf("Heap: [");
    for(int i=0; i<heap->size; i++){
        printf("%d,", heap->h_arr[i]);
    }
    printf("]\n");

    printf("Pos: [");
    for(int i=1; i<12; i++){
        printf("%d,", heap->pos[i]);
    }
    printf("]\n");
}
