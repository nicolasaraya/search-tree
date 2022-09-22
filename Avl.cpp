#include "Avl.h"
#include <iostream>

using namespace std; 

AVL::AVL(){
    root = NULL;
}
AVL::~AVL(){
}

void AVL::insert(int key){
    cout << key << endl;
    Node* aux = new Node(key);
    Node* tempParent = root;
    if(root == NULL){
        root = aux;
        return;
    }
    else{
        while(1){
            if(key < tempParent->getKey()){
                if(tempParent->getChildLeft() != NULL){
                    tempParent = tempParent->getChildLeft();
                }
                else{
                    tempParent->setChildLeft(aux);
                    aux->setParent(tempParent);
                    break; 
                }
            }
            else if(key > tempParent->getKey()){ 
                if(tempParent->getChildRight() != NULL){
                    tempParent = tempParent->getChildRight();
                }
                else{
                    tempParent->setChildRight(aux);
                    aux->setParent(tempParent);
                    break; 
                }
            }
            else break;
        }

    }

    if(tempParent->getChildRight() == NULL || tempParent->getChildLeft() == NULL){ //cuando se agrego un hijo por 1era vez
        do{
            int left = 0;
            int right = 0;
            if(tempParent->getChildRight() != NULL) right = tempParent->getChildRight()->getHeight();
            if(tempParent->getChildLeft() != NULL) left = tempParent->getChildLeft()->getHeight();
            tempParent->setHeight( max(left,right) + 1); 
            tempParent = tempParent->getParent();
        }while(tempParent != NULL);
    }
    
    if(!isBalanced(aux)) cout << "????????????" << endl;
    
}

//balance(); 


void AVL::remove(Node* n){

}

Node* AVL::search(int key){
    if(root->getKey() == key){
        return root; 
    }
    Node* aux = root; 
    while(aux->getKey() != key){
        if(key < aux->getKey()){
            aux = aux->getChildLeft();
        }
        else if(key > aux->getKey()){
            aux = aux->getChildRight();
        }
    }
    return aux; 
}


bool AVL::isBalanced(Node* n){
    Node * aux = n;
    while(aux != NULL){
        int left = 0;
        int right = 0;
        if(aux->getChildRight() != NULL) right = aux->getChildRight()->getHeight();
        if(aux->getChildLeft() != NULL) left = aux->getChildLeft()->getHeight();
        if(abs(left - right) > 1) {
            cout <<"desbalanceado" <<aux->getParent()->getKey()<<" " << endl;
            return false;
        }
        aux = aux->getParent();
    }
    return true;
}

void AVL::printAVL(){
    printPreOrder(root);
    cout << endl; 
}

void AVL::printPreOrder(Node* r){
    if(r!=NULL){
        cout << "|| " <<r->getKey() << ", " << r->getHeight() <<  "|| - ";
        printPreOrder(r->getChildLeft());
        printPreOrder(r->getChildRight());
    }
}
