#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

string doubleToString(double nilai, int precision){
    ostringstream stream;
    stream << fixed << setprecision(precision) << nilai;
    return stream.str();
}

class Mahasiswa{
    public:
        string nama;
        int nim;
        double nilai;


    // Constructor
    Mahasiswa(){
        string inputNama;
        int inputNim;
        double inputNilai;
        // Mari buat objek mahasiswa
        cout << "Masukkan data mahasiswa!" << endl;
        cout << "Nama: ";
        cin >> inputNama;
        cout << "NIM: ";
        cin >> inputNim;
        cout << "Nilai: ";
        cin >> inputNilai;

        Mahasiswa :: nama = inputNama;
        Mahasiswa :: nim = inputNim;
        Mahasiswa :: nilai = inputNilai;
    };

    // Methods
    // Arg+ret
    double katrolNilai(const double &koreksi){
        return Mahasiswa:: nilai + koreksi;
    }

    // NoArg+ret
    string getNama(){
        return nama;
    }

    // Arg+NoRet
    void setNilai(const double &nilai){
        Mahasiswa::nilai = nilai;
    }

    // NoArg++NoRet
    void tampilkanData(){
        cout << nama <<endl;
        cout << nim <<endl;
        cout << nilai <<endl;
    }

    string getInfo(){
        return nama + "\t" + to_string(nim) + "\t" + doubleToString(nilai, 2);
    }
  
};

class DBase{
    public:
        ifstream in;
        ofstream out;
        string fileName;

    DBase(const char* fileName){
        DBase::fileName = fileName;
    }

    void save(Mahasiswa data){
        DBase::out.open(DBase::fileName, ios::app);
        DBase::out << data.getInfo() << endl;
        DBase::out.close();

    }

    void showAll(){
        DBase::in.open(DBase::fileName, ios::in);
        string nama, nim, nilai; int index=0;

        while(DBase::in.eof()){
            DBase::in >> nama;
            DBase::in >> nim;
            DBase::in >> nilai;
            cout << index;
            cout << nama;
            cout << nim;
            cout << nilai;
            index++;
        }
        DBase::in.close();

    }

};

int main(){
    string command;
    cout << "command: ";
    cin >> command;
    while(command != "exit"){
        if (command == "input")


        cout << "command: ";
        cin >> command;
    }
    Mahasiswa mahasiswa = Mahasiswa();
    DBase data("data.txt");
    data.save(mahasiswa);

    // m1.tampilkanData();
    // double koreksi = 50;
    // double nilai = m1.katrolNilai(koreksi);
    // string nama = m1.getNama();
    // cout << nama << endl;
    // m1.setNilai(nilai);
    // m1.tampilkanData();

}