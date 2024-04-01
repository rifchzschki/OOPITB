#include <iostream>
#include "PlasticCup.hpp"

using namespace std;

int main(){
    PlasticCup P(20, 20);

    P.fill(10, HOT_WATER);
    cout << P.get_water_volume();
    P.fill(15, HOT_WATER);
    cout << P.get_water_volume();
    P.drink(10);
    cout << P.get_water_volume();

}