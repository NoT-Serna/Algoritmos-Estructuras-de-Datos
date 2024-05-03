#include<iostream>

using namespace std;

class Node{
  int data;
  Node* izq;
  Node* der;
  
public:

  Node(){
      data=0;
      izq = NULL;
      der =  NULL;
  }

  Node(int d){
      data=d;
      izq = NULL;
      der =  NULL;
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
      izq =  iz;
  }
  
  void setDer(Node* de){
      der =  de;
  }
  
  bool hasIzq(){
      return izq!=NULL;
  }
  
  bool hasDer(){
      return der!=NULL;
  }
  
  bool isHoja(){
      if(izq == NULL && der == NULL)
        return true;
        
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
                    t =  t->getDer();
                }else{
                    t->setDer(n);
                    found=true;
                }   
              }else{
                if(t->hasIzq()){
                    t =  t->getIzq();
                }else{
                    t->setIzq(n);
                    found=true;
                } 
              }
          }
      }
  }

  void preorder(){
      preorder(root);
  }

  void preorder(Node* r){
      if(r != NULL){
          cout<<r->getData()<<"\t";
          preorder(r->getIzq());
          preorder(r->getDer());
      }
  }

  void inorder() { 
      inorder(root); 
      
  }

  void inorder(Node* n) {
    if (n == NULL) return;
    inorder(n->getIzq());
    cout << n->getData() << "\t";
    inorder(n->getDer());
  }
  
  void postorder(){
      postorder(root);
  }
  
  void postorder(Node* p){
      if(p != NULL){
          postorder(p->getIzq());
          postorder(p->getDer());
          cout<<p->getData()<<"\t";
      }
  }
    
  void addr(int d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d < pt->getData()){
                pt->setIzq(n);
            }else{
                pt->setDer(n);
            }
        }else{
            if(d < t->getData()){
                addr(d, t->getIzq(), t);
            }else{
                addr(d, t->getDer(), t);
            }
        }
    }
    
    int altura(Node* t){
        if(t->getIzq() == NULL && t->getDer() == NULL){
            return 0;
        }else{
            if(t->getIzq() != NULL && t->getDer() == NULL){
                return 1 + altura(t->getIzq());
            }else{
                if(t->getIzq() == NULL && t->getDer() != NULL){
                    return 1 + altura(t->getDer());
                }else{
                    if(t->getIzq() != NULL && t->getDer() != NULL){
                        return 1 + altura(t->getIzq()) + altura(t->getDer());
                    }
                }
            }
        }
    }


    
    
};

int main()
{
    
    Tree t;
    t.addr(18);
    t.addr(12);
    t.addr(15);
    t.addr(24);
    t.addr(21);
    t.addr(41);
    
    t.postorder();

    
    return 0;
}
