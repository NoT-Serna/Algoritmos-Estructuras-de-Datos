#include <iostream>
using namespace std;

int insert_sort(int A[10]){
    int i, j , temp;
    for(i = 0; i< 10; i++){
        temp = A[i];
        j = i -1;

        while(j>= 0 && A[j] > temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
    for(int i = 0; i<10 ; i++){
        cout<< A[i];
    }
    return 0;
}

int main(){
    int A[10] = {9,8,7,6,5,4,3,2,1};
    insert_sort(A);
}
