#include "User.h"
#include <iostream>
using namespace std;

int main() {
    // Membuat objek User
    User user1(strdup("ucup"));

    // cout << user1.getNumOfUser() << endl;

    // // Menambahkan beberapa musik ke daftar favorit
    user1.addFavouriteMusic(strdup("Song 1"));
    user1.addFavouriteMusic(strdup("Song 2"));
    user1.addFavouriteMusic(strdup("Song 3"));

    
    // Menampilkan informasi tentang user
    std::cout << "User name: " << user1.getName() << std::endl;
    std::cout << "Number of favorite music: " << user1.getNumOfFavouriteMusic() << std::endl;
    std::cout << "Favorite music list:" << std::endl;
    user1.viewMusicList();

    // Menghapus salah satu musik dari daftar favorit
    user1.deleteFavouriteMusic(strdup("Song 2"));

    // Menampilkan informasi setelah menghapus musik
    std::cout << "Number of favorite music after deletion: " << user1.getNumOfFavouriteMusic() << std::endl;
    std::cout << "Favorite music list after deletion:" << std::endl;
    user1.viewMusicList();

    // Menghapus objek User
    std::cout << "Number of user before deleting: " << User::getNumOfUser() << std::endl;

    // Mengganti nama
    user1.setName(strdup("iki"));

    User user2(user1);
    cout<<user2.getName()<<endl;
    cout<<user2.getNumOfUser()<<endl;
    return 0;
}
