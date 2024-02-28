#include "Item.hpp"

using namespace std;

int Item::totalRevenue = 0;
int Item::totalItems = 0;


Item :: Item(): stock(0), price(0), sold(0), serialNum(totalItems+1){
    totalItems += 1;
}

Item :: Item(int stock, int price): stock(stock), price(price), sold(0), serialNum(totalItems+1) {
    totalItems += 1;
}

Item :: Item(const Item& other): stock(other.stock), price(other.price), sold(other.sold), serialNum(totalItems+1){
    totalItems += 1;
}

Item :: ~Item(){
    // totalItems -= 1;
}

int Item :: getSerialNum() const{
    return serialNum;
}

int Item :: getSold() const{
    return sold;
}

int Item :: getPrice() const{
    return price;
}

void Item :: addStock(int addedStock){
/* Menambahkan stok item. Tidak akan bernilai negatif. */
    if(addedStock>=0){
        this->stock += addedStock;
    }
}
void Item :: sell(int soldStock){
/* Menjual item. Jika item tidak cukup, maka item terjual hanya sampai stok item habis */
    if (stock>soldStock){
        stock -= soldStock;
        sold += soldStock;
        totalRevenue += soldStock * price;

    }else{
        sold += stock;
        totalRevenue += stock * price;
        stock = 0;
    }
}
void Item :: setPrice(int newPrice){
    this->price = newPrice;
}