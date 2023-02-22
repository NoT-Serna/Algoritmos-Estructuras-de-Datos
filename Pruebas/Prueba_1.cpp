#include <iostream>
#include<stdlib.h>
using namespace std;
#include<stdexcept>
#include<string>


using namespace std;

class Transaccion{
private:   
    int emp_origen;
    int emp_destino;
    int monto;
    
public:
    Transaccion(){
        emp_origen = 0;
        emp_destino = 0;
        monto = 0;
    }
    
    Transaccion(emp_origen,emp_destino,monto){
        emp_origen = origen;
        emp_destino = destino;
        monto = m;
    }
    
    int get_origen(int origen){
        return origen;
    }
    
    int get_destino(int destino){
        return destino;
    }
    
    int get_m(){
        return monto;
    }
    
    void set_origen(int or){
        emp_origen = a;
    }
    
    void set_destino(int a){
        emp_destino = a;
    }
    
    void set_monto(int a){
        monto = a;
    }
    
    
    Transaccion& operator=(const Transaccion& f) { 
        emp_origen = f.emp_origen;
        emp_destino = f.emp_destino;
        monto = f.monto;
        return *this; 
    }
  
  
  string to_string() {
        return "("+std::to_string(origen) + "," + std::to_string(destino)+ "," + std::to_string(m)+")";
    }
    
  friend std::ostream& operator<<(std::ostream& os, Transaccion& b) {
        return os << b.to_string();
    }
    
};





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
    
    
    Lista<Transaccion> t = Lista();

    //Creación de transacciones. Valide que no haya transacciones con un mismo origen y destino, y que el monto no pase del máximo establecido: monto = rand()%100000;
    for (int i = 0; i<num_trans; i++){
        
        
       int origen = rand()%num_emp;
        
        while(origen == destino){
            destino = rand()%num_emp;
        }
         int monto = rand()%100000;
         
         t.add(Transaccion(origen,destino,m))
    }
        
    
    //Imprimir lista de transacciones originales
    for(int i=0; i<num_trans; i++){
        cout<<t.get(i)->get_dato()<<endl;
    }
    
    //Calcular monto total de transacciones entre empresas en mat_bank
    mat_bank = new int*[num_emp];
    for(int i = 0; i < num_emp; i++){
        mat_bank[i] = new int[num_emp];
    }
    
    
    
    //Imprimir la matriz mat_bank
    
    for(int i = 0; i<num_emp; i++){
        for(int j = 0; j < num_emp; j++){
            mat_bank[i][j] = 0;
        }
        cout<<endl;
    }

    //Alterar las transacciones cuyo indice%error == 0, disminuyendo su valor en 25% (monto*0.75) 
    for(int i = 0; i<num_trans; i++){
        if(i%error == 0){
            int monto = t.get(i)->get_monto();
            t.get(i)->get_dato.set_monto(monto * 0.75);
        }
    
    }
    
    //Imprimir lista de transacciones alteradas
        for(int i=0; i<num_trans; i++){
        cout<<t.get(i)->get_dato()<<endl;
    }

    //Calcular monto total de transacciones alteradas entre empresas en mat_alt
    for(int i = 0; i<num_trans; i++){
        Transaccion trans = t.get(i)->get_dato();
        
        int fila = trans.get_origen();
        int columna = trans.get_destino();
        int monto = trans.get_monto();
        
        mat_bank[fila][columna] += monto;
    }
    
    //Imprimir la matriz mat_alt

    //Imprimir las diferencias encontradas entre ls matrices
    /*
    for(int i=0; i<num_emp; i++){
        for(int j=0; j<num_emp; j++){
            if(mat2[i][j] != mat[i][j])
                cout<<"Diferencia en total de transacciones entre empresas "<<i<<" y "<<j<<" por "<<(mat_alt[i][j]-mat_bank[i][j])<<endl;
        }
    }
    
    */
    return 0;
}
