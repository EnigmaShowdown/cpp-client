#ifndef CLIENTBACKEND
#define CLIENTBACKEND
#include "enigmaShowdownCommunicationClient.h"
#include "enigmaShowdownVariables.h"
#include <iostream>
#include <string>
#include "playerCode.h"
#include "json.hpp"
#include <fstream>
#include "clientBackend.h"
#include <thread>

class clientBackend
{
public:
  void client();
private:
  void clientThreadHandler();
  zeroMQSubscriberClient subClient;;
};



#endif // !CLIENTBACKEND
