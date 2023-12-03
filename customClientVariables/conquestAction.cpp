
#include "conquestAction.hpp"


void to_json(json& j, const ConquestAction& d)
{
  j = json{ {"moveAction", d.moveAction} };
}