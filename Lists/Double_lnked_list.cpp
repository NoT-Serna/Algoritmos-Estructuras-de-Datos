#include <iostream>
using namespace std;



template<typename T>
class Nodo{
private:
  T  dato;
  Nodo* next;
  Nodo* prev;

public:

 Nodo(T d){
     dato = d;
     next =  NULL;
     prev = NULL;
 }
 
 ~Nodo(){
 }
 
 T get_dato(){
     return dato;
 }

  T* get_dato_ptr(){
     return &dato;
 }
 
 void set_dato(T d){
     dato = d;
 }
 
 Nodo* get_next(){
     return next;
 }
 
 Nodo* get_prev(){
     return prev;
 }
 
 void set_next(){
    next = NULL;
 }
   
  
 void set_next(Nodo* n){
     next = n;
 }
  
 void set_prev(){
   prev =  NULL;
 }
 
 void set_prev(Nodo* p){
     prev = p;
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
            while(temp_next != ptr){
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
            if(pos > size/2){
                for(int i = size-1; i>= pos; i--) {
                    temp = temp->get_prev();
                }
            }else{
                for(int i = 0; i<pos; i++){
                    temp = temp->get_next();
                }
                
            }
            return temp;
        }
    }
    
      int getSize(){
        return size;
    }
    
    void setPtr(Nodo<T>* ptrr) {
        ptr = ptrr;
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp->get_next() != ptr){
                cout<<temp->get_dato()<<","<<"\t";
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    
    void push_back(T d){
        if(size == 0){
            Nodo<T>* first_node = new Nodo<T>(d);
            first_node->set_next(first_node);
            first_node->set_prev(first_node);
            ptr = first_node;
            size++;
        }else{
            Nodo<T>* last_node = ptr->get_prev();
            Nodo<T>* new_node = new Nodo<T>(d);
            last_node->set_next(new_node);
            new_node->set_next(ptr);
            new_node->set_prev(last_node);
            ptr->set_prev(new_node);
            size++;
        }
    }
    
    
    void insert(T d, int pos){
        if(pos == 0){
            Nodo<T>* node = ptr;
            Nodo<T>* new_node = new Nodo<T>(d);
            Nodo<T>* last_node = ptr->get_prev();
            new_node->set_next(ptr);
            node->set_prev(node);
            node->set_prev(last_node);
            last_node->set_next(node);
            ptr = new_node;
            size++;
        }else if(pos == size || size == 0){
            push_back(d);
        }else{
            Nodo<T>* prev_nodo = get_nodo(pos);
            Nodo<T>* insert_nodo = new Nodo<T>(d);
            Nodo<T>* next_nodo = get_nodo(pos+1);
            
            prev_nodo->set_next(insert_nodo);
            insert_nodo->set_prev(prev_nodo);
            insert_nodo->set_next(next_nodo);
            next_nodo->set_prev(insert_nodo);
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

};

int main(){
    Lista<int> l;
    
    for(int i = 0; i<12; i++){
        l.push_back(i);
    }
    l.print();
    
    l.insert(23,4);
    l.print();
    
    
    return 0;
}
