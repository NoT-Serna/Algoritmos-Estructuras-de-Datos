#include <iostream>
using namespace std;

int** crear_mat(int f, int c) {
    int** m = new int*[f];
    for (int i = 0; i < f; i++) {
        m[i] = new int[c];
        for(int j=0; j<c ; j++){
            m[i][j] =  0;
        }
    }
    return m;
}

void destruir_mat(int** m, int f) {
    for (int i = 0; i < f; i++) {
        delete[] m[i];
    }
    delete m;
}

void print_mat(int** m, int  f, int c){
    for (int i = 0; i < f; i++) {
        for(int j=0; j<c ; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

class Cita{
    private:
    int codigo_paciente;
    int codigo_medico;
    int codigo_enfermedad;
    
    public:
    
    Cita(){
        codigo_paciente = 0;
        codigo_medico = 0;
        codigo_enfermedad = 0;
    }
    
    Cita(int p, int m, int e){
        codigo_paciente = p;
        codigo_medico = m;
        codigo_enfermedad = e;
    }
    
//Hacer el get y el set para cada atributo
//Getters
    int get_codigo_paciente(){
        return codigo_paciente;
    }
    
    int get_codigo_medico(){
        return codigo_medico;
    }
    
    int get_codigo_enfermedad(){
        return codigo_enfermedad;
    }

//Setters
    
    void set_codigo_paciente(int p){
        codigo_paciente = p;
    }
    
    void set_codigo_medico(int m){
        codigo_medico = m;
    }
    
    void set_codigo_enfermedad(int e){
        codigo_enfermedad = e;
    }
    
    
    
    Cita& operator=(const Cita& f) { 
		codigo_paciente = f.codigo_paciente;
		codigo_medico = f.codigo_medico;
		codigo_enfermedad = f.codigo_enfermedad;
		return *this;
	}
	
	string to_string() {
	    string s = std::to_string(codigo_paciente)+", "+std::to_string(codigo_medico)+", "+std::to_string(codigo_enfermedad);
	    return s;
	}

	friend std::ostream& operator<<(std::ostream& os, Cita& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Cita b) {
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
    
    void add(T d){
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
    
    void insert(T d, int i){
        if(i<=size && i>=0 && ptr != NULL){
            Nodo<T>* nodo = new Nodo<T>(d);
            if(i == 0){
                nodo->set_next(ptr);
                ptr = nodo;
            }else{
                int j = 0;
                Nodo<T>* temp =  ptr;
                while(j<i-1){
                    temp = temp->get_next();
                    j++;
                }
                nodo->set_next(temp->get_next());
                temp->set_next(nodo);
            }
            size++;
        }else{//Si el índice es incorrecto o la lista está vacía, se añade al final
            add(d);
        }
        
    }
    
    int get_size(){
        return size;
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                cout<<temp->get_dato()<<"\t";
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    void println(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                cout<<temp->get_dato()<<endl;
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    Nodo<T>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<T>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
};


class EPSUrsa{
    private:
    Lista<Cita*> citas;
    int paciente;
    int medico;
    int enfermedad;
    int numero_cita;
    int** matriz;
    
    public:
    
    EPSUrsa(){
        paciente = 0;
        medico = 0;
        enfermedad = 0;
        numero_cita = 0;
        matriz = crear_mat(medico, enfermedad);

    }
    
    EPSUrsa(int p, int m, int e, int c){
        paciente = p;
        medico = m;
        enfermedad = e;
        numero_cita = c;
        matriz = crear_mat(medico,enfermedad);
    
    
    }
    
    ~EPSUrsa(){
        destruir_mat(matriz, medico);
    }
    
    void init_lista(){
        Cita* t;
        int p;
        int m;
        int e;
        for(int i = 0; i<numero_cita; i++){
            p = rand()%p;
            m = rand()%m;
            e = rand()%e;
            t = new Cita(p,m,e);
            citas.add(t);
        }
        cout<<"Fueron creadas "<<citas.get_size()<<" en la plataforma"<<endl;
        println();   
     }
    
    void print(){
        citas.print();
    }
    
    void println(){
        citas.println();
    }
    
    void calc_mat(){
        Nodo<Cita*>* temp = citas.get(0);

        while(temp != NULL){
            matriz[temp->get_dato()->get_codigo_medico()][temp->get_dato()->get_codigo_enfermedad()]++;
            temp = temp->get_next(); 
        }

        cout<<endl;
        print_mat(matriz,medico,enfermedad);
    }
    
};
/*
    int enfermedad_mayor(){

    }
    
    int enfermedad_menor(){

    }
    
    int medico_mayor(){
    }
    
    int medico_menor(){

    }
    
    float promedio_citas(){

    }
    
    
    int medico_mayor_e(int e){

    }

*/
    








int main() {
    srand(1234);
    int p = 10;
    int m = 10;
    int e = 10;
    int c = 100;
    EPSUrsa eps = EPSUrsa(p,m,e,c);
    eps.init_lista();

    eps.calc_mat();


    return 0;
}