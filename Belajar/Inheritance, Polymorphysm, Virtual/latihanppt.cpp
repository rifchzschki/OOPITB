#include <iostream>

using namespace std;

class Kendaraan{
    private:
        int nomor;
        string merk;
        int tahun;
    
    public:
        Kendaraan(int nomor, string merk, int tahun):nomor(nomor), merk(merk), tahun(tahun){}
        virtual long biayaSewa(int lamaSewa)=0;
        virtual void printInfo(){
            cout << "Nomor: " << nomor << endl;
            cout << "Merk: " << merk << endl;
            cout << "Tahun: " << tahun << endl;
        }

};

class Bus : public Kendaraan {
    private:
        int kapasitas;
    
    public:
        Bus(int nomor, string merk, int tahun): kapasitas(0), Kendaraan(nomor, merk, tahun){}
        long biayaSewa(int lamaSewa){
            return 1000000*lamaSewa;
        }
        void printInfo(){
            Kendaraan :: printInfo();
            cout << "Kategori: Bus" << endl << endl;
        }
        void tambahKapasitas(const int& tambahan){
            kapasitas += tambahan;
        }
        
};

class Minibus : public Kendaraan {
    private:
        int kapasitas;
    
    public:
        Minibus(int nomor, string merk, int tahun): kapasitas(0), Kendaraan(nomor, merk, tahun){}
        long biayaSewa(int lamaSewa){
            if(lamaSewa<=5){return 5000000;}
            else{return 5000000 + 5000000*(lamaSewa-5);}
        }
        void printInfo(){
            Kendaraan :: printInfo();
            cout << "Kategori: Minibus" << endl << endl;
        }
        float diskon(int lamaSewa){
            if(lamaSewa > 10){
                return 0.1 * biayaSewa(lamaSewa);
            }else {
                return 0;
            }
        }
        void tambahKapasitas(const int& tambahan){
            kapasitas += tambahan;
        }
        
};

class Mobil : public Kendaraan {
    private:
        string supir;

    public:
        Mobil(int nomor, string merk, int tahun): supir("XXXX"), Kendaraan(nomor, merk, tahun){}
        long biayaSewa(int lamaSewa){
            return 500000 * lamaSewa;
        }
        void setSupir(const string& nama){
            supir = nama;
        }
        void printInfo(){
            Kendaraan :: printInfo();
            cout << "Kategori: Mobil" << endl << endl;
        }
};

int main(){
    Mobil mobil(1234, "toyota", 2020);
    Minibus elf(5663, "mercedes", 2013);
    Bus bus(9283, "fuso", 2021);

    // mobil
    mobil.printInfo();
    cout << mobil.biayaSewa(10) << endl;
    cout << endl;

    // minibus
    elf.printInfo();
    cout << elf.biayaSewa(11) << endl;
    cout << endl;


    // bus
    bus.printInfo();
    cout << bus.biayaSewa(12) << endl;
    cout << endl;
}