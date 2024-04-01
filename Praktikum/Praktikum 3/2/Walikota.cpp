#include "Walikota.hpp"
#include <iostream>
#include "Exception.hpp"
#include <exception>

using namespace std;

Walikota :: Walikota():kayu(DEFAULT_KAYU), gulden(DEFAULT_GULDEN), pekerja(DEFAULT_PEKERJA){}

Walikota :: Walikota(int kayu, int gulden, int pekerja):kayu(kayu), gulden(gulden), pekerja(pekerja){}

Walikota :: ~Walikota(){}

void Walikota :: bangunBangunan(string namaBangunan, int kayu, int gulden){
    try{
        pakaiKayu(kayu);
        pakaiGulden(gulden);
        pekerjakanPekerja();
        Bangunan B(namaBangunan);
        bangunan.push_back(B);
        cout<<"Bangunan [" << bangunan.size() << "] " <<  namaBangunan << " berhasil dibangun" << endl;
        }
    catch(KayuTidakCukupException e){
        cout << e.what() << ", beli kayu dulu." << endl;
        // batalPakaiKayu(kayu);
        // batalkanPekerja();
        // batalPakaiGulden(gulden);
    } catch(PekerjaTidakCukupException e){
        cout << e.what() << ", rekrut pekerja dulu." << endl;
        batalPakaiKayu(kayu);
        // batalkanPekerja();
        batalPakaiGulden(gulden);
    }catch(GuldenTidakCukupException e){
        cout << e.what() << ", tagih pajak dulu." << endl;
        batalPakaiKayu(kayu);
        // batalkanPekerja();
        // batalPakaiGulden(gulden);
    }

}

void Walikota :: tambahKayu(int num){
    kayu += num;
}

void Walikota :: tambahGulden(int num){
    gulden += num;
}

void Walikota :: tambahPekerja(int num){
    pekerja += num;
}

void Walikota :: pakaiKayu(int num){
    if(kayu>=num){
        kayu-=num;
    }else{
        throw KayuTidakCukupException();
    }
}

void Walikota :: pakaiGulden(int num){
    if(gulden>=num){
        gulden-=num;
    }else{
        throw GuldenTidakCukupException();
    }
}

void Walikota :: pekerjakanPekerja(){
    if(pekerja>0){
        pekerja-=1;
    }else{
        throw PekerjaTidakCukupException();
    }
    
}

void Walikota :: batalPakaiKayu(int num){
    kayu+=num;
}

void Walikota :: batalPakaiGulden(int num){
    gulden+=num;
}

void Walikota :: batalkanPekerja(){
    pekerja+=1;
}

void Walikota :: sebutBangunan(int idx){
    try{
        cout << bangunan.at(idx).getNamaBangunan() << endl;
    }catch(exception e){
        cout << e.what() <<endl;
    }
}

void Walikota :: statusKota(){
    cout << "Status" << endl;
    cout << "  Kayu: " << kayu << endl;
    cout << "  Gulden: " << gulden << endl;
    cout << "  Pekerja: " << pekerja << endl;
    cout << "  Bangunan:" << endl;
    for(int i=0; i<bangunan.size(); i++){
        cout << "    Bangunan[" << i+1 << "]: " << bangunan.at(i).getNamaBangunan() << endl;
    }
}