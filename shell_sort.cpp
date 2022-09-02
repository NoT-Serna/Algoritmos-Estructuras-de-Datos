#include <iostream>
using namespace std;

int Sort(int A[], int n){
    for(int g = n/2; g > 0; g/=2){
        for(int i = g; i < n;  i+= 1){
            int temp = A[i];
            int j;
            for (j = i; j>= g && A[j-g]> temp; j -= g){
                A[j] = temp;
            }
        }
    }
    return 0;
}

void Display(int A[], int n){
    for (int i = 0; i<n; i++){
        cout<< A[i] << " ";
    }
}

int main(){
    int A[] = {1,14,4,42,7}, i;
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Principal Array: ";
    Display(A,n);
    Sort(A,n);
    
    cout << "\n Array after sorting: ";
    Display(A,n);
    return 0;

}
