#include "GlassCup.hpp"
#include <stdio.h>

bool GlassCup :: is_usable(){
    return Glass::is_usable();
}

void GlassCup :: fill(int volume, enum WaterType type){
    if(is_usable()){
        Cup::fill(volume, type);
    }
}

void GlassCup :: drink(int volume){
    if(is_usable()){
        Cup::drink(volume);
    }
}

void GlassCup :: drop(int height){
    int force;
    if(Cup :: get_water_volume()>0){
        force = height*get_water_volume();
    }else{
        force = height;
    }
    Glass :: apply_force(force);
}

/**      usable
        /  |   \
       /   |    \
      /    |     \
   cup , glass, plastic
    | \    |      |
    |  \___|_     |
    |     /  \    |
   glasscup, plasticcup  **/