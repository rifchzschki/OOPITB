#include "Restaurant.hpp"
#include <iostream>

using namespace std;

Restaurant :: Restaurant(){}

Restaurant :: ~Restaurant(){}

void Restaurant :: Push(int val){
    order.push(val);
}

void Restaurant :: Pop(int val){
    if(val>order.size()){
        cout << "Proses tidak valid" << endl;
    }else{
        for(int i=0; i<val; i++){
            order.pop();
        }
    }
}

void Restaurant :: AddMenu(int k, int val){
    int tmp_top;
    stack<int> tmp;
    while(order.size()>0){
        tmp.push(order.top());
        order.pop();
    }
    while(tmp.size()>0){
        tmp_top = tmp.top();
        if(k>0){
            tmp_top += val;
            k -=1;
        }
        order.push(tmp_top);
        tmp.pop();
    }
    
}

void Restaurant :: Reorder(int k){
    int count, size = order.size();
    stack<int> tmp;
    stack<int> tmp2;
    if(k>order.size()){
        k = order.size();
    }

    while(order.size()>0){
        tmp.push(order.top());
        order.pop();
    }
    for(k;k>0;k--){
        tmp2.push(tmp.top());
        tmp.pop();
    }
    while(size>0){
        if(tmp2.size()>0){
            order.push(tmp2.top());
            tmp2.pop();
        }else{
            if(tmp.size()>0){
                order.push(tmp.top());
                tmp.pop();
            }
        }
        size--;
    }


}

ostream& operator<<(ostream& os,Restaurant r){
    os << "(";
    stack<int> temp=r.order;
    while(temp.size()>0){
        os << temp.top() ;
        temp.pop();
        if(temp.size()>0){
            os << ", ";
        }
    }
    os << ")" << endl;
}