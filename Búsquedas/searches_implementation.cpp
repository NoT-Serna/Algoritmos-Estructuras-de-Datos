#include <iostream>
using namespace std;

void print_vec(int v[], int tam){
    for(int i = 0; i<tam; i++){
        cout<<v[i]<<" ";
    }
}

int insert_order(int x, int*v , int tam, int pos){
    for(int i = tam; i>pos; i--){
        v[i] = v[i-1];
    }
    v[pos] = x;
    return tam +1;
}

int binary_search(int v[],int tam, int dato){
    int ini = 0;
    int fini = tam-1;
    int mid = fini + ini /2;
    while(ini <= fini){
        mid =(fini+ini)/2;
        if(v[mid] == dato){
            return dato;
        }else{
            if(v[mid] > dato){
                fini = mid-1;
            }else{
                if(v[mid] < dato ){
                    ini = mid + 1;
                }
            }
        }
    }
    return -1;
    
}


int main(){
    int tam = 10;
    int vec_1[tam] = {1,2,3,4,5,6,7,8,9,10};
    
    
   for(int i = 0; i<tam; i++){
       vec_1[i];
   }
   print_vec(vec_1,tam);
   
  cout<<binary_search(vec_1,tam,898989);
   
   
    return 0;
}
