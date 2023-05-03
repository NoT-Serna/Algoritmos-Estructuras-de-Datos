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

bool palindrome(string n){
    int len = n.length();
    if(len <= 1){
        return true;
    }

    if(n[0] == n[len-1]){
        return palindrome(n.substr(1, len-2));
    }
    return false;
}


int main(){
    string n = "alla";
    cout<<reverse_string(n);
    cout<<endl;
    cout<<palindrome(n);
    return 0;
}
