#include <math.h>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template<typename T>
class Nodo {
  T n;
  Nodo* next;

 public:
  Nodo(T d) {
    n = d;
    next = NULL;
  }

  T get() { return n; }

  Nodo* getNext() { return next; }

  void setNext(Nodo* p) { next = p; }
};

template<typename T>
class Pila {
  Nodo<T>* ptr;
  int n_size;

 public:
  Pila() {
    ptr = NULL;
    n_size = 0;
  }

  int size() { return n_size; }

  void push(T d) {
    if (n_size == 0) {
      ptr = new Nodo<T>(d);
      n_size++;
    } else {
      Nodo<T>* r = ptr;
      Nodo<T>* n = new Nodo<T>(d);
      n->setNext(r);
      ptr = n;
      n_size++;
    }
  }
  
  int pop() {
      if(n_size == 0) throw invalid_argument("La pila esta vacia");
      
      Nodo<T>* n = ptr;
      if(n->getNext() != NULL) {
        ptr = n->getNext();
      } else {
          ptr = NULL;
      }
      n_size--;
      T value = n->get();
      delete n;
      
      return value;
  }
  
  void print() {
    if (n_size == 0) {
      cout << "La lista está vacía" << endl;
    } else {
      Nodo<T>* t = ptr;
      do {
        cout << "" << (*t).get() << ", ";
        t = t->getNext();

      } while (t != NULL);
      cout << endl;
    }
  }
};

int main() {
  Pila<char> pila;
  pila.push('h');
  pila.push('o');
  pila.push('o');
  pila.push('o');
  
  cout << pila.pop() << endl;
  cout << pila.pop() << endl;
  cout << pila.pop() << endl;
  cout << pila.pop() << endl;
  
  pila.print();
  return 0;
}
