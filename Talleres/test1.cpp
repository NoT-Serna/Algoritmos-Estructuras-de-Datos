#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vec_1;
    int myints[] = {1,2,3,4,5,6,7,8,9};

    for(int i = 0; i<vec_1.size(); i++){
        cout<<vec_1[i];
    }
    
    vec_1.assign(myints,myints+9);
    vec_1.push_back(vec_1.at(8)+1);
    cout<<"The missing element in the vector is "<<vec_1.at(9);

}
