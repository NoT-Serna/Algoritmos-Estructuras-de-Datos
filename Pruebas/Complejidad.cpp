#include<iostream>
#include<ctime>
using namespace std;

void print_vec(int v[], int tam){
    for(int i = 0; i<tam; i++){
        cout<<v[i]<<" ";
    }
}


int binary(int v[], int n, int x){
    int ini = 0;
    int fin = n-1;
    int i= fin + ini /2;
    while(ini <= fin){
        i=(fin + ini)/2;
        if(v[i] == x){
            return i;
        }else{
            if(v[i] > x){
                fin = i-1;
            }else{
                ini = i +1;
            }
        }
    }
    return -1;
}








int main() {
    int tam = 50;
    int vec_1[tam] = {};
    for(int i = 0; i<tam; i++){
        vec_1[i] = i;
    }
    clock_t time_req;
    time_req = clock();
    cout<<binary(vec_1,tam,9)<<endl;
    time_req = clock()-time_req;
    cout<<(float)time_req/CLOCKS_PER_SEC<<" segundos";
    return 0;
}
