#ifndef ENTITYSTATE
#define ENTITYSTATE
#include "vec2.hpp"
#include "entityType.hpp"
#include "../json.hpp"
using json = nlohmann::json;




struct EntityState
{
  std::string id;
  Vec2 position;
  EntityType entityType;
};

void from_json(const json& j, EntityState& d);

#endif // !ENTITYSTATE
