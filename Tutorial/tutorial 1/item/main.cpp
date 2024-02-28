#include "Item.hpp"
#include <iostream>

using namespace std;

int main(){
    Item I(10, 20);
    Item T(10, 20);
    Item E(10, 20);
    T.setPrice(50);
    I.sell(21);
    T.sell(21);
    E.sell(21);


    cout << T.totalRevenue << endl;
    cout << T.totalItems << endl;
}