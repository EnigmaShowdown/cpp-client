#ifndef LEVELSTATEBROADCAST
#define LEVELSTATEBROADCAST
#include "conquestStateView.hpp"
#include "../json.hpp"
using json = nlohmann::json;


struct levelStateBroadcast
{
  int tickTillStart;
  std::string levelID;
  conquestStateView gameStateView;

};

void from_json(const json& j, levelStateBroadcast& d);

#endif