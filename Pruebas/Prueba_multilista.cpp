// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<math.h> 
#include<string.h>

using namespace std;

class Point {

//Atributos
    int x;
    int y;
    Point* pointer;
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

    Point* get_next_point(){
        return pointer;
    }

    int get_dato(){
        return x + y;
    }


    


    //Setters
    void set_x(int xc) {
        x = xc;
    }

    void set_y(int yc) {
        y = yc;
    }

    void set_next(Point* p){
        pointer = p;
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
    
    char to_string(){
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
  
  void set_next(Nodo* p){
      pointer = p;
  }
  
  void push_back(Point* d){
        
        if(size == 0){
            point = new Point(*d);
            size++;
        }else{
            Point* c_1 = point;
            while(c_1->get_next_point() != NULL){
                c_1 = c_1->get_next_point();    
            }
            point->set_next(new Point(*d));
            size++;
        }
        
    }

    Point* get(int i){
        if(i < size && i>=0){
            Point* p = point;
            for(int x = 0; x<i; x++){
                p = p->get_next_point();
            }
            return p;
        }else{
            if(size == 0){
                cout<<"La lista de personas está vacía";
            }else{
                cout<<"la posicion no existe";
            }
            return NULL;
        }

    }

    char to_string(){
        char c = get_dato()->to_string();
        string s(size,c);
        s.append(" Persona >>");
        Point* p = point;
        while(p != NULL){
            s.append(p->get_next_point()->to_string());
            p = p->get_next_point();
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
    
    void push_back(Persona* d){
        
        if(size == 0){
            ptr = new Nodo(d);
            size++;
        }else{
            Nodo* t = ptr;
            while(t->get_next() != NULL){
                t = t->get_next();    
            }
            t->set_next(new Nodo(d));
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
            //Si la lista está vacía o si se quiere insertar el nodo al final
            //se usa el método push_back
            if(size == 0 || pos == size){ 
                push_back(p);
            }else{
                Nodo* n = new Nodo(p);
                //Si se quiere insertar el nodo de primero en la lista
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
            //throw invalid_argument("La posicion no existe o la lista está vacía");
            cout<<"La posicion no existe o la lista está vacía"<<endl;
        }
        
    }
    
};


int main()
{
   
   Lista l = Lista();
   
   l.push_back(new Persona('x'));
   l.print();


   l.get(0)->push_back(new Point(3,4));
   l.print();


   return 0;
}
