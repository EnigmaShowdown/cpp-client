//  Hello World client in C++
//  Connects REQ socket to tcp://localhost:5555
//  Sends "Hello" to server, expects "World" back
// Set up timeout settings for request client message
#include <zmq.hpp>
#include "enigmaShowdownCommunicationClient.h"
//Where the actual communication is, is called as a thread
void zeroMQSubscriberClient::subscriberHandler()
{
  //  Prepare our context and socket
  zmq::context_t context(1);
  zmq::socket_t socket(context, zmq::socket_type::sub);
  std::string connectionInformationString = "tcp://";
  connectionInformationString.append(host).append(":").append(std::to_string(port));
  socket.connect(connectionInformationString);
  zmq_setsockopt(socket, ZMQ_SUBSCRIBE, "", 0);



  while (isRunning)
  {
    //get messages and push them into the queue as strings
    zmq::message_t message;
    socket.recv(message, zmq::recv_flags::none);
    messageQueue.enqueue(message.to_string());
    //std::cout << message;
  }
}

//Creates a thread of the start subscriber function
void zeroMQSubscriberClient::generateSubscriber()
{
  if (isRunning) {
    //customLog("Error: client is already running");
  }
  else {
    isRunning = true;
    std::thread th1([this] {subscriberHandler(); });
    th1.detach();
  }
}

//Gets the next message
std::string zeroMQSubscriberClient::getNextMessage()
{
  return messageQueue.dequeueNoWait();
}

//Waits for the next message
std::string zeroMQSubscriberClient::waitGetNextMessage()
{
  //If no socket is running we don't wait.
  if (!isRunning)
  {
    //Output an error and return an empty string
    //customLog("Error, tried to wait for next message without a running socket");
    return std::string();
  }
  return messageQueue.dequeue();
}

//Closes the thread for the subscriber socket
void zeroMQSubscriberClient::endSubscriber()
{
  if(isRunning)
    isRunning = false;
  else
  {
    //customLog("Error: no existing subscriber is running");
  }
}

//Sends a message
std::string zeroMQRequestClient::sendMessageWait(std::string message)
{
  //Setup the socket
  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REQ);
  std::string connectionInformationString = "tcp://";
  connectionInformationString.append(host).append(":").append(std::to_string(port));
  socket.connect(connectionInformationString);
  //zmq_setsockopt(socket, ZMQ_REQ, "", 0);
  //Copy the desired message into a zeromq format and send it
  zmq::message_t request(message.data(), message.length());
  memcpy(request.data(), message.data(), message.size());

  socket.send(request, 0);
  //std::cout <<std::endl <<  std::strerror(errno) <<std::endl;
  //Set up the reply location and recieve it
  zmq::message_t reply;
  socket.recv(reply, zmq::recv_flags::none);
  std::string replyString = std::string(static_cast<char*>(reply.data()), reply.size());
  //TODO: Setup logic for a timeout, decide if resend or fail. 
  return replyString;
}

std::string zeroMQRequestClient::sendMessageHandler(std::string message)
{
  return std::string();
}

//Closes the request socket
void zeroMQRequestClient::closeRequestClient()
{
  //Unused as I believe the thread auto-closes when the program ends

}