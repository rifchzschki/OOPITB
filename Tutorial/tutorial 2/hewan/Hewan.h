#ifndef HEWAN_H
#define HEWAN_H

#include <iostream>

using namespace std;

class Hewan{
    protected:
        string nama;

    public:
        Hewan(string nama): nama(nama){}
        ~Hewan(){
            cout << "Hewan mati " << nama << endl;
        }   

        virtual void print(){
            cout << "Hewan ini namanya " << Hewan :: nama << endl;
        }
};

class Anjing: public Hewan{
    public:
        Anjing(string nama): Hewan(nama){}
        ~Anjing(){
            cout << "Anjing mati " << Hewan::nama << endl;
        }
        void print(){
            cout << "Anjing ini namanya " << Hewan :: nama << endl;
        }

};

class Kucing: public Hewan{
    public:
        Kucing(string nama): Hewan(nama){}
        virtual ~Kucing(){
            cout << "Kucing mati " << Hewan::nama << endl;
        }
        // void print(){
        //     cout << "Hewan ini namanya " << Hewan :: nama << endl;
        // }

};

class KucingAnggora: public Kucing{
    protected:
        string pemilik;
    
    public:
        KucingAnggora(string namaHewan, string namaPemilik): pemilik(namaPemilik), Kucing(namaHewan){}
        ~KucingAnggora(){
            cout << "Kucing anggora mati " << Hewan::nama << endl;
        }
        void print(){
            cout << "Kucing anggora ini namanya " << Hewan::nama << ". ";
            cout << "Pemiliknya adalah " << pemilik << endl;
        }
};

class AnjingBulldog: public Anjing{
    protected:
        string pemilik;
    
    public:
        AnjingBulldog(string namaHewan, string namaPemilik): pemilik(namaPemilik), Anjing(namaHewan){}
        ~AnjingBulldog(){
            cout << "Anjing bulldog mati " << Hewan::nama << endl;
        }
        void print(){
            cout << "Anjing bulldog ini namanya " << Hewan::nama << ". ";
            cout << "Pemiliknya adalah " << pemilik << endl;
        }
};


#endif