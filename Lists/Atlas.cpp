#include<iostream>
#include<math.h> 
#include<string>
using namespace std;

class Pais{
private:
    string nombre;
    Pais* pointer;

public: 
    Pais(){
        nombre = " ";
        pointer = NULL;
        
    }
    
    ~Pais(){
        
    }
    
    Pais(string n){
        nombre = n;
        pointer = NULL;
    }
    
    string get_dato(){
        return nombre;
    }
    
    void set_dato(string n){
        nombre = n;
    }
    
    Pais* get_next(){
        return pointer;
    }
    
    void set_next(Pais* p){
        pointer = p;
    }
    
    string to_string(){
        return get_dato();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Pais& b){
        return os <<b.to_string();
    }
};

class Ciudad{
private:
    string dato;
    int poblacion;
    Ciudad* pointer;

public: 
    Ciudad(){
        dato = " ";
        poblacion = 0;
        pointer = NULL;
        
    }
    
    ~Ciudad(){
        
    }
    
    Ciudad(string d, int p){
       this-> dato = d;
       this->poblacion = p;
        pointer = NULL;
    }
    
    string get_dato(){
        return dato;
    }
    
    int get_poblacion(){
        return poblacion;
    }
    
    Ciudad get_ciudad(){
        return *this;
    }
    
    
    void set_dato(string d){
        dato = d;
    }
    
    void set_poblacion(int p){
        poblacion = p;
    }
    
    Ciudad* get_next(){
        return pointer;
    }
    
    void set_next(Ciudad* p){
        pointer = p;
    }
    
    Ciudad& operator=(const Ciudad& f){
        set_dato(f.dato);
        set_poblacion(f.poblacion);
        return *this;
    }
    
    string to_string(){
        return "(" + get_dato() + ", " + std::to_string(get_poblacion()) + ")";
    }
    
    friend std::ostream& operator<<(std::ostream& os, Ciudad& b){
        return os <<b.to_string();
    }
};

class Nodo{
  
  Pais* pais;
  Nodo* pointer;
  Nodo* prev;
  Ciudad* ciudad;
  int size; 
  
public:
  
  Nodo(){
      pais = NULL;
      pointer = NULL;
      prev = NULL;
      ciudad = NULL;
      size = 0;
  }
  
  ~Nodo(){
  }
  
  Nodo(Pais* p){
      pais = p;
      pointer = NULL;
      prev = NULL;
      ciudad = NULL;
      size = 0;
  }
    
  Pais* get_dato(){
      return pais;
  }
  
  void set_dato(Pais* p){
      pais = p;
  }
  
  Nodo* get_next(){
      return pointer;
  }
  
  Nodo* get_prev(){
      return prev;
  }
  
  void set_next(Nodo* p){
      pointer = p;
  }
  
  void set_prev(Nodo* a){
      prev = a;
  }
  
  void push_back(string c , int p){
        
        if(size == 0){
            ciudad = new Ciudad(c,p);
            size++;
        }else{
            Ciudad* c_1 = ciudad;
            while(c_1->get_next() != NULL){
                c_1 = c_1->get_next();    
            }
            c_1->set_next(new Ciudad(c,p));
            size++;
        }
        
    }

    Ciudad* get(int i){
        if(i < size && i>=0){
            Ciudad* c = ciudad;
            for(int x = 0; x<i; x++){
                c = c->get_next();
            }
            return c;
        }else{
            if(size == 0){
                cout<<"La lista de personas está vacía";
            }else{
                cout<<"la posicion no existe";
            }
            return NULL;
        }

    }

    Ciudad* get_capital(string d){
        pais = new Pais(d);
        cout<<"La capital de "<< d << " es " << *get(0)<<endl;;
        return get(0);
    }

    


    string to_string(){
        string s = get_dato()->to_string();
        s.append(">>");
        Ciudad* c = ciudad;
        while(c != NULL){
            s.append(c->get_ciudad().to_string());
            c = c->get_next();
            s.append(">>");
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
    
    void push_back(Pais* d){
        
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
    
    
    void insert(Pais* p, int pos){
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

   l.push_back(new Pais("Colombia")); 
   l.insert(new Pais("Italia"),1);
   l.push_back(new Pais("China"));
   
   l.get(0)->push_back("Bogotá", 8000000);
   l.get(0)->push_back("Medellín", 2569000);
   l.get(0)->push_back("Cali", 2228000);
   l.get(0)->get_capital("Colombia");


   l.get(1)->push_back("Roma", 2873000);
   l.get(1)->push_back("Milan", 1352000);
   l.get(1)->get_capital("Italia");

   l.get(2)->push_back("Beijing", 21540000);
   l.get(2)->push_back("Shanghái", 26320000);
   l.get(2)->get_capital("China");
   cout<<endl;

   l.print();



   return 0;
}
