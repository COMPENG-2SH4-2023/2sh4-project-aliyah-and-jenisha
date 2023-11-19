#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    int xBoardSize, yBoardSize;

    xBoardSize = mainGameMechsRef->getBoardSizeX();
    yBoardSize = mainGameMechsRef->getBoardSizeY();

    

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list


}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

