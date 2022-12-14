#include "Node.h"
#include <iostream>


using namespace std;

//color true = red
//color false = black

Node::Node(int key){
    this->key = key;
    height = 1;
    parent = NULL;
    childLeft = NULL;
    childRight = NULL;
    color = RED;
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

void Node::setColor(bool b){
    color = b;
}

bool Node::getColor(){
    return color;
}

