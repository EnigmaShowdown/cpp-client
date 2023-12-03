#include "vec2.hpp"


void from_json(const json& j, Vec2& d)
{
  j.at("x").get_to(d.x);
  j.at("y").get_to(d.y);
}