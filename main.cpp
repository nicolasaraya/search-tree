#include <iostream>
#include "Avl.h"
#include "Rbt.h"
#include "Ubt.h"
#include <chrono>
#include <math.h>
#include <iomanip>


using namespace std;

int main(int argc, char const *argv[]){
    std::chrono::time_point<std::chrono::high_resolution_clock> _init, _end; 
    std::chrono::duration<double> delta; 

    uint64_t n_elementos = pow(2,20);
    

    cout << "2^" << log2(n_elementos) << endl; 
    cout << "******RBT*****" << endl;
    RedBlackTree* rbt = new RedBlackTree();
    _init = std::chrono::high_resolution_clock::now();
    for(size_t i = 1; i <= n_elementos; i++){
        rbt->insert(i);
    }
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
     cout << std::fixed << std::setprecision(9) << "Insert:"<< delta.count()/n_elementos << endl;


    _init = std::chrono::high_resolution_clock::now();
    for(size_t i = 1; i <= n_elementos; i++){
        rbt->search(0);
    }
    _end = std::chrono::high_resolution_clock::now();    
    delta = _end - _init;
    cout << std::fixed << std::setprecision(9) <<"search 0: " << delta.count() << endl;


    _init = std::chrono::high_resolution_clock::now();
    rbt->search(n_elementos + 2);
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
    cout << std::fixed << std::setprecision(9) <<"search end: " << delta.count() << endl;

    delete(rbt);
    ///////////////////////////
    cout << "******AVL*****" << endl;
    AVL* a = new AVL();
    _init = std::chrono::high_resolution_clock::now();
    for(size_t i = 1; i <= n_elementos; i++){
        a->insert(i);
    }
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
     cout << std::fixed << std::setprecision(9) << "Insert:"<< delta.count()/n_elementos << endl;
    
    _init = std::chrono::high_resolution_clock::now();
    a->search(0);
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
    cout << std::fixed << std::setprecision(9) <<"search 0: " << delta.count() << endl;


    _init = std::chrono::high_resolution_clock::now();
    a->search(n_elementos + 2);
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
    cout << std::fixed << std::setprecision(9) <<"search end: " << delta.count() << endl;

    delete(a);
    /////////////////////
    cout << "******UBT*****" << endl;
    UnbalancedTree* b = new UnbalancedTree();
    _init = std::chrono::high_resolution_clock::now();
    for(size_t i = 1; i <= n_elementos; i++){
        b->insert(i);
    }
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
    cout << std::fixed << std::setprecision(9) << "Insert:"<< delta.count()/n_elementos << endl;
    
    _init = std::chrono::high_resolution_clock::now();
    b->search(0);
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
    cout << std::fixed << std::setprecision(9) <<"search 0: " << delta.count() << endl;
    

    _init = std::chrono::high_resolution_clock::now();
    b->search(n_elementos + 2);
    _end = std::chrono::high_resolution_clock::now();
    delta = _end - _init;
    cout << std::fixed << std::setprecision(9) <<"search end: " << delta.count() << endl;




    return 0;
}
