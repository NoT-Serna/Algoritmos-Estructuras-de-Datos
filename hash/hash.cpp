#include <iostream>
#include <string>
using namespace std;

void hash_func(string m){
    char* char_arr = &m[0];

    for(int i = 0; i < m.length(); i++){
            char_arr[i] = static_cast<int>(char_arr[i]);
            char_arr[i]++;
            cout<<char_arr[i];
            
    }
}

int hash_func_ver2(string m) {
    int hash = 0;
    for (char c : m) {
        hash += static_cast<int>(c);
    }
    return hash;
}


int main(){

    hash_func("hola buenas tardes me llamo Juan David Serna");
    cout<<endl;

    string str = "Juan David Serna";
    int hash = hash_func_ver2(str);
    cout << "Hash value of \"" << str << "\" is: " << hash <<endl;

    return 0;
}