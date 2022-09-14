#include <iostream>
#include <vector>
using namespace std;
 void partition(vector<int> vec_1, int ini, int fin){
    int i = -1;
    int j= 0;
    int pivot = vec_1.size()-1;
     
    for(j = 0; j<vec_1.size(); j++){
        if(pivot>=vec_1.at(j)){
            i++;
            int temp = vec_1.at(j++);
            vec_1.at(j) = temp;
            
        }else{
            if(pivot<=vec_1.at(j)){
                i++;
                vec_1.at(j) = vec_1.at(j);
            }
        }
    }
     
 }
 
void quick_sort(){
    
}

int main() {
    
    int myints[] = {2,4,7,9,1,8,6,5,3};
    vector<int> vec_1;
    vec_1.assign(myints,myints+9);
    partition(vec_1,2,3);
    for(int i = 0; i<vec_1.size(); i++){
        cout<<vec_1.at(i);
        
    }

    return 0;
}
