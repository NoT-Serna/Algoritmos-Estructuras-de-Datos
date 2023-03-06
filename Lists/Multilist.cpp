#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;
class Liga{
private:
    string dato;
    Liga* ptr;

public:
    Liga(){
        dato = " ";
        ptr = NULL;
    }
    
    ~Liga(){
    }
    
    Liga(string d){
        dato = d;
        ptr = NULL;
    }
    
    string get_dato(){
        return dato;
    }
    
    void set_dato(string d){
        dato = d;
    }
    
    Liga* get_next(){
        return ptr;
    }
    
    void set_next(Liga* p){
        ptr = p;
    }
    
    string to_string() {
		return get_dato();
	}


	friend std::ostream& operator<<(std::ostream& os, Liga& b) {
		return os << b.to_string();
	}
    
    
};

class Equipo{
private:
    string dato;
    Equipo* ptr;

public:
    Equipo(){
        dato = "";
        ptr = NULL;
    }
    
    ~Equipo(){
    }
    
    Equipo(string d){
        dato = d;
        ptr = NULL;
    }
    
    string get_dato(){
        return dato;
    }
    
    void set_dato(string d){
        dato = d;
    }
    
    Equipo* get_next(){
        return ptr;
    }
    
    void set_next(Equipo* p){
        ptr = p;
    }
    
    string to_string() {
		return get_dato();
	}


	friend std::ostream& operator<<(std::ostream& os, Equipo& b) {
		return os << b.to_string();
	}
    
    
    
};

template<typename T>
class Nodo{
private:
  T dato;
  Nodo* next;
  Equipo* equipo;
  Liga* liga;
public:

 Nodo(T d){
     dato = d;
     next =  NULL;
     equipo = NULL;
     liga = NULL;  
 }
 
 ~Nodo(){
 }
 
 T get_dato(){
     return dato;
 }
 
 void set_dato(T d){
     dato = d;
 }
 
 Nodo* get_next(){
     return next;
 }
 
 void set_next(){
     next = NULL;
 }
 
 void set_next(Nodo* n){
     next = n;
 }
 
    
};

template<typename T>
class Lista{
private:
  Nodo<T>* ptr;
  int size;

public:

    Lista(){
        ptr = NULL;
        size = 0;
    }
  
    ~Lista(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            Nodo<T>* temp_next = ptr->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el último nodo
        }
    }
    
    Nodo<T>* get_nodo(int pos) {
        if(size == 0) {
            throw invalid_argument("La lista no tienen nodos");
        } else if (pos >= size || pos < 0) {
            throw invalid_argument("El nodo no esta en la lista");
        } else {
            Nodo<T>* temp = ptr;
            for(int i = 0; i < pos; i++) {
                temp = temp->get_next();
            }
            return temp;
        }
        return NULL;
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                cout<<temp->get_dato()<<","<<"\t";
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    void push_back(T d){
        Nodo<T>* nodo = new Nodo<T>(d);
        
        if(ptr == NULL){//La lista está vacía
            ptr  = nodo;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void insert(T d, int pos){
        if(pos == 0){
            Nodo<T>* nodo = get_nodo(pos);
            Nodo<T>* new_node = new Nodo<T>(d);
            new_node->set_next(nodo);
            ptr = new_node;
            size++;
        }else if(pos == size || size == 0){
            push_back(d);
        }else{
            Nodo<T>* prev_node = get_nodo(pos-1);
            Nodo<T>* insert_node = prev_node->get_next();
            
            Nodo<T>* temp = new Nodo<T>(d);
            prev_node->set_next(temp);
            temp->set_next(insert_node);
            size++;
        }
    }
    
    bool search(T d){
      Nodo<T>* temp = ptr;
      while(temp != NULL){
          if(temp->get_dato() == d){
              cout<<"Dato encontrado";
              return true;
          }
          temp = temp->get_next();
      }
      cout<<"Dato no encontrado";
      return false;
    }
    
    void remove_nodo(int pos){
        if(pos < 0 || pos >= size){
            cout<<"No hay nodo en esta posición";
        }else if(pos == 0){
            Nodo<T>* temp = ptr;
            ptr = temp->get_next();
            delete temp;
            size--;
            
        }else if(pos == size-1){
            Nodo<T>* nodo = get_nodo(pos-1);
            Nodo<T>* temp = nodo->get_next();
            nodo->set_next();
            delete temp;
            size--;
        }else{
            Nodo<T>* prev_nodo = get_nodo(pos-1);
            Nodo<T>* temp = temp;
            
            prev_nodo->get_next();
            temp->set_next(get_nodo(pos+1));
            delete temp;
            size--;
            
        }
    }

    
    
};



int main()
{
    Lista<string> l;
    
    l.push_back()
    l.print();
    
    
    
    return 0;
}
