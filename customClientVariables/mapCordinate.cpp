
#include "mapCordinate.hpp"


void from_json(const json& j, MapCordinate& d)
{
  j.at("x").get_to(d.x);
  j.at("y").get_to(d.y);
}