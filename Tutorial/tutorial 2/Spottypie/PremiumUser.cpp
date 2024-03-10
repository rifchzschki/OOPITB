#include <iostream>
#include "PremiumUser.h"

using namespace std;

PremiumUser :: PremiumUser(char* nama): active(true),num_of_music_downloaded(0), User(nama){}
PremiumUser :: PremiumUser(const PremiumUser& other): User(other), active(other.active), num_of_music_downloaded(other.num_of_music_downloaded){}
PremiumUser :: ~PremiumUser(){
    cout << "Premium user " << User::name << " deleted" <<endl;
}

void PremiumUser :: downloadMusic(char* title){
    if(active == true){
        for(int i=0; i< User::getNumOfFavouriteMusic(); i++){
            if (strcmp(title, User::music_list[i]) == 0){
                cout << "Music Downloaded: " << music_list[i] << endl;
            }
        }
        num_of_music_downloaded+=1;
    }else{
        cout << "Activate premium account to download music"<< endl;
    }
}

void PremiumUser :: inactivatePremium(){
    active = false;
}

void PremiumUser :: activatePremium(){
    active = true;
}

int PremiumUser :: getNumOfMusicDownloaded()const{
    return num_of_music_downloaded;
}

bool PremiumUser :: getPremiumStatus() const{
    return active;
}
