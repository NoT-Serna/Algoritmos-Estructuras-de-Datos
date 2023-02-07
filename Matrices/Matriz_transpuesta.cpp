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
    
    cout<<"\n";
    
    //Imprimir diagonal primaria
    cout<<"Diagonal principal: "<<" ";
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            cout<<m[j][i=j]<<"\t";
        }
        cout<<endl;
    }
    
    
    
    //Imprmir diagonal secundaria
    cout<<"Diagonal secundaria: "<<" ";
    for(int j = 0; j<c; j++){
        cout<<m[j][c-1-j]<<"\t";
    }
    
    cout<<"\n";
    
    
    //Triángulo Superior
    cout<<"Triángulo Superior: "<<"\n";
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            if(j>=i){
                cout<<m[j][i]<<"\t";
            }else{
                cout<<" " <<"\t";
            }
        }
        cout<<endl;
    }
    cout<<"\n";
    
    //Triángulo Inferior
    cout<<"Triángulo Inferior: "<<"\n";
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            if(j<=i){
                cout<<m[j][i]<<"\t";
            }else{
                cout<<" "<<"\t";
            }
        }
        cout<<endl;
    }
    
    //Triangulo Superior Primario
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            if(j<=c-1-i){
                cout<<m[j][i]<<"\t";
            }else{
                cout<<" "<<"\t";
            }
        }
        cout<<endl;
    }
    
    //Triangulo Superior Secundario
    for(int i = 0; i<f; i++){
        for(int j = 0; j<c; j++){
            if(j>=c-1-i){
                cout<<m[j][i]<<"\t";
            }else{
                cout<<" "<<"\t";
            }
        }
        cout<<endl;
    }
    
    
    
    
    return 0;
}
