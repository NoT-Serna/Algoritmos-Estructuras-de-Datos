#include <iostream>
using namespace std;

void elevacion(int vec[], int tam){
    for(int i = 0; i<tam; i++){
        vec[i]*= vec[i];
    }
}

void print(int vec[], int tam){
    for(int i = 0; i<tam; i++){
        cout<<vec[i]<<" ";
    }
}


int main() {
    int tam = 5;
    int vec[tam]= {1,2,3,4,5};
    elevacion(vec,tam);
    print(vec,tam);


    return 0;
}