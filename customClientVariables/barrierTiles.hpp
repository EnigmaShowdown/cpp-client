#ifndef barrierTilesEnum
#define barrierTilesEnum

#include "mapCordinate.hpp"
#include "../json.hpp"
using json = nlohmann::json;


enum BarrierType { Wall, Wall_Triangle_Smooth_Lower_Left, Wall_Triangle_Smooth_Lower_Right, Wall_Triangle_Smooth_Upper_Left, Wall_Triangle_Smooth_Upper_Right };

NLOHMANN_JSON_SERIALIZE_ENUM(BarrierType, {
  { Wall, "WALL"},
  {Wall_Triangle_Smooth_Lower_Left, "WALL_TRIANGLE_SMOOTH_LOWER_LEFT"},
  {Wall_Triangle_Smooth_Lower_Right, "WALL_TRIANGLE_SMOOTH_LOWER_RIGHT"},
  {Wall_Triangle_Smooth_Upper_Left, "WALL_TRIANGLE_SMOOTH_UPPER_LEFT"},
  {Wall_Triangle_Smooth_Upper_Right, "WALL_TRIANGLE_SMOOTH_UPPER_RIGHT"}
  });

struct BarrierTile
{
  MapCordinate coordinate;
  BarrierType barrierType;
};

void from_json(const json& j, BarrierTile& d);

#endif // !barrierTilesEnum
