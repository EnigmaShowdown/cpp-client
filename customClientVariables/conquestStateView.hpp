#ifndef CONQUESTSTATEVIEW
#define CONQUESTSTATEVIEW

#include "entityState.hpp"
#include "barrierTiles.hpp"
#include "../json.hpp"

using json = nlohmann::json;

struct conquestStateView
{
  int tick;
  std::vector<EntityState> entities;
  std::vector<BarrierTile> barriers;
};

void from_json(const json& j, conquestStateView& d);

#endif