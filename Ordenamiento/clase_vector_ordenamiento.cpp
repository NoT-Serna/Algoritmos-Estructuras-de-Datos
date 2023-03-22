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
            v[i] = v[i+1];
            size--;
            cout<<"Eliminado el número: "<<get<<endl;;
            return true;
        }
    }   
        cout<<"El número "<<get<<" no se encuentra en el array: ";
        return false;

    }
    
    int bubble_sort(){
        int temp, j;
        for(j = 0; j<size; j++){
            for(int i =0; i<size-1; i++){
                if(v[i] > v[i+1]){
                    temp = v[i];
                    v[i] = v[i+1];
                    v[i+1] = temp;
                }
            }
        }
    }

    
    int insert_sort(){
        int temp, j;
        for(int i = 0; i<size; i++){
            temp = v[i];
            j = i -1;
        }
        while(j>= 0 && v[j] > temp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
        
    }
    
    int select_sort(){
        for(int i = 0; i<size;  i++){
            int min = i;
        
            for(int j = i+1; j<size; j++){
                if(v[j] < v[min]){
                    min = j;
                }
            }
            if(min != i){
                int temp = v[min];
                v[min] = v[i];
                v[i] = temp;
            }
        }
        
    }
    
    int shell_sort(){
        for(int gap = size/2; gap >0; gap/=2){
            for(int i = gap; i<size; i+=1){
                int temp = v[i];
                int j;
                for(j = i;  j>gap && v[j-gap] > temp; j -= gap){
                    v[i] = temp;
                }
                
            }
        }
        
    }
    
    int partition(){
        int i = get(0)-1;
        int j = 0;
        int pivot = get(size);
        
        for(j = get(0); j<=size; j++){
            if(v[j]<pivot){
                i++;
                int temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
        return i;
    }

    
};
