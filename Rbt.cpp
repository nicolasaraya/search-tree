#include "Rbt.h"
#include <iostream>
#include <vector>
#define REDCOLOR  "\x1B[31m"
#define RESET "\x1B[0m"

using namespace std; 

RedBlackTree::RedBlackTree(){
    root = NULL;
}

RedBlackTree::~RedBlackTree(){
    deleteBST(root);
}  

void RedBlackTree::deleteBST(Node* r){
    if(r == NULL) return;
    Node* a = r->getChildLeft();
    Node* b = r->getChildRight();
    delete r;
    deleteBST(a);
    deleteBST(b);
}



void RedBlackTree::insert(int key){
    //cout << key << endl;
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
        fix(aux);
    }    
}

void RedBlackTree::fix(Node* n){
    if(n == root) return; 
    else{
        while (n != NULL && (n != root) && n->getColor() == RED && n->getParent()->getColor()==RED){
            Node* parent = n->getParent(); 
            Node* gParent = parent->getParent(); 
            if(gParent == NULL) break;
            if(gParent->getChildLeft() != NULL && parent == gParent->getChildLeft()){ //padre es el izq del abuelo
                Node* uncle = gParent->getChildRight();
                if(uncle != NULL && uncle->getColor() == RED){
                    //no rotar, actualizar colores.
                    gParent->setColor(RED);
                    parent->setColor(BLACK);
                    uncle->setColor(BLACK);
                    n = gParent;
                }
                else{ //n es el hijo derecho del padre
                    if(n == parent->getChildRight()){
                        rotateLeft(parent);
                        n = parent;
                        parent = parent->getParent();
                    }
                    rotateRight(gParent);
                    //swap color
                    bool aux = parent->getColor();
                    parent->setColor(gParent->getColor());
                    gParent->setColor(aux);
                    n = parent;
                }
            }

            else{ //parent es el hijo derecho de gParent
                Node* uncle = gParent->getChildLeft();

                if(uncle != NULL && uncle->getColor() == RED){ //tio tb es rojo
                    gParent->setColor(RED);
                    parent->setColor(BLACK);
                    uncle->setColor(BLACK);
                    n = gParent;
                }
                else{ //n es el hijo derecho de parent y se rota a la derecha 
                    if(n == parent->getChildLeft()){
                        rotateRight(parent);
                        n = parent;
                        parent = parent->getParent();
                    }
                    
                    rotateLeft(gParent);
                    bool aux = parent->getColor();
                    parent->setColor(gParent->getColor());
                    gParent->setColor(aux);
                }

            }
        }
    }
    root->setColor(BLACK);
}


void RedBlackTree::printRBT(){
    vector<Node*> actual;
    if(root != NULL) actual.push_back(root);
    while(actual.size() != 0){
        vector<Node*> next;
        for(int i = 0;i < actual.size(); i++){
            if(actual.at(i)->getColor() == RED) printf(REDCOLOR "|%d|" RESET, actual.at(i)->getKey());
            else cout << "|"<< actual.at(i)->getKey() <<"|";
            if(actual.at(i)->getChildLeft()!= NULL) next.push_back(actual.at(i)->getChildLeft());
            if(actual.at(i)->getChildRight()!= NULL) next.push_back(actual.at(i)->getChildRight());
        }
        cout << endl;
        actual = next;
    }
}


void RedBlackTree::rotateLeft(Node* n){
    Node* rChild = n->getChildRight();
    if(rChild != NULL) n->setChildRight(rChild->getChildLeft());

    if(n->getChildRight() != NULL) n->getChildRight()->setParent(n);

    rChild->setParent(n->getParent());

    if(n->getParent() == NULL){
        root = rChild;
    }
    
    else if( n == n->getParent()->getChildLeft()){
        n->getParent()->setChildLeft(rChild);
    }

    else{
        n->getParent()->setChildRight(rChild);
    }

    rChild->setChildLeft(n);
    n->setParent(rChild);


}
void RedBlackTree::rotateRight(Node* n){
    Node* lChild = n->getChildLeft();
    n->setChildLeft(lChild->getChildRight());

    if(n->getChildLeft() != NULL) n->getChildLeft()->setParent(n);

    lChild->setParent(n->getParent());

    if(n->getParent() == NULL){
        root = lChild;
    }
    
    else if(n == n->getParent()->getChildLeft()){
        n->getParent()->setChildLeft(lChild);
    }

    else{
        n->getParent()->setChildRight(lChild);
    }

    lChild->setChildRight(n);
    n->setParent(lChild);
    
}



Node* RedBlackTree::search(int key){
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




