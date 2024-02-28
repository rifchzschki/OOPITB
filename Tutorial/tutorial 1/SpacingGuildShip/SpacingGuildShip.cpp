#include "SpacingGuildShip.hpp"

float SpacingGuildShip :: totalGuildTravel = 0;
int SpacingGuildShip :: producedShips = 0;

SpacingGuildShip :: SpacingGuildShip(): maxPassengerCap(50), passengerCount(0), guildNavigatorCount(3), operatingGuildNavigator(3), spiceStock(50), serialNum(producedShips+1){
    producedShips +=1;
}

SpacingGuildShip :: SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock): maxPassengerCap(maxPassengerCap), passengerCount(0), guildNavigatorCount(guildNavigatorCount), operatingGuildNavigator(guildNavigatorCount),spiceStock(spiceStock), serialNum(producedShips+1){
    producedShips +=1;
}

SpacingGuildShip :: SpacingGuildShip(const SpacingGuildShip& other): maxPassengerCap(other.maxPassengerCap), passengerCount(other.passengerCount), guildNavigatorCount(other.guildNavigatorCount), operatingGuildNavigator(other.operatingGuildNavigator),spiceStock(other.spiceStock), serialNum(producedShips+1){
    producedShips +=1;
}

SpacingGuildShip :: ~SpacingGuildShip(){

}

int SpacingGuildShip :: getShipSerialNum() const{
	/* Mengembalikan serial number dari pesawat */
    return serialNum;
}

int SpacingGuildShip :: getPassengerCount() const{
	/* Mengembalikan jumlah penumpang pesawat */
    return passengerCount;
}

void SpacingGuildShip :: travel(float distance){ //ini yang masih salah
	/* Pesawat bergerak sebesar distance, sehingga 
	 * totalGuildTravel bertambah sebesar:
	 *
	 * distance / (E^2 * operatingGuildNavigator).
	 * 
	 * Catatan: 
	 * 1. Apabila tidak ada Guild Navigator yang operasional, 
	 *    maka totalGuildTravel tidak bertambah;
	 * 2. Apabila ada Guild Navigator yang operasional, 
	 *    maka jumlah Guild Navigator operasional berkurang 1 */

    if(this->operatingGuildNavigator > 0){
        // maju
        float div = E*E*operatingGuildNavigator;
        totalGuildTravel += distance/div;
        operatingGuildNavigator -=1 ;

    }else{
        // tidak maju
    
    }
}

void SpacingGuildShip :: boarding(int addedPassengers){
	/* Penumpang naik ke pesawat sebesar addedPassenger. 
	 * Jika pesawat tidak muat, penumpang pesawat menjadi penuh */
    if(addedPassengers < (maxPassengerCap-passengerCount)){
        // masih muat
        passengerCount += addedPassengers;

    }else{
        // penuh
        passengerCount = maxPassengerCap;

    }
}

void SpacingGuildShip :: dropOff(int droppedPassengers){
	/* Penumpang turun dari pesawat sebesar droppedPassenger. 
	 * Jika jumlah penumpang kurang, kosongkan pesawat */
    if(droppedPassengers<passengerCount){
        // kurangi
        passengerCount -= droppedPassengers;
    }else{
        //kosong
        passengerCount = 0;
    }
}

void SpacingGuildShip :: refreshNavigator(int n){
	/* Menambah n Guild Navigator operasional yang menghabiskan
	 * n * GUILD_NAVIGATOR_SPICE_DOSE spice dari stok.
	 * 
	 * Catatan:
	 * 1. Maksimum merefresh seluruh Guild Navigator yang ada di pesawat 
	 * 2. Apabila stok kurang, maka merefresh n maksimum yang dapat di refresh
	 *    dari stok spice yang ada */

    if(n>guildNavigatorCount){
        n = guildNavigatorCount;
    }

    int added; 
    if(spiceStock<n*GUILD_NAVIGATOR_SPICE_DOSE){
        added = (int) spiceStock/GUILD_NAVIGATOR_SPICE_DOSE;
        spiceStock = 0;
    }else{
        added = n;
        spiceStock -= n*GUILD_NAVIGATOR_SPICE_DOSE;
    }
    operatingGuildNavigator += added;

}

void SpacingGuildShip :: transitToArrakis(int addedSpice){
	/* Menambah stok spice sebesar addedSpice */
    spiceStock += addedSpice;
}