#include "PlasticCup.hpp"

bool PlasticCup::is_usable()
{
  return Plastic::is_usable() && this->current_microplastics<=this->maximum_microplastics;
}

void PlasticCup::fill(int volume, enum WaterType type)
{
  if(PlasticCup::is_usable())
  {
  Cup::fill(volume,type);
  Plastic::use();
  // this->current_microplastics += type == HOT_WATER ? 2 * Plastic::shred_microplastics(Cup::get_water_volume(), this->capacity) : Plastic::shred_microplastics(Cup::get_water_volume(), this->capacity);
  double ratio = static_cast<double>(get_water_volume()) / static_cast<double>(capacity);

  int shredded_microplastics = Plastic::shred_microplastics(static_cast<int>(ratio), 1);

  if (type == WaterType::HOT_WATER)
  {
    shredded_microplastics *= 2;
  }

  current_microplastics += shredded_microplastics;
   }
}

void PlasticCup::drink(int volume)
{
  if(is_usable())
  {
  Cup::drink(volume);
  Plastic::use();
  current_microplastics -= volume;
  if (current_microplastics < 0)
  {
    current_microplastics = 0;
  }
  }
}

void PlasticCup::drop(int height)
{
this->current_microplastics +=shred_microplastics(get_water_volume()*height,capacity);

}