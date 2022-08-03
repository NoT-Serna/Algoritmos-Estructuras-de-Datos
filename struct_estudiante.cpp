#include <iostream>
#include <string>
using namespace std;



int main() {
    // Write C++ code here
    struct estudiante {
        string nombre;
        int edad;
        int id;
    };
   
   estudiante* lista = new estudiante[2];
   
   for(int i = 0; i < 2; i++) {
       lista[i].nombre = "Juan";
       lista[i].edad = i;
       lista[i].id = i;
       cout << lista[i].nombre << " " << lista[i].edad << endl;
   }
   
    return 0;
}
