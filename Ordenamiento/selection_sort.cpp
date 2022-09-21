#include <iostream>
#include <vector>
using namespace std;

void selection_sort(int arr[]){
    for (int i = 0; i<4; i++){
        int min = i;
    
    for(int j = i+1; j<5; j++){
        if (arr[j]< arr[min]){
            min = j;
        }
    }
    if (min != i){
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
  }
}

int main(){

    int myarr[] = {3,8,2,1,4};
    cout<< "Unsorted array: "<<endl;
    for(int i = 0; i <5; i++){
        cout<<myarr[i]<<" ";
    }
    cout<<endl;

    selection_sort(myarr);
    cout<<"Sorted Array: " <<endl;
    for (int i = 0; i<5; i++){
        cout<<myarr[i]<<" ";
    }


    return 0;
}
