#ifndef PLAYERACTIONREQUEST
#define PLAYERACTIONREQUEST

#include <string>
#include "../json.hpp"
using json = nlohmann::json;

#include "ConquestAction.hpp"


struct PlayerActionRequest
{
  std::string playerId;
  int levelTick;
  ConquestAction playerAction;
};

void to_json(json& j, const PlayerActionRequest& d);

#endif // !PLAYERACTIONREQUEST
