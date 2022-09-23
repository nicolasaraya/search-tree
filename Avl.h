#ifndef AVL_H
#define AVL_H
#include <vector>
#include <climits>
#include "Node.h"

using namespace std; 

class AVL{
    private:
        ///     var         ///
        Node* root;
        ///     methods     ///
        void balance(Node*); 
        Node* createNode(int);
        int balanceFactor(Node*);
        void printPreOrder(Node*);
        void LLRotate(Node*, Node*);
        void RLRotate(Node*, Node*);
        void RRRotate(Node*, Node*);
        void LRRotate(Node*, Node*);
        void height(Node*);
        void height2(Node*);
        void deleteAVL(Node*);


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