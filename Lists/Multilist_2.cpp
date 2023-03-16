#include<iostream>
#include<math.h> 
#include<string.h>

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

class Persona{
private:
    string dato;
    Persona* pointer;

public: 
    Persona(){
        dato = " ";
        pointer = NULL;
        
    }
    
    ~Persona(){
        
    }
    
    Persona(string d){
        dato = d;
        pointer = NULL;
    }
    
    string get_dato(){
        return dato;
    }
    
    void set_dato(string d){
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
      Point* p = point;
      Point* p_1;
      while(p != NULL){
        p_1 = p;
        p = p->get_next();
        delete p_1;
      }
      delete point;
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
  
  void push_back(int x, int y){
        
        if(size == 0){
            point = new Point(x,y);
            size++;
        }else{
            Point* c_1 = point;
            while(c_1->get_next() != NULL){
                c_1 = c_1->get_next();    
            }
            c_1->set_next(new Point(x,y));
            size++;
        }
        
    }

    Point* get(int i){
        if(i < size && i>=0){
            Point* p = point;
            for(int x = 0; x<i; x++){
                p = p->get_next();
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

    string to_string(){
        string s = get_dato()->to_string();
        s.append(">>");
        Point* p = point;
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
   Lista l = Lista();

   l.push_back(new Persona("Juan")); 
   l.insert(new Persona("David"),1);
   l.push_back(new Persona("Serna"));
   l.print();



   l.get(1)->push_back(2,2);
   l.get(1)->push_back(4,8);
   l.get(0)->push_back(4,5);
   l.get(2)->push_back(3,1);
   l.print();

   

   return 0;
}
