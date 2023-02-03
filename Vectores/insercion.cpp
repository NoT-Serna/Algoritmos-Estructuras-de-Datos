#include <iostream>

using namespace std;

void print(int v[], int tam){
    for (int i = 0; i<tam; i++){
        cout<<v[i]<<" ";
    }
}


int insert_order(int x, int* v , int tam, int pos){
    for(int i = tam; i>pos; i--){
        v[i] = v[i-1];
    }
    v[pos] = x;
    return tam +1;
}

bool search_num(int *v, int x, int tam){
    for(int i = 0; i<tam; i++){
        if(x == v[i]){
            cout<<" Encontrado";
            return true;
        }
        
    }
    cout<<"no fue encontrado";
    return false;
}
    
   



int main(){
   int tam = 5;
   int vec_1[tam];
    for (int i = 0; i<tam; i++){
        vec_1[i];
    }
   
   //Vector inicial
   print(vec_1,tam);
   cout<<"\n";
    
   //Vector con insert
   insert_order(100, vec_1, tam, 1 );
   print(vec_1,tam);
   search_num(vec_1, 100, tam);
   cout<<"\t";
   
    return 0;
}
