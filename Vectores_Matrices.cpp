#include<iostream>
using namespace std;

int producto_punto(int* v1, int*v2) {
       int producto = 0;
       for(int i=0; i<3;i++) {
           producto += v1[i]*v2[i];
       }
       
       return producto;
}

int vect_index(int index) {
    if(index < 3) {
        return index;
    } else {
        return index % 3;
    }
}

void producto_cruz(int* v1, int* v2, int* v3) {
    int x,y,z;
    x = v1[1]*v2[2] - v1[2]*v2[1];
    for(int i=0; i<3; i++) {
        v3[i] = v1[vect_index(i+1)]*v2[vect_index(i+2)] - v1[vect_index(i+2)]*v2[vect_index(i+1)];
    }
} 

void vector_x_matriz(int** mat, int n , int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mat[i][j]<<"\t ";
        }
    }
}




int main() {
    int vector1[3] = {1,2,3};
    int vector2[3] = {4,5,6};
    int vector_resultado[3] = {0,0,0};
    
    producto_cruz(vector1, vector2, vector_resultado);
    
    cout << "\n";
    for(int i=0; i<3; i++) {
        cout << vector_resultado[i] << " ";
    }
    //cout << producto_punto(vector1, vector2);
    
    
    return 0;
}
