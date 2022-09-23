#include "Ubt.h"
#include <iostream>
#include <vector>

UnbalancedTree::UnbalancedTree(){
    root = NULL;
}
UnbalancedTree::~UnbalancedTree(){
    deleteBST(root);
}
void UnbalancedTree::deleteBST(Node* r){
    if(r == NULL) return;
    Node* a = r->getChildLeft();
    Node* b = r->getChildRight();
    delete r;
    deleteBST(a);
    deleteBST(b);
}
void UnbalancedTree::insert(int key){
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
}

Node* UnbalancedTree::search(int key){
    Node* aux = root; 
    while(aux->getKey() != key && aux != NULL){
        if(key < aux->getKey()){
            aux = aux->getChildLeft();
        }
        else if(key > aux->getKey()){
            aux = aux->getChildRight();
        }
    }
    return aux; 
}

void UnbalancedTree::printRBT(){
    std::vector<Node*> actual;
    if(root != NULL) actual.push_back(root);
    while(actual.size() != 0){
        std::vector<Node*> next;
        for(int i = 0;i < actual.size(); i++){
            std::cout << "|"<< actual.at(i)->getKey() <<"|";
            if(actual.at(i)->getChildLeft()!= NULL) next.push_back(actual.at(i)->getChildLeft());
            if(actual.at(i)->getChildRight()!= NULL) next.push_back(actual.at(i)->getChildRight());
        }
        std::cout << std::endl;
        actual = next;
    }
}