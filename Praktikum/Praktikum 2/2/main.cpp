#include "Hero.hpp"
#include "Invoker.hpp"
#include "Axe.hpp"
#include <iostream>

using namespace std;

int main (){
    Invoker *I, *A;
    I = new Invoker(10,1000);
    I->useSkill();
    A = new Invoker(*I);
    A->Hero::heal(1);
    Invoker B;
    B.move(10,25);
    B=*A;

    Axe *C;
    C = new Axe(200,10);
    C->move(2,20);
    C->heal(10);
    Axe *D;
    D = new Axe(*C);
    Axe F(D->operator+(*C));
    D->useSkill();
    F.useSkill();
    delete C;
}