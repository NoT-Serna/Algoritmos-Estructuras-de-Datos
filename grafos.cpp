#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int dato;
    Node* next
};

struct Edge{
    int ini, dest;
};

class Grafo{
    
    Node* add_node(int dest, Node* head){
        Node* newNode = new Node;
        newNode -> dato = dest;
        
        newNode-> next = head;
        
        return newNode;
    }
    
    int total_nodes;

public:
    Node **head;
    
    Grafo(Edge edges[]. int n, int total_nodes){
        
        head = new Node*[total_nodes]();
        this->total_nodes = total_nodes;
        
        for (int i = 0; i<total_nodes; i++){
            head[i] = nullptr;
        }
        
        for(unsigned i = 0; i<n; i++){
            int ini = edges[i].ini;
            int dest = edges[i].dest;
        }
    }
    
    
    
};
