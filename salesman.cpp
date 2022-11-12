#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstddef>
#include <ctime>
#include <math.h>
#include <iostream>

int** generateGraph(int const *size);
void showGraph(int** const graph,int const *size);
void preciseMethod(int** const graph, int const *size);
int fac(int n);

int main(){
    int size = 5;
    int **graph = generateGraph(&size);
    showGraph(graph,&size);
    preciseMethod(graph, &size);
    delete[] graph;
   return 0;
}

int fac(int n){
    if(n > 1)
       return n*fac(n-1);
    else
        return 1;
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
               graph[i][j] = std::rand() % 100 + 1;
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
           printf("%10d",graph[i][j]);
       }
       puts("");
   }
}

void preciseMethod(int** const graph, int const *size){
    int way = 0;
    int minimalWay = 1e2 * *size;
    int reshuffle[*size];
    for(int i = 0; i < *size; ++i){
        reshuffle[i] = i;
    }
    do{
        way = 0;
        for(int i = 0; i < *size-1; ++i){
            way += graph[reshuffle[i]][reshuffle[i+1]];
        }
        if(way < minimalWay){
            minimalWay = way;
            for(int i = 0; i < *size; ++i){
                printf("%d - ",reshuffle[i]+1);
            }
            puts("");
        }
    }while(std::next_permutation(reshuffle+1,reshuffle+*size));
    printf("minimalway  - %d\n",minimalWay);
}
