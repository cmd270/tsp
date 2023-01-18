// ⢛⣽⡟⠁⠄⠄⣀⡠⠔⠂⠈⠄⠄⠄⡀⠠⡀⠄⠄⠄⠄⠄⠄⠉⠉⠛⠿⢶⣦⣤⣄⣘⢦
// ⣾⠏⢀⣠⡶⠛⠁⠄⠄⠄⣰⠄⠄⣼⣷⡀⢻⣷⣤⡀⠄⢀⡀⠄⠄⠄⠄⠄⠈⠙⠻⣿⣿
// ⣯⣴⠟⠋⠄⠄⠄⢠⡎⢰⣿⡇⢰⣿⣿⣿⣜⣿⣿⣿⣄⠘⣿⣄⠄⠄⠄⠄⠄⠄⠄⠄⠙
// ⠟⠁⠄⠄⠄⠄⢠⣿⣇⣿⠿⢻⣸⣿⣿⣟⢉⡛⠻⠿⣿⣷⣿⣿⡆⣦⠄⠄⠄⠄⠄⠄⠄
// ⠄⠄⠄⠄⣠⡇⣾⣿⣭⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠄⠄⠄⠄⠄⠄
// ⠄⠄⠄⢀⣿⣷⠿⠿⠿⠿⢟⢻⣿⣿⣿⣿⣿⣿⣥⢒⣉⠭⠤⢉⡉⠛⠿⡆⠄⠄⠄⠄⠄
// ⠄⠄⠄⠘⠉⣀⣴⠖⠉⣡⠒⣿⣿⣿⣿⣿⣿⣿⣷⣿⠁⠄⠄⠆⠹⣦⠄⡄⠄⠄⠄⠄⠄
// ⠄⠄⠄⢰⡀⣿⡇⠄⠄⢀⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣠⡄⠠⠄⢀⣏⣼⠁⠄⠄⠄⠄⠄
// ⠄⠄⠄⠈⣿⣾⣿⡴⠶⣁⡤⢸⣿⣿⣿⣿⣿⣿⣋⣉⣦⣝⣚⣃⣾⣿⠏⠄⠄⠄⠄⠄⠄
// ⠄⠄⠄⠄⠘⣿⣿⣿⣶⣾⣿⣿⣿⣏⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣠⡎⠄⠄⠄⠄⠄
// ⠄⠄⠄⠄⢰⣜⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⠁⠄⠄⠄⠄⠄
// ⠄⠄⠄⠄⠄⢿⣿⣿⣿⣿⣿⣿⡛⠛⠉⠉⠉⠉⠉⣽⣿⣿⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄
// ⠄⠄⠄⠄⠄⠈⠻⣿⣿⣿⣿⣿⣧⠄⠄⠄⠄⠄⣴⣿⣿⣿⣿⣿⡿⠋⠄⠄⠄⠄⠄⠄⠄
// ⠄⠄⠄⠄⠄⠄⠄⠄⠉⠛⠿⣿⣿⣿⣶⣶⣶⣿⣿⣿⣿⠟⠋⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠙⠛⠿⠿⠟⠋⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
#include <algorithm>
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <limits.h>
#include <vector>

#define X 1280
#define Y 720

void generate_graph(int const size);
void show_graph(int const size);
void precise_method(int const size); // Метод перебора (точный)
void greedy_method( int const size); // Жадный метод (неточный)
int** prim_algorithm(int const size);
void wooden_algorithm(int const size);
std::vector<int> euler_loop(int const size, int** mst);

int graph[100][100];    // Граф максимального числа городов
int size = 5;           // Счетчик городов
int main(void){
    while(size <= 9){
        printf("ELEMENTS : %d\n",size);
        generate_graph(size);
        //show_graph(size);
        precise_method(size);
        greedy_method(size);
        wooden_algorithm(size);
        size++;
        printf("\n");
    }
}

// Генерация графа.
// Осуществляется как рассчет расстояний между точками.
// Точки создаются случайно в пределах двух констант X и Y.
void generate_graph(int const size){
    srand(time(NULL));
    std::pair <int,int> points[size];   // Заводим массив пар точек(x,y)
    for(int i = 0; i < size; ++i){      
        points[i] = std::make_pair(std::rand() % X + 1,std::rand() % Y + 1); // Создаем случайно точку ограниченую по констам X и Y
    //    printf("%d. (%d,%d)\n",i+1,points[i].first,points[i].second);
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
    clock_t tStart = clock();
    int tour_len = 0;
    int minimal_tour = INT_MAX;
    int* reshuffle = new int[size+1]; // Заводим массив для комбинаций
    for(int i = 0; i < size; ++i){ // Первая комбинация
        reshuffle[i] = i;
    }
    reshuffle[size] = 0; // Послединй элемент 0, поскольку нужно вернуться в город
    do{
        // printf("[ ");
        // for(int i = 0; i < size + 1; ++i){
        //      printf("%d ",reshuffle[i]+1);
        // }
        // printf("] - ");
        reshuffle[size] = 0;
        tour_len = 0;
        for(int i = 0; i < size; ++i){
            tour_len += graph[reshuffle[i]][reshuffle[i+1]]; 
        }
        // printf("%d\n", tour_len);
        if(tour_len < minimal_tour){
            minimal_tour = tour_len;
        }
    }while(std::next_permutation(reshuffle+1,reshuffle+size)); // Следующая комбинация
    printf("Time taken for precise method: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    delete[] reshuffle;
    printf("Length of minimal tour: %d\n",minimal_tour);
}

// Жадный метод.
// Каждый проход, выбирает самый короткий путь.
void greedy_method(int const size){  
    clock_t tStart = clock();
    std::vector<int> no_return = {0};   // Вектор-буфер, запоминающий ход
    int tour_len = 0, to = 0;
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
    printf("Time taken for greedy_method: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("Length of minimal tour: %d\n",tour_len);
    //std::cout << "Tour: " << tour+"1]" << std::endl;
}

// Деревянный алгоритм
// Суть, которого заключается в постройке остовного дерева и получения пути эйлерова цикла
// Полученный путь от эйлеров цикла избавить от дубликатов
// Далее пройтись этим путем пройтись по графу
void wooden_algorithm(int const size){
    clock_t tStart = clock();
    std::vector<int> path = euler_loop(size, prim_algorithm(size)); //
    // Убираем дубилкаты из тура, который вернул эйлеров цикл
    auto end = path.end();
    for (auto it = path.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
    path.erase(end, path.end());
    path.push_back(0);
    int tour_len = 0;
    // Проходим до графу полученным туром
    for(int i = 0; i < size; ++i){
       tour_len += graph[path.at(i)][path.at(i+1)];
    }
    printf("Time taken for wooden algorithm: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("Length of minimal tour: %d\n",tour_len);
}

int** prim_algorithm(int const size){
    int prev_min = 0;
    // Два массива для проверки вершин
    bool used_to[size];
    bool used_from[size];
    memset(used_from, 0, sizeof(bool) * size);
    // Создаем пустое дерево
    int** min_span_tree = new int*[size];
    for(int i = 0; i < size; i++){
        min_span_tree[i] = new int[size];
        for(int j = 0; j < size; j++){
           min_span_tree[i][j] = 0;
        }
    }
    used_from[0] = 1;
    // Перебор дерева
    for (int i = 0; i < size; i++){ // <- отвечает на количество вершин
        int h = -1, e = -1, min_edge = INT_MAX;
        for(int k = 0; k < size; k++){
            for(int j = 0; j < size; j++){
                if(graph[k][j] < min_edge && graph[k][j] && used_from[k] && !used_to[j] ){ // Ищем минимальное, не равное 0 ребро,
                                                                                           // вершины которого не были добавлены в дерево
                    min_edge = graph[k][j];
                    h = k;
                    e = j;
                }
            } 
        }
        if( h != -1 && e != -1){ // если минимальный путь был найден
            min_span_tree[h][e] = min_edge, min_span_tree[e][h] = min_edge; // добавляем в дерево
            used_to[e] = 1, used_from[e] = 1; // обозначаем, что такая вершина уже есть
        }
    }
    return min_span_tree;
}

std::vector<int> euler_loop(int const size, int** mst){
    int v = 0, count_v = 1;
    std::vector<int> prev_v; // вектор который запоминает посещенные вершины
    std::vector<int> path; // вектор тур
    path.push_back(v), prev_v.push_back(v);

    while(count_v != size){
        int temp_v = -1;

        for(int j = 0; j < size; ++j){ // ищем ребро
            if(mst[v][j] != 0){
                temp_v = j;
            }
        }

        if(temp_v != -1){ // если путь найден
            prev_v.push_back(v); // добавляем в тур
            v = temp_v;
            mst[prev_v.back()][v] = 0, mst[v][prev_v.back()] = 0; // удаляем ребро
            path.push_back(v); // добавляем вершину в посещенные
            count_v++;
        }
        else{ // если не найден
            v = prev_v.back(); // вовращаем предыдущую вершину
            prev_v.pop_back(); // удаляем ее из вектора
            path.push_back(v); // добавляем в тур
        }

    }
    return path;
}
