#include <algorithm>
#include <stdio.h>
#include <ctime>
#include <math.h>
#include <iostream>
#include <limits.h>

#define X 1280
#define Y 720

void generate_graph(int const size);
void show_graph(int const size);
void precise_method(int const size); // Метод перебора (точный)
void greedy_method( int const size); // Жадный метод (неточный)

int graph[100][100];    // Граф максимального числа городов
int size = 5;           // Счетчик городов

int main(void){
    generate_graph(size);
    show_graph(size);
    precise_method(size);
    //greedy_method(size);
}

void generate_graph(int const size){
    std::pair <int,int> points[size];   // Заводим массив пар точек(x,y)
    for(int i = 0; i < size; ++i){      
        points[i] = std::make_pair(std::rand() % X + 1,std::rand() % Y + 1); // Создаем случайно точку ограниченую по констам X и Y
        printf("%d. (%d,%d)\n",i+1,points[i].first,points[i].second);
    }
    for(int i = 0; i < size; ++i){
        for(int j = i+1; j < size;++j){
            graph[i][j] =   (int)ceil(sqrt(pow(points[i].first - points[j].first, 2)
                            + pow(points[i].second - points[j].second, 2))); // Эквивалент рассчета расстояния между точками
            graph[j][i] = graph[i][j];
        }
    }
}

void show_graph(int const size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            printf("%10d",graph[i][j]);
        }
        puts("");
    }
}

void precise_method(int const size){
    int tour_len = 0;
    int minimal_tour = INT_MAX;
    int* reshuffle = new int[size+1];
    for(int i = 0; i < size; ++i){
        reshuffle[i] = i;
    }
    reshuffle[size] = 0;
    do{
        printf("[ ");
        for(int i = 0; i < size + 1; ++i){
            printf("%d ",reshuffle[i]+1);
        }
        printf("] - ");
        reshuffle[size] = 0;
        tour_len = 0;
        for(int i = 0; i < size; ++i){
            tour_len += graph[reshuffle[i]][reshuffle[i+1]]; 
        }
        printf("%d\n", tour_len);
        if(tour_len < minimal_tour){
            minimal_tour = tour_len;
        }
    }while(std::next_permutation(reshuffle+1,reshuffle+size));
    delete[] reshuffle;
    printf("Length of minimal tour is: %d\n",minimal_tour);
}

// void greedyMethod(int const size){  
//     int** graphCopy = graph;
//     int way = 0;
//     int from = 0;
//     int to = 0;
//     std::string path = std::to_string(from+1)+"-";
//     for(int i = 0; i < *size -1 ; ++i){
//         int minimalPath = 1e5* *size;
//         for(int j = 1; j < *size; ++j){
//             if(from != j){
//                 if(minimalPath > graphCopy[from][j] && graphCopy[from][j] != -1){
//                     minimalPath = graphCopy[from][j];
//                     to = j;
//                 }
//             }
//         }
//         for(int k = 0; k < *size; ++k){ // no way
//             graphCopy[k][to] = -1;
//         }
//         way += minimalPath;
//         from = to;
//         path += (std::to_string(from+1)+"-");
//     }
//     way += graphCopy[from][0];
//     path += "1";
//     printf("minimalWay - %d\n",way);
//     std:: cout << "path is " << path << std::endl;
// }
