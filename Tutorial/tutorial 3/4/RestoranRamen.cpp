#include "RestoranRamen.hpp"
#include <iostream>

using namespace std;

void RestoranRamen :: tambahOrder(int n, int p){
    daftarMeja[n]+=p;
}

int RestoranRamen :: tutupOrder(int n){
    int total = daftarMeja[n];
    daftarMeja.erase(n);
    return total;
}

int RestoranRamen :: cekTotal(int n){
    return daftarMeja[n];
}

int RestoranRamen :: totalMeja(){
    return daftarMeja.size();
}

void RestoranRamen :: cetakMeja(){
    if(daftarMeja.size() == 0){
        cout << "Restoran kosong" << endl;

    }else{
        for(auto itr=daftarMeja.begin(); itr!=daftarMeja.end();itr++){
            cout << "Meja " << itr->first << " = " << itr->second << endl;
        }
    }
}