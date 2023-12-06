#include "playerCode.h"
#include <iostream>
#include <random>
//This is where you program all your logic! you have been provided with all of the game data that exists for the current tick. 
//Feel free to add new files or whatever you desire to this current one! Please do not edit any of the existing files, as they are poorly written and prone to breaking. 
//The current return statement returns a move action, the first number is the direction denoted in radians, and the second number is the speed with a max of 5

static std::vector<Vec2> last5Pos;
static int curState = 0;
//Checks if the player is moving, true if moving false if not. 
//Does not function during the first 5 ticks of the game
bool checkIfMoving(Vec2 curPos)
{
  
  last5Pos.push_back(curPos);
  if (last5Pos.size() < 6) return true;

  
  last5Pos.erase(last5Pos.begin());
  if (last5Pos[4].x == last5Pos[0].x && last5Pos[4].y == last5Pos[0].y)
  {
    return false;
  }
  else
  {
    return true;
  }
}

MoveAction funnyMove()
{
  static int curTickCurMove = 0;
  static MoveAction funnyMoveAction{ 0, 10 };
  if (curTickCurMove < 5)
  {
    curTickCurMove++;
    return funnyMoveAction;
  }
  curTickCurMove = 0;
  funnyMoveAction = MoveAction{ ((rand() % 6283) / 1000.0), 10 };
  return funnyMoveAction;
}

MoveAction playerCode(levelStateBroadcast gameData)
{
 
  MoveAction playerAction{ 0,5 };
  //Stops it from overticking when it shouldn't
  if (gameData.tickTillStart > 0) return playerAction;
  
  //Check if we need to increase state
  if (!checkIfMoving(gameData.gameStateView.entities[0].position))
  {
    curState++;
  }

  //Move action decision
  switch (curState)
  {
    case 0:
      break;
    case 1:
      playerAction = MoveAction{ 1.570796 , 10 };
      break;
    case 2:
      playerAction = MoveAction{ 3.141593 , 10 };
      break;
    case 3:
      playerAction = MoveAction{ 5.061455 , 10 };
      break;
    case 4:
      playerAction = MoveAction{ 1.745329 , 5 };
      break;
    default:
      playerAction = funnyMove();
      break;
  }
  return playerAction;
}


