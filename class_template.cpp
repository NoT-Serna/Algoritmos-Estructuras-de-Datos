#include <iostream>
#include <stdlib.h>
using namespace std;

class Persona{
    private: //Atributos
        int edad;
        string nombre;
    public: //Métodos
        Persona(int,string); //Constructor
        void leer();
        void leer_edad();

};

//Constructor, nos sirve para inicializar los atributos
Persona::Persona(int _edad, string _nombre){
    edad = _edad;
    nombre = _nombre;

}

// Métodos
void Persona::leer(){
    cout<<"Metodo leer"<<nombre;
}

void Persona::leer_edad(){
    cout<<"Metodo edad"<<edad;

}


int main(){
    Persona p1 = Persona(20,"Juancho");
    Persona p2 = Persona(19,"Luchito");

    p1.leer();
    p2.leer_edad();


    return 0;
}