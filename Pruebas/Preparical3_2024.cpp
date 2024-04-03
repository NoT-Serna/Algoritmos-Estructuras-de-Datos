#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <string>
using namespace std;

// ESTRUCTURA PARTICIPANTE
// Defina aquí la estructura Participante con dos miembros: nombre (string) y puntaje (int)
// Añada un constructor que inicialice un participante con su nombre y puntaje
struct Participante {
    int puntaje;
    string nombre;

    Participante(int _puntaje, string _nombre) : puntaje(_puntaje), nombre(_nombre) {}

    bool operator>(const Participante& other) const {
        return puntaje > other.puntaje;
    }
};

// COMPARAR PUNTAJES
// Defina una función para comparar dos participantes por su puntaje
// Esta función se utilizará para construir el Max-Heap
void max_heap(vector<Participante>& v, int n, int i) {
    int temp;
    int largest = i;
    int der = 2 * (i + 1);
    int izq = 2 * (i + 1) - 1;

    if (izq < n && v[izq].puntaje < v[largest].puntaje) {
        largest = izq;
    }

    if (der < n && v[der].puntaje < v[largest].puntaje) {
        largest = der;
    }

    if (largest != i) {
        temp = v[largest].puntaje;
        v[largest].puntaje = v[i].puntaje;
        v[i].puntaje = temp;
        max_heap(v, n, largest);
    }
}

void heap_sort(vector<Participante>& v, int n) {
    int center = (n / 2) - 1;
    int temp;

    for (int i = center; i >= 0; i--) {
        max_heap(v, n, i);
    }

    for (int i = 1; i < n; i++) {
        temp = v[0].puntaje;
        v[0].puntaje = v[n - i].puntaje;
        v[n - i].puntaje = temp;
        max_heap(v, n - i, 0);
    }
}

// Función para imprimir un arreglo de participantes
void imprimirParticipantes(vector<Participante>& arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i].nombre << " (" << arr[i].puntaje << " puntos)" << endl;
}

int main() {
    // Inicializar el generador de números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    vector<Participante> participantes;
    vector<string> nombres = {"Alice", "Bob", "Carol", "Dave", "Eve"};

    // Crear participantes con nombres fijos y puntajes aleatorios
    for (const auto& nombre : nombres) {
        int puntajeAleatorio = rand() % 101; // Genera un puntaje aleatorio entre 0 y 100
        participantes.emplace_back(puntajeAleatorio, nombre);
    }

    // Llamar a la función heap_sort con el vector de participantes como argumento
    heap_sort(participantes, participantes.size());

    cout << "Participantes ordenados por puntaje (de mayor a menor):" << endl;
    imprimirParticipantes(participantes, participantes.size());

    return 0;
}
