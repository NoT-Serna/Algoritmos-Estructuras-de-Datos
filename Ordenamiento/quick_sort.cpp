#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>* vec_1, int ini, int fin){
    int i = ini-1;
    int j= 0;
    int pivot = vec_1->at(fin);
     
    for(j = ini; j<=fin; j++){
        if(vec_1->at(j)<=pivot){
            i++;
            int temp = vec_1->at(j);
            vec_1->at(j) = vec_1->at(i);
            vec_1->at(i) = temp;
            
        }
    }
    return i;
     
 }
 
 void quick_sort(vector<int>* vec_1, int ini , int fin){
     if(ini<fin){
       int i = partition(vec_1, ini, fin);
         quick_sort(vec_1, ini, i-1);
         quick_sort(vec_1, i+1, fin);
     }
 }
 

int main() {
    
    int myints[] = {2,4,7,9,1,8,6,5,3};
    vector<int> vec_1;
    vec_1.assign(myints,myints+9);
    quick_sort(&vec_1, 0, vec_1.size()-1);
    
    for(int i = 0; i<vec_1.size(); i++){
        cout<<vec_1.at(i)<<" ";
    }

    return 0;
}
