
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

int insertar(int* v, int n, int x, int pos){
    for(int i = n; i>pos;i--){
        v[i] = v[i-1];
    }
    v[pos] = x;
   return n+1; 
}

int eliminar(int* v, int n, int pos){
    for(int i = pos; i<n-1;i++){
        v[i] = v[i+1];
    }
   return n-1; 
}

int main()
{
    int v[9];
    int tam = 7;
    for(int i=0; i<tam; i++){
        v[i] = i+1;
    }
    for(int i=0; i<tam;i++){
        cout<<v[i]<<"\t";
    }
    cout<<"\n";
    tam = insertar(v,tam,10,5);
    
    for(int i=0; i<tam;i++){
        cout<<v[i]<<"\t";
    }
    
    cout<<"\n";
    tam = eliminar(v,tam,5);
    
    for(int i=0; i<tam;i++){
        cout<<v[i]<<"\t";
    }
    
    return 0;
}
