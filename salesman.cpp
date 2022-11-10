#include <cstdlib>
#include <stdio.h>
#include <cstddef>
#include <ctime>
#include <iostream>

int** generateGraph(int const size);
void showGraph(int** const graph,int const *size);

int main(){
    int size = 5;
    int **graph = generateGraph(size);
    showGraph(graph,&size);
   return 0;
}

int** generateGraph(int const size){
   int **graph = new int* [2];
   graph[0] = new int[size];
   graph[1] = new int[size];
   std::srand(std::time(NULL));
   ptrdiff_t i,j;
   for(i = 0; i < size; ++i){
       for(j = 0; j < size;++i){
           if(i == j){
              graph[i][j] = 0;
           }
           else{
               graph[i][j] = std::rand() % ( 100 - 1 +1);
               graph[j][i] = graph[i][j];
           }
       }
   }
   return graph;
}

void showGraph(int** const graph,int const *size){
   ptrdiff_t i,j;
   for(i = 0; i < *size; ++i){
       for(j = 0; j < *size; ++j){
           printf("%5d",graph[i][j]);
       }
       puts("");
   }
}
