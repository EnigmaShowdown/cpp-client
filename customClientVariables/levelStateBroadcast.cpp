#include "levelStateBroadcast.hpp"


void from_json(const json& j, levelStateBroadcast& d)
{
  j.at("levelId").get_to(d.levelID);
  j.at("ticksUntilBegin").get_to(d.tickTillStart);
  j.at("gameStateView").get_to(d.gameStateView);

}
