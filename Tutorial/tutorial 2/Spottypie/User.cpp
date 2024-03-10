#include "User.h"
#include <iostream>
#include <cstring>

using namespace std;
int User :: n_user = 0;

User :: User(char* namaPengguna): num_of_favourite_music(0), music_list(nullptr){
    name = new char[strlen(namaPengguna) + 1];
    strcpy(name, namaPengguna);
    n_user+=1;
}

User :: User(const User& other){
    // delete[] name;
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    num_of_favourite_music = other.num_of_favourite_music;
    music_list = new char* [num_of_favourite_music];
    for(int i=0; i<other.num_of_favourite_music; i++){
        music_list[i] = new char[strlen(other.music_list[i])+1];
        strcpy(music_list[i], other.music_list[i]);
    }
    n_user +=1;
}

User :: ~User(){
    cout << "User " << name << " deleted" << endl;
    delete[] name;
    if(music_list != nullptr){
        for(int i=0; i<num_of_favourite_music;i++){
            delete[] music_list[i];
        }
        delete[] music_list;
    }
    n_user -=1;
}

void User :: addFavouriteMusic(char* title){
    // tidak dapat menghandle jika music_list penuh karena tidak ada kapasitas yang jelas
    char** new_music_list = new char*[num_of_favourite_music+1];
    for(int i=0; i<num_of_favourite_music; i++){
        new_music_list[i] = new char[strlen(music_list[i]+1)];
        strcpy(new_music_list[i], music_list[i]);
        delete[] music_list[i];
    }

    new_music_list[num_of_favourite_music] = new char[strlen(title) + 1];
    strcpy(new_music_list[num_of_favourite_music], title);
    delete[] music_list;
    music_list = new_music_list;
    num_of_favourite_music +=1;    
}

void User :: deleteFavouriteMusic(char* title){
    if(num_of_favourite_music != 0 ){
        for(int i=0 ; i<num_of_favourite_music; i++){
            if(strcmp(title, music_list[i]) == 0){
                // hapus music_list[i]
                delete[] music_list[i];
                for(int j=i; j<num_of_favourite_music-1; j++){
                    music_list[j] = music_list[j+1];
                }
                num_of_favourite_music -= 1;
            }
        }
    }
}

void User :: setName(char* nama){
    delete[] name;
    name = new char [strlen(nama)+1];
    strcpy(name, nama);
}

char* User :: getName() const{
    return name;
}

int User :: getNumOfFavouriteMusic() const{
    return num_of_favourite_music;
}

void User :: viewMusicList() const{
    if(num_of_favourite_music!=0){
        for(int i=0; i<num_of_favourite_music; i++){
            cout << i+1 << ". " << music_list[i] << endl;
        }
    }else{
        cout << "No music in your favourite list" << endl;
    }
}

int User :: getNumOfUser(){
    return n_user;
}