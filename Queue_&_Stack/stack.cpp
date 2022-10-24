#include <math.h>

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

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
      cout << endl;
    }
  }
};

int main() {
  Pila pila = Pila();
  pila.push(1);
  pila.push(2);
  pila.push(3);
  pila.push(4);
  
  cout << pila.pop() << endl;
  cout << pila.pop() << endl;
  cout << pila.pop() << endl;
  cout << pila.pop() << endl;

  return 0;
}
