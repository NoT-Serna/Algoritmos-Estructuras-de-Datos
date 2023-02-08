#include <iostream>

using namespace std;

int** crear_mat(int f, int c){
    int** m = new int*[f];
    for(int i = 0; i <f; i++){
        m[i] = new int[c];
        for(int j = 0; j<c; j++){
            m[i][j] = rand()%6;
        }
    }
    return m;
}

void print_mat(int** m , int f , int c){
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            cout<<m[i][j]<<"\t ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int promedio_filas(int**m, int f, int c){
    for(int i = 0; i<f; i++){
        int suma = m[i]+ m[i+1];
        
    }
}



int main(){
    int c = 5;
    int f = 5;
    int**m = crear_mat(f,c);
    print_mat(m, f,c);
    promedio_filas(m,f,c);
    
    
    return 0;
}
