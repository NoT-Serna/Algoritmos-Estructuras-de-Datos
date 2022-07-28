#include<iostream>
using namespace std;

int main()
{
   int mat[10][10];
   int n=10;
   int m = 10;
   
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           mat[i][j] = i*m + j;
       }
   }
   
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           cout<<mat[i][j]<<"\t";
       }
       cout<<"\n";
   }
   
    return 0;
}
