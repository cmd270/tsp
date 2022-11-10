#include <stdio.h>

int** generateGraph(int const *size);

int main(void) {
    int size = 5;
    generateGraph(&size);
    puts("Hello world!");
}

int** generateGraph(int const *size){
    int graph[*size][*size] = {0} ;
    size_t i;
    size_t j;
    for(i = 0; i < *size; ++i){
        for(j = 0; j < *size; ++j){

        } 
    }
    return graph;
}
