#include <iostream>
#include <type_traits>

using namespace std;

template<typename T>
void func(T t1, T t2){
        cout << "Masukan Anda: " << t1 << " dan " << t2 << ", memiliki tipe yang sama" << endl;
}

template<typename T1,typename T2>
void func(T1 t1, T2 t2){
        cout << "Masukan Anda: " << t1 << " dan " << t2 << ", mungkin memiliki tipe yang berbeda" << endl;
}

template<>
void func<char, int>(char t1, int t2){
    while(t2>0){
        cout<<t1<<endl;
        t2-=1;
    }
}

// int main(){
//     func(2, 2);
//     func(2, 2.0);
//     func('a', 2);
//     return 0;
// }

