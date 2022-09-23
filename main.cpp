#include <iostream>
#include "Avl.h"
#include "Rbt.h"

using namespace std;

int main(int argc, char const *argv[]){
   
    /*
    AVL* _avl = new AVL();

    for(int i = 0; i < 30; i++){
        _avl->insert(i);
        //_avl->printAVL();
    }
    _avl->printAVL();
    */


    RedBlackTree* rbt = new RedBlackTree();

    for(int i = 0; i < 30; i++){
        rbt->insert(i);
    }
    rbt->printRBT();
    

    return 0;
}
