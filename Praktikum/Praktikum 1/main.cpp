#include <iostream>
#include "Paper.hpp"

using namespace std;

int main(){
    Paper *a; 
    a = new Paper('A');
    Paper b('B');
    Paper c('C');
    Paper x(c);
    

    a->fold();
    b.fold();
    c.fold();
    c.glue();
    delete a;
    c.setName('X');
    x.fold();
    x.glue();
    return 0;
}