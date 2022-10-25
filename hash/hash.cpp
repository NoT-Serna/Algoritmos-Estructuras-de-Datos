#include <iostream>
#include <string>
using namespace std;

int sascii(string x, int M){
    char ch[];
    ch = x.toCharArray();
    int xlength = x.length();

    int i, sum;
    for(sum=0, i = 0; i<x.length(); i++){
        sum += ch[i];
    }
    return sum % M;
}


//Simple hash function//
/*
int main(){

    return 0;
    
}

#include <iostream>
using namespace std;

int h(int x) {
    return x % 16;
}

int main(){
    cout<<h(89);
    return 0;
}
*/