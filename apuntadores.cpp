// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
/* & llamar a la dirección de memoria */
void incrementar(int* n){
    cout<<n<<&n;
    (*n) ++;
    cout<< "El nuevo valor de n adentro es"<<*n<<" "<<&n<<endl;
    
}
int main() {
    int n = 0;
    incrementar(&n);

    return 0;
}
