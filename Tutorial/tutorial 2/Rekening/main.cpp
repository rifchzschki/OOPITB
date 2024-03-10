#include "Rekening.h"
#include "RekeningGiro.h"
#include "RekeningTabungan.h"
#include <iostream>

using namespace std;

int main(){
    // Rekening A(10000);
    // A.simpanUang(5000);
    // // A.setSaldo(0);
    // if(A.tarikUang(10000)){
    //     cout<<"1"<<endl;
    // }
    // cout << A.getSaldo() << endl;
    // RekeningTabungan T(10000, 2000);
    // if(T.tarikUang(8000)){
    // cout << 1 << endl;
    
    // }
    // cout << T.getSaldo() << endl;
    RekeningGiro G(20000, 0.1);
    cout << G.hitungBunga()<<endl;
}