#include "PlasticCup.hpp"

bool PlasticCup::is_usable()
{
    return Plastic::is_usable() && current_microplastics<maximum_microplastics;
}

void PlasticCup::fill(int volume, enum WaterType type)
{
  if(is_usable())
  {
  Cup::fill(volume,type);
  Plastic::use();
  this->current_microplastics += (type == 1 ? 2 * Plastic::shred_microplastics(get_water_volume(), this->capacity) : Plastic::shred_microplastics(get_water_volume(), this->capacity));
   }
}

void PlasticCup::drink(int volume)
{
  if(is_usable())
  {
  Cup::drink(volume);
  Plastic::use();
  this->current_microplastics = (this->current_microplastics - volume < 0 ? 0 : this->current_microplastics - volume);
  }
}

void PlasticCup::drop(int height)
{
this->current_microplastics +=shred_microplastics(get_water_volume()*height,capacity);

}