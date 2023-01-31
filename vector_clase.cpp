// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Vector {
    private:
        int size = 0;
        int capacity = 2;
        int *v;
        
        void print_vect(){
            cout << "El vector se ve asi:";
            cout << "[";
            for(int i = 0; i<capacity; i++){
                cout<<v[i]<<", ";
            }
            cout << "]";
            cout << endl;
        }
        
        void capacity_x2(){
            int aux[capacity];
            for(int i=0; i<capacity; i++) {
               aux[i] = v[i];
            }
               
            //crea nuevo vector del doble de tamaño
            capacity = capacity * 2;
            v = new int[capacity]; // posible error
               
            // pasa los datos viejos al nuevo vector
            for(int i = 0; i < capacity / 2; i++) {
               v[i] = aux[i];
            }
            
        }
        
        void move_right(int x) {
            for(int i=size+1; i > x; i--) {
                v[i] = v[i-1];
            }
        }

        void move_left(int x){
            for(int i= x; i<capacity; i++){
                v[i] = v[i+1];
            }
        }
        
    public:
        Vector() {
            v = new int[capacity];
        }
        
        void push_back(int x) {
            // cuando no esta lleno el vector
            if(capacity > size) {
                v[size] = x;
                size++;
            } else { // cuando se llena el vector
               // vector auxiliar para los datos viejos
               capacity_x2();
               
               v[size] = x;
               size++;
            }
            print_vect();
        }
        
        bool insert(int x, int i) {
            if(i<size) {
                if(capacity > size) {
                    move_right(i);
                    v[i] = x;
                } else {
                    capacity_x2();
                    move_right(i);
                    v[i] = x;
                }
                print_vect();
                return true;
            } else {
                cout << "nada";
                return false;
            }
        }
        
        bool remove(int i) {
            if(i<size) {
                move_left(i);
                size--;
                return true;
            } else {
                return false;
            }
            print_vect();
        }
        
        int get(int i) {
            return v[i];
        }
        
        void set(int x, int i) {
            v[i] = x;
            print_vect();
        }
};        

int main() {
    int x, i;
    int eleccion;
    bool seguir = true;
    Vector vect_1 = Vector();
    
    cout<< "Bienvenido al menu del vectorisisimos" << endl;
    while(seguir) {
        cout << "Escoga la funcion que quiere utilizar:" << endl;
        cout << "   1. push_back: Agregue un dato en la ultima posicion." << endl;
        cout << "   2. insert: Agregue un dato en cualquier posicion." << endl;
        cout << "   3. remove: Elimine un dato en cualquier posicion." << endl;
        cout << "   4. get: Obtenga un dato de cualquier posicion." << endl;
        cout << "   5. set: Establezca un dato en cualquier posicion." << endl << endl;
        cout << "   6. salir." << endl;
        cout << "Cual es el numero de su eleccion?: ";
        cin >> eleccion;
        
        if(eleccion == 1) {
            cout << "Ingrese el numero que quiere agregar: ";
            cin >> x;
            vect_1.push_back(x);
        } else if (eleccion == 2) {
            cout << "Ingrese el numero que quiere agregar: ";
            cin >> x;
            cout << "Ingrese la posicion en que desea agregar el numero: ";
            cin >> i;
            vect_1.insert(x, i);
        } else if (eleccion == 3) {
            cout << "Ingrese la posicion en que desea eliminar el numero: ";
            cin >> i;
            vect_1.remove(i);
        } else if (eleccion == 4) {
            cout << "Ingrese la posicion en que desea obtener el numero: ";
            cin >> i;
            cout << "El numero que esta en la posicion " << i << " es: " << vect_1.get(i) << endl;
        } else if (eleccion == 5) {
            cout << "Ingrese el numero que quiere agregar: ";
            cin >> x;
            cout << "Ingrese la posicion en que desea establecer el numero: ";
            cin >> i;
            vect_1.set(x, i);
        } else if (eleccion == 6) {
            seguir = false;
        }
    }
    
    cout << "Has salido del programa.";
    
    return 0;
}
