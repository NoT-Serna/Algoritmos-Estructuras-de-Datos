
#include<iostream>

using namespace std;

void init_vect(int* v, int tam){
    for(int i=0; i<tam; i++){
        v[i] = 0;
    }
}

void sum_vect(int v[], int tam){
    for(int i=1; i<tam; i++){
        v[i] = v[i-1]+v[i];
    }
    cout<<"La suma es "<<v[tam-1]<<"\n";
}

int main()
{
    int vector[10];
    int r = rand();
    
    for(int i =0; i<10; i++){
        cout<<vector[i]<<"\t";
    }
    cout<<"\n";
    init_vect(vector, 10);
    for(int i =0; i<10; i++){
        cout<<vector[i]<<"\t";
    }
    
    cout<<"\n";
    
    for(int i =0; i<10; i++){
        vector[i]=rand();
    }
    
    for(int i =0; i<10; i++){
        cout<<vector[i]<<"\t";
    }
    cout<<"\n";
    sum_vect(vector, 10);
    
    for(int i =0; i<10; i++){
        cout<<vector[i]<<"\t";
    }
    
    
    
    return 0;
}