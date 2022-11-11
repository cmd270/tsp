#include <cstdlib>
#include <stdio.h>
#include <cstddef>
#include <ctime>
#include <iostream>

int** generateGraph(int const *size);
void showGraph(int** const graph,int const *size);

int main(){
    int size = 5;
    int **graph = generateGraph(&size);
    showGraph(graph,&size);
   return 0;
}

int** generateGraph(int const *size){
   int **graph = new int* [*size];
   for(int i = 0; i < *size; ++i){
       graph[i]=new int[*size];
   }
   std::srand(std::time(NULL));
   for(int i = 0; i < *size; ++i){
       for(int j = 0; j < *size;++j){
           if(i == j){
              graph[i][j] = 0;
           }
           else{
               graph[i][j] = std::rand() % 30;
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
