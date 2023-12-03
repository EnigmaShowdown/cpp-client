#ifndef CONQUESTACTION
#define CONQUESTACTION

#include "moveAction.hpp"
#include "../json.hpp"
using json = nlohmann::json;

struct ConquestAction
{
  MoveAction moveAction;
};

void to_json(json& j, const ConquestAction& d);

#endif