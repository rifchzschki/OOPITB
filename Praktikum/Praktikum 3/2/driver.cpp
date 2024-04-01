#include "Bangunan.hpp"
#include "Walikota.hpp"

#include <iostream>

using namespace std;

int main(){
    Walikota w(20, 20, 20);
    w.bangunBangunan("rumah", 10, 10);
    w.statusKota();
    w.bangunBangunan("rumah1", 10, 10);
    w.statusKota();
    w.bangunBangunan("rumah2", 10, 10);
    w.statusKota();
    w.bangunBangunan("rumah3", 10, 10);
    w.statusKota();
    w.bangunBangunan("rumah4", 10, 10);
    w.statusKota();
    w.bangunBangunan("rumah5", 10, 10);
    w.statusKota();
    // w.bangunBangunan("rumah2", 10, 10);
    // w.statusKota();
}