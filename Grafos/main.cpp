#include <iostream>
#include <fstream>
#include <sstream>
#include <set> // For std::set
#include <vector> // For std::vector

// Definición de los tipos de nodos y arcos
struct Node {
    std::string name;
    std::set<std::pair<Node*, int>> neighbors; // Modificar para almacenar pares de nodos y pesos
};

// Definición del grafo
class SimpleGraph {
private:
    std::set<Node *> nodes;

public:
    // Destructor para liberar la memoria
    ~SimpleGraph() {
        for (Node *node : nodes) {
            delete node;
        }
    }

    // Métodos para añadir nodos y arcos
   Node *addNode(const std::string &name) {
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
        start->neighbors.insert({finish, weight});
        // No es necesario agregar el arco en la dirección opuesta para grafos dirigidos
    }

    // Método para obtener los nodos del grafo
    const std::set<Node *> &getNodes() const {
        return nodes;
    }
};

// Función para leer el grafo desde un archivo de entrada
void readGraph(SimpleGraph &g, std::istream &infile) {
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string node1, arrow, node2;
        int weight = 0; // Inicializar el peso con un valor predeterminado
        if (iss >> node1) {
            if (iss >> arrow >> node2 >> weight) {
                Node *n1 = g.addNode(node1);
                Node *n2 = g.addNode(node2);
                if (arrow == "-") {
                    g.addArc(n1, n2, weight);
                    g.addArc(n2, n1, weight);
                } else if (arrow == "->") {
                    g.addArc(n1, n2, weight);
                } else {
                    std::cerr << "Formato de flecha no válido: " << arrow << std::endl;
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
    std::ifstream infile("client.txt");
    if (!infile) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // Leer el grafo desde el archivo
    readGraph(g, infile);

    // Cerrar el archivo
    infile.close();

    // Mostrar los nodos en el grafo
    std::cout << "Nodos en el grafo:" << std::endl;
    for (Node *node : g.getNodes()) {
        std::cout << node->name << std::endl;
    }

    // Mostrar los vecinos de cada nodo y el peso de las aristas
    std::cout << "Vecinos de los nodos y peso de las aristas:" << std::endl;
    for (Node *node : g.getNodes()) {
        std::cout << "Vecinos de " << node->name << ": ";
        for (const auto &neighbor : node->neighbors) {
            std::cout << neighbor.first->name << " (peso: " << neighbor.second << "), ";
        }
        std::cout << std::endl;
    }

    return 0;
}



















