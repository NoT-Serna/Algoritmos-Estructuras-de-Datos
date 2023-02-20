# include <iostream>

using namespace std;

template<typename T>

class Vector{
    
private:
    int size ;
    int capacity;
    T* v;
    
public:
    
    Vector(){
        size = 0;
        capacity = 10;
        v = new T[capacity];
    }
    
    Vector(int n){
        size = 0;
        capacity = n;
        v = new T[capacity];
    }
    ~Vector(){
        delete[] v;
    }
    
    int get_size(){
        return size;
    }
    
    int get_capacity(){
        return capacity;
    }
    
    T get(int i){
        if(i >= 0 && i < size)
            return v[i]; 
        else
            return NULL;
    }
    
    void print_vect(){
        for(int i = 0; i<capacity; i++){
            cout<<v[i]<<" ";
        }
    }
    
    void capacity_x2(){
        int aux[capacity];
        for(int i = 0; i<capacity; i++){
            aux[i] = v[i];
        }
        
        capacity = capacity *2;
        v = new int[capacity];
        
        for(int i = 0; i<capacity/2; i++){
            v[i] = aux[i];
        }
    }
    
    void push_back(T x){
        if(capacity > size){
            v[size] = x;
            size++;
        }else{
            capacity_x2();
            v[size] = x;
            size++;
        }
    }

    void move_left(int x){
        for(int i = 0; i > x; i--){
            v[i] = v[i-1];
        }
    }
    
    void move_right(int x){
        for(int i = 0; i<x; i++){
            v[i] = v[i+1];
        }
    }


    void insert(T x , int pos){
        if(size ==  pos){
            push_back(x);
        }else{
            if(pos < size){
                move_right(pos);
                v[pos] = x;       
            }
        }
    }

    bool search(T get){
        for(int i = 0; i<size; i++){
            if(get == v[i]){
                cout<<"el número "<<get<<" fue encontrado."<<"\n";
                return true;
            }
        }
        cout<<"El número "<<get<<" no fue encontrado.";
        return false;
        
    }

    bool remove(T get) {
      for(int i = 0; i<size; i++){
        if(get ==v[i]){
            v[i] = v[i-1];
            size--;
            cout<<"Eliminado el número: "<<get<<endl;;
            return true;
        }
    }   
        cout<<"El número "<<get<<" no se encuentra en el array: ";
        return false;

    }

    
};





int main(){
    
    //Initializing the array
    
    Vector<int> v;

    //Printing array & push_back
    cout<<"Original array: " <<"\t";
    for(int i = 0; i<10; i++){
        v.push_back(i);
    }
    v.print_vect();
    cout<<endl;
    
    //Insert
    cout<<"Insert method: " <<"\t";
    v.insert(600,1);
    v.print_vect();
    cout<<endl;
    
    //Search
    cout<<"Search method: " <<"\t";
    v.search(600);
    cout<<endl;

    //Delete 
    cout<<"Delete method: ";
    v.remove(600);
    v.print_vect();

    return 0;
}
