#include<iostream>
#include <math.h> 

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
	
	string to_string() {
		return "("+std::to_string(x) + "," + std::to_string(y)+")";
	}


	friend std::ostream& operator<<(std::ostream& os, Point& b) {
		return os << b.to_string();
	}

};

class Tweet{
  
  string dato;
  Tweet* pointer;
  
public:
  
  Tweet(){
      dato = "";
      pointer = NULL;
  }
  
  ~Tweet(){
  }
  
  Tweet(string d){
      dato = d;
      pointer = NULL;
  }
    
  string getDato(){
      return dato;
  }
  
  void setDato(string d){
      dato = d;
  }
  
  Tweet* getNext(){
      return pointer;
  }
  
  void setNext(Tweet* p){
      pointer = p;
  }
    
    string to_string() {
		return getDato();
	}


	friend std::ostream& operator<<(std::ostream& os, Tweet& b) {
		return os << b.to_string();
	}
    
};

class Nodo{
  
  Point* dato;
  Nodo* pointer;
  Tweet* tweets;
  int size;
  
public:
  
  Nodo(){
      dato = NULL;
      pointer = NULL;
      tweets = NULL;
      size = 0;
  }
  
  ~Nodo(){
      Tweet* t = tweets;
      Tweet* tt;
      while(t != NULL){
          tt = t;
          t = t->getNext();
          delete tt;
      }
      delete dato;
  }
  
  Nodo(Point* d){
      dato = d;
      pointer = NULL;
      tweets = NULL;
      size = 0;
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
  
  void push_back(string d){
        
        if(size == 0){
            tweets = new Tweet(d);
            size++;
        }else{
            Tweet* t = tweets;
            while(t->getNext() != NULL){
                t = t->getNext();    
            }
            t->setNext(new Tweet(d));
            size++;
        }
        
    }
    
    Tweet* get(int i){
        if(i < size && i>=0){
            Tweet* n = tweets;
            for(int x = 0; x<i;x++){
                n = n->getNext();
            }
            return n;
        }else{
            //throw invalid_argument("La posicion no existe");
            if(size == 0){
                cout<<"La lista de tweets está vacía";
            }else{
                cout<<"La posicion no existe";
            }
            return NULL;
        }
        
    }
    
    
    string to_string() {
        string s = getDato()->to_string();
        s.append(" >> ");
        Tweet* t = tweets;
        while(t != NULL){
            s.append(t->getDato());
            s.append(" > ");
            t = t->getNext();
        }
        s.append("\n");
		return s;
	}


	friend std::ostream& operator<<(std::ostream& os, Nodo& b) {
		return os << b.to_string();
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
        Nodo* n;
        while(t->getNext() != NULL){
            n = t;
            t = t->getNext();    
            delete n;
        }
        delete t;
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
    
    void print(){
        if(size == 0){
            cout<<"La lista está vacía"<<endl;
        }else{
            Nodo* t = ptr;
            do{
                //cout<<"("<<(*t).getDato()->getX()<<", "<<t->getDato()->getY()<<"), ";
                cout<<(*t);
                t = t->getNext();
                
            }while(t != NULL);
            cout<<endl;
        }
    }
    
    Nodo* get(int i){
        if(i < size && i>=0){
            Nodo* n = ptr;
            for(int x = 0; x<i;x++){
                n = n->getNext();
            }
            return n;
        }else{
            //throw invalid_argument("La posicion no existe");
            if(size == 0){
                cout<<"La lista está vacía";
            }else{
                cout<<"La posicion no existe";
            }
            return NULL;
        }
        
    }
    
    void insert(Point* p, int pos){
        if(pos >= 0 && pos <= size){
            //Si la lista está vacía o si se quiere insertar el nodo al final
            //se usa el método push_back
            if(size == 0 || pos == size){ 
                push_back(p);
            }else{
                Nodo* n = new Nodo(p);
                //Si se quiere insertar el nodo de primero en la lista
                if(pos == 0){
                    n->setNext(ptr);
                    ptr = n;
                }else{
                    Nodo* t = get(pos-1);
                    n->setNext(t->getNext());
                    t->setNext(n);
                }
                size++;
            }
        }else{
            //throw invalid_argument("La posicion no existe");
            cout<<"La posicion no existe"<<endl;
            
        }
        
    }
    
    void remove(int pos){
        
        if((pos >= 0 && pos <= size) && size > 0){
            //Si la lista está vacía o si se quiere insertar el nodo al final
            //se usa el método push_back
            if(pos == 0){ 
                Nodo* t = ptr;
                ptr = ptr->getNext();
                delete t;
            }else{
                Nodo* t = get(pos-1);
                Nodo* t2 = t->getNext();
                
                t->setNext(t2->getNext());
                delete t2;
            }
            size--;
        }else{
            //throw invalid_argument("La posicion no existe o la lista está vacía");
            cout<<"La posicion no existe o la lista está vacía"<<endl;
        }
        
    }
    
};


int main()
{
   
   Lista l = Lista();
   
   l.push_back(new Point(1,1));
   
   l.print();
   
   l.push_back(new Point(2,2));
   
   l.print();
   
   for(int i = 3; i<10; i++){
       l.push_back(new Point(i,i));
   }
   
   l.print();
   
   cout<<(*l.get(2)->getDato())<<endl;
   cout<<(*l.get(2))<<endl;
   
   l.insert(new Point(20,20),5);
   
   l.print();
   
   /*Lista l2 = Lista();
   
   l2.insert(new Point(20,20),5);
   l2.insert(new Point(20,20),0);
   l2.insert(new Point(19,19),0);
   
   l2.print();
   */
   
   l.remove(4);
   l.print();
   
   l.get(5)->push_back("Hola");
   l.get(5)->push_back("Mundo");
   
   l.print();
   
   return 0;
}
