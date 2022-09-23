#include "Avl.h"
#include <iostream>

using namespace std; 

AVL::AVL(){
    root = NULL;
}

AVL::~AVL(){
    deleteAVL(root);
}

void AVL::deleteAVL(Node* r){
    if(r == NULL) return;
    Node* a = r->getChildLeft();
    Node* b = r->getChildRight();
    delete r;
    deleteAVL(a);
    deleteAVL(b);
}


void AVL::insert(int key){
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
    height(tempParent);
    balance(tempParent);
    /*
    if(tempParent->getChildRight() == NULL || tempParent->getChildLeft() == NULL){ //cuando se agrego un hijo por 1era vez
        do{
            int left = 0;
            int right = 0;
            if(tempParent->getChildRight() != NULL) right = tempParent->getChildRight()->getHeight();
            if(tempParent->getChildLeft() != NULL) left = tempParent->getChildLeft()->getHeight();
            cout << balanceFactor(tempParent) << "<-" << endl;
            tempParent->setHeight( max(left,right) + 1); 
            tempParent = tempParent->getParent();
        }while(tempParent != NULL);
    }*/
    
    
}

void AVL::height(Node *tempParent){
    while(tempParent != NULL){
        int left = 0;
        int right = 0;
        if(tempParent->getChildRight() != NULL) right = tempParent->getChildRight()->getHeight();
        if(tempParent->getChildLeft() != NULL) left = tempParent->getChildLeft()->getHeight();
        tempParent->setHeight( max(left,right) + 1); 
        tempParent = tempParent->getParent();
    }
}


void AVL::height2(Node *parent){
    Node * leftChild = parent->getChildLeft();
    Node * rightChild = parent->getChildRight();
    int left = 0;
    int right = 0;
    if(leftChild->getChildRight() != NULL) right = leftChild->getChildRight()->getHeight();
    if(leftChild->getChildLeft() != NULL) left = leftChild->getChildLeft()->getHeight();
    leftChild->setHeight( max(left,right) + 1);

    left = 0;
    right = 0;
    if(rightChild->getChildRight() != NULL) right = rightChild->getChildRight()->getHeight();
    if(rightChild->getChildLeft() != NULL) left = rightChild->getChildLeft()->getHeight();
    rightChild->setHeight( max(left,right) + 1);
    height(parent);
}

void AVL::balance(Node* n){
    int _balance;
    int _balanceP;
    Node* child = n;
    while (child != root && child != NULL){
        _balance = balanceFactor(child);
        int _balanceP = balanceFactor(child->getParent());
        if(_balance == -1){ 
            if(_balanceP == -2){ //right right
                //cout << "RR" << endl;
                if(child->getParent() == root) root = child;
                RRRotate(child->getParent(), child);
            }
            else if(_balanceP == 2) { //left right
                //cout << "LR" << endl;
                if(child->getParent() == root) root = child->getChildRight();
                LRRotate(child->getParent(), child);  
            }
        }
        else if(_balance == 1){
            if(_balanceP == -2){//right left
                //cout << "RL" << endl;
                if(child->getParent() == root) root = child->getChildLeft();
                RLRotate(child->getParent(), child);
            }
            else if(_balanceP == 2){//left left
                //cout << "LL" << endl;
                if(child->getParent() == root) root = child;
                LLRotate(child->getParent(), child);
            }
        }
        child = child->getParent();
    }
}


void AVL::RRRotate(Node* parent, Node* child){
    Node* B = child->getChildLeft(); 
    parent->setChildRight(B);
    child->setParent(parent->getParent());
    child->setChildLeft(parent);
    parent->setParent(child);
    if(B != NULL) B->setParent(parent);
    if(child->getParent() != NULL){
        if(child->getParent()->getChildLeft() == parent) child->getParent()->setChildLeft(child);
        else child->getParent()->setChildRight(child);
    }
    height2(child);
}
void AVL::LRRotate(Node* parent, Node* child){
    Node* B = child->getChildRight()->getChildLeft();
    Node* C = child->getChildRight()->getChildRight();
    Node* aux = child->getChildRight();
    //child = 10;
    //parent = 30;    
    aux->setParent(parent->getParent());
    if(aux->getParent() != NULL){
        if(aux->getParent()->getChildLeft() == parent) aux->getParent()->setChildLeft(aux);
        else aux->getParent()->setChildRight(aux);
    }

    aux->setChildRight(parent); 
    parent->setParent(aux);

    parent->setChildLeft(C);
    if(C != NULL) C->setParent(parent);

    aux->setChildLeft(child);
    child->setParent(aux);

    child->setChildRight(B);
    if(B != NULL) B->setParent(child);
    height2(aux);
    
}
void AVL::LLRotate(Node* parent, Node* child){
    Node* C = child->getChildRight(); 
    parent->setChildLeft(C);
    child->setParent(parent->getParent());
    child->setChildRight(parent);
    parent->setParent(child);
    if(C!= NULL)C->setParent(parent);
    if(child->getParent() != NULL){
        if(child->getParent()->getChildLeft() == parent) child->getParent()->setChildLeft(child);
        else child->getParent()->setChildRight(child);
    }
    height2(child);
}
void AVL::RLRotate(Node* parent, Node* child){
    Node* B = child->getChildLeft()->getChildLeft();
    Node* C = child->getChildLeft()->getChildRight();
    Node* aux = child->getChildLeft();
    //child = 30;
    //parent = 10;    
    aux->setParent(parent->getParent());
    if(aux->getParent() != NULL){
        if(aux->getParent()->getChildLeft() == parent) aux->getParent()->setChildLeft(aux);
        else aux->getParent()->setChildRight(aux);
    }

    aux->setChildLeft(parent); 
    parent->setParent(aux);

    parent->setChildRight(B);
    if(B != NULL) B->setParent(parent);

    aux->setChildRight(child);
    child->setParent(aux);

    child->setChildLeft(C);
    if(C != NULL) C->setParent(child);
    height2(aux);
}



void AVL::remove(Node* n){

}

Node* AVL::search(int key){
    if(root->getKey() == key){
        return root; 
    }
    Node* aux = root; 
    while(aux->getKey() != key && aux !=NULL){
        if(key < aux->getKey()){
            aux = aux->getChildLeft();
        }
        else if(key > aux->getKey()){
            aux = aux->getChildRight();
        }
    }
    return aux; 
}

int AVL::balanceFactor(Node* n){
    if(n == NULL) return INT_MIN; 
    int left = 0;
    int right = 0;
    if(n->getChildRight() != NULL) right = n->getChildRight()->getHeight();
    if(n->getChildLeft() != NULL) left = n->getChildLeft()->getHeight();    
    return(left - right);
}

void AVL::printAVL(){    
    vector<Node*> actual;
    if(root != NULL) actual.push_back(root);
    while(actual.size() != 0){
        vector<Node*> next;
        for(int i = 0;i < actual.size(); i++){
            cout << "|"<< actual.at(i)->getKey() <<"|";
            if(actual.at(i)->getChildLeft()!= NULL) next.push_back(actual.at(i)->getChildLeft());
            if(actual.at(i)->getChildRight()!= NULL) next.push_back(actual.at(i)->getChildRight());
        }
        cout << endl;
        actual = next;
    }
}

