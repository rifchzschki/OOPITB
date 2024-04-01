#include <iostream>
#include "Restaurant.hpp"

using namespace std;

void print(const stack<int> &s){
    stack<int> a=s;
    while(a.size()>0){
        cout << a.top() << endl;
        a.pop();
    }
}

int main(){
    Restaurant R;
    R.Push(1);
    R.Push(2);
    R.Push(3);
    R.Push(4);

    cout << R ;
    R.Reorder(3);
    cout << R ;
    R.AddMenu(2,3);
    cout << R ;
}