#ifndef AVL_H
#define AVL_H
#include <vector>
#include "Node.h"

using namespace std; 

class AVL{
    private:
        ///     var         ///
        Node* root;
        ///     methods     ///
        void balance(); 
        Node* createNode(int);
        bool isBalanced(Node*);
        void printPreOrder(Node*);
        void LLRotate();
        void RLRotate();
        void RRRotate();
        void LRRotate();

    public:
        ///     var         ///
        ///     methods     ///
        AVL();
        ~AVL();
        void insert(int);
        void remove(Node*);
        Node* search(int); 
        void printAVL();
};

#endif