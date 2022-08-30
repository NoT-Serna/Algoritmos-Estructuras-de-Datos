#include <iostream>
using namespace std;
void selection_sort(int v[], int* vaux, int n){
    int min = 100000;
    for(int i=0; i < n; i++) {
        for(int j=0; j<n; j++){
            if(min > n) {
                min = j;
            } else if(v[j] < v[min]) {
                min = j;
            }
        }
        vaux[i] = v[min];
        v[min] = 100000;
        min = 100000;
    }

}

int main() {

    int vector[] = {2,3,5,3,6,8,9,12};
    int v_ordenado[10];
    selection_sort(vector, v_ordenado, 8);
    
    for(int i = 0; i < 8; i++) {
        cout << v_ordenado[i] << endl;
    }
    
    return 0;
}
