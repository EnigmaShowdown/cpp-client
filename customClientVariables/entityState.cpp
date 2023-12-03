

#include "entityState.hpp"


void from_json(const json& j, EntityState& d)
{
  j.at("id").get_to(d.id);
  j.at("position").get_to(d.position);
  j.at("entityType").get_to(d.entityType);
}