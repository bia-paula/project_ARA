#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

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
        insertEdge(g, line[0], createEdge(line[1], line[2]));


    }
    fclose(fp);

    printGraph(*g);


}