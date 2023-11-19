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
    delete(mainGameMechsRef);
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list

    // int i;

    // for(i = 0; i < 10; i++){
    //     if(playerPos[i] != NULL){
    //         playerPos[i] = returnPos;
    //     }
    // }

    



}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 

    GameMechs* thisGMRef;

    char input,previousDirection;

    input = thisGMRef->getInput();

    if(input != 0)  // if not null character
    { 
        switch(input){
            case 27:  // the esc key
                //exitFlag = 1;
                break;

            case 'w':
            case 'W':
                if(previousDirection != 's'){

                    myDir = UP;
                    previousDirection = 'w';

                    break;

                } else{
                   myDir = DOWN;
                   previousDirection = 's';

                    break;
                }
                
                

            case 's':
            case 'S':

                if(previousDirection != 'w'){

                    myDir = DOWN;
                    previousDirection = 's';

                    break;
                } else{

                    myDir = UP;
                    previousDirection = 'w';

                    break;
                }
                
                
                break;

            case 'a': 
            case 'A':

                if(previousDirection != 'd'){

                    myDir = LEFT;
                    previousDirection = 'a';

                } else{
                    myDir = RIGHT;
                    previousDirection = 'd';
                }
                
                break;
            
            case 'd':
            case 'D':

                if(previousDirection != 'a'){
                    myDir = RIGHT;
                    previousDirection = 'd';

                } else{
                    myDir = LEFT;
                    previousDirection = 'd';
                }
                
                break;

            default:
                break;
        }
    }



         
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

