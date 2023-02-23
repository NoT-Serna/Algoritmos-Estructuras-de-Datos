#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

template<typename T>
class Nodo{
private:
  T dato;
  Nodo* next;

public:

 Nodo(T d){
     dato = d;
     next =  NULL;
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
 
 void set_next(Nodo* n){
     next = n;
 }

 void set_next(){
    next = NULL;
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
        if (pos < 0 || pos >= size) {
            throw invalid_argument("No hay ningun nodo que eliminar en esa posicion");
        } else if(pos == 0) {
            Nodo<T>* temp = ptr;
            ptr = temp->get_next();
            delete temp;
            size--;
        } else if (pos == size - 1) {
           Nodo<T>* prev = get_nodo(pos-1);
           Nodo<T>* temp = prev->get_next();
           temp->set_next();
           delete temp;
           size--;
        } 
        else {
            Nodo<T>* prev = get_nodo(pos-1);
            Nodo<T>* temp = prev->get_next();
            Nodo<T>* next = temp->get_next();
            
            prev->set_next(next);
            delete temp;
            size--;
        }
    }

    
    
};



int main()
{
    Lista<int> l;
    
    l.print();
    for(int i=0; i<10; i++){
        l.push_back(i);
    }
    l.print();
    l.insert(100,1);
    l.print();
    
    l.search(2);
    l.remove_nodo(6);
    cout<<endl;
    l.print();
    
    
    
    return 0;
}
