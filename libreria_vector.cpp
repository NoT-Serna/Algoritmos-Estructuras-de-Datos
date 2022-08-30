#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

void print_v(vector<int> v) {
    string separador = "[";
    for(int i = 0; i < v.size(); i++) {
        if(i > 0) {
            separador = ",";
        }
        cout << separador << v.at(i);
    }
    cout << "]" << endl;
}


int main() {
    vector<int> pow3;
    for(int i = 1; i < 11; i++) {
        pow3.push_back(pow(3, i));
    }
    
    print_v(pow3);
    
    for(int i = 0; i < pow3.size(); i++) {
        if(pow3.at(i) >= 100) {
            pow3.erase(pow3.begin(), pow3.begin()+ i);
            break;
        }
    }
    
    print_v(pow3);
    

    return 0;
}
