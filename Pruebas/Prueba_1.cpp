#include <iostream>
#include<stdlib.h>
using namespace std;
#include<stdexcept>
#include<string>


using namespace std;

class Transaccion{
    int emp_origen;
    int emp_destino;
    int cantidad_monto;

public:
    Transaccion(){
        emp_origen = 0;
        emp_destino = 0;
        cantidad_monto = 0;

    }

    Transaccion(int origen,int destino, int monto){
        emp_origen = origen;
        emp_destino = destino;
        cantidad_monto = monto;
        

    }
    //Getters
    int get_emp_origen(){
        return emp_origen;
    }

    int get_emp_destino(){
        return emp_destino;
    }

    int get_cantidad_monto(){
        return cantidad_monto;
    }

    //Setters
    void set_emp_origen(int origen){
        emp_origen = origen;
    }

    void set_emp_destino(int destino){
        emp_destino = destino;
    }

    void set_cantidad_monto(int monto){
        cantidad_monto = monto;
    }

    Transaccion& operator=(const Transaccion& f){
        emp_origen = f.emp_origen;
        emp_destino = f.emp_destino;
        cantidad_monto = f.cantidad_monto;
        return *this;
    }

    string to_string(){
        return "("+std::to_string(emp_origen) + ", "+ std::to_string(emp_destino)+ ", " + std::to_string(cantidad_monto)+")";

    }

    friend std::ostream& operator<<(std::ostream& os, Transaccion b){
        return os << b.to_string();
    }
    
};





template<typename T>
class Nodo{
private:
  T  dato;
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

};



int main()
{
    srand(1234);
    int num_emp = 4; //Número de empresas
    int num_trans = 100; //Número de transacciones
    int error = 16; //Variable para incluir errores en las transacciones
    int monto_max = 100000; //Variable para definir el máximo valor de un monto
    
    int** mat_bank; //Declaración de la matriz con información reportada por el banco, calculada con las transacciones originales
    int** mat_emp; //Declaración de la matriz con información alterada, reportada por la empresa, calculada con las transacciones alteradas
    
    
    Lista<Transaccion> t;

    //Creación de transacciones. Valide que no haya transacciones con un mismo origen y destino, y que el monto no pase del máximo establecido: monto = rand()%100000;
    int origen = 0;
    int destino = 0;
    int monto = 0;

    for(int i = 0; i< num_trans; i++){
        int origen = rand()%num_emp;
        int destino = rand()%num_emp;

        while(origen == destino){
            destino = rand()%num_emp;
        }
        int monto = rand()%monto_max;
        t.push_back(Transaccion(origen,destino,monto));
    }
    
    //Imprimir lista de transacciones originales
    for(int i=0; i<num_trans; i++){
        cout<<t.get_nodo(i)->get_dato()<<endl;
    }
    
    //Calcular monto total de transacciones entre empresas en mat_bank
    
    //Imprimir la matriz mat_bank

    //Alterar las transacciones cuyo indice%error == 0, disminuyendo su valor en 25% (monto*0.75)    
    
    //Imprimir lista de transacciones alteradas

    //Calcular monto total de transacciones alteradas entre empresas en mat_alt
    
    //Imprimir la matriz mat_alt

    //Imprimir las diferencias encontradas entre ls matrices
    
    return 0;
}
