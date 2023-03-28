#include <iostream>
#include <math.h>

void swap(int*& a, int*& b){
    int* temp = a;
    a = b;
    b = temp;
}

void print_vec(int** v, int size){
    for (int i = 0; i < size;  i++){
        std::cout << "(" << v[i][0] << ", " << v[i][1] << ") ";
    }
    std::cout << std::endl;
}


float distance_between_points(int* a, int* b){
    int x = a[0] - b[0];
    int y = a[1] - b[1];
    
    return sqrt(x*x + y*y);
}


void print_vec_distance(int** v, int size, int* ref){
    for (int i = 0; i < size;  i++){
        std::cout << "(" << v[i][0] << ", " << v[i][1] << "). Distance: " << distance_between_points(v[i], ref) << std::endl;
    }
    std::cout << std::endl;
}



int** bubble_sort(int** v, int size, int* ref){
    
    int swaps = 1;
    while(swaps != 0){
        swaps = 0;
        for (int i = 0; i < size-1; i++){
            if (distance_between_points(v[i], ref) < distance_between_points(v[i+1], ref)){
                swap(v[i], v[i+1]);
                swaps++;
            }
        }
    }
    return v;
}




int main() {
    
    int n = 10;
    int** v = new int*[n];
    for (int i = 0; i < n; i++){
        v[i] = new int[2];
    }
    
    for (int i = 0; i < n; i++){
        v[i][0] = rand() % 100;
        v[i][1] = rand() % 100;
    }
    
    print_vec(v, n);
    
    ///////////////////////////////////
    
    std::cout << "Ordenamos el vector:\n";
    
    int* ref = new int[2];
    ref[0] = 99;
    ref[1] = 21;
    v = bubble_sort(v, n, ref);
    
    print_vec_distance(v, n, ref);
}
