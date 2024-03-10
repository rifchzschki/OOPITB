#include "DepreciatingAsset.hpp"


double DepreciatingAsset :: getValue(int years){
    if (years == 0){
        return x->getValue(years);
    }else{
        years -=1;
        return getValue(years)*(1-rate);
    }
}