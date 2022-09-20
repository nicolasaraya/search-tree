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
                tempParent->setHeight( tempParent->getHeight() + 1 );
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
                tempParent->setHeight( tempParent->getHeight() + 1 );
                if(tempParent->getChildRight() != NULL){
                    tempParent = tempParent->getChildRight();
                }
                else{
                    tempParent->setChildRight(aux);
                    aux->setParent(tempParent);
                    break; 
                }
            }
        }

        if( isBalanced(tempParent)) {
            cout << "ok"  << endl;
        }
        else{
            cout << "dont ok " << endl;
        }


    }

}

void AVL::remove(Node* n){

}

Node* AVL::search(int key){
    return NULL;

}


bool AVL::isBalanced(Node* n){
    return true;
}

void AVL::printAVL(){
    printPreOrder(root);
}

void AVL::printPreOrder(Node* r){
    if(r!=NULL){
        cout << "|| " <<r->getKey() << ", " << r->getHeight() <<  "|| - ";
        printPreOrder(r->getChildLeft());
        printPreOrder(r->getChildRight());
    }
}