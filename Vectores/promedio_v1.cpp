#include <iostream>
#include <math.h>

using namespace std;

//Funciones
int* crear_vect(int n){
    int *v = new int[n];
    for(int i = 0; i<n; i++){
        v[i] = 0;
    }
    return v;
}



int main(){
    //Definición de variables
    int n = 5;
    int* x = crear_vect(n);
    float promedio = 0;
    float desvest = 0;
    float temp = 0;
    
    //Ingresar notas
    for(int i = 0; i<n; i++){
        x[i] = i +1;
    }
    cout<<endl;
    
    for(int i = 0; i<n; i++){
        cout<<x[i]<<"\t";
    }
    cout<<endl;
    
    for(int i = 0; i<n; i++){
        promedio += x[i];
    }
    
    promedio /=n;
    cout<<"El promedio es: "<<promedio<<endl;
    
    for(int i = 0; i<n; i++){
        temp += pow(x[i]-promedio,2);
    }
    
    temp /=n;
    desvest = sqrt(temp);
    cout<<"la desviación estandar es: "<<desvest<<endl;
    delete[] x;
    
    return 0;
}
