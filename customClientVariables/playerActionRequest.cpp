
#include "playerActionRequest.hpp"


void to_json(json& j, const PlayerActionRequest& d)
{
  j = json{ {"playerId", d.playerId}, {"levelTick", d.levelTick}, {"playerAction", d.playerAction} };
}
