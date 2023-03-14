#include <iostream>
#include <string>

using namespace std;

class Point{
private:
    int x;
    int y;
    Point* next;

public:
    Point(int xc, int yc){
        x = xc;
        y = yc;
    }
    
    Point(){
        x = 0;
        y = 0;
    }
    //Getters
    
    int get_x(){
        return x;
    }
    
    int get_y(){
        return y;
    }
    
    Point* get_next(){
        return next;
    }
    
    //Setters
    void set_x(int xc){
        x = xc;
    }
    
    void set_y(int yc){
        y = yc;
    }
    
    void set_next(Point* p){
        next = p;
    }
    
    
    
    
};

class Lista_Point{
private:
    int size = 0;

public:
    Point* ptr;
    
    
    Lista_Point(){
        ptr = NULL;
        size = 0;
    }
    
    ~Lista_Point(){
        
    }
    
    int get_size(){
        return size;
    }
    
    void set_size(int tam){
        size = tam;
    }
    
    Point* get_nodo(int pos) {
        if(size == 0) {
            throw invalid_argument("La lista no tienen nodos");
        } else if (pos >= size || pos < 0) {
            throw invalid_argument("El nodo no esta en la lista");
        } else {
            Point* temp = ptr;
            for(int i = 0; i < pos; i++) {
                temp = temp->get_next();
            }
            return temp;
        }
        return NULL;
    }
    
    void push_back(int x, int y){
        Point* p_1 = new Point(x,y);
        if (ptr == NULL){
            ptr = p_1;
        }else{
            Point* temp = ptr;
            while(temp -> get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(p_1);
        }
        size++;
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            Point* temp =  ptr;
            while(temp != NULL){
                cout<<temp->get_x()<<","<<temp->get_y()<<")"<<"\t";
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
       void insert(int x, int y, int pos){
        if(pos == 0){
            Point* nodo = get_nodo(pos);
            Point* new_node = new Point(x,y);
            new_node->set_next(nodo);
            ptr = new_node;
            size++;
        }else if(pos == size || size == 0){
            push_back(x,y);
        }else{
           Point* prev_node = get_nodo(pos-1);
           Point* insert_node = prev_node->get_next();
            
            Point* temp = new Point(x,y);
            prev_node->set_next(temp);
            temp->set_next(insert_node);
            size++;
        }
    }
    
};

class Persona{
private:
    string nombre;
    int id;
    Persona* next;

public:
    Lista_Point l_p;
    
    Persona(int info){
        id = info;
        next = NULL;
    }
    
    ~Persona(){
        
    }
    
    void set_dato(int persona){
        id = persona;
    }
    void set_next(Point* p){
        l_p.ptr = p;
    }
    
    void set_next_persona(Persona* p_1){
        next = p_1;
    }
    
    int get_dato(){
        return id;
    }
    
    Point* get_next(){
        return l_p.ptr;
    }
    
    int get_size(){
        return l_p.get_size();
    }
    
    Persona* get_next_persona(){
        return next;
    }
    
    
    
};

class Lista_Persona{
public:
    Persona* ptr;
    int size;
    int nodos;

private:
    Lista_Persona(){
        ptr = NULL;
        size = 0;
        nodos = 0;
    }
    
    ~Lista_Persona(){
        
    }
    
   void push_back(int x, int y, int cantidad){
       Persona* temp = ptr;
       for(int i = 0; i<cantidad; i++){
           temp = temp->get_next_persona();
       }
            temp->l_p.push_back(x, y);
   }
   
   void push_back_persona(int id){
          Persona* nueva_persona = new Persona(id);   
           
        if (ptr==nullptr){  
            ptr = nueva_persona;   
        }else{   
            Persona* temp = ptr;
            Persona* prev =nullptr;
            while(temp!=nullptr && id>temp->get_dato()){   
                prev =temp;
                temp = temp -> get_next_persona();    
            }   
            if(temp!=ptr){
                prev->set_next_persona(nueva_persona);    
                nueva_persona->set_next_persona(temp);
            }else{
                nueva_persona->set_next_persona(temp);
                ptr=nueva_persona;
            }
        
        }   
       nodos++;  
   }
    
};

int main(){
    
    
    return 0;
}
