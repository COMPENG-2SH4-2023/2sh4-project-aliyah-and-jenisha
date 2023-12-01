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
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete(mainGameMechsRef);

    delete playerPosList;
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
            case 'w':
                if (myDir != DOWN) {
                    myDir = UP;
                }
                break;
            
            case 'a':
                if (myDir != RIGHT) {
                    myDir = LEFT;
                }
                break;

             case 's':
                if (myDir != UP) {
                    myDir = DOWN;
                }
                break;
            
            case 'd':
                if (myDir != LEFT) {
                    myDir = RIGHT;
                }
                break;
            
            default:
                break;
        }
            /*case 27:  // the esc key
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
                */
        }
    }




void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currHead; 
    playerPosList->getHeadElement(currHead);


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
    if(currHead.x > 24){
        currHead.x = 2; 

    } else if(currHead.x < 2){
        currHead.x = 24;

    } else if(currHead.y < 2){
        currHead.y = 10;
    } else if(currHead.y > 11){
        currHead.y = 2;
    }


    if(checkSelfCollision == true){
        setExitTrue();
        loseFlag = 1;

    } else{

         playerPosList->insertHead(currHead);
         playerPosList->removeTail();

    }
   

}

bool Player::checkSelfCollision(objPos head){

    Player* object;

    playerPosList->getHeadElement(head);
    objPosArrayList* playerBody = object->getPlayerPos(); // entire player pos list
    objPos tempBody;



     for(int k = 0; k < playerBody->getSize(); k++){
        playerBody->getElement(tempBody, k);

        if(tempBody.x == head.x && tempBody.y == head.y){
            return true;
        }
     }

     return false;


}

