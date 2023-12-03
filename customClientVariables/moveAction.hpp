#ifndef MOVEACTION
#define MOVEACTION


#include "../json.hpp"
using json = nlohmann::json;

struct MoveAction
{
  double directionRadians;
  double speed;
};

void to_json(json& j, const MoveAction& d);

#endif // !MOVEACTION
