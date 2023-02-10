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

void promedio(int**m, int f, int c){
    int* suma_filas = new int[f];
    int* suma_columnas = new int[c];

    for(int i = 0; i<f; i++){
        suma_filas[i]= 0;
    }

    for(int j = 0; j<c; j++){
        suma_columnas[j] = 0;
    }
    
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            suma_filas[i] = suma_filas[i] + m[i][j];
            suma_columnas[j] = suma_columnas[j] +m[i][j];
            cout<<m[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<"la suma de filas es: "<<endl;
    for(int i = 0; i<f; i++){
        cout<<suma_filas[i]<<endl;
    }
    cout<<" la suma de columnas es: "<<endl;
    for(int j = 0; j<c; j++){
        cout<<suma_columnas[j]<<endl;
    }

    cout<<"El promedio de cada fila es: "<<endl;
    for(int i = 0; i<f; i++){
        int promedio = 0;
        promedio = suma_filas[i] / f;
        cout<<promedio;
    }


}





int main(){
    int c = 5;
    int f = 5;
    int**m = crear_mat(f,c);
    print_mat(m, f,c);
    promedio(m,f,c);
   
    
    return 0;
}
