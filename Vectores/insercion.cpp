#include <iostream>

using namespace std;

int insert_order(int x, int* v , int tam, int pos){
    for(int i = tam; i>pos; i--){
        v[i] = v[i-1];
    }
    v[pos] = x;
    return tam +1;
}


int main(){
   int tam = 7;
   int vec_1[9];
   
   //Vector inicial 
   for(int i = 0; i<tam; i++){
        cout<<vec_1[i]<<"\t";
   }    
   cout<<"\n";

   //Vector con insert
   insert_order(100, vec_1, tam, 10 );
   for(int i = 0; i<tam; i++){
        cout<<vec_1[i]<<"\t";
   }    
   cout<<"\n";
   
    return 0;
}