#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
    T data;
    Node* izq;
    Node* der;

public:
    Node() : izq(nullptr), der(nullptr) {}

    Node(T d) : data(d), izq(nullptr), der(nullptr) {}

    T getData() {
        return data;
    }

    Node* getIzq() {
        return izq;
    }

    Node* getDer() {
        return der;
    }

    void setIzq(Node* iz) {
        izq = iz;
    }

    void setDer(Node* de) {
        der = de;
    }

    bool hasIzq() {
        return izq != nullptr;
    }

    bool hasDer() {
        return der != nullptr;
    }

    bool isHoja() {
        return (izq == nullptr && der == nullptr);
    }
};

template <typename T>
class Tree {
    Node<T>* root;

public:
    Tree() : root(nullptr) {}

    void add(T d) {
        Node<T>* n = new Node<T>(d);
        if (root == nullptr) {
            root = n;
        } else {
            Node<T>* t = root;
            bool found = false;
            while (!found) {
                if (d < t->getData()) {
                    if (t->hasIzq()) {
                        t = t->getIzq();
                    } else {
                        t->setIzq(n);
                        found = true;
                    }
                } else {
                    if (t->hasDer()) {
                        t = t->getDer();
                    } else {
                        t->setDer(n);
                        found = true;
                    }
                }
            }
        }
    }

    void preorder() {
        preorder(root);
    }

    void preorder(Node<T>* r) {
        if (r != nullptr) {
            cout << r->getData() << "\t";
            preorder(r->getIzq());
            preorder(r->getDer());
        }
    }

    void inorder() {
        inorder(root);
    }

    void inorder(Node<T>* n) {
        if (n == nullptr) return;
        inorder(n->getIzq());
        cout << n->getData() << "\t";
        inorder(n->getDer());
    }

    void postorder() {
        postorder(root);
    }

    void postorder(Node<T>* p) {
        if (p != nullptr) {
            postorder(p->getIzq());
            postorder(p->getDer());
            cout << p->getData() << "\t";
        }
    }

    void addr(T d) {
        if (root != nullptr)
            addr(d, root, root);
        else
            root = new Node<T>(d);
    }

    void addr(T d, Node<T>* t, Node<T>* pt) {
        if (t == nullptr) {
            Node<T>* n = new Node<T>(d);
            if (d < pt->getData()) {
                pt->setIzq(n);
            } else {
                pt->setDer(n);
            }
        } else {
            if (d < t->getData()) {
                addr(d, t->getIzq(), t);
            } else {
                addr(d, t->getDer(), t);
            }
        }
    }

    int altura(Node<T>* t) {
        if (t->getIzq() == nullptr && t->getDer() == nullptr) {
            return 0;
        } else {
            if (t->getIzq() != nullptr && t->getDer() == nullptr) {
                return 1 + altura(t->getIzq());
            } else {
                if (t->getIzq() == nullptr && t->getDer() != nullptr) {
                    return 1 + altura(t->getDer());
                } else {
                    if (t->getIzq() != nullptr && t->getDer() != nullptr) {
                        return 1 + altura(t->getIzq()) + altura(t->getDer());
                    }
                }
            }
        }
    }
};

int main() {
    Tree<int> t;
    t.addr(18);
    t.addr(12);
    t.addr(15);
    t.addr(24);
    t.addr(21);
    t.addr(41);

    t.postorder();

    return 0;
}
