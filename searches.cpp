#include <iostream>
#include <string>
using namespace std;
//Sequential search
int search(int v[], int n, int x, int i){

    while(v[i] !=x){
        i++;
    }
    if(i<n){
        return i;
    }else{
        return -1;
    }
}

//Index search: for a large data structure 
int index(int v[], int n, int vi[], int m, int x){
    int k = x/1000;
    int i = vi[k];
    int j = vi[k+1];
    while(i<j && v[i] != x){
        i++;
    }
    if (i<j){
        return i;
    }else{
        return -1;
    }
}

//Binary search
int binary(int v[], int n, int x){
    int ini = 0;
    int fin = n-1;
    int i= fin + ini /2;
    while(ini <= fin){
        i=(fin + ini)/2;
        if(v[i] == x){
            return i;
        }else{
            if(v[i] > x){
                fin = i-1;
            }else{
                ini = i +1;
            }
        }
    }
    return -1;
}








int main() {
   int vector[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<binary(vector,10,9);
    return 0;
}
