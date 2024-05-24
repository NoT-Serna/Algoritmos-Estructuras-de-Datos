/*
 * Archivo: graph.h
 * ----------------
 * Este archivo es la interfaz para un paquete de grafos flexible que exporta
 * una clase parametrizada Graph.
 */

#ifndef _graph_h
#define _graph_h

#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>

/*
 * Clase: Graph<NodeType, ArcType>
 * -------------------------------
 * Esta clase representa un grafo con los tipos de nodos y arcos especificados.
 * Los parámetros NodeType y ArcType indican los tipos de registro u objeto
 * utilizados para los nodos y arcos, respectivamente. Estos tipos pueden contener
 * cualquier campo o método requerido por el cliente, pero deben contener los siguientes
 * campos requeridos por el paquete Graph:
 *
 * La definición de NodeType debe incluir:
 * - Un campo string llamado name
 * - Un campo std::set<ArcType *> llamado arcs
 *
 * La definición de ArcType debe incluir:
 * - Un campo NodeType * llamado start
 * - Un campo NodeType * llamado finish
 */

template <typename NodeType, typename ArcType>
class Graph {
/*
 * Notas sobre la representación
 * -----------------------------
 * La clase Graph está construida como una abstracción en capas sobre las clases Set y Map.
 * La mayor parte de la complejidad aparece en las implementaciones subyacentes.
 */

private:

/* Variables de instancia */
    std::set<NodeType *> nodes;        /* El conjunto de nodos en el grafo */
    std::set<ArcType *> arcs;          /* El conjunto de arcos en el grafo */
    std::map<std::string, NodeType *> nodeMap; /* Un mapa de nombres y nodos */

/* Métodos privados */
    void deepCopy(const Graph & src);
    NodeType *getExistingNode(const std::string &name) const;

public:

    /*
     * Constructor: Graph
     * Uso: Graph<NodeType, ArcType> g;
     * -------------------------------
     * Crea un objeto Graph vacío.
     */
    Graph();

    /*
     * Destructor: ~Graph
     * ------------------
     * Libera el almacenamiento interno asignado para representar el grafo.
     */
    ~Graph();

    /*
     * Método: size
     * Uso: int size = g.size();
     * -------------------------
     * Devuelve el número de nodos en el grafo.
     */
    int size() const;

    /*
     * Método: isEmpty
     * Uso: if (g.isEmpty()) ...
     * -------------------------
     * Devuelve verdadero si el grafo está vacío.
     */
    bool isEmpty() const;

    /*
     * Método: clear
     * Uso: g.clear();
     * -----------------
     * Re-inicializa el grafo a vacío, liberando cualquier almacenamiento dinámico.
     */
    void clear();

    /*
     * Método: addNode
     * Uso: g.addNode(name);
     *       g.addNode(node);
     * -------------------------
     * Añade un nodo al grafo. La primera forma crea el nodo a partir del nombre. 
     * La segunda forma toma un puntero a nodo creado por el cliente.
     * Ambas formas devuelven un puntero al nodo añadido, aunque ese valor 
     * típicamente se ignora.
     */
    NodeType *addNode(const std::string &name);
    NodeType *addNode(NodeType *node);

    /*
     * Método: removeNode
     * Uso: g.removeNode(name);
     *       g.removeNode(node);
     * -------------------------
     * Elimina un nodo del grafo, donde el nodo puede ser especificado
     * ya sea por su nombre o como un valor de puntero. Eliminar un nodo también
     * elimina todos los arcos que contienen ese nodo.
     */
    void removeNode(const std::string &name);
    void removeNode(NodeType *node);

    /*
     * Método: getNode
     * Uso: NodeType *node = g.getNode(name);
     * -------------------------------------
     * Busca un nodo en la tabla de nombres adjunta al grafo y
     * devuelve un puntero a ese nodo. Si no existe un nodo con el
     * nombre especificado, getNode devuelve NULL.
     */
    NodeType *getNode(const std::string &name) const;

    /*
     * Método: addArc
     * Uso: g.addArc(s1, s2);
     *      g.addArc(n1, n2);
     *      g.addArc(arc);
     * -------------------
     * Añade un arco al grafo. Los extremos del arco pueden especificarse
     * como cadenas que indican los nombres de los nodos o como punteros a 
     * las estructuras de los nodos. Todas las versiones devuelven un puntero 
     * al arco añadido, aunque ese valor típicamente se ignora.
     */
    ArcType *addArc(const std::string &s1, const std::string &s2);
    ArcType *addArc(NodeType *n1, NodeType *n2);
    ArcType *addArc(ArcType *arc);

    /*
     * Método: removeArc
     * Uso: g.removeArc(s1, s2);
     *      g.removeArc(n1, n2);
     *      g.removeArc(arc);
     * ----------------------
     * Elimina un arco del grafo, donde el arco puede especificarse de
     * tres maneras: por los nombres de sus extremos, por los punteros de los
     * nodos en sus extremos, o como un puntero de arco. Si más de un arco
     * conecta los extremos especificados, todos ellos son eliminados.
     */
    void removeArc(const std::string &s1, const std::string &s2);
    void removeArc(NodeType *n1, NodeType *n2);
    void removeArc(ArcType *arc);

    /*
     * Notas de implementación: getNodeSet, getArcSet
     * ---------------------------------------------
     * Estos métodos simplemente devuelven el conjunto solicitado por el cliente. Para
     * mayor eficiencia, los conjuntos se devuelven por referencia, porque al hacerlo 
     * se elimina la necesidad de copiar el conjunto.
     */
    std::set<NodeType *> &getNodeSet();
    std::set<ArcType *> &getArcSet();
    std::set<ArcType *> &getArcSet(NodeType *node);
    std::set<ArcType *> &getArcSet(const std::string &name);

    /*
     * Notas de implementación: getNeighbors
     * -------------------------------------
     * Esta implementación vuelve a calcular el conjunto cada vez, lo cual es razonablemente
     * eficiente si el grado del nodo es pequeño.
     */
    std::set<NodeType *> getNeighbors(NodeType *node);
    std::set<NodeType *> getNeighbors(const std::string &name);

    /*
     * Notas de implementación: constructor de copia y operador de asignación
     * ----------------------------------------------------------------------
     * Estos métodos aseguran que copiar un grafo crea una estructura de nodos y arcos
     * completamente nueva y paralela.
     */
    const Graph<NodeType, ArcType> &operator=(const Graph &src);
    Graph(const Graph &src);
};

/*
 * Notas de implementación: Constructor y destructor de Graph
 * ----------------------------------------------------------
 * La única inicialización requerida en este nivel es crear estructuras de datos vacías,
 * lo cual es realizado automáticamente por las clases subyacentes. 
 * El destructor, sin embargo, debe liberar las estructuras de arco y nodo individuales.
 * Llamar a clear es suficiente para realizar esta tarea.
 */
template <typename NodeType, typename ArcType>
Graph<NodeType, ArcType>::Graph() {
    /* Vacío */
}

template <typename NodeType, typename ArcType>
Graph<NodeType, ArcType>::~Graph() {
    clear();
}

/*
 * Notas de implementación: size, isEmpty
 * --------------------------------------
 * Estos métodos están definidos en términos del conjunto de nodos, por lo que la clase Graph 
 * simplemente reenvía las solicitudes a la clase Set.
 */
template <typename NodeType, typename ArcType>
int Graph<NodeType, ArcType>::size() const {
    return nodes.size();
}

template <typename NodeType, typename ArcType>
bool Graph<NodeType, ArcType>::isEmpty() const {
    return nodes.empty();
}

/*
 * Notas de implementación: clear
 * ------------------------------
 * La implementación de clear libera todos los nodos y arcos.
 */
template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::clear() {
    for (NodeType *node : nodes) {
        delete node;
    }
    for (ArcType *arc : arcs) {
        delete arc;
    }
    arcs.clear();
    nodes.clear();
    nodeMap.clear();
}

/*
 * Notas de implementación: addNode
 * --------------------------------
 * El método addNode añade el nodo al conjunto de nodos del grafo y
 * al mapa de nombres a nodos.
 */
template <typename NodeType, typename ArcType>
NodeType *Graph<NodeType, ArcType>::addNode(const std::string &name) {
    if (nodeMap.find(name) != nodeMap.end()) {
        throw std::runtime_error("addNode: Nodo con nombre " + name + " ya existe");
    }
    NodeType *node = new NodeType();
    node->name = name;
    nodes.insert(node);
    nodeMap[name] = node;
    return node;
}

template <typename NodeType, typename ArcType>
NodeType *Graph<NodeType, ArcType>::addNode(NodeType *node) {
    nodes.insert(node);
    nodeMap[node->name] = node;
    return node;
}

/*
 * Notas de implementación: removeNode
 * -----------------------------------
 * El método removeNode elimina el nodo especificado pero también debe 
 * eliminar cualquier arco en el grafo que contenga el nodo. Para evitar
 * cambiar el conjunto de nodos durante la iteración, esta implementación
 * crea un vector de arcos que requieren eliminación.
 */
template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::removeNode(const std::string &name) {
    removeNode(getExistingNode(name));
}

template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::removeNode(NodeType *node) {
    std::vector<ArcType *> toRemove;
    for (ArcType *arc : arcs) {
        if (arc->start == node || arc->finish == node) {
            toRemove.push_back(arc);
        }
    }
    for (ArcType *arc : toRemove) {
        removeArc(arc);
    }
    nodes.erase(node);
    nodeMap.erase(node->name);
    delete node;
}

/*
 * Notas de implementación: getNodeSet, getArcSet
 * ---------------------------------------------
 * Estos métodos simplemente devuelven el conjunto solicitado por el cliente. Para
 * mayor eficiencia, los conjuntos se devuelven por referencia, porque al hacerlo 
 * se elimina la necesidad de copiar el conjunto.
 */
template <typename NodeType, typename ArcType>
std::set<NodeType *> &Graph<NodeType, ArcType>::getNodeSet() {
    return nodes;
}

template <typename NodeType, typename ArcType>
std::set<ArcType *> &Graph<NodeType, ArcType>::getArcSet() {
    return arcs;
}

template <typename NodeType, typename ArcType>
std::set<ArcType *> &Graph<NodeType, ArcType>::getArcSet(NodeType *node) {
    return node->arcs;
}

template <typename NodeType, typename ArcType>
std::set<ArcType *> &Graph<NodeType, ArcType>::getArcSet(const std::string &name) {
    return getArcSet(getExistingNode(name));
}

/*
 * Notas de implementación: getNeighbors
 * -------------------------------------
 * Esta implementación vuelve a calcular el conjunto cada vez, lo cual es razonablemente
 * eficiente si el grado del nodo es pequeño.
 */
template <typename NodeType, typename ArcType>
std::set<NodeType *> Graph<NodeType, ArcType>::getNeighbors(NodeType *node) {
    std::set<NodeType *> neighbors;
    for (ArcType *arc : node->arcs) {
        neighbors.insert(arc->finish);
    }
    return neighbors;
}

template <typename NodeType, typename ArcType>
std::set<NodeType *> Graph<NodeType, ArcType>::getNeighbors(const std::string &name) {
    return getNeighbors(getExistingNode(name));
}

/*
 * Notas de implementación: constructor de copia y operador de asignación
 * ----------------------------------------------------------------------
 * Estos métodos aseguran que copiar un grafo crea una estructura de nodos y arcos
 * completamente nueva y paralela.
 */
template <typename NodeType, typename ArcType>
const Graph<NodeType, ArcType> &Graph<NodeType, ArcType>::operator=(const Graph &src) {
    if (this != &src) {
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename NodeType, typename ArcType>
Graph<NodeType, ArcType>::Graph(const Graph &src) {
    deepCopy(src);
}

/*
 * Método privado: deepCopy
 * ------------------------
 * Este método realoca todos los nodos y arcos para asegurar que las estructuras sean disjuntas.
 */
template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::deepCopy(const Graph &other) {
    for (NodeType *oldNode : other.nodes) {
        NodeType *newNode = new NodeType();
        *newNode = *oldNode;
        newNode->arcs.clear();
        addNode(newNode);
    }
    for (ArcType *oldArc : other.arcs) {
        ArcType *newArc = new ArcType();
        *newArc = *oldArc;
        newArc->start = getExistingNode(oldArc->start->name);
        newArc->finish = getExistingNode(oldArc->finish->name);
        addArc(newArc);
    }
}

template <typename NodeType, typename ArcType>
NodeType *Graph<NodeType, ArcType>::getExistingNode(const std::string &name) const {
    auto it = nodeMap.find(name);
    if (it != nodeMap.end()) {
        return it->second;
    }
    return nullptr;
}

/*
 * Método: addArc
 * Uso: g.addArc(s1, s2);
 *      g.addArc(n1, n2);
 *      g.addArc(arc);
 * -------------------
 * Añade un arco al grafo. Los extremos del arco pueden especificarse
 * como cadenas que indican los nombres de los nodos o como punteros a 
 * las estructuras de los nodos. Todas las versiones devuelven un puntero 
 * al arco añadido, aunque ese valor típicamente se ignora.
 */
template <typename NodeType, typename ArcType>
ArcType *Graph<NodeType, ArcType>::addArc(const std::string &s1, const std::string &s2) {
    NodeType *n1 = getExistingNode(s1);
    NodeType *n2 = getExistingNode(s2);
    if (!n1 || !n2) {
        throw std::runtime_error("addArc: Uno o ambos nodos no existen");
    }
    return addArc(n1, n2);
}

template <typename NodeType, typename ArcType>
ArcType *Graph<NodeType, ArcType>::addArc(NodeType *n1, NodeType *n2) {
    ArcType *arc = new ArcType();
    arc->start = n1;
    arc->finish = n2;
    n1->arcs.insert(arc);
    arcs.insert(arc);
    return arc;
}

template <typename NodeType, typename ArcType>
ArcType *Graph<NodeType, ArcType>::addArc(ArcType *arc) {
    arcs.insert(arc);
    arc->start->arcs.insert(arc);
    return arc;
}

/*
 * Método: removeArc
 * Uso: g.removeArc(s1, s2);
 *      g.removeArc(n1, n2);
 *      g.removeArc(arc);
 * ----------------------
 * Elimina un arco del grafo, donde el arco puede especificarse de
 * tres maneras: por los nombres de sus extremos, por los punteros de los
 * nodos en sus extremos, o como un puntero de arco. Si más de un arco
 * conecta los extremos especificados, todos ellos son eliminados.
 */
template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::removeArc(const std::string &s1, const std::string &s2) {
    NodeType *n1 = getExistingNode(s1);
    NodeType *n2 = getExistingNode(s2);
    if (!n1 || !n2) {
        return;
    }
    removeArc(n1, n2);
}

template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::removeArc(NodeType *n1, NodeType *n2) {
    std::vector<ArcType *> toRemove;
    for (ArcType *arc : n1->arcs) {
        if (arc->finish == n2) {
            toRemove.push_back(arc);
        }
    }
    for (ArcType *arc : toRemove) {
        removeArc(arc);
    }
}

template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::removeArc(ArcType *arc) {
    arc->start->arcs.erase(arc);
    arcs.erase(arc);
    delete arc;
}

#endif