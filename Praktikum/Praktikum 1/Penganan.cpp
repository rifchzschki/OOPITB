#include "Penganan.hpp"
#include <iostream>

using namespace std;

int Penganan :: n_rumah = 0;
int Penganan :: uang = 0;

Penganan :: Penganan(): keik(0), panekuk(0){}
Penganan :: Penganan(int keik, int panekuk): keik(keik), panekuk(panekuk){}

int Penganan :: GetKeik() const {
    return keik;
}

int Penganan :: GetPanekuk() const {
    return panekuk;
}

void Penganan :: SetKeik(int numKeik){
    keik = numKeik;
}

void Penganan :: SetPanekuk(int numPanekuk){
    panekuk = numPanekuk;
}

Penganan operator+(const Penganan& A1, const Penganan& A2){
    int totalKeik = A1.GetKeik() + A2.GetKeik();
    int totalPanekuk = A1.GetPanekuk() + A2.GetPanekuk();
    Penganan P(totalKeik, totalPanekuk);
    Penganan :: n_rumah +=1;
    return P;
    
}

Penganan operator- (const Penganan& A1, const Penganan& A2){
    int totalKeikDijual, sisaKeik, sisaPanekuk, totalPanekukDijual;
    if(A1.GetKeik()>A2.GetKeik()){
        sisaKeik = A1.GetKeik() - A2.GetKeik();
        totalKeikDijual = A2.GetKeik();
        
    }else{
        sisaKeik = 0;
        totalKeikDijual = A1.GetKeik();
    }

    if(A1.GetPanekuk()>A2.GetPanekuk()){
        totalPanekukDijual = A2.GetPanekuk();
        sisaPanekuk = A1.GetPanekuk() - A2.GetPanekuk();
    }else{
        sisaPanekuk = 0;
        totalPanekukDijual = A1.GetPanekuk();
    }

    Penganan :: uang += totalKeikDijual*51 + totalPanekukDijual*37;
    Penganan P(sisaKeik, sisaPanekuk);
    return P;
}

Penganan operator^ (const Penganan& A, const int n){
    int mines, stokPanekuk, stokKeik;
    if(A.GetKeik()>=n){
        stokKeik = A.GetKeik() - n;
    }else{
        stokKeik = 0;
        mines = (n - A.GetKeik())*51;
    }

    if(A.GetPanekuk()>=n){
        stokPanekuk = A.GetPanekuk() - n;
    }else{
        stokPanekuk = 0;
        mines = (n - A.GetKeik())*51;
    }
    Penganan :: uang -= mines;
    Penganan P(stokKeik, stokPanekuk);
    return P;
}

Penganan operator^ (const int n, const Penganan& A){
    int mines, stokPanekuk, stokKeik;
    if(A.GetKeik()>=n){
        stokKeik = A.GetKeik() - n;
    }else{
        stokKeik = 0;
        mines = (n - A.GetKeik())*51;
    }

    if(A.GetPanekuk()>=n){
        stokPanekuk = A.GetPanekuk() - n;
    }else{
        stokPanekuk = 0;
        mines = (n - A.GetKeik())*51;
    }
    Penganan :: uang -= mines;
    Penganan P(stokKeik, stokPanekuk);

    return P;

}

int Penganan :: JumlahUang(){
    return uang;
}

int Penganan :: HitungNRumah(){
    return n_rumah;
}

void Penganan :: Print(){
    cout << Penganan :: keik << "keik-" << Penganan::panekuk << "panekuk" << endl;
}