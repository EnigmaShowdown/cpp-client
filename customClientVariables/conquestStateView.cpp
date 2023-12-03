#include "conquestStateView.hpp"




void from_json(const json& j, conquestStateView& d)
{
  j.at("tick").get_to(d.tick);
  j.at("entities").get_to(d.entities);
  j.at("barriers").get_to(d.barriers);
}