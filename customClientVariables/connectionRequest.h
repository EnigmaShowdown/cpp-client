#ifndef CONNECTIONREQUEST
#define CONNECTIONREQUEST

#include "../json.hpp"

using json = nlohmann::json;

enum ClientType { PlayerClient, ServerClient};

NLOHMANN_JSON_SERIALIZE_ENUM(ClientType, {
  {PlayerClient, "PLAYER"},
  {ServerClient, "SERVER"},
  });
struct ConnectRequest
{
  ClientType clientType;
};

void to_json(json& j, const ConnectRequest& d);




#endif // !CONNECTIONREQUEST
