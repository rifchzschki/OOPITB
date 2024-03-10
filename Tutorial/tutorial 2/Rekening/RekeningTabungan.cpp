#include "RekeningTabungan.h"
#include <iostream>

using namespace std;

RekeningTabungan :: RekeningTabungan(double initSaldo, double initTransaksi):Rekening(initSaldo){
    if(initTransaksi>=0){
        biayaTransaksi = initTransaksi;
    }else{
        biayaTransaksi = 0;
    }
}

void RekeningTabungan :: setBiayaTransaksi(double Transaksi){
    biayaTransaksi = Transaksi;
}

double RekeningTabungan :: getBiayaTransaksi() const{
    return biayaTransaksi;
}

void RekeningTabungan :: simpanUang(double nominal){
    Rekening :: simpanUang(nominal);
    Rekening :: setSaldo(Rekening::getSaldo() - biayaTransaksi);
}

bool RekeningTabungan :: tarikUang(double nominal){
    // if(Rekening :: getSaldo()-(biayaTransaksi+nominal) >=0){
    //     if(Rekening :: tarikUang(nominal)){
    //         Rekening :: setSaldo(Rekening :: getSaldo()-biayaTransaksi);
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }else{
    //     return false;
    // }

    if(Rekening :: tarikUang(nominal)){
        Rekening :: setSaldo(Rekening :: getSaldo() - biayaTransaksi);
        return true;
    }else{
        return false;
    }

}