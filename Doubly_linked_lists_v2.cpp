#include<iostream>
#include <math.h> 
#include <stdexcept>
#include <string>

using namespace std;

class Point {

//Atributos
    int x;
    int y;

    const int rmax = 1;

public:
    
    //Constructores
    Point(int xc, int yc) {
        x = xc;
        y = yc;

    }

    Point() {
        x = 0;
        y = 0;
    }

    //M�todos
    
    Point ofuscacion() {
        return Point(x + 2 * (rand() % rmax) - rmax, y + 2 * (rand() % rmax) - rmax);
    }
    
    double dist() {
        return dist(0,0);
    }

    double dist(int xc, int yc) {
        return sqrt(pow(x-xc, 2) + pow(y-yc, 2));
    }

    double dist(Point p) {
        return dist(p.x, p.y);
    }

    //Getters
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }


    //Setters
    void setX(int xc) {
        x = xc;
    }

    void setY(int yc) {
        y = yc;
    }
    
    Point& operator=(const Point& f) { 
		setX(f.x);
		setY(f.y);
		return *this; 
	}

};

class Nodo{
  Point* dato;
  Nodo* next;
  Nodo* prev;
  
public:
  
  Nodo(){
      dato = NULL;
      next = NULL;
      prev = NULL;
  }
  
  ~Nodo(){
      delete dato;
  }
  
  Nodo(Point* d){
      dato = d;
      next = NULL;
      prev = NULL;
  }
    
  Point* getDato(){
      return dato;
  }
  
  void setDato(Point* d){
      dato = d;
  }
  
  Nodo* getNext(){
      return next;
  }
  
  Nodo* getPrev(){
      return prev;
  }
  
  void setNext(Nodo* p){
      next = p;
  }
  
  void setPrev(Nodo* p){
      prev = p;
  }
  
  void setNext() {
      next = NULL;
  }
  
  void setPrev() {
      prev = NULL;
  }
    
};

class Lista{
    Nodo* ptr;
    int size;

public:  

    Lista(){
        ptr = NULL;
        size = 0;
    }
    
    ~Lista(){
        Nodo* t = ptr;
        Nodo * n;
        for(int i = 0; i<size; i++){
            n = t;
            t = t->getNext();
            delete n;
        }
    }
    
    void push_back(Point* d){
        
        if(size == 0){
            Nodo* n = new Nodo(d);
            n->setNext(n);
            n->setPrev(n);
            ptr = n;
            size++;
        }else{
            Nodo* last = ptr->getPrev();
            Nodo* n = new Nodo(d);
            last->setNext(n);
            n->setNext(ptr);
            n->setPrev(last);
            ptr->setPrev(n);
            size++;
        }
        
    }
    
    int getSize(){
        return size;
    }
    
    void setPtr(Nodo* ptrr) {
        ptr = ptrr;
    }
    
    Nodo* getNodo(int pos) { // ver si arranca desde inicio o final
        if(size == 0) {
            throw invalid_argument("La lista no tienen nodos");
        } else if (pos >= size || pos < 0) {
            throw invalid_argument("El nodo no esta en la lista");
        } else {
            Nodo* t = ptr;
            if(pos > size/2) {
                for(int i = size-1; i >= pos; i--) {
                    t = t->getPrev();
                }
            } else {
                for(int i = 0; i < pos; i++) {
                    t = t->getNext();
                }
            }
            return t;
        }
    }
    
    void insert(Point* d, int pos) {
        if(pos > size || pos < 0) {
            throw invalid_argument("No es posible insertar un nodo en esa posicion");
        } else if(pos == 0) {
            Nodo* r = ptr;
            Nodo* n = new Nodo(d);
            Nodo* last = r->getPrev();
            n->setNext(r);
            r->setPrev(n);
            n->setPrev(last);
            last->setNext(n);
            ptr = n;
            size++;
        } else if(pos == size || size == 0) {
            push_back(d);
        } else {
            Nodo* r = getNodo(pos);
            Nodo* l = r->getPrev();
            Nodo* n = new Nodo(d);
            
            l->setNext(n);
            n->setNext(r);
            r->setPrev(n);
            n->setPrev(l);
            size++;
        }
    }

    void remove_nodo(int pos){
        if (pos < 0 || pos >= size) {
            throw invalid_argument("No hay ningun nodo que eliminar en esa posicion");
        } else if(pos == 0) {
            Nodo* obj = ptr;
            Nodo* r = obj->getNext();
            Nodo* last = obj->getPrev();
            
            last->setNext(r);
            r->setPrev(last);
            ptr = r;
            delete obj;
            size--;
        } else if (pos == size - 1) {
           Nodo* first = ptr;
           Nodo* obj = first->getPrev();
           Nodo* l = obj->getPrev();
           
           l->setNext(first);
           first->setPrev(l);
           delete obj;
           size--;
        } 
        else {
            Nodo* obj = getNodo(pos);
            Nodo* l = obj->getPrev();
            Nodo* r = obj->getNext();
            
            l->setNext(r);
            r->setPrev(l);
            delete obj;
            size--;
        }
    }
    
        Lista reverse() {
        Lista r = Lista();
        Nodo* t = ptr;
        do{
            t = t->getNext();
            Nodo* n = t;
            if(r.getSize() == 0) {
                n->setNext();
                r.setPtr(n);
            } else {
                Nodo* ri = r.getNodo(0);
                n->setNext(ri);
                r.setPtr(n);
            }
            size++;
        }while(t->getNext() != NULL);
        
        return r;
    }
    
    void reverse_list(){
        for(int i = 1;i<size;i++){
            Nodo* l = getNodo(i-1);
            cout << l->getDato()->getX();
            cout<< i;
            Nodo* n = l->getNext();
            ptr = n;
            Nodo* r = ptr;
            l->setNext(n->getNext());
            n->setNext(l);
            print();
            
        
        }
    }
    
    void print(){
        if(size == 0){
            cout<<"La lista está vacía" <<endl;
        }else{
            Nodo* t = ptr;
            for(int i =0; i<size; i++) {
                cout<<"("<<(*t).getDato()->getX()<<", "<<t->getDato()->getY()<<"), ";
                t = t->getNext();
            }
            cout<<endl;
        }
    }
    
};


int main()
{
   
   Lista l = Lista();
   
   // PUSH BACK
   cout<<"Initial list"<<endl;
   for(int i = 1; i<11; i++){
       l.push_back(new Point(i,i));
   }
   l.print();
   
    //INSERT
   cout<<"Insert method"<<endl;
   l.insert(new Point(10,10), 6);
   l.print();
   
   // REMOVE
   cout<<"Remove method"<<endl;
   l.remove_nodo(5);
   l.print();
   
   //REVERSE
   Lista c = Lista();
   cout<<"Reverse method"<<endl;
   l.reverse_list();
   l.print();
   c.print();
   
   return 0;
}
