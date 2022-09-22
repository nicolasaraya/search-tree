#include <iostream>
#include "Avl.h"

using namespace std;

int main(int argc, char const *argv[]){
    AVL* _avl = new AVL();

    _avl->insert(10);
    _avl->insert(5);
    _avl->insert(15);
    _avl->insert(3);
    _avl->insert(8);
    _avl->insert(12);
    _avl->insert(17);
    _avl->insert(20);
    _avl->insert(25);




    _avl->printAVL();
    return 0;
}
