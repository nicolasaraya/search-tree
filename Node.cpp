#include "Node.h"
#include <iostream>

using namespace std;


Node::Node(int key){
    this->key = key;
    height = 0;
    parent = NULL;
    childLeft = NULL;
    childRight = NULL;
}

Node::~Node(){
}

Node* Node::getParent(){
    return parent;
}

Node* Node::getChildLeft(){
    return childLeft;
}

Node* Node::getChildRight(){
    return childRight;
}

int Node::getKey(){
    return key;
}

int Node::getHeight(){
    return height;
}

void Node::setHeight(int height){
    this->height = height;
}

void Node::setParent(Node* p){
    parent = p; 
}

void Node::setChildLeft(Node* l){
    childLeft = l;
}

void Node::setChildRight(Node* r){
    childRight = r;
}