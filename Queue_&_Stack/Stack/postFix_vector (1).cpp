#include <iostream>
#include <vector>
#include <string>
#include <cctype>
// #include <stack>
// #include "stack.h"
#include "stack_1.h"

double evaluarPostfix(const std::string expr){

    std::vector<double> v;
    for(char c : expr){
        if(isdigit(c)){
            v.push_back(c - '0'); // Convierte en numero
        }else{
            double b = v.back(); v.pop_back();
            double a = v.back(); v.pop_back();
            switch (c)
            {
            case '+': v.push_back(a + b); break;
            case '-': v.push_back(a - b); break;
            case '*': v.push_back(a * b); break;
            case '/': v.push_back(a / b); break;
            }
        }
    }
    return v.back();
}


int main(){
    std::string expr = "6523+8*+3+*";
    std::cout << "Resultado: " << evaluarPostfix(expr) << std::endl;
    return 0;
}