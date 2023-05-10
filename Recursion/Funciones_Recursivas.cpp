#include <iostream>
using namespace std;
// Recursion
//Reemplazar ciclos por condicionales

//FIBONACCI
int fibonacci(int n){
    if (n == 0 || n==1){
        return n;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int fact(int x){
    if(x==1){
        return x;
    }else{
        return x*fact(x-1);
    }
}

int der(int i){

    int der = 2*(i+1);
    return der;
}

int izq(int i){
    int izq = 2*(i+1)-1;
    return izq;
}

void recorrido_recursivo(int vec[], int tam, int i){
    if(izq(i) < tam){
        recorrido(vec,tam,izq(i));
    }
    if(der(i)< tam){
        recorrido(vec,tam,der(i));
    }
    cout<<vec[i]<<" ";
}

void print(int vec[], int tam){
    for(int i = 0; i<tam; i++){
        cout<<vec[i]<<" ";
    }
}



int main() {
    
    cout<<"Factorial "<<fact(3)<<endl;
    cout<<"Fibonacci "<<fibonacci(4);
    
    int tam = 9;
    int vec[tam] = {7,2,4,9,8,3,1,5,6};
    print(vec,tam);
    cout<<endl;
    recorrido_recursivo(vec,tam,0);
    
    return 0;
}
