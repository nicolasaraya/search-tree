#ifndef NBT_H
#define NBT_H
#include "Node.h"

class UnbalancedTree{
    public:
        UnbalancedTree();
        ~UnbalancedTree();
        void insert(int);
        Node* search(int);
        void printRBT();
    private:
        Node* root;
        void deleteBST(Node*);
};

#endif