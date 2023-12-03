#ifndef VEC2
#define VEC2

#include "../json.hpp"

using json = nlohmann::json;

struct Vec2
{
  float x;
  float y;
};

void from_json(const json& j, Vec2& d);

#endif //!VEC2