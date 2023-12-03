#ifndef enigmaShowdownCommunicationClient
#define enigmaShowdownCommunicationClient

#pragma warning (disable: 4996)

#include <iostream>
#include <thread>

#include "TSQueue.h"

static int MQConstPort = 31878;
static std::string MQConstHost = "localhost";


//TODO::

//Figure out how to package with zeromq
//Change message send to be a thread
class zeroMQRequestClient
{
public:
  //These 2 are intended for a request client with longevity
  zeroMQRequestClient()
  {
    port = MQConstPort-1;
    host = MQConstHost;
  }

  zeroMQRequestClient(int port_, std::string host_)
  {
    port = port_;
    host = host_;
  }

  std::string sendMessageWait(std::string message);

private:


  SafeQueue<std::string> messageQueue;
  std::string sendMessageHandler(std::string message);
  int port = 0;
  std::string host;
  void closeRequestClient(); //Not neaded, as the request socket will close automatically after recieving the reply or timing out
};



class zeroMQSubscriberClient
{
public:
  zeroMQSubscriberClient()
  {
    port = MQConstPort;
    host = MQConstHost;
  }

  zeroMQSubscriberClient(int port_, std::string host_)
  {
    port = port_;
    host = host_;
  }

  void generateSubscriber();

  void endSubscriber();
  
  std::string getNextMessage();

  std::string waitGetNextMessage();


  SafeQueue<std::string> messageQueue;
private:
  //This is used for 2 purposes, to know if it is already running as well as stopping an existing thread
  bool isRunning = false;
  int port = 0;
  std::string host;
  void subscriberHandler();
};

//A simple function that is used for all outputs from the two sockets runners above. This is used so that there is a single location for error log outputs, to pick how its handled in one location
//void customLog(std::string logMessage) {std::cout << logMessage;}

#endif // !enigmaShowdownCommunicationClient
