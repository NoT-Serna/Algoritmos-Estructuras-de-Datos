#include <iostream>
using namespace std;


int main(){
    int A[10] = {1,3,5,7,9,8,5,2,4,6};
    int i,j, temp;
    for(i = 0; i<10; i++){
        temp = A[i];
        j = i-1;

        while(j>= 0 && A[j] > temp){
            j--;
        }
        A[j+1] = temp;
    }
    for(int i = 0; i<10; i++){
        cout <<A[i];
    }
    return 0;
}
