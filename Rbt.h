#ifndef RBT_H
#define RBT_H
#include "Node.h"

class RedBlackTree{
    public:
        RedBlackTree();
        ~RedBlackTree();
        void insert(int);
        Node* search(int);
        void printRBT();
    private:
        Node* root;
        void fix(Node*);
        void rotateLeft(Node*);
        void rotateRight(Node*);
        void deleteBST(Node*);

};

#endif