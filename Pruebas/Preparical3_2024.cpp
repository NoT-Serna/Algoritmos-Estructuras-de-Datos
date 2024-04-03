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

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;

    Student(string n, double g) : name(n), grade(g) {}

    bool operator<(const Student& other) const {
        return grade < other.grade;
    }
};

int partitionStudents(vector<Student>& students, int ini, int fin) {
    int pivot = students[fin].grade;
    int i = ini - 1;

    for (int j = ini; j < fin; j++) {
        if (students[j].grade <= pivot) {
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[fin]);
    return i + 1;
}


void quicksort(vector<Student>& students, int ini, int fin) {
    if (ini < fin) {
        int i = partitionStudents(students, ini, fin);
        quicksort(students, ini, i - 1);
        quicksort(students, i + 1, fin);
    }
}


void printStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << student.name << " " << student.grade << endl;
    }
    cout << "-----------------------------" << endl;
}

int main() {
    vector<vector<Student>> testCases = {
        {{"Juan", 85.5}, {"Ana", 90.2}, {"Carlos", 85.5}},
        {{"Bob", 75.0}, {"Alice", 85.0}, {"Charlie", 95.0}, {"Diana", 85.0}},
        {{"Eve", 60.5}, {"Frank", 60.5}, {"Grace", 60.5}},
        {{"Heidi", 88.8}, {"Ivan", 88.8}, {"Judy", 99.0}},
        {{"Ken", 100.0}, {"Leo", 58.3}, {"Mia", 58.3}, {"Nina", 100.0}, {"Oscar", 58.3}}
    };

    for (auto& test : testCases) {
        quicksort(test, 0, test.size() - 1);
        printStudents(test);
    }

    return 0;
}

*/
