#include <iostream>
#include <chrono>
#include "Avl.h"
#include "Rbt.h"
#include "Ubt.h"


using namespace std;

size_t n_elementos = (size_t)1<<20;

int main(int argc, char const *argv[]){

    srand(time(NULL));

    UnbalancedTree* ubt = new UnbalancedTree();
    AVL* avl = new AVL();
    RedBlackTree* rbt = new RedBlackTree();

    auto start = std::chrono::system_clock::now();
    for(size_t i = 0; i < n_elementos; i++) ubt->insert(i);
    auto end = std::chrono::system_clock::now();
    cout << "ubt Insert:"<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()/(double)(n_elementos) << endl;

    start = std::chrono::system_clock::now();
    for(size_t i = 0; i < n_elementos; i++) avl->insert(i);
    end = std::chrono::system_clock::now();
    cout << "avl Insert:"<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()/(double)(n_elementos) << endl;

    start = std::chrono::system_clock::now();
    for(size_t i = 0; i < n_elementos; i++) rbt->insert(i);
    end = std::chrono::system_clock::now();
    cout << "rbt Insert:"<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()/(double)(n_elementos) << endl;

    return 0;
}
