#include <algorithm>
#include <stdio.h>
#include <ctime>
#include <cstring>
#include <math.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <set>
#include <fstream>

#define X 1280
#define Y 720

void generate_graph(int const size);
void show_graph(int const size);
void precise_method(int const size); // Метод перебора (точный)
void greedy_method( int const size); // Жадный метод (неточный)
int** prim_algorithm(int const size);
void wooden_algorithm(int const size);
void euler_loop(int const size, int** mst);

int graph[100][100];    // Граф максимального числа городов
int size = 5;           // Счетчик городов

int main(void){
    generate_graph(size);
    show_graph(size);
    // precise_method(size);
    // greedy_method(size);
    wooden_algorithm(size);
}

// Генерация графа.
// Осуществляется как рассчет расстояний между точками.
// Точки создаются случайно в пределах двух констант X и Y.
void generate_graph(int const size){
    srand(time(NULL));
    std::pair <int,int> points[size];   // Заводим массив пар точек(x,y)
    for(int i = 0; i < size; ++i){      
        points[i] = std::make_pair(std::rand() % X + 1,std::rand() % Y + 1); // Создаем случайно точку ограниченую по констам X и Y
        printf("%d. (%d,%d)\n",i+1,points[i].first,points[i].second);
    }
    for(int i = 0; i < size; ++i){
        for(int j = i+1; j < size;++j){
            graph[i][j] =   (int)ceil(sqrt(pow(points[i].first - points[j].first, 2)
                            + pow(points[i].second - points[j].second, 2))); // Эквивалент рассчета расстояния между точками
            graph[j][i] = graph[i][j]; // Смежность
        }
    }
}

void show_graph(int const size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            printf("%10d",graph[i][j]);
        }
        printf("\n");
    }
}

// Метод перебора.
// Совершает перебор всех возможных комбинаций (n-1)!, где n-количество городов
// Попутно в каждом туре считается путь и сравнивается с минимальным путем,
// Который имеется на данный момент.
void precise_method(int const size){
    printf("*** precise_method ***\n");
    int tour_len = 0;
    int minimal_tour = INT_MAX;
    int* reshuffle = new int[size+1]; // Заводим массив для комбинаций
    for(int i = 0; i < size; ++i){ // Первая комбинация
        reshuffle[i] = i;
    }
    reshuffle[size] = 0; // Послединй элемент 0, поскольку нужно вернуться в город
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
    }while(std::next_permutation(reshuffle+1,reshuffle+size)); // Следующая комбинация
    delete[] reshuffle;
    printf("Length of minimal tour: %d\n",minimal_tour);
}

// Жадный метод.
// Каждый проход, выбирает самый короткий путь.
void greedy_method(int const size){  
    printf("*** greedy_method ***\n");
    std::vector<int> no_return = {0};   // Вектор-буфер, запоминающий ход
    int tour_len = 0;
    int to = 0;
    std::string tour = "[1 ";
    for(int i = 0; i < size-1 ; ++i){
        int temp = 0;
        int minimal_path = INT_MAX;
        for(int j = 0; j < size; ++j){
            bool pass = true;
            if(graph[to][j] != 0){
                for(int item : no_return){
                    if(item == j){      // Если такой ход уже был, выходим из цикла
                        pass = false;
                        break;
                    }
                }
                if(graph[to][j] < minimal_path && pass){
                    minimal_path = graph[to][j];
                    temp = j;
                }
            }
        }
        tour_len += minimal_path;
        tour += (std::to_string(temp+1) + " ");
        no_return.push_back(temp);  // Пушим ход
        to = temp; // Запоминаем ход, с которого нужно начинать на следующей итерации
    }
    tour_len += graph[to][0];
    printf("Length of minimal tour: %d\n",tour_len);
    std::cout << "Tour: " << tour+"1]" << std::endl;
}

int** prim_algorithm(int const size){
    int sum_mst = 0, prev_min = 0;
    bool used_to[size];
    bool used_from[size];
    memset(used_from, 0, sizeof(bool) * size);
    int** min_span_tree = new int*[size];
    for(int i = 0; i < size; i++)
        min_span_tree[i] = new int[size];
    used_from[0] = 1;
    for (int i = 0; i < size; i++){
        int h = -1, e = -1, min_edge = INT_MAX;
        for(int k = 0; k < size; k++){
            for(int j = 0; j < size; j++){
                if(graph[k][j] < min_edge && graph[k][j] && used_from[k] && !used_to[j] ){
                    min_edge = graph[k][j];
                    h = k;
                    e = j;
                }
            } 
        }
        if( h != -1 && e != -1){
            min_span_tree[h][e] = min_edge, min_span_tree[e][h] = min_edge;
            used_to[e] = 1, used_from[e] = 1;
            if(prev_min != min_edge){
                sum_mst += min_edge;
                prev_min = min_edge;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%10d",min_span_tree[i][j]);
        }
        printf("\n");
    }
    printf("SUM MST = %d\n",sum_mst);
    return min_span_tree;
}

void euler_loop(int const size, int** mst){
    // int fmst[5][5] = {
    // {0,0,0,720,0},
    // {0,0,160,198,125},
    // {0,160,0,0,0},
    // {720,198,0,0,0},
    // {0,125,0,0,0}};
    printf("***********************************************\n");
    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < size; j++){
    //         printf("%10d",fmst[i][j]);
    //     }
    //     printf("\n");
    // }
    std::ofstream file;
    file.open("matrix.txt");
    if(file.is_open()){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                file <<  " " <<  mst[i][j];
            }
            file << std::endl;
        }
        file << std::endl;
    }
    int prev_v = 0, v = 0;
    int count_v = 1;
    std::vector<int> path = {0};
    while(count_v != size){
        int temp_v = -1;
        for(int j = 0; j < size; ++j){
            if(mst[v][j] != 0){
                temp_v = j;
            }
        }
        if(temp_v != -1){
            printf("mst[%d][%d] = 0, mst[%d][%d] = 0\n",prev_v,temp_v,temp_v,prev_v);
            prev_v = v;
            v = temp_v;
            count_v++;
            mst[prev_v][v] = 0, mst[v][prev_v] = 0;
            path.push_back(v);
        }
        else{
            path.push_back(prev_v);
            v = prev_v;
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                printf("%10d",mst[i][j]);
            }
            printf("\n");
        }
        printf("----\n");
    }

    for(auto item : path){
        printf("%2d ",item+1);
    }
    printf("\n");
}

void wooden_algorithm(int const size){
    euler_loop(size, prim_algorithm(size));
}
