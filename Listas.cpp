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
  Nodo* pointer;
  
public:
  
  Nodo(){
      dato = NULL;
      pointer = NULL;
  }
  
  ~Nodo(){
      delete dato;
  }
  
  Nodo(Point* d){
      dato = d;
      pointer = NULL;
  }
    
  Point* getDato(){
      return dato;
  }
  
  void setDato(Point* d){
      dato = d;
  }
  
  Nodo* getNext(){
      return pointer;
  }
  
  void setNext(Nodo* p){
      pointer = p;
  }
  
  void setNext() {
      pointer = NULL;
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
        while(t->getNext() != NULL){
            n = t;
            t = t->getNext();
            delete n;
        }
    }
    
    void push_back(Point* d){
        
        if(size == 0){
            ptr = new Nodo(d);
            size++;
        }else{
            Nodo* t = ptr;
            while(t->getNext() != NULL){
                t = t->getNext();    
            }
            t->setNext(new Nodo(d));
            size++;
        }
        
    }
    
    int getSize(){
        return size;
    }
    
    void setPtr(Nodo* ptrr) {
        ptr = ptrr;
    }
    
     Nodo* getNodo(int pos) {
        if(size == 0) {
            throw invalid_argument("La lista no tienen nodos");
        } else if (pos >= size || pos < 0) {
            throw invalid_argument("El nodo no esta en la lista");
        } else {
            Nodo* t = ptr;
            for(int i = 0; i < pos; i++) {
                t = t->getNext();
            }
            return t;
        }
    }
    
    void insert(Point* d, int pos) {
        if(pos > size || pos < 0) {
            throw invalid_argument("No es posible insertar un nodo en esa posicion");
        } else if(pos == 0) {
            Nodo* r = getNodo(pos);
            Nodo* n = new Nodo(d);
            n->setNext(r);
            ptr = n;
            size++;
        } else if(pos == size || size == 0) {
            push_back(d);
        } else {
            Nodo* l = getNodo(pos-1);
            Nodo* r = l->getNext();
            
            Nodo* n = new Nodo(d);
            l->setNext(n);
            n->setNext(r);
            size++;
        }
    }
    
    
    void remove_nodo(int pos){
        if (pos < 0 || pos >= size) {
            throw invalid_argument("No hay ningun nodo que eliminar en esa posicion");
        } else if(pos == 0) {
            Nodo* obj = ptr;
            ptr = obj->getNext();
            delete obj;
            size--;
        } else if (pos == size - 1) {
           Nodo* l = getNodo(pos-1);
           Nodo* obj = l->getNext();
           l->setNext();
           delete obj;
           size--;
        } 
        else {
            Nodo* l = getNodo(pos-1);
            Nodo* obj = l->getNext();
            Nodo* r = obj->getNext();
            
            l->setNext(r);
            delete obj;
            size--;
        }
    }
    
    
    void reverse(){
        for(int i = 1;i<size;i++){
            Nodo* l = getNodo(i-1);
            //cout << l->getDato()->getX();
            cout<< i;
            Nodo* n = l->getNext();
            ptr = n;
           //Nodo* r = ptr;
            l->setNext(n->getNext());
            n->setNext(l);
            print();
            
            // usar insert cada VEZ EN PUESTO +1
        }
    }
    
    void print(){
        if(size == 0){
            cout<<"La lista está vacía" <<endl;
        }else{
            Nodo* t = ptr;
            do{
                cout<<"("<<(*t).getDato()->getX()<<", "<<t->getDato()->getY()<<"), ";
                t = t->getNext();
                
            }while(t != NULL);
            cout<<endl;
        }
    }
    
};


int main()
{
   
   Lista l = Lista();
   
   // PUSH BACK
   for(int i = 1; i<11; i++){
       l.push_back(new Point(i,i));
   }
   l.print();
   
    
   
   return 0;
}