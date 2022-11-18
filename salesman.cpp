#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cstddef>
#include <ctime>
#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#define X 1280
#define Y 720

int** generateGraphByCoord(int const *size);
int** generateGraph(int const *size);
void showGraph(int** const graph,int const *size);
void preciseMethod(int** const graph, int const *size);
void greedyMethod(int** const graph, int const *size);

int main(){
    int size = 5;
    int **graph = generateGraphByCoord(&size);
    showGraph(graph,&size);
    //preciseMethod(graph, &size);
    greedyMethod(graph,&size);
    delete[] graph;
   return 0;
}

int** generateGraphByCoord(int const *size){
    std::srand(std::time(NULL));
    int **graph = new int* [*size];
    std::pair <int,int> points[*size];
    for(int i = 0; i < *size; ++i){
        graph[i]=new int[*size];
        points[i] = std::make_pair(std::rand() % X + 1,std::rand() % Y + 1);
        printf("%d point have coord\nx=%d\ny=%d\n",i+1,points[i].first,points[i].second);
    }
        for(int i = 0; i < *size; ++i){
            for(int j = i+1; j < *size;++j){
                graph[i][j] = (int)ceil(sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2)));
                graph[j][i] = graph[i][j];
            }
        }
   return graph;
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
    int minimalWay = 1e5 * *size;
    int* reshuffle = new int[*size+1];
    for(int i = 0; i < *size; ++i){
        reshuffle[i] = i;
    }
    reshuffle[*size] = 0;
    do{
        for(int i = 0; i < *size + 1; ++i){
            printf("%d - ",reshuffle[i]+1);
        }
        reshuffle[*size] = 0;
        way = 0;
        for(int i = 0; i < *size; ++i){
            way += graph[reshuffle[i]][reshuffle[i+1]]; // ss
        }
        printf("way is %d\n", way);
        if(way < minimalWay){
            minimalWay = way;
        }
    }while(std::next_permutation(reshuffle+1,reshuffle+*size));
    delete[] reshuffle;
    printf("minimalway  - %d\n",minimalWay);
}
//TODO : greedyMethod
void greedyMethod(int** const graph, int const *size){
    int** graphCopy = graph;
    int way = 0;
    int from = 0;
    int to = 0;
    std::string path = std::to_string(from+1)+"-";
    for(int i = 0; i < *size -1 ; ++i){
        int minimalPath = 1e5* *size;
        for(int j = 1; j < *size; ++j){
            if(from != j){
                if(minimalPath > graphCopy[from][j] && graphCopy[from][j] != -1){
                    minimalPath = graphCopy[from][j];
                    to = j;
                }
            }
        }
        for(int k = 0; k < *size; ++k){ // no way
            graphCopy[k][to] = -1;
        }
        way += minimalPath;
        from = to;
        path += std::to_string(from+1);
        path += "-";
    }
    way += graphCopy[from][0];
    path += "1";
    printf("minimalWay - %d\n",way);
    std:: cout << "path is " << path << std::endl;
}
