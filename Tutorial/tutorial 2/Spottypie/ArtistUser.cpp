#include "ArtistUser.h"
#include <iostream>

using namespace std;


int ArtistUser :: num_of_artist = 0;

ArtistUser :: ArtistUser(char* nama): User(nama), num_of_music_uploaded(0), uploaded_music_list(nullptr){}
ArtistUser :: ArtistUser(const ArtistUser& other): User(other), num_of_music_uploaded(other.num_of_music_uploaded){
    uploaded_music_list = new char* [other.num_of_music_uploaded];
    for(int i=0; i<other.num_of_music_uploaded; i++){
        uploaded_music_list[i] = new char [strlen(other.uploaded_music_list[i])+1];
        strcpy(uploaded_music_list[i], other.uploaded_music_list[i]);
    }
    num_of_artist +=1;
}

ArtistUser :: ~ArtistUser(){
    cout<<"Artist User " << User::name<<" deleted"<<endl;
    if(uploaded_music_list != nullptr){
        for(int i=0; i<num_of_music_uploaded; i++){
            delete[] uploaded_music_list[i];
        }
        delete[] uploaded_music_list;
    }
    num_of_artist -=1;
}

void ArtistUser :: uploadMusic(char* title){
    char** new_uploaded_music_list = new char* [num_of_music_uploaded+1];
    for(int i=0; i<num_of_music_uploaded; i++){
        new_uploaded_music_list[i] = new char [strlen(uploaded_music_list[i])+1];
        strcpy(new_uploaded_music_list[i], uploaded_music_list[i]);
        delete[] uploaded_music_list[i];
    }

    new_uploaded_music_list[num_of_music_uploaded] = new char [strlen(title)+1];
    strcpy(new_uploaded_music_list[num_of_music_uploaded], title);
    delete[] uploaded_music_list;
    uploaded_music_list = new_uploaded_music_list;
    num_of_music_uploaded +=1;    
}

void ArtistUser :: deleteUploadedMusic(char* title){
    if(num_of_music_uploaded != 0 ){
        for(int i=0; i<num_of_music_uploaded; i++){
            if(strcmp(title, uploaded_music_list[i])==0){
                // hapus dari list
                delete [] uploaded_music_list[i];
                for(int j=i; j<num_of_music_uploaded-1; j++){
                    uploaded_music_list[j] = uploaded_music_list[j+1];
                }
                num_of_music_uploaded -= 1;
            }
        }
    }
}

void ArtistUser :: viewUploadedMusicList() const{
    if(num_of_music_uploaded>0){
        for(int i=0; i<num_of_music_uploaded; i++){
            cout << i+1 << ". " << uploaded_music_list[i] << endl; 
        }
    }else{
        cout << "No music uploaded" << endl;
    }
    
}

int ArtistUser :: getNumOfMusicUploaded() const{
    return num_of_music_uploaded;
}

int ArtistUser :: getNumOfArtist(){
    return num_of_artist;
}
