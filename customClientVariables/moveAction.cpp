#include "moveAction.hpp"


void to_json(json& j, const MoveAction& d)
{
  j = json{ {"directionRadians", d.directionRadians}, {"speed", d.speed} };
}