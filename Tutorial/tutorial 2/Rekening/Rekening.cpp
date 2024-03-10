#include "Rekening.h"
#include <iostream>

using namespace std;

Rekening :: Rekening(double saldoMasuk){
    if (saldoMasuk >= 0){
        saldo = saldoMasuk;
    }else{
        saldo = 0;
    }
}

void Rekening :: setSaldo(double saldoBaru){
    saldo = saldoBaru;
}

double Rekening :: getSaldo() const{
    return saldo;
}

void Rekening :: simpanUang(double uang){
    saldo += uang;
}

bool Rekening :: tarikUang(double nominal){
    if(nominal <= getSaldo()){
        saldo -= nominal;
        return true;
    }else{
        return false;
    }
}
