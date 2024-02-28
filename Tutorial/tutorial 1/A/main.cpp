#include "A.hpp"
#include <iostream>
using namespace std;

int main() {
    A *x,*y;
    x = new A('1');
    y = new A('2');
    A z(*x);
    *x=*y;
    y->show();
    delete y;
    delete x;

}