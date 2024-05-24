#include <iostream>
#include <fstream>
#include <sstream>
#include <set> 
#include <vector>
#include <string>
using namespace std;

// Definición de los tipos de nodos y arcos
struct Node {
    string name;
    set<pair<Node*, int>> vecinos; // Modificar para almacenar pares de nodos y pesos
};

// Definición del grafo
class SimpleGraph {
private:
    set<Node *> nodes;

public:
    // Destructor para liberar la memoria
    ~SimpleGraph() {
        for (Node *node : nodes) {
            delete node;
        }
    }

    // Métodos para añadir nodos y arcos
    Node *addNode(const string &name) {
        // Check if the node already exists
        for (Node *node : nodes) {
            if (node->name == name) {
                return node; // Node already exists, return it
            }
        }
        // If the node doesn't exist, create and add it
        Node *node = new Node();
        node->name = name;
        nodes.insert(node);
        return node;
    }

    void addArc(Node *start, Node *finish, int weight) {
        start->vecinos.insert({finish, weight});
        // No es necesario agregar el arco en la dirección opuesta para grafos dirigidos
    }

    // Método para obtener los nodos del grafo
    const std::set<Node *> &getNodes() const {
        return nodes;
    }
};

// Función para leer el grafo desde un archivo de entrada
void readGraph(SimpleGraph &g, istream &infile) {
    std::string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string node1, flecha, node2; // Changed from arrow to flecha
        int weight = 0; // Inicializar el peso con un valor predeterminado
        if (iss >> node1) {
            if (iss >> flecha >> node2 >> weight) { // Changed from arrow to flecha
                Node *n1 = g.addNode(node1);
                Node *n2 = g.addNode(node2);
                if (flecha == "-") { // Changed from arrow to flecha
                    g.addArc(n1, n2, weight);
                    g.addArc(n2, n1, weight);
                } else if (flecha == "->") { // Changed from arrow to flecha
                    g.addArc(n1, n2, weight);
                } else {
                    cerr << "Formato de flecha no válido: " << flecha << std::endl;
                }
            } else {
                g.addNode(node1);
            }
        }
    }
}

int main() {
    // Crear el grafo
    SimpleGraph g;

    // Abrir el archivo de entrada
    ifstream infile("client.txt");
    if (!infile) {
        cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // Leer el grafo desde el archivo
    readGraph(g, infile);

    // Cerrar el archivo
    infile.close();

    // Mostrar los nodos en el grafo
    cout << "Nodos en el grafo:" << std::endl;
    for (Node *node : g.getNodes()) {
        cout << node->name << std::endl;
    }

    // Mostrar los vecinos de cada nodo y el peso de las aristas
    cout << "Vecinos de los nodos y peso de las aristas:" << std::endl;
    for (Node *node : g.getNodes()) {
        cout << "Vecinos de " << node->name << ": ";
        for (const auto &neighbor : node->vecinos) {
            cout << neighbor.first->name << " (peso: " << neighbor.second << "), ";
        }
        cout << std::endl;
    }

    return 0;
}



















