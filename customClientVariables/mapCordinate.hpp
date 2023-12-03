#ifndef MAPCORDINATE
#define MAPCORDINATE

#include "../json.hpp"
using json = nlohmann::json;

struct MapCordinate
{
  int x;
  int y;
};

void from_json(const json& j, MapCordinate& d);

#endif // !MAPCORDINATE
