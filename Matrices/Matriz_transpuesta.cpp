#include <iostream>

using namespace std;

int main(){
    
    int m[5][5];
    int c=5, f=5;
    srand(1234);
    
    //Inicializar la matriz
    for(int i = 0; i<f; i++){
        for(int j =0; j<c; j++){
            m[i][j] = rand()%100;
        }
    }
    
    //Imprmir la matriz
    cout<<"Matriz original"<<"\n";
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n";
    
    //Transpuesta de una matriz
    cout<<"Matriz transpuesta"<<"\n";
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            cout<<m[j][i]<<"\t";
        }
        cout<<endl;
    }
    
    
    
    
    return 0;
}
