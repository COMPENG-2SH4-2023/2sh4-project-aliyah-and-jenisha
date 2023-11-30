#include "Player.h"

objPosArrayList* playerPosList;


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2, mainGameMechsRef->getBoardSizeY() /2, '*'); // easier way to do this

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete(mainGameMechsRef);
}

 objPosArrayList* Player::getPlayerPos()
{
     return playerPosList;

    



}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 

    GameMechs* thisGMRef;

    char input, previousDirection;

    input = thisGMRef->getInput();


    if(input != 0)  // if not null character
    { 
        switch(input){
            case 27:  // the esc key
                thisGMRef->setExitTrue();//exitFlag = 1;
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

    objPos currHead; 


    switch(myDir){
        case UP:
            currHead.y--;
            break;
        case DOWN:
            currHead.y++;
            break;
        case RIGHT:
            currHead.x++;
            break;
        case LEFT:
            currHead.x--;
            break;
    }
    if(currHead.x > 25){
        currHead.x = 1; 
 
    } else if(currHead.x < 1){
        currHead.x = 25;

    } else if(currHead.y < 1){
        currHead.y = 12;
    } else if(currHead.y > 12){
        currHead.y = 1;
    }

    playerPosList->insertHead(currHead);
    playerPosList->removeTail();

}

