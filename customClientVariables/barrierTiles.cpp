#include "barrierTiles.hpp"



void from_json(const json& j, BarrierTile& d)
{
  j.at("coordinate").get_to(d.coordinate);
  j.at("barrierType").get_to(d.barrierType);
}