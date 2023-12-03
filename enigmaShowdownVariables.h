
#ifndef ESV
#define ESV

#include <cstdint>
#include <string>
#include <vector>
#include "json.hpp"
#include "customClientVariables/barrierTiles.hpp"
#include "customClientVariables/conquestStateView.hpp"
#include "customClientVariables/entityState.hpp"
#include "customClientVariables/entityType.hpp"
#include "customClientVariables/levelStateBroadcast.hpp"
#include "customClientVariables/mapCordinate.hpp"
#include "customClientVariables/vec2.hpp"
#include "customClientVariables/playerActionRequest.hpp"
#include "customClientVariables/conquestAction.hpp"
#include "customClientVariables/moveAction.hpp"
#include "customClientVariables/connectionRequest.h"

using json = nlohmann::json;

struct packet
{
  std::string type;
};

struct PlayerAction : packet {};

struct GameStateView : packet
{
  int tick;
};


#endif // !enigmaShowdownVariables
