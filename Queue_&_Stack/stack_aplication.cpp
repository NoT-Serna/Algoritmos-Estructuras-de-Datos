#include <math.h>

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
//Stacks

class Nodo {
  int n;
  Nodo* next;

 public:
  Nodo(int d) {
    n = d;
    next = NULL;
  }

  int get() { return n; }

  Nodo* getNext() { return next; }

  void setNext(Nodo* p) { next = p; }
};

class Pila {
  Nodo* ptr;
  int n_size;

 public:
  Pila() {
    ptr = NULL;
    n_size = 0;
  }

  int size() { return n_size; }

  void push(int d) {
    if (n_size == 0) {
      ptr = new Nodo(d);
      n_size++;
    } else {
      Nodo* r = ptr;
      Nodo* n = new Nodo(d);
      n->setNext(r);
      ptr = n;
      n_size++;
    }
  }
  
  int pop() {
      if(n_size == 0) throw invalid_argument("La pila esta vacia");
      
      Nodo* n = ptr;
      if(n->getNext() != NULL) {
        ptr = n->getNext();
      } else {
          ptr = NULL;
      }
      n_size--;
      int value = n->get();
      delete n;
      
      return value;
  }
  
  void print() {
    if (n_size == 0) {
      cout << "La lista está vacía" << endl;
    } else {
      Nodo* t = ptr;
      do {
        cout << "" << (*t).get() << ", ";
        t = t->getNext();

      } while (t != NULL);
    }
  }
  
  void suma_polaca(int i, int j, char symbol){
      if(n_size == 0){
          cout<< "No hay nada que sumar"<<endl;
      } else{
          ptr = new Nodo(i);
          Nodo* n = new Nodo(j);
          if(symbol == '+'){
              int sum;
              push(i);
              push(j);
            sum = i + j;
            cout<<"Notacion inversa polaca "<<i<<", "<<j<<", "<<"+";
            cout<<endl;
            cout<<"Resultado: "<<sum;
          }
      }
  }
  
  void suma_polaca_triple(int i, int j, int n,  char symbol){
      if(n_size == 0){
          cout<<"No hay nada que sumar"<<endl;
      } else{
          ptr = new Nodo(i);
          Nodo* k = new Nodo(j);
          Nodo* t = new Nodo(n);
          if(symbol == '+'){
              int sum_1;
              push(i);
              push(j);
              push(n);
            sum_1 = i + j;
            int sum_2;
            sum_2 = sum_1 + n;
             cout<<"Notacion inversa polaca "<<i<<", "<<j<<", "<< n <<"," <<" +"<<endl;
             cout<<"Resultado: "<<sum_2;
          }
      }
  }
  
};

int main() {
  Pila pila = Pila();
  pila.push(1);
  pila.push(2);
  pila.push(3);
  pila.push(4);
  
  pila.print();
  cout<<endl;
  pila.pop();
  pila.pop();
  pila.print();
  cout<<endl;
  
  pila.suma_polaca(5,7,'+');
  cout<<endl;
  pila.suma_polaca_triple(5,7,5,'+');

  return 0;
}
