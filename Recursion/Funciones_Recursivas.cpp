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



int main() {
    
    cout<<"Factorial "<<fact(3)<<endl;
    cout<<"Fibonacci "<<fibonacci(4);
    
    return 0;
}
