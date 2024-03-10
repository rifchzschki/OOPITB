#include "RekeningGiro.h"
#include <iostream>

using namespace std;

RekeningGiro :: RekeningGiro(double initSaldo, double initBunga): Rekening(initSaldo){
    if(initBunga >=0){
        sukuBunga = initBunga;
    }else{
        sukuBunga = 0;
    }
}

void RekeningGiro :: setSukuBunga(double bunga){
    sukuBunga = bunga;
}

double RekeningGiro :: getSukuBunga() const{
    return sukuBunga;
}

double RekeningGiro :: hitungBunga(){
    return Rekening :: getSaldo() * sukuBunga;
}

