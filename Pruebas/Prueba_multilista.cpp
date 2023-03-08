// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include <math.h> 

using namespace std;

class Point {

//Atributos
    int x;
    int y;
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

    //Getters
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }


    //Setters
    void set_x(int xc) {
        x = xc;
    }

    void set_y(int yc) {
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

class Persona{
private:
    char dato;
    Persona* pointer;

public: 
    Persona(){
        dato = 0;
        pointer = NULL;
        
    }
    
    ~Persona(){
        
    }
    
    Persona(char d){
        dato = d;
        pointer = NULL;
    }
    
    char get_dato(){
        return dato;
    }
    
    void set_dato(char d){
        dato = d;
    }
    
    Persona* get_next(){
        return pointer;
    }
    
    void set_next(Persona* p){
        pointer = p;
    }
    
    string to_string(){
        return get_dato();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Persona& b){
        return os <<b.to_string();
    }
};



class Nodo{
  
  Point* point;
  Nodo* pointer;
  Persona* persona;
  int size; 
  
public:
  
  Nodo(){
      point = NULL;
      pointer = NULL;
      persona = NULL;
      size = 0;
  }
  
  ~Nodo(){
      
  }
  
  Nodo(Persona* p){
      persona = p;
      pointer = NULL;
      point = NULL;
      size = 0;
  }
    
  Persona* get_dato(){
      return persona;
  }
  
  void set_dato(Persona* p){
      persona = p;
  }
  
  Nodo* get_next(){
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

   
   return 0;
}
