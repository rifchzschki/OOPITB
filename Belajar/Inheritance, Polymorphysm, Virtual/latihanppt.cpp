#include <iostream>

using namespace std;


class Kendaraan{
    private:
        int nomor;
        string merk;
        int tahun;
    
    public:
        Kendaraan():nomor(0), merk("XXX"), tahun(0){}
        Kendaraan(int nomor, string merk, int tahun):nomor(nomor), merk(merk), tahun(tahun){}
        Kendaraan(const Kendaraan& other):nomor(other.nomor), merk(other.merk), tahun(other.tahun) {}
        ~Kendaraan(){}
        Kendaraan& operator=(const Kendaraan& other){
            this->nomor = other.nomor;
            this->merk = other.merk;
            this->tahun = other.tahun;
            return *this;
        }
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
        Mobil(): supir("XXXX"), Kendaraan(){}
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

class KoleksiKendaraan{
    private:
        Kendaraan** arr;
        int size;
        int Neff;

    public:
        KoleksiKendaraan():size(100), Neff(0), arr(new Kendaraan*[size]){};
        KoleksiKendaraan(int size):size(size), Neff(0), arr(new Kendaraan*[size]){};
        KoleksiKendaraan(const KoleksiKendaraan& other):size(other.size), Neff(other.Neff){
            arr = new Kendaraan*[size];
            for(int i = 0; i<Neff; i++){
                arr[i] = other.arr[i];
            }
        };
        ~KoleksiKendaraan(){
            delete[] arr;
        }

        KoleksiKendaraan &operator=(const KoleksiKendaraan &other) {
            if (this != &other) {
                delete[] arr;

                size = other.size;
                Neff = other.Neff;

                arr = new Kendaraan *[size];

                for (int i = 0; i < Neff; ++i) {
                    arr[i] = other.arr[i];
                }
            }
            return *this;
        }

        // Operator untuk menambahkan sebuah Kendaraan ke dalam array sebagai elemen terakhir
        KoleksiKendaraan &operator<<(Kendaraan *kendaraan) {
            if (Neff < size) {
                arr[Neff++] = kendaraan;
            }
            return *this;
        }

        // Operator untuk menambahkan semua Kendaraan dari KoleksiKendaraan lain ke dalam array Kendaraan
        KoleksiKendaraan &operator<<(const KoleksiKendaraan &other) {
            int spaceLeft = size - Neff;
            int added = 0;
            int i = 0;
            while (added < spaceLeft && i < other.Neff) {
                arr[Neff++] = other.arr[i++];
                added++;
            }
            return *this;
        }

        void printAll() const {
            for (int i = 0; i < Neff; ++i) {
                arr[i]->printInfo();
            }
        }


};

int main(){
    Mobil mobil(1234, "toyota", 2020);
    Minibus elf(5663, "mercedes", 2013);
    Bus bus(9283, "fuso", 2021);

    KoleksiKendaraan arr(5);
    
    arr.operator<<(&mobil);
    arr.operator<<(&elf);
    arr.operator<<(&bus);

    // // mobil
    // mobil.printInfo();
    // cout << mobil.biayaSewa(10) << endl;
    // cout << endl;

    // // minibus
    // elf.printInfo();
    // cout << elf.biayaSewa(11) << endl;
    // cout << endl;


    // // bus
    // bus.printInfo();
    // cout << bus.biayaSewa(12) << endl;
    // cout << endl;

    arr.printAll();
}