#include <iostream>
#include "stack_1.h"
#include "queue_1.h"
#include <unordered_map>
#include <stack>
using namespace std;

//Problema 4

bool isValid(string s) {
    Stack<char> parentheses_stack;
    unordered_map<char, char> closing_to_opening = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // Si es un paréntesis de apertura, lo agregamos a la pila
            parentheses_stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            // Si es un paréntesis de cierre, verificamos si la pila está vacía o si el paréntesis de apertura coincide
            if (parentheses_stack.isEmpty() || parentheses_stack.top() != closing_to_opening[c]) {
                return false; // No hay un paréntesis de apertura correspondiente o no coincide
            } else {
                parentheses_stack.pop(); // Coincide, eliminamos el paréntesis de apertura de la pila
            }
        }
    }

    // La cadena es válida si la pila está vacía al final
    return parentheses_stack.isEmpty();
}

int minValue(Stack<int>& A){
    int min = A.top();
    while(!A.isEmpty()){
        int current = A.top();
        if(current < min ){
            min = current;
        }
        A.pop();
    }
    return min;
}

stack<int> inverted(stack<int>& A){
    Stack<int> inverted;
    while(!A.empty()){
        inverted.push(A.top());
        A.pop();
    }


    while(!inverted.isEmpty()){
        A.push(inverted.top());
        inverted.pop();
    }

    return A;
}

Queue<int> Reverse(Queue<int>&B, int target){
    while(!B.isEmpty()){
        
    }
}



int main() {
    string input = "({})";

    if (isValid(input)) {
        cout << "La cadena de paréntesis es válida." << endl;
    } else {
        cout << "La cadena de paréntesis no es válida." << endl;
    }

    Stack<int> stack_1;
    stack_1.push(5);
    stack_1.push(2);
    stack_1.push(8);
    stack_1.push(3);
    stack_1.push(17);

    int min = minValue(stack_1);
    cout<<"Min value: "<<min<<endl;

    return 0;
}
}
