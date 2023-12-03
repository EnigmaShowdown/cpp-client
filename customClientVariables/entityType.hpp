#ifndef ENTITYTYPE
#define ENTITYTYPE

#include "../json.hpp"
using json = nlohmann::json;

enum EntityType { Player, Crate, Flag, Pressure_Plate };

NLOHMANN_JSON_SERIALIZE_ENUM(EntityType, {
  {Player, "PLAYER"},
  {Crate, "CRATE"},
  {Flag, "FLAG"},
  {Pressure_Plate, "PRESSURE_PLATE"}
  });


#endif // !ENTITYTYPE
