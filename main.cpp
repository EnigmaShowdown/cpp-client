#include <iostream>
#include <string>
#include <fstream>
#include "clientBackend.h"
#include "json.hpp"
#include "customClientVariables/connectionRequest.h"


void clientTest()
{
  clientBackend test;
  test.client();
  while (true) {}
}


void connectRequestTest()
{
  ConnectRequest test;
  test.clientType = PlayerClient;
  json j;
  to_json(j, test);
  std::cout << nlohmann::to_string(j);
  return;
}



int main()
{

  clientTest();
  
  return 0;
}