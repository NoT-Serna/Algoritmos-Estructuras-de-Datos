#include <iostream>
#include <vector>
using namespace std;

void cocktail_sort(vector<int>& v) {
    int size = v.size();
    int temp;
    
    for(int i = 0; i < size/2; i++) {
        cout << endl << "Ciclo "<< i << endl;
        for(int j = 0; j < size-1; j++) {
            //adelante
            cout << v.at(j) << "<" << v.at(j+1) << ": " << (v.at(j) < v.at(j+1)) << endl;
            if(v.at(j) < v.at(j+1)) {
                temp = v.at(j+1);
                v.at(j+1) = v.at(j);
                v.at(j) = temp;
            }
            //atras
            if(v.at(size-j-1) > v.at(size-j-2)) {
                temp = v.at(size-j-1);
                v.at(size-j-1) = v.at(size-j-2);
                v.at(size-j-2) = temp;
            }
            
            for(int i = 0; i < v.size(); i++) {
                cout << v.at(i) << " ";
            }
            cout << endl;
            
        }
    }
}



int main(){
    vector<int> v1 = {5,8,9,3,1,13,15,1};
    cocktail_sort(v1);
    
    cout << "Resultado: ";
    for(int i = 0; i < v1.size(); i++) {
        cout << v1.at(i) << " ";
    }

}
