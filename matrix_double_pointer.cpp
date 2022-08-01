// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int** create_matrix(int n, int m) {
    int ** mat = new int*[n];
    for(int i =0; i < n; i++) {
        mat[i] = new int[m];
        for(int j = 0; j < m; j++) {
            //mat[i][j] = 0;
            mat[i][j] = i*m + j;
        }
    }
    
    return mat;
}

void print_matrix(int** mat, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // Write C++ code here
    int n = 10;
    int m = 10;
    
    int** mat = create_matrix(n,m);
    print_matrix(mat, n, m);

    return 0;
}
