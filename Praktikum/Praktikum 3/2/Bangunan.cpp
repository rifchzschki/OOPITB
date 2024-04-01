#include "Bangunan.hpp"
#include <iostream>

Bangunan::Bangunan():namaBangunan("Bangunan Kosong"){}

Bangunan::Bangunan(string namaBangunan):namaBangunan(namaBangunan){}

string Bangunan::getNamaBangunan(){return namaBangunan;}
