#include <iostream>
#include <string>
using namespace std;

string reverse_string(string n){
    int len = n.length();
    if(len <= 1){
        return n;
    }else{
        return reverse_string(n.substr(1)) + n[0];
    }
}


int main(){
    string n = "hola";
    cout<<reverse_string(n);
    return 0;
}
