#include "CException.hpp"
#include <iostream>

using namespace std;

int main(){
    int x,n=0;
    try{
        if(n==0){
            throw DivideByZeroException();
        } 
    }catch(DivideByZeroException e){cout<<e.what()<<endl;}
}