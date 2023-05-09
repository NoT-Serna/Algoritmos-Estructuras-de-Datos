#include<iostream>
#include<math.h> 
#include<string>
#include<sstream>
using namespace std;

class Point {

//Atributos
    int x;
    int y;
    Point* next;

public:
    
    //Constructores
    Point(int xc, int yc) {
       this-> x = xc;
       this-> y = yc;
        next = NULL;

    }

    //Getters
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }

    Point* get_next(){
        return next;
    } 

    Point get_dato_point(){
        return *this;
    }




    //Setters
    void set_x(int xc) {
        x = xc;
    }

    void set_y(int yc) {
        y = yc;
    }

    void set_next(Point* p){
        next = p;
    }
    
    Point& operator=(const Point& f) { 
		set_x(f.x);
		set_y(f.y);
		return *this; 
	}
	
	string to_string() {
		return "("+std::to_string(x) + "," + std::to_string(y)+")";
	}


	friend std::ostream& operator<<(std::ostream& os, Point& b) {
		return os << b.to_string();
	}

};

class Distancia{
private:
    float dato;
    Distancia* pointer;

public: 
    Distancia(){
        dato = 0;
        pointer = NULL;
        
    }
    
    ~Distancia(){
    }
    
    Distancia(float d){
        dato = d;
        pointer = NULL;
    }
    
    float get_dato(){
        return dato;
    }
    
    void set_dato(float d){
        dato = d;
    }
    
    Distancia* get_next(){
        return pointer;
    }
    
    void set_next(Distancia* d){
        pointer = d;
    }
    
    float to_string(){
        return get_dato();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Distancia& b){
        return os <<b.to_string();
    }
};

class Nodo{
  
  Point* point;
  Nodo* pointer;
  Distancia* distancia;
  int size; 
  
public:
  
  Nodo(){
      point = NULL;
      pointer = NULL;
      distancia = NULL;
      size = 0;
  }
  
  ~Nodo(){
      Distancia* d = distancia;
      Distancia* d_1;
      while(d != NULL){
        d_1 = d;
        d = d->get_next();
        delete d_1;
      }
      delete point;
  }
  
  Nodo(Point* p){
      point = p;
      pointer = NULL;
      distancia = NULL;
      size = 0;
  }
    
  Point* get_dato(){
      return point;
  }
  
  void set_dato(Point* p){
      point = p;
  }
  
  Nodo* get_next(){
      return pointer;
  }
  
  void set_next(Nodo* p){
      pointer = p;
  }
  
  void push_back(float d){
        
        if(size == 0){
            distancia = new Distancia(d);
            size++;
        }else{
            Distancia* c_1 = distancia;
            while(c_1->get_next() != NULL){
                c_1 = c_1->get_next();    
            }
            c_1->set_next(new Distancia(d));
            size++;
        }
        
    }

    Distancia* get(float i){
        if(i < size && i>=0){
            Distancia* d = distancia;
            for(int x = 0; x<i; x++){
                d = d ->get_next();
            }
            return d;
        }else{
            if(size == 0){
                cout<<"La lista de personas está vacía";
            }else{
                cout<<"la posicion no existe";
            }
            return NULL;
        }

    }

    string to_string(){
        string s = get_dato()->to_string();
        s.append(">>");
        Distancia* d = distancia;
        while(p != NULL){
            s.append(p->get_dato_point().to_string());
            p = p->get_next();
        }
        s.append("\n");
        return s;
    }


    friend std:: ostream& operator<<(std:: ostream& os, Nodo& b){
        return os <<b.to_string();
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
        while(t->get_next() != NULL){
            n = t;
            t = t->get_next();    
            delete n;
        }
        delete t;
    }
    
    void push_back(int x, int y){
        
        if(size == 0){
            ptr = new Nodo(x,y);
            size++;
        }else{
            Nodo* t = ptr;
            while(t->get_next() != NULL){
                t = t->get_next();    
            }
            t->set_next(new Nodo(x,y));
            size++;
        }
        cout<<endl;
        
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
                cout<<(*t);
                t = t->get_next();
                
            }while(t != NULL);
            cout<<endl;
        }
    }
    
    Nodo* get(int i){
        if(i < size && i>=0){
            Nodo* n = ptr;
            for(int x = 0; x<i;x++){
                n = n->get_next();
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
    
    void insert(Persona* p, int pos){
        if(pos >= 0 && pos <= size){
            if(size == 0 || pos == size){ 
                push_back(p);
            }else{
                Nodo* n = new Nodo(p);
                if(pos == 0){
                    n->set_next(ptr);
                    ptr = n;
                }else{
                    Nodo* t = get(pos-1);
                    n->set_next(t->get_next());
                    t->set_next(n);
                }
                size++;
            }
        }else{
            cout<<"La posicion no existe"<<endl;
            
        }
        
    }
    
    void remove(int pos){
        
        if((pos >= 0 && pos <= size) && size > 0){
            if(pos == 0){ 
                Nodo* t = ptr;
                ptr = ptr->get_next();
                delete t;
            }else{
                Nodo* t = get(pos-1);
                Nodo* t2 = t->get_next();
                
                t->set_next(t2->get_next());
                delete t2;
            }
            size--;
        }else{
            cout<<"La posicion no existe o la lista está vacía"<<endl;
        }
        
    }
    
};


int main()
{

   return 0;
}
