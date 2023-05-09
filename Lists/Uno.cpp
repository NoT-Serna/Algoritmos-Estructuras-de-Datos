#include<iostream>
#include<math.h> 
#include<string>
using namespace std;

class Jugador{
private:
    int jugador;
    Jugador* pointer;

public: 
    Jugador(){
        jugador = 0 ;
        pointer = NULL;
        
    }
    
    ~Jugador(){
        
    }
    
    Jugador(int j){
        jugador = j;
        pointer = NULL;
    }
    
    int get_dato(){
        return jugador;
    }
    
    void set_dato(int j){
        jugador = j;
    }
    
    Jugador* get_next(){
        return pointer;
    }
    
    void set_next(Jugador* p){
        pointer = p;
    }
    
    string to_string(){
        string s = std::to_string(jugador);
        return s;
    }
    
    friend std::ostream& operator<<(std::ostream& os, Jugador& b){
        return os <<b.to_string();
    }
};

class Cartas{
private:
    int color;
    int numero;
    Cartas* pointer;

public: 
    Cartas(){
        color = 0;
        numero = 0;
        pointer = NULL;
        
    }
    
    ~Cartas(){
        
    }
    
    Cartas(int c, int n){
       this-> color = c;
       this-> numero = n;
        pointer = NULL;
    }
    
    int get_color(){
        return color;
    }
    
    int get_numero(){
        return numero;
    }

    
    Cartas get_cartas(){
        return *this;
    }

    
    
    void set_color(int c){
        color = c;
    }
    
    void set_numero(int n){
        numero = n;
    }
    
    Cartas* get_next(){
        return pointer;
    }
    
    void set_next(Cartas* p){
        pointer = p;
    }
    
    Cartas& operator=(const Cartas& f){
        set_color(f.color);
        set_numero(f.numero);
        return *this;
    }



    
    string to_string(){
        return "(" + std::to_string(color) + ", " + std::to_string(numero) + ")";
    }
    
    friend std::ostream& operator<<(std::ostream& os, Cartas& b){
        return os <<b.to_string();
    }

};

class Nodo{
  
  Jugador* jugador;
  Nodo* pointer;
  Nodo* prev;
  Cartas* cartas;
  int size; 
  
public:
  
  Nodo(){
      jugador = NULL;
      pointer = NULL;
      prev = NULL;
      cartas = NULL;
      size = 0;
  }
  
  ~Nodo(){
  }
  
  Nodo(Jugador* p){
      jugador = p;
      pointer = NULL;
      prev = NULL;
      cartas = NULL;
      size = 0;
  }
    
  Jugador* get_dato(){
      return jugador;
  }
  
  void set_dato(Jugador* p){
      jugador = p;
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
  
  void push_back(int c , int n){
        
        if(size == 0){
            cartas = new Cartas(c,n);
            size++;
        }else{
            Cartas* c_1 = cartas;
            while(c_1->get_next() != NULL){
                c_1 = c_1->get_next();    
            }
            c_1->set_next(new Cartas(c,n));
            size++;
        }
        
    }
    

    Cartas* get(int i){
        if(i < size && i>=0){
            Cartas* c = cartas;
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

    void bubble_sort(){
    int num_jugadores = 10;
    int num_colores = 4;
    int num_cartas = 10;
    int temp;
    for(int i = 0; i<num_cartas; i++){
        for(int j = 0; j<num_cartas-1; j++){
            Cartas* c = cartas;
            if(c->get_cartas().get_numero() > c->get_next()->get_cartas().get_numero()){
                temp = c->get_numero();
                c->get_cartas()->get_numero() = c->get_next()->get_numero();
            
             }
            }
        }
    }



    

    string to_string(){
        string s = get_dato()->to_string();
        s.append(">>");
        Cartas* c = cartas;
        while(c != NULL){
            s.append(c->get_cartas().to_string());
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
    
    void push_back(Jugador* d){
        
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
    
    
    void insert(Jugador* p, int pos){
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
    
    srand(1234);
    int num_jugadores = 10;
    int num_colores = 4;
    int num_cartas = 10;
    Lista l = Lista();
    
    
    for(int i = 0; i<4; i++){
        l.push_back(new Jugador(rand()%num_jugadores));
    }
    
    l.get(0)->push_back(rand()%num_colores, rand()%num_cartas);
    l.get(0)->push_back(rand()%num_colores, rand()%num_cartas);
    l.get(0)->push_back(rand()%num_colores, rand()%num_cartas);
    
    l.get(1)->push_back(rand()%num_colores, rand()%num_cartas);
    l.get(1)->push_back(rand()%num_colores, rand()%num_cartas);
    l.get(1)->push_back(rand()%num_colores, rand()%num_cartas);
    
    l.get(2)->push_back(rand()%num_colores, rand()%num_cartas);
    l.get(2)->push_back(rand()%num_colores, rand()%num_cartas);
    l.get(2)->push_back(rand()%num_colores, rand()%num_cartas);
    

    // Necesito ayuda con el ordenamiento para acceder al numero de la carta de la siguiente carta en la lista
    
    
    
    l.print();
    
    
    
   
    /*
    int winner = rand()%num_jugadores;

    int temp = rand()%num;
    for(int i = 0; i<num_colores; i++){
        for(int j = 0; j<num_cartas; j++){
            temp = rand()%num_jugadores
            if(temp!= winner){
                l.get(temp)->push_back(i,j);
            }
        }
    }
    /*
    
    l.print();

    
    /*
   srand(1234);
   int num_jugadores = 4;
   int num_colores = 4;
   int num_tarjetas = 10;
   
   
   
   int winner = rand()%num_jugadores;
   Lista l = Lista();
   
   
   
    int temp=0;
    for(int i = 0; i<num_colores; i++){
        for(int j = 0; j< num_tarjetas; j++){
            temp = rand()%num_jugadores;
            if(temp != winner){
                l.get(temp)->push_back(i,j);
            }
        }
    }
    */
    
    cout<<"Tengo problemas con el ordenamiento profe, necesito acceder al numero en get_numero pero no me esta dejando";




   return 0;
}
