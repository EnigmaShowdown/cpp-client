#include "clientBackend.h"



std::string convertMoveAction(std::string playerId, int frame, MoveAction playerMovement)
{
  std::string test;
  json j;
  j["type"] = "player-action-request";
  j["playerId"] = playerId;
  j["levelTick"] = frame;
  j["playerAction"]["type"] = "conquest-action";
  j["playerAction"]["moveAction"]["directionRadians"] = playerMovement.directionRadians;
  j["playerAction"]["moveAction"]["speed"] = playerMovement.speed;
  return to_string(j);
}


void clientBackend::clientThreadHandler()
{
  //When there is a message in subscriber port
  while (true)
  {
    //Parse it
    std::string data = subClient.waitGetNextMessage();
    if (data != std::string())
    {
      //Run the player code function
      zeroMQRequestClient connectionClient;
      levelStateBroadcast dataTemp = json::parse(data).template get<levelStateBroadcast>();
      connectionClient.sendMessageWait(convertMoveAction(dataTemp.gameStateView.entities[0].id,dataTemp.gameStateView.tick, playerCode(dataTemp)));
    }
  }
}


void clientBackend::client()
{
  //Start a subscriber port
  subClient.generateSubscriber();
  //Connect to the server
  zeroMQRequestClient connectionClient;
  ConnectRequest d;
  json j;
  to_json(j, ConnectRequest());
  connectionClient.sendMessageWait(to_string(j));
  //Run thread
  std::thread clientThread([this] {clientThreadHandler(); });
  clientThread.detach();
}