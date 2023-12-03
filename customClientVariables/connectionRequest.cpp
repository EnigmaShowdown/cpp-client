
#include "connectionRequest.h"
//"{\"type\" : \"connect-request\", \"clientType\" : \"PLAYER\"}"
void to_json( json& j, const ConnectRequest& d)
{
  j = "{\"type\" : \"connect-request\", \"clientType\" : \"PLAYER\"}"_json;
}


