#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int idata){

    Node* node = new Node();
    node->data = idata;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool isleaf(Node*){
    if(node->left= NULL || node->right=NULL){
        return true;

    }else{
        return false;

    }
}

int main(){

    Node *root = newNode(1);
    root->left = newNode(8);
    root->right = newNode(7);
    root->left->left = newNode(6);

    cout<<root->left->left->data;
    return 0;
}
