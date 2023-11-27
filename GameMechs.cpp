#include "GameMechs.h"
#include "MacUILib.h"
GameMechs::GameMechs()
{
    loseFlag = false;
    exitFlag = false;
    boardSizeX = 20; //default board size
    boardSizeY = 10;
    score = 0;
    input = 0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX; //default board size
    boardSizeY = boardY;

}

// do you need a destructor?
GameMechs::~GameMechs(){}


bool GameMechs::getExitFlagStatus()
{

}

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;

}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;

}


void GameMechs::setExitTrue()
{
    exitFlag =1;

}

void GameMechs::setInput(char this_input)
{
    input = this_input;

    



}

void GameMechs::clearInput()
{
    input =0;

}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore() 
{
    score++;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::setLoseFlag(){
    loseFlag = 1;
}


