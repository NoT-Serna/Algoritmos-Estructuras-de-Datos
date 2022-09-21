#include<iostream>
#include<string>
using namespace std;

void max_heap(int* v, int n, int i){
    int temp;
    int largest = i;
    int der = 2*(i+1);
    int izq = 2*(i+1)-1;
    
    if(izq < n && v[izq] > v[largest]){
        largest = izq;
    }
    
    if(der < n && v[der] > v[largest]){
        largest = der;
    }
    
    if(largest != i){
        temp = v[largest];
        v[largest] = v[i];
        v[i] = temp;
        max_heap(v,n,largest);
    }
    
}

void heap_sort(int* v, int n){
    int max_father = (n/2)-1;
    int temp;
    
    for(int i=max_father; i>=0; i--){
        max_heap(v,n,i);
    }
    
    for(int i=1; i<n; i++){
        temp = v[0];
        v[0] = v[n-i];
        v[n-i] = temp;
        max_heap(v,n-i,0);
    }
    
}

int main()
{
    srand(10);
    int n = 10;
    int* v = new int[n];
    for(int i=0; i<n; i++){
        v[i] = rand()%100;
    }
    for(int i=0; i<n; i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
    heap_sort(v,n);
    for(int i=0; i<n; i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
    
}
