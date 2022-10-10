#include <iostream>
using namespace std;

class Node{
    int data;
    Node* izq;
    Node* der;

public:

   Node(){
       data=0;
       izq=NULL;
       der=NULL;
   }
   
   Node (int d){
       data=d;
       izq=NULL;
       der=NULL;
   }
   
   int getData(){
       return data;
   }
   
   
   Node* getIzq(){
       return izq;
   }
   
   Node* getDer(){
       return der;
   }
   
   void setIzq(Node* iz){
       izq = iz;
   }
   
   void setDer(Node* de){
       der = de;
   }
   
   
   bool hasIzq(){
       return izq != NULL;
   }
   
   bool hasDer(){
       return der !=NULL;
   }
   
   bool isHoja(){
       if(izq == NULL && der == NULL){
           return true;
        
       }
       return false;
   }
};


class Tree{
    
    Node* root;

public: 
    Tree(){
        root = NULL;
    }
    
    void add(int d){
        Node* n = new Node(d);
        if(root == NULL){
            root = n;
        }else{
            Node* t = root;
            bool found = false;
            while(!found){
                if(t->getData() < n->getData()){
                    if(t->hasDer()){
                        t= t->getDer();
                    }else{
                        t->setDer(n);
                        found = true;
                    }
                }
            }
            }
            
        }
        
    }
    
};

int main() {
  
  
    return 0;
}
