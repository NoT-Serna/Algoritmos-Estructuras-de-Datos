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

class Cola {
  Nodo* ptr;
  Nodo* tail;
  int n_size;

 public:
  Cola() {
    ptr = NULL;
    tail = NULL;
    n_size = 0;
  }

  int size() { return n_size; }

  void push(int d) {
    if (n_size == 0) {
      ptr = new Nodo(d);
      tail = ptr;
      n_size++;
    } else {
      Nodo* n = new Nodo(d);
      tail->setNext(n);
      tail = n;
      n_size++;
    }
  }
  
  int pop() {
      if(n_size == 0) throw invalid_argument("La cola esta vacia");
      
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
  Cola c = Cola();
  c.push(1);
  c.push(2);
  c.push(3);
  c.push(4);
  
  cout << c.pop() << endl;
  cout << c.pop() << endl;
  cout << c.pop() << endl;
  cout << c.pop() << endl;

  return 0;
}
