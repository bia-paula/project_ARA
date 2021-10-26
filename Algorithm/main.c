#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "algorithm.h"

int main( int argc, char *argv[] ) {

    if (argc != 2){
        perror("Command Line incorrect format: ./main <internetFile>");
        exit(1);
    }
    //Open File
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        perror("Unable to open file!");
        exit(1);
    }

    char buffer[128];
    char *ptr;

    int line[3], i = 0;

    //Maximum number of nodes is 
    Graph *g = createGraph();

    //Read Line
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        i = 0;
        ptr = strtok(buffer, " ");
        while(ptr != NULL){
            if(i == 3){
                perror("File Line in wrong format!");
                exit(1);
            }

            line[i] = atoi(ptr);
            ptr = strtok (NULL, " ");
            i++;
        }

        //Create and Insert Edge
        //List of in-neighbors for each node
        insertEdge(g, line[1], createEdge(line[0], line[2]));


    }
    fclose(fp);

    //printGraph(g);

    int type_cnt[4];
    int *len_cnt = malloc(g->n * sizeof(int));

    //Initialize counters
    for(int i=0; i<4; i++)
        type_cnt[i] = 0; 
    for(int i=0; i<g->n; i++)
        len_cnt[i] = 0; 

    for(int i=0; i<MAX_N; i++){
        if(nodeBelongsInGraph(g,i)){
            reverseDijkstra(g,1,type_cnt,len_cnt);
        }           
    }  

    for(int i=0; i<4; i++)
        printf("Type %d: %d\n", i+1, type_cnt[i]); 
    for(int i=0; i<g->n; i++)
        printf("Len %d: %d\n", i, len_cnt[i]); 

    free(len_cnt);
    freeGraph(g);
    
}